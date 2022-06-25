#include <iostream>
#include <queue>

void PrintQueue(std::queue<int> &q){
    std::vector<int> v;
    while (!q.empty()){
        v.push_back(q.front());
        q.pop();
    }
    std::cout<<"queue contents: {";
    for (auto e : v){
        std::cout<< e <<" ";
    }
    std::cout<<"}"<<std::endl;
}

int main(){
    std::queue<int> q;
    q.push(73);
    q.push(66);
    q.push(48);
    PrintQueue(q);
    return 0;
}