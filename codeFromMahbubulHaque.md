## Nth Palindrome Number:

```cpp

#include <iostream>
using namespace std;
int main ()
{
  int cnt = 0, target = 15, num = 1, res = 0;

  while (cnt != target)
    {
      int num1 = num;
      int num2 = 0;
    //reverse of number
    while(num1!=0)
    {
        int rem = num1%10;
        num1 /= 10;
        num2=num2*10+rem;
    }
    if(num==num2) // num is holding num1 value
      {
          cnt++;
          res=num;
      }
      num = num + 1;
    }
  cout<<target<<"th palindrome number is "<<res;
  return 0;
}

// cnt is the number of the palindrome


```

## Left skiwed priramid

```cpp
#include <iostream>
using namespace std;

int main ()
{
  int n = 10;
  for(int i = 0; i<5; i++){
      for(int j = 0; j <= i; j++) cout<<"* ";
      cout<<endl;
  }
  return 0;
}
```

## Equilateral Triangle

```cpp
// Equilateral Triangle
#include <iostream>
using namespace std;

int main()
{
	int n = 5;

	// ith row has n-i leading spaces
    // and i elements
	for (int i = 0; i < n; i++) {
	    // n-i leading spaces
	    for( int j = 0; j <= n - i - 1; j++) cout<<" "; // 1 for the one single * present
	    // i elements
		for (int j = 0; j <= i; j++)
			cout << "* ";
		cout << endl;
	}
	return 0;
}
```

## Pascal number triangle

a variety of bilateral triangle

```cpp
// Equilateral Triangle
#include <iostream>
#include<math.h>
using namespace std;

// Driver code
int main()
{
	int n = 5;

	// ith row has n-i leading spaces
    // and i elements
	for (int i = 0; i < n; i++) {
	    // n-i leading spaces
	    for( int j = 0; j <= n - i - 1; j++) cout<<" "; // 1 for the one single * present
	    // i elements
		for (int j = 0; j <= i; j++)
            // this will generate pascal tree
			cout << min(j+1, i-j+1)<<" ";
		cout << endl;
	}
	return 0;
}
```

## Maclaurin Series of Cos(x)

```cpp

// Maclaurin Series of CosX =  1 - (x^2/2!) + (x^4/4!) - (x^6/6!) +..nth term
#include <iostream>
#include<math.h>
using namespace std;

//

int fib(int n){
    if(n == 0 or n == 1) return 1;
    else return n*fib(n-1);
}

int main()
{
    int n = 9, x = 3.1416, sign = 1;
    double res = 0;

    for(int i = 0 ; i<n; i++){
        double numerator = pow(x, 2*i);
        double denominator = fib(2*i);
        res += sign * numerator/denominator;
        //cout<<sign * numerator/denominator<<endl;
        sign *= -1;
    }

	cout<<res;
	return 0;
}

```
