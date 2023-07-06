// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSObjectActor.h"

#include "Components/SphereComponent.h"
#include "FPPShoot/FPPShootCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSObjectActor::AFPSObjectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent=CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent=MeshComponent;
	
	SphereComponent=CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
	SphereComponent->SetupAttachment(MeshComponent);
	
}

// Called when the game starts or when spawned
void AFPSObjectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AFPSObjectActor::PlayEffects()
{
	//生成特效
	UGameplayStatics::SpawnEmitterAtLocation(this,PickupFX,GetActorLocation());
}

void AFPSObjectActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	AFPPShootCharacter* MyCharacter=Cast<AFPPShootCharacter>(OtherActor);
	if (MyCharacter)
	{
		MyCharacter->bIsCarringObjective=true;
		PlayEffects();
		Destroy();
	}
}

// Called every frame
void AFPSObjectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

