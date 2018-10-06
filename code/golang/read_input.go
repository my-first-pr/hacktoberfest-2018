package main

import (
	"fmt"
)

func main() {
	fmt.Println("Hi! Please enter your name...")
	var inpt string
	fmt.Scan(&inpt)
	fmt.Printf("Hello %s, wellcome on Hacktoberfest!\n", inpt)
}
