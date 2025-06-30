// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UObject/Object.h"
#include "HxJsonFunctionLibrary.generated.h"

class UHxJsonObject;
class UHxJsonValue;
/**
 * 
 */
UCLASS()
class HXJSON_API UHxJsonFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//static UHxJsonObject*
	UFUNCTION(BlueprintCallable,Category="HXSD|Json",meta=(WorldContext="WorldContextObject"))
	static bool DeserializeObject(UObject* WorldContextObject,const FString JsonString,UHxJsonObject*& JsonObject);
	UFUNCTION(BlueprintCallable,Category="HXSD|Json",meta=(WorldContext="WorldContextObject"))
	static bool DeserializeArray(UObject* WorldContextObject,const FString JsonString,TArray<UHxJsonValue*>& JsonArray);
	UFUNCTION(BlueprintCallable,Category="HXSD|Json")
	static bool SerializeObject(UHxJsonObject* JsonObject,FString& JsonString);

	UFUNCTION(BlueprintCallable,Category="HXSD|Json")
	static bool SerializeArray(TArray<UHxJsonValue*> JsonArray,FString& JsonString);

	
	UFUNCTION(BlueprintCallable,Category="HXSD|Json",meta=(WorldContext="WorldContextObject"))
	static UHxJsonObject* MakeHxJsonObject(UObject* WorldContextObject);
	
	//UFUNCTION(BlueprintCallable,Category="HXSD|Json",meta=(WorldContext="WorldContextObject"))
	//static UHxJsonValue* MakeHxJsonValue(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable,Category="HXSD|Json",BlueprintPure,meta=(WorldContext="WorldContextObject"))
	static UHxJsonValue* MakeHxJsonValueString(UObject* WorldContextObject,const FString& Value);
	UFUNCTION(BlueprintCallable,Category="HXSD|Json",BlueprintPure,meta=(WorldContext="WorldContextObject"))
	static UHxJsonValue* MakeHxJsonValueBool(UObject* WorldContextObject,bool Value);
	UFUNCTION(BlueprintCallable,Category="HXSD|Json",BlueprintPure,meta=(WorldContext="WorldContextObject"))
	static UHxJsonValue* MakeHxJsonValueInteger(UObject* WorldContextObject,int32 Value);
	UFUNCTION(BlueprintCallable,Category="HXSD|Json",BlueprintPure,meta=(WorldContext="WorldContextObject"))
	static UHxJsonValue* MakeHxJsonValueObject(UObject* WorldContextObject,UHxJsonObject* Value);
	UFUNCTION(BlueprintCallable,Category="HXSD|Json",BlueprintPure,meta=(WorldContext="WorldContextObject"))
	static UHxJsonValue* MakeHxJsonValueFloat(UObject* WorldContextObject,float Value);
};
