# To Clarify

Here are a few questions that have come up in my mind so far...

## 1. "iterators" versus... just iterating through a vector or array.

when we do something like:
```cpp
for (int i=0; i<v.size(); i++) {...do the_thing...;}
```
is it not correct to say we are "iterating" through the elements of `v`?

Ok, now if that's correct, is it also correct to call `i` an "iterator"? Or is that a special term we use only to describe something defined as:
```cpp
std::specific_container_type<data_type>::iterator
```
## 2. Practice Midterm Q4.1

<!-- This immediately made me think of that time in lecture when you showed us the example where little Bobby Bruin took two steps to create an object: 

1. initialize to default values
2. copy values from a separate, pre-existing object of the same class.

and we were told that a better way to do this would be to simply call the copy constructor during initialization so the desired values would be used upon initialization instead of having to copy all the values all over again.

... but I'm not really seeing that here. -->

Oh. Duh. Pass by reference to avoid copying the whole damn vector for income and expenses.

Also, when Q4.1 mentions the "delcaration (signature) of `CalculateTax`", it's talking about where it is defined as a method in the body of the `class TaxCalculator` code, right? And not where it is called in `int main()`, right?


## 3. Rules for Writing Classes? 

When writing classes, is it required to have the constructor come first, immediately after "public:"? For Q4 on the practice midterm (taxes), I had placed a couple of attribute initializations prior to my constructors. The compiler wouldn't have it. It could not overload the two constructors, even though they had clearly different signatures. When I removed the initialization of the attributes from their aforementioned location (above/before the constructors) and then instead intialized them within the parentheses of the parameterized constructor, it compiled and ran just fine.

Why is it that we can't initialize our attributes first, and *then* use them in the constructor, like this (this is how I had it first, which did not work):

```cpp
class TaxCalculator {
    public:
        //initialize public attributes:
        std::vector<float> income, expenses;

        //non-parameterized constructor with defaults of zero:
        TaxCalculator(){  
            income_ = {0};
            expenses_ = {0};
        };
        //parameterized constructor:
        TaxCalculator(income, expenses){ //params initialized above (compile error!)
            income_ = income;
            expenses_ = expenses;
        };
```
... and instead we need to do it like this:
```cpp
class TaxCalculator {
    public:
        // //can't put these public attributes here???:
        // std::vector<float> income, expenses;

        //non-parameterized constructor with defaults of zero:
        TaxCalculator(){  
            income_ = {0};
            expenses_ = {0};
        };
        //parameterized constructor:
        TaxCalculator(std::vector<float> income, std::vector<float> expenses){
            income_ = income;
            expenses_ = expenses;
        }; 
```
Is the rule that the public attributes used in a constructor *must* be initialized within the parentheses of that constructor (or in an initialization list following them), or is the rule that nothing can be defined before/above the constructor in the class definition?



## 4. Ok, but... why header files? 
https://imgflip.com/i/6kb7xm

<a href="https://imgflip.com/i/6kb7xm"><img src="https://i.imgflip.com/6kb7xm.jpg" title="made at imgflip.com"/></a><div>

In the header (.h) files, you will only see the input and output of the function, not what's inside of it. The code for the function itself will be found in a .cc or .cpp file (ref: cpp-template repo; sort.h). Reasons for these two distinct file types (.h vs .cc/.cpp) are historical. In general, the sequence of events during compilation is as follows:

1. Preprocessor sees .h file(s) included in a .cpp (or .cc) file via `include "some_file.h"` statement at top of .cpp file.
2. The .cpp file(s) gets compiled into an object file (.o)
3. If multiple .cpp files were compiled into multiple .o files, the linker pulls them all together into a single set of executable machine code instructions.

QUESTION: Ok, but ...why header files? If the whole definition of the functions is in a .cpp file somewhere, and the header files only list the input, name, and output of a function, what's the use of a header file? What meaningful contribution does it make? Why don't we just include the ..cpp file(s) that contain the actual function code we need? I guess what I'm asking is, what are those "historical" reasons for having header files? 

Ok, so at (0:39) a student asks why there are two header files in the diagram... should it be 1-to-1? Answer: the header files are like libraries, and there's no need to have a .h for every .cpp. Once you include the header file(s) in your .cpp file, you have access to all of the functions they list (but HOW?). For example, if you want to utilize some established machine vision libraries, you just do `include "whatever_library.h"` and you'll be able to access all the functions therein...

Ok, ok, but if those header files only list the inputs, names, and outputs of the functions I need, but do not contain the actual function code itself, then how does including the header file allow me to access the function code?

## 5. HW2, Q5: Arrays (ugh!)

<!-- I spent way longer than I'd care to admit on the `ConcatenateArrays()` part of q5 and *still* didn't arrive at a workable solution (whereas the `ConcatenateVectors()` part of q5 was quick and easy). 

I felt like I had a reasonable grasp on arrays (they're just pointers!) and how to handle them, but this question made me realize I don't. Now, note that I *did* have something that worked to concatenate two arrays when implemented in a dummy main() program, without the specified int* type returned from the function. I just could not, for the life of me, make it work with the specified output pointer type... which I kept thinking was odd, since... arrays. are. just. pointers! So, I ended up leaving that function commented out of my .cc file for q5 and taking the loss. -->


