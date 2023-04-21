// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveblePawn.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"


// Sets default values
AMoveblePawn::AMoveblePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMoveblePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveblePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// void AMoveblePawn::Move(const FInputActionValue& Value)
// {
// 	// input is a Vector2D
// 	FVector2D MovementVector = Value.Get<FVector2D>();
//
// 	if (Controller != nullptr)
// 	{
// 		// find out which way is forward
// 		const FRotator Rotation = Controller->GetControlRotation();
// 		const FRotator YawRotation(0, Rotation.Yaw, 0);
//
// 		// get forward vector
// 		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
// 	
// 		// get right vector 
// 		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
//
// 		// add movement 
// 		AddMovementInput(ForwardDirection, MovementVector.Y);
// 		AddMovementInput(RightDirection, MovementVector.X);
// 	}
// }
//
// // Called to bind functionality to input
// void AMoveblePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
// {
// 	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
// }

