/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-20 22:13:35
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-25 14:24:59
 */

#include <stdio.h>

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

int main() {
    char str[100];
    gets(str);
    printf("%lf\n", strToLf(str));
    return 0;
}
