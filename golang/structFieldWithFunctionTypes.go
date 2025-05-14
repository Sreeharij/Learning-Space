package main

import (
	"fmt"
	"strings"
)

func main(){
	p := Processor{
		transform: func(s string) string {
			return strings.ToUpper(s)
		},
		validate: func(s string) bool {
			return len(s) > 0
		},
	}

	fmt.Println(p.transform("hello"))
	fmt.Println(p.validate(""))
}

type Processor struct {
	transform func(string) string 
	validate func(string) bool
}