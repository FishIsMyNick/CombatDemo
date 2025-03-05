// Fill out your copyright notice in the Description page of Project Settings.


#include "SpitProjectile.h"

// Sets default values
ASpitProjectile::ASpitProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ActorASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ActorASC"));
}


// ABILITIES
UAbilitySystemComponent* ASpitProjectile::GetAbilitySystemComponent() const
{
	return ActorASC;// AbilitySystemComp;
}