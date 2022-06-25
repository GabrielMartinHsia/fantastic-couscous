#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {};
    std::vector<int> *p = &v;
    std::cout<<"*v[0]: "<<p<<std::endl;

    return 0;

}

