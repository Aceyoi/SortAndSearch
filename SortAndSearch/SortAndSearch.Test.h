//Сапожников Юрий ИВТ-22
#pragma once

#include <cassert>
#include "SortAndSearch.Modul.h"

using namespace std;

void testcheck(){

	vector<int> bubblesortbestCase{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> bubblesortaverageCase{ 4, 1, 7, 3, 8, 2, 6, 10, 5, 9 };
	vector<int> bubblesortworstCase{ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	vector<int> shellsortbestCase{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> shellsortaverageCase{ 4, 1, 7, 3, 8, 2, 6, 10, 5, 9 };
	vector<int> shellsortworstCase{ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	vector<int> quicksortbestCase{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> quicksortaverageCase{ 4, 1, 7, 3, 8, 2, 6, 10, 5, 9 };
	vector<int> quicksortworstCase{ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	vector<int> mergesortbestCase{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> mergesortaverageCase{ 4, 1, 7, 3, 8, 2, 6, 10, 5, 9 };
	vector<int> mergesortworstCase{ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	bubblesort(bubblesortbestCase);
	bubblesort(bubblesortaverageCase);
	bubblesort(bubblesortworstCase);

	shellsort(shellsortbestCase);
	shellsort(shellsortaverageCase);
	shellsort(shellsortworstCase);

	quicksort(quicksortbestCase, 0, quicksortbestCase.size() - 1);
	quicksort(quicksortaverageCase, 0, quicksortaverageCase.size() - 1);
	quicksort(quicksortworstCase, 0, quicksortworstCase.size() - 1);

	mergesort(mergesortbestCase, 0, mergesortbestCase.size());
	mergesort(mergesortaverageCase, 0, mergesortaverageCase.size());
	mergesort(mergesortworstCase, 0, mergesortworstCase.size());

	if (sort_check(bubblesortbestCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };
	if (sort_check(shellsortbestCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };
	if (sort_check(quicksortbestCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };
	if (sort_check(mergesortbestCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };

	if (sort_check(bubblesortaverageCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };
	if (sort_check(shellsortaverageCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };
	if (sort_check(quicksortaverageCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };
	if (sort_check(mergesortaverageCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };

	if (sort_check(bubblesortworstCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };
	if (sort_check(shellsortworstCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };
	if (sort_check(quicksortworstCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };
	if (sort_check(mergesortworstCase) == true) { cout << "Проверка прошла успешно" << endl; }
	else { cout << "Проверка провалена" << endl; };

	assert(binsearch(bubblesortbestCase, 0, bubblesortbestCase.size(), 7) == 7);
	assert(interpolationsearch(bubblesortbestCase, 0, bubblesortbestCase.size(), 7) == 7);

	assert(binsearch(bubblesortbestCase, 0, bubblesortbestCase.size(), 11) == -1);
	assert(interpolationsearch(bubblesortbestCase, 0, bubblesortbestCase.size(), 11) == -1);

	cout << endl;
}