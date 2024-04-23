#include <iostream>

int main() {
    int* ptr = new int(42);
    // Use the pointer
    std::cout << "Value: " << *ptr << std::endl;

    delete ptr;     // Delete the allocated memory
    ptr = nullptr;  // Eliminate the dangling pointer

    // Array example
    int* arr = new int[5] {1, 2, 3, 4, 5};
    delete[] arr;
    arr = nullptr;

    return 0;
}
