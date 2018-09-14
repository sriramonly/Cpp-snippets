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
std::count(v.begin(), v.end(), 1);
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
set<int> myset;
set<int>::iterator itlow,itup;
for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
itlow=myset.lower_bound (30);                //       ^
itup=myset.upper_bound (60);                 //                   ^
// set lower_bound: An iterator to the the first element in the container which is not considered to go before val, or set::end if all elements are considered to go before val.


// Vector of 20 "Unknown" strings
vector< string > names(20, “Unknown”);
//matrix of size mxn filled with -1
vector< vector< int > > Matrix(m, vector< int >(n, -1));

// insert an item after the first
v.insert(1, 42); // Insert value 42 after the first

vector< int > X; 
sort(X.begin(), X.end()); // Sort array in ascending order
sort(X.rbegin(), X.rend()); // Sort arry in descending order using with reverse iterators

int data[5] = { 1, 5, 2, 4, 3 };
vector< int > X(data, data+5);
int v1 = *max_element(X.begin(), X.end()); // Returns value of max element in vector
int i1 = min_element(X.begin(), X.end()) – X.begin; // Returns index of min element in vector




void some_function(vector< int > v) { // Never do it : creates a copy of v
// ...
}
// Use this instead:
 void some_function(const vector< int >& v) { // OK: if changing v in some way, remove const
// ...
}

// string stream
void f(const string& s) { 
  // Construct an object to parse strings
  istringstream is(s); 
  // Vector to store data
  vector< int > v; 
  // Read integer while possible and add it to the vector
  int tmp;
  while(is >> tmp) {
    v.push_back(tmp);
  }
}

// using next_permutation
do {
  Solve(..., v);
} while(next_permutation(v.begin(), v.end());

      
// set from array 
int data[5] = { 5, 1, 4, 2, 3 };
set< int > S(data, data+5);
set< int > s(v.begin(), v.end()); 

        
// From my notes
//Convert string to uppercase:
transform(su.begin(), su.end(), su.begin(), ::toupper);

//Check if a character is punctuation mark:
int ispunct( int ch );
//Checks if the given character is a punctuation character as classified by the current C locale. The default C locale classifies the characters !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~ as punctuation.
//The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
//Return value: Non-zero value if the character is a punctuation character, zero otherwise.
//CHeck if character is alphanumeric i.e. letter or number
isalnum
//To modify characters in a string p, use this: 
for (auto & c: p) c = isalpha(c) ? tolower(c) : ' '; 

//Area of a triangle (a Leetcode question):
double area(int x1, int y1, int x2, int y2, int x3, int y3) {
return abs(0.5*(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))); }

//Algorithms
//Sum of a vector of ints: use accumulate():
accumulate(v.begin(), v.begin()+int(v.size()/2), 0) // sum of first half of vector

//random_shuffle()
Shuffle the elements in the vector:
#include <ctime>
// seed the random number generator (required)
std::srand (unsigned (std::time(0)));
std::random_shuffle(v.begin(), v.end());

//sort vector of structs/objects with custom comparator
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
vector<Interval> intervals;        
bool comparator(Interval i, Interval j) {
    return i.start <= j.start;
}        
sort(intervals.begin(), intervals.end(), comparator);
        
        
//binary_search()
//Determine whether item is in vector (returns bool):
std::cout << binary_search(v.begin(), v.end(), 'c') << std::endl;        

//String to integer:
std::stoi( str );
//Integer to string
to_string(i);//i is int

//Convert an string to an int
// first convert the string to a const char*
const char *c = s.c_str();
// then convert the char* to an int
int i = std::atoi(c);
// or do both steps at once
int i = std::atoi(s.c_str());

        
     
//for_each()
//Apply myfunction() to each member of the vector:
void myfunction(char c) {
    std::cout << c << std::endl;
}
std::for_each(v.begin(), v.end(), myfunction);        

//replace()
//Replace occurrences of 'a' with 'd' in the vector:
std::replace(v.begin(), v.end(), 'a', 'd');
        
//priority queue by default stored numbers in decreasing order. To use increasing order, initialize this way:
std::priority_queue<int, std::vector<int>, std::greater<int> > my_min_heap;
//Remove leading zeros from a string of integers:
std::string str = "0000000057"; 
str.erase(0, str.find_first_not_of('0')); //useful
assert(str == "57");
//**Split a string by a char**
vector<string> split(const string& s, char c) {
vector<string> v;
stringstream ss(s);
string x;
while (getline(ss, x, c))
v.push_back(x); 
return v; //this line is not needed 
}
//**Tokenizing the scanned line**
using stringstream class would help tokenize the string.
use the following::
#include<sstream> 
stringstream SS;
string s,s1; 
getline(cin, s); 
SS << s; 
do{ 
s1.erase(); // to remove all characters from s1. SS >> s1; cout << s1 << endl; 
} while(SS); 
SS.str(""); // to reuse the stringstream object.
C++ policy based data structure : [Read here](https://codeforces.com/blog/entry/11080) to find order k-th largest element  &  number of items in a set that are strictly smaller than an item in O(log n) time.
//Reserve size of a vector after declaring:
std::vector<int> vec1; vec1.**reserve**(30); // Allocate space for 30 items, but vec1 is still empty. 
std::vector<int> vec2; vec2.**resize**(30); // Allocate space for 30 items, and vec2 now contains 30 items.

//iterating a map c++11
unordered_map<int, int>mp;                                              
for(auto i: mp) { cout<<i.first<<" " << i.second};                                              
                                              
//iterating a map in reverse order                                              
for(map<int, vector<int>>::reverse_iterator it=bucket.rbegin(); it!=bucket.rend();it--) {..}

                                              
// List splicing
list<pair<int, int>> used;                                              
used.splice(used.begin(), used, cache[key]); // lru cache q

std::list<int> list1 = { 1, 2, 3, 4, 5 };
std::list<int> list2 = { 10, 20, 30, 40, 50 };

auto it = list1.begin();
std::advance(it, 2);

list1.splice(it, list2);
std::cout << "list1: " << list1 << "\n";
std::cout << "list2: " << list2 << "\n";

list2.splice(list2.begin(), list1, it, list1.end());
std::cout << "list1: " << list1 << "\n";
std::cout << "list2: " << list2 << "\n";                                              
/*output
list1:  1 2 10 20 30 40 50 3 4 5
list2: 
list1:  1 2 10 20 30 40 50
list2:  3 4 5 */                                             
                                             
// How to have a class member as a reference.(initializing it later in constructor)
class MyClass { 
    vector<int>& vec; 
  
public: 
    // this is the right way to assign 
    // the reference of stl container 
    MyClass(vector<int>& arr) 
        : vec(arr) 
    { 
    } 
    void print() 
    { 
        /// print the value of vector 
        for (int i = 0; i < vec.size(); i++) 
            cout << vec[i] << " "; 
    } 
}; 
  
                                              /
