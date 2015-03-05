#ifndef TESTER_H_
#define TESTER_H_

#include <utility>
#include <functional>
#include <iostream>
#include <string>
#include <stdexcept>

class assertion_failed: public std::runtime_error {
 public:
    assertion_failed(const std::string &expr,
                     const std::string &file, int line)
        : std::runtime_error("Assertion '" + expr + "' failed on " + file + ":" + 
                             std::to_string(line)) {}
};

template<const char *name>
struct caller {
    template<class T>
    caller(T fun) {
        try {
            std::clog << "Run " << name << "...";
            fun();
            std::clog << "\x1b[32;1mOK\x1b[0m" << std::endl;
        } catch (const std::exception &e) {
            std::clog << "\x1b[31;1mFAIL" << std::endl;
            std::clog << e.what() << "\x1b[0m" << std::endl;
        }
    }
};

#define CAT2(X, Y) X ## Y
#define CAT(X, Y) CAT(X, Y)
#define TEST(NAME) const char STR_ ## NAME[] = #NAME; \
                   caller<STR_ ## NAME> NAME = []
#define ASSERT(EXPR) if (!(EXPR)) throw assertion_failed(#EXPR, __FILE__, __LINE__);
                   
#endif  // TESTER_H_
