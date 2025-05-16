package user

import (
	"context"
	"errors"
)

type User struct {
	ID       string
	Name     string
	Email    string
	Password string
}

func SaveUser(ctx context.Context, user *User) error {
	_, err := db.Exec(ctx, "INSERT INTO users (id, name, email, password) VALUES ($1, $2, $3, $4)",
		user.ID, user.Name, user.Email, user.Password)
	return err
}

func GetUserByEmail(ctx context.Context, email string) (*User, error) {
	u := &User{}
	err := db.QueryRow(ctx, "SELECT id, name, email, password FROM users WHERE email=$1", email).
		Scan(&u.ID, &u.Name, &u.Email, &u.Password)

	if err != nil {
		return nil, errors.New("user not found")
	}
	return u, nil
}
