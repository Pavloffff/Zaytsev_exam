#include <bits/stdc++.h>

using namespace std;

typedef struct 
{
	int *arr;
	int n;
} hoar_input;

void swap(int *arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int get_pivot(int *arr, int n)
{
	int left = 0, right = n - 1, mid = (left + right) / 2;
	if ((arr[left] >= arr[right] && arr[left] <= arr[mid]) 
		|| (arr[left] <= arr[right] && arr[left] >= arr[mid])) {
		return left;
	} else if ((arr[right] >= arr[left] && arr[right] <= arr[mid]) 
		|| (arr[right] <= arr[left] && arr[right] >= arr[mid])) {
		return right;
	} else {
		return mid;
	}
}

int partition(int *arr, int n, int p)
{
	int i = 0, j = n - 1;
	int pivot = arr[p];
	while (i <= j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			if (arr[i] > arr[j])
				swap(arr, i, j);
			i++;
			j--;
		}
	}
	return i;
}

void hoar(int *arr, int n)
{
	stack<hoar_input> s;
	s.push({arr, n});
	while(!s.empty()) {
		hoar_input hi = s.top();
		s.pop();
		arr = hi.arr;
		n = hi.n;
		while (n > 1) {
			int p = get_pivot(arr, n);
			int i = partition(arr, n, p);
			if (n - i > i) {
				s.push({arr + i, n - i});
				n = i;
			} else {
				s.push({arr, i});
				arr = arr + i;
				n = n - i;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n = 11;
	int arr[n] = {13, 2, 45, 4, 6, 0, 7, 11, 28, 1, -26};
	hoar(arr, n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	return 0;
}
