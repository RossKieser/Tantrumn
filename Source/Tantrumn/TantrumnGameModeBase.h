// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TantrumnGameWidget.h"
#include "GameFramework/GameModeBase.h"
#include "TantrumnGameModeBase.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
	None UMETA(DisplayName = "None"),
	Waiting UMETA(DisplayName = "Waiting"),
	Playing UMETA(DisplayName = "Playing"),
	Paused UMETA(DisplayName = "Paused"),
	GameOver UMETA(DisplayName = "GameOver"),
};


UCLASS()
class TANTRUMN_API ATantrumnGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATantrumnGameModeBase();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	EGameState GetCurrentGameState() const;

	void PlayerReachedEnd();

private:
	// --- VARS --- //

	// Create and set CurrentGameState to NONE. This will be tracked in the code file. 
	UPROPERTY(VisibleAnywhere, Category = "States")
	EGameState CurrentGameState = EGameState::None;
	
	// Countdown before gameplay state begins. Exposed so we can easily change this in BP editor. 
	UPROPERTY(EditAnywhere, Category = "Game Details")
	float GameCountdownDuration = 4.0f;

	FTimerHandle TimerHandle;

	UPROPERTY()
	UTantrumnGameWidget* GameWidget; // Object we'll be creating and adding to the Viewport
	
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UTantrumnGameWidget> GameWidgetClass; // Exposed class to check the type of widget to display

	APlayerController* PC = nullptr;

	// --- FUNCTIONS --- //

	void DisplayCountdown();
	void StartGame();

};


