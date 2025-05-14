package main

import(
	"fmt"
)

type student struct{
	grade string
}

func (s *student) updateGrade(newGrade string){
	s.grade = newGrade
}

type Rectangle struct{
	width, height float64
}

func (rec Rectangle) Area() float64 {
	return rec.width * rec.height
}

func main(){
	s := student{grade:"B"}
	fmt.Println("Before: ",s.grade)

	s.updateGrade("A")

	fmt.Println("After: ",s.grade)

	myRectangle := Rectangle{width: 10, height:20}
	fmt.Println("Area: ",myRectangle.Area())
}