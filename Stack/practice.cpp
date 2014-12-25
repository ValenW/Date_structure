/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-22 22:04:26
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-25 21:00:19
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "../List/my_list.cpp"
#include "../Vector/my_vector.cpp"
#include "my_stack.h"

using namespace std;

/* 进制转换
 * 最高支持十六进制
 * 结果保存在栈s中
 */
void convert(my_stack<char>& s, int n, int base) {
    static char digit[] =
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0) {
        int r = (int) (n % base);
        s.push(digit[r]);
        n /= base;
    }
}

/* 括号匹配
 *
 */
bool paren(const char exp[], int lo, int hi) {
    my_stack<char> s;
    for (int i = lo; i < hi; i++) {
        switch(exp[i]) {
            case '(': case '[': case '{':
                s.push(exp[i]);
                break;
            case ')':
                if (s.empty() || s.pop() != '(') return false;
                break;
            case ']':
                if (s.empty() || s.pop() != '[') return false;
                break;
            case '}':
                if (s.empty() || s.pop() != '{') return false;
                break;
            default: break;
        }
    }
    return false;
}
