package user

import (
	"context"
	"errors"
	"strings"

	"github.com/golang-jwt/jwt/v5"
	"google.golang.org/grpc"
	"google.golang.org/grpc/metadata"
)

func AuthInterceptor() grpc.UnaryServerInterceptor {
	return func(
		ctx context.Context,
		req interface{},
		info *grpc.UnaryServerInfo,
		handler grpc.UnaryHandler,
	) (interface{}, error) {
		// Skip auth for Register and Login
		if info.FullMethod == "/user.UserService/Register" || info.FullMethod == "/user.UserService/Login" {
			return handler(ctx, req)
		}

		// Get token from metadata
		md, ok := metadata.FromIncomingContext(ctx)
		if !ok {
			return nil, errors.New("missing metadata")
		}

		authHeader := md["authorization"]
		if len(authHeader) == 0 {
			return nil, errors.New("authorization token not provided")
		}

		tokenStr := strings.TrimPrefix(authHeader[0], "Bearer ")

		claims := &Claims{}
		token, err := jwt.ParseWithClaims(tokenStr, claims, func(token *jwt.Token) (interface{}, error) {
			return jwtKey, nil
		})

		if err != nil || !token.Valid {
			return nil, errors.New("invalid token")
		}

		// Add user ID to context (optional)
		ctx = context.WithValue(ctx, "userID", claims.UserID)

		return handler(ctx, req)
	}
}
