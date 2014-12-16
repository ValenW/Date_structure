/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-10 06:42:15
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-15 03:41:52
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "my_vector.h"

typedef int Rank;

using namespace std;

int randBy(int i) {
    srand(time(0));
    return rand() % i;
}

template <typename T>
void toSwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void my_vector<T>::copyFrom(T const* a, Rank lo, Rank hi) {
    _elem = new T[_size = (hi - lo)*2];
    _capt = 0;
    for (int i = lo; i < hi; i++) _elem[_capt++] = a[i];
}

template <typename T>
void my_vector<T>::expand() {
    if (_capt < _size) return;
    T* oldElem = _elem;
    _elem = new T[_size <<= 1];
    for (int i = 0; i < _capt; i++) _elem[i] = oldElem[i];
    delete[] oldElem;
}

template <typename T>
void my_vector<T>::shrink() {
    if (_capt > _size >> 2 || _size >> 1 < DEF_SIZE) return;
    T* oldElem = _elem;
    _elem = new T[_size >>= 1];
    for (int i = 0; i < _capt; i++) _elem = oldElem;
    delete[] oldElem;
}

template <typename T>
void my_vector<T>::unsort(Rank lo, Rank hi) {
    if (lo == -1) {
        lo = 0;
        if (hi == -1) {
            hi = _capt;
        } else {
            return;
        }
    } else if (hi == -1) {
        hi = _capt;
    } else if(hi <= lo) {
        return;
    }
    T* v = _elem + lo;
    for (int i = hi - lo; i > 0; i--) toSwap(v[i-1], v[randBy(i)]);
}

template <typename T>
Rank my_vector<T>::find(T const& e, Rank lo, Rank hi) const {
    while ((lo < hi--) && (e != _elem[hi]));
    return hi;
}

template <typename T>
Rank my_vector<T>::insert(T const& e, Rank r) {
    if (r == -1) r = _capt;
    if (r > _capt || r < -1) return -1;
    expand();
    for (int i = _capt; i > r; i--) _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _capt++;
    return r;
}

template <typename T>
int my_vector<T>::remove(Rank lo, Rank hi) {
    if (lo >= hi || hi > _capt) return -1;
    T *v = _elem + lo, *vv = _elem + hi;
    for (int i = 0; i < _capt - hi; i++) v[i] = vv[i];
    _capt -= (hi - lo);
    shrink();
    return hi - lo;
}

template <typename T>
T my_vector<T>::remove(Rank r) {
    if (r == -1) r = _capt - 1;
    T re = _elem[r];
    remove(r, r+1);
    return re;
}

template <typename T>
void my_vector<T>::sort(Rank lo, Rank hi) {
    if (lo == -1) lo = 0;
    if (hi == -1) hi = _capt;
    mergeSort(lo, hi);
}

template <typename T>
int my_vector<T>::deduplicate() {
    int oldCapt = _capt;
    Rank i = 1;
    while (i < _capt) find(_elem[i], 0, i) < 0 ? i++ : remove(i);
    return oldCapt - _capt;
}

template <typename T>
int my_vector<T>::uniquify() {
    int i = 0, j = 0;
    while (++j < _capt)
        if (_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
    _capt = ++i;
    shrink();
    return j - i;
}

template <typename T>
int my_vector<T>::disordered() const {
    int n = 0;
    for (int i = 0; i < _capt - 1; i++)
        if (_elem[i] > _elem[i+1])
            n++;
    return n;
}

template <typename T>
Rank my_vector<T>::bubbleR(Rank lo, Rank hi) {
    int last = lo;
    while (++lo < hi)
        if (_elem[lo - 1] > _elem[lo]) {
            toSwap(_elem[lo - 1], _elem[lo]);
            last = lo;
        }
    return last;
}

template <typename T>
Rank my_vector<T>::bubbleL(Rank lo, Rank hi) {
    int first = hi - 1;
    while (lo < --hi)
        if (_elem[hi - 1] > _elem[hi]) {
            toSwap(_elem[hi - 1], _elem[hi]);
            first = hi;
        }
    return first;
}

template <typename T>
void my_vector<T>::bubbleSort(Rank lo, Rank hi) {
    while (lo < (hi = bubbleR(lo, hi)));
}//(lo = bubbleL(lo, hi))

template <typename T>
Rank my_vector<T>::binarySearch(T const& e, Rank lo, Rank hi) {
    while (hi > lo) {
        Rank mi = (hi + lo) >> 1;
        e < _elem[hi] ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

template <typename T>
void my_vector<T>::merge(Rank lo, Rank mi, Rank hi) {
    T* a = _elem + lo;
    int lb = mi - lo;
    T* b = new T[lb];
    for (int i = 0; i < lb; b[i] = a[i++]);
    int lc = hi - mi;
    T* c = a + lb;
    for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc); ) {
        if ((j < lb) && (!(k < lc) || (b[j] <= c[k]))) a[i++] = b[j++];
        if ((k < lc) && (!(j < lb) || (c[k] < b[j]))) a[i++] = c[k++];
    }
    delete[] b;
}

template <typename T>
void my_vector<T>::mergeSort(Rank lo, Rank hi) {
    if (hi - lo < 2) return;
    int mi = (hi + lo) >> 1;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
}
