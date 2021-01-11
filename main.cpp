#include <iostream>
#include <memory>

using namespace std;

int main() {
    std::make_unique<>()
    [[maybe_unused]] int a[] = {1, 2, 3};
    return 0;
}
