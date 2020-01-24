//задание сделать класс дроби и выполнить арифметические действия с ними
#include <iostream>
#include <conio.h>

using namespace std;

class Rational {
    int a, b; //a-числитель b-знаменатель
public:
    Rational(int= 0, int= 1);

    Rational Add(const Rational &) const;

    Rational Sub(const Rational &) const;

    Rational And(const Rational &) const;

    Rational Div(const Rational &) const;

    void Print() const;

    void Change(int, int);

private:
    int Nod(int, int) const;
};

Rational::Rational(int chislit, int znamenat) {
    a = chislit;
    if (znamenat)
        b = znamenat;
    else {
        cout << "Cannot be divided by zero!" << endl;
        exit(1);
    }
};

int Rational::Nod(int c, int d) const {
    if (d == 0)
        return c;
    if (c % d == 0)
        return Nod(d, c % d);
};

Rational Rational::Add(const Rational &s) const {
    int c;
    Rational Sum;
    Sum.a = a * s.b + b * s.a;
    Sum.b = b * s.b;
    if (Sum.a > Sum.b)
        c = Nod(Sum.b, Sum.a);
    else
        c = Nod(Sum.b, Sum.a);
    Sum.a = Sum.a / c;
    Sum.b = Sum.b / c;
    return Sum;
};

Rational Rational::Sub(const Rational &s) const {
    int c;
    Rational Sum;
    Sum.a = a * s.b - b * s.a;
    Sum.b = b * s.b;
    if (Sum.a > Sum.b)
        c = Nod(Sum.b, Sum.a);
    else
        c = Nod(Sum.b, Sum.a);
    Sum.a = Sum.a / c;
    Sum.b = Sum.b / c;
    return Sum;
};

Rational Rational::And(const Rational &s) const {
    int c;
    Rational Sum;
    Sum.a = a * s.a;
    Sum.b = b * s.b;
    if (Sum.a > Sum.b)
        c = Nod(Sum.b, Sum.a);
    else
        c = Nod(Sum.a, Sum.b);
    Sum.a = Sum.a / c;
    Sum.b = Sum.b / c;
    return Sum;
};

Rational Rational::Div(const Rational &s) const {
    int c;
    Rational Sum;
    Sum.a = a * s.b;
    Sum.b = b * s.a;
    if (s.a == 0) {
        cout << "Cannot be divided by zero!" << endl;
        exit(1);
    };
    if (Sum.a > Sum.b)
        c = Nod(Sum.b, Sum.a);
    else
        c = Nod(Sum.b, Sum.a);
    Sum.a = Sum.a / c;
    Sum.b = Sum.b / c;
    return Sum;
};

void Rational::Print() const {
    if (b == 1)
        cout << a << endl;
    else
        cout << a << "/" << b << endl;
    double otv = (double) a / b;
    cout << otv << endl;
};

void Rational::Change(int d, int e) {
    int f;
    a = d;
    if (e)
        b = e;
    else {
        cout << "Cannot be divided by zero!" << endl;
        exit(1);
    };
    if (a > b)
        f = Nod(a, b);
    else
        f = Nod(b, a);
    a = a / f;
    b = b / f;
};

//int Rational::Nod (int c, int d) const
//	{
//	if (d==0)
//		return c;
//	if (c%d==0)
//		return 1;
//	return Nod (d, c%d);
//	};	

int main() {
    double h1, l1, h2, l2;
    std::cout << "Enter the first drop" << endl;
    std::cout << "Enter the numerator: ";
    std::cin >> h1;
    std::cout << "Enter denominator: ";
    std::cin >> l1;
    std::cout << "Enter the second drop" << endl;
    std::cout << "Enter the numerator: ";
    std::cin >> h2;
    std::cout << "Enter denominator ";
    std::cin >> l2;

    Rational R1(h1, l1), R2(h2, l2), R3;
    //R3=R1.Add(R2);
    //R1.Print();
    //R2.Print();
    //R3.Print();

    R3 = R1.Sub(R2);
    R3.Print();

    //R3=R2.Sub(R1);
    //R3.Print();

    //R3=R1.And(R2);
    //R3.Print();

    //R3=R1.Div(R2);
    //R3.Print();

    return 0;
};

/*
ostream& operator<<(ostream& s, const Array& Data) {
146: s << endl;
147: for (int i = 0; i < Data.VSize; i++) {
148: for (int j = 0; j < Data.HSize; j++)
149: s << ’\t’ << Data[i][j];
150: s << endl;
151: }
152: s << endl;
153: return s;
154: }
*/