/**
 * @Author  : ValenW
 * @Link    : https://github.com/ValenW
 * @Email   : ValenW@qq.com
 * @Date    : 2014-12-16 19:19:29
 * @Last Modified by:   ValenW
 * @Last Modified time: 2014-12-16 19:39:03
 */

/* 普通版 O(count(n)) */
int countOnes(unsigned n) {
    int ones = 0;
    while (n > 0) {
        noes++; // 至少有一个一
        n &= n-1; // 清除最右的1
    }
}

/* 改进版，O(log logn) */

#define POW(c) (1 << (c)) //return 2^c
#define MASK(c) (((unsigned long) - 1) / (POW(POW(c)) + 1))
#define ROUND(n, c) (((n) & MASK(c)) + ((n) >> POW(c) & MASK(c)))

///////////
//别问我///
///////////

/* 以2^c为单位分组，相间全1或全0
 * 如(以32位为例)
 * MASK(0) = 01010101010101010101010101010101
 * MASK(1) = 00110011001100110011001100110011
 * ......
 */

int countOnes2(unsigned n) {
    n = ROUND(n, 0);
    n = ROUND(n, 1);
    n = ROUND(n, 2);
    n = ROUND(n, 3);
    n = ROUND(n, 4);
    return n;
}
