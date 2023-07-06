// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSObjectActor.h"

#include "Components/SphereComponent.h"

// Sets default values
AFPSObjectActor::AFPSObjectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MeshComponent=CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent=MeshComponent;

	SphereComponent=CreateDefaultSubobject<USphereComponent>("SphereComponent");
	RootComponent->SetupAttachment(MeshComponent);
}

// Called when the game starts or when spawned
void AFPSObjectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSObjectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

