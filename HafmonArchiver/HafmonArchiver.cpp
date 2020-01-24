#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>

using namespace std;

///Узел
class Node {
public:
    int a;
    char c;
    Node *left, *right;

    Node() { left = right = NULL; }

///3) конструктор
    Node(Node *L, Node *R) {//принимает левого и правого сына
        left = L;
        right = R;
        a = L->a + R->a;//сумма - родителя
    }
};

///Сортировка
struct MyCompare {
    bool operator()(const Node *l, const Node *r) const { return l->a < r->a; }
};


vector<bool> code;
map<char, vector<bool> > table;

///4) пробегаемся по дереву и асоциируем символы с двоичными кодами
void BuildTable(Node *root) {
    if (root->left != NULL) {//если слева не ноль
        code.push_back(0);//ставим в вектор 0
        BuildTable(root->left);//запускаем BuildTable для левого сына
    }

    if (root->right != NULL) {
        code.push_back(1);
        BuildTable(root->right);
    }

    if (root->left == NULL && root->right == NULL)
        table[root->c] = code;//если буква существует то асоциируем эту букву с code

    code.pop_back();//возвращаемся назад(выкидываем последний символ)
}


int main(int argc, char *argv[]) {
///Входной файл
    ifstream f("text.txt", ios::out | ios::binary);

    map<char, int> m;

    while (!f.eof()) {//Пока не конец файла
        char c = f.get();//считываем байт(в том числе и пробелы)
        m[c]++;
    }


///1) записываем начальные узлы в список list

    list<Node *> t;//лист указателей на Node(из map загружаю в node)
    for (map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr) {//проходимся по map

        Node *p = new Node;//создаем в динамической памяти новый узел
        p->c = itr->first;//первый элемент
        p->a = itr->second;//второй элемент
        t.push_back(p);
    }


///2) создаем дерево

    while (t.size() != 1) {//пока не останется 1 элемент
        t.sort(MyCompare());//сортирую

        Node *SonL = t.front();//присваиваю первому элементу в списке
        t.pop_front();//удаляю этот первый элемент
        Node *SonR = t.front();
        t.pop_front();

        Node *parent = new Node(SonL, SonR);//создаем родителя
        t.push_back(parent);//кладем в список

    }

    Node *root = t.front();   //root - указатель на вершину дерева

/// 4) Создаем пары символ-код

    BuildTable(root);


    f.clear();//сбрасываем
    f.seekg(0); // перемещаем указатель снова в начало файла

///Выводим коды в файл output.txt
    ofstream g("output.txt", ios::out | ios::binary);

    int count = 0;//счетчик
    char buf = 0;//вспомогательная переменная


///5)Вектор из 0 и 1 записываем в buf. И как только достигли 8 то записываем в файл g
    while (!f.eof()) {
        char c = f.get();
        vector<bool> x = table[c];

        for (int n = 0; n < x.size(); n++) {
            buf = buf | x[n] << (7 - count);
            count++;
            if (count == 8) {
                count = 0;
                g << buf;
                buf = 0;
            }
        }
    }

    f.close();//Закрываем файл
    g.close();//Закрываем файл

///Разархивация
    ifstream F("output.txt", ios::in | ios::binary);//открываем файл для чтения

    setlocale(LC_ALL, "Russian"); // чтоб русские символы отображались в командной строке

    Node *p = root;
    count = 0;
    char byte;
    byte = F.get();//считываю байт из файла F
    while (!F.eof()) {
        bool b = byte & (1 << (7 - count));//проверяю первый символ 0 или 1
        if (b) p = p->right; //если  1 иду вправо
        else p = p->left;//если 0 иду влево
        if (p->left == NULL && p->right == NULL) {//проверяю наткнулись ли на букву(если слева ноль и справа ноль)
            cout << p->c;//если наткнулись то вывести ее
            p = root;//и опять переместиться в корень
        }
        count++;
        if (count == 8) {//если достигли 8 бита считываем новый байт
            count = 0;
            byte = F.get();
        }
    }

    F.close();//Закрываем файл

    return 0;
}