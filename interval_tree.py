# courtesy: https://leetcode.com/problems/merge-intervals/discuss/110825/AC-Python-solution-interval-tree-easy-to-understand-beat-15.77
class Node(object):
    def init(self, startIdx, endIdx, next):
    self.startIdx = startIdx
    self.endIdx = endIdx
    # self.val = val
    self.nextnode = next

#Definition for an interval.
class Interval(object):
    def init(self, s=0, e=0):
    self.start = s
    self.end = e
class IntervalTree(object):
    def init(self, startIdx, endIdx):
    self.root = Node(startIdx, endIdx, None)

def add_interval(self, building):
    [l, r] = building
    # print "add_interval l = ", l, " r = ", r
    curNode = self.root
    def helper(l, r, curNode):
        if curNode.startIdx <= l:
            # print "1.0 curNode.startIdx = ", curNode.startIdx, " curNode.endIdx = ", curNode.endIdx

            if curNode.endIdx < l:
                if curNode.nextnode == None:
                    # print "need create new node"
                    newNode = Node(l, r, None)
                    curNode.nextnode = newNode
                else:
                    helper(l, r, curNode.nextnode)
            else:
                if curNode.endIdx  < r:
                    # print "need expand right bond of current node"
                    curNode.endIdx = r
    helper(l, r, curNode)

def printTree(self):
    res = []
    curNode = self.root
    while curNode:
        # print "curNode.startIdx = ", curNode.startIdx, " curNode.endIdx = "
        res.append([curNode.startIdx, curNode.endIdx])
        curNode = curNode.nextnode
    return res

class Solution(object):
    def merge(self, intervals):
    """
    :type intervals: List[Interval]
    :rtype: List[Interval]
    """
        # print "intervals = ", intervals
        lenIntervals = len(intervals)
        # print "lenIntervals = ", lenIntervals
        if lenIntervals == 0:
            return []
        intervals.sort(key=lambda x:x.start)
        tree = IntervalTree(intervals[0].start, intervals[0].end)
        for i in range(1, lenIntervals):
            # print "intervals[i] = ", intervals[i]
            tree.add_interval([intervals[i].start, intervals[i].end])
        res = tree.printTree()
        # print "res = ", res
        return res
