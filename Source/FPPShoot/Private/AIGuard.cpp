// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuard.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
AAIGuard::AAIGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//创建人型感应组件
	PawnSensingComponent=CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComponent");
	//看到玩家
	PawnSensingComponent->OnSeePawn.AddDynamic(this,&AAIGuard::OnPawnSeen);
	//听到玩家
	PawnSensingComponent->OnHearNoise.AddDynamic(this,&AAIGuard::OnNoiseHeard);
}

// Called when the game starts or when spawned
void AAIGuard::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAIGuard::OnPawnSeen(APawn* SeenPawn)
{
	if (SeenPawn==nullptr)
	{
		return;
	}
	//3D球
	DrawDebugSphere(GetWorld(),SeenPawn->GetActorLocation(),32.f,12,FColor::Yellow,false,10);
}

void AAIGuard::OnNoiseHeard(APawn* Instigat, const FVector& Location, float Volume)
{
	//3D球
	DrawDebugSphere(GetWorld(),Location,32.f,12,FColor::Green,false,10);

	//获得朝向
	FVector Direction=Location-GetActorLocation();
	Direction.Normalize();
	
	FRotator NewLookAt=FRotationMatrix::MakeFromX(Direction).Rotator();
	SetActorRotation(NewLookAt);
}

// Called every frame
void AAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

