# -*- coding:utf-8 -*-
"""
### 136. Single Number
"""

class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        A.sort()
        len_a = len(A)
        i = 0
        j = 1
        while len_a > i and len_a > j:
            if A[i] == A[j]:
                i = i + 2
                j = j + 2
            else:
                return A[i]
        if len_a == j:
            return A[i]
    # for elem in A:
    #     if A.count(elem) == 1:
    #         return elem
