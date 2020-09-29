#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void quickSort(int arr[], int low, int high)
{
	int first = low;
	int last = high;
	int key = arr[first];
	if (low >= high)
		return;
	while (first < last)
	{
		while (first < last && arr[last] > key)
		{
			last--;
		}
		arr[first] = arr[last];

		while (first < last && arr[first] < key)
		{
			first++;
		}
		arr[last] = arr[first];
	}
	arr[first] = key;

	quickSort(arr, low, first - 1);
	quickSort(arr, first + 1, high);
}
void print(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

}
int main()
{
	int i;
	int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	printf("\n");
	quickSort(arr, 0, sz-1);
	print(arr, sz);
	printf("\n");

	return 0;
}