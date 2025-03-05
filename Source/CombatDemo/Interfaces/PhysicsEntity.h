// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PhysicsEntity.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI)
class UPhysicsEntity : public UInterface
{
	GENERATED_BODY()
};

class IPhysicsEntity
{
	GENERATED_BODY()
public:
	virtual void LaunchTarget(AActor* targetActor) const;
	virtual void LaunchEntity(FVector direction);
	virtual FVector GetLaunchVector(AActor* targetActor) const;
};
