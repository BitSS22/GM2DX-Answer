#include "PreCompile.h"
#include "ContentsCore.h"
#include <EngineCore/EngineGraphicDevice.h>
#include <EngineCore/EngineVertex.h>
#include <EngineCore/EngineIndexBuffer.h>
#include <EngineCore/Mesh.h>
#include <EngineCore/EngineBlend.h>
#include <EngineCore/EngineShader.h>
#include <EngineCore/EngineMaterial.h>
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineSprite.h>
#include "MyVertex.h"



void UContentsCore::MyGSetting()
{



	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("ContentsResources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Image");
		std::vector<UEngineFile> ImageFiles = Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
		for (size_t i = 0; i < ImageFiles.size(); i++)
		{
			std::string FilePath = ImageFiles[i].GetPathToString();
			UEngineTexture::Load(FilePath);
		}
	}

	UEngineSprite::CreateSpriteToMeta("Player.png", ".sdata");

	UEngineSprite::CreateSpriteToMeta("TileMap.png", ".sdata");


	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("ContentsResources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Image/Tevi");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("ContentsResources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Image/TileSet");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory CurDir;
		CurDir.MoveParentToDirectory("ContentsShader");

		std::vector<UEngineFile> ShaderFiles = CurDir.GetAllFile(true, { ".fx", ".hlsl" });

		for (size_t i = 0; i < ShaderFiles.size(); i++)
		{
			UEngineShader::ReflectionCompile(ShaderFiles[i]);
		}
	}


	{
		std::shared_ptr<UEngineMaterial> Mat = UEngineMaterial::Create("MyCollisionDebugMaterial");
		Mat->SetVertexShader("EngineDebugCollisionShader.fx");
		Mat->SetPixelShader("EngineDebugCollisionShader.fx");
		// 언제나 화면에 나오는 누구도 이녀석의 앞을 가릴수 없어.
		Mat->SetDepthStencilState("CollisionDebugDepth");
		Mat->SetRasterizerState("CollisionDebugRas");
	}





	const FVector Top = { 0.0f, 0.5f, 0.0f, 1.f };
	const FVector Bottom = { 0.0f, -0.5f, 0.0f, 1.f };

	const FVector Left = { -0.5f, 0.0f, 0.0f, 1.f };
	const FVector Right = { 0.5f, 0.0f, 0.0f, 1.f };
	const FVector Front = { 0.0f, 0.0f, -0.5f, 1.f };
	const FVector Back = { 0.0f, 0.0f, 0.5f, 1.f };

	const FVector RedColor = { 1.f, 0.f, 0.f, 1.f };
	const FVector MagentaColor = { 1.f, 0.f, 1.f, 1.f };
	const FVector YellowColor = { 1.f, 1.f, 0.f, 1.f };
	const FVector GreenColor = { 0.f, 1.f, 0.f, 1.f };


	std::vector<MyVertex> Vertexes = {};

	Vertexes.push_back(MyVertex(Top, RedColor));
	Vertexes.push_back(MyVertex(Front, RedColor));
	Vertexes.push_back(MyVertex(Left, RedColor));

	Vertexes.push_back(MyVertex(Top, MagentaColor));
	Vertexes.push_back(MyVertex(Right, MagentaColor));
	Vertexes.push_back(MyVertex(Front, MagentaColor));

	Vertexes.push_back(MyVertex(Top, RedColor));
	Vertexes.push_back(MyVertex(Back, RedColor));
	Vertexes.push_back(MyVertex(Right, RedColor));

	Vertexes.push_back(MyVertex(Top, MagentaColor));
	Vertexes.push_back(MyVertex(Left, MagentaColor));
	Vertexes.push_back(MyVertex(Back, MagentaColor));


	Vertexes.push_back(MyVertex(Bottom, YellowColor));
	Vertexes.push_back(MyVertex(Front, YellowColor));
	Vertexes.push_back(MyVertex(Left, YellowColor));

	Vertexes.push_back(MyVertex(Bottom, GreenColor));
	Vertexes.push_back(MyVertex(Right, GreenColor));
	Vertexes.push_back(MyVertex(Front, GreenColor));

	Vertexes.push_back(MyVertex(Bottom, YellowColor));
	Vertexes.push_back(MyVertex(Back, YellowColor));
	Vertexes.push_back(MyVertex(Right, YellowColor));

	Vertexes.push_back(MyVertex(Bottom, GreenColor));
	Vertexes.push_back(MyVertex(Left, GreenColor));
	Vertexes.push_back(MyVertex(Back, GreenColor));

	UEngineVertexBuffer::Create("MyMesh", Vertexes);


	std::vector<unsigned int> Indexes = {};

	for (size_t i = 0; i < Vertexes.size(); ++i)
		Indexes.push_back(static_cast<unsigned int>(i));

	UEngineIndexBuffer::Create("MyMesh", Indexes);
	UMesh::Create("MyMesh");

	std::shared_ptr<UEngineMaterial> MyMaterial = UEngineMaterial::Create("MyMaterial");
	MyMaterial->SetVertexShader("MyShader.fx");
	MyMaterial->SetPixelShader("MyShader.fx");

}
