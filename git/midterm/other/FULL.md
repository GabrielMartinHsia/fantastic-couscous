Skip to content

4/11 Questions Answered
Saved at 9:50 PM
< 90 minutes remaining
Your answers will be submitted automatically when time expires.
Midterm
Q1 Honor Question (Easy - Required)
1 Point

You ARE allowed to consult the following resources when working on the exam:

    Notes you took in the class including any slides from the class
    The textbooks
    Your own code from the assignments
    C++ and STL Documentations: http://en.cppreference.com

    You MAY NOT collaborate with anyone else on this exam. This means you cannot talk to anyone else about the exam until after the exam deadline.
    You MAY NOT attempt to check the answers online.

    You can use any text editor to write your code in first and then paste into Gradescope. 
    You can use Visual Studio Code and Bazel to compile and test your code. 
    You can use any STL function or container.

The exam has a total of 125 points. 100 is considered full credit.

I affirm I have read these exam rules and will follow them. Failure to do so may subject me to sanctions including an F in the course.
Type your full name to affirm you have read the above statement:
Gabriel Lewis Martin-Hsia
Gabriel Lewis Martin-Hsia

Your code should be readable: please format your code and add comments to explain what you are doing. 
(Please write "I will format my code, make it readable, and will add comments" in this box):
I will format my code, make it readable, and will add comments
I will format my code, make it readable, and will add comments
Q2 Concept Questions: Easy
10 Points

Answer the following questions:
1. What are the main difference between std::vector and std::list?
2. Why would one prefer using std::stack over std::vector?
3. Why would one prefer using std::vector over dynamic array?
4. In C++ one can pass-by-reference a parameter by using a C++ reference or a C++ const reference. Please explain the pros and cons for each case.
5. What is an initialization list in a constructor and why is it preferred?
# 1.
What are the main differences between vecotrs and lists:

## `std::vector`:
* guaranteed contiguous memory locations
* indexing `i`th element is fast, with runtime complexity $O(1)$, since we are able to simply add `i` to the index of the first vector element.
* size does not need to be known at compile time.
* can use `push_back()` to dynamically insert new values into a vector. Generally, this requires the entire vector to be completely re-allocated (copied from one location to another) to a location where an adequate number of contiguous addresses are available. Despite this, with amortization techniques, this operation can be completed with a runtime complexity of O(1) on average.
* inserting/removing arbitrary values from a vector has runtime complexity of O(n). This is slower than for std::list, which is O(1).
* methods include push_back(), pop_back(), insert(), erase()

## `std::list`:
* elements are stored in non-contiguous memory locations, so indexing them is slow. Rather than simply adding the index to the head pointer like we would with `std::vector`, we have to traverse all elements between the beginning of the list and the `i`th element to index it.
* Indexing the `i`th element is slow, with runtime complexity of O(n)
* However, once indexed, insert/delete is fast, with runtime complexity of O(1).
* Methods include empty(), size(), insert(), erase(), front(), back(), push_front(), pop_front(), push_back(), pop_back()

# 2. 
Why might we prefer std::stack over std::vector?

In general, stack is less versatile than vector. We cannot iterate through its elements the way we can with vector, and access adheres to strict first-in, first-out ordering, so we can only ever access its rear (last) element. In cases where such restrictions are necessary to ensure expected behavior, using std::stack can be advantageous. 

# 3. 
Why would one prefer using std::vector over dynamic array?

While vectors and arrays are both stored in contiguous memory locations (and therefore quickly indexed at O(1)), in general, a vector will be more versatile than a dynamic array. Though dynamic arrays need not have their sizes set at compile time, their sizes cannot be changed once set at runtime. Vector sizes are truly dynamic with the push_back method.

# 4. 
In C++ one can pass-by-reference a parameter by using a C++ reference or a C++ const reference. Please explain the pros and cons for each case.

* pass by reference fn(type &arg) allows the original argument, initialized outside the scope of the function, to be changed. This can be advantageous in cases where multiple items need to be returned by a function (we are only allowed a single 'return' statement for any function). If we want to output 3 values, we can initialize them outside the scope of the function, pass them each by reference to the function, and any manipulations on their references inside the function will take effect on the original variables as well.

* passing by const reference fn(const type &arg) ensures the values of the variables outside the scope of the function are *not* changed. This is advantageous in the event that we have a vector or array or other large entity to pass to our function that we do *not* want to have changed outside the scope of the function. The advantage is that we are still passing by reference, so we do not need to *copy* the original data into the scope of the function, which can be extremely costly. This way you keep your variables safe outside the scope of the function, but can manipulate the values inside the function without copying them.

# 5. 
What is an initialization list in a constructor and why is it preferred?

An initialization list is one way to initialize the attributes of an instance of a class object in the constructor, the alternative being to simply initialize them in the body of the constructor. The constructor can be either parameterized (user inputs attribute values) or non-parameterized (any required attributes are set as defaults, without any user input required). Using an initialization list can be more efficient than assigning attributes in the body of the constructor, allowing the compiler to construct the data in one pass, in the order provided.
# 1.
What are the main differences between vecotrs and lists:

## `std::vector`:
* guaranteed contiguous memory locations
* indexing `i`th element is fast, with runtime complexity $O(1)$, since we are able to simply add `i` to the index of the first vector element.
* size does not need to be known at compile time.
* can use `push_back()` to dynamically insert new values into a vector. Generally, this requires the entire vector to be completely re-allocated (copied from one location to another) to a location where an adequate number of contiguous addresses are available. Despite this, with amortization techniques, this operation can be completed with a runtime complexity of O(1) on average.
* inserting/removing arbitrary values from a vector has runtime complexity of O(n). This is slower than for std::list, which is O(1).
* methods include push_back(), pop_back(), insert(), erase()

## `std::list`:
* elements are stored in non-contiguous memory locations, so indexing them is slow. Rather than simply adding the index to the head pointer like we would with `std::vector`, we have to traverse all elements between the beginning of the list and the `i`th element to index it.
* Indexing the `i`th element is slow, with runtime complexity of O(n)
* However, once indexed, insert/delete is fast, with runtime complexity of O(1).
* Methods include empty(), size(), insert(), erase(), front(), back(), push_front(), pop_front(), push_back(), pop_back()

# 2. 
Why might we prefer std::stack over std::vector?

In general, stack is less versatile than vector. We cannot iterate through its elements the way we can with vector, and access adheres to strict first-in, first-out ordering, so we can only ever access its rear (last) element. In cases where such restrictions are necessary to ensure expected behavior, using std::stack can be advantageous. 

# 3. 
Why would one prefer using std::vector over dynamic array?

While vectors and arrays are both stored in contiguous memory locations (and therefore quickly indexed at O(1)), in general, a vector will be more versatile than a dynamic array. Though dynamic arrays need not have their sizes set at compile time, their sizes cannot be changed once set at runtime. Vector sizes are truly dynamic with the push_back method.

# 4. 
In C++ one can pass-by-reference a parameter by using a C++ reference or a C++ const reference. Please explain the pros and cons for each case.

* pass by reference fn(type &arg) allows the original argument, initialized outside the scope of the function, to be changed. This can be advantageous in cases where multiple items need to be returned by a function (we are only allowed a single 'return' statement for any function). If we want to output 3 values, we can initialize them outside the scope of the function, pass them each by reference to the function, and any manipulations on their references inside the function will take effect on the original variables as well.

* passing by const reference fn(const type &arg) ensures the values of the variables outside the scope of the function are *not* changed. This is advantageous in the event that we have a vector or array or other large entity to pass to our function that we do *not* want to have changed outside the scope of the function. The advantage is that we are still passing by reference, so we do not need to *copy* the original data into the scope of the function, which can be extremely costly. This way you keep your variables safe outside the scope of the function, but can manipulate the values inside the function without copying them.

# 5. 
What is an initialization list in a constructor and why is it preferred?

An initialization list is one way to initialize the attributes of an instance of a class object in the constructor, the alternative being to simply initialize them in the body of the constructor. The constructor can be either parameterized (user inputs attribute values) or non-parameterized (any required attributes are set as defaults, without any user input required). Using an initialization list can be more efficient than assigning attributes in the body of the constructor, allowing the compiler to construct the data in one pass, in the order provided.
Q3 Help Bobby Bruin!
24 Points

Mr. Bobby Bruin wrote some code. For each case below, please specify:
1. What is wrong or can go wrong.
2. How the code can be improved or fixed.
Q3.1 String Comparison: Easy
14 Points

Bobby wrote this function to compare two strings ignoring the case.

// It should return true if v1 and v2 are equal ignoring the case and false
// otherwise.
bool CompareStringsCaseInsensitive(const std::string& v1,
                                   const std::string& v2) {
  for (int i = 0; i < v1.size(); i++) {
    if (std::tolower(v1[i]) != std::tolower(v2[i])) {
      return false;
    }
  }
  return true;
}

The code sometimes work, but sometimes crashes on his laptop.

    Provide a sample input for v1 and v2 that might crash the program.
    Provide a sample input for v1 and v2 that will not crash but will produce incorrect output.
    Rewrite the code for Bobby to be crash-free and always produce the correct result.

One thing that is wrong here is that we are using the size of the first string as our basis of iteration, without regard to the size of the second. 

1. If the first string is longer than the second, once the index `i` moves past the end of the second string and we try to access v2[i], this is an unknown memory location. Accessing such a memory location can cause undefined behavior. For instance, s1="cats" and s2="cat" could cause such a problem.

2. If the second string is longer than the first, but all of the characters in the string up to this length are the same, it will produce true, even if the second string continues. For example, s1="cat" and s2="cats" will yield true incorrectly.

3. To fix this, we can insert this line at the beginning of the function to check that the inputs are the same size. If they are not, immediately return false.

if (v1.size() != v2.size()){return false;} 

So, all together it would be:

bool CompareStringsCaseInsensitive(const std::string& v1,
                                   const std::string& v2) {
  if (v1.size() != v2.size()){return false;}  //check that inputs are same length                                 
  for (int i = 0; i < v1.size(); i++) {
    if (std::tolower(v1[i]) != std::tolower(v2[i])) {
      return false;
    }
  }
  return true;
}

One thing that is wrong here is that we are using the size of the first string as our basis of iteration, without regard to the size of the second. 

1. If the first string is longer than the second, once the index `i` moves past the end of the second string and we try to access v2[i], this is an unknown memory location. Accessing such a memory location can cause undefined behavior. For instance, s1="cats" and s2="cat" could cause such a problem.

2. If the second string is longer than the first, but all of the characters in the string up to this length are the same, it will produce true, even if the second string continues. For example, s1="cat" and s2="cats" will yield true incorrectly.

3. To fix this, we can insert this line at the beginning of the function to check that the inputs are the same size. If they are not, immediately return false.

if (v1.size() != v2.size()){return false;} 

So, all together it would be:

bool CompareStringsCaseInsensitive(const std::string& v1,
                                   const std::string& v2) {
  if (v1.size() != v2.size()){return false;}  //check that inputs are same length                                 
  for (int i = 0; i < v1.size(); i++) {
    if (std::tolower(v1[i]) != std::tolower(v2[i])) {
      return false;
    }
  }
  return true;
}

Q3.2 Finding Errors: Easy
10 Points

Bobby was practicing the usage of pointers and wrote the following function:

#include <iostream>
void PrintGrade() {
  int* p;

  {
    int grade;
    p = &grade;
    std::cin >> grade;
  }

  std::cout << "*p: " << *p << std::endl;
}

What is wrong with the above code and how can you fix it?
//The data type is incorrect. Use char instead of int, like this:
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
//The data type is incorrect. Use char instead of int, like this:
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
Q4 Implement the Linked List Class: Medium
37 Points

Given are the following class declarations:

// A struct to store statistical values.
struct Statistics {
  int minimum;
  int maximum;
  float total;
  float average;
};

// A single node in the linked list.
struct ListNode {
  int data;
  ListNode *next;
  ListNode(int x) : data(x), next(nullptr) {}
};

// The linked list class.
class SinglyLinkedList {
 public:
  // Member variables
  ListNode *head_;
  int size_;

  //-----------------------------------------------------------------------------
  // These functions are already implemented. No need to change them.
  //-----------------------------------------------------------------------------
  SinglyLinkedList() : head_(nullptr), size_(0) {}
  bool empty() { return head_ == nullptr; }
  int size() { return size_; }

  //-----------------------------------------------------------------------------
  // Assume the following functions are implemented. You can use them without
  // implementing them.
  //-----------------------------------------------------------------------------
  // Returns a pointer to the last item in the list. nullptr if the list is
  // empty.
  ListNode *GetBackPointer();

  // Returns a pointer to the i(ith) item in the list. nullptr if i(th) item
  // doesn't exists.
  ListNode *GetIthPointer(int i);

  // Adds a new node with given value i at the end of the list and adjusts the
  // size_ and head_ correctly.
  void push_back(int i);

  //-----------------------------------------------------------------------------
  // The following functions should be implemented by you!
  //-----------------------------------------------------------------------------
  // Removes a node from the back of the list and adjusts the size_ and head_
  // correctly.
  //
  // If the list was empty, returns false, otherwise returns true.
  bool pop_back();

  // Write a new parameterized constructor that takes a vector as an input and
  // crates a linked list based on that. Note that your constructor should
  // assign a valid data for head_. Example:
  // Input:  v = {1, 4, 5, 6, 10}
  // The created list: 1->4->5->6->10, and head_ will point to the first node
  // with data 1.
  SinglyLinkedList(const std::vector<int> &v);

  // Write a function that converts the list into a vector. Example:
  // The list: 1->4->5->6->10
  // Output: a vector with data: {1, 4, 5, 6, 10}
  std::vector<int> ConvertToVector();

  // Write the following function which iterates through the list and returns a
  // variable of type Statistics which has the correct value for the items in
  // the list (minimum, maximum, total sum, and average)
  //
  // If empty, the result minimum should be INT_MAX, the result maximum should
  // be INT_MIN, the total sum should be 0, and the average should be 0.
  //
  // You can assume that the total sum of all numbers in the linked list fits
  // inside an integer.
  Statistics CalculateStatistics();
};

Q4.1 pop_back- Medium
12 Points

Please provide at two sample input and outputs for pop_back. Include the following cases:

    Corner cases
    Other cases

Implement 

bool SinglyLinkedList::pop_back();

Q4.2 Parameterized constructor- Medium
5 Points

Implement the parameterized constructor 

SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v)

Q4.3 ConvertToVector- Medium
10 Points

Implement 

std::vector<int> SinglyLinkedList::ConvertToVector();

Q4.4 CalculateStatistics - Medium
10 Points

Implement 

Statistics SinglyLinkedList::CalculateStatistics();

Q5 WordHistogram: Medium
28 Points

Given a string, you are asked to create a histogram of all the words
that appear in that string.

Assumption: The given text only has the following characters:

    lower case alphabetic characters, i.e. 'a' to 'z'
    Dot, comma and space, i.e.: '.', ',',  ' '

There are no other characters in the input
text, i.e. it does not have any new lines, tab, numbers, etc.

Example 1: 
Input: "this is a test, and this is another one."

Output (map of std::string to int): 
{ {"a", 1},
  {"and", 1},
  {"another", 1},
  {"is", 2},
  {"one", 1},
  {"test", 1},
  {"this", 2}
}

👉 Note: the only function from std:: that you can use is std::find. No other std:: functions are allowed!
Q5.1
28 Points

Please provide at least four other sample input and outputs for this function. Include the following cases:

    Empty case
    Corner cases
    Easy cases
    Harder cases

Implement this function:

std::map<std::string, int> WordHistogram(std::string &text);

What is the runtime complexity of your implementation?
Q6 String Processing - Recursion: Medium
24 Points

Given are the Command class which is an enum class and Result class:

enum class Command { kNumberOfVowels, kCheckSum };

struct Result {
  char checksum;
  unsigned int number_of_vowels;
  Result() : checksum('0'), number_of_vowels(0) {}
};

Write a function called StringProcessor (see the exact signature in the subquestion below) that takes a string and a variable of type Command as inputs.

    If command is kNumberOfVowels, it counts the number of vowels and stores the result in number_of_vowels
    member of a variable of type Result. Vowels are: 'a', 'e', 'i', 'o', 'u'.
    Example: input = "tester", output: result.number_of_vowels = 2.
    If command is kCheckSum, it calculates the checksum and stores the result in checksum
    member of a variable of type Result.
    Example: input = "tes", output: result.checksum = 't' ^ 'e' ^ 's'.

Note that the checksum of a string is a character whose
binary value is equal to the bitwise XOR of all characters in the given string.
Q6.1
24 Points

Please provide at least four sample input and outputs for this function for each possible values of Command. Include the following cases:

    Empty case
    Corner cases
    Easy cases
    Harder cases

Implement this function:

Result StringProcessor(std::string &text, Command command);

👉 Notes:
1. Your function should be implemented recursively. You are NOT allowed to
use any loops (i.e. no for or while loops).

    The only functions from std:: that you can use are std::find,
    std::tolower, and std::toupper. No other std:: functions are allowed.

👉 Hints:
1. Create a helper function and call it IsVowel whose input is a character
and its output is a boolean. It returns true if the input character was a
vowel and false otherwise.

    For your recursive function, you can break the given string from the
    middle and calculate the result on each half first and then combine them
    together. Make sure that you define your base cases first.
    Test if your implementation works for a string of both odd and even size.

What is the runtime complexity of your function?

    Is there any benefit in making the text parameter const?
    Is there any potential harm in making the command parameter a reference, but not const?

Q7 Testing your implementations
1 Point

Did you remember to test all of your function implementations for some sample input/outputs to make sure your answer is correct?
Choice 1 of 2: yesChoice 2 of 2: no
Submit & View Submission 