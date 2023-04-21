// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldMovement.generated.h"


UCLASS()
class ASSIGNEMT_RUNNER_API AWorldMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldMovement();
	FVector CurrentLocation;
	float speed;

private:
	float time;
	float death = 5.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void AReleased();
	
	
};
