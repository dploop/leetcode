class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = []
        lookup = {}
        for j, y in enumerate(nums):
            x = target - y
            i = lookup.get(x)
            if i is not None:
                result.append(i)
                result.append(j)
                break
            lookup[y] = j
        return result
