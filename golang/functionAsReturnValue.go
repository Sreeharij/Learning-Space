package main

import (
	"fmt"
)

func calculation(factor int) func(int) int {
	return func(value int) int {
		return factor * value
	}
}

func main(){
	multiplyByTwo := calculation(2)
	result := multiplyByTwo(20)
	fmt.Println("Result: ",result)
}