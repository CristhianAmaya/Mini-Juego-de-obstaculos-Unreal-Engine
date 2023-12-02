// Fill out your copyright notice in the Description page of Project Settings.


#include "Movimiento_Plataforma.h"

// Sets default values
AMovimiento_Plataforma::AMovimiento_Plataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovimiento_Plataforma::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	UE_LOG(LogTemp, Display, TEXT(""));
}

// Called every frame
void AMovimiento_Plataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move_Platform(DeltaTime);
	Rotate_Platform(DeltaTime);
}

//Método Rotación
void AMovimiento_Plataforma::Rotate_Platform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

//Movimiento normal plataformas
void AMovimiento_Plataforma::Move_Platform(float DeltaTime)
{
	//Mover plataformas
		Current(DeltaTime);
		//Cambiar ubicación de la plataforma
		SetActorLocation(Current(DeltaTime));

		//Se realiza la comparación
		if (ShouldPlatformReturn(DeltaTime)) //Si la diferencia en entre el punto actual y el recorrido es > la distancia por recorrer
		{
			float Overshoot = FVector::Dist(StartLocation,Current(DeltaTime)) - MoveDistance;
			UE_LOG(LogTemp, Display, TEXT("Valor por consola: %f"), Overshoot); //Esta línea de código sirve para imprimir por consola un mensaje
			FVector MoveDirection = Velocity.GetSafeNormal();
			StartLocation = StartLocation + MoveDirection * MoveDistance; //Se le asigna la univación actual a la ubicación de partida para que está se vuelva el nuevo punto cero
			SetActorLocation(StartLocation);
			Velocity = -Velocity; //Se le asigna velocidad negativa para que la plataforma cambie de dirección
		}
}

bool AMovimiento_Plataforma::ShouldPlatformReturn(float DeltaTime)
{
	float DistanceMoved = FVector::Dist(StartLocation,Current(DeltaTime));
	return DistanceMoved > MoveDistance;
}

FVector AMovimiento_Plataforma::Current(float DeltaTime)
{
	//Obtener la ubicación actual de la plataforma
	FVector CurrentLocation = GetActorLocation();
	//Realizo la opración que me permitirá mover la plataforma en la dirección del vector Velocidad
	CurrentLocation = CurrentLocation + (Velocity * DeltaTime);
	//Se calcula la diferencia en entre el punto de posición actual de la plataforma y el recorrido que realiza la misma

	return CurrentLocation;
}