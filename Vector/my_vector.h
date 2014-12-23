/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-10 06:42:15
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-10 06:42:15
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

typedef int Rank;
#define DEF_SIZE 10

template <typename T>
class my_vector {
protected:
    T* _elem;
    Rank _size, _capt;
    void copyFrom(T const* a, Rank lo, Rank hi);
    void expand();
    void shrink();

    /*short*/
    Rank bubbleR(Rank lo, Rank hi);
    Rank bubbleL(Rank lo, Rank hi);
    void bubbleSort(Rank lo, Rank hi);
    void merge(Rank lo, Rank mi, Rank hi);
    void mergeSort(Rank lo, Rank hi);

    /* search */
    Rank binarySearch(T const& e, Rank lo, Rank hi);

public:
    my_vector(int s = DEF_SIZE, int c = 0, T v = 0) {
        _elem = new T[_size = s];
        for (_capt = 0; _capt < c; _elem[_capt++] = v);
    }
    my_vector(T const* a, int n) { copyFrom(a, 0, n); }
    my_vector(T const* a, Rank lo, Rank hi) { copyFrom(a, lo, hi); }
    my_vector(my_vector<T> const& v, int n = -1) {
        if (n == -1) copyFrom(v._elem, 0, v._capt);
        else copyFrom(v._elem, 0, n);
    }
    my_vector(my_vector<T> const& v, Rank lo, Rank hi) {
        copyFrom(v._elem, lo, hi);
    }
    ~my_vector() { delete[] _elem; }
    my_vector<T>& operator=(my_vector<T> const& other) {
        _elem = new T[_size = other._size];
        _capt = other._capt;
        for (int i = 0; i < other._capt; i++) _elem[i] = other._elem[i];
    }

    int size() const { return _size; }
    int capt() const { return _capt; }
    bool empty() const { return !_capt; }

    T& operator[](Rank r) const { return _elem[r]; }

    T remove(Rank r = -1);
    int remove(Rank lo, Rank hi);
    Rank insert(T const& e, Rank r = -1);

    Rank find(T const& e) const { return find(e, 0, _size); } // find无序查找
    Rank find(T const& e, Rank lo, Rank hi) const;
    Rank search(T const& e) { return search(e, 0, _size); } // search有序查找
    Rank search(T const& e, Rank lo, Rank hi);

    void sort(Rank lo = -1, Rank hi = -1);
    void unsort(Rank lo = -1, Rank hi = -1);

    int deduplicate(); // 无序去重
    int uniquify(); //有序去重

    void traverse(void (*visit) (T&)) {
        for (int i = 0; i < _capt; i++) visit(_elem[i]);
    }
    template <typename VST> // VST为一个函数对象，即重载了()对象
    void traverse(VST& visit) {
        for (int i = 0; i < _capt; i++) visit(_elem[i]);
    }

    int disordered() const; // 逆序对个数

    template <typename sT>
    friend std::ostream& operator<< (std::ostream& out, const my_vector<sT> &a) {
        for (int i = 0; i < a.capt(); i++) out << a[i] << " ";
        out << std::endl;
        out << a.size() << std::endl;
        out << a.capt() << std::endl;
        out << a.empty() << std::endl;
        return out;
    }
};

#endif
