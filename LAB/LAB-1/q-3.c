#include <stdio.h>
int nonZero(int *arr, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (*((arr + i * n) + j) != 0)
			{
				count++;
			}
		}
	}
	return count;
}

int leadingDiagonalSum(int *arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				sum = sum + *((arr + i * n) + j);
		}
	}
	return sum;
}

int minorDiagonal(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i + j) == (n - 1))
			{
				printf(" %d", *((arr + i * n) + j));
			}
		}
	}
}
int productDiagonal(int *arr, int n)
{
	int mul = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				mul = mul * (*((arr + i * n) + j));
			}
			else if ((i + j) == (n - 1))
			{
				mul = mul * (*((arr + i * n) + j));
			}
		}
	}
	return mul;
}

int main()
{
	 printf("Arnab pal 213099\n");
	int n;
	printf("Enter edge size of square matrix: ");
	scanf("%d", &n);
	int matrix[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Enter values of row(%d) col(%d): ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("Original array\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	printf("non zero number count is: %d\n", nonZero(*matrix, n));
	printf("sum of leading diagonal element is: %d\n", leadingDiagonalSum(*matrix, n));
	printf("minor diagonal elements are:");
	minorDiagonal(*matrix, n);
	printf("\nproduct of all diagonal elements is: %d", productDiagonal(*matrix, n));
	return 0;
}
