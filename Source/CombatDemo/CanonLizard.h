// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/HealthEntity.h"
#include "Interfaces/AttackingEntity.h"
#include "GameFramework/Character.h"
#include "CombatDemoCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "Components/PrimitiveComponent.h"
#include "CannonLizardAnimInstance.h"
#include "BaseCharacter.h"
#include "CannonLizardAttributeSet.h"
#include "Delegates/DelegateCombinations.h"

#include "CanonLizard.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMyEvent);

UCLASS()
class COMBATDEMO_API ACanonLizard : public ABaseCharacter, public IAttackingEntity
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACanonLizard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/////////////////////////////////////////////////////////////////////////////
	//	
	// 	   \\\         ///     ///\\\        /////////\\\      ///////\\\
	//		\\\       ///     ///  \\\       ///      \\\\    ///      \\\
	//		\\\       ///     ///  \\\       ///       |||   |||
	//		 \\\     ///     ///    \\\      ///       ///    \\\\
	//		 \\\     ///     ///    \\\      ///////////        \\\\\\\\\
	//		  \\\   ///     //////\\\\\\     ///   \\\                 \\\\
	//		  \\\   ///     ///      \\\     ///    \\\                 |||
	//		   \\\  ///     ///       \\\    ///     \\\     \\\        ///
	//		    \\\///     ///         \\\   ///      \\\     \\\/////////
	//	
	/////////////////////////////////////////////////////////////////////////////

private:
	FTimerHandle rotationTimerHandle;
	FTimerHandle roamTimer;
	UPrimitiveComponent* PrimitiveComponent;

	// COMPONENTS
protected:
	UCannonLizardAnimInstance* animInstance;

	AAIController* AIController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AttackAttributes")
	class UCannonLizardAttributeSet* AttackSet;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isLookingAtTarget = false;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACombatDemoCharacter* TargetPlayer;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnMyEvent OnResetRoamEventTriggered;

	/////////////////////////////////////////////////////////////////////////////
	//		
	//		///////////   ///      ///   \\\     \\\      ////\\\\
	//		///			  ///      ///   \\\\    \\\    ///     \\\
	//		///			  ///      ///   \\\\\   \\\   ///       \\\
	//		/////////	  ///      ///   \\\\\\  \\\   |||
	//		///			  ///      ///   \\\ \\\ \\\   |||
	//		///			  ///      ///   \\\  \\\\\\   |||
	//		///			  \\\      ///   \\\   \\\\\   \\\       ///
	//		///			   \\\    ///    \\\    \\\\    \\\     ///
	//		///			    \\\\////     \\\     \\\      \\\\////
	//		
	/////////////////////////////////////////////////////////////////////////////

	// GETTERS
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetDamage() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetHitRange() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetSpitDamage() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetSpitRange() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetIsLookingAtTarget() const;
	// INIT
protected:
	void SetAnimInstance();

	// HEALTH ENTITY
public:
	UFUNCTION(BlueprintCallable)
	float HealHealth(float amount);

	// ATTACKING ENTITY
public:

	UFUNCTION(BlueprintCallable)
	virtual void LaunchTarget(AActor* targetActor) const override;

	UFUNCTION(BlueprintCallable)
	virtual FVector GetLaunchVector(AActor* targetActor) const override;


public:
	UFUNCTION(BlueprintCallable)
	bool SetTarget(APawn* pawn);

	UFUNCTION(BlueprintCallable)
	void ClearTarget();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetHitTraceStart() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetHitTraceEnd() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsTargetInAttackRange();

	//UFUNCTION(BlueprintCallable)
	//void DoAttackAnim();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsAttacking() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanMove() const;

	UFUNCTION(BlueprintCallable)
	void StartShooting();

	UFUNCTION(BlueprintCallable)
	void StopShooting();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsTargetInRange();

	UFUNCTION(BlueprintCallable)
	void MoveToTarget();

	FRotator GetSmoothRotation() const;

	UFUNCTION(BlueprintCallable)
	void DoSmoothRotation();

	UFUNCTION(BlueprintCallable)
	void StopMovingToTarget();

	virtual void LaunchEntity(FVector direction) override;

	void ResetRoam();
};
