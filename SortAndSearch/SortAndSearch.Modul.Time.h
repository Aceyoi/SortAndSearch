//Сапожников Юрий ИВТ-22
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
	//cout << "Время выполнения: " << duration.count() << " секунд\n";
}

void Print_array_vector(vector<int>& array) {
	auto start = high_resolution_clock::now();
	print_array_vector(array);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "Время выполнения: " << duration.count() << " секунд\n";
}

void Bubblesort(vector<int>& array) {
	auto start = high_resolution_clock::now();
	bubblesort(array);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "Время выполнения Bubblesort: " << duration.count() << " секунд." << " Для " << array.size() << " чисел" << endl;
}

void Shellsort(vector<int>& array) {
	auto start = high_resolution_clock::now();
	shellsort(array);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "Время выполнения Shellsort: " << duration.count() << " секунд." << " Для " << array.size() << " чисел" << endl;
}

void Quicksort(vector<int>& array) {
	auto start = high_resolution_clock::now();
	quicksort(array, 0, array.size() - 1);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "Время выполнения Quicksort: " << duration.count() << " секунд." << " Для " << array.size() << " чисел" << endl;
}

void Mergesort(vector<int>& array) {
	auto start = high_resolution_clock::now();
	mergesort(array, 0, array.size());
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "Время выполнения Mergesort: " << duration.count() << " секунд." << " Для " << array.size() << " чисел" << endl;
}
/////////////////////////////////////////////////////////
void Binsearch(vector<int>& array, int X) {
	auto start = high_resolution_clock::now();
	cout << "Найденно число " <<  binsearch(array, 0, array.size(), X) << endl;
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "Время выполнения Binsearch: " << duration.count() << " секунд." << " Для " << array.size() << " чисел" << endl;
}

void Interpolationsearch(vector<int>& array, int X) {
	auto start = high_resolution_clock::now();
	cout << "Найденно число " << interpolationsearch(array, 0, array.size(), X) << endl;
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	cout << "Время выполнения Interpolationsearch: " << duration.count() << " секунд." << " Для " << array.size() << " чисел" << endl;
}