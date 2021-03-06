/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-26 21:29:01
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-26 21:29:01
 */

#ifndef BINNODE_H
#define BINNODE_H

#include <iostream>

#define isRoot(x) (! ((x).pa))
#define isLc(x) (!isRoot(x) && (&(x) == (x).pa -> lc))
#define isRc(x) (!isRoot(x) && (&(x) == (x).pa -> rc))
#define hasLc(x) ((x).lc)
#define hasRc(x) ((x).rc)
#define hasPa(x) ((x).pa)
#define hasC(x) (hasLc(x) || hasRc(x))
#define hasBC(x) (hasLc(x) && hasRc(x))
#define isLeaf(x) (!hasC(x))

#define sibling(p) (isLc(*(p)) ? (p) -> pa -> rc : (p) -> pa -> lc)
#define uncle(p) (isLc(*((x) -> pa)) ? (x) -> pa -> pa -> rc : (x) -> pa -> pa -> lc)
#define fromPa(x) (isRoot(x) ? _root : (isLc(x) ? (x).pa -> lc : (x).pa -> rc))

#define bnp(T) binNode<T>*
#define stature(p) ((p) ? (p) -> height : -1)

typedef enum {red, black} rbCol;

template <typename T>
struct binNode {
    T data;
    bnp(T) pa;
    bnp(T) lc;
    bnp(T) rc;
    int height;
    int npl;
    rbCol color;

    binNode() : pa(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(red) {}
    binNode(T e, bnp(T) p = NULL, bnp(T) lc = NULL, bnp(T) rc = NULL, int h = 0, int l = 1,
        rbCol c = red) : data(e), pa(p), lc(lc), rc(rc), height(h), npl(l), color(c){}
    int size() {
        int i = 1;
        if (rc) i += rc -> size();
        if (lc) i += lc -> size();
        return i;
    }
    
    bnp(T) insLc(T const& e) {
        return lc = new binNode(e, this);
    }
    bnp(T) insRc(T const& e) {
        return rc = new binNode(e, this);
    }
    bnp(T) succ();

    template <typename sT> void travLevel(sT& visit);
    template <typename sT> void travPre(sT& visit);
    template <typename sT> void travIn(sT& visit);
    template <typename sT> void travPost(sT& visit);

    bool operator== (binNode const& b) {return data == b.data;}
    bool operator!= (binNode const& b) {return data != b.data;}
    bool operator<= (binNode const& b) {return data <= b.data;}
    bool operator>= (binNode const& b) {return data >= b.data;}
    bool operator< (binNode const& b) {return data < b.data;}
    bool operator> (binNode const& b) {return data > b.data;}
};

#endif
