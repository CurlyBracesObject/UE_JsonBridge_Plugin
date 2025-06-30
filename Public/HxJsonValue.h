// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HxJsonValue.generated.h"

class UHxJsonObject;
/**
 * 
 */
UCLASS()
class HXJSON_API UHxJsonValue : public UObject
{
	GENERATED_BODY()

public:
	void SetJasonValue(TSharedPtr<FJsonValue> OutJsonValue);
	TSharedPtr<FJsonValue> GetNativeJsonValue(){return NativeJsonValue;};
	
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="HSXD|JsonValue")
	int32 AsNumber() const;
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="HSXD|JsonValue")
	FString AsString() const;
	
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="HSXD|JsonValue")
	float AsFloat() const;
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="HSXD|JsonValue")
	UHxJsonObject* AsObject() const;
	
private:
	TSharedPtr<FJsonValue> NativeJsonValue;
};
