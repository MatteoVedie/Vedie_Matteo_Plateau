#include "MyCharacter.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

AMyCharacter::AMyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialisation des variables
    PlayerScore = 0;
    GameTime = 60.0f; // Temps total du jeu en secondes
}

void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();

    // Lancer le timer
    GetWorldTimerManager().SetTimer(
        FTimerHandle(), this, &AMyCharacter::UpdateGameTime, 1.0f, true);
}

void AMyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
}

void AMyCharacter::MoveForward(float Value)
{
    AddMovementInput(GetActorForwardVector(), Value);
}

void AMyCharacter::MoveRight(float Value)
{
    AddMovementInput(GetActorRightVector(), Value);
}

void AMyCharacter::UpdateGameTime()
{
    GameTime -= 1.0f;
    if (GameTime <= 0.0f)
    {
        // Arrêter le jeu
        UE_LOG(LogTemp, Warning, TEXT("Game Over!"));
        GetWorldTimerManager().ClearAllTimersForObject(this);

        // Afficher le widget de fin (vous le configurez dans Blueprint)
    }
}

void AMyCharacter::CollectItem(int32 Points)
{
    PlayerScore += Points;
    UE_LOG(LogTemp, Log, TEXT("Score: %d"), PlayerScore);
}
