#include <iostream>

int main() {
    for (int i = 0; i < 20; ++i) {
        std::cout << (rand() & 1) << std::endl;
    }
    return 0;
}
