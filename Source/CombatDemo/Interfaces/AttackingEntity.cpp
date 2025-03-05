// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackingEntity.h"

// Add default functionality here for any IAttackingEntity functions that are not pure virtual.

//void IAttackingEntity::Attack() const{}

void IAttackingEntity::DealDamageToTarget(AActor* targetActor) const
{
}

void IAttackingEntity::LaunchTarget(AActor* targetActor) const
{
}

FVector IAttackingEntity::GetLaunchVector(AActor* targetActor) const
{
	return FVector();
}
