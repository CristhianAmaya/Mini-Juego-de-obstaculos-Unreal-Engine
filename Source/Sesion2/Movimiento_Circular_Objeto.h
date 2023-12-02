// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Movimiento_Circular_Objeto.generated.h"

UCLASS()
class SESION2_API AMovimiento_Circular_Objeto : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovimiento_Circular_Objeto();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category="Circular Movement");
	FVector Position;
	UPROPERTY(EditAnywhere, Category="Circular Movement");
	FVector Velocity;
	UPROPERTY(VisibleAnywhere, Category="Circular Movement");
	FVector Pivote;
	UPROPERTY(VisibleAnywhere, Category="Circular Movement");
	float angulo;

	void Movimientos_Circulares(float DeltaTime);

};
