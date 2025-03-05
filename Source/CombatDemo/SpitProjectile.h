// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "SpitProjectile.generated.h"

UCLASS()
class COMBATDEMO_API ASpitProjectile : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	class UAbilitySystemComponent* ActorASC;

public:	
	// Sets default values for this actor's properties
	ASpitProjectile();

public:
	// Ability System Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
