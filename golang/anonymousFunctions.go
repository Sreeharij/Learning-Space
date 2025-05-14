package main

import (
	"fmt"
)

func transform(numbers []int, op func(int) int) []int {
	result := make([]int, len(numbers))
	for i,v := range numbers{
		result[i] = op(v)
	}
	return result
}

func main(){
	squares := transform([]int{2,4,6},func(x int) int {
		return x * x
	}) 
	fmt.Println(squares)
}