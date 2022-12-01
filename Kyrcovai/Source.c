#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

#define PI 3.1415926535
#define SCREENW 60
#define SCREENH 40

typedef double (*Funcional)(double);

void menu();
double f1(double x);
double f2(double x);
double* step_func(Funcional func, double lb, double rb, double step);
int print_func(Funcional func, double lb, double rb, double step);
int graph(double x0, double x1, Funcional fun�);


void main()
{
	setlocale(0, "RUS");
	double x;
	double* res;
	int choisemain;
	char lb, rb;
	double lNum, rNum, step;
	int choise;
	menu();
	scanf("%d", &choisemain);
	while (choisemain != 6) {
		switch (choisemain) {
		case 1:
			printf("\n������� �������� x: ");
			scanf("%lf", &x);
			printf("\nY(%.2lf)=%.2lf", x, f1(x));
			break;
		case 2:
			printf("\n������� �������� x: ");
			scanf("%lf", &x);
			printf("\nV(%.2lf)=%.2lf", x, f2(x));
			break;
		case 3:
			getchar();
			printf("������� ��������, ������������ ��� ������� �������: ");
			scanf("\n%c%lf;%lf%c", &lb, &lNum, &rNum, &rb);
			printf("\n%c%.2lf;%.2lf%c", lb, lNum, rNum, rb);
			if (lNum > rNum) {
				printf("\n\n������: �������� ����� ������� ��������� ������ �������� ������ ������� ���������.");
			}
			if ((lb == '(' || lb == '[') && (rb == ')' || rb == ']')) {
				getchar();
			}
			else {
				puts("\n\n������: �� ����� ����������� ������ ��� ������� �������");
				break;
			}
			printf("\n\n������� �������� ���� �������: ");
			scanf("%lf", &step);
			if (rb == ')') {
				rNum = rNum - step;
			}
			if (lb == '(') {
				lNum = lNum + step;
			}
			res = step_func(f1, lNum, rNum, step);
			print_func(f1, lNum, rNum, step);
			break;
		case 4:
			getchar();
			printf("������� ��������, ������������ ��� ������� �������: ");
			scanf("\n%c%lf;%lf%c", &lb, &lNum, &rNum, &rb);
			printf("\n%c%.2lf;%.2lf%c", lb, lNum, rNum, rb);
			if (lNum > rNum) {
				printf("\n\n������: �������� ����� ������� ��������� ������ �������� ������ ������� ���������.");
			}
			if ((lb == '(' || lb == '[') && (rb == ')' || rb == ']')) {
				getchar();
			}
			else {
				puts("\n\n������: �� ����� ����������� ������ ��� �������");
				break;
			}
			printf("\n\n������� �������� ���� �������: ");
			scanf("%lf", &step);
			if (rb == ')') {
				rNum = rNum - step;
			}
			if (lb == '(') {
				lNum = lNum + step;
			}
			res = step_func(f2, lNum, rNum, step);
			print_func(f2, lNum, rNum, step);
			break;
		case 5:
			getchar();
			printf("������� ��������, ������������ ��� ������� �������: ");
			scanf("\n%c%lf;%lf%c", &lb, &lNum, &rNum, &rb);
			printf("\n%c%.2lf;%.2lf%c", lb, lNum, rNum, rb);
			if (lNum > rNum) {
				printf("\n\n������: �������� ����� ������� ��������� ������ �������� ������ ������� ���������.");
			}
			if ((lb == '(' || lb == '[') && (rb == ')' || rb == ']')) {
				getchar();
			}
			else {
				puts("\n\n������: �� ����� ����������� ������ ��� �������");
				break;
			}
			printf("\n\n������� ��� ��� �������: ");
			scanf("%lf", &step);
			if (rb == ')') {
				rNum -= step;
			}
			if (lb == '(') {
				lNum += step;
			}
			puts("������� ����� �������:\nY(x) - 1;\nV(x) - 2.\n");
			scanf("%d", &choise);
			switch (choise)
			{
			case 1:
				graph(lNum, rNum, f1);
				break;
			case 2:
				graph(lNum, rNum, f2);
				break;
			default:
				puts("������: ������� ��� ���� ������� �� ����������.");
			}
			break;
		default:
			printf("\n������: �� ����� �������������� ����� ����. ���������� �����:");
		}
		printf("\n\n������� ����� ������ ����: ");
		getchar();
		scanf("%d", &choisemain);
	}

	return 0;
}

void menu()
{
	printf("******************************** ���� *************************************\n");
	printf("*                                                                         *\n");
	printf("* 1 �������� ������� Y(x).                                                *\n");                                  
	printf("* 2 �������� ������� V(x).                                                *\n");
	printf("* 3 �������� ������� Y(x) � �������� ���������� � �����.                  *\n");
	printf("* 4 �������� ������� V(x) � �������� ���������� � �����.                  *\n");
	printf("* 5 ������ ������� Y(x) ��� V(x).                                         *\n");
	printf("* 6 ����� �� ���������.                                                   *\n");
	printf("*                                                                         *\n");
	printf("***************************************************************************\n");
	puts("\n\n������� ����� ������ ���� : ");
	return 0;
}

double f1(double x)
{
	double res;
	res = 2 * sin(PI * x) * sin(3 * PI * x) - 0.5;
	return res;
}

double f2(double x)
{
	double res;
	if (x >= 10) { res = 3 * pow(sin(x), 3) + cos(x); }
	else if (5 < x < 10) { res = (3 / 4) * exp(x); }
	else if (0 < x <= 5) { res = pow(sin(x), 3) - sqrt(log(fabs(x))); }
	return res;
}

double* step_func(Funcional fun, double lb, double rb, double step)
{
	double* result = (double*)malloc(((rb - lb) / step) * sizeof(double));
	double count = lb;
	for (int i = 0; i <= (rb - lb) / step; i++)
	{
		result[i] = fun(count);
		count += step;
	}
	return result;
}

int print_func(Funcional fun, double lb, double rb, double step)
{
	puts("\n");
	for (double x = lb; x <= rb; x += step) {
		printf("| x = %9.3f | y = %9.3f |\n", x, fun(x));
	}
	puts("\n");
	return 0;
}

int graph(double x0, double x1, Funcional fun�)
{
	char screen[SCREENW][SCREENH];
	double x, y[SCREENW];
	double ymin = 0, ymax = 0;
	double hx, hy;
	int i, j;
	int xz, yz;
	hx = (x1 - x0) / (SCREENW - 1);
	for (i = 0, x = x0; i < SCREENW; ++i, x += hx)
	{
		y[i] = fun�(x);
		if (y[i] < ymin) ymin = y[i];
		if (y[i] > ymax) ymax = y[i];
	}
	hy = (ymax - ymin) / (SCREENH - 1);
	yz = (int)floor(ymax / hy + 0.5);
	xz = (int)floor((0. - x0) / hx + 0.5);
	for (j = 0; j < SCREENH; ++j)
		for (i = 0; i < SCREENW; ++i)
		{
			if (j == yz && i == xz) screen[i][j] = '+';
			else if (j == yz) screen[i][j] = '-';
			else if (i == xz) screen[i][j] = '|';
			else screen[i][j] = ' ';
		}
	for (i = 0; i < SCREENW; ++i) {
		j = (int)floor((ymax - y[i]) / hy + 0.5);
		screen[i][j] = '*';
	}
	for (j = 0; j < SCREENH; ++j)
	{
		for (i = 0; i < SCREENW; ++i) putchar(screen[i][j]);
		putchar('\n');
	}
	return 0;
}