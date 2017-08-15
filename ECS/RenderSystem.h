#pragma once
#include "BaseSystem.h"
class CRenderSystem : public CBaseSystem
{
public:
	CRenderSystem(CEntityManager& manager);
	~CRenderSystem();
	void Update(float dt) override;

};

