package decimal

import (
	"strconv"
	"strings"
)

func getDecimalToBinary(decimal int64) int64 {
	binaryStringArray := []string{}

	// Divide the dividend until it reaches zero.
	for i := decimal; i != 0; i = i / 2 {
		// Append the reminder.
		// If no reminder add 0 in the beginning of array.
		// If contains a reminder add 1 in the beginning of array.
		binaryStringArray = append([]string{strconv.Itoa(int(i % 2))}, binaryStringArray...)
	}

	// Combine all the array of string of number.
	joinedBinaryStringArray := strings.Join(binaryStringArray, "")

	// Convert the combines string of number into a number.
	parsedBinary, err := strconv.ParseInt(joinedBinaryStringArray, 10, 64)

	// If invalid numbers.
	if err != nil {
		return -1
	}

	return parsedBinary
}
