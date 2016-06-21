#ifndef QSORTHELPERS_H
#define QSORTHELPERS_H

namespace QSortHelpers
{

template <typename T>
struct PtrLess // public std::binary_function<bool, const T*, const T*>
{
  bool operator()(const T* a, const T* b) const
  {
    // may want to check that the pointers aren't zero...
    return *a < *b;
  }
};
}

#endif // QSORTHELPERS_H
