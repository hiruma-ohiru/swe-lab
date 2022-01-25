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

double y_func(double x, int n) {
    double y = 0;
    if (x <= 0) {
        for (int i = 2; i <= n - 1; i++) {
            y += x / i;
        }
    }
    else {
        for (int i = 0; i <= n - 1; i++) {
            for (int j = 0; j <= i; j++) {
                y += i / (j + x);
            }
        }
    }
    return y;
}

void calculateInRange(double a, double b, double step, int n) {
    for (double x = a; x <= b; x += step) {
        cout << "x = " << x << "; y = " << y_func(x, n) << endl;
    }
}

void checkRange(double& a, double& b) {
    if (a > b) {
        double tmp = a;
        a = b;
        b = tmp;
    }
}

int main()
{
    try {
        double a, b, step;
        int n;

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
