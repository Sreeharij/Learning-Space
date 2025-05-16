package user

import (
	"log"
	"net"

	"ecommerce/user/pb"

	"google.golang.org/grpc"
)

func StartGRPCServer() {
	ConnectDB()
	defer CloseDB()

	lis, err := net.Listen("tcp", ":50051")
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	s := grpc.NewServer(grpc.UnaryInterceptor(user.AuthInterceptor()))

	pb.RegisterUserServiceServer(s, &UserService{})

	log.Println("UserService gRPC server listening on :50051")
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}
