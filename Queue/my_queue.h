/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-26 15:47:33
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-26 15:47:33
 */

#include <iostream>
#include <string>
#include "../List/my_list.h"

template <typename T>
class my_queue : public my_list<T> {
public:
    void enqueue(T const& e) {insLast(e);}
    T dequeue() {return remove(first());}
    T& front() {return first() -> data;}
};
