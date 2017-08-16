/**
* Shared pointer implementation
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

#ifndef OSTD_SHAREDPTR_H
#define OSTD_SHAREDPTR_H

#include <cstddef>
#include <cassert>

namespace ostd
{

template<typename T>
class SharedPtr
{
public:
    SharedPtr() noexcept
        : _counter{nullptr}, _rawPtr{nullptr}
    {}

    explicit SharedPtr(T *rawPtr) noexcept
        : _counter{new std::size_t(1)}, _rawPtr{rawPtr}
    {}

    ~SharedPtr()
    {
        decrementRefCount();
    }

    SharedPtr(const SharedPtr<T> &other) noexcept
        : _counter{other._counter}, _rawPtr{other._rawPtr}
    {
        incrementRefCount();
    }

    SharedPtr(SharedPtr<T> &&other) noexcept
        : _counter{other._counter}, _rawPtr{other._rawPtr}
    {
        other.reset();
    }

    SharedPtr<T> &operator=(const SharedPtr<T> &other) noexcept
    {
        decrementRefCount();
        copyFromOther(other);
        incrementRefCount();
        return *this;
    }

    SharedPtr<T> &operator=(SharedPtr<T> &&other) noexcept
    {
        decrementRefCount();
        copyFromOther(other);
        other.reset();
        return *this;
    }

    T *operator->() const noexcept
    {
        return _rawPtr;
    }

    T &operator*() noexcept
    {
        assert(nullptr != _rawPtr);
        return *_rawPtr;
    }

    const T &operator*() const noexcept
    {
        assert(nullptr != _rawPtr);
        return *_rawPtr;
    }

    T *get() const noexcept
    {
        return _rawPtr;
    }

private:
    void copyFromOther(const SharedPtr<T> &other) noexcept
    {
        _counter = other._counter;
        _rawPtr = other._rawPtr;
    }

    void decrementRefCount() noexcept
    {
        if (nullptr != _counter) {
            --*_counter;
            if (0 == *_counter)
                delete _rawPtr;
        }
    }

    void incrementRefCount() noexcept
    {
        if (nullptr != _counter)
            ++(*_counter);
    }

    void reset() noexcept
    {
        _counter = nullptr;
        _rawPtr = nullptr;
    }

    std::size_t *_counter;
    T *_rawPtr;
};

}//namespace ostd

#endif //OSTD_SHAREDPTR_H
