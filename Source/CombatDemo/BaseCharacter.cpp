// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CharacterASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	// Init attributes
	HealthSet = CreateDefaultSubobject<UHealthAttributeSet>("HealthSet");
	MovingSet = CreateDefaultSubobject<UMovingAttributeSet>("MovingSet");
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	CharacterASC->GetGameplayAttributeValueChangeDelegate(HealthSet->GetHealthAttribute()).AddUObject(this, &ABaseCharacter::OnHealthAttributeChanged);
	CharacterASC->GetGameplayAttributeValueChangeDelegate(HealthSet->GetShieldAttribute()).AddUObject(this, &ABaseCharacter::OnShieldAttributeChanged);
	CharacterASC->GetGameplayAttributeValueChangeDelegate(HealthSet->GetStaminaAttribute()).AddUObject(this, &ABaseCharacter::OnStaminaAttributeChanged);

	HealthSet->OnDamageTaken.AddUObject(this, &ABaseCharacter::OnDamageTakenChanged);
	HealthSet->OnDamageTaken.AddUObject(this, &ABaseCharacter::OnDamageTakenCallback);

	UE_LOG(LogTemp, Warning, TEXT("Character %s has %f HP."), *GetNameSafe(this), GetHealth());
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// ABILITIES
UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return CharacterASC;// AbilitySystemComp;
}


// Getters
float ABaseCharacter::GetHealth() const
{
	return HealthSet->GetHealth();
}

float ABaseCharacter::GetMaxHealth() const
{
	return HealthSet->GetMaxHealth();
}

void ABaseCharacter::SetHealth(float Value)
{
	HealthSet->SetHealth(Value);
}

float ABaseCharacter::GetShield() const
{
	return HealthSet->GetShield();
}

float ABaseCharacter::GetMaxShield() const
{
	return HealthSet->GetMaxShield();
}

void ABaseCharacter::SetShield(float Value)
{
	HealthSet->SetShield(Value);
}

float ABaseCharacter::GetStamina() const
{
	return HealthSet->GetStamina();
}

float ABaseCharacter::GetMaxStamina() const
{
	return HealthSet->GetMaxStamina();
}

void ABaseCharacter::SetStamina(float Value)
{
	HealthSet->SetStamina(Value);
}

float ABaseCharacter::GetHealthPercentage() const
{
	return GetHealth() / GetMaxHealth();
}

// Inits
void ABaseCharacter::InitializeAbilities()
{
	if (!HasAuthority() || !CharacterASC)
		return;

	for (TSubclassOf<UCharacterGameplayAbility>& Ability : DefaultAbilities) {
		FGameplayAbilitySpecHandle SpecHandle = CharacterASC->GiveAbility(FGameplayAbilitySpec(Ability, 1, static_cast<int32>(Ability.GetDefaultObject()->GetAbilityInputID()), this));
	}
}

void ABaseCharacter::InitializeEffects()
{
	if (!CharacterASC)
		return;

	FGameplayEffectContextHandle EffectContext = CharacterASC->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	for (TSubclassOf<UGameplayEffect>& Effect : DefaultEffects) {
		FGameplayEffectSpecHandle SpecHandle = CharacterASC->MakeOutgoingSpec(Effect, 1, EffectContext);
		if (SpecHandle.IsValid()) {
			FActiveGameplayEffectHandle ActiveGEHandle = CharacterASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}

void ABaseCharacter::InitializeACS()
{
	InitializeAbilities();
	InitializeEffects();
}

void ABaseCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (!CharacterASC)
		return;

	CharacterASC->InitAbilityActorInfo(this, this);
	InitializeACS();
}

// State changes
const FGameplayTag BlockInputTotalTag;// = FGameplayTag::RequestGameplayTag(FName("State.BlockInput.Total"));
const FGameplayTag BlockInputRotationOnlyTag;// = FGameplayTag::RequestGameplayTag(FName("State.BlockInput.RotationOnly"));


void ABaseCharacter::OnDamageTakenChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayTagContainer& GameplayTagContainer, float Damage)
{
	OnDamageTaken(DamageInstigator, DamageCauser, GameplayTagContainer, Damage);
}

void ABaseCharacter::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnShieldAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnShieldChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnStaminaAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnStaminaChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnDamageTakenCallback(AActor* EffectInstigator, AActor* EffectCauser, const FGameplayTagContainer& GameplayTags, float Damage)
{
	UE_LOG(LogTemp, Warning, TEXT("Character %s took damage: %f from %s"), *GetNameSafe(this), Damage, *GetNameSafe(EffectCauser));

	if (GetHealth() <= 0)
		Die();

	UE_LOG(LogTemp, Warning, TEXT("Character has %f HP remaining."), GetHealth());
}

void ABaseCharacter::Die_Implementation()
{
}


void ABaseCharacter::OnGameplayTagChanged(const FGameplayTag Tag, int32 NewCount)
{
	if (Tag == BlockInputTotalTag) {
		bool bShouldBlockInput = (NewCount > 0);
		HandleInputBlocking(bShouldBlockInput);
	}
	else if (Tag == BlockInputRotationOnlyTag) {

	}
}

void ABaseCharacter::HandleInputBlocking(bool Value)
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		PlayerController->SetIgnoreMoveInput(Value);
		
	}
}

void ABaseCharacter::HandleInputBlockingAllowRotation(bool Value)
{
	UCharacterMovementComponent* CharMoveComp = GetCharacterMovement();
	if (CharMoveComp)
	{
		if (Value)
		{
			// Reduce the movement speed while allowing rotation
			CharMoveComp->MaxWalkSpeed = 200.f;  // Example lower speed (adjust as necessary)
		}
		else
		{
			// Reset back to normal speed
			CharMoveComp->MaxWalkSpeed = 600.f;  // Default walking speed (adjust as necessary)
		}
	}
}

void ABaseCharacter::LaunchTarget(AActor* targetActor) const
{
}

// Physics
void ABaseCharacter::LaunchEntity(FVector direction)
{
	LaunchCharacter(direction, true, true);
}

FVector ABaseCharacter::GetLaunchVector(AActor* targetActor) const
{
	return (targetActor->GetActorLocation() - GetActorLocation()).Rotation().Vector();
}

