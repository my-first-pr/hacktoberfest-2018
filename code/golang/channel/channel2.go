package main

import (
	"fmt"
)

func sampleChannel(word string) string {
	return word + " World."
}

func main() {
	a := make(chan string)
	go func() {
		a <- sampleChannel("Hello")
	}()

	fmt.Println(<-a)
}
