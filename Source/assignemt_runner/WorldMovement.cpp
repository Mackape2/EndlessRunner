// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMovement.h"

#include "PlatformManager.h"


// Sets default values
AWorldMovement::AWorldMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentLocation = this->GetActorLocation();

}

// Called when the game starts or when spawned
void AWorldMovement::BeginPlay()
{
	Super::BeginPlay();
	CurrentLocation = this->GetActorLocation();
	
}


// Called every frame
void AWorldMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	time += DeltaTime;
	
	CurrentLocation.X += 1.f * APlatformManager::GameSpeed;

	SetActorLocation(CurrentLocation);
	
	
	if(time >= death)
		Destroy();
	
}

