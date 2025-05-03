#ifndef UNIQUE_PTR_H

#define UNIQUE_PTR_H

#include <stdexcept>

template <class T>
class unique_ptr {
 private:
  T* ptr;

 public:
  // Constructor
  explicit unique_ptr(T* p = nullptr) : ptr(p) {}

  // Destructor
  ~unique_ptr() {
    delete ptr;
    ptr = nullptr;
  }

  // Copy contructor
  unique_ptr(const unique_ptr& other) = delete;  // Disable copy constructor

  unique_ptr& operator=(const unique_ptr& other) =
      delete;  // Disable copy assign

  // Move constructor
  unique_ptr(unique_ptr&& other) {
    ptr = other.ptr;
    other.ptr = nullptr;
  }

  // Move assignment constructor
  unique_ptr& operator=(unique_ptr&& other) {
    if (this != &other) {
      delete ptr;
      ptr = other.ptr;
      other.ptr = nullptr;
    }

    return *this;
  }

  T* release() {
    T* temp = ptr;
    ptr = nullptr;
    return temp;
  }

  void reset(T* otherPtr) {
    if (ptr != otherPtr) {
      delete ptr;
      ptr = otherPtr;
    }
  }

  void swap(unique_ptr& other) {
    T* temp = ptr;
    ptr = other.ptr;
    other.ptr = temp;
  }

  T* get() const { return ptr; }

  operator bool() const { return ptr != nullptr; }

  T* operator->() const { return ptr; }

  T& operator*() const {
    if (ptr == nullptr) {
      throw std::runtime_error("Dereferencing a null pointer");
    }
    return *ptr;
  }
};

#endif
