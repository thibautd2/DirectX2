////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 100.0f;
const float SCREEN_NEAR = 0.1f;



///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "shadermanagerclas.h"
#include "cameraclass.h"
#include "modelclas.h"
#include "foliageclass.h"
#include "DirectXTK\SimpleMath.h"
using namespace std;
using namespace DirectX::SimpleMath;

////////////////////////////////////////////////////////////////////////////////
// Class name: ApplicationClass
////////////////////////////////////////////////////////////////////////////////
class ApplicationClass
{
public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass&);
	~ApplicationClass();

	bool Initialize(HINSTANCE, HWND, int, int);
	void Shutdown();
	bool Frame();

private:
	bool HandleMovementInput(float);
	bool Render();
	bool RenderSceneToTexture();

private:
	D3DClass* m_Direct3D;
	ShaderManagerClass* m_ShaderManager;
	CameraClass* m_Camera;
	ModelClass* m_GroundModel;
	FoliageClass* m_Foliage;
};

#endif