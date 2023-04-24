// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../Plugins/Developer/RiderLink/Source/RD/thirdparty/clsocket/src/ActiveSocket.h"
#include "GameFramework/Actor.h"
#include "PlatformManager.generated.h"

UCLASS()
class ASSIGNEMT_RUNNER_API APlatformManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformManager();
	UPROPERTY(EditAnywhere)
		TArray<TSubclassOf<AActor>>LevelParts;
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>>Projectile;
	float PlayTime;
	static inline float hits;
	static inline float GameSpeed;
	static inline float ActorLife;
	

private:
	float timer;
	float projTimer;
	float spawnTime = 1.f;
	
	int randomNumber;
	int controllNumber;
	int randomPlatform;
	int randomProjectile;
	
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Platforms();

	virtual void Projectiles();
	

};
