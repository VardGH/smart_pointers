#ifndef SHARED_POINTER_IMPL_HPP
#define SHARED_POINTER_IMPL_HPP

#include "shared_pointer.hpp"

namespace custom_smart_ptr {

template <typename T>
shared_pointer<T>::shared_pointer() 
    : m_ptr(nullptr)
    , counter(new int(0)) 
{
}

template <typename T>
shared_pointer<T>::shared_pointer(T* ptr) 
    : m_ptr(ptr)
    , counter(new int(1)) 
{
}

template <typename T>
shared_pointer<T>::shared_pointer(const shared_pointer<T>& rhs) 
    : m_ptr(rhs.m_ptr)
    , counter(rhs.counter) 
{
    if (m_ptr) 
        (*counter)++;
}

template <typename T>
shared_pointer<T>& shared_pointer<T>::operator=(const shared_pointer<T>& rhs) 
{
    if (this != &rhs) {
        clean();
        m_ptr = rhs.m_ptr;
        counter = rhs.counter;

        if (m_ptr) 
            (*counter)++;
    }
    return *this;
}

template <typename T>
shared_pointer<T>::shared_pointer(shared_pointer<T>&& rhs) 
    : m_ptr(rhs.m_ptr)
    , counter(rhs.counter)
{
    rhs.m_ptr = nullptr;
    rhs.counter = nullptr;
}

template <typename T>
shared_pointer<T>& shared_pointer<T>::operator=(shared_pointer<T>&& rhs) 
{
    if (this != &rhs) {
        clean();
        m_ptr = rhs.m_ptr;
        counter = rhs.counter;

        rhs.m_ptr = nullptr;
        rhs.counter = nullptr;
    }
    return *this;
}

template <typename T>
shared_pointer<T>::~shared_pointer() 
{
    clean();
}

template <typename T>
void shared_pointer<T>::clean() 
{
    if (counter && --(*counter) == 0) {
        delete m_ptr;
        delete counter;
    }
}

template <typename T>
T* shared_pointer<T>::get() const 
{
    return m_ptr;
}

template <typename T>
int shared_pointer<T>::use_count() const 
{
    return (counter) ? *counter : 0;
}

template <typename T>
void shared_pointer<T>::reset(T* ptr) 
{
    clean();
    m_ptr = ptr;
    counter = new int(ptr ? 1 : 0);
}

template <typename T>
T& shared_pointer<T>::operator*() const 
{
    return *m_ptr;
}

template <typename T>
T* shared_pointer<T>::operator->() const 
{
    return m_ptr;
}

} // namespace custom_smart_ptr

#endif // SHARED_POINTER_IMPL_HPP
