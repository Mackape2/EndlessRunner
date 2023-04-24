// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorTile.h"
#include "PlatformManager.h"


// Sets default values
AFloorTile::AFloorTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloorTile::BeginPlay()
{
	Super::BeginPlay();
	CurrentLocation = this->GetActorLocation();
}

// Called every frame
void AFloorTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	time += DeltaTime;
	
	CurrentLocation.X += 1.f * APlatformManager::GameSpeed;

	SetActorLocation(CurrentLocation);
	
	if(time >= (APlatformManager::ActorLife*3)/(APlatformManager::GameSpeed/5))
		Destroy();

}

