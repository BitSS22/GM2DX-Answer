cbuffer FTransform : register(b0)
{
	// transformupdate는 
	// 아래의 값들을 다 적용해서
	// WVP를 만들어내는 함수이다.
	// 변환용 벨류
	float4 Scale;
	float4 Rotation;
	float4 Qut;
	float4 Location;

	// 릴리에티브 로컬
	float4 RelativeScale;
	float4 RelativeRotation;
	float4 RelativeQut;
	float4 RelativeLocation;

	// 월드
	float4 WorldScale;
	float4 WorldRotation;
	float4 WorldQuat;
	float4 WorldLocation;

	float4x4 ScaleMat;
	float4x4 RotationMat;
	float4x4 LocationMat;
	float4x4 RevolveMat;
	float4x4 ParentMat;
	float4x4 LocalWorld;
	float4x4 World;
	float4x4 View;
	float4x4 Projection;
	float4x4 WVP;
};

struct MyVertex
{
    float4 POSITION : POSITIONT;
    float4 COLOR : COLOR;
};

struct MyVertexOutPut
{
    float4 SVPOSITION : SV_POSITION;
    float4 COLOR : COLOR;
};

MyVertexOutPut MyVertexShader_VS(MyVertex _Vertex)
{
    MyVertexOutPut OutPut;
	
    OutPut.SVPOSITION = mul(_Vertex.POSITION, WVP);
    OutPut.COLOR = _Vertex.COLOR;
	
    return OutPut;
}

float4 MyPixelShader_PS(MyVertexOutPut _Vertex) : SV_Target0
{
    return _Vertex.COLOR;
};