package main

func romanToInt(s string) int {
	c2n := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	result, prev, curr := 0, 0, 0
	for i := len(s); i > 0; prev = curr {
		i--
		curr = c2n[s[i]]
		if curr < prev {
			result -= curr
		} else {
			result += curr
		}
	}
	return result
}
