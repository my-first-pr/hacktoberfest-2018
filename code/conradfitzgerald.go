package main

import (
  "fmt"
  "runtime"
  "time"
  "os"
)

check(err error) {
  if err != nil {
    panic(err)
  }
}

func getTime() string {
  return string(time.Now())
}

func getOSInfo() string string {
  host, err := os.Hostname()
  check(err)
  return runtime.GOOS(), host
}

func main() {
  os, host := getOSInfo()
  fmt.Println("Hello, ", host, "!")
  fmt.Println("You are running ", os)
  fmt.Println("It is currently ", getTime())
}
