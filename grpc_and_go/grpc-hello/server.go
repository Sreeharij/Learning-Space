package main

import (
	"context"
	"fmt"
	"log"
	"net"

	pb "grpc-hello/proto"

	"google.golang.org/grpc"
)

type server struct {
	pb.UnimplementedGreeterServer
}

func (s *server) SayHello(ctx context.Context, req *pb.HelloRequest) (*pb.HelloReply, error) {
	log.Printf("Received: %s", req.GetName())
	return &pb.HelloReply{Message: fmt.Sprintf("Hello %s", req.GetName())}, nil
}

func main() {
	lis, err := net.Listen("tcp", ":50051")
	if err != nil {
		log.Fatalf("Failed to listen: %v", err)
	}

	grpcServer := grpc.NewServer()
	pb.RegisterGreeterServer(grpcServer, &server{})

	log.Println("Server listening on port 50051...")
	if err := grpcServer.Serve(lis); err != nil {
		log.Fatalf("Failed to serve: %v", err)
	}
}
