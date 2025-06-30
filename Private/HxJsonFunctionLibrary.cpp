// Fill out your copyright notice in the Description page of Project Settings.


#include "HxJsonFunctionLibrary.h"
#include "HxJsonObject.h"
#include "HxJsonValue.h"

bool UHxJsonFunctionLibrary::DeserializeObject(UObject* WorldContextObject,const FString JsonString, UHxJsonObject*& JsonObject)
//WorldContextObject 是一个指向 UObject 类型的指针。通常，在 Unreal 引擎中，
//WorldContextObject 是用来 标识上下文环境 的对象，具体来说，它指示了当前代码所处的 世界上下文（World Context）。
//NewObject<UClassType>(Outer) 创建的是一个 UObject 对象，这个对象必须得 是可以被修改、垃圾回收、销毁的
//参数必须是 非 const 的，这样 Unreal 引擎才能确保生命周期管理和垃圾回收正常工作。
		//如果没有 可修改的 Outer，Unreal 引擎将无法正确管理对象的销毁，可能导致内存泄漏或崩溃问题。

//UE CPP就是不能引用一个不能被修改指向的指针

//UHxJsonObject*& JsonObject是UHxJsonObject 对象的指针的引用
//创建出来的那个对象指针（UHXJsonObject*）的“别名”，允许你在函数里修改它的指向
{
	TSharedRef<TJsonReader<>> JsonReader=TJsonReaderFactory<>::Create(JsonString);
	TSharedPtr<FJsonObject> JsonRoot;

	if(FJsonSerializer::Deserialize(JsonReader,JsonRoot))
	{
		JsonObject=NewObject<UHxJsonObject>(WorldContextObject);
		JsonObject->SetNativeJsonObject(JsonRoot);
		return true;
	}
	return false;
}

bool UHxJsonFunctionLibrary::DeserializeArray(UObject* WorldContextObject, const FString JsonString,
	TArray<UHxJsonValue*>& JsonArray)
{
	TSharedRef<TJsonReader<>> JsonReader=TJsonReaderFactory<>::Create(JsonString);
	TArray<TSharedPtr<FJsonValue>> JsonValues;

	if(FJsonSerializer::Deserialize(JsonReader,JsonValues))
	{
		for(auto Jv:JsonValues)
		{
			UHxJsonValue* HxJsonValue=NewObject<UHxJsonValue>(WorldContextObject);
			HxJsonValue->SetJasonValue(Jv);
			JsonArray.Add(HxJsonValue);
		}
		return true;
	}
	return false;
}

bool UHxJsonFunctionLibrary::SerializeObject(UHxJsonObject* JsonObject, FString& JsonString)
{
	if(JsonObject && JsonObject->GetNativeJsonObject())
	{
		TSharedRef<TJsonWriter<>> JsonWriter=TJsonWriterFactory<>::Create(&JsonString);
		return FJsonSerializer::Serialize(JsonObject->GetNativeJsonObject().ToSharedRef(),JsonWriter);
	}
	return false;
}

bool UHxJsonFunctionLibrary::SerializeArray(TArray<UHxJsonValue*> JsonArray, FString& JsonString)
{
	TSharedRef<TJsonWriter<>> JsonWriter=TJsonWriterFactory<>::Create(&JsonString);
	TArray<TSharedPtr<FJsonValue>> JsonValues;

	for(auto Jv:JsonArray)
	{
		JsonValues.Add(Jv->GetNativeJsonValue());
	}
	return FJsonSerializer::Serialize(JsonValues,JsonWriter);
}

UHxJsonObject* UHxJsonFunctionLibrary::MakeHxJsonObject(UObject* WorldContextObject)
{
	UHxJsonObject* JsonObject=NewObject<UHxJsonObject>(WorldContextObject);
	JsonObject->SetNativeJsonObject(MakeShareable(new FJsonObject));
	return JsonObject;
}

/*
 *UHxJsonValue* UHxJsonFunctionLibrary::MakeHxJsonValue(UObject* WorldContextObject)
  {
  	UHxJsonValue* JsonValue=NewObject<UHxJsonValue>(WorldContextObject);
  	//JsonValue->SetJasonValue(MakeShareable(new FJsonValue));
  	return JsonValue;
  }
 */
UHxJsonValue* UHxJsonFunctionLibrary::MakeHxJsonValueString(UObject* WorldContextObject, const FString& Value)
{
	UHxJsonValue* JsonValue=NewObject<UHxJsonValue>(WorldContextObject);
	JsonValue->SetJasonValue(MakeShareable(new FJsonValueString(Value)));
	return JsonValue;
}

UHxJsonValue* UHxJsonFunctionLibrary::MakeHxJsonValueBool(UObject* WorldContextObject, bool Value)
{
	UHxJsonValue* JsonValue=NewObject<UHxJsonValue>(WorldContextObject);
	JsonValue->SetJasonValue(MakeShareable(new FJsonValueBoolean(Value)));
	return JsonValue;
}

UHxJsonValue* UHxJsonFunctionLibrary::MakeHxJsonValueInteger(UObject* WorldContextObject, int32 Value)
{
	UHxJsonValue* JsonValue=NewObject<UHxJsonValue>(WorldContextObject);
	JsonValue->SetJasonValue(MakeShareable(new FJsonValueNumber(Value)));
	return JsonValue;
}

UHxJsonValue* UHxJsonFunctionLibrary::MakeHxJsonValueObject(UObject* WorldContextObject, UHxJsonObject* Value)
{
	UHxJsonValue* JsonValue=NewObject<UHxJsonValue>(WorldContextObject);
	JsonValue->SetJasonValue(MakeShareable(new FJsonValueObject(Value->GetNativeJsonObject())));
	return JsonValue;
}

UHxJsonValue* UHxJsonFunctionLibrary::MakeHxJsonValueFloat(UObject* WorldContextObject, float Value)
{
	UHxJsonValue* JsonValue=NewObject<UHxJsonValue>(WorldContextObject);
	JsonValue->SetJasonValue(MakeShareable(new FJsonValueNumber(Value)));
	return JsonValue;
}


