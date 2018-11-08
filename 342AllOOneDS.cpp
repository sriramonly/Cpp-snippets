class AllOne {
    typedef struct Node {
        int value;
        unordered_set<string> keys;
        shared_ptr<Node> prev = nullptr;
        shared_ptr<Node> next = nullptr;
    };
    
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        //cout << "Inc:" << key << endl;
        int newValue = 1;        
        if(keyToValue.find(key) == keyToValue.end())
        {
            AddOrUpdateBeforeNode(key, newValue, nullptr, minNode);            
        }
        else
        {
            // Key is found. PrevValue must have valid node.
            int prevValue = keyToValue[key];
            newValue = prevValue + 1;
            auto prevNode = valueToKey[prevValue];
            auto nextNode = prevNode->next;
            prevNode = RemoveKey(key, prevNode);
            AddOrUpdateBeforeNode(key, newValue, prevNode, nextNode);            
        }
        keyToValue[key] = newValue;        
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        //cout << "Dec:" << key << endl;
        if(keyToValue.find(key) == keyToValue.end())
        {
            return;            
        }
        int prevValue = keyToValue[key];
        int newValue = prevValue - 1;        
        auto prevNode = valueToKey[prevValue];
        auto nextNode = prevNode->next;
        prevNode = RemoveKey(key, prevNode);
        if(newValue > 0)
        {
            keyToValue[key] = newValue;
            AddOrUpdateBeforeNode(key, newValue, prevNode, nextNode);                        
        }   
        else
        {
            keyToValue.erase(key);
        }
        if(minNode)
            cout << minNode->value;
        if(maxNode)
            cout << maxNode->value;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(maxNode == nullptr)
        {
            return "";
        }
        return *(maxNode->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(minNode == nullptr)
        {
            return "";
        }
        return *(minNode->keys.begin());
    }
    
private:
    
    shared_ptr<Node> RemoveKey(const string& key, shared_ptr<Node> nodeToRemove)
    {
        nodeToRemove->keys.erase(key);
        if(nodeToRemove->keys.size() > 0)
        {
            return nodeToRemove;
        }
        
        auto prevNode = nodeToRemove->prev;
        auto nextNode = nodeToRemove->next;
        if(prevNode)
        {
            prevNode->next = nextNode;
        }
        if(nextNode)
        {
            nextNode->prev = prevNode;
        }
        if(minNode->value == nodeToRemove->value)
        {
            minNode = nextNode;
        }
        if(maxNode->value == nodeToRemove->value)
        {
            maxNode = prevNode;
        }
        valueToKey.erase(nodeToRemove->value);
        return prevNode;
    }
    
    void AddOrUpdateBeforeNode(const string& key, int newValue, shared_ptr<Node> prevNode, shared_ptr<Node> nextNode)
    {
        // If value is not found, create new node; else just add key to existing node.
        if(valueToKey.find(newValue) ==  valueToKey.end())
        {
            shared_ptr<Node> node(new Node());
            node->value = newValue;
            node->keys.insert(key);
            node->next = nextNode;
            node->prev = prevNode;
            if(nextNode)
            {   
                nextNode->prev = node;
            }
            if(prevNode)
            {
                prevNode->next = node;
            }
            if((!minNode) || (newValue < minNode->value))
            {
                minNode = node;
            }
            if((!maxNode) || (newValue  > maxNode->value))
            {
                maxNode = node;
            }
            valueToKey[newValue] = node;                
        }
        else
        {
            valueToKey[newValue]->keys.insert(key);
        }
    }
    
    
    unordered_map<string, int> keyToValue;
    unordered_map<int, shared_ptr<Node>> valueToKey;
    shared_ptr<Node> maxNode = nullptr;
    shared_ptr<Node> minNode = nullptr;    
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
