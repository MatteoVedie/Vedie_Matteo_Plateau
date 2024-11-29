// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "GM_Collectible.h"

ACollectible::ACollectible()
{
	PrimaryActorTick.bCanEverTick = true;

    // Déclare le composant mais ne lui attribue pas de maillage par défaut
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;

    // Définition des collisions (Overlap)
    Mesh->SetCollisionProfileName("OverlapAllDynamic");

    // Points par défaut
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
    // Vérifie si c'est un personnage qui interagit
    ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);
    if (PlayerCharacter)
    {
        // Récupère le GameMode actuel
        AGM_Collectible* GameMode = Cast<AGM_Collectible>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            // Ajoute les points au score via le GameMode
            GameMode->AddToScore(Points);
        }
        // Détruit l'objet après interaction
        Destroy();
    }
}
