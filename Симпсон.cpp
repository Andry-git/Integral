#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double case3(int input, double N)
{
    cout << endl;
    cout << "1. Ввести количество разбиений\n";
    cout << "2. Вернуться\n";
    cin >> input;

    switch (input)
    {
    case 1:
    {
        cout << "\nВведите N = ";
        cin >> N;
        double a = 0, b = 2, n = N / 2;
        double h = (b - a) / (2 * n);
        double h1 = h / 2;
        vector <double> vectorX(N + 1), vectorY(N + 1);
        for (int i = 0; i < N; i++)
        {
            vectorX.at(i) = a + i * h;
            vectorY.at(i) = 4 * (pow(vectorX.at(i), 3)) + pow(vectorX.at(i), 2);
        }
        double s1 = 0, s2 = 0;
        for (int i = 1; i < N - 1; i += 2)
        {
            s1 += vectorY.at(i);
        }
        for (int i = 2; i < N - 2; i += 2)
        {
            s2 += vectorY.at(i);
        }
        double simpson = (h / 3) * (vectorY.at(0) + vectorY.at(N) + 4 * (s1)+2 * (s2));
        cout << "\nРезультат формулы Симпсона: " << simpson;
        cout << "\nТочное значение: " << 56 / 3;
        for (int i = 0; i < N; i++)
        {
            vectorX.at(i) = a + i * h1;
            vectorY.at(i) = 4 * (pow(vectorX.at(i), 3)) + pow(vectorX.at(i), 2);
        }
        for (int i = 1; i < N - 1; i += 2)
        {
            s1 += vectorY.at(i);
        }
        for (int i = 2; i < N - 2; i += 2)
        {
            s2 += vectorY.at(i);
        }
        double simpson1 = (h1 / 3) * (vectorY.at(0) + vectorY.at(N) + 4 * (s1)+2 * (s2));
        double r = 18 - simpson1, r1 = (abs(simpson - simpson1)) / 15;
        cout << "\nРезультат формулы Симпсона с шагом h/2: " << simpson1;
        cout << "\nОценка погрешности по правилу Рунге: " << r1;
        case3(input, N);
        break;
    }

    case 2:
        cout << endl;
        cout << "1. Интеграл 4x^3 + x^2 в пределе от 0 до 2 \n";
        cout << "2. Интеграл от sinx в пределе от 0 до пи \n";
        cout << "3. Выход\n";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            case3(input, N);
        }
        case 2:
        {
            //case2(input, N);
            break;
        }
        case 3:

            break;
        }
        break;
    }
    return 0;
}

double case2(int input, double N)
{
    cout << endl;
    cout << "1. Ввести количество разбиений\n";
    cout << "2. Вернуться\n";
    cin >> input;

    switch (input)
    {
    case 1:
    {
        cout << "\nВведите N = ";
        cin >> N;
        double a = 0, b = 3.1415926535, n = N / 2;
        double h = (b - a) / (2 * n);
        double h1 = h / 2;
        vector <double> vectorX(N + 1), vectorY(N + 1);
        for (int i = 0; i < N; i++)
        {
            vectorX.at(i) = a + i * h;
            vectorY.at(i) = sin(vectorX.at(i));
        }
        double s1 = 0, s2 = 0;
        for (int i = 1; i < N - 1; i += 2)
        {
            s1 += vectorY.at(i);
        }
        for (int i = 2; i < N - 2; i += 2)
        {
            s2 += vectorY.at(i);
        }
        double simpson = (h / 3) * (vectorY.at(0) + vectorY.at(N) + 4 * (s1)+2 * (s2));
        cout << "\nРезультат формулы Симпсона: " << simpson;
        cout << "\nТочное значение: " << 2.0;
        for (int i = 0; i < N; i++)
        {
            vectorX.at(i) = a + i * h1;
            vectorY.at(i) = sin(vectorX.at(i));
        }
        for (int i = 1; i < N - 1; i += 2)
        {
            s1 += vectorY.at(i);
        }
        for (int i = 2; i < N - 2; i += 2)
        {
            s2 += vectorY.at(i);
        }
        double simpson1 = (h1 / 3) * (vectorY.at(0) + vectorY.at(N) + 4 * (s1)+2 * (s2));
        double r = 2.0 - simpson1, r1 = (abs(simpson - simpson1)) / 15;
        cout << "\nРезультат формулы Симпсона с шагом h/2: " << simpson1;
        cout << "\nОценка погрешности по правилу Рунге: " << r1;
        case2(input, N);
        break;
    }

    case 2:
        cout << endl;
        cout << "1. Интеграл 4x^3 + x^2 в пределе от 0 до 2 \n";
        cout << "2. Интеграл от sinx в пределе от 0 до пи \n";
        cout << "3. Выход\n";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            case3(input, N);
        }
        case 2:
        {
            case2(input, N);
            break;
        }
        case 3:

            break;
        }
        break;
    }
    return 0;
}

double case1(int input, double N)
{
    cout << endl;
    cout << "1. Интеграл 4x^3 + x^2 в пределе от 0 до 2 \n";
    cout << "2. Интеграл от sinx в пределе от 0 до пи \n";
    cout << "3. Выход\n";
    cin >> input;
    switch (input)
    {
    case 1:
    {
        case3(input, N);
    }
    case 2:
    {
        case2(input, N);
        break;
    }
    case 3:
   
        break;
    }
    return 0;
}



int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Формула Симпсона";
    double N = 0;
    int input = 0;
    case1(input, N);

}