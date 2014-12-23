/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-16 19:47:19
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-16 20:10:22
 */

#include <iostream>

using namespace std;

int gcdShortest(int a, int b) {
    while(a^=b^=a^=b%=a);
    return b;
}

int gcd(int a, int b) {
    int t;
    if (a < b) {
        t = a;
        a = b;
        b = t;
    }
    while (a % b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return b;
}

int gcdCN(int a, int b) {
    int r = 0;
    while(!((a&1) || (b&1))) {
        a >>= 1;
        b >>= 1;
        r++;
    }
    while (1) {
        while (!(a&1)) a >>= 1;
        while (!(b&1)) b >>= 1;
        a < b ? b = b - a : a = a - b;
        if (a == 0) return b << r;
        if (b == 0) return a << r;
    }
}

int main() {
    int a = 0, b = 0;
    while (1) {
        cin >> a >> b;
        cout << gcd(a, b);
    }
}