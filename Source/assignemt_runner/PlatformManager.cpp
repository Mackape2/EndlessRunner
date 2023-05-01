// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformManager.h"

#include "RegularProjectile.h"


// Sets default values
APlatformManager::APlatformManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	hits = 0;
	GameSpeed = 2;
	ActorLife = 4;

}

// Called when the game starts or when spawned
void APlatformManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(hits<3)
	{
		timer+=DeltaTime;
        	projTimer+=DeltaTime;
        
        	if(GameSpeed <= 40)
        		GameSpeed+=DeltaTime;
        	
        	if(timer>=spawnTime/(GameSpeed/5))
        	{
        		timer = 0.f;
        		Platforms();
        	}
        	
        	if(projTimer >= spawnTime/(3+(GameSpeed/5)))
        	{
        		projTimer = 0.f;
        		Projectiles();
        	}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You lose"));
	}
	
}

void APlatformManager::Platforms()
{
	randomPlatform = FMath::RandRange(0,LevelParts.Num()-1);
	GetWorld()->SpawnActor<AActor>(LevelParts[randomPlatform], FVector(-1500,1750,-50),FRotator::ZeroRotator);
    	 
}

void APlatformManager::Projectiles()
{
	randomProjectile = FMath::RandRange(0,Projectile.Num()-1);
	while(randomNumber <= controllNumber+3 && randomNumber >= controllNumber - 3)
	{
		randomNumber = FMath::RandRange(0,35);
	}
	controllNumber = randomNumber;
	
	if(AActor* Actor = Cast<AActor>(GetWorld()->SpawnActor<AActor>(Projectile[randomProjectile], FVector(-1500,randomNumber * 100,100),FRotator::ZeroRotator)))
	{
		if(SpawnExplotion)
		{
			
			
		}
	}
}

void APlatformManager::Explode()
{
	SpawnExplotion = true;
	
}

