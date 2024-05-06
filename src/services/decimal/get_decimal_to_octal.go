package decimal

import (
	"strconv"
	"strings"
)

func getDecimalToOctal(decimal int64) int64 {
	octalStringArray := []string{}

	// Divide the dividend with 8 until it reaches zero.
	for i := decimal; i != 0; i = i / 8 {
		// Append the reminder.
		octalStringArray = append([]string{strconv.Itoa(int(i - 8*(i/8)))}, octalStringArray...)
	}

	// Combine all the array of string of number.
	joinedOctalStringArray := strings.Join(octalStringArray, "")

	// Convert the combines string of number into a number.
	parsedOctal, err := strconv.ParseInt(joinedOctalStringArray, 10, 64)

	// If invalid numbers.
	if err != nil {
		return -1
	}

	return parsedOctal
}
