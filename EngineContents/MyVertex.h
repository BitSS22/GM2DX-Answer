#include <EngineBase/EngineMath.h>
#include <EngineCore/EngineInputLayOutInfo.h>

struct MyVertex
{
	// 모든 버텍스는 자신의 레이아웃 정보를 가지고 있어야 한다.
	friend class EngineVertexInit;
	inline static UEngineInputLayOutInfo Info = {};

	float4 POSITION;
	float4 COLOR;
};


