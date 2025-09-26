#include "TimerActor.h"

ATimerActor::ATimerActor()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComp);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse"));
	if (MaterialAsset.Succeeded())
	{
		MeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	SetActorScale3D(FVector(3.0f, 3.0f, 3.0f));
	Changer = true;

}

void ATimerActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&ATimerActor::Teleport,
		1.0f,
		true,
		0.f
	);
	
}

void ATimerActor::Teleport()
{
	APoint = FVector(-3000.f, -2000.0f, 100.0f);
	BPoint = FVector(-2000.f, -2000.0f, 100.0f);

	if (Changer)
	{
		SetActorLocation(APoint);
	}
	else
	{
		SetActorLocation(BPoint);
	}
	Changer = !Changer;
}



