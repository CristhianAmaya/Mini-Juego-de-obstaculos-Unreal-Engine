// Fill out your copyright notice in the Description page of Project Settings.


#include "Movimiento_Circular_Objeto.h"
#include "Math/UnrealMathUtility.h" // Necesitas incluir esta cabecera para usar funciones matemáticas

// Sets default values
AMovimiento_Circular_Objeto::AMovimiento_Circular_Objeto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovimiento_Circular_Objeto::BeginPlay()
{
	Super::BeginPlay();
	Position = GetActorLocation();
	Pivote = FVector(Position.X + 2.0f, Position.Y, Position.Z);
	Velocity = FVector(2.0f, 0.0f, 0.0f);
	angulo = 0.0f;
}

// Called every frame
void AMovimiento_Circular_Objeto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Movimientos_Circulares(DeltaTime);
}

void AMovimiento_Circular_Objeto::Movimientos_Circulares(float DeltaTime)
{
	float Radio = FMath::Sqrt(FMath::Pow(Pivote.X - Position.X, 2) + FMath::Pow(Pivote.Y - Position.Y, 2));
	//angulo = FMath::Atan(((FMath::Pow(Position.Y, 2)/2)+(FMath::Pow(Pivote.Y, 2)/2))/((FMath::Pow(Position.X, 2)/2)+(FMath::Pow(Pivote.X, 2)/2)));
	angulo = FMath::Atan((Position.Y + Pivote.Y)/(Position.X + Pivote.X));
	FVector newPos = FVector(Radio*FMath::Cos(angulo), Radio*FMath::Sin(angulo), 0.0f);

	// Aplica la velocidad al ángulo
	angulo += Velocity.X * DeltaTime;

	//Ahora se desarrolla la rotación
        //Primero se crea otro angulo, al cual se le agrega la suma del angulo original
        float angulo2 = angulo;
        //Ahora se halla la nueva posición del vector rotación (newPos)
        newPos.X = (Position.X * FMath::Cos(angulo2)) - (Position.Y * FMath::Sin(angulo2));
        newPos.Y = (Position.Y * FMath::Cos(angulo2)) + (Position.X * FMath::Sin(angulo2));

		//Realizamos la rotación del objeto
        SetActorRotation(newPos.Rotation());

		//Se actualizan los datos
        Position = newPos;
}