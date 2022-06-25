//Q7 Given the following class definition, implement all the functions that are not already implemented.
#include <iostream>

struct ListNode {
    int val; //value to store at list location (node)
    ListNode* next; //pointer to next list location (node)
    ListNode(int x) : val(x), next(nullptr) {} //initialization list... user inputs int x, which is assigned to var. Pointer is set to nullptr.
};

class SinglyLinkedList{
    public:
        //member variable (object attribute). head pointer. points to first item in list.
        ListNode* head_;

        //already implemented ... in the struct above? No. Here, dummy. This note is just saying nothing more needs to be done here.
        SinglyLinkedList() {head_ = nullptr;} //non-parameterized constructor. Sets member variable "head_" to nullptr.

        //----------------------------------------------------------------------------
        //Implement the following functions
        //----------------------------------------------------------------------------
        //Returns true if the list is empty
        bool empty(){
           if (head_ == nullptr) {return true;}
           else return false;
        }

        //Returns the size of the list (note: no size_ variable exists)
        int size(){
            int count = 0;//list index
            if (empty()){return count;} //could specify SinglyLinkedList::empty(), but not necessary since empty() defined in class scope.
            ListNode* p = head_; //instantiate pointer to a ListNode struct. call it 'p'. set p = class attribute 'head_'.
            ListNode* p_prev; //initialize pointer to a ListNode struct. call it 'p_prev'.
            while (p != nullptr){ //if list is not empty, 'head_' will not be nullptr, so 'p' will not be nullptr.
                count++; //increment list index (captures size of list)
                p_prev = p; //assign present 'p' to 'p_prev' to move to next node
                p = p->next;//update 'p' to (*p).next ... so far, I've only seen 'nullptr' assigned to 'next'.
            }
            return count;
        }

        //returns pointer to last element in list
        ListNode* GetBackPointer() {
            if (empty()){return head_;} //derefrencing p->next for an empty list would be segmentation fault
            ListNode* p = head_; //instantiate a pointer 'p' to a ListNode object, set equivalent to 'head_'.
            while ((*p).next != nullptr){ // how does .next work??? 
                p = (*p).next; //or p->next
            }
            return p;
        }

        //returns pointer to address of ith list element
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

        //Adds a new item to the back of the list
        void push_back(int val){
            if (empty()){
                head_ = new ListNode(val);
                return;
            }
            //if not empty, get back ptr, make new_node, deref backpointer and set next to new_node
            auto back_ptr = GetBackPointer(); //pointer to present end node (which itself points to nullptr)
            auto new_node = new ListNode(val); //instantiate new ListNode struct with data value 'i'
            back_ptr->next = new_node; //assign new ListNode struct to (*back_ptr).next
        }

        //Adds a new item after the ith element of the list
        void insert_after(int val, int i) {
            if (empty()) {
                head_ = new ListNode(val);
                return;
            }
            auto ith_ptr = GetIthPointer(i);
            auto new_node = new ListNode(val);
            new_node->next = ith_ptr->next;
            ith_ptr->next = new_node;
        }

        //removes an item from the back of the list
        void pop_back(){
            if (empty()){
                std::cout<<"list empty, nothing to pop."<<std::endl;
                return;
            }
            ListNode* p = head_;
            ListNode* p_prev;
            while ((*p).next != nullptr) {
                p_prev = p;
                p = (*p).next;
            }
            (*p_prev).next = (*p).next;//the assumption here is that (*p).next is nullptr
            delete p;
        }

        //deletes ith argument from list
        void erase(int i) {
            if (empty()){
                std::cout<<"list empty, nothing to erase."<<std::endl;
                return;
            }
            ListNode* p = head_;
            ListNode* p_prev;
            int index = 0;
            while ((*p).next != nullptr) {
                if (index == i) {break;}
                p_prev = p;
                p = (*p).next;
                index++;
            }
            if (index < i) {
                std::cout<<"Warning: supplied argument 'i' out of bounds. Back list element deleted. "<<std::endl;
            }
            (*p_prev).next = (*p).next;
            delete p;
        }

        //prints list contents
        void print()
        {
            std::cout << "{";
            if (!empty())
            {
                ListNode *p = head_;
                ListNode *p_prev;
                while (p != nullptr)
                {
                    p_prev = p;
                    std::cout << (*p).val;
                    p = (*p).next;
                    if (p != nullptr) //if a value exists at p = p->next...
                    {
                        std::cout << ", ";
                    }
                }
            }
            std::cout << "}" << std::endl;
        }

    private:
};

int main(){
    auto my_list = SinglyLinkedList();
    my_list.print();
    std::cout<<"my_list back ptr: "<<my_list.GetBackPointer()<<std::endl;

    my_list.push_back(27);
    my_list.print();
    std::cout<<"my_list back ptr: "<<my_list.GetBackPointer()<<std::endl;

    my_list.push_back(42);
    my_list.print();
    std::cout<<"my_list back ptr: "<<my_list.GetBackPointer()<<std::endl;

    my_list.push_back(42943);
    my_list.print();
    std::cout<<"my_list back ptr: "<<my_list.GetBackPointer()<<std::endl;

    my_list.push_back(637);
    my_list.print();
    std::cout<<"my_list back ptr: "<<my_list.GetBackPointer()<<std::endl;

    my_list.pop_back();
    my_list.print();
    std::cout<<"my_list popped back ptr: "<<my_list.GetBackPointer()<<std::endl;

    std::cout<<"my_list ith ptr:  "<<my_list.GetIthPointer(16)<<std::endl;

    my_list.push_back(638);
    my_list.print();
    std::cout<<"my_list back ptr: "<<my_list.GetBackPointer()<<std::endl;

    my_list.erase(18);
    my_list.print();

    my_list.insert_after(237, 3);
    my_list.print();

    return 0;
}