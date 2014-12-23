/*
* @Author: ValenW
* @Date:   2014-12-14 22:16:39
* @Last Modified by:   ValenW
* @Last Modified time: 2014-12-22 22:03:13
*/

#include <iostream>
#include "List/my_list.cpp"
#include "Vector/my_vector.cpp"
#include "Stack/my_stact.h"

using namespace std;

int main() {
    my_stack<int> a;
    a.push(0);
    cout << a;
    cout << a.top() << endl << endl;
    cout << a.pop();
    cout << a;
    // my_list<int> a;
    // for (int i = 0; i < 20; i++) {
    //     a.insFirst(i);
    // }
    // cout << a;
    // my_list<int> a1(a);
    // cout << a.first() -> data << ' ' << a.last() -> data << endl;
    // cout << a.find(15) -> data << ' '<< a.find(13) -> data << ' ' << a.pOfMax() -> data << endl;
    // a.insFirst(2);
    // a.insLast(88);
    // a.insBfo(a.find(3), 44);
    // a.insAft(a.find(4), 33);
    // cout << a;
    // a.remove(a.find(44));
    // cout << a << "*******************" << endl;
    // for (int i = 0; i < 20; i++) {
    //     a.insFirst(i);
    // }
    // cout << a;
    // a.deduplicate();
    // cout << a;
    // a.sort();
    // cout << a;
    // for (int i = 0; i < 20; i++) {
    //     a.insFirst(i);
    // }
    // cout << a;
    // a.sort();
    // a.uniquify();
    // cout << a;
    // a0.remove(0, 1);
    // cout << a0;
    // my_list<int> a1(a0);
    // cout << a1;
    // my_list<int> a2(a1, 3);
    // cout << a2;
    // my_list<int> a3 = a2;
    // cout << a3;
    // a3.insert(4);
    // cout << a3;
    // cout << a3.find(11, 1, 3) << " " << a3.find(4) << endl;
    // a3.unsort(1, 4);
    // cout << a3;
    // a3.insert(11);
    // a3.insert(13);
    // a3.insert(4);
    // cout << a3;
    // a3.deduplicate();
    // cout << a3;
    // a3.sort();
    // cout << a3;
    // for (int i = 0; i < 100; i++) a3.insert(100-i);
    // cout << a3;
    // a3.unsort();
    // cout << a3;
    // a3.sort();
    // cout << a3;
    return 0;
}
