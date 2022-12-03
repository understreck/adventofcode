#include <cstdio>
#include <cstdlib>

using ull = unsigned long long;

char
next() {
    auto c = getchar(); getchar();

    return c;
}

int
main() {
    ull sum = 0;
    char opponent;
    while((opponent = next()) != EOF) {
        char us = next();
        if(opponent == 'A') {
            switch(us) {
                case 'X': {
                    sum += 3 + 0;
                } break;
                case 'Y': {
                    sum += 1 + 3;
                } break;
                case 'Z': {
                    sum += 2 + 6;
                } break;
            }
        }
        else if(opponent == 'B') {
            switch(us) {
                case 'X': {
                    sum += 1 + 0;
                } break;
                case 'Y': {
                    sum += 2 + 3;
                } break;
                case 'Z': {
                    sum += 3 + 6;
                } break;
            }
        }
        else if(opponent == 'C') {
            switch(us) {
                case 'X': {
                    sum += 2 + 0;
                } break;
                case 'Y': {
                    sum += 3 + 3;
                } break;
                case 'Z': {
                    sum += 1 + 6;
                } break;
            }
        }
    }

    printf("%llu", sum);
}
