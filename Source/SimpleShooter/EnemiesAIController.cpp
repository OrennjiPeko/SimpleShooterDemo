// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemiesAIController.h"
#include "kismet/GameplayStatics.h"
#include "BehaviorTree\BlackboardComponent.h"
#include "PlayerCharacter.h"
void AEnemiesAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr) 
	{
		RunBehaviorTree(AIBehavior);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}

void AEnemiesAIController::Tick(float DeltaSeconds) 
{
	Super::Tick(DeltaSeconds);
}

bool AEnemiesAIController::IsDead() const
{
	APlayerCharacter* ControlledCharacter = Cast<APlayerCharacter>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsDead();
	}

	return true;
}
