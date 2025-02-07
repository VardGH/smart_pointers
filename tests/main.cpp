#include <iostream>
#include "../shared_pointer/shared_pointer.hpp"
#include "../unique_pointer/unique_pointer.hpp"


struct Test
{
    int value;
    Test(int v) : value(v) { std::cout << "Test(" << value << ") created\n"; }
    ~Test() { std::cout << "Test(" << value << ") destroyed\n"; }
    void show() { std::cout << "Value: " << value << std::endl; }
};

int main()
{

    using namespace custom_smart_ptr;
    // 1. Default constructor
    unique_pointer<Test> up1;
    if (!up1.get()) std::cout << "up1 is empty\n";

    // 2. Constructor from raw pointer
    unique_pointer<Test> up2(new Test(10));
    std::cout << "up2 value: " << up2->value << std::endl;

    // 3. Move constructor
    unique_pointer<Test> up3(std::move(up2));
    if (!up2.get()) std::cout << "up2 is now empty after move\n";
    std::cout << "up3 value: " << up3->value << std::endl;

    // 4. Move assignment
    unique_pointer<Test> up4;
    up4 = std::move(up3);
    if (!up3.get()) std::cout << "up3 is now empty after move assignment\n";
    std::cout << "up4 value: " << up4->value << std::endl;

    // 5. Release ownership
    Test* raw_ptr = up4.release();
    if (!up4.get()) std::cout << "up4 is now empty after release\n";
    delete raw_ptr;  // Manual deletion

    // 6. Reset with a new pointer
    up4.reset(new Test(20));
    std::cout << "up4 new value: " << up4->value << std::endl;

    // 7. Swap
    unique_pointer<Test> up5(new Test(30));
    std::cout << "Before swap: up4 = " << up4->value << ", up5 = " << up5->value << std::endl;
    up4.swap(up5);
    std::cout << "After swap: up4 = " << up4->value << ", up5 = " << up5->value << std::endl;

    return 0;
}