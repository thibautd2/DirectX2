#pragma once
////////////////////////////////////////////////////////////////////////////////
// Filename: shadermanagerclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SHADERMANAGERCLAS_H_
#define _SHADERMANAGERCLAS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "textureshaderclass.h"
#include "fontshaderclass.h"
#include "foliageshaderclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: ShaderManagerClass
////////////////////////////////////////////////////////////////////////////////
class ShaderManagerClass
{
public:
	ShaderManagerClass();
	ShaderManagerClass(const ShaderManagerClass&);
	~ShaderManagerClass();

	bool Initialize(D3DClass*, HWND);
	void Shutdown();

	void RenderTextureShader(ID3D11DeviceContext*, int, Matrix, Matrix, Matrix, ID3D11ShaderResourceView*);
	void RenderFontShader(ID3D11DeviceContext*, int, Matrix, Matrix, Matrix, ID3D11ShaderResourceView*, Vector4);
	void RenderFoliageShader(ID3D11DeviceContext*, int, int, Matrix, Matrix, ID3D11ShaderResourceView*);

private:
	TextureShaderClass* m_TextureShader;
	FontShaderClass* m_FontShader;
	FoliageShaderClass* m_FoliageShader;
};

#endif