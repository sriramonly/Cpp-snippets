# Binary Indexed Tree
# Explanation: http://codeforces.com/blog/entry/619 
# that's the best explanation

# NOTE: this increments value at idx-th index by value [i.e. increase value by 'value']
def update(tree, A, idx, value):
    while idx <= len(A):
        tree[idx] += value
        idx += idx & -idx
        
def query(tree, A, idx):
    s = 0
    while idx >= 0:
        s += tree[idx]
        idx -= idx & -idx
    return s

def initialize_BIT(A, tree):
    n = len(A)
    for i in range(n+1):
        tree.append(0)
    for i in range(1, n):
        update(tree, A, i, A[i])
        
n = int(raw_input('Enter number of elements in array: '))
input_array = list(map(int, raw_input('Elements in array').split()))
input_array.insert(0, 0)
tree = []
initialize_BIT(input_array, tree)    

print 'Initial Fenwick Tree:'
for i in range(1, n+1):
    print tree[i]

# find sum(4) - sum(1), works only if input_array is at least of size 4
if len(input_array) >= 4:
    print tree[4]-tree[1]

# update the 4th index in original input_array to 7
update(tree, input_array, 1,7)

print 'Final Fenwick Tree:'
for i in range(1, n+1):
    print tree[i]



