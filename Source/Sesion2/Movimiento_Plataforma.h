// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Movimiento_Plataforma.generated.h"

UCLASS()
class SESION2_API AMovimiento_Plataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovimiento_Plataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

private:
	//Variables
	UPROPERTY(EditAnyWhere, Category="Moving")
	FVector Velocity = FVector(100.0f,0.0f,0.0f); //Velocidad a la que se mueve la plataforma
	UPROPERTY(EditAnyWhere, Category="Moving")
	float MoveDistance = 100;
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity = FRotator(0.0f, 90.0f, 0.0f);

	//Funciones
	void Move_Platform(float DeltaTime);
	void Rotate_Platform(float DeltaTime);

	bool ShouldPlatformReturn(float DeltaTime);
	FVector Current(float DeltaTime);
	float GetDistanceMoved() const;
};