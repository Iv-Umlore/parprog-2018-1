#pragma once

#include <iostream>

class Func {
private:
	double* _coeff;
	int* _index;
	int _size;
public:
	Func(int size) {
		_coeff = new double[size];
		_index = new int[size];
		for (int i = 0; i < size; i++) {
			_coeff[i] = 0;
			_index[i] = size - i - 1;
		}
		_size = size;
	}
	// �����������
	Func( Func* fun) {
		_size = fun->GetSize();
		_coeff = new double[_size];
		_index = new int[_size];
		for (int i = 0; i < _size; i++) {
			_coeff[i] = 0;
			_index[i] = _size - i - 1;
		}
	}
	// ����������� �����������
	~Func() {
		delete _coeff;
		delete _index;
	}
	// ����������
	void SetCoeffs(double* coeff) {
		for (int i = 0; i < _size; i++) {
			_coeff[i] = coeff[i];
		}
	}
	// ���������� ������������
	double GetCoeff(int pos) {
		return _coeff[pos];
	}
	// ������� ����������� �
	int GetIndex(int pos) {
		return _index[pos];
	}
	// ������� ������ �
	int GetSize() {
		return _size;
	}
	// ������� ����������� ��������

	void PrintFunc() {
		for (int i = 0; i < _size; i++) {
			if (_coeff[i] >= 0) std::cout << "+ ";
			if (_index[i] != 0) std::cout << _coeff[i] << " * x ^ " << _index[i] << " ";
			else std::cout << _coeff[i];
		}
		std::cout << std::endl;
	}
	// ����� �������
};