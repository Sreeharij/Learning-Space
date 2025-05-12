package main 

import "fmt"

func checkType(i interface{}){
	switch v := i.(type) {
    case int:
        fmt.Println("It's an int:", v)
    case string:
        fmt.Println("It's a string:", v)
    default:
        fmt.Printf("Unknown type %T\n", v)
    }
}

func main(){
	fmt.Println("Hello World")
	// fmt.Println("Statement 2")
	num := 100

	checkType(num);
	
	
}