#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

int
main() {
    auto s = std::string{};
    unsigned long long sum = 0;

    while(std::getline(std::cin, s)) {
        auto set = std::unordered_set<char>{};
        for(int i = 0; i < s.size() / 2; ++i) {
            if(std::find(s.begin() + (s.size() / 2), s.end(), s[i]) != s.end()) {
                set.insert(s[i]);
                // std::cout << s[i] << ':';
            }
        }

        for(auto c: set) {
            // std::cout << c << ':' << (int)c << ':' << c - 'a' << ':' << c - 'A' << '\n';
            if(c <= 'Z') sum += c - 'A' + 27;
            else sum += c - 'a' + 1;
        }
    }

    std::cout << sum << std::endl;
}
