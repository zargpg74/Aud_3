#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<malloc.h>
#include<Windows.h>

#include"Game.h"


int str_len(char* string) {//������� ���������� ����� ������
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

char* str_tolower(char* string) {//������� ����� ��������
	int len = str_len(string);
	char* eng_lower = "�������������������������������";
	char* eng_bigger = "�����Ũ�������������������������";
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
	SetConsoleCP(1251); //������� ����
	SetConsoleOutputCP(1251);
	setlocale(0, "ru");
	system("cls");

	char* word = NULL;//������ ��� ������ �����

	int f = 0, l = 0;//���������� ��� �������� �������� ������ � ��������� ����

	int n = 0;//���������� �������

	char* first_letter = NULL;//������ ������ ����
	char* last_letter = NULL;//������ ��������� ����

	char** city = NULL;//������ ������� � ���� �������

	int i = -1;//i-�������

	printf("������� ������. ����� ������� ������ ������� �������, � ��� ���������� ����� ������� '!,'\n");

	while (1)
	{
		int k;
		for (k = 0; k < 255; k++)//���������� ����� ���� �� ����� ������ �������. ������ ������ �������������� ������ ��� ������� ������������� ������
		{
			word = (char*)realloc(word, (k + 1) * sizeof(char));
			scanf_s("%c", &word[k]);
			if (word[k] == ',')
				break;
		}

		if (word[1] == '!')//������� ���������� �����
			break;

		i++;
		n++;

		str_tolower(word);//������ ������� ����� ����� �� ������

		city = (char**)realloc(city, n * sizeof(char*));//��������� ������ ��� ������ � �������
		city[i] = (char*)malloc((k - 1) * sizeof(char));

		first_letter = (char*)realloc(first_letter, n * sizeof(char));//��������� ������ ��� ������ � ��������� ����
		last_letter = (char*)realloc(last_letter, n * sizeof(char));

		for (int j = 0; j < k - 1; j++)//����������� i ������ ������� ������� �������� �����. ���������� ������ � ��������� ����� � ��������������� ������
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

		*word = NULL;//�������� ������ ����� ��� ������ ������
	}

	int m = 0;//������� ����������


	for (int i = 0; i < n; i++)// ��������� ������ � ��������� �����
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (first_letter[i] == last_letter[j])//���� ������� ���������� ������ ����� �� �� ������� � ������� ����� �� ���� ���������� ���������
			{
				m++;
				first_letter[i] = i;
				last_letter[j] = j;

				break;
			}
		}
	}

	if (m >= n - 1)//����������� ������� ��� ��������� ������� ����
		printf("\n��");
	else
		printf("\n���");

	for (int i = 0; i < n; i++)//������� ��� �������
	{
		free(city[i]);
	}
	free(city);
	free(first_letter);
	free(last_letter);
}
