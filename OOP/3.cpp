#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

///Задание 3: Написать программу, выводящую на экран все варианты перестановок N элементов, где N вводится с клавиатуры.
int main() {
    string s;
    cout << "s = ";
    cin >> s;
    sort(s.begin(), s.end());
    do {
        cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));
}