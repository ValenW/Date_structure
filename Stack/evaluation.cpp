/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-25 20:57:31
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-25 21:00:11
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include "../List/my_list.cpp"
#include "../Vector/my_vector.cpp"
#include "my_stack.h"

using namespace std;

/* 中值表达式转化为逆波兰表达式并求值
 * 分多段函数
 */

/* 优先级判断函数
 * a 为栈顶元素，b为当前元素
 * 如果b优先级大于a，则返回0，b入栈
 * 否则返回1，弹出a计算
 * 若为括号相遇，则返回特殊的-1标志。
 */
int ord(char c) {
    if (c == '+' || c == '-') return 0;
    if (c == '*' || c == '/') return 1;
    if (c == '^') return 2;
    if (c == '!') return 4;
    return -1;
}

int calNow(char a, char b) {
    if (b == '(') return 0;
    if (b == ')') return a == '(' ? -1 : 1;
    if (b == '\0') return a == '\0' ? -1 : 1;
    return ord(a) >= ord(b) ? 1 : 0;
}

/* 读数函数 */
char* readNum(char*& s) {
    static char a[100];
    int i;
    for (i = 0; isdigit(*s) || (*s) == '.'; i++) {
        a[i] = *s;
        s = s + 1;
    }
    a[i] = '\0';
    return a;
}

/* 从字符串转化为小数函数 */
double strToLf(char* s) {
    double re = 0.0;
    bool d = s[0] == '-';
    int i = d ? 1 : 0;

    while (s[i] != '\0' && s[i] != '.') {
        re = re * 10 + int(s[i] - '0');
        i++;
    }
    if (s[i] == '\0') return d ? -re : re;

    double e = 0.1;
    while (s[++i] != '\0') {
        re = re + int(s[i] - '0') * e;
        e *= 0.1;
    }
    return d ? -re : re;
}

/* 字符串尾追加函数 */
void append(char*& s, double d) {
    int l = strlen(s);
    char buf[64];
    if (d != (double)(int)d) sprintf(buf, "%.2lf \0", d);
    else sprintf(buf, "%d \0", (int)d);
    s = (char*)realloc(s, sizeof(char) * (l + strlen(buf) + 1));
    strcat(s, buf);
}

void append(char*& s, char o) {
    int l = strlen(s);
    s = (char*)realloc(s, sizeof(char) * (l + 3));
    sprintf(s + l, "%c ", o);
    s[l+2] = '\0';
}

/* 计算函数
 * 附带快速幂函数
 */
int power(int a, int n) {
    int re = 1, p = a;
    while (n >0) {
        if (n & 1) re *= p;
        n >>= 1;
        p *= a;
    }
    return re;
}

int fac(int n) {
    for (int i = n - 1; i > 1; i--) n *= i;
    return n;
}

double cals(double o1, char o, double o2) {
    switch (o) {
        case '+': return o1 + o2;
        case '-': return o1 - o2;
        case '*': return o1 * o2;
        case '/': return o1 / o2;
        case '^': return (double)power((int)o1, (int)o2);
        default: return 0.0;
    }
}

double cals(char o, double o2) {
    switch (o) {
        case '!': return (double)fac((int)o2);
        default: return 0.0;
    }
}

/* 返回计算结果
 * 并将转化成的逆波兰表达式
 * 存入一个字符串 rpn中
 *
 * #include <ctype.h>
 */
double calAndTran(char* s, char*& rpn) {
    my_stack<char> ops;
    my_stack<double> nus;
    ops.push('\0');
    while (!ops.empty()) {
        if (isdigit(*s)) {
            double a = strToLf(readNum(s));
            nus.push(a);
            append(rpn, a);
        } else switch (calNow(ops.top(), *s)) {
            case 0:
                ops.push(*s);
                s++;
                break;
            case -1:
                ops.pop();
                s++;
                break;
            case 1: {
                double nu2 = nus.pop();
                char op = ops.pop();
                append(rpn, op);
                if (op != '!') {
                    double nu1 = nus.pop();
                    nus.push(cals(nu1, op, nu2));
                } else {
                    nus.push(cals(op, nu2));
                }
                break;
            }
            default:
                exit(-1);
        }
    }
    return nus.pop();
}

int main() {
    char a[100];
    s:char *p = (char*)malloc(sizeof(char) * 100);
    scanf("%s", a);
    double re = calAndTran(a, p);
    printf("%lf %s\n", re, p);
    goto s;
}
