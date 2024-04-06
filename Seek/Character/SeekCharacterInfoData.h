#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SeekCharacterInfoData.generated.h"

USTRUCT(BlueprintType)
struct FCharacterInfoData : public FTableRowBase
{
	GENERATED_BODY()

	// 角色名称
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText Name;

	// 角色描述
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText Description;

	// 角色头像
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UTexture2D* Avatar;
};

