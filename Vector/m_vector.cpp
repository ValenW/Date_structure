/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-10 06:42:15
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-12 21:05:58
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "m_vector.h"

using namespace std;

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void my_vector::copyFrom(T* a, Rank lo, Rank hi) {
    _elem = new T[_size = (hi - lo)*2];
    _capt = 0;
    for (int i = lo; i < hi; i++) _elem[_capt++] = a[i];
}

template <typename T>
void my_vector::expand() {
    if (_capt < _size) return;
    T* oldElem = _elem;
    _elem = new T[_size <<= 1];
    for (int i = 0; i < _capt; i++) _elem[i] = oldElem[i];
    delete[] oldElem;
}

template <typename T>
void my_vector::shrink() {
    if (_capt > _size >> 2 || _size >> 1 < DEF_SIZE) return;
    oldElem = _elem;
    _elem = new T[_size >>= 1];
    for (int i = 0; i < _capt; i++) _elem = oldElem;
    delete[] oldElem;
}

template <typename T>
void my_vector::unsort(Rank lo, Rank hi) {
    if (hi <= lo) {
        return;
    } else if (lo == -1) {
        lo = 0;
        if (hi == -1) {
            hi = _capt;
        } else {
            return;
        }
    } else if (hi == -1) {
        hi = _capt;
    }
    T* v = _elem + lo;
    for (int i = hi - lo, i > 0; i--) swap(v[i-1], v[rand() % i]);
}

template <typename T>
Rank my_vector::find(T const& e, Rank lo, Rank hi) {
    while ((lo < hi--) && (e != _elem[hi]));
    return hi;
}

template <typename T>
Rank my_vector::insert(T const& e, Rank r) {
    if (r == -1) r = _capt;
    if (r > _capt || r < -1) return;
    expand();
    for (int i = _capt; i > r; i--) _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _capt++;
    return r;
}

template <typename T>
int my_vector::remove(Rank lo, Rank hi) {
    if (lo >= hi) return;
    T* v = _elem + lo, vv = _elem + hi;
    for (int i = 0; i < _capt - hi; i++) v[i] = vv[i];
    _capt -= (hi - lo);
    shrink();
    return hi - lo;
}

template <typename T>
T my_vector::remove(Rank r) {
    if (r == -1) r = _capt - 1;
    T re = _elem[r];
    remove(r, r+1);
    return re;
}

template <typename T>
void my_vector::sort(Rank lo, Rank hi) {

}

template <typename T>
int my_vector::deduplicate() {
    int oldCapt = _capt;
    Rank i = 1;
    while (i < _capt) find(_elem[i], 0, i) < 0 ? i++ : remove(i);
    return oldCapt - _capt;
}

template <typename T>
int my_vector::uniquify() {
    int i = 0, j = 0;
    while (++j < _capt)
        if (_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
    _capt = ++i;
    shrink();
    return j - i;
}

template <typename T>
int my_vector::disordered() {
    int n = 0;
    for (int i = 0; i < _capt - 1; i++)
        if (_elem[i] > _elem[i+1])
            n++;
    return n;
}

template <typename T>
void my_vector::bubbleSort(Rank lo, Rank hi) {
    bool sorted = false;
    for (int i = 0; !sorted && i < _capt; i++) {
        for (int j = i; j < _capt; j++) {
            if (_elem[i] > _elem[j]) {
                swap(_elem[i], _elem[j]);
            }
        }
    }
}

template <typename T>
Rank my_vector::binarySearch(T const& e, Rank lo, Rank hi) {
    while (hi > lo) {
        Rank mi = (hi + lo) >> 1;
        e < _elem[hi] ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

template <typename T>
void my_vector::