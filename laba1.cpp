#include <iostream>
#include <cstring>
using namespace std;

void bin(int x, int width = 32) { //функция для перевода инта
        unsigned u = static_cast<unsigned>(x);
        for (int i = width - 1; i>=0; --i) {
            if (i==width - 1) cout << "[1]";
            putchar((u >> i) & 1 ? '1' : '0');
            if ((width - 1 -i)%8 == 7) cout << ' ';
        }
        cout << endl;
    }

void flt(float x) { // функция для перевода флоат
    unsigned int n;
    memcpy(&n, &x, sizeof(float));
    int order_f = sizeof(float)*8;
    unsigned int mask_f = 1 <<(order_f - 1);
    for (int i = 0; i < order_f; i++) {
        cout << ((n & (mask_f >> i)) ? '1' : '0');
        if (i==0 ||i==8) cout << " ";

    }
    cout << endl;

}

void dbl(double d) {
    unsigned long long l;
    memcpy(&l, &d, sizeof(double));

    int order_d = sizeof(double)*8;
    unsigned long long mask_d = 1ULL << (order_d -1);

    for (int i = 0; i < order_d; i++) {
        cout << ((l & (mask_d >> i)) ? '1': '0');
        if (i==0 || i==11) cout << " ";

    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Задание 1: " << endl;
    cout << "bool: " << sizeof(bool) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "short int: " << sizeof(short int) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "long int: " << sizeof(long int) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "long double: " << sizeof(long double) << endl;

    cout << "Задание 2: " << endl;
    int c;
    cin >> c;
    bin(c);

    cout << "Задание 3: " << endl;
    float a;
    cin >> a;
    flt(a);
    // unsigned int n;
    // memcpy(&n, &a, sizeof(float));
    
    // int order_f = sizeof(float)*8;
    // unsigned int mask_f = 1 <<(order_f - 1);

    // for (int i = 0; i < order_f; i++) {
    //     cout << ((n & (mask_f >> i)) ? '1' : '0');
    //     if (i==0 || i==8) cout << " ";

    // }
    // cout << endl;

    cout << "Задание 4: " << endl;
    double d;
    cin >> d;
    unsigned long long l;
    memcpy(&l, &d, sizeof(double));
    
    int order_d = sizeof(double)*8;
    unsigned long long mask_d = 1ULL <<(order_d - 1);

    for (int i = 0; i < order_d; i++) {
        cout << ((l & (mask_d >> i)) ? '1' : '0');
        if (i==0 || i==11) cout << " ";

    }
    cout << endl;

    cout << "Задание 5: " << endl;
    cout << "int: " << endl;
    int k;
    cout << "До: ";
    cin >> k;
    bin(k);
    int k1;
    k1 = k^=1 << 3;
    cout << "Поменяем 3 бит в числе и получим: ";
    bin(k1);
    cout << k1 << endl;


    cout << "float: " << endl;
    float f;
    cout << "До: ";
    cin >> f;
    unsigned int mbit;
    flt(f);
    float f1;
    memcpy(&mbit, &f, sizeof(float));
    mbit ^= (1 << 3);
    memcpy(&f1, &mbit, sizeof(float));
    cout << "Поменяем 3 бит в числе и получим: ";
    flt(f1);
    cout << f1 << endl;
    
    cout << "double: " << endl;
    double j;
    unsigned  int db;
    double d1;
    cin >> j;
    cout << "До: " << j;
    dbl(j);
    memcpy(&db, &j, sizeof(double));
    db ^= (1<<3);
    memcpy(&d1, &db, sizeof(double));
    cout << "меняем 3 бит: " << endl;
    dbl(d1);
    cout << d1 << endl;


    cout << "Задание 6. Умножение на 2." << endl;
    int j6;
    cout << "До умножения: ";
    cin >> j6;
    unsigned result = j6 << 1;
    cout << "После умножения: ";
    cout << result << endl;

    return 0;

}

