#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComp);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Props/MaterialSphere.MaterialSphere"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		MeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	MoveSpeed = 500.0f;
	MaxRange = 1000.0f;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(800.0f, 800.0f, 300.0f));
	StartLocation = GetActorLocation();
	SetActorScale3D(FVector(3.0f, 3.0f, 3.0f));
	
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	CurrentLocation = GetActorLocation();
	Distance = FVector::Dist(StartLocation, CurrentLocation);

	if (Distance < MaxRange)
	{
		AddActorLocalOffset(FVector(MoveSpeed * DeltaTime, 0.f, 0.f));
	}

	if (Distance >= MaxRange)
	{
		MoveSpeed *= -1;
		Distance = 0.f;
		StartLocation = GetActorLocation(); 
		AddActorLocalOffset(FVector(-MoveSpeed * DeltaTime, 0.f, 0.f));
	}
}