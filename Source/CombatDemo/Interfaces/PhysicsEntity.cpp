// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsEntity.h"

void IPhysicsEntity::LaunchTarget(AActor* targetActor) const
{
}

void IPhysicsEntity::LaunchEntity(FVector direction)
{
}

FVector IPhysicsEntity::GetLaunchVector(AActor* targetActor) const
{
    return FVector();
}

