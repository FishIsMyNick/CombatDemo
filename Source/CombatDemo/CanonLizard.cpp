// Fill out your copyright notice in the Description page of Project Settings.


#include "CanonLizard.h"

// Sets default values
ACanonLizard::ACanonLizard()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttackSet = CreateDefaultSubobject<UCannonLizardAttributeSet>("AttackSet");
}

// Called when the game starts or when spawned
void ACanonLizard::BeginPlay()
{
	Super::BeginPlay();

	SetAnimInstance();
	AIController = Cast<AAIController>(GetController());
	PrimitiveComponent = Cast<UPrimitiveComponent>(GetRootComponent());

	OnResetRoamEventTriggered.Broadcast();
}

// Called every frame
void ACanonLizard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACanonLizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// INIT

float ACanonLizard::GetDamage() const
{
	return AttackSet->GetHitDamage();
}

float ACanonLizard::GetHitRange() const
{
	return AttackSet->GetHitRange();
}

float ACanonLizard::GetSpitDamage() const
{
	return AttackSet->GetSpitDamage();
}

float ACanonLizard::GetSpitRange() const
{
	return AttackSet->GetSpitRange();
}

bool ACanonLizard::GetIsLookingAtTarget() const
{
	return isLookingAtTarget;
}

void ACanonLizard::SetAnimInstance()
{
	animInstance = Cast<UCannonLizardAnimInstance>(GetMesh()->GetAnimInstance());
	if (animInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannon Lizard anim instance set."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get Cannon Lizard anim instance."));
	}
}


float ACanonLizard::HealHealth(float amount)
{
	SetHealth(GetHealth() + amount);
	return GetHealth();
}

bool ACanonLizard::SetTarget(APawn* pawn)
{
	if (TargetPlayer)
		return true;

	ACombatDemoCharacter* player = Cast<ACombatDemoCharacter>(pawn);
	if (player)
	{
		TargetPlayer = player;
		return true;
	}
	return false;
}

void ACanonLizard::ClearTarget()
{
	TargetPlayer = NULL;
	StopMovingToTarget();
	StopShooting();
}

// ATTACKING ENTITY

void ACanonLizard::LaunchTarget(AActor* targetActor) const
{
	if (IPhysicsEntity* target = Cast<IPhysicsEntity>(targetActor))
		target->LaunchEntity(GetLaunchVector(targetActor));
	/*if (ACharacter* target = Cast<ACharacter>(targetActor))
		target->LaunchCharacter(GetLaunchVector(targetActor), true, true);*/
}

FVector ACanonLizard::GetLaunchVector(AActor* targetActor) const
{
	float power = 1800.0f;
	return Super::GetLaunchVector(targetActor) * power + FVector(0, 0, 100);
}


FVector ACanonLizard::GetHitTraceStart() const
{
	return GetActorLocation() + GetActorRotation().Vector() * 40;
}

FVector ACanonLizard::GetHitTraceEnd() const
{
	return GetActorLocation() + GetActorRotation().Vector() * GetHitRange() * 0.75f;
}

bool ACanonLizard::IsTargetInAttackRange()
{
	if (TargetPlayer) {
		return FMath::Abs((GetActorLocation() - TargetPlayer->GetActorLocation()).Length()) <= GetHitRange();
	}
	return false;
}

bool ACanonLizard::IsAttacking() const
{
	return animInstance->isAttacking;
}

bool ACanonLizard::CanMove() const
{
	return !animInstance->isAttacking && !animInstance->isAttackOnCooldown;
}

void ACanonLizard::StartShooting()
{
	GetWorldTimerManager().ClearTimer(rotationTimerHandle);
	animInstance->DoShootAnim();
}

void ACanonLizard::StopShooting()
{
	animInstance->StopShooting();
}

bool ACanonLizard::IsTargetInRange()
{
	return FMath::Abs((GetActorLocation() - TargetPlayer->GetActorLocation()).Length()) <= GetSpitRange();
	//return (FMath::Abs(TargetPlayer->GetActorLocation() - GetActorLocation())).Length() <= ShootingRange;
}

void ACanonLizard::MoveToTarget()
{
	if (AIController) {
		AIController->MoveToActor(TargetPlayer, GetSpitRange());
	}
}

FRotator ACanonLizard::GetSmoothRotation() const
{
	if (TargetPlayer) {

		return UKismetMathLibrary::RInterpTo(
			GetActorRotation(),
			UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetPlayer->GetActorLocation()),
			0.01f,
			1);
	}
	return GetActorRotation();
}


void ACanonLizard::DoSmoothRotation()
{
	if (!isLookingAtTarget) {
		SetActorRotation(GetSmoothRotation());
		GetWorldTimerManager().SetTimer(rotationTimerHandle, this, &ACanonLizard::DoSmoothRotation, 0.01, true);
		animInstance->angularMomentum = PrimitiveComponent->GetPhysicsAngularVelocityInDegrees().GetComponentForAxis(EAxis::Z);
	}
}

void ACanonLizard::StopMovingToTarget()
{
	if (AIController) {
		AIController->StopMovement();
	}
}

void ACanonLizard::LaunchEntity(FVector direction)
{
	if (AIController) {
		AIController->StopMovement();
	}
	Super::LaunchEntity(direction);
	GetWorldTimerManager().SetTimer(roamTimer, this, &ACanonLizard::ResetRoam, 1.0f, false);
}

void ACanonLizard::ResetRoam()
{
	OnResetRoamEventTriggered.Broadcast();
}
