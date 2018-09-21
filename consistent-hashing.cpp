#include<bits/stdc++.h>
using namespace std;

//adapted from: http://www.tom-e-white.com/2007/11/consistent-hashing.html

class ConsistentHash {
private:
   int numberOfReplicas;
   map<int, string> circle;

public:
  ConsistentHash(int numberOfReplicas, vector<string> &nodes) {
    this->numberOfReplicas = numberOfReplicas;
    for (string node : nodes) {
      add(node);
    }
  }

  void add(string node) {
    for (int i = 0; i < numberOfReplicas; i++) {
        int code = hash<string>()(node + to_string(i));
        circle[code] = node;
    }
  }

 void remove(string node) {
    for (int i = 0; i < numberOfReplicas; i++) {
        int code = hash<string>()(node + to_string(i));
      circle.erase(code);
    }
  }

 string get(string key) {
    if (circle.empty()) {
      return "";
    }

    int code = hash<string>()(key);
    if (circle.find(code) ==circle.end()) {
      if(circle.lower_bound(code) != circle.end()) return circle.lower_bound(code)->second;
      else return circle.begin()->second;
    }
    return circle.find(code)->second;
  } 

};

int main() {
    vector<string> v{"192.168.65.53", "192.168.65.101", "192.168.65.808"};
    ConsistentHash h(10, v);

    cout<<h.get("554")<<endl;
    h.add("192.168.65.54");
    cout<<h.get("554")<<endl;
    h.remove("192.168.65.101");
    cout<<h.get("554")<<endl;
    h.remove("192.168.65.100");
    cout<<h.get("554");
}
