#include <EngineBase/EngineMath.h>
#include <EngineCore/EngineInputLayOutInfo.h>

struct MyVertex
{
	// ��� ���ؽ��� �ڽ��� ���̾ƿ� ������ ������ �־�� �Ѵ�.
	friend class EngineVertexInit;
	static UEngineInputLayOutInfo Info;

	float4 POSITION;
	float4 COLOR;
};


