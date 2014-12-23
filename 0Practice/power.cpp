/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-16 19:39:18
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-16 19:42:37
 */

//O(log n) 计算a^n
int power(int a, int n) {
    int pow = 1, p = a;
    while(n > 0) {
        if (n & 1) pow *= p;
        p *= p;
        n >> 1;
    }
}
