using namespace std;
#include <iostream>
#include <cmath>

double gauss()
{
	double n, x, y, z, rez = 0;
	double currentX;
	cout << "Введите количество уравнений: \n";
	cin >> n;
	double** X;
	X = new double* [n+1];
	double* result;
	result = new double[n];
	for (int i = 0; i < n+1; i++) {
		X[i] = new double[n+1]; // инициализация массива
	}

		cout << "Введите коэффициенты при X: " << endl;
		for (int j = 0; j < n; j++) {
			cout << "Уравнение " << j+1 << ": \n";
			for (int i = 0; i < n; i++) {
				cout << "Коэффициент при X" << i+1 << "= ";
				cin >> x;
				X[j][i] = x;
			}
		}
		cout << endl;
		cout << "Введите свободные члены: " << endl;
		for (int j = 0; j < n; j++) {
			for (int i = n; i < n + 1; i++) {
				cout << "Для уравнения " << j + 1 << " = ";
				cin >> x;
				X[j][i] = x;
			}
		}
		int f = n;
		cout << endl;
		cout << "Система уравнений:\n ";
		for (int j = 0; j < n; j++) {
			int zero = 0;
			for (int i = 0; i < n; i++) {

				if (i == 0 || X[j][i] < 0)
					if (X[j][i] == 1)
						cout << "X" << i + 1 << " ";
					else
						if (X[j][i] == -1)
							cout << "-X" << i + 1 << " ";
						else
							if (X[j][i] == 0)
								zero++ ;
							else
								cout << X[j][i] << "X" << i + 1 << " ";
				else
					if (X[j][i] == 1)
						cout << "+ X" << i + 1 << " ";
					else
						if (X[j][i] == 0)
							zero++;
						else
							cout << "+ " << X[j][i] << "X" << i + 1 << " ";

			}
			if (zero!=n)
				cout << " = " << X[j][f] << "\n";
		}
		cout << endl;
		///////////////////////////////////////////////////////////////////////////////////
		double max, a;
		int i, j, k, m;
		for (k = 0; k < n; k++) //Поиск максимального элемента в столбце
		{
			max = abs(X[k][k]);
			i = k;
			for (m = k + 1; m < n; m++)
				if (abs(X[m][k]) > max)
				{
					i = m;
					max = abs(X[m][k]);
				}

			if (max == 0)   //проверка на нулевой элемент
			{
				cout << "Система не имеет решений" << endl;
			}

			if (i != k)  //  перестановка i-ой строки, содержащей главный элемент k-ой строки
			{
				for (j = k; j < n + 1; j++)
				{
					a = X[k][j];
					X[k][j] = X[i][j];
					X[i][j] = a;
				}
			}
			max = X[k][k];//преобразование k-ой строки 
			X[k][k] = 1;
			for (j = k + 1; j < n + 1; j++)
				X[k][j] = X[k][j] / max;
			for (i = k + 1; i < n; i++)//преобразование строк с помощью k-ой строки
			{
				a = X[i][k];
				X[i][k] = 0;
				if (a != 0)
					for (j = k + 1; j < n + 1; j++)
						X[i][j] = X[i][j] - a * X[k][j];
			}
		}

		for (i = n - 1; i >= 0; i--)   //Нахождение решений СЛАУ
		{
			result[i] = 0;
			max = X[i][f];
			for (j = n; j > i; j--)
				max = max - X[i][j] * result[j];
			result[i] = max;
		}

		cout << "Решение системы:" << endl;  //вывод решений
		for (i = 0; i < n; i++)
		{
			cout << "X" << i + 1 << " =" << result[i];
			cout << endl;
		}
		return 0;
}

int main()
{
	double rez = 0;
	setlocale(LC_ALL, "Rus");
	cout << "Метод Гаусса с выбором главного элемента по столбцу\n" << endl;
	gauss();
	cout << endl;
	return 0;
}