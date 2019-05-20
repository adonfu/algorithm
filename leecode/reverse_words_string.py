# -*- coding:utf-8 -*-
"""
151. Reverse Words in a String
"""
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        if len(s) == 0:
            return ''
        else:
            s = s.strip(' ')
            li = s.split(' ')
            rlt = ''
            while len(li) > 0:
                tem = li.pop()
                if tem <> '':
                    rlt = rlt + tem + ' '
            return rlt.strip(' ')
