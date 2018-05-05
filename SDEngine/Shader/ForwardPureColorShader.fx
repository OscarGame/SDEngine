SamplerState SampleType:register(s0);   //������ʽ


cbuffer CBMatrix:register(b0)
{
	matrix World;
	matrix View;
	matrix Proj;
	matrix WorldInvTranspose;
	float3 cameraPos;
	float pad1;
	float4 dirLightColor;
	float3 dirLightDir;
	float pad2;
	float3 ambientLight;
	float pad3;
};

cbuffer CBEveryFrame:register(b1)
{
	float4 surfaceColor;
}

struct VertexIn
{
	float3 Pos:POSITION;
	float3 Color:COLOR;
	float3 Normal:NORMAL;
	float3 Tangent:TANGENT;
	float2 Tex:TEXCOORD;  

};


struct VertexOut
{
	float4 Pos:SV_POSITION;
	float3 W_Normal:NORMAL; 
};


VertexOut VS(VertexIn ina)
{
	VertexOut outa;
	outa.Pos = mul(float4(ina.Pos, 1.0f), World);
	outa.Pos = mul(outa.Pos, View);
	outa.Pos = mul(outa.Pos, Proj);
	outa.W_Normal = mul(ina.Normal, (float3x3)WorldInvTranspose);  //����������ת�þ���ĵ����б�����ûɶ��
	outa.W_Normal = normalize(outa.W_Normal);
	return outa;
}


float4 PS(VertexOut outa) : SV_Target
{
	
	float4 color;
	float3 lightDir = normalize(-dirLightDir);
	float3 worldNormal = normalize(outa.W_Normal);
	//float diffuseFactor = saturate(dot(worldNormal, lightDir));
	color.rgb =dirLightColor.xyz * surfaceColor.xyz;
	color.a = 0.6;
	return color;
}