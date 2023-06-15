// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGun.generated.h"

class UGunDataAsset;
UCLASS()
class MODULARWEAPONSYSTEM_API ABaseGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void ClearAttachments();

	void SetGunAsset(TObjectPtr<UGunDataAsset> InGunAsset);
	
private:
	void SetupAttachments();

	
private:
	UPROPERTY(EditAnywhere)
		TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY()
		TArray<TObjectPtr<UStaticMeshComponent>> AttachmentComponents;
	
	UPROPERTY(EditAnywhere)
		TObjectPtr<UGunDataAsset> GunDataAsset;
};
