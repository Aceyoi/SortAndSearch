//Сапожников Юрий ИВТ-22
#pragma once

using namespace std;

void random_array(vector<int>& a, size_t MAX, size_t MIN) {
	for (int i = 0; i < a.size(); i++) {
		a[i] = rand() % MAX + MIN;  // Случайное значение массива от MIN до MAX
	}
}


void print_array_vector(vector<int>& a) {
	for (size_t i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// Метод пузырьковой сортировки
template <typename T>
void bubblesort(vector<T>& arr) {
	if (0 >= arr.size()) return;
	for (size_t i = 0; i < arr.size() - 1; i++) {
		for (size_t j = 0; j < arr.size(); j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// Метод сортировки Шелла
template <typename T>
void shellsort(vector<T>& arr) {
	for (size_t gap = arr.size() / 2; gap > 0; gap /= 2) {
		for (size_t i = gap; i < arr.size() + 1; i++) {
			T temp = arr[i];
			size_t j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

template <typename T>
void quicksort(vector<T>& arr, size_t begin, size_t end) {
	if (begin >= end) return;

	size_t base = begin; //опорный элемент
	size_t current = begin;//элемент который перемещается влево от опорного

	for (size_t i = begin + 1; i <= end; i++) {
		if (arr[i] < arr[base]) {				//если элемент arr[i] меньше опорного
			swap(arr[i], arr[++current]);  //меняем его и опорный элемент местами
		}
	}
	swap(arr[base], arr[current]);     //опорный элемент ставится на место последнего перемещеного

	if (current > begin) {
		quicksort(arr, begin, current - 1);//вызов функции для левой части массива
	}
	if (end > current + 1) {
		quicksort(arr, current + 1, end);//вызов функции для правой части массива
	}
}

//Метод на проверку сортировки от max к min или от min к max в динамическом массиве
template <typename T>
bool sort_check(vector<T>& arr) {
		for (size_t i = 0; i < arr.size() - 1; i++) {
			if (arr[i] < arr[i + 1]) {
				return true;
			}
		};
	return false;
}