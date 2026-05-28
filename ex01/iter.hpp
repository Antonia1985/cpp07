#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T* arr, const std::size_t arrSize, F function)
{
    for (std::size_t i = 0; i < arrSize; i++)
    {
        function(arr[i]);
    }
}

#endif