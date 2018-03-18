#pragma once

#include <cstdio> 
#include <random> 
#include <ctime> 
#include <chrono>
using namespace std;

int n_tests[] = { 1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };

int main(int argc, char * argv[]) {
	// �������������� ����� stdout � ���� matr.in 
	freopen("../matr.in", "wb", stdout);
	// ������ ��������� ��������� ����� � seed ������ ���������� ������� � ������ ����� 
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	// ������ ����������� ������������� ��������� �������� ���� double � ��������� // [-50, 50] 
	uniform_real_distribution <double> distribution(-50, 50);
	// ����� ������ ������ 
	int n = 10;
	// ���� �������� ����� ����� � ���������� ��������� ������, �� ���� ������ �� 	n_tests 
	if (argc > 1) n = n_tests[atoi(argv[1])];
	// ���������� � �������� ���� ����������� ������ 
	fwrite(&n, sizeof(n), 1, stdout);
	// ������ ��������� ������ ��� ������ ������� 
	double * cur = new double[n];
	// ���������� ������ ������� 
	for (int i = 0; i < n; i++) {
		// ��������� ���������� ������� �� ������������ ������������� ��������� ������ ������� 
		for (int j = 0; j < n; j++) cur[j] = distribution(generator);
		// ���������� ������ � �������� ���� � ����
		fwrite(cur, sizeof(*cur), n, stdout);
	}
	cur[0] = distribution(generator);
	cur[1] = distribution(generator);
	if (cur[0] > cur[1]) swap(cur[0], cur[1]);
	fwrite(cur, sizeof(*cur), 2, stdout);
	return 0;
}