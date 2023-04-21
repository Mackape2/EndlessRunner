// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformManager.h"

#include "WorldMovement.h"


// Sets default values
APlatformManager::APlatformManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatformManager::BeginPlay()
{
	Super::BeginPlay();
	controllNumber = 0;
	
}



// Called every frame
void APlatformManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	PlayTime+=DeltaTime;
	timer+=DeltaTime;
	
	if(timer>=cooldown)
	{
		timer = 0;
		while(randomNumber <= controllNumber+3 && randomNumber >= controllNumber - 3)
		{
			randomNumber = FMath::RandRange(0,35);
		}
		controllNumber = randomNumber;
		int randomPart = FMath::RandRange(0,LevelParts.Num()-1);
		AActor* actor = GetWorld()->SpawnActor<AActor>(LevelParts[randomPart], FVector(0,randomNumber * 100,0),FRotator::ZeroRotator);
		Cast<AWorldMovement>(actor)->speed = 5.f * PlayTime;
	}
}


