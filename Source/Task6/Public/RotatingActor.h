#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class TASK6_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float RotationSpeed;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	USceneComponent* RootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	UStaticMeshComponent* MeshComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	

};
