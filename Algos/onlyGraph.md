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
`for more explanation` when for this tree the distance between root 3 and 0 is 2, now this 2 is calculated in 2 steps,

1. when we calculate res[2] we add 1 dist for node 3
2. when calculating nodes number in right subtree [ 2 as root ] we add 1

I need two arrays count and res. Count will store the number of nodes in each subtree and res will the store the answer as discussed above. Below is the code.

```cpp
	// intially count array was initialized to 0.
	// count[parent] is the sum of count of its child + 1
	// v is the Adjacency List
	void dfs(int i, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            dfs(u, i);
            count[i] += count[u];
            res[i] += res[u] + count[u];
        }
        count[i] += 1;
    }
```

### Calculate Sum of Distance from Each Node to Every Other Nodes in the Graph

We can run the dfs function above for every node and get the solution. This will result in **O(N \* N)** time complexity. But we can do this in **O(N)** time using a technique popularly known as `**re-rooting techinque.**`

The idea is to derive the solution of every node by shifting the root.

![image](https://github.com/rds8rds/CompetitiveProgramming/assets/47500104/4bb2693f-0e17-4824-ae9d-c64045317c40)

Suppose we shift the root from root 0 to 1, what changes can we observe.
`count[1] `nodes got 1 unit closer to new root and `n - count[1]` nodes got 1 unit away from the new root.
So,

`res[1] = res[0] - count[1] + n - count[1]`

i.e
`res[new_root] = res[root] - count[new_root] + n - count[new_root]`

The way we are running dfs the new_root will be child and root will be parent.
Here, is the code for this part.

```cpp
void dfs2(int i, int n, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            res[u] = res[i] - count[u] + n - count[u];
            dfs2(u, n, i);
        }
    }
```
