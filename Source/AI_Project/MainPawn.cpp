// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Project.h"
#include "MainPawn.h"


// Sets default values
AMainPawn::AMainPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));

	BoxCollider->SetSimulatePhysics(true);
	BoxCollider->SetMassOverrideInKg(NAME_None, 0.001f, true);
	BoxCollider->SetLinearDamping(3.0f);
	BoxCollider->SetEnableGravity(false);
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	RootComponent = BoxCollider;

}

// Called when the game starts or when spawned
void AMainPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMainPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MouseWorld, MouseDir;
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	PC->DeprojectMousePositionToWorld(MouseWorld, MouseDir);

	FVector Direction = (MouseWorld - GetActorLocation()).GetSafeNormal();

	BoxCollider->AddForceAtLocation(Direction * 5.0f, GetActorLocation());

	float Distance = ((GetActorLocation() - MouseWorld).Size()) - 440.0f;

	UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), Distance);

}

// Called to bind functionality to input
void AMainPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

