from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        n = len(nums)
        for i, x in enumerate(nums):
            if x > 0:
                break
            if i > 0 and nums[i - 1] == x:
                continue
            j, k = i + 1, n - 1
            while j < k:
                y, z = nums[j], nums[k]
                if (j > i + 1 and nums[j - 1] == y) or x + y + z < 0:
                    j += 1
                    continue
                if (k < n - 1 and nums[k + 1] == z) or x + y + z > 0:
                    k -= 1
                    continue
                result.append([x, y, z])
                j += 1
                k -= 1
        return result
