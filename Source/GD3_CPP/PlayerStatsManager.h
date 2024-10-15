// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerStatsManager.generated.h"

UCLASS()
class GD3_CPP_API APlayerStatsManager : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	APlayerStatsManager();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PlayersNumber;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void InitializeStats(int32 playernumber);

	UFUNCTION(BlueprintCallable)
	void NbrOfSixByPlayersId(int32 nbr);
};	
