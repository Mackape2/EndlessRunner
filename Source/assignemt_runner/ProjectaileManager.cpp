// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectaileManager.h"

// Sets default values
AProjectaileManager::AProjectaileManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectaileManager::BeginPlay()
{
	Super::BeginPlay();
	controllNumber = 0;
	
}

// Called every frame
void AProjectaileManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timer+=DeltaTime;
	
	if(timer>= cooldown)
	{
		timer = 0.f;

		int randomPart = FMath::RandRange(0,LevelParts.Num()-1);
		while(randomNumber <= controllNumber+3 && randomNumber >= controllNumber - 3)
		{
			randomNumber = FMath::RandRange(0,35);
		}
		controllNumber = randomNumber;
		AActor* actor = GetWorld()->SpawnActor<AActor>(LevelParts[randomPart], FVector(0,randomNumber * 100,500),FRotator::ZeroRotator);
	}
}

