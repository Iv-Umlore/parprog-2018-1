#pragma once

#include <cstdio> 
#include <random> 
#include <ctime> 
#include <chrono>
using namespace std;

int n_tests[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

int main(int argc, char * argv[]) {
	// �������������� ����� stdout � ���� matr.in 
	freopen(argv[1], "wb", stdout);
	// ������ ��������� ��������� ����� � seed ������ ���������� ������� � ������ ����� 
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	// ������ ����������� ������������� ��������� �������� ���� double � ��������� // [0, 25] 
	uniform_real_distribution <double> distribution(0, 25);				// ������� ������� � ��������� ��� ���������� ����� � �������
	// ����� ������ ������												// ��������� ������ ������������� ��������
	int size = rand()%15 + 1;
	
	// ���� �������� ����� ����� � ���������� ��������� ������, �� ���� ������ �� 	n_tests 
	if (argc > 1) size = n_tests[atoi(argv[1])];
	// ���������� � �������� ���� ����������� ������ 
	fwrite(&size, sizeof(size), 1, stdout);
	// ������ ��������� ������ ��� ������ ������� 
	double * cur = new double[size];
	// ���������� ������ ������� 
	for (int i = 0; i < 7; i++) {
		// ��������� ���������� ������� �� ������������ ������������� ��������� ������ ������� 
		for (int j = 0; j < size; j++) cur[j] = distribution(generator);
		// ���������� ������ � �������� ���� � ����
		fwrite(cur, sizeof(*cur), size, stdout);
	}
	double confines[2];
	// ������ ������� ��������������

	uniform_real_distribution <double> acreage (-10, 10);

	confines[0] = acreage(generator);		// ��� X
	confines[1] = acreage(generator);
	if (confines[0] > confines[1]) swap(confines[0], confines[1]);
	fwrite(confines, sizeof(*confines), 2, stdout);

	confines[0] = acreage(generator);		// ��� Y
	confines[1] = acreage(generator);
	if (confines[0] > confines[1]) swap(confines[0], confines[1]);
	fwrite(confines, sizeof(*confines), 2, stdout);

	return 0;
}