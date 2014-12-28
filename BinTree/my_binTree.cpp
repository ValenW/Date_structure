/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-26 20:24:00
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-28 16:13:34
 */

#include <iostream>
#include <fstream>
#include <string>
#include "my_binTree.h"

using namespace std;

template <typename T>
bnp(T) binNode<T>::succ() {
    bnp(T) bn = this;
    if (hasRc(*bn)) {
        bn = bn ->rc;
        while (hasLc(*bn)) bn = bn -> lc;
    } else {
        while (isRc(*bn)) bn = bn -> pa;
        bn = bn -> pa;
    }
    return bn;
}

template <typename T> template <typename sT>
void binNode<T>::travLevel(sT& visit) {
    my_queue<bnp(T)> q;
    q.enqueue(this);
    while (!q.empty()) {
        bnp(T) x = q.dequeue();
        visit(x -> data);
        if (hasLc(*x)) q.enqueue(x -> lc);
        if (hasRc(*x)) q.enqueue(x -> rc);
    }
}

template <typename T> template <typename sT>
void binNode<T>::travPre(sT& visit) {
    travPreI1(this, visit);
}

template <typename T> template <typename sT>
void binNode<T>::travIn(sT& visit) {
    travInI2(this, visit);
}

template <typename T> template <typename sT>
void binNode<T>::travPost(sT& visit) {
    travPostI(this, visit);
}

template <typename T>
int removeAt(bnp(T) x) {
    if (!x) return 0;
    int n = 1 + removeAt(x -> lc) + removeAt(x -> rc);
    delete x;
    return n;
}

template <typename T>
int my_binTree<T>::remove(bnp(T) x) {
    fromPa(*x) = NULL;
    upHAbove(x -> pa);
    int n = removeAt(x);
    _size -= n;
    return n;
}

template <typename T>
my_binTree<T>* my_binTree<T>::secede(bnp(T) x) {
    fromPa(*x) = NULL;
    upHAbove(x -> pa);
    x -> pa  =NULL;
    my_binTree<T>* t = new my_binTree<T>;
    t -> _root = x;
    t -> _size = x -> size();
    _size -= x -> size();
    return t;
}

template <typename T, typename sT>
void travPreR(bnp(T) x, sT& visit) {
    if (!x) return;
    visit(x -> data);
    travPreR(x -> lc, visit);
    travPreR(x -> rc, visit);
}

template <typename T, typename sT>
void travInR(bnp(T) x, sT& visit) {
    if (!x) return;
    travInR(x -> lc, visit);
    visit(x -> data);
    travInR(x -> rc, visit);
}

template <typename T, typename sT>
void travPostR(bnp(T) x, sT& visit) {
    if (!x) return;
    travPostR(x -> lc, visit);
    travPostR(x -> rc, visit);
    visit(x -> data);
}

template <typename T, typename sT>
void travLBr(bnp(T) x, sT& visit, my_stack<bnp(T)>& s) {
    while (x) {
        visit(x -> data);
        s.push(x -> rc);
        x = x -> lc;
    }
}

template <typename T, typename sT>
void travPreI1(bnp(T) x, sT& visit) {
    my_stack<bnp(T)> s;
    while (true) {
        travLBr(x, visit, s);
        if (s.empty()) return;
        x = s.pop();
    }
}

template <typename T>
void goLBr(bnp(T) x, my_stack<bnp(T)> s) {
    while (x) {
        s.push(x);
        x = x -> lc;
    }
}

template <typename T, typename sT>
void travInI1(bnp(T) x, sT& visit) {
    my_stack<bnp(T)> s;
    while (true) {
        goLBr(x, s);
        if (s.empty()) return;
        x = s.pop();
        visit(x -> data);
        x = x -> rc;
    }
}

template <typename T, typename sT>
void travInI2(bnp(T) x, sT& visit) {
    my_stack<bnp(T)> s;
    while (true) {
        if (x) {
            s.push(x);
            x = x -> lc;
        } else if (!s.empty()) {
            x = s.pop();
            visit(x -> data);
            x = x -> rc;
        } else break;
    }
}

template <typename T, typename sT>
void travInI3(bnp(T) x, sT& visit) {
    bool back = false;
    while (true) {
        if (!back && hasLc(*x)) x = x -> lc;
        else if (hasRc(*x)) {
                visit(x -> data);
                x = x -> rc;
                back = false;
            } else {
                visit(x -> data);
                if (!(x = x -> succ())) break;
                back = true;
            }
    }
}

template <typename T, typename sT>
void travInI4(bnp(T) x, sT& visit) {
    while (true) {
        if (hasLc(*x)) x = x -> lc;
        else {
            visit(x -> data);
            while (!hasRc(*x))
                if (!(x = x -> succ())) return;
                else visit(x -> data);
            x = x -> rc;
        }
    }
}

template <typename T>
void goLHL(my_stack<bnp(T)>& s) {
    while(bnp(T) x = s.top()) {
        if (hasLc(*x)) {
            if (hasRc(*x)) s.push(x -> rc);
            s.push(x -> lc);
        } else s.push(x -> rc);
    }
    s.pop();
}

template <typename T, typename sT>
void travPostI(bnp(T) x, sT& visit) {
    my_stack<bnp(T)> s;
    if (x) s.push(x);
    while (!s.empty()) {
        if (s.top() != x -> pa) goLHL(s);
        x = s.pop();
        visit(x -> data);
    }
}
