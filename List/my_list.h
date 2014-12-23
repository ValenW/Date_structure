/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-16 20:22:24
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-16 20:22:24
 */
#ifndef LIST_H
#define LIST_H

#include <iostream>

typedef int Rank;
#define liNodeP(T) listNode<T>*

template <typename T>
struct listNode {
    T data;
    liNodeP(T) pred;
    liNodeP(T) succ;

    listNode() {}
    listNode(T e, liNodeP(T) p, liNodeP(T) s) : data(e), pred(p), succ(s) {}

    liNodeP(T) insertAsPred (T const& e) {
        liNodeP(T) t = new listNode(e, pred, this);
        pred -> succ = t;
        pred = t;
        return t;
    }
    liNodeP(T) insertAsSucc (T const& e) {
        liNodeP(T) t = new listNode(e, this, succ);
        succ -> pred = t;
        succ = t;
        return t;
    }
};

template <typename T>
class my_list {
private:
    int _size;
    liNodeP(T) head;
    liNodeP(T) tail;

protected:
    void init();
    void copyNodes(liNodeP(T) p, int n);
    int clear();

    void merge(liNodeP(T)& p, int n, my_list<T>& l, liNodeP(T) q, int m);
    void mergeSort(liNodeP(T)& p, int n);
    void selectionSort(liNodeP(T) p, int n);
    void insertionSort(liNodeP(T) p, int n);

public:
    my_list() {init();}
    my_list(my_list<T> const& l) {copyNodes(l.first(), l._size);}
    // my_list(my_list<T> const& l, Rank r, int n) {copyNodes(l[r], n);}
    my_list(liNodeP(T) p, int n) {copyNodes(p, n);}
    ~my_list() {clear(); delete head; delete tail;}

    int size() const {return _size;}
    bool empty() const {return _size <= 0;}
    T& operator[] (Rank r) const;
    liNodeP(T) first() const {return head -> succ;}
    liNodeP(T) last() const {return tail -> pred;}

    bool valid(liNodeP(T) p) const {return p && tail != p && head != p;}
    int disordered() const;

    liNodeP(T) find(T const& e) const {return find(e, _size, tail);}
    liNodeP(T) find(T const& e, int n, liNodeP(T) p) const;
    liNodeP(T) search(T const& e) const {return search(e, _size, tail);}
    liNodeP(T) search(T const& e, int n, liNodeP(T) p) const;
    liNodeP(T) pOfMax() const {return pOfMax(head -> succ, _size);}
    liNodeP(T) pOfMax(liNodeP(T) p, int n) const;

    liNodeP(T) insFirst(T const& e) {
        _size++;
        return head -> insertAsSucc(e);
    }
    liNodeP(T) insLast(T const& e) {
        _size++;
        return tail -> insertAsPred(e);
    }
    liNodeP(T) insBfo(liNodeP(T) p, T const& e) {
        _size++;
        return p -> insertAsPred(e);
    }
    liNodeP(T) insAft(liNodeP(T) p, T const& e) {
        _size++;
        return p -> insertAsSucc(e);
    }

    T remove(liNodeP(T) p);

    void sort(liNodeP(T) p, int n);
    void sort() {sort(first(), _size);}

    int deduplicate();
    int uniquify();
    void reverse();

    void traverse(void(*visit) (T&)) {
        for (liNodeP(T) p = head -> succ; p != tail; p = p -> succ)
            visit(p -> data);
    }
    template <typename V>
    void traverse(V& visit) {
        for (liNodeP(T) p = head -> succ; p != tail; p = p -> succ)
            visit(p -> data);
    }

    template <typename sT>
    friend std::ostream& operator<< (std::ostream& out, const my_list<sT> &l) {
        for (int i = 0; i < l._size; i++) out << l[i] << ' ';
        out << std::endl << l.size() << std::endl;
        return out;
    }
};

#endif
