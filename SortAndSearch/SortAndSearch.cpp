//Сапожников Юрий ИВТ-22

#include "SortAndSearch.Modul.Time.h"
#include "SortAndSearch.Test.h"

using namespace std;
const size_t X = 50;
const size_t XX = 100;
const size_t XXX = 1000;
const size_t XXXX = 10'000;
const size_t XXXXX = 100'000;
const size_t XXXXXX = 10'000'000;
const size_t XXXXXXX = 100'000'000;
const size_t MAX = 100; // Максимальное число для случайного числа
const size_t MIN = 1;  // Минимальное число для случайного числа

int main(){
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));  // Инициализация генератора случайных чисел вне цикла 
	testcheck();

	vector<int> array0; // Создание интового векторногго массива
	array0.resize(XX);

	vector<int> array1; // Создание интового векторногго массива
	array1.resize(XX);

	vector<int> array2; // Создание интового векторногго массива
	array2.resize(XX);

	vector<int> array3; // Создание интового векторногго массива
	array3.resize(XX);

	vector<int> array4; // Создание интового векторногго массива
	array4.resize(XXXX);

	Random_array(array0, MAX, MIN);
	Random_array(array1, MAX, MIN);
	Random_array(array2, MAX, MIN);
	Random_array(array3, MAX, MIN);
	Random_array(array4, MAX, MIN);

	Bubblesort(array0);
	Shellsort(array1);
	Quicksort(array2);
	Mergesort(array3);

	cout << "Вывод массива: " << endl;
	Print_array_vector(array4);
	cout << endl;

	shellsort(array4);
	Binsearch(array4, 7);
	Interpolationsearch(array4, 7);


	return 0;
}

