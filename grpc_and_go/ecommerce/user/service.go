package user

import (
	"context"
	"errors"

	"ecommerce/user/pb"

	"github.com/google/uuid"
)

type UserService struct {
	pb.UnimplementedUserServiceServer
}

func (s *UserService) Register(ctx context.Context, req *pb.RegisterRequest) (*pb.RegisterResponse, error) {
	id := uuid.NewString()
	user := &User{
		ID:       id,
		Name:     req.Name,
		Email:    req.Email,
		Password: req.Password,
	}

	err := SaveUser(ctx, user)
	if err != nil {
		return nil, err
	}

	return &pb.RegisterResponse{UserId: id}, nil
}

func (s *UserService) Login(ctx context.Context, req *pb.LoginRequest) (*pb.LoginResponse, error) {
	user, err := GetUserByEmail(ctx, req.Email)
	if err != nil || user.Password != req.Password {
		return nil, errors.New("invalid credentials")
	}

	token, err := GenerateJWT(user.ID)
	if err != nil {
		return nil, err
	}

	return &pb.LoginResponse{
		UserId: user.ID,
		Token:  token,
	}, nil
}
