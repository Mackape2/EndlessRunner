// Fill out your copyright notice in the Description page of Project Settings.


#include "RegularProjectile.h"
#include "PlatformManager.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

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
	CurrentLocation = this->GetActorLocation();
}

// Called every frame
void ARegularProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	time += DeltaTime;
	
	CurrentLocation.X += 1.f * APlatformManager::GameSpeed;

	SetActorLocation(CurrentLocation);
	
	if(time >= APlatformManager::ActorLife*5/(APlatformManager::GameSpeed/5))
		Destroy();
}
void ARegularProjectile::OverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
			APlatformManager::hits += 1;
			Destroy();
			
		}
	}
}

