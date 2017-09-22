package main

func numJewelsInStones(J string, S string) int {
    num := int(0)
    set := make(map[int32]struct{})
    for _, c := range J {
        set[c] = struct{}{}
    }
    for _, c := range S {
        if _, ok := set[c]; ok {
            num++
        }
    }
    return num
}

