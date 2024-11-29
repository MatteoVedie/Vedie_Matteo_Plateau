// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectible.generated.h"

UCLASS()
class GD3_CPP_API ACollectible : public AActor
{
	GENERATED_BODY()
	
public:	
	ACollectible();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public :
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	// Points attribu�s (positifs ou n�gatifs)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Collectible")
	int32 Points;

	// R�f�rence au Mesh (g�r� dans le Blueprint)
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collectible", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;
};
