#include <iostream>
#include <cmath>

using namespace std;

void Task1() {
    cout << "Hello World" << endl;
}

void Task2() {
    int a, b, sum, difference, multiplication, division, remainder;
    cout << "A = ";
    cin >> a;
    cout << "B = ";
    cin >> b;
    sum = a + b;
    difference = a - b;
    multiplication = a * b;
    division = a / b;
    remainder = a % b;
    cout << "Sum = " << sum;
    cout << "\nDifference = " << difference;
    cout << "\nMultiplication = " << multiplication;
    cout << "\nRemainder = " << remainder;
    cout << "\nDivision = " << division << endl;
}

void Task4() {
    int a, b;
    cout << "A = ";
    cin >> a;
    cout << "B = ";
    cin >> b;
    if ((a % b) > 0) {
        cout << "Is not divided" << endl;
    } else {
        cout << "Is divided" << endl;
    }
}

void Task5() {
    int a, b;
    cout << "A = ";
    cin >> a;
    cout << "B = ";
    cin >> b;

    a += b;
    b = a - b;
    a -= b;

    cout << "A = " << a;
    cout << "\nB = " << b << endl;
}

void Task6() {
    int a, b, c, d;
    cout << "Enter a three-digit number: ";
    cin >> a;
    b = a / 100;
    c = a / 10 % 10;
    d = a % 10;
    cout << "Sum = " << b + c + d;
    cout << "\nCompos = " << b * c * d << endl;
}

void Task7() {
    cout << "The equation of a line passing through two points is: Ax + By + C = 0" << endl;
}

void Task8() {
    float p, r, pl, s;
    p = 3.14;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    pl = p * (r * r);
    s = 2 * p * r;
    cout << "Square = " << pl;
    cout << "\nCircumference = " << s << endl;
}

void Task9() {
    int n, div = 2;
    cout << "N = ";
    cin >> n;
    cout << n << " = 1";
    while (n > 1) {
        while (n % div == 0) {
            cout << " * " << div;
            n = n / div;
        }
        div++;
    }
}

void Task10() {
    int n;
    cout << "N = ";
    cin >> n;
    int *a = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
        a[i] = i;
    for (int p = 2; p < n + 1; p++) {
        if (a[p] != 0) {
            cout << a[p] << endl;
            for (int j = p * p; j < n + 1; j += p)
                a[j] = 0;
        }
    }
}

void Task11() {
    int height; // высота треугольника
    cout << "Enter the height of an isosceles triangle: ";
    cin >> height;

    for (int i = 0; i < height; i++) {
        for (int j = 1; j < height - i; j++) {
            cout << "   ";
        }

        for (int j = height - 2 * i; j <= height; j++) {
            cout << "^_O";
        }
        cout << endl;
    }

}

int main() {
    int a;
    cout << "Enter the job number: ";
    cin >> a;
    switch (a) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 4:
            Task4();
            break;
        case 5:
            Task5();
            break;
        case 6:
            Task6();
            break;
        case 7:
            Task7();
            break;
        case 8:
            Task8();
            break;
        case 9:
            Task9();
            break;
        case 10:
            Task10();
            break;
        case 11:
            Task11();
            break;
    }
    return 0;
}