// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#pragma warning(push)
#pragma warning(disable : 4005)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP
#define NOMCX
#define NOSERVICE
#define NOHELP
#pragma warning(pop)

// Windows Header Files:
#include <windows.h>
#include <mmsystem.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdint.h>
#include <utility>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <stack>
#include <vector>


#include <d3d11.h>
#include <dinput.h>

#include "d3dclass.h"

#include "DirectXTK/SimpleMath.h"


#include "colorshaderclass.h"

#include "textureclass.h"
#include "positionclass.h"
#include "systemclass.h"
#include "applicationclass.h"
#include "systemclass.h"

#include "cameraclass.h"
#include "foliageclass.h"
#include "foliageshaderclass.h"
#include "modelclas.h"
#include "positionclass.h"
#include "Resource.h"
#include "terrainclass.h"
#include "textureclass.h"
#include <d3dcompiler.h>
#include "DirectXTK\DDSTextureLoader.h"
#include <Windows.h>
#include <Wingdi.h>