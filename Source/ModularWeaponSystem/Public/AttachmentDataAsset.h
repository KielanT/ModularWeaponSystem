// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <variant>

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AttachmentDataAsset.generated.h"

UENUM()
enum class EDataType : uint8
{
	Integer,
	Float,
	String,
	Boolean,
	Vector,
};


USTRUCT()
struct FDataEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EDataType DataType;

	TVariant<int32, float, FString, bool, FVector> GetDataValue();
	
private:
	UPROPERTY(EditAnywhere, meta = (EditCondition = "DataType == EDataType::Integer", EditConditionHides))
	int32 IntegerValue;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "DataType == EDataType::Float", EditConditionHides))
	float FloatValue;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "DataType == EDataType::String", EditConditionHides))
	FString StringValue;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "DataType == EDataType::Boolean", EditConditionHides))
	bool BoolValue;
	
	UPROPERTY(EditAnywhere, meta = (EditCondition = "DataType == EDataType::Vector", EditConditionHides))
	FVector VectorValue;
};

UCLASS()
class MODULARWEAPONSYSTEM_API UAttachmentDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMesh> Mesh;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UTexture2D> ImageIcon;
	
	UPROPERTY(EditAnywhere)
	FName Name;

	UPROPERTY(EditAnywhere)
	FName SocketName;
	
	UPROPERTY(EditAnywhere, Category = "Custom Data")
	TMap<FString, FDataEntry> Data;
	
};
