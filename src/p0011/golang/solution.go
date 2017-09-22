package main

func maxArea(h []int) int {
	result, i, j := 0, 0, len(h) - 1
	for i < j {
		if h[i] < h[j] {
			if result < (j - i) * h[i] {
				result = (j - i) * h[i]
			}
			i++
		} else {
			if result < (j - i) * h[j] {
				result = (j - i) * h[j]
			}
			j--
		}
	}
	return result
}
