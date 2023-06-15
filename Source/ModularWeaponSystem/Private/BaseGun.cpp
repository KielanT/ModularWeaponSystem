// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGun.h"

#include "AttachmentDataAsset.h"
#include "GunDataAsset.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseGun::ABaseGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	
}

// Called when the game starts or when spawned
void ABaseGun::BeginPlay()
{
	Super::BeginPlay();

	SetupAttachments();
	
	// if(BarrelData)
	// {
	// 	if(auto value = BarrelData->Data.Find("Weight"))
	// 	{
	// 		if(value->DataType == EDataType::Float)
	// 		{
	// 			float OutFloat = value->GetDataValue().Get<float>();
	// 			UE_LOG(LogTemp, Warning, TEXT("Weight %f"), OutFloat);
	// 		}
	// 	}
	// }

	
}

void ABaseGun::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	
}

// Called every frame
void ABaseGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGun::ClearAttachments()
{
	if(!AttachmentComponents.IsEmpty())
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Cleared Attachments called"));
		for(auto& comp : AttachmentComponents)
		{
			comp->UnregisterComponent();
		}
		AttachmentComponents.Empty();
	}
}

void ABaseGun::SetGunAsset(TObjectPtr<UGunDataAsset> InGunAsset)
{
	GunDataAsset = InGunAsset;
	ClearAttachments();
	SetupAttachments();
}

void ABaseGun::SetupAttachments()
{
	if(GunDataAsset)
	{
		if(GunDataAsset->SkeletalMesh)
			SkeletalMeshComponent->SetSkeletalMesh(GunDataAsset->SkeletalMesh);

		
		for(auto& elem : GunDataAsset->SelectedAttachments)
		{
			if(auto& val = elem.Value)
			{
				TObjectPtr<UStaticMeshComponent> Component = NewObject<UStaticMeshComponent>(this);
				Component->SetStaticMesh(val->Mesh);

				FAttachmentTransformRules rules =  FAttachmentTransformRules::KeepWorldTransform;
				rules.LocationRule = val->AttachmentRules.Location;
				rules.RotationRule = val->AttachmentRules.Rotation;
				rules.ScaleRule = val->AttachmentRules.Scale;
				
				Component->AttachToComponent(SkeletalMeshComponent, rules, val->SocketName);
				Component->RegisterComponent();

				AttachmentComponents.Add(Component);
			}
		}

	}
}

