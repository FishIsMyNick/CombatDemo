// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Logging/LogMacros.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "UI/PlayerStats.h"

#include "AbilityCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
//
//UENUM(BlueprintType)
//enum class EAttackNotifyType : uint8
//{
//	LightHitStart UMETA(DisplayName = "LightHitStart"),
//	HeavyHitStart UMETA(DisplayName = "HeavyHitStart"),
//	LightKickStart UMETA(DisplayName = "LightKickStart"),
//	HeavyKickStart UMETA(DisplayName = "HeavyKickStart"),
//	LightHit UMETA(DisplayName = "LightHit"),
//	HeavyHit UMETA(DisplayName = "HeavyHit"),
//	LowKick UMETA(DisplayName = "LowKick"),
//	MidKick UMETA(DisplayName = "MidKick"),
//	HighKick UMETA(DisplayName = "HighKick"),
//	HitEnd UMETA(DisplayName = "HitEnd"),
//	AttackEnd UMETA(DisplayName = "AttackEnd")
//};
//
//UENUM(BlueprintType)
//enum class EDashNotifyType : uint8
//{
//	SmallDashStart UMETA(DisplayName = "SmallDashStart"),
//	BigDashStart UMETA(DisplayName = "BigDashStart"),
//	SmallDash UMETA(DisplayName = "SmallDash"),
//	BigDash UMETA(DisplayName = "BigDash"),
//	DashEnd UMETA(DisplayName = "DashEnd"),
//	FullDashEnd UMETA(DisplayName = "FullDashEnd")
//};
/**
 * 
 */
UCLASS()
class COMBATDEMO_API AAbilityCharacter : public ABaseCharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* Attack1Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* Attack2Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* DashAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AbilityAction;

public:
	AAbilityCharacter();

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);


protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// To add mapping context
	virtual void BeginPlay();

	virtual void SendAbilityLocalInput(const FInputActionValue& Value, int32 InputID);

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


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

//UI
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	UPlayerStats* StatsUI;

// ATTACKS AND ABILITIES
protected:
	void Attack1(const FInputActionValue& Value);
	void Attack2(const FInputActionValue& Value);
	void Dash(const FInputActionValue& Value);
	void Ability(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	bool isAttacking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	bool canSwapAttack = true;

// DASHING
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dashing")
	bool isDashing = false;

// ANIMATION
protected:

	UAnimInstance* attackAnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* currentAttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* currentDashMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UAnimMontage*> punchAttackMontages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UAnimMontage*> kickAttackMontages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* dashMontage;

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
protected:
	virtual void OnHealthAttributeChanged(const FOnAttributeChangeData& Data) override;
	virtual void OnShieldAttributeChanged(const FOnAttributeChangeData& Data) override;
	virtual void OnStaminaAttributeChanged(const FOnAttributeChangeData& Data) override;

// Combat
public:
	/*UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CheckIsAttackMontagePunch() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CheckIsPunchAttackStartAllowed() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CheckIsAttackMontageKick() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CheckIsKickAttackStartAllowed() const;

	UFUNCTION(BlueprintCallable)
	void SetRandomPunchAnim();

	UFUNCTION(BlueprintCallable)
	void SetRandomKickAnim();

	UFUNCTION(BlueprintCallable)
	void StopAttackMontage();

	UFUNCTION(BlueprintCallable)
	void StopDashMontage();*/
};
