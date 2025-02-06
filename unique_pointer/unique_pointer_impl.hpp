#ifndef UNIQUE_POINTER_IMPL_HPP
#define UNIQUE_POINTER_IMPL_HPP

#include "unique_pointer.hpp"

namespace custom_smart_ptr
{

// default ctor
template <typename T>
unique_pointer<T>::unique_pointer()
    : m_ptr(nullptr)
{
}

template <typename T>
unique_pointer<T>::unique_pointer(T* ptr)
    : m_ptr(ptr)
{
}

// move ctor
template <typename T>
unique_pointer<T>::unique_pointer(unique_pointer<T>&& rsh)
    : m_ptr(rsh.m_ptr)
{
    rsh.m_ptr = nullptr;
}

// move assignment
template <typename T>
unique_pointer<T>& unique_pointer<T>::operator=(unique_pointer<T>&& rsh)
{
    if (this != &rsh) {
        delete m_ptr; // free resource 
        m_ptr = rsh.m_ptr;
        rsh.m_ptr = nullptr;
    }
    return *this;
}

// dtor
template <typename T>
unique_pointer<T>::~unique_pointer()
{
    delete m_ptr;
}

template <typename T>
T* unique_pointer<T>::operator->() const
{
    return m_ptr;
}

template <typename T>
T& unique_pointer<T>::operator*() const
{
    return *m_ptr;
}

} // namespace name


#endif // UNIQUE_POINTER_IMPL_HPP