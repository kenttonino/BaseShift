package services

import (
	"fmt"
	"slices"
	"strings"

	"github.com/kentlouisetonino/baseshift/src/helpers"
)

func getHexadecimalInput() string {
	var optionChecker string
	validOptions := []string{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"}

	// Ask the octal input from the end user.
	fmt.Print(helpers.ThreeSpace, "Hexadecimal", helpers.ThreeSpace, ": ")

	// Handle the input.
	fmt.Scan(&optionChecker)

	// Check if hexadecimal input is valid.
	hexadecimalArray := strings.SplitAfter(optionChecker, "")
	for i := 0; i < len(hexadecimalArray); i++ {
		if slices.Contains(validOptions, hexadecimalArray[i]) == false {
			return "-1"
		}
	}

	return optionChecker
}
