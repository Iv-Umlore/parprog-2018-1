#pragma once

#include "Func.h"

static class Math {
public:
	// �������� ������� � �����
	static double valueIn(Func* fun, double point) {
		double result = 0;
		int size = fun->GetSize();
		for (int i = 0; i < size; i++) {
			result = result + fun->GetCoeff(i)*exponent(point, fun->GetIndex(i));
		}
		return result;
	}
	
	// �������� ����� � �������
	static double exponent(double value, int exp) {
		double result = 1.0;
		while (exp > 0) {
			result = result * value;
			exp--;
		}
		return result;
	}	

	// �������� ����������
	static double TIntegral(Func* fun, double start, double finish, double accuracy = 0.1) {
		int parts = 1;					// ���������� �����
		double last_result = 0.0;		// ��������� ����������� ���������
		double result = 0.0;			// ������� ���������
		double partValue = 0.0;			// ������ ����
		double point = 0.0;
		do {
			point = start;
			if ((last_result != 0) && (result - last_result > accuracy * 5)) parts += 9;
			last_result = result;
			result = 0.0;
			parts++;
			partValue = (finish - start) / parts;
			for (int i = 0; i < parts; i++) {
				result = result + ((valueIn(fun, point) + valueIn(fun, point + partValue)) / 2 * partValue);
				// (F0 + F1) / 2 * H  // �������� ������ � ������� ����� �������� * ������ ���������
				point = point + partValue;
			}
		} 
		while (result - last_result > accuracy);		// ���� ����������� � ����������� ������
		return result;
	}
};
