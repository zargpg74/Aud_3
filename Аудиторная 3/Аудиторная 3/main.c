#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#include"Massive.h"
#include"Game.h"

int main()
{
	setlocale(0, "ru");

	int k;
	printf("Введите номер задания: ");
	scanf_s("%d", &k);
	switch (k)
	{
	case 1:
		Massive();
		break;
	case 2:
		Game();
		break;
	default:
		printf("Введен неправильный номер задания. Пожалуйста, попробуйте еще раз.");
		exit(k);
	}
}