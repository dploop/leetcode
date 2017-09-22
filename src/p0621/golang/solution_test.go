package main

import (
    "testing"
)

func TestLeastInterval(t *testing.T) {
    if leastInterval([]byte{'A','A','A','B','B','B'}, 2) != 8 {
        t.Errorf("wrong answer")
    }
}
