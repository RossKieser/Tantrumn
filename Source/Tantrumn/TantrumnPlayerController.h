// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TantrumnPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANTRUMN_API ATantrumnPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
protected:
	 void SetupInputComponent() override;

	 void RequestMoveForward(float AxisValue);
	 void RequestMoveRight(float AxisValue);
	 void RequestLookUp(float AxisValue);
	 void RequestLookRight(float AxisValue);
	 void RequestJump();

	 // Base lookup rate, in deg/sec. Other scaling may affect final lookup rate.
	 UPROPERTY(EditAnywhere, Category = "Look")
	 float BaseLookUpRate = 90.0f;

	 // Base lookright rate, in deg/sec. Other Scaling may affect final lookright rate.
	 UPROPERTY(EditAnywhere, Category = "Look")
	 float BaseLookRightRate = 90.0f; 
};


