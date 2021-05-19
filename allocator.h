#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstdlib>
#include "construct.h"

namespace LemonSTL {
  // 配置器
  template<class T>
  class allocator {
  public:
    typedef T                    value_type;
    typedef T*                   pointer;   
    typedef const T*             const_pointer;
    typedef T&                   reference; 
    typedef const T&             const_reference;
    typedef size_t               size_type; 
    typedef ptrdif_t             differenc_type;
  public:
    static T* allocate();
    static T* allocate(size_t n);
    static void deallocate(T *ptr);
    static void deallocate(T *ptr, size_t n);

    static void construct(T* ptr);
    static void construct(T* ptr, const T& value);
    static void destroy(T* ptr);
    static void destroy(T* first, T* last);
  };

  template<class T>
  T* allocator<T>::allocate() {
    return static_cast<T*>(::operator new(sizeof(T)));  
  }

  template<class T>
  T* allocator<T>::allocate(size_t n) {
    if (n == 0) return nullptr;
    return static_cast<T*>(::operator new(n * sizeof(T))));  
  }
  
  template<class T>
  void allocator<T>::deallocate(T *ptr) {
    if (ptr == nullptr) return;
    ::operator delete(ptr);
  }

  template<class T>
  void allocator<T>::deallocate(T *ptr, size_t n) {
    if (ptr == nullptr) return;
    ::operator delete(ptr);
  }

  template<class T>
  void allocator<T>::construct(T* ptr) {
    LemonSTL::construct(ptr);
  }

  template<class T>
  void allocator<T>::construct(T* ptr, const T& value) {
    LemonSTL::construct(ptr, value);
  }

  template<class T>
  void allocator<T>::destroy(T* ptr) {
    LemonSTL::destroy(ptr);
  }
  
  template<class T>
  void allocator<T>::destroy(T* first, T* last) {
    LemonSTL::destroy(first, last);
  }
}

#endif
