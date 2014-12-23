/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-16 19:43:09
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-16 19:47:01
 */

void hanoi(int n, Stack<Disk>& sx, Stack<Disk>& sy, Stack<Disk>& sz) {
    if (n > 0) {
        hanoi(n-1, sx, sz, sy);
        move(sx, sz);
        hanoi(n-1, sy, sx, sz);
    }
}
