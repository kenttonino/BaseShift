package binary

import (
	"fmt"
	"slices"
	"strconv"

	"github.com/kentlouisetonino/baseshift/src/helpers"
)

// This handles the binary input value and its validation.
func getBinaryInput() int64 {
	var option int64
	var optionChecker string
	invalidNumbers := []int64{2, 3, 4, 5, 6, 7, 8, 9}

	// Ask the option.
	fmt.Print(helpers.ThreeSpace, "Binary", helpers.ThreeSpace, helpers.ThreeSpace, ": ")

	// Check if the string is a valid number.
	fmt.Scan(&optionChecker)
	parseOption, err := strconv.ParseInt(optionChecker, 10, 64)

	// If invalid numbers.
	if err != nil {
		return -1
	}

	// Assign the input the option variable.
	option = parseOption

	// Check if the input is a valid binary digit.
	isValid := true
	numberArray := getReversedBinaryArray(option)

	for i := 0; i < len(numberArray); i++ {
		isInvalid := slices.Contains(invalidNumbers, numberArray[i])

		if isInvalid {
			isValid = false
			break
		}

		continue
	}

	if isValid == false {
		return -1
	}

	return option
}
