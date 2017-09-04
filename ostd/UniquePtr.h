/**
* Unique pointer implementation
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

#ifndef OSTD_UNIQUEPTR_H
#define OSTD_UNIQUEPTR_H

#include <memory>
#include <cassert>

namespace ostd
{

template<typename T>
class UniquePtr
{
public:
    UniquePtr() noexcept
        : _rawPtr{nullptr}
    {}

    explicit UniquePtr(T *rawPtr) noexcept
        : _rawPtr{rawPtr}
    {}

    UniquePtr(UniquePtr<T> &&other) noexcept
        : _rawPtr{other._rawPtr}
    {
        other._rawPtr = nullptr;
    }

    UniquePtr<T> &operator=(UniquePtr<T> &&other) noexcept
    {
        reset();
        _rawPtr = other._rawPtr;
        other._rawPtr = nullptr;
        return *this;
    }

    ~UniquePtr()
    {
        reset();
    }

    UniquePtr(const UniquePtr<T>&) = delete;
    UniquePtr<T>& operator=(const UniquePtr<T>&) = delete;

    T *get() const noexcept
    {
        return _rawPtr;
    }

    void reset() noexcept
    {
        if (nullptr != _rawPtr) {
            delete _rawPtr;
            _rawPtr = nullptr;
        }
    }

    T *release() noexcept
    {
        auto rawPtr = _rawPtr;
        _rawPtr = nullptr;
        return rawPtr;
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

private:
    T *_rawPtr;
};

}//namespace ostd

#endif //OSTD_UNIQUEPTR_H
