# -*- coding:utf-8 -*-
"""
1. Two Sum
"""
class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        d = {}
        for i in range(len(num)):
            if d.has_key(num[i]):
                return (d[num[i]]+1, i+1)
            else:
                d[target - num[i]] = i
