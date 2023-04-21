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

	

private:
	float PlayTime;
	float timer;
	float cooldown = 1.f;
	int randomNumber;
	int controllNumber;
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
