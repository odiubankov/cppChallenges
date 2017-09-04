/**
* Playing around with SFINAE
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

#ifndef EFFECTIVECPP_UNIVREFOVERLOAD_H
#define EFFECTIVECPP_UNIVREFOVERLOAD_H

#include <string>

namespace effectivecpp
{

class Base
{
public:
    Base(int, int)
    {}

    explicit Base(const std::string&)
    {}
};

class DerivedSFINAE: public Base
{
public:
    template<
        typename T,
        typename... Args,
        typename = typename std::enable_if_t<!std::is_same<DerivedSFINAE, typename std::decay_t<T>>::value>>
    explicit DerivedSFINAE(T &&arg, Args &&... args)
        : Base{std::forward<T>(arg), std::forward<Args>(args)...}
    {
        _forwardConstructorIsCalled = true;
    }

    bool _forwardConstructorIsCalled{false};
};

}//namespace effectivecpp

#endif //EFFECTIVECPP_UNIVREFOVERLOAD_H
