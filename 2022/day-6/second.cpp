#include <cstdio>
#include <array>
#include <algorithm>

auto constexpr N = 14;
using A = std::array<char, N>;

bool
equal(A &a, int i) {
    if(i == (N - 1)) return false;

    // printf("%d", a[i] + 0);
    for(int j = i + 1; j < N; ++j) {
        // printf("::%d::", a[j] + 0);
        if(a[i] == a[j]) {
            // putchar('\n');
            return true;
        }
    }

    // putchar('\n');
    return equal(a, i + 1);
}

int
main() {
    auto a = A{};
    for(int i = 0; i < N; ++i) a[i] = getchar();

    std::size_t i = N;
    while(++i, a[N - 1] != '\n' && equal(a, 0)) {
        // for(int j = 0; j < N; ++j) putchar(a[j] == '\0' ? '0' : a[j]); putchar('\n');
        std::rotate(a.begin(), a.begin() + 1, a.end());
        a[N - 1] = getchar();
        // for(int j = 0; j < N; ++j) putchar(a[j] == '\0' ? '0' : a[j]); putchar('\n'); putchar('\n');
    }

    printf("%lu\n", i);
}
