## Python Data Structure; 

## python intmax 
```python
a = sys.maxsize
```

## One line return 
```python
return sum if cnt % 2 == 0 else sum - 2*lowest_abs; 
```

### List


python list is ordered, dynamic, mutable, heterogenous (different different data type)

```python
my_list = [1, 2, 3, 4]

# accessing 
my_list[0] = 5 

# append
my_list.append(6) #output [5, 2, 3, 4, 5]

# extend()
my_list.extend([6, 7, 8]) #output [5, 2, 3, 4, 5, 6, 8]

# insert()
my_list.insert(0, 3) #output [3, 2, 3, 4, 5, 6, 8]

# remove()
## remove  the first occurance of 4, in the list
my_list.remove(4) #output [3, 2, 3, ]

# useful functions

# checking if an element is in a list

my_list = [1, 3, 5, 7]

if 5 is in my_list: 
    return True

## slicing list[startInd : endIndex + 1]
my_list_slice = my_list[1:4]   # [2, 3, 4]
my_list_slice = my_list[ : 3]  # [1, 2, 3]
my_list_slice = my_list[ :: 2] # [1, 3]

# creating fixed sized list; 

int m,n = 4, 5

list_2d = [[0 for _ in range(m)] for _ in range(n)] # _ --> just a place holder;  

### reverse list traversal 

#reversed()
my_list = [1, 2, 4, 3, 6]

for item in reversed(my_list):
    print(item)

> prints: 1, 2, 4, 3, 6

# using reverse slice 

for item in my_list[:: -1]:
    print(item)

# sorting sorted()

sorted_list = sorted(my_list)

reverse_sorted_list = sorted(my_list, reverse = True)

```

### Touples 

A tuple in Python is an `immutable` sequence of items. It is similar to a list but has a key difference: once a tuple is created, its elements cannot be changed, added, or removed.


```python
# Empty tuple 
empty_tuple = ()

# Tuple with elements 
my_tuple = (1, 2, 3)

# single elemnets touple 
sing_tuple = (5, )

#### Features 
 - immutable
 - ordered 
 - allows duplicates 
 - heterogeneous 
 - hashable 
```
```python

my_tuple = (1, "hello", 3.14)
```


### Queue in python 

Queue is used for Lifo based taking input 

```python
# creation 

import queue
que = queue.Queue()

```

### Dictionary 

Dictionary is handy for mapping, it uses hashing inside. 

```python
# same as map 
my_dict = dict() 
my_dict = { 'a' : 3, 'b' : 2, 'c': 0}

# most used functions are 

# Add or update key-value pair: 
my_dict[key] = value


# Get the value 
my_dict.get(key); 
my_dic.get(key, defaultValue) # advancement of Dict().get() 😉😉

# if not in dictionary then create {key defaultValue} pair
my_dict.setDefault(key, defaultValue) 



# Update
my_dict = {"name": "Alice", "age": 25}
my_dict.update({"age": 30, "city": "New York"})
print(my_dict)  # Output: {'name': 'Alice', 'age': 30, 'city': 'New York'}

## Dictionary Comprehension
# Create a dictionary with default values
keys = ["name", "age", "city"]
default_value = "Unknown"
my_dict = {key: default_value for key in keys}
print(my_dict)  # Output: {'name': 'Unknown', 'age': 'Unknown', 'city': 'Unknown'}

# Update values dynamically
my_dict = {key: len(key) for key in keys}
print(my_dict)  # Output: {'name': 4, 'age': 3, 'city': 4}

# Combine and merge Dictionaries
dict1 = {"name": "Alice", "age": 25}
dict2 = {"city": "New York", "age": 30}  # Will overwrite "age"

# Merge dictionaries
merged_dict = dict1 | dict2
print(merged_dict)  # Output: {'name': 'Alice', 'age': 30, 'city': 'New York'}

## Add keys with default vlaue 
keys = ["name", "age", "city"]
default_value = None
my_dict = dict.fromkeys(keys, default_value)
print(my_dict)  # Output: {'name': None, 'age': None, 'city': None}

# 1. Iterating Over Keys
# The default iteration in a dictionary is over its keys.

my_dict = {"name": "Alice", "age": 25, "city": "New York"}

for key in my_dict:
    print(key)
# Output:
# name
# age
# city

# You can also use the .keys() method explicitly:
for key in my_dict.keys():
    print(key)

#Use the .values() method to iterate over the values:
for value in my_dict.values():
    print(value)
# Output:
# Alice
## 25
# New York
# 3. Iterating Over Key-Value Pairs

# Use the .items() method to iterate over both keys and values:

for key, value in my_dict.items():
    print(f"{key}: {value}")
# Output:
# name: Alice
# age: 25
# city: New York
```

### Set

```python

# Using curly braces
my_set = {1, 2, 3, 4}
print(my_set)  # Output: {1, 2, 3, 4}

# Using the set() constructor
my_set = set([1, 2, 2, 3, 4])
print(my_set)  # Output: {1, 2, 3, 4}

my_set = {1, 2, 3}

# Add an element
my_set.add(4)
print(my_set)  # Output: {1, 2, 3, 4}

# Remove an element
my_set.remove(2)  # Raises KeyError if the element is not found
print(my_set)  # Output: {1, 3, 4}

# Discard an element (does not raise an error if the element is not found)
my_set.discard(5)

# Remove and return an arbitrary element
removed_element = my_set.pop()
print(removed_element)  # Output: 1 (or another random element)
print(my_set)  # Output: {3, 4}

# Clear all elements
my_set.clear()
print(my_set)  # Output: set()

# presence testing 
my_set = {1, 2, 3, 4}
print(3 in my_set)   # Output: True
print(5 in my_set)   # Output: False


# Set operations
set1 = {1, 2, 3}
set2 = {3, 4, 5}

# Union (elements in either set)
print(set1 | set2)  # Output: {1, 2, 3, 4, 5}
print(set1.union(set2))  # Output: {1, 2, 3, 4, 5}

# Intersection (elements in both sets)
print(set1 & set2)  # Output: {3}
print(set1.intersection(set2))  # Output: {3}

# Difference (elements in set1 but not in set2)
print(set1 - set2)  # Output: {1, 2}
print(set1.difference(set2))  # Output: {1, 2}

# Symmetric Difference (elements in either set1 or set2, but not both)
print(set1 ^ set2)  # Output: {1, 2, 4, 5}
print(set1.symmetric_difference(set2))  # Output: {1, 2, 4, 5}

# subset checking 
set1 = {1, 2, 3}
set2 = {1, 2}

# Check if set2 is a subset of set1
print(set2.issubset(set1))  # Output: True

# Check if set1 is a superset of set2
print(set1.issuperset(set2))  # Output: True

# printing 
my_set = {1, 2, 3}
for item in my_set:
    print(item)  # Output: 1, 2, 3 (order may vary)

```


### Substring

```python
# using slicing 

sample = "this is my happy place"

part_of_sample = sample[0: 4] # subString of [0, 4 - 1] --> this
part_of_sample_2 = sample[ : len(sample)] # start from index 0 to end 
part_of_sample_3 = sample[6: ] # --> is my happy place


```


### Returning multiple objects with new python fuctional signature: 

```python
# using touple 
def concatenate_and_lengths(x: str, y:str) -> touple[int, int]:

# using data class [ need to dig more!]
@dataclass
class Lengths:
    length_x: int
    length_y: int

def string_lengths(x: str, y:str) -> Lengths:
    return Lengths(len(x), len(y))


```

✅ {} → Dictionary
✅ set() → Empty Set
✅ {1, 2, 3} → Set with elements 🚀 [ not dict]

### Sorting in python: 

```python

nums = [2, 1, 3, 4, 5]
sorted_nums = sorted(nums) // sorted_nums = [1, 2, 3, 4, 5]
reverse_sorted_nums = sorted(nums, reverse = True)

```


### Priority Queue in python 

> there is another heap implementation in python which is not thread safe but faster, `heapq`

There is  priorty queue class in python, which is in queue module

the basic operation are as follows: 

```python

from queue import PriorityQueue 

pq = PriorityQueue() # initialization
pq2 = PriorityQueue()
#insert into pq
pq.put(1)
pq.put(2)
pq2.put((5, "student x")) 
pq2.put((2, "student y"))
pq2.put((7, "student z"))

"""
pq 
-------------------
|1|
|2|

pq2
---------------------
|(2, "student y")|
|(5, "student x")|
|(7, "student z")|
"""
# remove element 

x = pq.get() # x = 1, also removes from min-heap
student_with_smallest_number = pq2.get() # this gets (2, "student y") and removes it 

# size 
size = pq.qsize()

# is empty 
bool is_empty = pq.empty() 
```