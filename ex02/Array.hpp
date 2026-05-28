#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>


template <typename T> //template <class T> (both are equal)
class Array
{
    private:
        unsigned int _size;
        T* _arr;
    public:

        Array() : _size(0), _arr(NULL){}

        Array(unsigned int n) : _size(n), _arr(new T[n]()){}

        Array(const Array& other) : _size(other._size), _arr(new T[other._size]())
        {
            for (unsigned int i =0; i < other._size; i++)
            {
                _arr[i] = other._arr[i];
            }
        }

        ~Array()
        {
            delete[] _arr;
        };

        Array& operator=(const Array& other)
        {
            if(this != &other)
            {
                delete[] this-> _arr;
                this->_size = other._size;

                this->_arr = new T[other._size]();
                
                for (unsigned int i =0; i < other._size; i++)
                {
                    this->_arr[i] = other._arr[i];
                }                
            }
            return *this;            
        }

        T& operator[](unsigned int i)
        {
            if(i >= _size)
            {
                throw std::exception();
            }
            return _arr[i];
        }

        unsigned int size() const        
        {
            return _size;
        }

};

#endif