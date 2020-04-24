class Solution:
    def romanToInt(self, s: str) -> int:
        sym2val = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        res = 0
        pre = sym2val[s[0]]
        add_pre = True
        for i in s[1:]:
            val = sym2val[i]
            if val > pre:
                res += -pre
            else:
                res += pre
            pre = val
        res += pre
        return res
