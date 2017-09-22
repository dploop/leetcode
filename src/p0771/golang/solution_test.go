package main

import (
    "testing"
)

func TestNumJewelsInStones(t *testing.T) {
    if numJewelsInStones("aA", "aAAbbbb") != 3 {
        t.Errorf("wrong answer")
    }
    if numJewelsInStones("z", "ZZ") != 0 {
        t.Errorf("wrong answer")
    }
}
