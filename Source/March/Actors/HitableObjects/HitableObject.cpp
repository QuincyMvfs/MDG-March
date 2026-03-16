// Fill out your copyright notice in the Description page of Project Settings.


#include "HitableObject.h"

// Sets default values
AHitableObject::AHitableObject()
{
}

void AHitableObject::OnHit_Implementation()
{
	IHitableInterface::OnHit_Implementation();
}

// Called when the game starts or when spawned
void AHitableObject::BeginPlay()
{
	Super::BeginPlay();
	
}


