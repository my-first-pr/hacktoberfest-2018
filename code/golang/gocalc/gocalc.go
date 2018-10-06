package main

import (
	"fmt"
)

var num1 int64
var num2 int64
var action string

func main() {
	fmt.Println("Enter firs number:")
	fmt.Scan(&num1)
	fmt.Println("Enter second number:")
	fmt.Scan(&num2)
	fmt.Println("Enter operation('+', '-', '*' or '/'):")
	fmt.Scan(&action)

	if action == "+" {
		fmt.Printf("%v + %v = %v\n", num1, num2, num1+num2)
	}
	if action == "-" {
		fmt.Printf(" %v - %v = %v\n", num1, num2, num1-num2)
	}
	if action == "*" {
		fmt.Printf(" %v * %v = %v\n", num1, num2, num1*num2)
	}
	if action == "/" {
		fmt.Printf(" %v / %v = %v\n", num1, num2, num1/num2)
	}
}
