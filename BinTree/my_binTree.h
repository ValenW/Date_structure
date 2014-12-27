/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-26 20:24:59
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-26 20:24:59
 */

#ifndef MY_BINTREE_H
#define MY_BINTREE_H

#include "binNode.h"
#include "../Stack/my_stack.h"
#include "../Queue/my_queue.h"

template <typename T>
class my_binTree {
protected:
    int _size;
    bnp(T) _root;
    virtual int upHeight(bnp(T) x) {
        return x -> height = 1 + max(stature(x -> lc), stature(x -> rc));
    }
    void upHAbove(bnp(T) x) {
        while (x) {upHeight(x); x = x -> pa;}
    }
public:
    my_binTree() : _size(0), _root(NULL) {}
    ~my_binTree() {if (_size > 0) remove(_root);}
    int size() const {return _size;}
    bool empty() const {return !_size;}

    bnp(T) root() const {return _root;}
    // insert 作为单个元素加入
    bnp(T) insRoot(T const& e) {
        _size = 1;
        return _root = new binNode(e);
    }
    bnp(T) insLc(bnp(T) x, T const& e) {
        _size++;
        x -> insLc(e);
        upHAbove(x);
        return x -> lc;
    }
    bnp(T) insRc(bnp(T) x, T const& e) {
        _size++;
        x -> insRc(e);
        upHAbove(x);
        return x -> rc;
    }
    // attach 作为子树加入
    bnp(T) attLc(bnp(T) x, my_binTree<T>* &t) {
        if (x -> lc = t -> _root) x -> lc -> pa = x;
        _size += t -> _size;
        upHAbove(x);
        t -> _root = NULL;
        t -> _size = 0;
        release(t);
        t = NULL;
        return x;
    }
    bnp(T) attRc(bnp(T) x, T const& e) {
        if (x -> rc = t -> _root) x -> rc -> pa = x;
        _size += t -> _size;
        upHAbove(x);
        t -> _root = NULL;
        t -> _size = 0;
        release(t);
        t = NULL;
        return x;
    }

    int remove(bnp(T) x);
    my_binTree<T>* secede(bnp(T) x); //摘除x并作为独立树返回

    template <typename sT>
    void travLevel(sT& visit) {if (_root) _root -> travLevel(visit);}
    template <typename sT>
    void travPre(sT& visit) {if (_root) _root -> travPre(visit);}
    template <typename sT>
    void travIn(sT& visit) {if (_root) _root -> travIn(visit);}
    template <typename sT>
    void travPost(sT& visit) {if (_root) _root -> travPost(visit);}
    
    operator== (my_binTree<T> const& t) {
        return _root && t._root && (_root == t._root;)
    }
};

#endif
