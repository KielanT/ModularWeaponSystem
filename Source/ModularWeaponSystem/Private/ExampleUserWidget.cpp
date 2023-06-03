// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleUserWidget.h"

#include "GunUserWidget.h"
#include "GunDataAsset.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "AssetRegistry/AssetRegistryModule.h"

bool UExampleUserWidget::Initialize()
{
	 Super::Initialize();
	
	return true;
}

void UExampleUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ShowGuns();
}

void UExampleUserWidget::ShowGuns()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	const UClass* Class = UGunDataAsset::StaticClass();
	TArray<FAssetData> GunAssetData;
	AssetRegistryModule.Get().GetAssetsByClass(Class->GetFName(), GunAssetData);
	int Index = 0;
	for(auto asset : GunAssetData)
	{
		if(GunWidget)
		{
			auto widget = CreateWidget<UGunUserWidget>(GetWorld(), GunWidget);
			widget->OnSelectedDelegate.AddDynamic(this, &UExampleUserWidget::SetBaseGun);
			
			auto Data = Cast<UGunDataAsset>(asset.GetAsset());
			widget->NameText->SetText(FText::FromString(Data->Name));
			GunList->AddChild(widget);
			Index++;
		}
	}
}

void UExampleUserWidget::SetBaseGun()
{
}
