#include "PreCompile.h"
#include "MyRenderer.h"

MyRenderer::MyRenderer()
{
	CreateRenderUnit();
	SetMesh("MyMesh");
	SetMaterial("MyMaterial");
}

MyRenderer::~MyRenderer()
{
}

