// Fill out your copyright notice in the Description page of Project Settings.


#include "GunUserWidget.h"
#include "Components/Button.h"

bool UGunUserWidget::Initialize()
{
	Super::Initialize();

	if(SelectedButton)
		SelectedButton->OnClicked.AddDynamic(this, &UGunUserWidget::OnClicked);
	
	return true;
}

void UGunUserWidget::OnClicked()
{
	OnSelectedDelegate.Broadcast();
}
