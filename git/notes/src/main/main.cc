//2022_06_02 Discussion3

#include <iostream>
#include <unordered_map>
#include <vector>
#include "src/lib/cpplib.h"

using namespace std;

vector<int> intersect(vector<int> &v1, vector<int> &v2) //pass by reference so you can drop elements as you go...
{
    unordered_map<int, int> dict;//like a python dict, whose values we can increment to count instances of ints in v1 & v2
    vector<int> res;

    for (int i=0; i<v1.size(); i++)
    {
        dict[v1[i]]++; //increment value of dict whose key is v1[i]
    }

    for (int i=0; i<v2.size(); i++)
    {
        if (dict[v2[i]] > 0) //if v2[i] is already in dict, it's in v1, therefore comprises intersection of v1 & v2.
            res.push_back(v2[i]);
            dict[v2[i]]--;
    }

    return res;
}

int main()
{
    CPPLib s;
    vector<int> v1 = {1,2,3,4};
    vector<int> v2 = {6,5,4,3,3,2};
    vector<int> vres = s.intersect(v1, v2);
    for (auto i : vres)
        cout<<i<<" ";
    cout<<endl;

    cout<<"all finished"<<endl;

    // std::vector<char> v(1);
    // std::cout << v[100] << std::endl;

    return 0;
}