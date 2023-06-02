// Fill out your copyright notice in the Description page of Project Settings.


#include "AttachmentDataAsset.h"

TVariant<int32, float, FString, bool, FVector> FDataEntry::GetDataValue()
{
	TVariant<int32, float, FString, bool, FVector> Value;
		
	switch (DataType)
	{
	case EDataType::Integer:
		Value.Emplace<int32>(IntegerValue);
		break;
	case EDataType::Float:
		Value.Emplace<float>(FloatValue);
		break;
	case EDataType::String:
		Value.Emplace<FString>(StringValue);
		break;
	case EDataType::Boolean:
		Value.Emplace<bool>(BoolValue);
		break;
	case EDataType::Vector:
		Value.Emplace<FVector>(VectorValue);
		break;
	}

	return Value;
}
