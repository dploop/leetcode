package main

import (
	"math"
)

func myAtoi(s string) int {

	i := 0

	for i < len(s) && s[i] == ' ' {
		i++
	}

	sign := int32(1)
	if i < len(s) {
		switch s[i] {
		case '-': sign = -1; i++
		case '+': i++
		}
	}

	y := int32(0)
	for i < len(s) && '0' <= s[i] && s[i] <= '9' {
		if y > math.MaxInt32 / 10 || y == math.MaxInt32 / 10 && s[i] > '7' {
			if sign > 0 {
				return math.MaxInt32
			} else {
				return math.MinInt32
			}
		}
		y = y * 10 + int32(s[i] - '0')
		i++
	}

	return int(sign * y)
}
