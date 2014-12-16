#include <stdio.h>

int main() {
    int a = 0;
    if (-1 < sizeof(a)) {
        printf("%d", a);
    } else {
        printf("%d", 1);
    }
}