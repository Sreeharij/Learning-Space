package main

import (
	"fmt"
	"os"
	"os/exec"
)

func main() {
	switch os.Args[1] {
	case "run":
		run()

	case "child":
		child()
	default:
		fmt.Println("Invalid")
	}
}

func run() {
	fmt.Println("Parent running")

	// cmd := exec.Command("/proc/self/exe", "hola") //Run same process with invalid command line argument
	cmd := exec.Command("/proc/self/exe", "child")
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	cmd.Run()
}

func child() {
	fmt.Println("Inside Child proces")

	cmd := exec.Command("/bin/bash")
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	cmd.Run()
}
