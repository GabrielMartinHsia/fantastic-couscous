#include <iostream>
#include <stack>

int main(){
    std::stack<int> s;

    s.push(13);
    s.push(77);

    if (!s.empty()){
        int r = s.top();
        std::cout<<"present top of s: "<<r<<std::endl;
        s.pop();
        std::cout<<"top of s after pop: "<<s.top()<<std::endl;
    }

    std::cout<<"s.size(): "<<s.size()<<std::endl;

    return 0;
}
