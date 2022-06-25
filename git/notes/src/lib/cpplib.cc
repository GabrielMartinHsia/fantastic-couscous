#include <iostream>
#include <unordered_map>
#include <vector>
#include "cpplib.h"

using namespace std;

vector<int> CPPLib::intersect(vector<int> &v1, vector<int> &v2) //pass by reference so you can drop elements as you go...
{
    unordered_map<int, int> dict;
    vector<int> res;

    for (int i=0; i<v1.size(); i++)
    {
        dict[v1[i]]++;
    }

    for (int i=0; i<v2.size(); i++)
    {
        if (dict[v2[i]] > 0)
            res.push_back(v2[i]);
            dict[v2[i]]--;
    }

    return res;
}