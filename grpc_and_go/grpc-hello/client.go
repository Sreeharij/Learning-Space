package main

import (
	"context"
	"log"
	"time"

	pb "grpc-hello/proto"

	"google.golang.org/grpc"
)

func main() {
	// Connect to the server
	conn, err := grpc.Dial("localhost:50051", grpc.WithInsecure(), grpc.WithBlock())
	if err != nil {
		log.Fatalf("Could not connect: %v", err)
	}
	defer conn.Close()

	client := pb.NewGreeterClient(conn)

	// Create context with timeout
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	// Call SayHello
	res, err := client.SayHello(ctx, &pb.HelloRequest{Name: "Go Developer"})
	if err != nil {
		log.Fatalf("Could not greet: %v", err)
	}

	log.Printf("Greeting: %s", res.GetMessage())
}
