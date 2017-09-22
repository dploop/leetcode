class Solution:
    def myAtoi(self, s: str) -> int:

        i = 0

        while i < len(s) and s[i] == ' ':
            i += 1

        sign = 1
        if i < len(s):
            if s[i] == '-':
                sign = -1
                i += 1
            elif s[i] == '+':
                i += 1

        y = 0
        while i < len(s) and s[i].isdigit():
            if y > 0x7fffffff // 10 or (y == 0x7fffffff // 10 and s[i] > '7'):
                return 0x7fffffff if sign > 0 else -0x80000000
            y, i = y * 10 + int(s[i]), i + 1

        return sign * y


if __name__ == '__main__':
    sol = Solution()
    print(sol.myAtoi("2147483648"))
