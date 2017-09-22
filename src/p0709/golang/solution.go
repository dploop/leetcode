package main

func toLowerCase(str string) string {
	chars := []byte(nil)
	for _, char := range []byte(str) {
		if char >= 'A' && char <= 'Z' {
			char = char + 'a' - 'A'
		}
		chars = append(chars, char)
	}
	return string(chars)
}
