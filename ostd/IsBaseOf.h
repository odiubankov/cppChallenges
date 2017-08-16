/**
* Check if one type is a parent(base) type of another(daughter) type
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


#ifndef OSTD_ISBASEOF_H
#define OSTD_ISBASEOF_H

namespace ostd
{

template<typename T, typename BaseT>
class IsBaseOf
{
    struct Yes
    {
        char y;
    };
    struct No
    {
        char n[2];
    };

    static Yes f(BaseT *);
    static No f(...);

public:
    enum
    {
        Value = sizeof(f(static_cast<T *>(nullptr))) == sizeof(Yes)
    };
};

}//namespace ostd


#endif //OSTD_ISBASEOF_H
