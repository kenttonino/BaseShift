package decimal

import (
	"fmt"
	"strconv"

	"github.com/kentlouisetonino/baseshift/src/helpers"
)

func getDecimalInput() int64 {

	// Declare the variables.
	var optionChecker string

	// Ask the option.
	fmt.Print(helpers.ThreeSpace, "Decimal", helpers.ThreeSpace, helpers.ThreeSpace, ": ")

	// Check if the string is a valid number.
	fmt.Scan(&optionChecker)
	parseOption, err := strconv.ParseInt(optionChecker, 10, 64)

	// If invalid numbers.
	if err != nil {
		return -1
	}

	return parseOption
}
