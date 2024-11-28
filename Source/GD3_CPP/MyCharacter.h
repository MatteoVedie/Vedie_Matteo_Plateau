#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class GD3_CPP_API AMyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMyCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Score du joueur
    UPROPERTY(BlueprintReadOnly, Category = "Score")
    int32 PlayerScore;

    // Timer du jeu
    UPROPERTY(BlueprintReadOnly, Category = "Timer")
    float GameTime;

    // Fonctions pour collecter les objets et mettre à jour le score
    void CollectItem(int32 Points);

private:
    void MoveForward(float Value);
    void MoveRight(float Value);
    void UpdateGameTime();
};
