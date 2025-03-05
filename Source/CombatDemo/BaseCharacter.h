// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayEffectTypes.h"
#include "CharacterGameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "HealthAttributeSet.h"
#include "MovingAttributeSet.h"
#include "Interfaces/PhysicsEntity.h"

#include "BaseCharacter.generated.h"

UCLASS()
class COMBATDEMO_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface, public IPhysicsEntity
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//TIMER
protected:
	FTimerHandle LaunchTagTimerHandle;

	// ABILITIES
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	class UHealthAttributeSet* HealthSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	class UMovingAttributeSet* MovingSet;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<class UCharacterGameplayAbility>> DefaultAbilities;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects")
	TArray<TSubclassOf<class UGameplayEffect>> DefaultEffects;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	class UAbilitySystemComponent* CharacterASC;

public:
	// Ability System Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ability")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ability")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetHealth(float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ability")
	float GetShield() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ability")
	float GetMaxShield() const;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetShield(float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ability")
	float GetStamina() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ability")
	float GetMaxStamina() const;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetStamina(float Value);
	
	//UI
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ability")
	float GetHealthPercentage() const;

// Inits
	virtual void InitializeAbilities();
	virtual void InitializeEffects();
	void InitializeACS();

	virtual void PostInitializeComponents() override;

	// State changes
	virtual void OnDamageTakenChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayTagContainer& GameplayTagContainer, float Damage);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ability")
	void OnDamageTaken(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayTagContainer& GameplayTagContainer, float Damage);

	virtual void OnHealthAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ability")
	void OnHealthChanged(float OldValue, float NewValue);

	virtual void OnShieldAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ability")
	void OnShieldChanged(float OldValue, float NewValue);

	virtual void OnStaminaAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ability")
	void OnStaminaChanged(float OldValue, float NewValue);


	// Function that will be called when damage is taken
	void OnDamageTakenCallback(AActor* EffectInstigator, AActor* EffectCauser, const FGameplayTagContainer& GameplayTags, float Damage);

	UFUNCTION(BlueprintNativeEvent)
	void Die();

	void OnGameplayTagChanged(const FGameplayTag Tag, int32 NewCount);

	void HandleInputBlocking(bool Value);

	void HandleInputBlockingAllowRotation(bool Value);
	//

// Physics
	virtual void LaunchTarget(AActor* targetActor) const override;
	virtual void LaunchEntity(FVector direction) override;
	virtual FVector GetLaunchVector(AActor* targetActor) const override;
};
