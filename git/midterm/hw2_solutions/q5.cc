#include <iostream>
#include <vector>

// concatenate two dynamic arrays.
// for example:
// array_1 = {1, 2}, size_1 = 2
// array_2 = {2, 3, 4}, size_12 = 3
// Output: {1, 2, 2, 3, 4}.
// Question 1: Why did we have to provide size_1, size_2 as an input?
// Question 2: How can we know the size of the output?

int* ConcatenateArrays(int* array_1, int size_1, int* array_2, int size_2){
    int size = size_1 + size_2;
    int* result = new int[size];

    for (int i=0; i<size_1; i++){
        result[i] = array_1[i];
    }

    for (int i=0; i<size_2; i++){
        result[i + size_1] = array_2[i];
    }
    return result;
}

// Concatenate two dynamic vectors.
// Example:
// vector_1 = {1, 2}
// vector_2 = {2, 3, 4}
// Output: {1, 2, 2, 3, 4}.
// Question 1: Why didn't we provide the sizes?
// Question 2: We have two functions with the name of Concatenate. Is this ok?

std::vector<int> ConcatenateVectors(std::vector<int> v1, std::vector<int> v2){
    std::vector<int> result;
    for(auto e : v1){
        result.push_back(e);
    }
    for(auto e : v2){
        result.push_back(e);
    }
    return result;
}

void PrintArray(int arr[], int size){
    std::cout<<"your array: [";
    for (int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void PrintVector(std::vector<int> v){
    std::cout<<"your vector: {";
    for (auto e : v){
        std::cout << e << " ";
    }
    std::cout<<"}"<<std::endl;
}

int main(){
    int a1[] = {1,2,4,7,0};
    int a2[] = {3,7,5,2};
    int* a_conc = ConcatenateArrays(a1, 5, a2, 4);
    PrintArray(a_conc, 9);

    std::vector<int> v1 = {1,2,4,5,0};
    std::vector<int> v2 = {3,7,5,2};
    std::vector<int> v_conc = ConcatenateVectors(v1,v2);
    PrintVector(v_conc);
}