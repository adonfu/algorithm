# -*- coding:utf-8 -*-
"""
225. Implement Stack using Queues
"""
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        if not self.empty():
            return self.q.pop()
        else:
            return -1


    def top(self):
        """
        Get the top element.
        :rtype: int
        """

        if not self.empty():
            return self.q[-1]
        else:
            return -1

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if len(self.q):
            return False
        else:
            return True



# Your MyStack object will be instantiated and called as such:
obj = MyStack()
obj.push(2)
param_2 = obj.pop()
param_3 = obj.top()
param_4 = obj.empty()
print param_2,param_3,param_4
