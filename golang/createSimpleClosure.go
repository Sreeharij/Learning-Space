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

	increment := updateCounter()
	
	fmt.Println(increment())
	fmt.Println(increment())
}