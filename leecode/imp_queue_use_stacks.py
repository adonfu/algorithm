# -*- coding:utf-8 -*-
"""
232. Implement Queue using Stacks
"""
class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.sk = []


    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: None
        """
        self.sk.append(x)


    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if not self.empty():
            return self.sk.pop(0)
        else:
            return -1


    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if not self.empty():
            return self.sk[0]
        else:
            return -1

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        if len(self.sk):
            return False
        else:
            return True


# Your MyQueue object will be instantiated and called as such:
obj = MyQueue()
obj.push(1)
param_2 = obj.pop()
print param_2
param_3 = obj.peek()
print param_3
param_4 = obj.empty()
print param_4
