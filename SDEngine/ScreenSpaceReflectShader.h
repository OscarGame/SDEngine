#pragma once

#ifndef _SSR_SHADER_H
#define _SSR_SHADER_H
#include"Shader.h"

class SSRShader:Shader
{
public:
	struct CBSSR
	{
		float viewAngleThresshold;
		float edgeDistThresshold;
		float depthBias;
		float reflectScale;
		XMFLOAT4 pectiveValues;	
	};

private:
	ID3D11Buffer* mCBSSR; 
private:
	virtual void ShutDown();
	virtual void CreateBuffer();
public:
	SSRShader(WCHAR* vsFilenPath, WCHAR* psFilenPath);
	SSRShader(const SSRShader&);
	~SSRShader();

public:
	bool SetShaderCBExtern(CXMMATRIX worldMatrix, ID3D11ShaderResourceView* diffuseTex,
		ID3D11ShaderResourceView* depthTex,
		float viewAngleThresshold,float edgeDistThresshold, 
		float depthBias, float reflectScale, XMFLOAT4 perspectiveValues);

	bool SetShaderParamsExtern(CXMMATRIX worldMatrix, ID3D11ShaderResourceView* diffuseTex, 
		ID3D11ShaderResourceView* depthTex,
		float viewAngleThresshold, float edgeDistThresshold,
		float depthBias, float reflectScale, XMFLOAT4 perspectiveValues);
	
};
#endif 