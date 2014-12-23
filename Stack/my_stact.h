/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-22 20:47:27
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-22 20:47:27
 */

#ifndef MY_STACT_H
#define MY_STACT_H

#include "../Vector/my_vector.h"

template <typename T>
class my_stack : public my_vector<T> {
public:
    void push(T const& e) {this -> insert(e);}
    T pop() {return this -> remove(this -> capt() - 1);}
    T& top() {return (*this)[this -> size() - 1];}
};
#endif
