////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "applicationclass.h"
#include "stdafx.h"

ApplicationClass::ApplicationClass()
{
	m_Direct3D = 0;
	m_ShaderManager = 0;
	m_Camera = 0;
	m_GroundModel = 0;
	m_Foliage = 0;
}


ApplicationClass::ApplicationClass(const ApplicationClass& other)
{
}


ApplicationClass::~ApplicationClass()
{
}


bool ApplicationClass::Initialize(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight)
{
	bool result;


	// Initialize the input object.

	// Create the Direct3D object.
	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize DirectX 11.", L"Error", MB_OK);
		return false;
	}

	// Create the shader manager object.
	m_ShaderManager = new ShaderManagerClass;
	if (!m_ShaderManager)
	{
		return false;
	}

	// Initialize the shader manager object.
	result = m_ShaderManager->Initialize(m_Direct3D, hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the shader manager object.", L"Error", MB_OK);
		return false;
	}

	

	// Create the camera object.
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera and build the matrices needed for rendering.
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera->Render();
	m_Camera->RenderBaseViewMatrix();

	// Create the fps object.


	// Initialize the user interface object.
	

	// Create the ground model object.
	m_GroundModel = new ModelClass;
	if (!m_GroundModel)
	{
		return false;
	}

	// Initialize the ground model object.
	result = m_GroundModel->Initialize(m_Direct3D->GetDevice(), "../Engine/data/plane01.txt", L"../Engine/data/rock015.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the ground model object.", L"Error", MB_OK);
		return false;
	}

	// Create the foliage object.
	m_Foliage = new FoliageClass;
	if (!m_Foliage)
	{
		return false;
	}

	// Initialize the foliage object.
	result = m_Foliage->Initialize(m_Direct3D->GetDevice(), L"../Engine/data/grass.dds", 500);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the foliage object.", L"Error", MB_OK);
		return false;
	}

	return true;
}


void ApplicationClass::Shutdown()
{
	// Release the foliage object.
	if (m_Foliage)
	{
		m_Foliage->Shutdown();
		delete m_Foliage;
		m_Foliage = 0;
	}

	// Release the ground model object.
	if (m_GroundModel)
	{
		m_GroundModel->Shutdown();
		delete m_GroundModel;
		m_GroundModel = 0;
	}

	// Release the user interface object.
	
	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the shader manager object.
	if (m_ShaderManager)
	{
		m_ShaderManager->Shutdown();
		delete m_ShaderManager;
		m_ShaderManager = 0;
	}

	// Release the Direct3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}

	return;
}


bool ApplicationClass::Frame()
{
	bool result;
	float posX, posY, posZ, rotX, rotY, rotZ;
	Vector3 cameraPosition;


	// Get the view point position/rotation.
	

	// Do the frame processing for the user interface.


	// Get the position of the camera.
	
	cameraPosition = m_Camera->GetPosition();

	// Do the frame processing for the foliage.
	result = m_Foliage->Frame(cameraPosition, m_Direct3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Render the graphics.
	result = Render();
	if (!result)
	{
		return false;
	}

	return result;
}


bool ApplicationClass::HandleMovementInput(float frameTime)
{
	bool keyDown;
	float posX, posY, posZ, rotX, rotY, rotZ;


	// Set the frame time for calculating the updated position.


	return true;
}


bool ApplicationClass::Render()
{
	Matrix worldMatrix, viewMatrix, projectionMatrix, orthoMatrix, baseViewMatrix;


	// Clear the scene.
	m_Direct3D->BeginScene(0.0f, 0.65f, 1.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the matrices from the camera and d3d objects.
	m_Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	m_Direct3D->GetProjectionMatrix(projectionMatrix);
	m_Direct3D->GetOrthoMatrix(orthoMatrix);
	m_Camera->GetBaseViewMatrix(baseViewMatrix);

	// Render the ground model.
	m_GroundModel->Render(m_Direct3D->GetDeviceContext());
	m_ShaderManager->RenderTextureShader(m_Direct3D->GetDeviceContext(), m_GroundModel->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_GroundModel->GetColorTexture());

	// Turn on the alpha-to-coverage blending.
	m_Direct3D->EnableAlphaToCoverageBlending();

	// Render the foliage.
	m_Foliage->Render(m_Direct3D->GetDeviceContext());
	m_ShaderManager->RenderFoliageShader(m_Direct3D->GetDeviceContext(), m_Foliage->GetVertexCount(), m_Foliage->GetInstanceCount(), viewMatrix, projectionMatrix, m_Foliage->GetTexture());

	// Turn off the alpha blending.
	m_Direct3D->TurnOffAlphaBlending();

	// Render the user interface.

	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();

	return true;
}

bool ApplicationClass::RenderSceneToTexture()
{
	return false;
}
