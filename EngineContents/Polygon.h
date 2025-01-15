#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class APolygon : public AActor
{
public:
	// constrcuter destructer
	APolygon();
	~APolygon();

	// delete Function
	APolygon(const APolygon& _Other) = delete;
	APolygon(APolygon&& _Other) noexcept = delete;
	APolygon& operator=(const APolygon& _Other) = delete;
	APolygon& operator=(APolygon&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	std::shared_ptr<class MyRenderer> PolygonRenderer = nullptr;

};

