#include <iostream>

using namespace std;

int MaxElement(int**, int, int, int);
int** FillMatrixB(int**, int);
inline int** AllocMatrix(int);
inline bool IsDataValid(int n);
void EnterDimention(int &t);
void FillMatrix(int**, int);
void DisplayMatrix(int**, int);
inline void ClearMemory(int**, int);


int main()
{

	while (true)
	{
		cout.width(50);
		cout << endl << "Welcome to the programm!";
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		int n;
		EnterDimention(n);
		int**a = AllocMatrix(n);
		FillMatrix(a, n);
		system("cls");
		cout << endl << "Before" << endl << endl;
		DisplayMatrix(a, n);
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		cout << endl << "after" << endl << endl;
		int **b = FillMatrixB(a, n);
		DisplayMatrix(b, n);
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		cout << endl;
		system("pause");
		system("cls");
		ClearMemory(a, n);
		ClearMemory(b, n);
		char s;
		cout << "Would you like to countinie? " << endl;
		cout << "Yes- y or Y " << endl;
		cout << "No- other symbols" << endl;
		cout << "Waiting for Enter: " << endl;
		cin >> s;
		system("cls");
		if (s == 'y' || s == 'Y') continue;
		break;

	}

	return 0;
}


int MaxElement(int**matr, int n, int str, int stb)
{
	int max = matr[0][n-1];
	int up = str+1;
	int down = str-1;
	for (int j = n - 1; j >= 0; j--)
	{
		for (int i = 0; i < n; i++)
		{
			if ((j < stb) && (i == up))
			{
				i = down;
				continue;
			}
				if (matr[i][j]>max) max = matr[i][j];
		}
		if (j <= stb)
		{
			if (up > 0) up--;
			if (down < n - 1)down++;
		}
	}
	return max;
}

int** FillMatrixB(int**a, int n)
{
	int**b = AllocMatrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = MaxElement(a, n, i, j);
		}
	}
	return b;
}

inline int** AllocMatrix(int n)
{
	int**a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	return a;
}

inline bool IsDataValid(int n)
{
	if (n <= 0) return false;
	return true;
}

void EnterDimention(int &t)
{
	while (true)
	{
		cout << "Enter size   0<=n    : ";
		cin >> t;
		if (IsDataValid(t)) break;
		cout << "Error!" << endl;
	}
}

void FillMatrix(int**matr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "A [" << i + 1 << "] [" << j + 1 << "] :";
			cin >> matr[i][j];
			cout << endl;
		}
	}
}


void DisplayMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(7);
			cout << a[i][j];
		}
		cout << endl;
	}
}

inline void ClearMemory(int**a, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}