#include<iostream>
#include <ctime>
using namespace std;
int b[1000000], a[1000000];
template <typename  T>
void merge(T *a, T *b, int start, int p, int len)
{
	int i = start;
	int j = p + 1;
	int ptr = start;
	while (i <= p && j <= len)
	{
		if (a[i] <= a[j])
		{
			b[ptr++] = a[i++];
		}
		else
		{
			b[ptr++] = a[j++];
		}
		if (i > p)
		{
			for (int h = j; h <= len; h++)
				b[ptr++] = a[h];
		}
		else if (j > len)
		{
			for (int h = i; h <= p; h++)
				b[ptr++] = a[h];
		}
	}
}
template<typename T>
void mergesort(T *a, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergesort(a, left, mid);
		mergesort(a, mid + 1, right);
		merge(a, b, left, mid, right);
		for (int i = left; i <= right; i++)
			a[i] = b[i];
	}
}
int main()
{
	for (int i = 0; i < 1000000; i++)
		a[i] = rand();
	clock_t s = clock();
	mergesort(a, 0, 999999);
	clock_t end = clock();
	cout << (double)(end - s) / CLOCKS_PER_SEC;
	return 0;
}