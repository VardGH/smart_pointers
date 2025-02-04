#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

namespace custom_smart_ptr {

template <typename T>
class shared_pointer
{
public:
    // Default constructor
    shared_pointer();
    // Constructor with params
    explicit shared_pointer(T* ptr);

    // Copy semantics
    shared_pointer(const shared_pointer<T>& rhs);
    shared_pointer<T>& operator=(const shared_pointer<T>& rhs);

    // Move semantics
    shared_pointer(shared_pointer<T>&& rhs);
    shared_pointer<T>& operator=(shared_pointer<T>&& rhs);

    ~shared_pointer();

    // Utility functions
    T* get() const;
    int use_count() const;
    void reset(T* ptr = nullptr);

    // Operators
    T& operator*() const;
    T* operator->() const;

private:
    void clean();

private:
    T* m_ptr = nullptr;
    int* counter = nullptr;
};

} // namespace custom_smart_ptr

#include "shared_pointer_impl.hpp"

#endif // SHARED_POINTER_HPP