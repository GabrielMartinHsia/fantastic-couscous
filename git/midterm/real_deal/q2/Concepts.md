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