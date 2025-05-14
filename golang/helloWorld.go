package main

import (
	"fmt"
	"time"
)

func checkType(i interface{}) {
	switch v := i.(type) {
	case int:
		fmt.Println("It's an int:", v)
	case string:
		fmt.Println("It's a string:", v)
	default:
		fmt.Printf("Unknown type %T\n", v)
	}
}

func main() {

	messages := make(chan string)
	defer checkType(messages)

	go func() {
		time.Sleep(2 * time.Second)
		messages <- "Hello From first goroutine!"
	}()
	fmt.Println("Main here")
	for i := 1; i <= 10; i++ {
		fmt.Printf("%d\n", i)
	}
	msg := <-messages
	fmt.Println(msg)

	if 5 == 45 {
		fmt.Println("5 == 5")
	} else {
		fmt.Println("Else part")
	}

	var mp = map[int]int{
		1: 10,
		2: 20,
		3: 30,
	}
	fmt.Println(mp)

}
