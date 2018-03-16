//  ���������� ����������� ���������� � �������������� ������������ ����� (����� ��������).


#include "Func.h"
#include "Math.h"
#include "Generate.h"

#include <cstdio>

int main(int argc, char** argv) {
	// �������� ������
	//FILE* fin;
	//freopen("new_test.txt","r", stdin);
	// ���������� �������
	double result = 0.0;
	int size = 1; 
	Func* fun = new Func(size);

	double parameters[7];
	parameters[0] = 1;
	parameters[1] = 1;
	parameters[2] = 0;
	parameters[3] = 0;
	parameters[4] = 0;
	parameters[5] = 0;
	parameters[6] = 0;

	fun->SetCoeffs(&parameters[0]);
	fun->SetXindexs(&parameters[1]);
	fun->SetYindexs(&parameters[2]);
	fun->SetXcos(&parameters[3]);
	fun->SetYcos(&parameters[4]);
	fun->SetXsin(&parameters[5]);
	fun->SetYsin(&parameters[6]);
	/*double* parametr;
	fread(&size, sizeof(int), 1, stdin);
	parametr = new double(size);
	Func* fun = new Func(size);
	for (int i = 0; i < 7; i++) {
			fread(parametr, sizeof(double), size, stdin);
			switch (i) {
				case 0: fun->SetCoeffs(parametr);
				case 1: fun->SetXindexs(parametr);
				case 2: fun->SetYindexs(parametr);
				case 3: fun->SetXcos(parametr);
				case 4: fun->SetYcos(parametr);
				case 5: fun->SetXsin(parametr);
				case 6: fun->SetYsin(parametr);
			}
	}*/
	fun->PrintFunc();

	std::cout << TIntegral(fun, 0.0, 4.0, 0.01) << std::endl;

	//fclose(stdin);
	system("pause");
/*
	// ���������
	// Generate();

	// ���������� ������������ ������
	fin.open("generate.txt", std::fstream::in);
	fout.open("generate_out.txt", std::fstream::out);

	for (int i = 0; i < test_numb; i++) {					
		fin >> size;										// ��������� ������ �������

		Func fun(size);										// ������� �������
		double* coef = new double(size);					// ��������� �����
		for (int i = 0; i < size; i++) {
			fin >> coef[i];
		}
		fun.SetCoeffs(coef);
		fin >> other_par[0] >> other_par[1];			// ��������� ����������
		fin >> other_par[2];							// ��������
													// ������ ��������� � ����� ����������� � ����
		res = TIntegral(&fun, other_par[0], other_par[1], other_par[2]);
		fout << res << std::endl;
	}
	
	fin.close();
	fout.close();*/
	return 0;
}