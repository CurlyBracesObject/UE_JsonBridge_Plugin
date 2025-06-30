// Fill out your copyright notice in the Description page of Project Settings.


#include "HxJsonObject.h"

#include "HxJsonValue.h"

FString UHxJsonObject::GetStringField(const FString& FiledName) const
{
	if(!NativeJsonObject)
	{
		return TEXT("");
	}
	return NativeJsonObject->GetStringField(FiledName);
}

bool UHxJsonObject::GetBoolField(const FString& FiledName) const
{
	if(!NativeJsonObject)
	{
		return false;
	}
	return NativeJsonObject->GetBoolField(FiledName);
}

int32 UHxJsonObject::GetIntegerField(const FString& FiledName) const
{
	if(!NativeJsonObject)
	{
		return 0;
	}
	return NativeJsonObject->GetIntegerField(FiledName);
}

TArray<UHxJsonValue*> UHxJsonObject::GetArrayField(const FString& FiledName) const
{
	TArray<UHxJsonValue*> ValueArray;
	if(NativeJsonObject)
	{
		//NativeJsonObject->GetArrayField(FiledName);
		TArray<TSharedPtr<FJsonValue>> NativeValueArray=NativeJsonObject->GetArrayField(FiledName);
		for(auto Jv:NativeValueArray)
		{
			UHxJsonValue* JsonValue=NewObject<UHxJsonValue>(GetOuter());
			JsonValue->SetJasonValue(Jv);
			ValueArray.Add(JsonValue);
		}
	}
	return ValueArray;
}

void UHxJsonObject::SetStringField(const FString& FieldName, const FString& Value)
{
	if(NativeJsonObject)
	{
		NativeJsonObject->SetStringField(FieldName,Value);
	}
}

void UHxJsonObject::SetBoolField(const FString& FieldName, bool Value)
{
	if(NativeJsonObject)
	{
		NativeJsonObject->SetBoolField(FieldName,Value);
	}
}

void UHxJsonObject::SetIntegerField(const FString& FieldName, int32 Value)
{
	if(NativeJsonObject)
	{
		NativeJsonObject->SetNumberField(FieldName,Value);
	}
}

void UHxJsonObject::SetNativeJsonObject(TSharedPtr<FJsonObject> OutJsonObject)
{
	NativeJsonObject=OutJsonObject;
}
