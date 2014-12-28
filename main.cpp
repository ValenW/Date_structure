/*
* @Author: ValenW
* @Date:   2014-12-14 22:16:39
* @Last Modified by:   ValenW
* @Last Modified time: 2014-12-28 10:49:30
*/

#include <iostream>
#include "List/my_list.cpp"
#include "Vector/my_vector.cpp"
#include "Stack/my_stack.h"
#include "Queue/my_queue.h"
#include "BinTree/my_binTree.cpp"

using namespace std;

template <typename T>
struct add {
    virtual void operator() (T& a) {
        cout << a << ' ';
    }
};

template <typename T>
void inc(my_binTree<T> &b) {
    b.travLevel(add<T>());
}

int main() {
    cout << endl << "***** binTree *****" << endl;
    my_binTree<int> ba;
    ba.insRoot(0);
    ba.insLc(ba.root(), 1);
    ba.insRc(ba.root(), 2);

    my_binTree<int> bb, bc;
    bb.insRoot(10);
    bc.insRoot(20);
    ba.attLc(ba.root(), &bb);
    ba.attRc(ba.root(), &bc);
    cout << ba;
    cout << (*(ba.secede(ba.root() -> lc)));
    // cout << ba;
    // ba.travLevel(add<int>());
    cout << ba;
    ba.insRoot(0);
    cout << ba;

    int i = 0;
    my_queue<bnp(int)> q;
    bnp(int) x = ba.root();
    q.enqueue(x);
    while (!q.empty() && i < 126) {
        x = q.dequeue();
        i++;
        if (!hasLc(*x)) ba.insLc(x, i);
        i++;
        if (!hasRc(*x)) ba.insRc(x, i);
        q.enqueue(x -> lc);
        q.enqueue(x -> rc);
    }
    cout << ba;

    struct add<int> out;
    cout << endl << "***level***" << endl;
    ba.travLevel(out);
    cout << endl << "***pre***" << endl;
    ba.travPre(out);
    cout << endl << "***post***" << endl;
    ba.travPost(out);
    cout << endl << "***in***" << endl;
    ba.travIn(out);
    // cout << endl << "***** Queue *****" << endl;
    // my_queue<int> qa;
    // for (int i = 0; i < 20; i++) qa.enqueue(i);
    // cout << qa;
    // for (int i = 0; i < 10; i++) qa.dequeue();
    // cout << qa;
    // for (int i = 0; i < 5; i++) cout << qa.front() << ' ';

    // cout << endl << "***** Stack *****" << endl;
    // my_stack<int> sa;
    // sa.push(0);
    // cout << sa;
    // cout << sa.top() << endl << endl;
    // cout << sa.pop();
    // cout << sa;

    // cout << endl << "***** List *****" << endl;
    // my_list<int> la;
    // for (int i = 0; i < 20; i++) {
    //     la.insFirst(i);
    // }
    // cout << la;
    // my_list<int> a(la);
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

    // cout << endl << "***** Vactor *****" << endl;
    // int va[20];
    // for (int i = 0; i < 20; i++) va[i] = i;
    // my_vector<int> va0(va, 10, 15);
    // cout << va0;
    // va0.remove(0, 1);
    // cout << va0;
    // my_vector<int> va1(va0);
    // cout << va1;
    // my_vector<int> va2(va1, 3);
    // cout << va2;
    // my_vector<int> va3 = va2;
    // cout << va3;
    // va3.insert(4);
    // cout << va3;
    // cout << va3.find(11, 1, 3) << " " << va3.find(4) << endl;
    // va3.unsort(1, 4);
    // cout << va3;
    // va3.insert(11);
    // va3.insert(13);
    // va3.insert(4);
    // cout << va3;
    // va3.deduplicate();
    // cout << va3;
    // va3.sort();
    // cout << va3;
    // for (int i = 0; i < 100; i++) va3.insert(i);
    // va3.unsort();
    // cout << va3;
    // va3.sort();
    // cout << va3;
    return 0;
}
