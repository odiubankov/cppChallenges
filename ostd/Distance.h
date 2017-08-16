/**
* Implementation of std::distance algorithm
* Usage of random access iterators in case of vector and forward iterator in other case
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

#ifndef OSTD_DISTANCE_H
#define OSTD_DISTANCE_H

#include <iterator>

namespace ostd
{

template<typename IteratorT, typename IteratorTraitT>
class _distance
{
public:
    _distance(const IteratorT &itFirst, const IteratorT &itSecond)
        : _val{0}
    {
        auto itFirstCopy = itFirst;
        while (itFirstCopy != itSecond) {
            ++itFirstCopy;
            ++_val;
        }
    }

    std::size_t get() const
    { return _val; }

private:
    std::size_t _val;
};

template<typename IteratorT>
class _distance<IteratorT, std::random_access_iterator_tag>
{
public:
    _distance(const IteratorT &itFirst, const IteratorT &itSecond)
        : _val{0}
    {
        _val = itSecond - itFirst;
    }

    std::size_t get() const
    { return _val; }

private:
    std::size_t _val;
};

template<typename IteratorT>
std::size_t Distance(const IteratorT &itFirst, const IteratorT &itSecond)
{
    return _distance<IteratorT, typename std::iterator_traits<IteratorT>::iterator_category>{itFirst, itSecond}.get();
}

}//namespace ostd

#endif //OSTD_DISTANCE_H
