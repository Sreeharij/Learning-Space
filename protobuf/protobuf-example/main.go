package main 

import (
	"fmt"
	"log"
	"os"

	"google.golang.org/protobuf/proto"

	"protobuf-example/examplepb"
)

func main() {
	p := &examplepb.Person{
		Id: 1,
		Name: "Alice",
		Email: "alice@example.com",
	}
	
	data,err := proto.Marshal(p)
	if err != nil {
		log.Fatalf("Failed to encode: %v",err)
	}

	err = os.WriteFile("person.bin",data,0644)
	if err != nil {
		log.Fatalf("Failed to write: %v",err)
	}
	fmt.Println("Person serialized and written to person.bin")

	readData,err := os.ReadFile("person.bin")
	if err != nil {
		log.Fatalf("Failed to read: %v",err)
	}

	var person2 examplepb.Person
	err = proto.Unmarshal(readData, &person2)
	if err != nil {
		log.Fatalf("Failed to decode: %v",err)
	}

	fmt.Printf("Deserialized Person: ID=%d, Name=%s, Email=%s\n", person2.Id, person2.Name, person2.Email)
}