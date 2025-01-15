#include "PreCompile.h"
#include "TestGameMode.h"

#include "EngineCore/Mesh.h"
#include "EngineCore/EngineMaterial.h"
#include "EngineCore/EngineVertexBuffer.h"
#include "EngineCore/EngineIndexBuffer.h"
#include "Polygon.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/CameraActor.h>



ATestGameMode::ATestGameMode()
{
}

ATestGameMode::~ATestGameMode()
{
}

void ATestGameMode::BeginPlay()
{
	AActor::BeginPlay();

	PolygonPtr = GetWorld()->SpawnActor<APolygon>("Polygon");
	
}

void ATestGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsDown('P'))
	{
		GetWorld()->GetMainCamera()->FreeCameraSwitch();
	}
}

void ATestGameMode::LevelChangeStart()
{
}
