// Fill out your copyright notice in the Description page of Project Settings.


#include "SeekNPCCharacter.h"

#include "SeekPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASeekNPCCharacter::ASeekNPCCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(GetRootComponent());
	Sphere->SetSphereRadius(InteractRange);
}

void ASeekNPCCharacter::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bBFromSweep, const FHitResult& SweepResult)
{
	if (ASeekPlayerCharacter* Interactable = Cast<ASeekPlayerCharacter>(OtherActor))
	{
		ASeekNPCCharacter *Item = Cast<ASeekNPCCharacter>(this);
		TScriptInterface<ISeekInteractInterface> InteractableInterface;
		InteractableInterface.SetInterface(Cast<ISeekInteractInterface>(Item));
		InteractableInterface.SetObject(Item);
		InteractableInterface->Execute_SetInteractableType(InteractableInterface.GetObject(), ESeekInteractableType::NPC);
		PlayerCharacter->AddInteractItem(InteractableInterface);
	}
}

void ASeekNPCCharacter::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ASeekPlayerCharacter* Interactable = Cast<ASeekPlayerCharacter>(OtherActor))
	{
		ASeekNPCCharacter *Item = Cast<ASeekNPCCharacter>(this);
		TScriptInterface<ISeekInteractInterface> InteractableInterface;
		InteractableInterface.SetInterface(Cast<ISeekInteractInterface>(Item));
		InteractableInterface.SetObject(Item);
		InteractableInterface->Execute_SetInteractableType(InteractableInterface.GetObject(), ESeekInteractableType::NPC);
		PlayerCharacter->RemoveInteractItem(InteractableInterface);
	}
}

// Called when the game starts or when spawned
void ASeekNPCCharacter::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharacter = Cast<ASeekPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ASeekNPCCharacter::OnSphereBeginOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ASeekNPCCharacter::OnSphereEndOverlap);
}

// Called every frame
void ASeekNPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASeekNPCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASeekNPCCharacter::OnInteract()
{
	if (PlayerCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("与NPC交互"));
		k2_OnInteract();
	}
}


