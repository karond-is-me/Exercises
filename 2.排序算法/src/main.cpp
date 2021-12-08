#include <iostream>
#include <fstream>
#include <random>
#include "global.h"
#include "n2.h"


int main(int argc, char** argv)
{
    // vector<int> num_list{-412,3,51,6,-1,-21,54,34,-155,45,23,54,76,34,3,-777};
    std::vector<int> num_list;
    std::uniform_int_distribution<signed> u(-2000000,2000000);
    std::default_random_engine e;
    std::ofstream file;
    file.open("random_list.txt");
    int n;
    for (int i = 0;i<10000;i++)
    {
        n = u(e);
        num_list.push_back(n);
        file << n <<std::endl;
    }
    file.close();
    {
        auto result_list = num_list;
        Timer t;
        bubble_sort(result_list);
        t.printDiff("n2:");
        // for (auto &i : result_list){
        //     cout << i << " ";
        // }
    }
    {
        auto result_list = num_list;
        Timer t;
        selection_sort(result_list);
        t.printDiff("n2:");
        // for (auto &i : result_list){
        //     std::cout << i << " ";
        // }
    }
    {
        auto result_list = num_list;
        Timer t;
        selection_sort2(result_list);
        t.printDiff("n2:");
        // for (auto &i : result_list){
        //     std::cout << i << " ";
        // }
    }
    return 0;
}