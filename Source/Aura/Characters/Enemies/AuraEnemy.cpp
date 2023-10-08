// Fill out your copyright notice in the Description page of Project Settings.


#include "Aura/Characters/Enemies/AuraEnemy.h"
#include "Aura/Interfaces/EnemyInterface.h"
void AAuraEnemy::HighlightActor()
{
	bHighlight = true;
	UE_LOG(LogTemp, Warning, TEXT("Highlight!"));
	GetMesh()->SetRenderCustomDepth(true);
	WeaponMesh->SetRenderCustomDepth(true);
}
void AAuraEnemy::UnHighlightActor()
{
	bHighlight = false;
	UE_LOG(LogTemp, Warning, TEXT("UnHighlight!"));
	GetMesh()->SetRenderCustomDepth(false);
	WeaponMesh->SetRenderCustomDepth(false);
}
