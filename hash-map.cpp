//From: https://leetcode.com/problems/design-hashmap/discuss/152746/Java-Solution
struct KVNode {
    int key;
    int value;
    KVNode* next;
    KVNode(int k, int v) : key(k), value(v), next(NULL) {}
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        KVNode* pre = find(key);
        if (pre -> next) {
            pre -> next -> value = value;
        } else {
            pre -> next = new KVNode(key, value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        KVNode* pre = find(key);
        if (pre && pre -> next) {
            return pre -> next -> value;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        KVNode* pre = find(key);
        if (pre && pre -> next) {
            KVNode* temp = pre -> next;
            pre -> next = pre -> next -> next;
            temp -> next = NULL;
            delete temp;
        }
    }
private:
    vector<KVNode*> buckets = vector<KVNode*>(10000, new KVNode(-1, -1));
    
    int index(int key) {
        return key % 10000;
    }
    
    KVNode* find(int key) {
        KVNode *cur = buckets[index(key)], *pre = NULL;
        while (cur && cur -> key != key) {
            pre = cur;
            cur = cur -> next;
        }
        return pre;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */


/********More generic with templates*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

template<class K, class V>
class KVNode {
    public:
    K key;
    V value;
    KVNode* next;
    KVNode* prev;
    KVNode(K k, V v) : key(k), value(v), next(NULL), prev(NULL) {}
};

template<class K, class V>
class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(K key, V value) {
        KVNode<K, V>* node = find(key);
        if (node) {
            node-> value = value;
        } else {
            KVNode<K, V> *cur = buckets[index(key)]; // get first node 
            node = new KVNode<K, V>(key, value);
            node->next=cur;
            if(cur) cur->prev= node;
            buckets[index(key)] = node; // important line!!!!
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    V get(K key) {
        KVNode<K, V>* node = find(key);
        if (node) {
            return node->value;
        }
        return NULL;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(K key) {
        KVNode<K, V>* node = find(key);
        if (node) {
            if(node->prev) node->prev->next = node->next;
            if(node->next) node->next->prev = node->prev;
            delete node;
        }
    }
private:
    
    vector<KVNode<K, V>*> buckets = vector<KVNode<K, V>*>(1000);

    int index(K key) {
        return hash<K>()(key) % 1000;
    }
    
    KVNode<K, V>* find(K key) {
        KVNode<K, V> *cur = buckets[index(key)], *node = cur;
        while (node && node->key != key) {
            node = node->next;
        }
        return node;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

int main(){
    MyHashMap<int, int> mp;
    mp.put(1, 2);
    mp.put(1, 3);
    mp.put(2, 6);
    cout<<mp.get(1)<<endl;
    cout<<mp.get(2)<<endl;
    mp.remove(1);
    cout<<mp.get(1)<<endl;
    cout<<mp.get(2)<<endl;


    MyHashMap<string, int> mp1;
    mp1.put("ab", 3);
    cout<<mp1.get("ab");
    return 0;
}









