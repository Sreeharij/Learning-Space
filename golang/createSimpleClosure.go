package main
import( 
	"fmt"
)

func main(){
	updateCounter := func() func() int {
		count := 100

		return func() int{
			count++
			return count
		}
	}

	updateWithInitialValue := func(initial int) func() int{
		count := initial

		return func() int {
			count++
			return count
		}
	}

	increment := updateCounter()
	
	fmt.Println(increment())
	fmt.Println(increment())

	inc_x := updateWithInitialValue(200)
	fmt.Println(inc_x())
	fmt.Println(inc_x())
}