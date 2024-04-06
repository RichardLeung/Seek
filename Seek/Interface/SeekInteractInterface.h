// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SeekInteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class USeekInteractInterface : public UInterface
{
	GENERATED_BODY()
};

UENUM(BlueprintType)
enum class ESeekInteractableType : uint8
{
	// NPC
	NPC UMETA(DisplayName = "NPC"),
	// 物品
	Item UMETA(DisplayName = "Item"),
};

/**
 * 
 */
class SEEK_API ISeekInteractInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// 获取交互对象的类型
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interactable")
	ESeekInteractableType GetInteractableType() const;

	// 设置交互对象的类型
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interactable")
	void SetInteractableType(ESeekInteractableType NewType);
	
	virtual void OnInteract() = 0;
};
