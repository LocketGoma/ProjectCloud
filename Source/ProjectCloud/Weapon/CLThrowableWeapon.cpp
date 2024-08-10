// Fill out your copyright notice in the Description page of Project Settings.


#include "CLThrowableWeapon.h"

void ACLThrowableWeapon::SetTargetLocation()
{
}

void ACLThrowableWeapon::ThrowWeapon()
{
	bLaunch = true;

	SetThrowtrajectory();
	MoveThrowWeapon();
	K2_ThrowWeapon();
}

void ACLThrowableWeapon::K2_ThrowWeapon_Implementation()
{
	//Do Something
}
