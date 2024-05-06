package octal

import (
	"fmt"
	"strconv"
	"strings"

	"github.com/kentlouisetonino/baseshift/src/helpers"
)

func getOctalInput() int64 {
	var optionChecker string

	// Ask the octal input from the end user.
	fmt.Print(helpers.ThreeSpace, "Octal", helpers.ThreeSpace, helpers.FourSpace, ": ")

	// Handle the input.
	fmt.Scan(&optionChecker)

	// Check if octal input is valid.
	// Allowed numbers are 0 to 7.
	if strings.Contains(optionChecker, "8") || strings.Contains(optionChecker, "9") {
		return -1
	}

	// Convert string number to int64 compatible.
	parseOption, err := strconv.ParseInt(optionChecker, 10, 64)

	// If invalid numbers.
	if err != nil {
		return -1
	}

	return parseOption
}
