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
	
	SetupAttachments();
}

// Called every frame
void ABaseGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
				rules.LocationRule = EAttachmentRule::SnapToTarget;
				rules.RotationRule = EAttachmentRule::KeepWorld;
				
				Component->AttachToComponent(SkeletalMeshComponent, rules, val->SocketName);
				Component->RegisterComponent();
				//UE_LOG(LogTemp, Warning, TEXT("AttachmentName %s"), *val->Name.ToString());
			}
		}

	}
}

