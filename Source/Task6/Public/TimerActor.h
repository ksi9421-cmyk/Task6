#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerActor.generated.h"

UCLASS()
class TASK6_API ATimerActor : public AActor
{
	GENERATED_BODY()

public:
	ATimerActor();


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	USceneComponent* RootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	FVector APoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	FVector BPoint;
	
	bool Changer;

	virtual void BeginPlay() override;

	void Teleport();
private:
	FTimerHandle TimerHandle;


};
