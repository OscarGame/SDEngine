#include"DiffuseShader.h"


DiffuseShader::DiffuseShader(WCHAR* vsFilenPath, WCHAR* psFilenPath):
	Shader_3D(vsFilenPath, psFilenPath)
{
}


DiffuseShader::DiffuseShader(const DiffuseShader& other):
	Shader_3D(other)
{

}


DiffuseShader::~DiffuseShader()
{
	ShutDown();
}

void DiffuseShader::ShutDown()
{

}

bool DiffuseShader::SetShaderCBExtern(CXMMATRIX worldMatrix, ID3D11ShaderResourceView* diffuseTexture)
{
	
	Shader_3D::SetShaderCB(worldMatrix);
	g_pDeviceContext->PSSetShaderResources(0, 1, &diffuseTexture);

	return true;
}


bool DiffuseShader::SetShaderParamsExtern(CXMMATRIX worldMatrix, ID3D11ShaderResourceView* diffuseTexture)
{

	bool result;

	//设置Shader常量缓存和纹理资源
	result = SetShaderCBExtern(worldMatrix, diffuseTexture);
	if (!result)
		return false;

	//设置VertexShader PixelShader InputLayout SamplerState
	SetShaderState();

	return true;
}