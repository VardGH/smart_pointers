#include <iostream>
#include "../shared_pointer/shared_pointer.hpp"
#include "../unique_pointer/unique_pointer.hpp"

int main() 
{
    custom_smart_ptr::shared_pointer<int> ptr1(new int(13));
    std::cout << "val: " << *ptr1 << std::endl;
    std::cout << "Use count: " << ptr1.use_count() << std::endl;

    {
        custom_smart_ptr::shared_pointer<int> ptr2 = ptr1;
        std::cout << "Use count: " << ptr1.use_count() << std::endl;
    }

    std::cout << "Use count: " << ptr1.use_count() << std::endl;

    custom_smart_ptr::unique_pointer<int> uptr(new int(23));
    std::cout << "value: " << *uptr << std::endl;
    
    return 0;
}
