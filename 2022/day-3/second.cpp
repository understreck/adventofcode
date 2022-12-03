#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

int
main() {
    auto l1 = std::string{};
    auto l2 = std::string{};
    auto l3 = std::string{};
    unsigned long long sum = 0;
    
    while(std::getline(std::cin, l1), std::getline(std::cin, l2), std::getline(std::cin, l3)) {
        auto s = std::unordered_set<char>{};
        for(char c : l1) {
            if(std::find(l2.begin(), l2.end(), c) != l2.end()) {
                s.insert(c);
            }
        }

        for(auto c : s) {
            if(std::find(l3.begin(), l3.end(), c) != l3.end()) {
                if(c <= 'Z') sum += c - 'A' + 27;
                else sum += c - 'a' + 1;
                break;
            }
        }
    }

    std::cout << sum << std::endl;
}
