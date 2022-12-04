#include <cstdio>
#include <queue>
#include <cmath>

using ll = long long;

ll
next() {
    char c = getchar();
    ll n = 0;
    if(c == EOF) return -1;
    while(c >= '0' && c <= '9') {
        n = n * 10 + (c - '0');
        c = getchar();
    }
    
    return n;
}

int
main() {
    ll n = 0;
    ll a;
    while((a = next()) != -1) {
        ll b = next(), c = next(), d = next();
        if(a > c) std::swap(a, c), std::swap(b, d);
        if(a + (b -a) >= c) n++;
    }

    printf("%lld", n);
}
