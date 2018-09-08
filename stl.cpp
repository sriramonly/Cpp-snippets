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


