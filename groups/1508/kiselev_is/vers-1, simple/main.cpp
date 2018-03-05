//  ���������� ����������� ���������� � �������������� ������������ ����� (����� ��������).

#include "Func.h"
#include "Math.h"
#include <fstream>

int main(int argc, char** argv) {
	// �������� ������
	std::ifstream fin("test_for_program_in.txt");
	std::ofstream fout("test_for_program_out.txt");
	
	// ���������� �������
	double result = 0.0;
	int size = 0;
	double res = 0.0;
	double interval[2];
	double accuracy = 0.1;
	for (int i = 0; i < 5; i++) {						// 5 ������
		fin >> size;										// ��������� ������ �������

		Func fun(size);										// ������� �������
		double* coef = new double(size);					// ��������� �����
		for (int i = 0; i < size; i++) {
			fin >> coef[i];
		}			
		fun.SetCoeffs(coef);
		fin >> interval[0] >> interval[1];			// ��������� ����������
		fin >> accuracy;							// ��������
		fin >> result;
		// ������ ��������� � ����� ����������� � ����
		res = Math::TIntegral(&fun, interval[0], interval[1], accuracy);
		fout << res << " Expected: " << result << std::endl;
	}
	
	fin.close();
	fout.close();
	return 0;
}