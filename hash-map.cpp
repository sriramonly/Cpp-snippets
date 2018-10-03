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
