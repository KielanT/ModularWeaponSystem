// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ExampleUserWidget.generated.h"

class UGunUserWidget;
/**
 * 
 */
UCLASS()
class MODULARWEAPONSYSTEM_API UExampleUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

	virtual void NativeConstruct() override;

private:
	void ShowGuns();

	UFUNCTION()
	void SetBaseGun();
private:
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UPanelWidget> GunList;

	//UPROPERTY(meta = (BindWidget))
	//TObjectPtr<UPanelWidget> BarrelAttachmentList;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UGunUserWidget> GunWidget;
};
