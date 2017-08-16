/**
* Implementation of Vector
*
* Copyright 2017 Oleksii Diubankov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef OSTD_VECTOR_H
#define OSTD_VECTOR_H

#include <algorithm>
#include <stdexcept>

namespace ostd
{

template<typename T>
class Vector
{
    T *_data;
    std::size_t _size;
    std::size_t _capacity;

public:
    Vector()
        : _data{nullptr}, _size{0}, _capacity{0}
    {}

    Vector(const Vector &other)
    {
        if (other._size > 0) {
            copy_from_other(other);
        }
        else {
            _data = nullptr;
            _size = 0;
            _capacity = 0;
        }
    }

    Vector(Vector &&other) noexcept
    {
        move_from_other(std::move(other));
    }

    Vector &operator=(const Vector &other)
    {
        if (this == &other)
            return *this;

        clean_resources();
        copy_from_other(other);
        return *this;
    }

    Vector &operator=(Vector &&other) noexcept
    {
        if (this == &other)
            return *this;

        clean_resources();
        move_from_other(std::move(other));
        return *this;
    }

    ~Vector()
    {
        clean_resources();
    }

    void push_back(const T &val)
    {
        if (_size == _capacity)
            increase_capacity();

        _data[_size] = val;
        ++_size;
    }

    void pop_back()
    {
        if (0 == _size)
            throw std::out_of_range{""};

        --_size;
        if (_size < _capacity / 4)
            decrease_capacity();
    }

    std::size_t size() const noexcept
    { return _size; }

    const T &operator[](std::size_t index) const
    {
        if (index >= size())
            throw std::out_of_range{""};

        return _data[index];
    }

    T &operator[](std::size_t index)
    {
        if (index >= size())
            throw std::out_of_range{""};

        return _data[index];
    }

private:
    void copy_from_other(const Vector &other)
    {
        _data = new T[other._size];
        std::copy(other._data, other._data + other._size, _data);
        _capacity = _size = other._size;
    }

    void move_from_other(Vector &&other) noexcept
    {
        _size = other._size;
        _capacity = other._capacity;
        _data = other._data;

        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
    }

    void clean_resources()
    {
        if (nullptr != _data) {
            delete[] _data;
            _data = nullptr;
            _size = 0;
            _capacity = 0;
        }
    }

    void increase_capacity()
    {
        if (_capacity == 0) {
            _capacity = 1;
            _data = new T[_capacity];
        }
        else {
            _capacity *= 2;
            applyNewCapacity();
        }
    }

    void decrease_capacity()
    {
        _capacity /= 2;
        applyNewCapacity();
    }

    void applyNewCapacity()
    {
        auto tempData = new T[_capacity];
        if (std::is_nothrow_move_constructible<T>::value)
            std::move(_data, _data + _size, tempData);
        else
            std::copy(_data, _data + _size, tempData);
        std::swap(_data, tempData);
        delete[] tempData;
    }
};

}//namespace ostd



#endif //OSTD_VECTOR_H
