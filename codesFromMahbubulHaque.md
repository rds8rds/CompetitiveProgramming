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

## Decimal to binary conversion or decimanl to binary

### Decimal to Binary hard coding

```cpp
// clean code
int decToBinary(int num)
{
    int binary = 0, i = 1;

    while(num){
        int rem = num%2;
        binary += i*rem;
        i *= 10;
        num /= 2;
    }

    cout<<binary<<endl;
    return binary;
}
```

### Binary to Decimal

```cpp

int binaryToDec(int n) {
    // Write C++ code here
    int n, res = 0, currBase = 1;
    while(n){
        int rem = n%10;
        res += rem * currBase;
        currBase *= 2;
        n = n/10;
    }

    cout<< res;
    return res;
}
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    int num = 10, binary = 0;
    string tmp ="";

    while(num){
        int rem = num%2;
        // using vector
        vec.push_back(rem);
        // using string
        tmp = to_string(rem) + tmp;
        num  = num / 2;
    }

    for(int i = vec.size() - 1; i >= 0; i--){
        binary *= 10;
        binary += vec[i];
    }
    cout<<binary<<endl;
    cout<<tmp;
}

```

## find how may times string a present in string b

```cpp
// how many times string needle present in string hay
// test: hay = "aaa" and needle = "aa" output 2;
int needleInHay( string hay, string needle){

    int hayStart = 0, needleStart = 0;
    int cnt = 0;

    while( hayStart <= hay.size() - needle.size() ){
        int a = 0;
        while( hay[hayStart + a] == needle[needleStart]){
            a++, needleStart++;
            if(needleStart == needle.size()){
                hayStart++; // start checking from next index;
                needleStart = 0,
                cnt++;

            }
        }
        if(hay[hayStart] != needle[needleStart]) {
            needleStart = 0;
            hayStart++;
        }
    }

    return cnt;
}
```

## Lexigraphically small string

```cpp
// using kind of default function
// lexigraphically smaller or not
int isSmaller( string a, string b){
    return a < b;

}

```

## date Formatting

```cpp
//12/09/2023 ==> day: 12, month: 09, year: 2023;
vector<int> dateFormater( string date){
    int start = 0;
    vector<int> res;
    while( start < date.size() ){
        int a = 0;
        while(start + a < date.size() and date[start + a] != '/') a++;

        // stoi() will raise exception if we let 0 sized string to
        // pass on it
        if(a > 0){
            int x = stoi(date.substr(start, a));
            res.push_back(x);

        }

        // update start
        start += a==0 ? 1 : a;
    }
    return res;

}
```

## subsequence problem

```cpp
// subsequence problem
// check s1 = "bdesh" is a subsequence of s2 = "bangladesh"
// for this case answer is true;

bool isSubSequence(string s1, string s2){
    int start1 = 0, start2 = 0;
    while(start2 < s2.size() ){
        if(s1[start1] == s2[start2]){
            start1++, start2++;
        } else start2++;

        if(start1 == s1.size()) return true;
    }
    return false;
}
```

## fibonacci Number (iterator)

```cpp
// fib(0) = 0, fib(1) = 1, n>1 fib(n) = fib(n-1) + fib(n-2);
int fib( int x ){
    int a = 0, b = 1, c;
    if(x == 0) return a;
    else if( x == 1 ) return b;

    for(int i = 2; i<=x; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// recursive fibonacci TLE causion
int fib2(int x){
    if(x == 0 or x == 1) return 1;
    else return fib(n-1) + fib(n-2);
}

```

## sieve algorithm

```cpp
vector<int> sieve(int n){
    vector<int> mark,res;
    mark.resize(n+1, 0);
    int i, j, limit = sqrt(n) + 2;

    // q is not prime
    mark[1] = 1;
    // almost all the evens are not prime
    for (i = 4; i <= n; i += 2) mark[i] = 1;

    // 2 is prime
    res.push_back(2);
    // run loop for only odds
    for (i = 3; i<= n; i += 2){
        // if not prime, no need to do "nultiple cutting"
        if ( not mark[i] ){ // only primes are alowed
            // i is prime
            res.push_back(i);

            // if we don't do it, following
            // i*i may overflow

            if(i <= limit){
                // loop through all odd multiples of i
                // greater than i*i bcoz
                // for h*i where h < i is already
                // marked when i was equal to h

                for(int j = i*i; j <= n; j += 2*i){
                    // j += 2*i we olny traverse through
                    // odd numbers
                    mark[j] = i;
                }
            }
        }
    }
    return res;
}
```

```cpp
for(int i=2;i<=N;i++)
    if(prime[i])
        for(int j=i*i;j<=N;j+=i) prime[j]=0;
```

## yarin's sieve (memory efficient sieve)

https://codeforces.com/blog/entry/68299

```cpp
#include<bits/stdc++.h>
using namespace std;

#define MAXSIEVE 100000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd


int main() {
    int i,j;
	memset(a,255,sizeof(a));
	a[0]=0xFE;
	for(i=1;i<MAXSQRT;i++)
		if (a[i>>3]&(1<<(i&7)))
			for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
				a[j>>3]&=~(1<<(j&7));

    // only odd primes can be generated
    for(int i = 1; i<100; i += 2 ){
        if(isprime(i)) cout<<i<<" ";
    }

}

```

## segmented sieve ()

https://medium.com/%E0%A6%AA%E0%A7%8D%E0%A6%B0%E0%A7%8B%E0%A6%97%E0%A7%8D%E0%A6%B0%E0%A6%BE%E0%A6%AE%E0%A6%BF%E0%A6%82-%E0%A6%AA%E0%A6%BE%E0%A6%A4%E0%A6%BE/segmented-sieve-number-theory-1af0602dba39

```cpp
typedef long long ll;
vector < int > primes; /*এখানে primes ভেক্টরে sieve এর মাধ্যমে প্রাইম নাম্বারগুলো জেনারেট করে নেওয়া হয়েছে  */
void segmentedSieve(ll L, ll R)
{
 bool isPrime[R-L+1];
 for(int i=0 ; i<=R-L+1 ; i++)
    isPrime[i]=true;

 if(L==1)
    isPrime[0]=false;

 for(int i=0 ; primes[i]*primes[i]<=R ; i++)
 {
    ll curPrime=primes[i];
    ll base=curPrime*curPrime;
    if(base<L)
    {
       base=((L+curPrime-1)/curPrime)*curPrime;
    }
    for(ll j=base ; j<=R ; j+=curPrime)
    isPrime[j-L]=false;
 }
 for(int i=0 ; i<=R-L ; i++)
 {
    if(isPrime[i]==true)
        cout<<L+i<<endl;
 }
 cout<<endl;
}
```

## factors of numbers ranging from 1 to n similar to sieve

```cpp
vector<vector<int>> factoring( int n )
{
    vector<vector<int>>res(n + 1,vector<int>());
    for(int i = 1; i <= n; i++){
        for(int j = i; j<= n; j+=i){
            //cout<<j <<" "<<i<<endl;
            res[j].push_back(i);

        }
    }
    return res;
}
```

## prime Factoring

```cpp
vector<int> primeFactorGen( int x )
{
    vector<int> res;

    while(x % 2 == 0){
        x = x/2;
        res.push_back(2);
    }

    for(int i = 3; i <= sqrt(x) + 1; i += 2){
    // next primes are all odd so i = i + 2;
    // plus one for consistency because sometimes in floating point cal
    // computer may lose some precission 3.00 may turn int 2.99999
        while( x % i == 0) {
            res.push_back(i);
            x = x/i;
        }
    }

    if(x > 2) res.push_back(x);

    return res;
}
```

## Prime factors with their powers in pair

```cpp
vector<pair<int, int>> primeFactorWithPowerGen(int n){
    vector<int> primeFactors  = primeFactorGen(n);

     vector<pair<int,int>> primeFactorWithPower;
     for(int it : primeFactors){
         if(primeFactorWithPower.empty()) primeFactorWithPower.push_back({it, 1});
         else{
             if(primeFactorWithPower.back().first == it){
                 primeFactorWithPower.back().second++;
             } else {
                 primeFactorWithPower.push_back({it, 1});
             }
         }
     }
     return primeFactorWithPower;
}

```

## NOD (number of divisors )

```cpp
 int genNOD(int n){ // number of divisors

     vector<pair<int, int>> primeFactorWithPower = primeFactorWithPowerGen(n);

     // NOD = (power1 + 1) * (power2 + 1) * (power3 + 1)....;
     int ret = 1;
     for(auto it : primeFactorWithPower){
         ret *= (it.second + 1);
     }
     return ret;
 }
```

## SOD (sum of divisors)

```cpp
int genSOD(int n){ // number of divisors

     vector<pair<int, int>> primeFactorWithPower = primeFactorWithPowerGen(n);

     // SOD = (p^0 + p^1 + p^2 +...+ p^a1) * (q^0 + q^1 + ... + q^a2) +......
     // here p, q,... is prime factors
     // a1, a2,... are their respective factors
     // n = p ^ a1 * q ^ a2 *....;
     int ret = 1;
     for(auto it : primeFactorWithPower){
         int sumForSinglePrimeFactor = 0;
         for(int i = 0; i <= it.second; i++){
             sumForSinglePrimeFactor += pow(it.first, i);
         }
         ret *= sumForSinglePrimeFactor;
     }
     return ret;
 }
```

## GCD and LCM

```cpp
int gcd(int x, int y){
    if(x > y) swap(x,y);

    // x is smaller
    if(y % x == 0) return x;
    else return gcd( y % x, x); // ছোট, বড়
}

// iterative GCD;
int genGCD(int a, int b){
    if( b > a ) swap(a, b);
    while( a % b != 0){
        int mod  = a % b; // this mod will be lesser than both a, b
        a = b;
        b = mod;
    }
    return b;
}

int lcm (int x, int y){
    return (x*y ) / gcd(x, y);
}

```

## Euler's Totient function

সহমৌলিক নাম্বার এর সংখ্যা বের করার ফাংশন। φₙ = n \* (1 - 1/p₁) \* (1 - 1/p₂) \* (1 - 1/p₃) \* (1 - 1/pᵢ) where pᵢ i = 1, 2, 3... are prime factors of n; সকল সংখ্যার কমন সহমৌলিক হল ১;
or n = p<sub>1</sub><sup>a1</sup> p<sub>2</sub><sup>a2</sup> p<sub>3</sub><sup>a3</sup>... p<sub>i</sub><sup>ai</sup>

### sieve Phi

```cpp

int phi[1000006], mark[1000006];
void seivePhi(int n) {
    int i, j;

    // initialization
    for(int i = 1; i <= n; i++) phi[i] = i;

    memset(mark, 0, sizeof(mark)); // 0: prime 1: composite
    mark[1] = 1;

    for( i = 2; i <= n; i++){
        // কোনো অপ্টিমাইজেশন করা হল না
        if(not mark[i]){// prime
            for(j = i; j<=n; j+=i){
                mark[j] = 1; // কম্পিজিট নাম্বার গুলোকে কেটে দিলাম
                phi[j] = phi[j]*(i - 1)/i;
            }
        }
    }
}


```

Totient function for single number:

```cpp
// totient function for a single number
int phi(int n){
    int ret = n;
    for(int i = 2; i * i <= n; i++){
        while(n%i == 0){
            n = n/i;
        }
        ret = ret*(i - 1)/i;
    }
    if( n > 2){
        // then n is the last prime number;
        ret = ret * (n - 1)/n;
    }
    return ret;
}
```

## BigMod

বড় নাম্বার এর জন্য MOD বের করা, এই আলগরিদম গুলোকে কিন্তু ডিভাইড এন্ড কঙ্কার বলে

```cpp
//bigMod (a, b, M) means a^b mod M
// complexity O(log n)
// recursive + devide and conquer method

int bigMod(int a, int b, int M){
    if( b == 0) return 1 % M;
    // a^b mod M = (a^(b/2) mod M) * (a^(b/2) mod M) mod M
    // if b is odd then
    //  a^b mod M = (a^(b/2) mod M) * (a^(b/2) mod M) (a mod M) mod M
    int x = bigMod( a, b/2, M);
    x = (x*x) % M;
    if( b % 2 == 1) x = (a*x) % M;
    return x;
}
```

### Recursive bigSum() similar to big mod

জিওমেট্রিক সিরিজ এর জন্য MOD বের করা

```cpp
// bigSum(a, n, M) n == total terms in series
// return mod of( a^0 + a^1 + a^2 + a^3 + ... + a^(n-1) ) by M
// complexity O(long n * log n);
int bigSum (int a, int n, int M){

    //  base cases
    if (n == 1) return 1 % M;

    if(n % 2 == 1){ // odd number of terms
        return (bigSum(a, n-1, M) + bigMod(a, n-1, M)) % M;
    } else {
        int halfRes, res;

        halfRes = bigSum(a, n/2, M); // even
        res = (halfRes + (halfRes * bigMod(a, n/2, M)) % M) % M;
        return res;
    }
}
```

### Recursive bigSum() উপরের সমস্যার জন্য log(n) টাইমে সলুশন বের করা

```cpp
// bigSumV2(a, b, M)
// a^0 + a^1 + a^2 + a^3 + a^4 +.... a^b
// if b iis even
// (a^0 + a^2 + a^4 +...... a^b-2) + a(a^0 + a^2 + a^4 + ... + a^b-2)
// if odd
// 1 + a(a^0 + a^1 + .... + a^b-2) => a * bigSumV2(a, b-1, M);

int bigSumV2( int a, int n, int M){

    // base case
    if ( n == 1 ) return 1 % M;

    int res = 0;

    if(n % 2 == 1) return (1 + a * bigSumV2(a, n-1, M)) % M;

    else {
        int halfRes;
        halfRes = bigSumV2(pow(a, 2), n/2, M);
        return (halfRes + a * halfRes ) % M;
    }
}

```

### Home Task

## Extended GCD & Modular Inverse

### Extended GCD;

```cpp

// returns gcd,
// x, y point refers a*x + b*y = gcd;

int extendedGCD(int a, int b, int& x, int& y){

    // base case
    if( a == 0){
        x = 0, y = 1;
        return b;
    }

    int x_, y_;
    int res = extendedGCD (b%a, a, x_, y_);

    x = y_ - (b/a) * x_;
    y = x_;

    /*
    fist itr
    a * x + b * y = d
    a * y_ - a * int(b/a) * x_ +  b * x _ = d
    a * y_ + b%a * x_ =  d

    2nd itr
    b%a * x_ + a * y_ = d

    first itr == 2nd itr;

    */
    return res;
}
```

### Modular Inverse ( b^-1 mod M ) বের করা;

#### Fermat's Little Theorem:

if x = b^-1^ mod, M then b\*x mod M = 1 and 0 <= x < M; [property of modular inveres]
for example modular inverse of 3 mod 7 is 5; not 12;

মড ইনভার্স এর কন্সেপ্টঃ ধরা যাক আমাদের দুটি সংখ্যার ভাগফল বের করতে হবে, খুব সহজ ব্যাপারই তো মনে হচ্ছে; কিন্তু এখন বিষয় টা যদি এমন হয় আমারা ভাগফলটা অনেক বড় এবং আমারা বড় বড় ডাটা টাইপের ভ্যারিয়াবলেও রাখতে পারছি না, সেক্ষত্রে আমারা চাইলে ভাগফলের মড হিসাব করতে পারি; আর মড জন্য আমাদের ডাটাটাইপের সবচেয়ে বড় নাম্বারটা ব্যাবহার করতে পারি, এখন আমাদেরকে কেউ ভাগ করেতে দিলে আমারা বলে দিব এই নাম্বারটা দিয়ে মড করা আছে আমাদের ভাগফল সে চাইলে তার উত্তরকে মড করে মিলিয়ে নিতে পারে;

কিন্তু ঝামেলা হল; ভাগের জন্য মড অপারেশনটা ভিন্ন ধরনের অন্যা অপারেশনে আমারা জাস্ট অপারেশন করে যখনি আউট অফ বাউন্ড হওয়ার চান্স দেখি আমারা মড করে ফেলি; কিন্তু ভাগের ক্ষেত্রে আমাদের নতুন একটা কন্সেপ্ট এর ধারনা লাগে `inverse mod`

যেমনঃ
a*b mod M = (a mod M * b \* mod M ) mod M;
a + b mod M = (a mod M + b mod M ) mod M;

but for division operation:

a / b mod M != (a mod M )/ (b mod M );
কারন কিন্তু সহজ M যদি b এর সমান হয় তাইলেই তো (a mod M) / 0 হয়ে যাবে; শুন্য দিয়ে ভাগ কি ভয়ানক ব্যাপার  
আমাদের যেটা করতে হবে সেটা হল ঃ

a / b mod M = a \* (b^-1 mod M) এই b^-1 mod M কেই পড়া হয় মডিউলার ইনভার্স অফ b mod M;

প্রথমেই বলে রাখি মডিউলার ইনভার্স করার জন্য দুটি নাম্বার লাগে; আর যেকোনো দুটি নাম্বার এর কিন্তু মডিউলার ইনভার্স থাকে না;
`মডিউলার ইনভার্স এক্সিস্ট করার জন্য সংখ্যা দুটিকে হতে হবে কো প্রাইম`
যেমন ঃ ২, ৫ বা ৩, ১৬ এর মডিউলার ইনভার্স আছে; কিন্তু ২, ১৬ এর কিন্তু নেই;

মডিউলার ইনভার্স দুই ভাবে বের করা শিখব আমরাঃ

- সূত্র ব্যবহার করে (Fermat's Little Theorem)
- এক্সটেন্ডেড জি সি ডি ব্যাবহার করে

**সূত্র:**

`b^-1 mod M` এ M যদি মৌলিক সংখ্যা হয় তাইলে `ইনভার্স মডিউলো অফ ( b mod M )` = `b^-1 mod M = b^(M-2) mod M`
কারন আমারা জানি মৌলিক সংখ্যার ধর্ম অনুযায়ী ঃ
if M is a prime number then` b^(M - 1) ≡ 1 mod M`; now `b^-1 _ b^(M-1 ) = b^-1 _ 1 mod M` [ product rule for MOD operation ]
we get `**b^-1 mod M = b^(M-2) mod M**`

NB:` b^(M - 1) ≡ 1 mod M` এ `"≡"` সাইন`congrunce`বোঝাতে ব্যাবহার করা হয়; আর পড়া হয়ঃ left side is a congruent module M of right side; এক্ষেত্রে `b^(M - 1) , 1 `দুটি নাম্বার ই `mod M` এর কনগ্রুয়েন্ট; অর্থাৎ দুই জনকেই M দিয়ে মড করলে একই ভাগশেষ পাওয়া যাবে বা `b^(M - 1) mod M = 1 mod M`

b. আর যদি M প্রাইম নাম্বার না হয় সেক্ষেত্রে যদি b, M কোপ্রাইম হয়; ( কোনো কমন গুননীয়ক না থাকে )
তবে আমাদের **b^-1 mod M = b<sup>ϕ(m) - 1</sup> mod M**

এখানে ϕ(m) হল অয়লার এর টোসান্ট ফাংশন; [ ১ এর চেয়ে বড় m থেকে ছোটো `কয়টা সংখ্যা` আছে যার সাথে m এর কোনো সাধারন গুননীয়ক নেই ]
যেমন ϕ(১২) = ৪, এবং সখ্যা গুলো হল ঃ ১, ৫, ৭, ১১; ϕ(m) এর মান ১ থেকে ছোট হতে পারে না; কারন সেখানে ১ ইনক্লুডেড থাকবে;

> so b <sup>-1</sup> mod M = b<sup>M-2</sup> mod M `if M is prime`

> or b <sup>-1</sup> mod M = b<sup>ϕ(m)-1</sup> mod M `if b, M are co-prime`

```cpp
// for larger value of M is this result can easily get out of bound
// Fermat's Little theorem
int modular_inverse(int b, int M){
    int gcd = gcdGen(b, M);

    if( isPrime(M) == true )return pow(b, M-2) mod M;

    if(gcd != 1) return -1;// not co-prime;
    else{
        int totient = totientFunc(M);
        return pow(b, totient -1) mod M;
    }
}

```

##### More efficient power funciton by using efficient power function

```cpp

long long modularExponentiation(long long a,long long b)
    {
        if(b==0) return 1;

        if(b%2==0)
        {
            return modularExponentiation((long long)(a % M * a % M) % M,b/2) % M;
        }else{
            return ((long long)a%M*modularExponentiation(a, b-1) % M) % M;
        }

    }

int modular_inverse(int b, int M){
    int gcd = gcdGen(b, M);

    if( isPrime(M) == true )return modularExponentiation(b, M-2) mod M;

    if(gcd != 1) return -1;// not co-prime;
    else{
        int totient = totientFunc(M);
        return modularExponentiation(b, totient -1) mod M;
    }
}

```

#### Extended GCD Method

২। দ্বিতীয় পদ্ধতিঃ extended GCD ব্যাবহার করে; আমাদের b <sup> -1 </sup> mod M এর জন্য এমনটা x খুজে বের করতে হবে যেন, b\*x mod M = 1 হয়; বা bx - ym = 1;
এখন আমরা extended GCD মাধ্যমে দেখতে পারি (x, m) এর gcd 1 কিনা ? আর যদি 1 হয় তাইলে extended gcd আমাদের সেই (x, y) খুজে দিতে পারবে;

কারনঃ ফাংশনে extended_gcd(a,b,x,y) পাঠালে, ax + by = gcd এর জন্য x, y ভ্যালু বের করে দেয়; সেখান থেকে আমরা x টা নিয়ে নিলেই ল্যাটা চুকে গেল;

```cpp
long int modInverse(long long int b, long long int m)
{

    long long int x, y; // used in extended GCD algorithm
    long long int g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x % m + m) % m;
    // we use mod operation for efficiency's sake
    // also m is added to handle minus values that can be generated from extended GCD;
}

```

## Combinatronics & Factorial Problems

### ১০০! এর শেষে কটি শূন্য আছে ?

আমাদের ফ্যাক্টরিয়াল বের করার কোনো দরকার নেই!

```cpp
//number of zeroes in 100!
// or number of 5 in the prime factoraization of 100!
// generally number of prime numbe a, in b!'s prime factorization

// number of a = b/a + b/a^2 + b/a^3 +... untill this term gets zero

int number_of_a_int_b_prime_factoriazation( int a, int b){
    int res = 0;
    while(b/a){
        res += b/a;
        a = a*a;
    }
    return res;
}
```

### Calculate the Number of Digits in x!

```cpp
// number of digits in factorial
// fact(5) = 120 = 1*10^(2.xx);
// if we take log of (fact(5)) = 2.xx;
// so floor(2.xx) + 1 = 3; is the answer
// also
// log(fact(5)) = log (1*2*3*4*5);

int factorialDigit(int a){
    double res = 0;
    for(int i = 1; i <= a; i++){
        res += log10(i);
    }
    return res + 1;
}
```

### Efficient Combination: nCr

#### Using Sequential Multiplication

nCr = n!/((n-r)!\*r!)
সূত্রটায় সমস্যা হল আমারা খুব সহজেই ফাক্টোরিয়াল এর জন্য ইন্টিজার ওভারফ্লোতে পরে যেতে পারি, ওভারফ্লো এড়াবার একটা উপায় হতে পারে, sequencial multiplication ব্যাবহার করা n-r , r এর মধ্যে যেটা বড় সেটার ফ্যাক্টোরিয়াল দিয়ে n! কে ভাগ করা যেতে পারে; উপরে থাকবে কত গুলো সিকুয়েনশিয়াল ইন্টিজার এর গুনফল; তাকে নিচের ছোট ফাক্টোরিয়াল দিয়ে ভাগ করে ফলাফল পেতে পারি;

```cpp
//efficient combination
long long fact(int n){
    long long res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

long long sequMul(int a, int b){
    long long res = 1;
    for(int i = a; i <= b; i++){
        res *= i;
    }
    return res;
}

long long effi_ncr(long long n, long long r){
    if(n-r < r) r = n - r;
    long long tmp = sequMul(n-r + 1, n); // n-r is bigger than r;
    return tmp / fact(r);
}
```

##### Using Pascal Triangle

প্যাসকেল ট্রাইয়াংগেল দেখে আমারা খুব সহজেই nCr বের করতে পারি, আমাদের যেটা লাগবে সেটা হল আমরা n সাইজের একটা প্যাস্কেল ট্রাইয়াঙ্গেল বানাবো এবং এর শেষ row এর r তম ইন্ডেক্স এ গিয়ে যে নাম্বারটা পাবো সেটাই হল আমাদের উত্তর;
উদাহরন দিয়ে দেখানো যাকঃ

                ১        ----> ০
              ১   ১       ---> ১
            ১   ২   ১      --> ২
          ১   ৩   ৩  ১    ---> ৩

হিসাব করতে বসি আমাদের যদি বলা হয় 3C2 কত?
আমারা প্যাস্কেল ট্রাইঙ্গেল এর ৩ নম্বর রো এর ২ নম্ব্র কলাম এ যাব, দেখব আছে ৩; সুতরাং উত্তর ৩;

আরেকটু খেয়াল করলে দেখব আমাদের নির্দিস্ট n এর জন্য পুরো ট্রাইঙ্গেল রাখার দরকার নেই, শুধু লাস্টের ধাপটা রাখলেই চলে; তাহলে লাস্ট এর ধাপ লেখার একটা কোড লিখে ফেললেই চলে; আমারা আসলে DP ব্যাবহার করে খুব সহজেই কোডটা লিখে নিতে পারি;

```cpp
int ncr_mod_pascalTri(int n, int r, int P){
    // we only need values up to r to calulate rth value of pascal
    // triangle so we take r+1 sized array
    // in normal pascal it should be pascalRow(n+1, 0);
    vector<int> pascalRow(r+1, 0);
    // first row of pascal triangle; base case
    pascalRow[0] = 1;
    for(int i = 1; i <= n; i++){
        // we could start from j = i, but ast we don't really need
        // the values i > j, we don't calculate them;
        for( int j = min(i,r); j > 0; j--){
            // নতুন রোএর jth number = আগের রো এর jth number ও j-1th নাম্বার এর যোগফল;
            pascalRow[j] = pascalRow[j] + pascalRow[j - 1]%P;
        }
    }

    return pascalRow[r];
}

```

এই প্যাস্কেল ট্রাইঙ্গেল থেকেই কিন্তু combination এর একটা প্রোপার্টি অভজার্ভ করা যায়ঃ
$\binom{n}{r}$ = $\binom{n-1}{r}$ + $\binom{n-1}{r-1}$

##### Building Whole Pascal Triangle Or Should I say Top Down DP for Combiantion

ব্যাসিকালি আগের কোডটাই বাট আমরা পুরা ট্রাইঙ্গেলকেই সেভ করে রাখব!

```cpp

```

## Deep dive into modular arithmatics

### Fermit's Little Theorem

### Lucas's Theorem

বড় সংখ্যার কম্বিনেশন বের করে মড করতে বলা হলে আমরা খুব সহজেই variable size limit এক্সিট করে ফেলতে পারি, একটা উপায় হতে পারে কম্বিনেশনের মড বের করার ঃ লুকাস থিওরেম; লুকাস থিওরেম বলে, দুটি নাম্বার এর কম্বিনেশনের P মড হবে, সংখ্যা দুটির P বেসড রিপ্রেজেন্টেশনের সেইম পজিশন নাম্বারদের নিজেদের মধ্যেকার কম্বিনেশন মড P এর গুনফল;

to make things clearer; lets say we have to calculate 25 C 8 MOD 13;

so by lucas's theorem we need to reduce n = 36 as 13 based representation

> so 25 = (25/13 ) * 13 + 25 % 13 = 1*13 + 12;

and for r = 8

> 8 = 0 \* 13 + 8;

> 25 = 1*13 + 12;
> 8 = 0*13 + 8;

> now by lucas's theorem,
> 36 C 8 mod 13 = (1 C 0 mod 13 )\* (12 C 8 mod 13) = 1 \* (495 mod 13) = 1;

> with-out lucus's (25! /( 8! \* 17! )) mod 13 = 1081575 mod 13 = 1;

```cpp

int ncr_lucus(int n, int r, int P){
    // base case
    if(r == 0 ) return 1;

    // computing current ni and ri from P based representation
    int ni = n % P, ri = r%p;
    return ncr_lucus(n/p, r/p, P) * generic_ncr(ni, ri, P);
    // here generic_ncr is any function that can calculate ncr for smaller number and then mod the result with P;

}


```

### Calculating nCr mod P

I will add this later;
Find it on my GeekForGeeks

### Dearrangement Number (D)

n সংখ্যক লোক ও n সংখ্যক রঙের টুপি থাকলে, টুপি আর লোক গুলোকে কতভাবে সাজানো যায় যাতে কোনো লোক তার টুপি না পায় ?
করা যেতে পারে
১। ডিয়ারেঞ্জমেট নাম্বার দিয়ে
২। ইনক্লুশন এক্সক্লুশন প্রিন্সিপাল ব্যাবহার করে (DP)

D <sub>n</sub> = (n-1) _ D<sub>n-2</sub> + (n-1) _ D <sub> n-1 </sub>

Base case: D<sub>0</sub> = 1, D<sub>1</sub> = 1;

```cpp
// dearrangement number
int dearrangementNum(int n){
    if( n == 0) return 1;
    else if( n == 1) return 0;
    else return (n-1)*dearrangementNum(n-2) + (n-1)*dearrangementNum(n-1);
}

```

#### Using Inclusing Exclusion Principal

```cpp
int fact(int n){
    int res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

// dearrangement number
// by exclusion inclusion principle
int dearrangementNum(int n){
    int maxChoice = (1 << n ) - 1;
    int totalPermutations = fact(n);
    for( int mask = 1; mask <= maxChoice; mask++){
        int i = __builtin_popcount(mask); // i = rightPlaceHolders Count;
        if( i & 1){ //i is odd
            totalPermutations -= fact(n-i);
        } else {
            totalPermutations += fact(n-i);
        }
    }
    return totalPermutations;

}
```

#### Also using Formula like n!/e

Turnsout if we rounding of $\frac{n!}{e}$ to it's closest number we can find the result

> D <sub>n</sub> = closest Integer (n!/e)
> if the n!/e's decimal values are greater than .5 then take ceiling value or take floor val;

### Catalan Number

Catalan Number C<sub>n</sub> = $\binom{2n}{n}$ - $\binom{2n}{n+1}$

অনেক ধরনের প্রশ্নের উত্তর আছে কাটালান নাম্বার এর কাছে, যেমন n টি X, এবং n টি Y দিয়ে কতগুলো Dyck word তৈরি করা যায় ? ডাইক ওয়ার্ড হল, সেইসব ওয়ার্ড যার সেকোন প্রিফিক্স ওয়ার্ড এ Y এর সংখ্যা X এর চেয়ে বেশি নয়; ফর n = 3
উত্তর C<sub>3</sub> = 5 {XXXYYY, XXYYXY, XXYXYY, XYXYXY, XYXXYY}

একদম একই সমস্যা হল n টি "(" ও n টি ")" দিয়ে কত গুলো সঠিক parenthesis expression বানানো যায় ? আগের মতই C<sub>3</sub> = 5;

> C<sub>n</sub> = $\frac{n}{n+1}\binom{2n}{n}$

এরকম আরো কিছু n leaf ওয়ালা কতগুলো full binaray tree আছে [ যেখানে প্রতি নোড এ হয় o বা 2 টি করে চাইল্ড নোড আছে ]
উত্তর: c<sub>n-1</sub>

### Stirling Number

#### Stirling Number of First Kind

#### Stirling Number of Second Kind

### Matrix Calculation

#### Fibonacci

#### Stirling Number

## Learn Bitset
