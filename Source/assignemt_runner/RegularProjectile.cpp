// Fill out your copyright notice in the Description page of Project Settings.


#include "RegularProjectile.h"
#include "PlatformManager.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "assignemt_runnerCharacter.h"

// Sets default values
ARegularProjectile::ARegularProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Trigger = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	Trigger->InitCapsuleSize(57.f,60.f);
	Trigger->SetCollisionProfileName(TEXT("Trigger"));
	Trigger->SetupAttachment(RootComponent);
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ARegularProjectile::OverlapBegin);

}

// Called when the game starts or when spawned
void ARegularProjectile::BeginPlay()
{
	Super::BeginPlay();
	currentLocation = this->GetActorLocation();
	killzoneLocation = currentLocation + 2000;
	if(APlatformManager::SpawnExplotion)
	{
		killSwitch = true;
		GEngine->AddOnScreenDebugMessage(-1,1,FColor::Black,"Boom");
		APlatformManager::SpawnExplotion = false;
	}

}

// Called every frameSSSS
void ARegularProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	time += DeltaTime;
	
	currentLocation.X += 1.f * APlatformManager::GameSpeed;

	SetActorLocation(currentLocation);
	
	if(killSwitch)
		if(currentLocation.X >= killzoneLocation.X)
		{
			DrawDebugSphere(GetWorld(),this->GetActorLocation(),50.f,50,FColor::Yellow,false,1);
			Destroy();
		}
		
	if(currentLocation.X >= Aassignemt_runnerCharacter::startLocation.X + 200)
	{
		
		if( FMath::RandRange(1,5) == 2)
		{
			APlatformManager::Explode();
			GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,"Boom");
		}
		Destroy();
	}
}


void ARegularProjectile::OverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
			APlatformManager::hits += 1;
			Destroy();
	}
}

