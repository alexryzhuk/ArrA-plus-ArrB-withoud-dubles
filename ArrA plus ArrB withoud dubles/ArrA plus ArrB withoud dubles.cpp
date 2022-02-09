// ArrA plus ArrB withoud dubles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
using namespace std;

void inputArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
}
void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
}
void sortAandB(int* A, int m, int* B, int n, int*& C, int& NM)
{
	int ii = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i] == B[j])
			{
				break;
			}
			else if (j == n - 1)
			{
				C[ii] = A[i];
				ii++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (B[i] == A[j])
			{
				break;
			}
			else if (j == m - 1)
			{
				C[ii] = B[i];
				ii++;
			}
		}
	}
	NM = ii;
}
void withoutDubles(int* C, int NM, int*& D, int& z)
{
	int jj = 0;
	for (int i = 0; i < NM - 1; i++)
	{
		for (int j = i + 1; j < NM; j++)
		{
			if (C[i] == C[j])
			{
				break;
			}
			else if(j==NM-1)
			{
				D[jj] = C[i];
				jj++;
			}
		}
	}
	z = jj;
}
int main()
{
	srand(time(NULL));
	int n = 1, m = 1;
	cout << "Enter n, m" << endl;
	cin >> m >> n;

	int NM = m + n;
	int z= m + n;
	int* A = new int[m];
	int* B = new int[n];
	int* C = new int[NM];
	int* D = new int[z];

	inputArr(A, m);
	printArr(A, m);
	cout << endl;
	inputArr(B, n);
	printArr(B, n);
	sortAandB(A, m, B, n, C, NM);
	withoutDubles(C, NM, D, z);
	cout << endl;
	printArr(D, z);

	delete[]A;
	delete[]B;
	delete[]C;
	delete[]D;
}
