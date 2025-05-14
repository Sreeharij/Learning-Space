package main

import "fmt"

func calculation(x int,y int, op func(int, int) int) int {
	return op(x,y)
}

func multiply(x, y int) int {
	return x*y
}

func main(){
	result := calculation(2,5,multiply)
	fmt.Println("Result: ",result)
}