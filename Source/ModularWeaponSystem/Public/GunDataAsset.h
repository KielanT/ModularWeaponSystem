// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GunDataAsset.generated.h"

class UAttachmentDataAsset;
/**
 * 
 */
UCLASS()
class MODULARWEAPONSYSTEM_API UGunDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UTexture> ImageIcon;

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	TMap<FString, TObjectPtr<UAttachmentDataAsset>> SelectedAttachments;
	
	UPROPERTY(EditAnywhere)
	TArray<TObjectPtr<UAttachmentDataAsset>> CompatibleAttachments;
};
