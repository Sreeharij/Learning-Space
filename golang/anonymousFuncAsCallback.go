package main
import (
	"fmt"
	"io"
	"net/http"
)

func main(){
	fetchData("https://example.com",func(data []byte,err error) {
		if err != nil{
			fmt.Println("Error: ",err)
			return
		}
		fmt.Println("Data length: ",len(data))
	})
	fmt.Scanln()
}

func fetchData(url string, callback func([]byte,error)){
	go func(){
		resp,err := http.Get(url)

		if err != nil{
			callback(nil,err)
			return
		}

		defer resp.Body.Close()
		data,err := io.ReadAll(resp.Body)
		callback(data,err)
	}()
}