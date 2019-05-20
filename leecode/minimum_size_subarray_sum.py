# -*- coding:utf-8 -*-
"""
209. Minimum Size Subarray Sum
"""
class Solution:
    # @param {integer} s
    # @param {integer[]} nums
    # @return {integer}
    def minSubArrayLen(self, s, nums):
        if len(nums) == 0:
            return 0
        min = len(nums)
        i = 0
        j = 0
        while j<len(nums):
            s -= nums[j]
            while s <= 0:
                if min > j-i+1:
                    min = j-i+1
                s += nums[i]
                i += 1
            j += 1
        if min == len(nums):
            return 0
        return min
