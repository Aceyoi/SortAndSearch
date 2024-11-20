//���������� ���� ���-22
#pragma once

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

#include "SortAndSearch.Modul.h"

void Random_array(vector<int>& array, size_t MAX, size_t MIN) {
	auto start = high_resolution_clock::now();
	random_array(array, MAX, MIN);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	//cout << "����� ����������: " << duration.count() << " ������\n";
}

void Print_array_vector(vector<int>& array) {
	auto start = high_resolution_clock::now();
	print_array_vector(array);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "����� ����������: " << duration.count() << " ������\n";
}

void Bubblesort(vector<int>& array) {
	auto start = high_resolution_clock::now();
	bubblesort(array);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "����� ���������� Bubblesort: " << duration.count() << " ������." << " ��� " << array.size() << " �����" << endl;
}

void Shellsort(vector<int>& array) {
	auto start = high_resolution_clock::now();
	shellsort(array);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "����� ���������� Shellsort: " << duration.count() << " ������." << " ��� " << array.size() << " �����" << endl;
}

void Quicksort(vector<int>& array) {
	auto start = high_resolution_clock::now();
	quicksort(array, 0, array.size());
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "����� ���������� Quicksort: " << duration.count() << " ������." << " ��� " << array.size() << " �����" << endl;
}

void Mergesort(vector<int>& array) {
	auto start = high_resolution_clock::now();
	mergesort(array, 0, array.size());
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "����� ���������� Mergesort: " << duration.count() << " ������." << " ��� " << array.size() << " �����" << endl;
}
/////////////////////////////////////////////////////////
void Binsearch(vector<int>& array, int X) {
	auto start = high_resolution_clock::now();
	cout << "�������� ����� " <<  binsearch(array, 0, array.size(), X) << endl;
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "����� ���������� Binsearch: " << duration.count() << " ������." << " ��� " << array.size() << " �����" << endl;
}

void Interpolationsearch(vector<int>& array, int X) {
	auto start = high_resolution_clock::now();
	cout << "�������� ����� " << interpolationsearch(array, 0, array.size(), X) << endl;
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "����� ���������� Interpolationsearch: " << duration.count() << " ������." << " ��� " << array.size() << " �����" << endl;
}