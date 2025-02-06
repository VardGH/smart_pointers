#ifndef UNIQUE_POINTER_HPP
#define UNIQUE_POINTER_HPP

namespace custom_smart_ptr {

template <typename T>
class unique_pointer
{
public:
    // Deafult constructor
    unique_pointer();
    unique_pointer(T* ptr);

    // Copy semantics (deleted)
    unique_pointer(const unique_pointer& rhs) = delete;
    unique_pointer& operator=(const unique_pointer& rhs) = delete;

    // Move semantics
    unique_pointer(unique_pointer&& rhs);
    unique_pointer& operator=(unique_pointer&& rhs);

    // Destructor
    ~unique_pointer();

public:
    // dereferences pointer to the managed object
    T* operator->() const;
    T& operator*() const;
private:
    int* m_ptr = nullptr;
};

} // namespace custom_smart_pointer

#include "unique_pointer_impl.hpp"

#endif // UNIQUE_POINTER_HPP