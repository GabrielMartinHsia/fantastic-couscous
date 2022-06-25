Oh, hello. I didn't see you there. Well, now that you're here, welcome to my notes. This will, more than likely, be a rambling and incoherent, stream-of-consciousness collection of thoughts and musings inspired by ee538 and all manner of who-knows-what I'm sure to stumble across on Stack Overflow along the way. There will be typos. There will be questions - rhetorical and otherwise. There will probably be swearing - I *do* work at a power plant after all, and I've picked up some ... habits. There will be tangents and thoughts right out of left field. Some of them might actually be worth considering - most of them, however, probably garbage. But all of this, I'm hoping, will help me learn to be somewhat fluent in C++.

Anyway, let's get started...

# 2022.05.20 (lecture 1):
## Bookmarks:
* `cpp-template` & `cpp_tour`: (0:17)
* compiled vs interpreted languages: (0:28)
* bazel (0:38)

## `cpp-template` & `cpp_tour`: (0:17)
* `cpp-template`: a repo you can use as a template to write your own cpp programs
* `cpp_tour`: a pretty comprehensive how-to repo with all kinds of good demos and examples

## compiled vs interpreted languages: (0:28)
What does a compiler do? It turns your program into executable machine language instructions that your CPU can understand. Not all CPUs are the same. You may have one built by intel, or apple, or AMD, etc. Each will have its own requirements/idyosyncracies. The compiled executable must cater to your specific type of CPU. So, you need to install a compiler that will produce executables your CPU will understand. Note the difference between compile time and runtime here. Before the program can *run*, it must be compiled into an executable. Once you have this executable, *that* is what the CPU is running at runtime. So, everything in your program must be "correct" at compile time. 

Interpreted languages, on the other hand, try to read through a program and execute it line-by-line. It's entirely possible for half of your program to be executed, and then at line, 1000 say, if finds something that isn't right and throws an error. Python is an example of an interpreted language. Interestingly, Python's interpreter is written in C++. So, since there is this intermediate layer of the interpreter that all the code must be processed through *at runtime*, interpreted languages like Python will be slower at runtime than compiled languages like C++.

## file types: .cpp, .h, etc. (0:33)
image.png

In the header (.h) files, you will only see the input and output of the function, not what's inside of it. The code for the function itself will be found in the corresponding .cc or .cpp file (ref: cpp-template repo; sort.h). Reasons for these two distinct file types (.h vs .cc/.cpp) are historical. In general, the sequence of events during compilation is as follows:

1. Preprocessor sees .h file, it gets included in a .cpp (or .cc) file via `include "some_file.h"` at top of .cpp file.
2. The .cpp file(s) gets compiled into an object file (.o)
3. If multiple .cpp files were compiled into multiple .o files, the linker pulls them all together into a single set of executable machine code instructions.

QUESTION: Ok, but why male models? ... and by male models, I mean header files. If the whole definition of the functions is in the .cpp file, and the header files only contain the input, name, and output of a function, what's the use of a header file? What meaningful contribution does it make? I guess what I'm asking is, what are those "historical" reasons for having header files? 

Ok, so at (0:39) a student asks why there are two header files in the diagram... should it be 1-to-1? Answer: the header files are like libraries, and there's no need to have a .h for every .cpp. Once you include the header file(s) in your .cpp file, you have access to all of the functions they list. For example, if you want to utilize some established machine vision libraries, you just do `include "whatever_library.h"` and you'll be able to access all the functions therein...

Ok, ok, but I have a followup question: if those header files only list the inputs, names, and outputs of the functions I need, but do not contain the actual function code itself, then how does including the header file allow me to access the function code?






# 2022.05.27:
## Bookmarks (lecture 2):

* Enum Class (1:29)
* Pointers (1:38)
* Struct Person (1:40)



# 2022.06.02:

Today we were notified via Piazza that the due date for HW1 would be extended until Tuesday, 06/7 (from 12pm tomorrow, Friday 06/3) on account of some people having registered late for the class. I definitely feel like I *could* have finished it by the original deadline, but more time is always welcome. Piazza is great. First time I've used it, and I think it's excellent.

So far, I have a very positive impression of our instructor. He is very clear, lively and engaging. I appreciate his line-by-line treatment of the code examples in class, and the thought-provoking questions he'll ask along the way to invite participation. The extra videos he's posted so far have been very helpful. The memes in his slides are hillarious and on point. Really looking forward to the rest of the semester. The TA is also very good. 


## TO DO, HW1:
### 1. Tests for the `RandomCase()` function? 
A student asked about this on Piazza, and I'm still not quite sure ... how to generate our "expected" string for the test to compare to the randomly-generated strings?

--> See @23 for discussion on this topic... solved: use `srand()` to set the random seed. Then when `rand()` is called, the same random sequence will be generated every time the program (or test) is run.



### 2. Runtime complexity of the recursive `climbSteps()`
$O(c^n)$? ... where $c = \phi \approx 1.618...$ (golden ratio). Also, try it with *memoization* to make it more efficient? Would this then get it to $O(n)$? How to do dictionaries (a la Python) in cpp?



### 3. Empty input vector to the `FindMedian()` function... 

zero seems like a better option, but I don't know if a mathematician would approve. Definitely not -1, which is what you've got presently. Maybe just the lowest possible signed integer value? hmmm.

--> See thread @53... a response to your question: 

https://stackoverflow.com/questions/23270078/test-a-specific-exception-type-is-thrown-and-the-exception-has-the-right-propert

Solved: To see test log, go to:

 `bazel-testlogs --> tests --> q2_student_test : test.log`

Here is some GoogleTest documentation:

http://google.github.io/googletest/primer.html


## Discussion 3:

More details on pointers and references. Get this - not there yet.

1. Watch at least the first 15 minutes over again
2. Do sample problems




# 2022.06.03

## LECTURE 3:

## Bookmarks (lecture 3):

* References vs Pointers (9:27)
* Passing Parameters to a Struct (19:30)
* References in loops to change items in a container (39:42)
* ARRAYS! (1:16)
* Flow control (1:41)

## POINTERS

Two ways to create a pointer:

1. `type* p = &var` ... for instance:
```cpp
int a = 17; //just a regular old variable assignment
int* p = &a; //integer pointer p points to the location of variable a
```
2. `p = new type` ... for instance:
```cpp
{
p = new int; //allocate dynamic memory from the heap
// ... blah blah blah... code code code 
delete p; //ALWAYS DELETE WHEN FINISHED!!!
}
```

## ARRAYS

What is an array?
* An indexed collection of items located at contiguous memory locations

In most languages, items in an array are in CONTIGUOUS locations; e.g., locations 0, 4, 8, 12, ... etc.

* Arrays are just pointers!!! You point to the first item, and you can simply increment your way to the rest of them...

Implementing Arrays:
```cpp
int arr[10]; //initialize an array of integers "arr" with 10 elements
arr[5] = 2;  //assign 2 to the 5th index address of "arr".
*(arr + 5) = 2; //same as arr[5] = 2...
```
... this shows how you're really just de-referencing the memory location 5 increments from the beginning of the array and assigning a value of 2 to that location.

RUNTIME COMPLEXITY of indexing a location in an array: is it faster to access arr[0] than arr[7]? No, because memory locations are contiguous, so anywhere you want to index is just a single *add* operation, i.e., RTC is $O(1)$. This is why ARRAYS ARE SO FAST.

HOWEVER, The SIZE OF AN ARRAY MUST BE DEFINED AT COMPILE TIME.

You *can* use a *DYNAMIC ARRAY* if you need to have the size defined at runtime, but even these *CANNOT CHANGE size* during runtime.

Impementing a DYNAMIC ARRAY:
```cpp
int var = 0;
std::cin >> var; //user-defined array size...
int *arr = new int[var]; //borrow "var" contiguous addresses from heap
```
Note the ONLY way to implement a DYNAMIC array is as shown above, using `new`. You CANNOT simply do:
```cpp
int arr[var]; //Nope. Can't do this at runtime.
```
Also note that you're also borrowing memory from the heap here, so you'll need to DELETE this pointer when you're finished using it... Like this:
```cpp
delete [] arr;
```
you MUST include those brackets, or else you'll only delete the pointer to the first element of the array.

QUESTION: why isn't it possible to change the size of an array? If I want to put one more item in the array, I'd need another contiguous memory address, which is certainly not guaranteed to be available. Even when you do `new` to initialize a dynamic array at runtime, you're still guaranteed a contiguous chucnk of memory but that's it. You can't change it.

VECTORS, conversely, have this handy `push_back()` function that allows you to append new items to their contiguous memory... What's happening here? The vector is moving all over the memory space, each time to a location where the requisite number of contiguous addresses are available, and then the old location is being given back to the heap.

Something kind of like this:
```cpp
void push_back(int in) {
  int *b = new int [a.size()+1];
  for (int i=0; i<a.size(); i++) {
    b[i] = a[i]; //This is O(1) because we are indexing arrays...
  }
  delete a;
  b[a.size()] = in;
  a = b;
}
```
Runtime complexity of pushback is $O(n)$... in C++, a trick is utilized to make it behave like it's $O(1)$ (amortization) in its actual implementation. But by itself, without such tricks, push_back is not cheap.

### 0. IF YOU SEE *p ANYWHERE ... :

* `*p` 
anywhere in anyone's code... **MAKE SURE YOU KNOW IT'S A _VALID ADDRESS_**.

"p is like a bomb... *p is like the red wire."

IF YOU TRY TO DE-REFERENCE A POINTER TO AN UNKNOWN MEMORY LOCATION, YOU'RE INVITING **UNDETERMINED BEHAVIOR**

### 1. Install this Debugger and experiment with tutorials...

https://www.youtube.com/watch?v=-TUogVOs1Qg&feature=youtu.be

... ok, so it looks like the github.com/ourarash/cpp-template has changed quite a bit since Feb 10, 2020 when this video went up on YT. I'm seeing a completely different file tree. Note: I'm at 11:17 in the video and I think I need to do what he's saying about modifying the `launch.json` file... tried breakpoints here and it didn't work. However, they do work on the "vanilla" `fib.cc` file in the `gcc_debug_template` repo. It's pretty cool. Next step is to get this all working with Bazel. This raises a question... will I need to supply/modify the `launch.json` file for every repo I want to debug with Bazel and codelldb?

Update: at 11:22 in link above, we see the instructions from the (old version of the? ) repo:

* Run the following in the terminal:
```bash
bazel build --cxxopt='-std=c++11' src/main:main -c dbg
```
where the `--cxxopt='-std=c++11'` part is copied from the `launch.json` file. Note: in the version of the repo I cloned, it's `--cxxopt='-std=c++17'` not `--cxxopt='-std=c++11'`. 

* Run the following in the root of your workspace to find the target of `bazel-cpp-template` symlink that Bazel creates.
```bash
readlink -n bazel-cpp-template
```

* Put the output of that command in `launch.json`'s `sourcemap` section:
```bash
"sourcemap": {
    "output of readlink -n bazel-cpp-template":"${workspaceFolder}"
}
```
for example:
```bash
"sourcemap": {
    "/private/var/tmp/_bazel_ari/asdfasdfasdfadfadfadfasdfadfadfadf/execroot/__main__":"${workspaceFolder}"
}
```
so, after doing all this, I'm not quite having success.

### 2. look at CPP_TOUR repo... 
`int *p = i`? ... say `i=10`... uh-oh...

... instead, use `&i` means "address of `i`", which is what you want.

### 3. In C++, functions can ONLY HAVE A SINGLE OUTPUT... 
but a way around this is to use references... then if you pass by reference, and operate on the variables inside the function, then those variables' values *actually change* because you operated on their references. In a sense, you've got these changed values as your "outputs," even if the function is `void` or just returns `0`. So, if you put an `&` in front of a parameter in a function call, you can think of it as an "output" that can be manipulated by that function... neat!

### 4. Another important reason to use references 
is to avoid copying, which, if you're just copying an int or char or whatever, is not a big deal, but if your input is a vector with a billion elements, that copy is going to take a shit ton of time(/space?)...

### 5. Refernces in loops...
cpp-tour/references:references_in_loops

### 6. DYNAMIC MEMORY 
HEAP: the memory you get from the OS...
is `int i = 8` heap memory? No.
Pointers: new and delete... first define `*p = nullptr`... then use `p = new int`, which asks the OS to 'loan' it an address in memory to use temporarily...
* `new` like borrowing memory
* `delete` like returning it
NOTE: never do `delete p;` before you've done `p = new int`...
What's the benefit of being able to get some new memory in the middle of my program? We're trying to be very careful with our memory footprint. Start with 2 bytes at first. If you don't actually need more memory, don't use it. 

### 7. 1:20 MEMORY LEAK... 
say you borrow 4 bytes at a time from the heap, then (stupidly) reassign (overwrite) it in a loop without using `delete` to give that memory back to the OS... say, 10,000 times... by the end of the loop, that's 40 kB of memory that is just occupied but unused. ooof... 

### 8. ARRAYS. 
items in arrays are in **contiguous locations** in memory.
WHAT IF I TOLD YOU... ARRAYS ARE JUST POINTERS

CPP_TOUR/src/arrays:dynamic_arrays_main

like dynamic variables, you'll need to delete every new array you create to avoid memory leaks... note that for dynamic arrays, you'll need to do `delete [] my_arr` with brackets. If you just do `delete my_arr`, you'll only return the first 4-byte bin to the OS, and the remaining memory locations will leak.

NOTE: even dynamic arrays cannot change in size once they've been created with a `my_arr = new int[array_size]` statement, since we don't know what lives at the next contiguous memory address.

... enter: VECTORS... with vector.push_back()

1:40 ... writing the .push_back() method...


## References:
for FindMedian():

https://www.cplusplus.com/reference/algorithm/sort/

https://www.tutorialspoint.com/program-for-mean-and-median-of-an-unsorted-array-in-cplusplus

runtime complexity of recursive Fibonacci: 

https://stackoverflow.com/questions/360748/computational-complexity-of-fibonacci-sequence

recursive fibonacci with memoization:

https://codereview.stackexchange.com/questions/106525/recursive-memoized-fibonacci-in-c

https://stackoverflow.com/questions/47457462/fibonacci-memoization-algorithm-in-c

running unit test for expected error:

https://stackoverflow.com/questions/23270078/test-a-specific-exception-type-is-thrown-and-the-exception-has-the-right-propert

# 2022.06.09
## Discussion Section

## 1. String Methods

## 2. Vectors

## 3. Sets

# HW 2 Hints...

# 2022.06.10
## Lecture

# 1. 

# 2. 

# 3. Sets:

collection of items that are:
* all of the same type
* unique (no duplicate items)
* arbirarily (not) ordered... but c++ internally sorts its sets, so you can provide items in any order and it will return them in sorted order...
* O(log(n))

# 3.1 Unordered_Set:
* on average O(1) ... up to O(n)


# 4. Maps (aka "dictionary" elsewhere)

A collection of pairs, functionally similar to a dictionary. Items are internally sorted by key.
* no duplicate keys
* implemented using balanced trees
* O(log(n))

# 5. Unordered_Map:

* not sorted
* implemented using a Hash table
* on average, O(1) ... up to O(n)


# 6. Iterators

kind of like a pointer that gives you access to a collection. E.g., a vector.

vector.begin(): gives a pointer to the first item
vector.end(): gives a pointer to one item *after* the last item

... wait, but why not just use *a pointer*???

iterating a pointer would only work for std::vector (guaranteed contiguous memory locations)... it wouldn't work for sets, maps, etc.

application: Insert & Delete...

note: pointers are dangers, SO ARE ITERATORS!!! (01:24)

use `it = v.insert(it, 12);` or use a `break` to escape before dereferencing the iterator again at the mem location of the *old* vector, which would cause **UNDEFINED BEHAVIOR**. 

# 7. Find (01:30)

NOTE: only i++ is guaranteed, not i += 2... another option is to use std::advance(i, 10) to advance your iterator by more than 1 (ten, in this case)

# Use Address Sanitizer!

* https://www.youtube.com/watch?v=hhpzDFvXopk

I've copied the `.bazelrc` file into this folder ... and, yes, now when we use the additional `--config=asan` (asan = address sanitizer) on a bad bit of code in the `int main(){...}` block, we see the shadow memory map and everything. Nice!

sample bad code throws `heap-buffer-overflow` error:
```cpp
  std::vector<char> v(1); //init vector of size 1...
  std::cout << v[100] << std::endl; //outside allocated vector mem
```
at command line:
```shell
bazel run --config=asan //src/main:main
```

# Friday, 2022.06.17
REVIEW:

```cpp
(*q).name
```
is the same as
```cpp
q->name
```

And, this is a TERNARY OPERATOR:
```cpp
return some_attribute_.empty() ? NONE : createStars();
```
which means: if `some_attribute_` is empty, return `NONE`, otherwise, return the result of the `createStars()` funciton.

## Struct & Class

Object-oriented programing. A Struct is a collection of variables that, together, describe some kind of object, basically the same way as the attributes of an instance of a particular Class. There's a distinction between Structs and Classes that we'll get to at the end, but for most intents and purposes, Structs are the same as Classes.

THE DISTINCTION (48:57) By default, everything in a `Struct` is public; and by default, everything in a `Class` is private. By convention, if you just have a few variables you want to bind together for a simpler kind of object, you'll use `Struct`; whereas if you have more complicated or customized methods in addition to various attributes, you'll define a `Class`.

We can define whatever kind of class we want. The example used here is the `Person` class, with attributes `name_`, `age_`, and `social_security_number_`. Attributes can be either public, i.e., accessible outside the scope of the class; or private, i.e., inaccessible outside the scope of the class itself. Only I know my social security number, and I get to choose who knows my age.

Instances of a class are called objects. We can initialize as many objects of a given class as we want, and it's as simple as initializing any other data type, such as an `int` or `char`. And similarly, we can define certain methods as part of our class, that a Person object can do or be subject to. For instance, a person might `.speak()` or we may wish to `.SetSSN()` for a new person.

A few fundamental attributes may be initialized automatically with placeholder values when an object is instantiated. For instance, when we initialize a new `Person` object, they are imbued with the default `name_ = "UNKNOWN"` and default `age_ = 0`. These default values are established by way of the constructor function. The constructor has the same name as the class itself. You can choose to allow a user to pass arguments to the constructor or not, by either including or not including parameters in the constructor function.

Interesting: to allow a user to pass arguments to the constructor *or* rely on default values, you can write multiple constructors; each for a given number of user-entered constructor arguments. This differs a bit from Python, where we can simply use default arguments in the function definition instead of having to write multiple definitions.

IMPORTANT: Just as you control how objects are instantiated, you need to control how they are destroyed. Some of your attributes may be pointers, with addresses allocated dynamically from the OS heap. Once the program exits the scope of a given object, i.e., exits the set of curly braces `{}` wherein the object was instantiated, it will be destroyed. The deconstructor *must* delete (deallocate) all such pointer variables initialized as part of the object, or else memory leaks will occur.

## MIDTERM FLAG 1:
Lecture Video 07/17/2022: (0:38) You define a function with parameter inputs of various class objects, some passed by value, reference, pointer, etc. You need to describe what happens with each of these parameters. What are benefits/drawbacks of passing parameters by value (copying can be time/space intensive) vs by reference (will change the original unless held const - could be useful), vs by pointer (will need to deallocate heap) ... etc. ?

Here is an example of an inefficient way to copy a `Point` object:

```cpp
Point p4; // Non-parameterized constructor called
p4 = p2;  // Copy values (attributes) from p2 to p4.
```

First the constructor is called, which assigns default values for the new `p4` object (this takes some amount of time...) *then*, those values are *overwritten* with the values from `p2`, which takes... more time. A more efficient way to do it would be:

```cpp
Point p4 = p2; //use copy constructor
```
because we don't wast time writing default values with our non-parameterized constructor. We go straight to copying the attributes of `p2` to `p4` via our copy constructor.

IMPORTANT: Why is a copy constructor's parameter passed by `const` *reference* and not by *value* ?

(see `cpp_tour` repo, `constructor_main.cc`):
```cpp
  // Copy constructor
  Point(const Point &p2) {
    std::cout << "COPY constructor." << std::endl;

    i_ = p2.GetI();
    j_ = p2.GetJ();
    z_ = new int;
    // *z_ = p2.GetZ();
  }
  ```

If the parameter were passed by value, SOMETHING REALLY BAD WOULD HAPPEN: 

When we pass by value, a copy of the original is created. To copy an object of any class, its COPY CONSTRUCTOR is called... 

Soooooo, if calling your COPY CONSTRUCTOR initializes the process of copying an object of its OWN CLASS, that means it CALLS ITSELF... INFINITELY. 

THIS IS WHY YOU **ABSOLUTELY CANNOT** PASS BY VALUE TO THE COPY CONSTRUCTOR!!!

Instead, just pass by reference and make sure you use `const` so that the original doesn't get changed.

## MIDTERM FLAG 2:
Lecture Video 07/17/2022: (1:17) LINKED LISTS... Ok, you gotta pick it back up at 1:28. Need to shift back to hw for now...

RUNTIME Vector vs List:
* Insert At Arbitrary Location in a Vector: $O(n)$
* Push Back into a Vector: $O(1)$ (on average)
* Inserting and Deleting At Arbitrary Location in a List: $O(1)$
* Indexing in a List: $O(n)$ (bc you have to start at beginning)

Note: STL handles "iteration" through lists... even though they're not contiguous addresses, the standard library's got you covered here (somehow, magically).

A `struct ListNode` object (ref lecture video 06/17/2022 at 1:23), see `cpp_tour` repo, `linked_list.cc`:
```cpp
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
```
Notes:
* we have two attributes that comprise any instance of our `ListNode` struct: an integer value `val` and a ListNode* pointer `next` which points to the memory location of the next node in the linked list.

* then we have the constructor function, which bears the name of the struct itself. Here we see it is instantiated with the integer paramter `x`, which the user must pass by value. We also see the initialization list, which initializes the value attribute to x via `val(x)`, and initializes the ListNode pointer to the null pointer via `next(nullptr)`. Alternatively, these attributes could have been assigned in the body of the constructor. However, since we have instead used an initialization list here, the body of the constructor is empty `{}`.

IMPORTANT: Every linked list MUST have a HEAD POINTER, which points to the first node of the list.

# 2022.06.24 Finishing L4 Slides, on to L5 Slides
## Operator Overloading
* operator is a keyword. follow it with ... an operator
* binary vs unary operators
* ++p1 is more efficient than p1++
* look back at (44:44)... convince yourself of everything on this slide.

## Deep & Shallow Copy
* later...

## LECTURE 5

## Trees & Heaps
Binary trees... 
* can have 0, 1, or 2 branches per node.
* top node is root node. no parents
* RECURSIVE data structures... code a recursive solution to a tree problem
* PERFECT binary tree: all possible children exist. each level of the tree is completely full
* COMPLETE binary tree. similar to perfect, except some children are missing from BOTTOM RIGHT.
* Level. some number we assign to each node. root:1, children of root:2, their children:3, etc. Note we start counting levels from ONE, not from ZERO.
* Height of the tree is the maximum level number.
* for n nodes: upper bound on levels is n (1 branch per node); lower bound: however many times can you divid n by 2 ... that's $log_2(n+1)$ ... $log_2(n)$ appears in runtime of a lot of tree-based algorithms.
* Going from root to leaf via any branch of a perfect tree: $O(log(n))$ ... whaaa???? Can we use this for linked lists too??
* LNR, NLR, RLN ... in order, preorder, post order
* max number of nodes at level "i": $2^(i-1)$
* parent (i) = floor(i/2) ...or floor((i-1)/2) for i starting at 0.
* leftchild(i) = i*2 ... i\*2 + 1 if i starts at 0.
* rightchild(i) = i*2 + 1 ... i\*2 + 2 if i starts at 0.
* you can store a tree in an array, if it is perfect

## BINARY SEARCH TREE
* any node in left subtree has value LESS than that node's value.
* any node in right subtree has value GREATER than that node's value.
* note the LEFT and RIGHT subtrees are also BSTs -- RECURSIVE!
* there can be NO DUPLICATE NODES.
* red & black trees data structure... redblack_trees? ... std::search() ...std::set()?
* this is how std::search() [std::set()?] returns values IN ORDER... just traverse the BST.
* worst case runtime is O(h) ... where h is the height of the tree
* finding minimum value in BST is O(h), which can be O(log(n)) if tree is balanced.
* stay tuned for HEAP, which can get this down to O(1)

## Min HEAP
1. COMPLETE binary tree
2. Parent is **LESS** THAN (or equal to) both children
... THERFORE: the MIN is the ROOT.

Functions: 
* push(key)
* pop()
* Key = top()

GOOD NEWS: heaps are complete binary trees. So, using a VECTOR to store elements is not very wasteful. We go from O(n) to O(1) to do ____a thing____. Nice.

* LOOK AT `heap::TrickleUp(int i)`... the while statment is the second heap requirement...
