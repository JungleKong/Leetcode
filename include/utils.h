#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <list>
#include <deque>
#include <algorithm>

#include "mylist.h"
#include "mytree.h"

using namespace std;

template<class T>
void printVec(const std::vector<T>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << "\t";
        if (i % 10 == 9) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(int i = 0; i < vec.size(); ++i){
        os << vec[i] << "\t";
        if (i % 10 == 9) {
            os << std::endl;
        }
    }
    return os;
}
