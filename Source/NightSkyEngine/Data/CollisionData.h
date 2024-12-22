﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "PaperFlipbook.h"
#include "NightSkyEngine/Battle/CollisionBox.h"
#include "CollisionData.generated.h"

USTRUCT()
struct FAnimStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName PartName = "Body";
	UPROPERTY(EditAnywhere)
	UAnimSequenceBase* AnimSequence;
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* Flipbook;
};

USTRUCT()
struct FCollisionStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FGameplayTag CelName;
	UPROPERTY(EditAnywhere)
	TArray<FAnimStruct> Anim;
	UPROPERTY(EditAnywhere)
	int32 AnimFrame = 0;
	UPROPERTY(EditAnywhere)
	TArray<FCollisionBox> Boxes;
};

/**
 * 
 */
UCLASS()
class NIGHTSKYENGINE_API UCollisionData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FCollisionStruct> CollisionFrames;

	FCollisionStruct GetByCelName(const FGameplayTag& CelName)
	{
		for (auto& CollisionFrame : CollisionFrames)
		{
			if (CollisionFrame.CelName == CelName) return CollisionFrame;
		}
		return FCollisionStruct();
	}
};
