// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Collectible.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"

AGM_Collectible::AGM_Collectible()
{
    // Initialisation des valeurs
    Score = 0;
    GameTime = 20.0f;
}

void AGM_Collectible::BeginPlay()
{
    Super::BeginPlay();
    GameTime = 20.0f;
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
   
    // Vérifiez si la classe de widget est assignée
    if (WB_HUDMINIGAME_Class)
    {
        // Créez une instance du widget
        UUserWidget* EndCollectibleInstance = CreateWidget<UUserWidget>(GetWorld(), WB_HUDMINIGAME_Class);

        if (EndCollectibleInstance)
        {
            // Ajoutez le widget au viewport pour l'afficher à l'écran
            EndCollectibleInstance->AddToViewport();
        }
    }
}