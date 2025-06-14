#pragma once
#include "Structure.h"

class Window : public Structure
{
	using Super = Structure;
public:
	Window();
	virtual ~Window() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

protected:
	virtual void TickOn();
	virtual void TickOff();
	virtual  void UpdateAnimation();

public:
	virtual float GetSpeed() { return 0.f; }
	ObjectState GetState() { return _info.state(); }

private:
	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other);
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other);

private:
	Flipbook* _flipbookOn = nullptr;
	Flipbook* _flipbookOff = nullptr;
};

