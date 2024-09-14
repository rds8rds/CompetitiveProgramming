#### Java array with size and fill with a value 

```java
import java.util.Arrays;

int[] cumXor = new int[len];  // Declare the array

// Initialize all elements to the value 5
Arrays.fill(cumXor, 5);
```

#### ArrayList in java [much like vector]

```java
import java.util.ArrayList;

public class Example {
    public static void main(String[] args) {
        // Create an ArrayList of integers
        ArrayList<Integer> arrayList = new ArrayList<>();

        // Add elements to the ArrayList
        arrayList.add(1);
        arrayList.add(2);
        arrayList.add(3);

        // Access elements by index
        System.out.println("Element at index 1: " + arrayList.get(1));

        // Iterate over the elements
        for (int i : arrayList) {
            System.out.println(i);
        }

        // Remove an element
        arrayList.remove(1);

        // Print the updated ArrayList
        System.out.println("Updated ArrayList: " + arrayList);
    }
}
```

#### Java max, min method 

```java
    int a = Integer.max(a, b);
    int b = Integer.min(a, b);
```