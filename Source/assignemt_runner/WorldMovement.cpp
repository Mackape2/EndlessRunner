// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMovement.h"
#include "InputCoreTypes.h"
#include "Kismet/KismetMathLibrary.h"
#include "assignemt_runnerCharacter.h"
#include "InputTriggers.h"


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
	check(InputComponent);
	InputComponent->BindAction("APressed", IE_Released ,this ,AWorldMovement::AReleased());
	CurrentLocation = this->GetActorLocation();
	
}

void AWorldMovement::AReleased()
{
	CurrentLocation.Y += 300.f;
}


// Called every frame
void AWorldMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	time += DeltaTime;
	
	CurrentLocation.X += speed;

	SetActorLocation(CurrentLocation);
	

	
	if(time >= death)
		Destroy();
	
}

