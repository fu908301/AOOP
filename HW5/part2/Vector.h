#ifndef __VECTOR_H__
#define __VECTOR_H__

#define __TRACE__

#include<string>
#include<vector>
#include"Trace.h"
using std::vector;

static int count = 1;

template<typename T>
class Vector
{
public:
  Vector( int size )
  {
    TRACE( tmp, "vector<T>::vector(int)" );
    cout << "  count = " << count << endl;
    this->sz = size;
    v = new T[sz];
  }
  ~Vector()
  {
    TRACE( tmp, "vector<T>::~vector" );
    cout << "  count = " << count << endl;
    delete [] v;
  }
  T &elem( int index )
  {
    return v[index];
  }
  T &operator[]( int index )
  {
    return v[index];
  }
private:
  T *v;
  int sz;
};

template<>
class Vector<void *>
{
public:
  Vector( int size )
  {
    TRACE( tmp, "vector<void*>::vector(int)" );
    cout << "  count = " << count << endl;
    this->sz = size;
    p = new void*[sz];
  }
  ~Vector()
  {
    TRACE( tmp, "vector<void*>::~vector" );
    cout << "  count = " << count << endl;
    delete [] p;
  }
  void *&elem( int index )
  {
    return p[index];
  }
  void *&operator[]( int index )
  {
    return p[index];
  }
private:
  void **p;
  int sz;
};

template<typename T>
class Vector<T *>: public Vector<void *>
{
public:
  typedef Vector<void *> Base;
  Vector( int size ): Base( size )
  {
    TRACE( tmp, "vector<T*>::vector(int)" );
    count++;
    this->sz = size;
    p = new void*[sz];
  }
  ~Vector()
  {
    TRACE( tmp, "vector<T*>::~vector" );
    count--;
    delete [] p;
  }
  T *&elem( int i )
  {
    return reinterpret_cast<T *&>( p[i] );
  }
  T *&operator[]( int i )
  {
    return reinterpret_cast<T *&>( p[i] );
  }
private:
  void **p;
  int sz;
};

#endif
