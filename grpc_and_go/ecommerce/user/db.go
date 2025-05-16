package user

import (
	"context"
	"fmt"
	"log"

	"github.com/jackc/pgx/v5/pgxpool"
)

var db *pgxpool.Pool

func ConnectDB() {
	// databaseUrl := os.Getenv("DATABASE_URL")
	//TODO
	databaseUrl := "postgres://postgres:123@localhost:5432/ecommerce?sslmode=disable"
	if databaseUrl == "" {
		databaseUrl = "postgres://postgres:password@localhost:5432/ecommerce?sslmode=disable"
	}

	var err error
	db, err = pgxpool.New(context.Background(), databaseUrl)
	if err != nil {
		log.Fatalf("Unable to connect to database: %v", err)
	}

	fmt.Println("Connected to PostgreSQL!")
}

func CloseDB() {
	if db != nil {
		db.Close()
	}
}
