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
int b = Integer.min(a, b); // Math.max(a, b) is also available 
```

### hashmap 

```java
import java.util.HashMap;

public class HashMapExample {
    public static void main(String[] args) {
        // Create a HashMap
        HashMap<String, Integer> map = new HashMap<>();
        
        // Add key-value pairs
        map.put("Apple", 3); 
        map.put("Banana", 5);
        map.put("Orange", 2);
        
        // Access elements
        System.out.println("Apple count: " + map.get("Apple")); // Output: Apple count: 3
        
        // Check if a key exists
        if (map.containsKey("Banana")) {
            System.out.println("Banana is in the map.");
        }
        
        // Remove an entry
        map.remove("Orange");
        
        // Loop through the HashMap
        for (String key : map.keySet()) {
            System.out.println("Key: " + key + ", Value: " + map.get(key));
        }
        
        // Size of the map
        System.out.println("Size: " + map.size()); // Output: Size: 2

        // if we use HashMap.get() for a key that we don't belong to the hash map we get null output; 
    }
}

```

#### toCharArray() --> string to charecter array java

string.toCharArray()

### toLowerCase(), toUpperCase() --> cahnge case to charecter;

but we just cant user toLowerCase() to any charecter as a dot operator, because char in java is a premitive datatype so we need to use Static method [**instead of instance methods(used as dot method)**]

### StringBuilder class

In java String is immutable so changes in string is costly we need to create new string for any simplest change, for that StringBuilder comes to our rescue.
Lets see what can we do with it?

#### Initialization: 

```java
StringBuilder sb = new StringBuilder(); 

// appending

sb.append("hello world"); // string
sb.append('!'); // char

String date = " 20 Aug, 2020";
sb.append(date);

// String Modificatio

sb.insert(5, "-"); // hello- world 20 Aug, 2020
sb.delete(5, 6); // hello world...
sb.replace(0, 5, "Hi"); // Hi world.... 

// reverse string 

sb.reverse(); 

// string convertio

String res = sb.toString()

```