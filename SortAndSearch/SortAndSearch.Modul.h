//���������� ���� ���-22
#pragma once

using namespace std;

void random_array(vector<int>& a, size_t MAX, size_t MIN) {
	for (int i = 0; i < a.size(); i++) {
		a[i] = rand() % MAX + MIN;  // ��������� �������� ������� �� MIN �� MAX
	}
}


void print_array_vector(vector<int>& a) {
	for (size_t i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// ����� ����������� ����������
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

// ����� ���������� �����
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

	size_t base = begin; //������� �������
	size_t current = begin;//������� ������� ������������ ����� �� ��������

	for (size_t i = begin + 1; i <= end; i++) {
		if (arr[i] < arr[base]) {				//���� ������� arr[i] ������ ��������
			swap(arr[i], arr[++current]);  //������ ��� � ������� ������� �������
		}
	}
	swap(arr[base], arr[current]);     //������� ������� �������� �� ����� ���������� ������������

	if (current > begin) {
		quicksort(arr, begin, current - 1);//����� ������� ��� ����� ����� �������
	}
	if (end > current + 1) {
		quicksort(arr, current + 1, end);//����� ������� ��� ������ ����� �������
	}
}

template<typename T>
void merging(vector<T>& a, size_t begin, size_t mid, size_t end) {
	T* c = new T[end - begin];					//����� ��� �������� ���������� �������

	size_t
		left = begin,						//������ �������� �� ����� �������
		right = mid,							//������ �������� �� ������ �������
		i = 0;								//������ ������� c 

	while (left < mid && right < end) {			//���� �� ��������� ����� ����� �� ��������
		if (a[left] <= a[right]) {				//������������ �������� �� ��������

			c[i] = a[left];						// ���� left ������ right, �� � ������ i ������� � �������� �������� �� ����� �������
			left++;
		}
		else {
			c[i] = a[right];					//� ��������� ������ �� ������
			right++;
		}
		i++;
	}
	//�������� ���������� �������� � ������ c
	if (left == mid) {							//���� ��� ��������� ����� ����� �����

		while (right < end) {					//�� �������� �������� �� ������

			c[i] = a[right];
			right++;
			i++;
		}
	}
	else if (right == end) {					//���� �� ��� ��������� ����� ������ �����

		while (left < mid) {				// �� �������� �������� �� �����

			c[i] = a[left];
			left++;
			i++;
		}
	}

	size_t j = 0;
	while (j < end - begin) {					//��������� �������� �� ������� � � ������ �
		a[begin + j] = c[j];
		j++;
	}
	delete[] c;
}

///����������� ������� ���������� �������� �� �����������
/// a - �����������������
///left - ����� ������� ����������
/// right - ������ ������� ����������
/// 
/// BigO = O(n log(n)) ��� ���� �������
template<typename T>
void mergesort(vector<T>& a, size_t left, size_t right) {

	if (left < right - 1) {
		size_t mid = left + (right - left) / 2;
		mergesort(a, left, mid);	//���������� ����� �������� ����������� �������
		mergesort(a, mid, right);  //���������� ������ �������� ����������� �������
		merging(a, left, mid, right);
	}
}












// ����� ��������� ������
template <typename T>
int binsearch(vector<T>& arr, size_t begin, size_t end, T value) {
	size_t left = begin;
	size_t right = end - 1;

	while (left <= right) {
		size_t mid = left + (right - left) / 2; // ������� ��������

		if (arr[mid] == value) { // ���� ������
			return value; // ���������� ������
		}
		else if (arr[mid] < value) { // ���� �������� ������, ���� ������
			left = mid + 1;
		}
		else { // ���� �������� ������, ���� �����
			right = mid - 1;
		}
	}
	return -1; // ���� �� ������
}

// ����� ����������������� ������
template <typename T>
int interpolationsearch(vector<T>& arr, size_t begin, size_t end, T value) {
	size_t left = begin;
	size_t right = end - 1;

	while (left <= right && value >= arr[left] && value <= arr[right]) {
		// ������� �������, ��������� ������������
		size_t pos = left + ((value - arr[left]) * (right - left) / (arr[right] - arr[left]));

		if (arr[pos] == value) { // ���� ������
			return value; // ���������� ������
		}
		else if (arr[pos] < value) { // ���� �������� ������, ���� ������
			left = pos + 1;
		}
		else { // ���� �������� ������, ���� �����
			right = pos - 1;
		}
	}
	return -1; // ���� �� ������
}

//����� �� �������� ���������� �� max � min ��� �� min � max � ������������ �������
template <typename T>
bool sort_check(vector<T>& arr) {
		for (size_t i = 0; i < arr.size() - 1; i++) {
			if (arr[i] < arr[i + 1]) {
				return true;
			}
		};
	return false;
}