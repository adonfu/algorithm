# -*- coding:utf-8 -*-
"""
33. Search in Rotated Sorted Array
"""
class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def search(self, A, target):
        # try:
        #     return A.index(target)
        # except:
        #     return -1

        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = left + (right - left) / 2
            if nums[mid] == target:
                return mid
            if nums[mid] < nums[right]:
                if nums[mid] < target and nums[right] >= target:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if nums[left] <= target and nums[mid] > target:
                    right = mid - 1
                else:
                    left = mid + 1
        return -1;
