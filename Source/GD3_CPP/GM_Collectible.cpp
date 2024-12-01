// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Collectible.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/World.h"

AGM_Collectible::AGM_Collectible()
{
    // Initialisation des valeurs
    Score = 0;
    GameTime = 50.0f;
}

void AGM_Collectible::BeginPlay()
{
    Super::BeginPlay();
    GameTime = 80.0f;
    UE_LOG(LogTemp, Warning, TEXT("Le jeu commence avec GameTime = %.2f"), GameTime);
    // Démarrer un timer pour mettre à jour la variable GameTime
    GetWorld()->GetTimerManager().SetTimer(GameTimerHandle, this, &AGM_Collectible::UpdateTimer, 1.0f, true);
}

void AGM_Collectible::AddToScore(int32 Points)
{
    Score += Points;
}

void AGM_Collectible::UpdateTimer()
{
    GameTime -= 1.0f;

    if (GameTime <= 0.0f)
    {
        GameTime = 0.0f;
        EndGame();
    }
}

void AGM_Collectible::EndGame()
{
    // Code pour arrêter le jeu, par exemple, afficher un écran de fin ou arrêter le niveau
    UGameplayStatics::SetGamePaused(GetWorld(), true);
    // Vérifie si le niveau "Game" existe et l'ouvre
    UGameplayStatics::OpenLevel(GetWorld(), FName("Game"));
}