// Fill out your copyright notice in the Description page of Project Settings.


#include "CannonLizardAnimInstance.h"

void UCannonLizardAnimInstance::DoAttackAnim()
{
	if (!isAttacking && !isAttackOnCooldown)
		isAttacking = true;
}

void UCannonLizardAnimInstance::DoShootAnim()
{
	//if (!isShooting && !isAttackOnCooldown)
		isShooting = true;
}

void UCannonLizardAnimInstance::StopShooting()
{
	SetShootingOff();
}

void UCannonLizardAnimInstance::SetAttackingOff()
{
	isAttackOnCooldown = true;
	GetWorld()->GetTimerManager().SetTimer(stateSetTimerHandle, this, &UCannonLizardAnimInstance::TurnOffAttackCooldown, 0.5f, false);
	isAttacking = false;
}

void UCannonLizardAnimInstance::SetShootingOff()
{
	isAttackOnCooldown = true;
	GetWorld()->GetTimerManager().SetTimer(stateSetTimerHandle, this, &UCannonLizardAnimInstance::TurnOffAttackCooldown, 0.5f, false);
	isShooting = false;
}

void UCannonLizardAnimInstance::TurnOffAttackCooldown() {
	isAttackOnCooldown = false;
}

float UCannonLizardAnimInstance::GetVelocity() const
{
	if (owner)
		return owner->GetVelocity().Length();
	return 0.0f;
}
