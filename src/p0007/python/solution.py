class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            y = -int(str(-x)[::-1])
            if y < -(2 ** 31):
                y = 0
        else:
            y = int(str(x)[::-1])
            if y >= (2 ** 31):
                y = 0
        return y

