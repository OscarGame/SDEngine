#include"MathTool.h"

//返回一个矩阵的逆矩阵的转置
XMMATRIX MathTool::GetInvenseTranspose(CXMMATRIX ma)
{
	XMMATRIX A = ma;

	//将矩阵A的第四行置零,因为向量是无法进行平移的
	A.r[3] = { 0.0f, 0.0f, 0.0f, 1.0f };

	XMVECTOR det = XMMatrixDeterminant(A);
	XMMATRIX MaInvense = XMMatrixInverse(&det, A);
	return XMMatrixTranspose(MaInvense);
}
