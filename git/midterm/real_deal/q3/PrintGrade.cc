#include <iostream>
void PrintGrade() {
  char* p;

  {
    char grade;
    p = &grade;
    std::cin >> grade;
  }

  std::cout << "*p: " << *p << std::endl;
}


int main(){
    PrintGrade();
    return 0;
}

