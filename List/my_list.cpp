/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-16 20:22:18
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-22 20:39:08
 */

#include <iostream>
#include <string>
#include "my_list.h"

using namespace std;

template <typename T>
void my_list<T>::init() {
    head = new listNode<T>;
    tail = new listNode<T>;
    head -> pred = NULL;
    head -> succ = tail;
    tail -> succ = NULL;
    tail -> pred = head;
    _size = 0;
}

template <typename T>
void my_list<T>::copyNodes(liNodeP(T) p, int n) {
    init();
    while(n--) {
        insLast(p -> data);
        p = p -> succ;
    }
}

template <typename T>
int my_list<T>::clear() {
    int re = _size;
    while (_size > 0) remove(head -> succ);
    return re;
}

template <typename T>
T& my_list<T>::operator[] (Rank r) const {
    liNodeP(T) p = first();
    while (r--) p = p -> succ;
    return p -> data;
}

template <typename T>
liNodeP(T) my_list<T>::find(T const& e, int n, liNodeP(T) p) const {
    while (n--) if ((p = p -> pred) -> data == e) return p;
    return NULL;
}

template <typename T>
T my_list<T>::remove(liNodeP(T) p) {
    T re = p -> data;
    p -> succ -> pred = p -> pred;
    p -> pred -> succ = p -> succ;
    delete p;
    _size--;
    return re;
}

template <typename T>
int my_list<T>::deduplicate() {
    if (_size < 2) return 0;
    int oldSize = _size;
    liNodeP(T) p = head;
    Rank r = 0;

    while(tail != (p = p -> succ)) {
        liNodeP(T) q = find(p -> data, r, p);
        q ? remove(q) : r++;
    }
    return oldSize - _size;
}

template <typename T>
int my_list<T>::uniquify() {
    if (_size < 2) return 0;
    int oldSize = _size;
    liNodeP(T) p = head -> succ;
    liNodeP(T) q;
    while((q = p -> succ) != tail)
        if (p -> data != q -> data) p = q;
        else remove(q);
    return oldSize - _size;
}

template <typename T>
liNodeP(T) my_list<T>::search(T const& e, int n, liNodeP(T) p) const {
    while (n--) if (((p = p -> pred) -> data) <= e) break;
    return p;
}

template<typename T>
void my_list<T>::insertionSort(liNodeP(T) p, int n) {
    for (int i = 0; i < n; i++) {
        insAft(search(p -> data, i, p), p -> data);
        p = p -> succ;
        remove(p -> pred);
    }
}

template<typename T>
void my_list<T>::selectionSort(liNodeP(T) p, int n) {
    liNodeP(T) h = p -> pred;
    liNodeP(T) t = p;
    for (int i = 0; i < n; i++) t = t -> succ;
    while (n > 1) {
        liNodeP(T) max = pOfMax(h -> succ, n);
        insBfo(t, remove(max));
        t = t -> pred;
        n--;
    }
}

template<typename T>
liNodeP(T) my_list<T>::pOfMax(liNodeP(T) p, int n) const {
    liNodeP(T) max = p;
    for (liNodeP(T) cur = p; n > 1; n--)
        if (((cur = cur -> succ) -> data) >= (max -> data)) max = cur;
    return max;
}

template <typename T>
void my_list<T>::mergeSort(liNodeP(T)& p, int n) {
    if (n < 2) return;
    int m = n >> 1;
    liNodeP(T) q = p;
    for (int i = 0; i < m; i++) q = q -> succ;
    mergeSort(p, m);
    mergeSort(q, n - m);
    merge(p, m, *this, q, n - m);
}

template<typename T>
void my_list<T>::merge(liNodeP(T)& p, int n, my_list<T>& l, liNodeP(T) q, int m) {
    liNodeP(T) pp = p -> pred;
    while(m > 0)
        if ((n > 0) && (p -> data <= q -> data)) {
            if (q == (p -> succ)) break;
            n--;
        } else {
            insBfo(p, l.remove((q = q -> succ) -> pred));
            m--;
        }
    p = pp -> succ;
}

template<typename T>
void my_list<T>::sort(liNodeP(T) p, int n) {
    insertionSort(p, n);
}