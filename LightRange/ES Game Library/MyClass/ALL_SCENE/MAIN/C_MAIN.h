#pragma once
#include "../SCENEMANAGER/BaseScreen.h"
#include "../../C_OBJECT/Object.h"

class C_MAIN : public BaseScene
{
public:
	C_MAIN() {};
	virtual ~C_MAIN();

	virtual void Initialize() override;
	virtual void Update()     override;
	virtual void Draw3D()     override;
	virtual void Draw2D()     override;
	virtual void DrawAlpha3D()override;

private:
	ObjectManager _objectroot;
	Object* enemy_card;

	int ��t = 1;
	int appearance_se;
};
