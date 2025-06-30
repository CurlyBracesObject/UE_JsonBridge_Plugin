// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HxJsonObject.generated.h"

class UHxJsonValue;
/**
 * 
 */
UCLASS(BlueprintType)
class HXJSON_API UHxJsonObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="HXSD|JsonObject")
	FString GetStringField(const FString& FiledName) const;
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="HXSD|JsonObject")
	bool GetBoolField(const FString& FiledName) const;
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="HXSD|JsonObject")
	int32 GetIntegerField(const FString& FiledName) const;

	UFUNCTION(BlueprintCallable,BlueprintPure,Category="HXSD|JsonObject")
	TArray<UHxJsonValue*> GetArrayField(const FString& FiledName) const;

	UFUNCTION(BlueprintCallable,Category="HXSD|JsonObject")
	void SetStringField(const FString& FieldName,const FString& Value);
	UFUNCTION(BlueprintCallable,Category="HXSD|JsonObject")
	void SetBoolField(const FString& FieldName,bool Value);
	UFUNCTION(BlueprintCallable,Category="HXSD|JsonObject")
	void SetIntegerField(const FString& FieldName,int32 Value);
	
	void SetNativeJsonObject(TSharedPtr<FJsonObject> OutJsonObject);
	TSharedPtr<FJsonObject> GetNativeJsonObject(){return NativeJsonObject;};

private:
	TSharedPtr<FJsonObject> NativeJsonObject;
};
