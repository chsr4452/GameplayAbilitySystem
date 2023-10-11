// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "AuraPlayerController.h"
#include "Aura/AbilitySystem/AuraAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Aura/Characters/Aura/AuraPlayerState.h"
#include "Aura/UI/HUD/AuraHUD.h"


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

	SpringArmComponent->TargetArmLength = 800;
	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritYaw= false;
	SpringArmComponent->bInheritRoll= false;
	// SpringArmComponent->SetUsingAbsoluteRotation(true);
	// FRotator CameraRotation(70.f, 0.f, 0.f);
	// SpringArmComponent->SetWorldRotation(CameraRotation);


}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	// InitAbilityActorInfo for a server.
	InitAbilityActorInfo();
	
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// InitAbilityActorInfo for a client.
	InitAbilityActorInfo();
	
}


void AAuraCharacter::InitAbilityActorInfo()
{	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
 	check(AuraPlayerState);
	if(AuraPlayerState == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Nullptr"));
	}
 	// AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
 	//  AttributeSet = AuraPlayerState->GetAttributeSet();
  //    AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);

	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();

	if(AAuraPlayerController* PC =  Cast<AAuraPlayerController>(GetController()))
	{
			if(AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD()))
			{
				AuraHUD->InitOverlay(PC, AuraPlayerState, AbilitySystemComponent, AttributeSet);
			}
		
	}

}

