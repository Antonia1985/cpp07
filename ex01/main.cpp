#include "iter.hpp"
#include <iostream>

void printNum(int& num)
{
    std::cout << num << std::endl;
}

void printConst(const int& num)
{
    std::cout << num << std::endl;
}

void print(int num)
{
    std::cout << num << std::endl;
}

template <typename T>
void print(T value)
{
    std::cout << value << " " ;
}

int main()
{
    int arr[5] = {1, 3, 5, 7, 9};
    const std::size_t size =  sizeof(arr) / sizeof(arr[0]);
    iter(arr, size, printNum);
    std::cout << std::endl;

    const int arrConst[5] = {10, 30, 50, 70, 90};
    const std::size_t sizeConst =  sizeof(arrConst) / sizeof(arrConst[0]);
    iter(arrConst, sizeConst, printConst);
    std::cout << std::endl;

    std::string words[2] = {"hello", "you"};
    iter(words, 2, print<std::string>); // an instantiated function template
    std::cout << std::endl;

    int nums[3] = {100, 101, 102};
    iter(nums, 3, print<int>); // an instantiated function template
    std::cout << std::endl;

    return 0;
}