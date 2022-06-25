#include <iostream>
#include <vector>

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
  ListNode* GetBackPointer() {
            if (empty()){return head_;} //derefrencing p->next for an empty list would be segmentation fault
            ListNode* p = head_; //instantiate a pointer 'p' to a ListNode object, set equivalent to 'head_'.
            while ((*p).next != nullptr){ // how does .next even work??? Ask for clarification here!
                p = (*p).next; //or p->next
            }
            return p;
        }

  // Returns a pointer to the i(ith) item in the list. nullptr if i(th) item
  // doesn't exists.
  ListNode* GetIthPointer(int i) {
            if (empty()) {return head_;}
            ListNode* p = head_;
            int index = 0;
            while ((*p).next != nullptr){
                if (index == i) {break;}
                p = (*p).next;
                index++;
            }
            if (index < i){
                std::cout<<"Warning: supplied argument 'i' out of bounds, address of back element returned. "<<std::endl;
            }
            return p;
        }

  // Adds a new node with given value i at the end of the list and adjusts the
  // size_ and head_ correctly.
  void push_back(int i){
            if (empty()){
                head_ = new ListNode(i);
                return;
            }
            //if not empty, get back ptr, make new_node, deref backpointer and set next to new_node
            auto back_ptr = GetBackPointer(); //pointer to present end node (which itself points to nullptr)
            auto new_node = new ListNode(i); //instantiate new ListNode struct with data value 'i'
            back_ptr->next = new_node; //assign new ListNode struct to (*back_ptr).next
        }

  //-----------------------------------------------------------------------------
  // The following functions should be implemented by you!
  //-----------------------------------------------------------------------------
  // Removes a node from the back of the list and adjusts the size_ and head_
  // correctly.
  //
  // If the list was empty, returns false, otherwise returns true.
  bool pop_back(){
            if (empty()){return false;}
            ListNode* p = head_;
            ListNode* p_prev;
            while ((*p).next != nullptr) {
                p_prev = p;
                p = (*p).next;
            }
            (*p_prev).next = (*p).next;//the assumption here is that (*p).next is nullptr
            delete p;
            return true;
        }

  // Write a new parameterized constructor that takes a vector as an input and
  // crates a linked list based on that. Note that your constructor should
  // assign a valid data for head_. Example:
  // Input:  v = {1, 4, 5, 6, 10}
  // The created list: 1->4->5->6->10, and head_ will point to the first node
  // with data 1.
  SinglyLinkedList(const std::vector<int> &v);
  SinglyLinkedList(const std::vector<int> &v): head_(ListNode* (v[0])), size_(v.size()) {}
  SinglyLinkedList(const std::vector<int> &v) {
    // std::vector<int> *p = &v;
    // head_ = v[0];
    
  }

  // Write a function that converts the list into a vector. Example:
  // The list: 1->4->5->6->10
  // Output: a vector with data: {1, 4, 5, 6, 10}
  std::vector<int> ConvertToVector();
  std::vector<int> ConvertToVector() {
    std::vector<int> v_res(size_);

  }

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