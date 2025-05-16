package user

import (
	"time"

	"github.com/golang-jwt/jwt/v5"
)

//TODO

var jwtKey = []byte("MySecretKey") // Replace with a strong secret in production

type Claims struct {
	UserID string `json:"user_id"`
	jwt.RegisteredClaims
}

// GenerateJWT generates a JWT token for a given user ID
func GenerateJWT(userID string) (string, error) {
	expirationTime := time.Now().Add(24 * time.Hour) // token valid for 24 hours

	claims := &Claims{
		UserID: userID,
		RegisteredClaims: jwt.RegisteredClaims{
			ExpiresAt: jwt.NewNumericDate(expirationTime),
			IssuedAt:  jwt.NewNumericDate(time.Now()),
			Issuer:    "ecommerce-app",
		},
	}

	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	return token.SignedString(jwtKey)
}
