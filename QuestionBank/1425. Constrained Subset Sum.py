from typing import List


class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        dq = []
        dp = nums.copy()
        total_max = 0
        for i in range(len(dp)):
            cur_val = dp[i]
            if len(dq) > 0:
                cur_val += dp[dq[0]]
            if len(dq) > 0 and dq[0] == i - k:
                dq.pop(0)
            while len(dq) > 0 and dp[dq[len(dq) - 1]] < cur_val:
                dq.pop(len(dq) - 1)
            dq.append(i)
            dp[i] = max(0, cur_val)
            if cur_val > total_max:
                total_max = cur_val
        if total_max == 0:
            return max(nums)
        return total_max


s = Solution()
a = s.constrainedSubsetSum([-5266,4019,7336,-3681,-5767], 2)
print(a)
