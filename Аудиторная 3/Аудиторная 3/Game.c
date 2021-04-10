#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<malloc.h>
#include<Windows.h>

#include"Game.h"


int str_len(char* string) {//функция вычисления длины строки
	int i = 0;
	while (1)
		if (string[i] != '\0' && string[i] != '\n')
			i++;
		else if (string[i] == '\n')
			break;
		else if (string[i] == '\0')
			break;
	return i;
}

char* str_tolower(char* string) {//функция смена регистра
	int len = str_len(string);
	char* eng_lower = "абвгдеёжзиклмнопрстуфхцчшщъыьэюя";
	char* eng_bigger = "АБВГДЕЁЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	for (size_t i = 0; i <= len; i++) {
		for (size_t x = 0; x < 27; x++) {
			if (string[i + 1] == eng_bigger[x])
				string[i + 1] = eng_lower[x];
		}
	}
	return string;
}


void Game()
{
	SetConsoleCP(1251); //Русский язык
	SetConsoleOutputCP(1251);
	setlocale(0, "ru");
	system("cls");

	char* word = NULL;//массив для записи слова

	int f = 0, l = 0;//Переменные для индексов массивов первых и последних букв

	int n = 0;//Количество городов

	char* first_letter = NULL;//массив первых букв
	char* last_letter = NULL;//массив последних букв

	char** city = NULL;//массив городов в виде матрицы

	int i = -1;//i-счетчик

	printf("Введите города. После каждого города ставьте запятую, а для завершения ввода введите '!,'\n");

	while (1)
	{
		int k;
		for (k = 0; k < 255; k++)//записываем слово пока не будет нажата запятая. Каждый символ перезаписываем массив для точного распределения памяти
		{
			word = (char*)realloc(word, (k + 1) * sizeof(char));
			scanf_s("%c", &word[k]);
			if (word[k] == ',')
				break;
		}

		if (word[1] == '!')//условие завершение ввода
			break;

		i++;
		n++;

		str_tolower(word);//меняем регистр всего слова на нижний

		city = (char**)realloc(city, n * sizeof(char*));//выделение памяти для города в массиве
		city[i] = (char*)malloc((k - 1) * sizeof(char));

		first_letter = (char*)realloc(first_letter, n * sizeof(char));//Выделение памяти для первых и последних букв
		last_letter = (char*)realloc(last_letter, n * sizeof(char));

		for (int j = 0; j < k - 1; j++)//присваиваем i строке матрицы городов значение слова. Записываем первую и последнюю букву в соответствующий массив
		{
			city[i][j] = word[j + 1];
			if (j == 0)
			{
				first_letter[f] = city[i][j];
				f++;
			}
			if (j == k - 2) {
				last_letter[l] = city[i][j];
				l++;
			}
		}

		*word = NULL;//обнуляем массив слова для записи нового
	}

	int m = 0;//счетчик совпадений


	for (int i = 0; i < n; i++)// проверяем первые и последние буквы
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (first_letter[i] == last_letter[j])//если найдено совпадение меняем буквы на их индексы в массиве чтобы не было повторного сравнения
			{
				m++;
				first_letter[i] = i;
				last_letter[j] = j;

				break;
			}
		}
	}

	if (m >= n - 1)//достаточное условие для выявления цепочки слов
		printf("\nДА");
	else
		printf("\nНЕТ");

	for (int i = 0; i < n; i++)//очищаем все массивы
	{
		free(city[i]);
	}
	free(city);
	free(first_letter);
	free(last_letter);
}
