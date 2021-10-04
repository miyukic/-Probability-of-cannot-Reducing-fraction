#include <iostream>
#include <unistd.h>
#include <random>
#include <utility>
#include <cmath>
#include <cstdio>

constexpr double PI = 3.14159265358979323846L;

uint64_t do約分(uint64_t a, uint64_t b);
bool is約数がない(int a, int b);

int main()
{
    std::cout << isatty(1) << std::endl;
    // ターミナルのことをLinuxではttyという。
    std::random_device seed_gen;
    std::mt19937 mt{seed_gen()};
    std::uniform_int_distribution<> dist{0, 1000}; 

    constexpr uint32_t TIMES = 300000;
    uint32_t count = 0;
    for (uint32_t i = 0; i < TIMES; i++) {
        if (is約数がない(dist(mt), dist(mt))) {
            //std::cout << "約分が無い" << std::endl;
            ++count;
        }
    }
    std::cout << "6/π^2 = " << (double)6.0 / (double)std::pow((double)PI, 2) << std::endl;
    std::cout << "count=" << count << "TIMES=" << TIMES << std::endl;
    auto result = (double) count / TIMES;
    std::cout << "result=" << result << std::endl;
    //std::printf("%d\n", is約数がない(887*2, 887));

    return 0;
}

bool is約数がない(int a, int b) {
    if (do約分(a, b) == 1) return true; 
    return false;
}

uint64_t do約分(uint64_t a, uint64_t b) {
    if (a == 0 || b == 0) return 0;
    if (a < b) std::swap(a, b);
    if ((a % b) == 0) {
        return b;
    }
    return do約分(b, a % b);
}
