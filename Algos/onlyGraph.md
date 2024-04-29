### Calculate Sum of Distance to All Nodes from Root Node

![image](https://github.com/rds8rds/CompetitiveProgramming/assets/47500104/242dd675-1276-4fbd-affa-6c3615cb3467)

Consider the tree above, with 0 as the root node, every nearby nodes are in equidistant of value 1.
The result for subtree with 2 as root will be 2 (we can easily count it) and for subtree 1 is 1.

This is the recurrence relation we can use to calculate the sum of distances for root.

```cpp
res[0] = res[2] + number of nodes in subtree with root 2
        + res[1] + number of nodes in subtree with root 1

res[0] = 2 + 3 + 1 + 2 = 8
```

We are adding the number of nodes of subtree because every node in subtree will be 1 unit more far from the original root.
`for more explanation` when for this tree the distance between root 3 and 0 is 2, now this two is calculated in 2 steps,

1. when we calculate res[2] we add 1 dist for node 3
2. when calculating nodes number in right subtree [ 2 as root ] we add 1

I need two arrays count and res. Count will store the number of nodes in each subtree and res will the store the answer as discussed above. Below is the code.
