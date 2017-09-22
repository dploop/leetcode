package main

func reverse(z int) int {
	x, y := int32(z), int32(0)
	for ; x != 0; x /= 10 {
		n := y * 10 + x % 10
		if (n - x % 10) / 10 != y {
			y = 0; break
		}
		y = n
	}
	return int(y)
}
