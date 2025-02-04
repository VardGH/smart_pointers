#include <iostream>
#include "shared_pointer.hpp"

int main() 
{
    custom_smart_ptr::shared_pointer<int> ptr1(new int(13));
    std::cout << "val: " << *ptr1 << "\n";
    std::cout << "Use count: " << ptr1.use_count() << "\n"; 

    {
        custom_smart_ptr::shared_pointer<int> ptr2 = ptr1;
        std::cout << "Use count: " << ptr1.use_count() << "\n";
    }

    std::cout << "Use count: " << ptr1.use_count() << "\n";
    return 0;
}
