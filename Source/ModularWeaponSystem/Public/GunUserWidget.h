// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GunUserWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelecteGunSignature, UGunDataAsset*, InGunAsset);

class UTextBlock;
class UButton;

UCLASS()
class MODULARWEAPONSYSTEM_API UGunUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;



public:	
	void SetAsset(TObjectPtr<UGunDataAsset> InGunAsset);

private:
	UFUNCTION()
	void OnClicked();

public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> NameText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> SelectedButton;

	FOnSelecteGunSignature OnSelectedDelegate;

private:
	UPROPERTY()
		TObjectPtr<UGunDataAsset> GunAsset;
};
