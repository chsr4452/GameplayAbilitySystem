// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");

	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->TargetArmLength = 1200;
	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritYaw= false;
	SpringArmComponent->bInheritRoll= false;
	// SpringArmComponent->SetUsingAbsoluteRotation(true);
	// FRotator CameraRotation(70.f, 0.f, 0.f);
	// SpringArmComponent->SetWorldRotation(CameraRotation);


}
