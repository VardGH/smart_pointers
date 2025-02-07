# Custom Smart Pointers

This project implements custom smart pointers in C++: `shared_pointer` and `unique_pointer`. These smart pointers manage the lifetime of dynamically allocated objects, ensuring proper resource management and avoiding memory leaks.

## Project Structure

```
shared_pointer/
    shared_pointer_impl.hpp
    shared_pointer.hpp
tests/
    main.cpp
unique_pointer/
    unique_pointer_impl.hpp
    unique_pointer.hpp
```

## `shared_pointer`

The `shared_pointer` class is a reference-counting smart pointer that allows multiple pointers to share ownership of an object. When the last `shared_pointer` owning an object is destroyed, the object is deleted.

### Public Interface

- **Constructors:**
  - `shared_pointer()`
  - `explicit shared_pointer(T* ptr)`
  - `shared_pointer(const shared_pointer<T>& rhs)`
  - `shared_pointer(shared_pointer<T>&& rhs)`

- **Assignment Operators:**
  - `shared_pointer<T>& operator=(const shared_pointer<T>& rhs)`
  - `shared_pointer<T>& operator=(shared_pointer<T>&& rhs)`

- **Destructor:**
  - `~shared_pointer()`

- **Utility Functions:**
  - `T* get() const`
  - `int use_count() const`
  - `void reset(T* ptr = nullptr)`

- **Operators:**
  - `T& operator*() const`
  - `T* operator->() const`

## `unique_pointer`

The `unique_pointer` class is a smart pointer that owns and manages another object through a pointer and disposes of that object when the `unique_pointer` goes out of scope. It ensures that only one `unique_pointer` can own the object at any time.

### Public Interface

- **Constructors:**
  - `unique_pointer()`
  - `unique_pointer(T* ptr)`
  - `unique_pointer(unique_pointer<T>&& rhs) noexcept`

- **Assignment Operators:**
  - `unique_pointer<T>& operator=(unique_pointer<T>&& rhs) noexcept`

- **Destructor:**
  - `~unique_pointer()`

- **Utility Functions:**
  - `T* release() noexcept`
  - `void reset(T* ptr) noexcept`
  - `void swap(unique_pointer<T>& other) noexcept`
  - `T* get() const noexcept`

- **Operators:**
  - `T* operator->() const noexcept`
  - `T& operator*() const noexcept`

## Running Tests

To run the tests, compile and execute the `main.cpp` file. This file demonstrates the usage of both `shared_pointer` and `unique_pointer` classes.

```sh
g++ -std=c++11 -o test tests/main.cpp
./test
```