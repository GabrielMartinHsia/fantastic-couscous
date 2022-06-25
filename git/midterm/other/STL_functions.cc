#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional> //std::function<...>
#include <algorithm> //std::count_if(...)

//Passing a Function as a Parameter:
float BinaryOperation(int a, int b, std::function<float(int, int)> fnc){
    return fnc(a,b);
}

float Add(int a, int b) {return a + b;}
float Mult(int a, int b) {return a * b;}
float Div(int a, int b) {
    if (b == 0) {throw std::invalid_argument("undefined. cannot divide by zero.");}
    return (float)a / (float)b;
}

//feed to std::count_if to count odds and evens in a vector...
bool IsOdd(int i) {return (i % 2) == 1;}
bool IsEven(int i) {return (i % 2) == 0;}

//will use with transform (map):
int IncrementByTen(int a) {return a + 10;}

//See practice midterm q4 for std::accumulate() example (tax calculator)
//...accumulate, aka, reduce...

//Prints vector of any class T elements.
template <class T>
void PrintVector(std::vector<T> input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

int main() {
    int sum = BinaryOperation(2,3, Add);
    std::cout<<"Add: "<<sum<<std::endl;

    int prod = BinaryOperation(2,3, Mult);
    std::cout<<"Prod: "<<prod<<std::endl;

    float quot = BinaryOperation(2,3, Div);
    std::cout<<"Div: "<<quot<<std::endl;

    //std::count_if(...) demo...
    std::vector<int> v = {1,1,2,4,3,9,6,7,45};
    int cnt_even = std::count_if(v.begin(), v.end(), IsEven);
    int cnt_odd  = std::count_if(v.begin(), v.end(), IsOdd);
    std::cout<<"cnt_even: "<<cnt_even<<std::endl;
    std::cout<<"cnt_odd:  "<<cnt_odd<<std::endl;

    //for std::transform() demo: (use 'v' above as inputs)
    std::vector<int> outputs(v.size()); //create an output vector same size as input vector 'v'.
    std::transform(v.begin(), v.end(), //now pass IncrementByTen as arg to std::transform()...
                   outputs.begin(), IncrementByTen);
    PrintVector(outputs);

    //for std::copy_if(...) demo:
    std::vector<int> odds(v.size());
    std::copy_if(v.begin(), v.end(),
                 odds.begin(), IsOdd);
    PrintVector(odds); //leaves dangling zeros 
                

}