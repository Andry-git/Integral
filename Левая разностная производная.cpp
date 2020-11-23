
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double case2(int input, double h, double x)
{
    cout << endl;
    cout << "1. Ввести x\n";
    cout << "2. Вернуться к выбору шага\n";
    cin >> input;

    switch (input)
    {
    case 1:
    {
        cout << "\nВведите x = ";
        cin >> x;
        double A, A1, A2, B, B1, B2;
        A = x, B = sin(A);
        A1 = x - h;
        B1 = sin(A1);
        A2 = x + h;
        B2 = sin(A2);
        double cA = x, cB = cos(cA);
        double l = (B2 - B) / h;
        double pr = (B - B1) / h;
        double centr = (B2 - B1) / (2 * h);
        cout << "\nЛевая разностная производная: " << l;
        cout << "\nПравая разностная производная: " << pr;
        cout << "\nЦентральная разностная производная: " << centr;
        cout << "\nПроизводная: " << cB << endl;
        case2(input, h, x);
        break;
    }

    case 2:
        cout << endl;
        cout << "1. Ввести длину шага\n";
        cout << "2. Выход\n";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            cout << endl;
            cout << "Введите длину шага: ";
            cin >> h;
            case2(input, h, x);
        }
        case 2:
            break;
        }
    }
    return 0;
}

double case1(int input, double h, double x)
{
    cout << endl;
    cout << "1. Ввести длину шага\n";
    cout << "2. Выход\n";
    cin >> input;
    switch (input)
    {
    case 1:
    {
        cout << endl;
        cout << "Введите длину шага: ";
        cin >> h;
        case2(input, h, x);
    }
    case 2:
        break;
    }
    return 0;
}



int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "y = sinx\n";
    double x = 0, h = 0;
    int input = 0;
    case1(input, h, x);

}
