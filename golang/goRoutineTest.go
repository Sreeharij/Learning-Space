package main

import (
	"fmt"
	"time"
)

func sayHello() {
	fmt.Println("Hello GoRoutine!")
}

func main() {
	go sayHello()
	time.Sleep(1 * time.Second)
	fmt.Println("Hello main function!")
}
