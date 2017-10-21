#include<iostream>
#include <ctime>
using namespace std;
int num[1000000];
int tran(int a, int b)
{
	int i = a;
	int j = b + 1;
	int x = num[a];
	while (true)
	{
		while (num[++i] < x && i < b);
		while (num[--j] > x);
		if (i >= j) break;
		int temp = num[i];
		num[i] = num[j];
		num[j] = temp;
	}
	num[a] = num[j];
	num[j] = x;
	return j;
}
void qsort(int a, int b)
{
	if (a < b)
	{
		int c = tran(a, b);
		qsort(a, c - 1);
		qsort(c + 1, b);
	}
}
int main()
{
	for (int i = 0; i < 1000000; i++)
		num[i] = rand() ;
	clock_t s = clock();
	qsort(0, 999999);
	clock_t end = clock(); 
	cout << (double)(end - s) / CLOCKS_PER_SEC;
}