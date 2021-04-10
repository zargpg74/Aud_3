#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<malloc.h>

#include"Massive.h"


void Massive()
{
	system("cls");
	setlocale(0, "ru");

	int n;
	printf("Введите размер массива: ");
	scanf_s("%d", &n);

	int* mass = (int*)malloc(n * sizeof(int));
	printf("Введите массив: ");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &mass[i]);
	}

	system("cls");
	printf("Размер вашего массива: %d\n", n);
	printf("Ваш массив: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", mass[i]);
	}

	int* mass1 = NULL;
	int l = 0, count = 0;

	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j <= i; j++)
		{
			if (i != j)
			{
				if (mass[j] == mass[i])
					count++;
			}
		}
		if (count > 0)
			continue;

		mass1 = (int*)realloc(mass1, (l + 1) * sizeof(int));
		mass1[l] = mass[i];
		l++;
	}

	printf("\nИсправленный массив: ");
	for (int i = 0; i < l; i++)
	{
		printf("%d ", mass1[i]);
	}

	printf("\nРазмер исправленного массива: %d", l);

	free(mass);
	free(mass1);
}
