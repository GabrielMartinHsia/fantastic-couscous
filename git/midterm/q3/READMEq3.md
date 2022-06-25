# Q3

```cpp
//TODO: check this... I referenced nothing, just my raw understanding of this is here. I don't know if it's right. Start at MIDTERM FLAG 2 in notes repo.
```

## What is the difference between `std::vector` and `std::list`?

1. Compare the runtime complexity of finding an item in each of them.

for finding (searching?) an item in a `std::vector`: $O(n)$
for finding (searching?) an item in a `std::list`: $O(n)$

A vector is a chunk of adjacent memory addresses. To find an item in a vector, i.e., to search for a specific value or string or character in it, we need to iterate through it, from beginning to end, and compare each element to our search value. Since every item must be queried, the runtime complexity of this operation is $O(n)$. 

A list is a spattering of randomly-located memory addresses, which are not contiguous. Each element of the list carries a pointer to the next element's address. To search a list for a specific value, we still need to visit every address and compare the resident value to our search value. So, the runtime complexity of finding an item in a list is also $O(n)$.


2. Compare the runtime compleity of accessing item `i` in each of them, where `i` is the index of the item we are trying to access. Also specify why this difference exists.

for accessing an item of known index `i` from a `std::vector`: $O(1)$
for accessing an item of known index `i` from a `std::list`: $O(n)$

Since a vector is a series of contiguous memory addresses, accessing the `i`th element is just a matter of adding `i` to the index of the first element - so the runtime complexity is $O(1)$.

Since elements of a list have non-contiguous addresses, the only way to access the `i`th item is to visit each element via their series of linking pointers, counting the number of elements we've visited until we get to the `i`th one. So on average, the runtime complexity is $O(n)$.

## What is the difference between `std::set` and `std::unordered_set`

runtime complexity for search, remove, and insert is O(log(n)) for std::set. For std::unordered_set, these operations are, on average O(1), and, at worst, O(n). 

std::set is internally sorted and implemented using balanced trees. std::unordered_set is not sorted, and is implemented using a hash table.