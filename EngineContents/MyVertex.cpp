#include "PreCompile.h"
#include "MyVertex.h"


class MyVertexInit
{
public:
	MyVertexInit()
	{
		MyVertex::Info.AddInputLayout("POSITION", DXGI_FORMAT_R32G32B32A32_FLOAT);
		MyVertex::Info.AddInputLayout("COLOR", DXGI_FORMAT_R32G32B32A32_FLOAT);
	}
};

MyVertexInit MyInitObject;