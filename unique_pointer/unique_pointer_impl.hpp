#ifndef UNIQUE_POINTER_IMPL_HPP
#define UNIQUE_POINTER_IMPL_HPP

#include "unique_pointer.hpp"
#include <utility>

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
unique_pointer<T>::unique_pointer(unique_pointer<T>&& rsh) noexcept
    : m_ptr(rsh.m_ptr)
{
    rsh.m_ptr = nullptr;
}

// move assignment
template <typename T>
unique_pointer<T>& unique_pointer<T>::operator=(unique_pointer<T>&& rsh) noexcept
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
T* unique_pointer<T>::operator->() const noexcept
{
    return m_ptr;
}

template <typename T>
T& unique_pointer<T>::operator*() const noexcept
{
    return *m_ptr;
}

template <typename T>
T* unique_pointer<T>::release() noexcept
{
    T* tmp = m_ptr;
    m_ptr = nullptr;
    return tmp;
}

template <typename T>
void unique_pointer<T>::reset(T* ptr) noexcept
{
    delete m_ptr;
    m_ptr = ptr;
}

template <typename T>
void unique_pointer<T>::swap(unique_pointer<T>& rhs) noexcept
{
    std::swap(m_ptr, rhs.m_ptr);
}

template <typename T>
T* unique_pointer<T>::get() const noexcept
{
    return m_ptr;
}

} // namespace name


#endif // UNIQUE_POINTER_IMPL_HPP