class Solution {
    public int myAtoi(String s) {

        int i = 0;

        while (i < s.length() && s.charAt(i) == ' ') i++;

        int sign = 1;
        if (i < s.length()) {
            switch (s.charAt(i)) {
                case '-': sign = -1;
                case '+': i++; break;
            }
        }

        int y = 0;
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            if (y > Integer.MAX_VALUE / 10 || (y == Integer.MAX_VALUE / 10 && s.charAt(i) > '7')) {
                return (sign > 0) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            y = y * 10 + s.charAt(i) - '0'; i++;
        }

        return sign * y;
    }
}
