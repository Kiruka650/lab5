#define SRT_SECURE_NO_WORNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <time.h>
using namespace std;

void bfs(int v, int** p, int n, int* vis)
{
	queue <int> q{};
	q.push(v);
	vis[v] = true;

	while (!q.empty())
	{
		v = q.front();
		q.pop();
		cout << ">> " << v + 1 << " ";

		for (int i = 0; i < n; i++)
		{
			if (p[v][i] == 1 and vis[i] == false)
			{
				q.push(i);
				vis[i] = true;
			}
		}
	}
}

void vivod(int** p, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int i, j, n, v; //n - размер матрицы, v - вершина начала обхода алгоритма
	double ver;
	int tmp;
	cout << "Введите размер матрицы ";
	cin >> n;
	cout << "Введите вероятность от 0 до 100: ";
	cin >> ver;

	cout << "Введите вершину для начала поиска в ширину ";
	cin >> v;
	v -= 1;

	int* vis = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		vis[i] = 0;
	}

	int** p = (int**)malloc(n * sizeof(int*)); //выделение памяти для матрицы смежности
	for (i = 0; i < n; i++) {
		p[i] = (int*)malloc(n * sizeof(int));
	}

	srand(time(NULL));                              //заполнение массива p

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				p[i][j] = 0;
			}
			else
			{
				tmp = rand() % 100;
				if (tmp < ver)
					p[i][j] = 1;
				else
					p[i][j] = 0;
			}
		}
	}
	for (i = 0; i < n; i++)							//отзеркаливание матрицы
	{
		for (j = 0; j < n; j++)
		{
			p[j][i] = p[i][j];
		}
	}

	vivod(p, n);
	cout << endl << endl;
	bfs(v, p, n, vis);
	cout << endl;
	for (i = 0; i < n; i++) {
		if (vis[i] == 0) {
			bfs(i, p, n, vis);
			cout << endl;
		}
	}
	free(p);

	free(vis);
	cout << endl;
	system("pause");
	return 0;
}

