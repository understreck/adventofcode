#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>
#include <iostream>

using ull = unsigned long long;

struct Folder {
    std::unordered_map<std::string, Folder> folders;
    std::unordered_map<std::string, ull> files;
};

Folder root{};
auto top = std::stack<Folder*>{};

enum Command {
    CD,
    LS,
    EXIT
};

Command
next_command() {
    if(std::cin.eof()) return EXIT;
    std::cin.get(); std::cin.get();
    if(std::cin.get() == 'c') {
        std::cin.get(); std::cin.get(); return CD;
    }    

    std::cin.get(); std::cin.get(); return LS;
}

auto
print(Folder &f, int indent) -> void {
    for(auto &[name, folder] : f.folders) {
        for(int i = 0; i < indent; ++i) std::cout << "  ";
        std::cout << name <<  "/:\n";
        print(folder, indent + 1);
    }

    for(auto &[name, size] : f.files) {
        for(int i = 0; i < indent; ++i) std::cout << "  ";
        std::cout << name << " - " << size << '\n';
    }
}

auto
print() -> void {
    std::cout << "/:\n";
    print(root, 1);
    std::cout << std::flush;
}

ull sum = 0;

auto
size(Folder &f) -> ull {
    ull s = 0;
    for(auto &[name, folder] : f.folders) {
        s += size(folder);
    }

    for(auto &[name, size] : f.files) {
        s += size;
    }
    // std::cout << s << '\n';
    if(s <= 100000) sum += s;
    return s;
}

int
main() {
    std::cout.sync_with_stdio(false);
    std::cin.tie(0)->sync_with_stdio(false);
    Command cmd;
    while((cmd = next_command()) != EXIT) {
        if(cmd == CD) {
            std::string s;
            std::getline(std::cin, s);
            if(s[0] == '/') {
                top = {};
            }
            else if(s[0] == '.') {
                if(not top.empty()) top.pop();
            }
            else {
                if(top.empty()) {
                    top.push(&(root.folders[s]));
                }
                else {
                    top.push(&(top.top()->folders[s]));
                }
            }
        }
        else {
            while(not std::cin.eof()) {
                auto c = std::cin.get();
                if(c == '$') {
                    std::cin.putback('$');
                    break;
                }
                if(c == 'd') {
                    std::cin.get();
                    std::cin.get();
                    std::cin.get();
                    auto name = std::string{};
                    std::getline(std::cin, name);
                    if(top.empty()) root.folders[name];
                    else top.top()->folders[name];
                }
                else {
                    std::cin.putback(c);
                    ull size;
                    std::string name;
                    std::cin >> size >> std::ws;
                    std::getline(std::cin, name);
                    if(top.empty()) root.files[name] = size;
                    else top.top()->files[name] = size;
                }
            }
        }
    }
    // print();

    size(root);
    std::cout << sum << std::endl;
    // printf("%llu\n");
}
