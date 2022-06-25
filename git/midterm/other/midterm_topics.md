# Midterm Topics:

* Runtime complexity.
* Proof by induction.
* STL Data structures: e.g. queue, stack, vector, list, map, set.
* Pointers and references.
* Linked list implementation.
* C++ class definition: constructor, destructor, copy constructor, etc.
* STL functions such as transform, copy_if, and accumulate.
* No questions about GTest will be in the exam.
* Unless specified, you are allowed to use any STL function or data structure from std::.

## 1. Runtime Complexity
... See Lecture 1, Slides 39+ ...

## 2. Proof By Induction
... See Lecture 1, Slide 27, 28 ...
* importance of systematic testing, example uses two different input vectors with (i+1)th element changed to swap result.

## 3. STL Data Structures
For example:
* queue
* stack
* vector
* list
* map (& unordered_map)
* set (& unordered_set)

### 3.1 Queue
Like a vector, but we can always *only* access its first (front) and last (rear) elements.
* First-In, First-Out (think comm link buffer)
* Cannot iterate all of its elements, so, no begin and no end.
Methods include:
- empty()
- size()
- front(): read front
- push(): push into rear
- pop(): pop from front
Homework:
* write a function to print a queue (done, see queue.cc in this folder)
### 3.2 Stack (ref L4, Slide 13)
Like a vector, but *we can ONLY access its LAST element.* 
* Last-In, First-Out ordering
* Cannot iterate all of its elements, which means there is **NO .begin** and **NO .end**.
Methods include:
- empty()
- size() ... interesting; can't iterate all its elements, but we *do* know how many it has
- top()
- push()
- pop()
WORRY ABOUT:
* Don't `top()` or `pop()` when the stack is *empty*!!! ... you'd be deleting from an undefined location. UB!!!
* Don't `push()` when the stack is *full*!!! ... stack overflow. How do we know when the stack is full???
### 3.3 Vector
I think we're pretty good here... push_back() is neat. Read more about it in your notes repo.

### 3.4 List (L4, Slide 16) (2022/06/17 1:08)
We'll talk about this for the next half hour, and then discover that using this data structure is POINTLESS.
* similar to vectors in that lists are collections of objects of the same type.
* UNLIKE vectors in that elements are NOT stored at contiguous memory locations.
... so then, how do I find locations of elements if I can't just add number of addresses to move (like in a vector)? 
LINKED LIST:
Each node in a list carries a pointer to the *next* node in the list.

What is good about this?

* What is the runtime of inserting/removing to some arbitrary location (as opposed to the last position, which would be, on average, $O(1)$) in a VECTOR:
- $O(n)$, because we have to copy the whole vector to a new block of contiguous addresses sans/including newly deleted/inserted element.

However, in a list, all we have to do is change where one pointer is pointing, so insertion/deletion of an arbitrary element in a *list* is only $O(1)$.

`std::list` CHARACTERISTICS:

No contiguous memory locations, therefore:
* no indexing operator
* SLOW INDEXING: $O(n)$ (versus vectors, which index at $O(1)$)
* FAST insert/delete (at arbitray location): $O(1)$ (versus vectors, which are $O(n)$ for insert/delete)
* you should almost NEVER use `std::list` because of cache.
Lists CAN be iterated...

`std::list` METHODS:
* empty()
* size()
* insert(), erase()
* front(), back()
* push_front(), pop_front()
* push_back(), pop_back()

To implement lists *without* use of the standard library... see `linked_list.cc` activity, here, and in `cpp_tour`

METHODS DISCUSSED:
* print all items in a list
* get the tail pointer
```cpp
ListNode* p;
while(p != nullptr){
    p_prev = p;
    p = p->next;
}
```
... which optimizes as:
```cpp
ListNode* p;
while(p->next != nullptr){
    p = p->next;
}
```
* get `i`th item in a list (run a counter as you traverse the list...MIDTERM FLAG 1:30)
"... basically, you are creating an index. You are moving p from beginning to end, once you get to the counter, return it. But there's a danger that your list ends before you get to the counter(???), right? so in that case maybe return `nullptr` or an error... (???) Make sure in that case you do not generate UNDEFINED BEHAVIOR. ... YOU MIGHT SEE SOMETHING LIKE THIS IN YOUR MIDTERM EXAM."
### 3.5 Map (& unordered_map)
... see Lecture 3 slide 15

### 3.6 Set (& unordered_set)
... see Lecture 3 slide 16

## 4. Pointers and References
* Pointers: see Lecture 2, slide 15...
* References: see Lecture 2, slide 18 ...
* Note: Enum Class is also in Lecture 2, at slide 11 ... good for color pallettes, hw2 problem3, etc.

## 5. Linked List Implementation
check out `//q7/linked_list.cc` ... no unit tests (just running through local main()), but the class and methods seeem to be working pretty well.

## 6. C++ Class Definition
... Lecture 3, slide 33

## 8. STL Functions (ref L3 s26)
... such as `transform`, `copy_if`, and `accumulate`
... Only `accumulate` sounds familiar here. Let's review...


