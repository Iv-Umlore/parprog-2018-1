//  ���������� ����������� ���������� � �������������� ������������ ����� (����� ��������).

#include "Func.h"
#include "Math.h"

int main(int argc, char** argv) {
	// ������ ��������� ����������� ��� �������� �������
	Func fun(4);
	double coef[4] = { 1.0, 0.0, 2.0, - 4.0 };
	fun.SetCoeffs(coef);	
	std::cout << Math::TIntegral(&fun, 1.0, 4.0, 0.0001) << std::endl;
	fun.PrintFunc();
	system("pause");
	return 0;
}