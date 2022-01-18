#include <iostream>
#include <math.h>
using namespace std;

int y_func(int x, int n) {
    double y = 0;
    if (x <= 0) {
        for (int i = 2; i <= n - 1; i++) {
            //cout << (double) x / i << " = " << x << " / " << i << endl;
            y += x / i;
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

int main()
{
    int a, b, n, step;

    cout << "Input a = ";
    cin >> a;

    cout << "Input b = ";
    cin >> b;

    cout << "Input n = ";
    cin >> n;

    cout << "Input step = ";
    cin >> step;

    for (int x = a; x <= b; x += step) {
        cout << "x = " << x << "; y = " << y_func(x, n) << endl;
    }

    return 0;
}