// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/HealthStaminaEntity.h"
#include "Interfaces/AttackingEntity.h"
#include "Logging/LogMacros.h"
#include "Math/UnrealMathUtility.h"
#include "UI/PlayerStats.h"
#include "BaseCharacter.h"

#include "CombatDemoCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);



UCLASS(config = Game)
class ACombatDemoCharacter : public ABaseCharacter
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

public:
	ACombatDemoCharacter();

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AbilityAction;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void SendAbilityLocalInput(const FInputActionValue& Value, int32 InputID);

	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }



	/////////////////////////////////////////////////////////////////////////////
	/// 
	/// 	 ///////\	///	    ///	  /////\\\	 ////////////  ///\\	  /////
	/// 	///	   \\\	///     ///	 ///	\\\  	 ///	   ///\\\	 //////
	/// 	///			///	    ///	 |||			 ///	   /// \\\ /// ///
	/// 	///			///	    ///	 \\\			 ///	   ///	\\\///  ///
	/// 	///			///	    ///   \\\\\\		 ///	   ///	 \\//   ///
	/// 	///			///     ///	 	   \\\		 ///	   ///	  \/    ///
	///		\\\	   /// 	\\\	    ///	 \\\   /|||		 ///	   ///		    ///
	///		 \\//////	  \\\\////	  \\\/////		 ///	   ///		    ///
	/// 
	/////////////////////////////////////////////////////////////////////////////





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

	// COMPONENTS

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

	// UI AND STATS

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPlayerStats* statsUI;

	FTimerHandle staminaTimerHandle;
	FTimerHandle staminaRegenLoopHandle;

	FTimerHandle healthTimerHandle;
	FTimerHandle healthRegenLoopHandle;

	// STATE
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackState")
	bool isHitting = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackState")
	bool isKicking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementState")
	bool isDashing = false;


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

		// HEALTH STAMINA ENTITY
public:
	virtual void OnHealthAttributeChanged(const FOnAttributeChangeData& Data) override;
	virtual void OnShieldAttributeChanged(const FOnAttributeChangeData& Data) override;
	virtual void OnStaminaAttributeChanged(const FOnAttributeChangeData& Data) override;

private:

	UFUNCTION(BlueprintCallable)
	void SetRandomPunchAnim();

	UFUNCTION(BlueprintCallable)
	void SetRandomKickAnim();


	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetEnemyLaunchVector(AActor* targetActor) const;

	UFUNCTION(BlueprintCallable)
	virtual void LaunchTarget(AActor* targetActor) const override;

	// ABILITIES
	void Ability(const FInputActionValue& Value);

};
