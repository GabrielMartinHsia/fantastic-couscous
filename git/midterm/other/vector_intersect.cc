//2022.06.02 Discussion 3
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int> &v1, vector<int> &v2) {

    unordered_map<int, int> dict;
    vector<int> res;

    for (int i=0; i<v1.size(); i++){
        dict[v1[i]]++;
    }

    for (int i=0; i<v2.size(); i++){
        if (dict[v2[i]] > 0){
            res.push_back(v2[i]);
            dict[v2[i]]--;
        }
    }
    return res;
}

void PrintVector(vector<int> v){
    cout<<"{";
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"}"<<endl;
}

int main(){
    vector<int> v1, v2;
    v1 = {1,2,2,5,4,7,9,3};
    v2 = {3,6,9,8,3,4,1};
    auto v_intersect = intersect(v1, v2);
    PrintVector(v_intersect);
}