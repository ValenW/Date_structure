/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-26 20:24:00
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-26 22:21:31
 */

#include <iostream>
#include <fstream>
#include <string>
#include "my_binTree.h"

using namespace std;

template <typename T>
int removeAt(bnp(T) x) {
    if (!x) return 0;
    int n = 1 + removeAt(x -> lc) + removeAt(x -> rc);
    release(x -> data);
    release(x);
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
    formPa(*x) = NULL;
    upHAbove(x -> pa);
    x -> pa  =NULL;
    my_binTree<T>* t = new my_binTree<T>;
    t -> _root = x;
    t -> _size = x -> size();
    _size -= x -> size();
    return t;
}
