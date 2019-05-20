# -*- coding:utf-8 -*-
"""
20. Valid Parentheses
使用堆栈, 参考stack_use_queue.py and imp_queue_use_stacks.py
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
        :type x: char
        :rtype: None
        """
        self.sk.append(x)


    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: char
        """
        if not self.empty():
            return self.sk.pop(0)
        else:
            return None


    def peek(self):
        """
        Get the front element.
        :rtype: char
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

class MyStack(object):
    def __init__(self):
        self.q = []

    def push(self, x):
        """
        Push element x onto stack.
        :type x: char
        :rtype: None
        """
        self.q.append(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: char
        """
        if not self.empty():
            return self.q.pop()
        else:
            return None

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if len(self.q):
            return False
        else:
            return True


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        if not s:
            return True

        left_stack = MyStack()

        for _, elem in enumerate(s):

            if elem in ['(', '{', '[']:
                left_stack.push(elem)
                continue

            left = left_stack.pop()
            if left != '(' and elem ==')':
                return False
            if left !='{' and elem == '}':
                return False
            if left != '[' and elem == ']':
                return False

        if left_stack.empty():
            return True
        else:
            return False
