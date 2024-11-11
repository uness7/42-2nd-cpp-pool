#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>

class Array
{
	private:
		T* _array;
		unsigned int _size;

	public:
		Array(void) : _array(new T[0]), _size(0) {}

		Array(unsigned int size) : _array(new T[size]), _size(size) {}

		Array(const Array& other) : _size(other._size)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] _array;
				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return *this;
		}

		~Array(void)
		{
			if (_array)
				delete[] _array;
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _array[index];
		}

		unsigned int getSize(void) const { return _size; }
};

#endif
