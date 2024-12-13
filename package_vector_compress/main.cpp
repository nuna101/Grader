#include <stdexcept>
#include <iostream>
#include "vector2.h"
#include "student.h"

int main() {
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);
    CP::vector<int> v;
    int round,n;
    std::cin >> round >> n;
    for (int k = 0;k < round;k++) {
        v.clear();
        for (int i = 0;i < n + (k % 7);i++) {
            int a = PRNG();
            v.push_back(a);
        }
        v.check_compress();
    }
    std::cout << "Size of v is " << v.size() << std::endl;
    for (auto &x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "password: 9p843wujyh;sdl fg'p03w;asdk" << std::endl;
}
