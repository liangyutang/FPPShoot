// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuard.h"

#include "FPPShoot/FPPShootGameMode.h"
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

	GuardState=EAIState::Idle;
}

// Called when the game starts or when spawned
void AAIGuard::BeginPlay()
{
	Super::BeginPlay();
	OriginalRotation=GetActorRotation();
	
}

void AAIGuard::OnPawnSeen(APawn* SeenPawn)
{
	if (SeenPawn==nullptr)
	{
		return;
	}
	//3D球
	DrawDebugSphere(GetWorld(),SeenPawn->GetActorLocation(),32.f,12,FColor::Yellow,false,10);
	//停止一切操作
	if (AFPPShootGameMode* GameMode=Cast<AFPPShootGameMode>(GetWorld()->GetAuthGameMode()))
	{
		//游戏结束（失败）
		GameMode->CompleteMission(SeenPawn,false);
	}
	SetGuardState(EAIState::Alerted);
}

void AAIGuard::OnNoiseHeard(APawn* Instigat, const FVector& Location, float Volume)
{
	
	if (GuardState==EAIState::Alerted)
	{
		return;
	}
	
	//3D球
	DrawDebugSphere(GetWorld(),Location,32.f,12,FColor::Green,false,10);

	/*UE_LOG(LogTemp,Error,TEXT("2:%f  %f   %f"),Location.X,Location.Y,Location.Z);*/
	//获得朝向
	FVector Direction=Location-GetActorLocation();
	Direction.Normalize();
	
	FRotator NewLookAt=FRotationMatrix::MakeFromX(Direction).Rotator();
	NewLookAt.Pitch=0.f;
	NewLookAt.Roll=0.f;
	SetActorRotation(NewLookAt);

	GetWorldTimerManager().ClearTimer(TimerHandle_ResetOrient);
	GetWorldTimerManager().SetTimer(TimerHandle_ResetOrient,this,&AAIGuard::ResetOrientation,ResetOrientTime);
	
	SetGuardState(EAIState::Suspicious);
}

void AAIGuard::ResetOrientation()
{
	if (GuardState==EAIState::Alerted)
	{
		return;
	}
	
	SetActorRotation(OriginalRotation);
	
	GuardState=EAIState::Idle;
}

void AAIGuard::SetGuardState(EAIState NewState)
{
	if (GuardState==NewState)
	{
		return;
	}
	GuardState=NewState;

	OnStateChanged(NewState);
}

// Called every frame
void AAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

