// Fill out your copyright notice in the Description page of Project Settings.


#include "HxJsonValue.h"

#include "HxJsonFunctionLibrary.h"
#include "HxJsonObject.h"

void UHxJsonValue::SetJasonValue(TSharedPtr<FJsonValue> OutJsonValue)
{
	NativeJsonValue=OutJsonValue;
}

int32 UHxJsonValue::AsNumber() const
{
	if(NativeJsonValue)
	{
		return NativeJsonValue->AsNumber();
	}
	return 0;
}

FString UHxJsonValue::AsString() const
{
	if(NativeJsonValue)
	{
		return NativeJsonValue->AsString();
	}
	return TEXT("");
}

float UHxJsonValue::AsFloat() const
{
	if(NativeJsonValue)
	{
		return NativeJsonValue->AsNumber();
	}
	return 0;
}

UHxJsonObject* UHxJsonValue::AsObject() const
{
	if(NativeJsonValue)
	{
		//NativeJsonValue->AsObject();
		UHxJsonObject* HxJsonObject=NewObject<UHxJsonObject>(GetOuter());
		HxJsonObject->SetNativeJsonObject(NativeJsonValue->AsObject());
		return HxJsonObject;
	}
	return nullptr;
}
