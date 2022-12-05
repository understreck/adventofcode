#include <cstdio>
#include <deque>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <string>

std::size_t constexpr N = 10;

int
next() {
    int c = getchar(), n = 0;
    if(c == EOF) return -1;
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') {
        n = n * 10 + (c - '0');
        c = getchar();
    }

    return n;
}

int
main() {
    std::cin.tie(0);
    std::string s;

    auto stacks = std::array<std::deque<char>, N>{};

    while(std::getline(std::cin, s), s[1] < '0' || s[1] > '9') {
        for(int i = 1; i < N * 4 + 1; i += 4) {
            if(s[i] != ' ') stacks[(i - 1) / 4].push_back(s[i]);
        }
    }

    int i;
    while((i = next()) != -1) {
        auto from = next() - 1;
        auto to = next() - 1;
        auto I = i;
        while(i-- > 0) {
            stacks[to].push_front(stacks[from][i]);
        }
        for(i = 0;i < I; ++i) {stacks[from].pop_front();}
    }

    for(auto &stack : stacks) std::cout << stack.front();
}
