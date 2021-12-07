#include <iostream>
#include <fstream>
#include <random>
#include "n2.h"
#include "n.h"
#include "nlogn.h"
using namespace std;

int main(int argc, char** argv)
{
    // vector<int> num_list{-412,3,51,6,-1,-21,54,34,-155,45,23,54,76,34,3,-777};
    vector<int> num_list;
    uniform_int_distribution<signed> u(-20,20);
    default_random_engine e;
    ofstream file;
    file.open("random_list.txt");
    int n;
    for (int i = 0;i<80;i++)
    {
        n = u(e);
        num_list.push_back(n);
        file << n <<endl;
    }
    file.close();
    {
        Timer t;
        std::unique_ptr<Result> iret = n2search(num_list);
        t.printDiff("n2: ");
        cout << iret->max << " " << iret->begin << " " << iret->end <<endl;
    }
    {
        // 这种实现有错误
        Timer t;
        std::unique_ptr<Result> iret = nlognsearch(num_list);
        t.printDiff("nlogn: ");
        cout << iret->max << " " << iret->begin << " " << iret->end <<endl;
    }
    {
        Timer t;
        std::unique_ptr<Result> iret = nsearch(num_list);
        t.printDiff("n: ");
        cout << iret->max << " " << iret->begin << " " << iret->end <<endl;
    }
    return 0;
}
