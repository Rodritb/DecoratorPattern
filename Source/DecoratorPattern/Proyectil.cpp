// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil.h"

// Sets default values
AProyectil::AProyectil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>ProjectileMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	ProyectilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProyectilMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	RootComponent = ProyectilMesh;

	FVector NewScale(1.0f, 1.0f, 1.0f); // Cambia estos valores según tus necesidades
	SetActorScale3D(NewScale);

	vel = 500;
}

// Called when the game starts or when spawned
void AProyectil::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}
void AProyectil::Mover(float DeltaTime)
{
	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * vel * GetWorld()->GetDeltaSeconds();
	//FVector NewLocation = GetActorLocation() + FVector(0.0f, -vel, 0.0f) * DeltaTime;
	SetActorLocation(NewLocation);

}
