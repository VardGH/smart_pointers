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
    unique_pointer(unique_pointer&& rhs) noexcept;
    unique_pointer& operator=(unique_pointer&& rhs) noexcept;

    // Destructor
    ~unique_pointer();

public:
    // dereferences pointer to the managed object
    T* operator->() const noexcept;
    T& operator*() const noexcept;

    // modifiners
    T* release() noexcept; // returns a pointer to the managed object and releases the ownership
    void reset(T* ptr) noexcept; // replaces the managed object
    void swap(unique_pointer<T>& other) noexcept; // swaps the managed objects

    // observers
    T* get() const noexcept; // returns a pointer to the managed object

private:
    T* m_ptr = nullptr;
};

} // namespace custom_smart_pointer

#include "unique_pointer_impl.hpp"

#endif // UNIQUE_POINTER_HPP