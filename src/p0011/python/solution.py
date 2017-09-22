from typing import List


class Solution:
    def maxArea(self, h: List[int]) -> int:
        result, i, j = 0, 0, len(h) - 1
        while i < j:
            if h[i] < h[j]:
                result, i = max(result, (j - i) * h[i]), i + 1
            else:
                result, j = max(result, (j - i) * h[j]), j - 1
        return result
