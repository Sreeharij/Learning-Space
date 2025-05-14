package main

import (
	"fmt"
	"strings"
	
)

func main(){
	var greeting = "Hello World!"

	// fmt.Printf("normal String: ")
	// fmt.Printf("%s",greeting)
	// fmt.Printf("\n")
	// fmt.Printf("hex bytes: ")

	// for i := 0; i < len(greeting);i++ {
	// 	fmt.Printf("%x ", greeting[i])
	// }

	// fmt.Printf("\n")

	const sampleText = "\xbd\xb2\x3d\xbc\x20\xe2\x8c\x98" 

	// fmt.Printf("quoted string: ")
	// fmt.Printf("%+q", sampleText)
	// fmt.Printf("\n")  

	fmt.Printf("String length is: ")
	fmt.Println(len(greeting))

	wordsCollection := []string{"Hello","From","The","Other","Side"}
	sentence := strings.Join(wordsCollection," ")
	fmt.Println(sentence)

	for idx, char := range sentence{
		fmt.Printf("Index: %d, Character: %c\n",idx,char)
	}
}
