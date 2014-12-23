/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-16 20:10:40
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-16 20:19:26
 */

/* 将规模为n的数组循环左移k位
 * 原理：
 * R + L == (R' + L')' // '表示倒置
 */
void shift(int *a, int n, int k) {
    reverse(a, k);
    reverse(a + k, m - k);
    reverse(a, n);
}

/* 数组倒置 */
void reverse(int *a, n) {
    for (int i = 0; i < n/2; i++) {
        swap(a[i], a[n - i]);
    }
}