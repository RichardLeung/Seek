// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Seek/Character/SeekCharacterInfoData.h"
#include "GameFramework/Character.h"
#include "Seek/Interface/SeekInteractInterface.h"
#include "SeekNPCCharacter.generated.h"

UCLASS()
class SEEK_API ASeekNPCCharacter : public ACharacter, public ISeekInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASeekNPCCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	FDataTableRowHandle CharacterDataTableRowHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "NPC")
	FCharacterInfoData CharacterData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NPC")
	float ShowRange = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NPC")
	float InteractRange = 300.f;
	
protected:
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bBFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void OnInteract() override;

	UFUNCTION(BlueprintImplementableEvent)
	void k2_OnInteract();

	UPROPERTY()
	class ASeekPlayerCharacter* PlayerCharacter;

private:
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Sphere;

};
