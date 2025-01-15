#include "PreCompile.h"
#include "Polygon.h"
#include "MyRenderer.h"
#include <EngineCore/DefaultSceneComponent.h>

APolygon::APolygon()
{
	RootComponent = CreateDefaultSubObject<UDefaultSceneComponent>();

	PolygonRenderer = CreateDefaultSubObject<MyRenderer>();
	PolygonRenderer->SetupAttachment(RootComponent);

	SetActorRelativeScale3D(FVector(300.f, 600.f, 300.f));
	SetActorLocation(FVector(0.f, 0.f, 200.f));
}

APolygon::~APolygon()
{
}

void APolygon::BeginPlay()
{
	AActor::BeginPlay();
}

void APolygon::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	AddActorRotation(FVector(0.f, 0.f, 60.f) * _DeltaTime);
}

