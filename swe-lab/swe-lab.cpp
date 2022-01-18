#include <iostream>
#include <math.h>
using namespace std;

void checkValidInput() {
    if (cin.fail()) {
        throw "Incorrect input!";
    }
}

void checkValidParams(int n) {
    if (n < 3) {
        throw "Incorrect input data!";
    }
}

double y_func(int x, int n) {
    double y = 0;
    if (x <= 0) {
        for (int i = 2; i <= n - 1; i++) {
            cout << (double)x / i << " = " << x << " / " << i << endl;
            y += (double)x / i;
        }
    }
    else {
        for (int i = 0; i <= n - 1; i++) {
            for (int j = 0; j <= i; j++) {
                //cout << (double) i / (j + x) << " = " << i << "/ (" << j << "+" << x << ")" << endl;
                y += (double)i / (j + x);
            }
        }
    }
    return y;
}

void calculateInRange(int a, int b, int step, int n) {
    for (int x = a; x <= b; x += step) {
        cout << "x = " << x << "; y = " << y_func(x, n) << endl;
    }
}

void checkRange(int& a, int& b) {
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
}

int main()
{
    try {

        int a, b, n, step;

        cout << "Input a = ";
        cin >> a;
        checkValidInput();

        cout << "Input b = ";
        cin >> b;
        checkValidInput();
        checkRange(a, b);

        cout << "Input n (>= 3); n = ";
        cin >> n;
        checkValidParams(n);

        cout << "Input step = ";
        cin >> step;
        checkValidInput();

        calculateInRange(a, b, step, n);

    }
    catch (const char* ex) {
        cout << ex << endl;
        return -1;
    }

    catch (...) {
        cout << "Unknown error" << endl;
        return -2;
    }
    return 0;
}