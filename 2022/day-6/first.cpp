#include <cstdio>

int
main() {
    char a, b, c, d;
    a = b = c = d = getchar();
    std::size_t i = 0;
    while(++i, d != '\n' &&
        a == b || a == c || a == d ||
        b == c || b == d ||
        c == d) {
        a = b;
        b = c;
        c = d;
        d = getchar();
    }

    printf("%lu\n", i);
}
