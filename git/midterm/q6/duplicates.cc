#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, int> counts_dict(const std::vector<int> &v, int k) {
    std::unordered_map<int, int> counts;
    for (int i=0; i<v.size(); i++) {
        counts[v[i]]++;
    }
    return counts;
}

std::vector<int> cut_duplicates(std::unordered_map<int, int> &m, int k){
    std::vector<int> result;
    for (auto e: m){
        if (e.second <= k){
            result.push_back(e.first);
        }
    }
    return result;
}

void PrintVector(const std::vector<int> &v){
    std::cout<<"{";
    for (int i=0; i<v.size(); i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<"}"<<std::endl;
}

void PrintDict(std::unordered_map<int, int> &map){
    for (auto e: map){
        std::cout<<"vector value: "<<e.first<<", ";
        std::cout<<"count: "<<e.second<<std::endl;
    } 
}

int main() {
    std::vector<int> v = {1,2,2,2,2,1,7,3,3,6,4,1,3,1};
    int k = 2;
    std::unordered_map<int, int> c_map = counts_dict(v,k);
    PrintDict(c_map);
    std::vector<int> result = cut_duplicates(c_map, 2);
    PrintVector(result);
    return 0;
}