// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSExtractionZone.h"

#include "Components/BoxComponent.h"


// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OverlapComponent=CreateDefaultSubobject<UBoxComponent>("OverlapComponent");
	OverlapComponent->SetupAttachment(RootComponent);
	
	OverlapComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComponent->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
	OverlapComponent->SetBoxExtent(FVector(200.f));
	OverlapComponent->OnComponentBeginOverlap.AddDynamic(this,&AFPSExtractionZone::HandleOverlap);

	OverlapComponent->SetHiddenInGame(false);
	
}

// Called when the game starts or when spawned
void AFPSExtractionZone::BeginPlay()
{
	Super::BeginPlay();
}

void AFPSExtractionZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1,-1.5f,FColor::Green,TEXT("到达通关口"));
}

// Called every frame
void AFPSExtractionZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

