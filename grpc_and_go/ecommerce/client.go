package main

import (
	"bufio"
	"context"
	"fmt"
	"log"
	"os"
	"strings"
	"time"

	"ecommerce/user/pb"

	"google.golang.org/grpc"
)

func main() {
	conn, err := grpc.Dial("localhost:50051", grpc.WithInsecure())
	if err != nil {
		log.Fatalf("failed to connect: %v", err)
	}
	defer conn.Close()

	client := pb.NewUserServiceClient(conn)
	reader := bufio.NewReader(os.Stdin)

	fmt.Println("UserService Client")
	fmt.Println("------------------")

	for {
		fmt.Println("\nChoose an option:")
		fmt.Println("1) Register")
		fmt.Println("2) Login")
		fmt.Println("Type 'exit' to quit")

		fmt.Print("> ")
		choiceRaw, _ := reader.ReadString('\n')
		choice := strings.TrimSpace(choiceRaw)

		if strings.ToLower(choice) == "exit" {
			fmt.Println("Exiting client...")
			break
		}

		switch choice {
		case "1":
			name := promptInput(reader, "Enter Name: ")
			email := promptInput(reader, "Enter Email: ")
			password := promptInput(reader, "Enter Password: ")

			ctx, cancel := context.WithTimeout(context.Background(), 5*time.Second)
			defer cancel()

			resp, err := client.Register(ctx, &pb.RegisterRequest{
				Name:     name,
				Email:    email,
				Password: password,
			})
			if err != nil {
				fmt.Printf("Register failed: %v\n", err)
			} else {
				fmt.Printf("Register success! UserID: %s\n", resp.UserId)
			}

		case "2":
			email := promptInput(reader, "Enter Email: ")
			password := promptInput(reader, "Enter Password: ")

			ctx, cancel := context.WithTimeout(context.Background(), 5*time.Second)
			defer cancel()

			resp, err := client.Login(ctx, &pb.LoginRequest{
				Email:    email,
				Password: password,
			})
			if err != nil {
				fmt.Printf("Login failed: %v\n", err)
			} else {
				fmt.Printf("Login success! UserID: %s, Token: %s\n", resp.UserId, resp.Token)
			}

		default:
			fmt.Println("Invalid option, please try again.")
		}
	}
}

func promptInput(reader *bufio.Reader, prompt string) string {
	fmt.Print(prompt)
	text, _ := reader.ReadString('\n')
	return strings.TrimSpace(text)
}
