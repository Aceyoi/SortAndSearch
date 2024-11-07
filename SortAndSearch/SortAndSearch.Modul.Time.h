//���������� ���� ���-22
#pragma once

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

#include "SortAndSearch.Modul.h"


void Random_array(vector<int>& array, size_t MAX, size_t MIN) {
	auto start = chrono::high_resolution_clock::now();
	random_array(array, MAX, MIN);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::seconds>(end - start);
	//cout << "����� ����������: " << duration.count() << " ������\n";
}

void Print_array_vector(vector<int>& array) {
	auto start = chrono::high_resolution_clock::now();
	print_array_vector(array);
	system("cls");
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::seconds>(end - start);
	cout << "����� ����������: " << duration.count() << " ������\n";
}

void Bubblesort(vector<int>& array) {
	auto start = chrono::high_resolution_clock::now();
	bubblesort(array);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::seconds>(end - start);
	cout << "����� ���������� Bubblesort: " << duration.count() << " ������." << " ��� " << array.size() << " �����" << endl;
}

void Shellsort(vector<int>& array) {
	auto start = chrono::high_resolution_clock::now();
	shellsort(array);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::seconds>(end - start);
	cout << "����� ���������� Shellsort: " << duration.count() << " ������." << " ��� " << array.size() << " �����" << endl;
}

void Quicksort(vector<int>& array) {
	auto start = chrono::high_resolution_clock::now();
	quicksort(array, 0, array.size());
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::seconds>(end - start);
	cout << "����� ���������� Quicksort: " << duration.count() << " ������." << " ��� " << array.size() << " �����" << endl;
}

