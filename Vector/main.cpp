/*
* @Author: ValenW
* @Date:   2014-12-14 22:16:39
* @Last Modified by:   ValenW
* @Last Modified time: 2014-12-15 03:40:51
*/

#include <iostream>
#include "my_vector.cpp"

using namespace std;

int main() {
    int a[20];
    for (int i = 0; i < 20; i++) a[i] = i;
    my_vector<int> a0(a, 10, 15);
    cout << a0;
    a0.remove(0, 1);
    cout << a0;
    my_vector<int> a1(a0);
    cout << a1;
    my_vector<int> a2(a1, 3);
    cout << a2;
    my_vector<int> a3 = a2;
    cout << a3;
    a3.insert(4);
    cout << a3;
    cout << a3.find(11, 1, 3) << " " << a3.find(4) << endl;
    a3.unsort(1, 4);
    cout << a3;
    a3.insert(11);
    a3.insert(13);
    a3.insert(4);
    cout << a3;
    a3.deduplicate();
    cout << a3;
    a3.sort();
    cout << a3;
    for (int i = 0; i < 100; i++) a3.insert(i);
    a3.unsort();
    cout << a3;
    a3.sort();
    cout << a3;
    return 0;
}
