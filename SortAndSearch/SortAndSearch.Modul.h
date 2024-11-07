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

template<typename T>
void merging(vector<T>& a, size_t begin, size_t mid, size_t end) {
	T* c = new T[end - begin];					//буфер для хранения результата слияния

	size_t
		left = begin,						//индекс элемента из левой области
		right = mid,							//индекс элемента из правой области
		i = 0;								//индекс массива c 

	while (left < mid && right < end) {			//пока не достигнут конец одной из областей
		if (a[left] <= a[right]) {				//сравниваются значения из областей

			c[i] = a[left];						// если left меньше right, то в индекс i массива с помещаем значение из левой области
			left++;
		}
		else {
			c[i] = a[right];					//в противном случае из правой
			right++;
		}
		i++;
	}
	//помещаем оставшиеся значения в массив c
	if (left == mid) {							//если был достигнут конец левой части

		while (right < end) {					//то помещаем значения из правой

			c[i] = a[right];
			right++;
			i++;
		}
	}
	else if (right == end) {					//если же был достигнут конец правой части

		while (left < mid) {				// то помеащем знаяения из левой

			c[i] = a[left];
			left++;
			i++;
		}
	}

	size_t j = 0;
	while (j < end - begin) {					//помещение значений из массива с в массив а
		a[begin + j] = c[j];
		j++;
	}
	delete[] c;
}

///рекурсивная функция сортировки слиянием по возрастанию
/// a - сортируемыймассив
///left - левая граница сортировки
/// right - правая граница сортировки
/// 
/// BigO = O(n log(n)) для всех случаев
template<typename T>
void mergesort(vector<T>& a, size_t left, size_t right) {

	if (left < right - 1) {
		size_t mid = left + (right - left) / 2;
		mergesort(a, left, mid);	//сортировка левой половины сортируемой области
		mergesort(a, mid, right);  //сортировка правйо половины сортируемой области
		merging(a, left, mid, right);
	}
}












// Метод бинарного поиска
template <typename T>
int binsearch(vector<T>& arr, size_t begin, size_t end, T value) {
	size_t left = begin;
	size_t right = end - 1;

	while (left <= right) {
		size_t mid = left + (right - left) / 2; // Находим середину

		if (arr[mid] == value) { // Если найден
			return value; // Возвращаем индекс
		}
		else if (arr[mid] < value) { // Если значение больше, ищем справа
			left = mid + 1;
		}
		else { // Если значение меньше, ищем слева
			right = mid - 1;
		}
	}
	return -1; // Если не найден
}

// Метод интерполяционного поиска
template <typename T>
int interpolationsearch(vector<T>& arr, size_t begin, size_t end, T value) {
	size_t left = begin;
	size_t right = end - 1;

	while (left <= right && value >= arr[left] && value <= arr[right]) {
		// Находим позицию, используя интерполяцию
		size_t pos = left + ((value - arr[left]) * (right - left) / (arr[right] - arr[left]));

		if (arr[pos] == value) { // Если найден
			return value; // Возвращаем индекс
		}
		else if (arr[pos] < value) { // Если значение больше, ищем справа
			left = pos + 1;
		}
		else { // Если значение меньше, ищем слева
			right = pos - 1;
		}
	}
	return -1; // Если не найден
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