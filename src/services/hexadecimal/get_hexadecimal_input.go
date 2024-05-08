package hexadecimal

import (
	"fmt"
	"slices"
	"strings"

	"github.com/kentlouisetonino/baseshift/src/helpers"
)

func getHexadecimalInput() string {
	var optionChecker string

	// Ask the octal input from the end user.
	fmt.Print(helpers.ThreeSpace, "Hexadecimal", helpers.ThreeSpace, ": ")

	// Handle the input.
	fmt.Scan(&optionChecker)

	// Check if hexadecimal input is valid.
	hexadecimalArray := strings.SplitAfter(optionChecker, "")
	for i := 0; i < len(hexadecimalArray); i++ {
		if slices.Contains(hexValidOptions, hexadecimalArray[i]) == false {
			return "-1"
		}
	}

	return optionChecker
}
