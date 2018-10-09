package main

import (
	"fmt"
	"time"
	"encoding/json"
)

type Hacktober struct {
	Message string `json:"msg"`
	Date time.Time `json:"date"`
}

func main () {
	data := Hacktober{
		Message: "Hello Hacktoberfest 2018!",
		Date: time.Now(),
	}

	jsonBytes, _ := json.MarshalIndent(data, "", "  ")
	fmt.Println(string(jsonBytes))
}
