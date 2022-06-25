#include <iostream>

class MyClass {
 public:
  MyClass() {
    data_ = 0;
    std::cout << "Default Constructor" << std::endl;
  }

  MyClass(int d) {
    data_ = d;
    std::cout << "Parameter Constructor" << std::endl;
  }

  MyClass(const MyClass &rhs) {
    data_ = rhs.data_;
    std::cout << "Copy Constructor" << std::endl;
  }

  MyClass &operator=(const MyClass &rhs) {
    data_ = rhs.data_;
    std::cout << "Copy Assignment" << std::endl;
    return *this;
  }

  ~MyClass() { std::cout << "Destructor" << std::endl; }
  int data_;
};

// //5.1:
// int main() {
//   MyClass o1;
//   MyClass o2(10);
//   MyClass o3 = o2;
//   MyClass o4;
//   o4 = o1;
//   return 0;
// }

// //5.2
// void MyFunction1(MyClass p) {
//   std::cout << "p.data_: " << p.data_ << std::endl;
//   p.data_ = 5;
//   MyClass temp = p;
//   temp.data_ = 6;
// }


// int main() {
//   MyClass o1;
//   MyFunction1(o1);
//   std::cout << "o1.data_: " << o1.data_ << std::endl;
// }

//5.3
void MyFunction2(MyClass &p) {
  std::cout << "p.data_: " << p.data_ << std::endl;
  p.data_ = 5;
  MyClass temp = p;
  temp.data_ = 6;
}


int main() {
  MyClass o2;
  MyFunction2(o2);
  std::cout << "o2.data_: " << o2.data_ << std::endl;
}