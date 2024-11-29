// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "GM_Collectible.generated.h"

/**
 * Classe de GameMode pour g�rer le score et le timer.
 */
UCLASS()
class GD3_CPP_API AGM_Collectible : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGM_Collectible();


protected:
	virtual void BeginPlay() override;
	
public:
    // Variable pour le score du joueur
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
    int32 Score;

    // Variable pour le temps de jeu
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Timer")
    float GameTime;

    // Fonction pour ajouter des points au score
    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddToScore(int32 Points);

    // Fonction pour mettre � jour le timer
    UFUNCTION(BlueprintCallable, Category = "Timer")
    void UpdateTimer();

    // Fonction pour r�cup�rer le score actuel
    UFUNCTION(BlueprintCallable, Category = "HUD")
    int32 GetScore() const { return Score; }

    // Fonction pour r�cup�rer le temps de jeu actuel
    UFUNCTION(BlueprintCallable, Category = "HUD")
    float GetGameTime() const { return GameTime; }

    // Fonction pour arr�ter le jeu lorsque le temps est �coul�
    UFUNCTION(BlueprintCallable, Category = "HUD")

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UUserWidget> WB_HUDMINIGAME_Class;  // R�f�rence � la classe de widget
    void EndGame();

private:

    FTimerHandle GameTimerHandle;
};
