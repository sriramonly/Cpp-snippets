// Courtesy: https://codeforces.com/blog/entry/15643
// use the following header file instead of individual headers, this makes sure all others are included
#include <bits/stdc++.h> 
using namespace std;

// find hash value of an object.
// Usage: hash<type>()(variable)
std::cout <<  hash<string>()("Abc"); // prints some hashcode say: 8827185239717541355
int x=69;
cout<<hash<int>()(x)<<endl;
  
//sometimes unordered_map becames so slow. But it can improve with this two lines of code:
unordered_map<int,int>mp;
mp.reserve(1024);
mp.max_load_factor(0.25);
//With above two lines unordered_map become about 10 times faster.

// tie: Creates a tuple of lvalue references to its arguments or instances of std::ignore.
// std::tie can be used to unpack a tuple:
int a,b,c;
tie(a,b,c) = make_tuple(1,2,3); // assign
tie(a,b) = make_tuple(b,a); // swap(a,b)
tuple<int, int, int, char> t (3, 4, 5, 'g');
int a, b;
tie(b, ignore, a, ignore) = t; // use ignore to ignore a value
cout << a << ' ' << b << '\n'; // prints 5 3


// lambdas
vector<int> v = {3, 1, 2, 1, 8};
sort(begin(v), end(v), [] (int a, int b) { return a > b; });
for (auto i: v) cout << i << ' ';

auto f = [] (int a, int b) -> int { return a + b; };
cout << f(1, 2); // prints "3"


pair<int, int> p;
vector<int> v;
p = {3, 4}; // insert into pair 
v = {4, 5}; // insert into vector
pair<int, pair<char, long long> > p;
p = {3, {'a', 8ll}}

// Hidden functions
__gcd(6, 9) // prints 3
__builtin_ctz(16) // prints 4: This function returns number of trailing 0-bits of x which starts from least significant bit position.
__builtin_clz(16) //= 27 : This function returns number of leading 0-bits of x which starts from most significant bit position
  __builtin_ffs(10) //=2: This function returns 1 + least significant 1-bit of x. 
  
// no need to declare type, use auto
set<int> s = {8, 2, 3, 1};
for (auto it: s)
    cout << it << ' ';  
