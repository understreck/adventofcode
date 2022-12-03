#include <cstdio>
#include <cstdlib>

using ull = unsigned long long;

int
next() {
    int c = getchar(), n = 0;
    if(c == EOF || c == '\n') return -1;
    while(c >= '0' && c <= '9') {
        n = n * 10 + (c - '0');
        c = getchar();
    }

    return n;
}

int
main() {
    ull l = 0;
    ull nl = 0;
    ull nnl = 0;

    int n;
    while((n = next()) != -1) {
        ull sum = 0;
        do {
            sum += n;
        } while((n = next()) != -1);
        if(sum > l) nnl = nl, nl = l, l = sum;
        else if(sum > nl) nnl = nl, nl = sum;
        else if(sum > nnl) nnl = sum;
    }

    printf("%llu", l + nl + nnl);
}
