#ifndef MEYERSEXAMPLES_UNIVREFOVERLOAD_H
#define MEYERSEXAMPLES_UNIVREFOVERLOAD_H

#include <string>
#include <iostream>

namespace item27{

    class Base
    {
    public:
        Base(int, int);
        Base(std::string);

    };


    class Derived : public Base
    {
    public:
        template<
                typename T,
                typename... Args,
                typename = typename std::enable_if_t<!std::is_same<Derived, typename std::decay_t <T>>::value>>
        Derived(T&& arg, Args&&... args)
        : Base{std::forward<T>(arg), std::forward<Args>(args)...}
        {
            std::cout << "Derived perfect forwarding constructor" << std::endl;
        }
    };


    void test();

}//namespace item27

#endif //MEYERSEXAMPLES_UNIVREFOVERLOAD_H
