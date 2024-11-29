// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "GM_Collectible.h"

ACollectible::ACollectible()
{
	PrimaryActorTick.bCanEverTick = true;

    // D�clare le composant mais ne lui attribue pas de maillage par d�faut
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;

    // D�finition des collisions (Overlap)
    Mesh->SetCollisionProfileName("OverlapAllDynamic");

    // Points par d�faut
    Points = 10;
}

void ACollectible::BeginPlay()
{
	Super::BeginPlay();
}

void ACollectible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    FRotator RotationIncrement(0.0f, 1.0f, 0.0f);
    AddActorLocalRotation(RotationIncrement);
}

void ACollectible::NotifyActorBeginOverlap(AActor* OtherActor)
{
    // V�rifie si c'est un personnage qui interagit
    ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);
    if (PlayerCharacter)
    {
        // R�cup�re le GameMode actuel
        AGM_Collectible* GameMode = Cast<AGM_Collectible>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            // Ajoute les points au score via le GameMode
            GameMode->AddToScore(Points);
        }
        // D�truit l'objet apr�s interaction
        Destroy();
    }
}
