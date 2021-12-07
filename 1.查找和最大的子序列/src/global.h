#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <chrono>
#include <iostream>

struct Result 
{
    int max;
    int begin;
    int end;
    Result(int max, int begin, int end):max(max), begin(begin),end(end){};
};
class Timer {
private:
    std::chrono::steady_clock::time_point last;
public:
    Timer() : last{std::chrono::steady_clock::now()} {
    }
    void printDiff(const std::string& msg = "Timer diff: ") {
        auto now{std::chrono::steady_clock::now()};
        std::chrono::duration<double, std::milli> diff{now - last};
        std::cout << msg << diff.count() << "ms\n";
        last = std::chrono::steady_clock::now();
    }
};


#endif