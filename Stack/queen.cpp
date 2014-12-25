/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-25 21:00:55
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-25 21:50:22
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "../List/my_list.cpp"
#include "../Vector/my_vector.cpp"
#include "my_stack.h"

using namespace std;

struct Queen {
    int x, y;
    Queen(int xx, int yy) : x(xx), y(yy) {};
    Queen() : x(0), y(0) {};
    bool operator==(Queen const& q) const {
        return (x == q.x) || (y == q.y)
            || (x+y) == (q.x + q.y) || (x-y) == (q.x - q.y);
    }
    bool operator!=(Queen const& q) const {
        return !(*this == q);
    }
};

int placeQueens(int n) {
    my_stack<Queen> sol;
    Queen q(0, 0);
    int solN = 0;
    do {
        if (q.y >= n || sol.capt() >= n) {
            q = sol.pop();
            q.y++;
        } else {
            while (q.y < n && sol.find(q) >= 0) q.y++;
            if (q.y < n) {
                sol.push(q);
                if (sol.capt() >= n) {
                    solN++;
                    for (int i = 0; i < sol.capt(); i++) {
                        cout << '(' << sol[i].x << ',' << sol[i].y << ')' << endl;
                    }
                    cout << endl;
                }
                q.x++;
                q.y = 0;
            }
        }
    } while (q.x > 0 || q.y < n); //当q.x == 0 && q.y == n时退出循环
    return solN;
}

int main() {
    int n = 0;
    cin >> n;
    cout << placeQueens(n);
}
