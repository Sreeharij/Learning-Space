package main

import (
	"fmt"
	"os"
	"os/exec"
)

func main() {
	fmt.Println("Running process...")

	cmd := exec.Command("/bin/bash")
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr

	cmd.Run()
}
