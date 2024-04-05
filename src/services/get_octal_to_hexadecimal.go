package services

import (
	"strconv"
)

var octalToHexadecimalMap = map[string]string{
	"0000": "0",
	"0001": "1",
	"0010": "2",
	"0011": "3",
	"0100": "4",
	"0101": "5",
	"0110": "6",
	"0111": "7",
	"1000": "8",
	"1001": "9",
	"1010": "A",
	"1011": "B",
	"1100": "C",
	"1101": "D",
	"1110": "E",
	"1111": "F",
}

func getOctalToHexadecimal(octal int64) string {
	// Get the equivalent of octal in binary.
	binaryStringValue := getOctalToBinary(octal)

	// Convert the string binary value to int64.
	parsedBinary, err := strconv.ParseInt(binaryStringValue, 10, 64)

	if err != nil {
		return ""
	}

	// Convert the int64 value to int64 array and then reverse.
	binaryArray := getNumberArray(parsedBinary)

	// Get the length of the array.
	arrayLength := len(binaryArray)

	// Create a new binary array.
	newBinaryArray := []int64{}

	// If array lacks 3 digits to become divisible by 4.
	if (arrayLength % 4) == 1 {
		newBinaryArray = append([]int64{0, 0, 0}, binaryArray...)
	}

	// If array lacks 2 digits to become divisible by 4.
	if (arrayLength % 4) == 2 {
		newBinaryArray = append([]int64{0, 0}, binaryArray...)
	}

	// If array lacks 1 digit to become divisible by 4.
	if (arrayLength % 4) == 3 {
		newBinaryArray = append([]int64{0}, binaryArray...)
	}

	// If array is divisible by 4.
	if (arrayLength % 4) == 0 {
		newBinaryArray = binaryArray
	}

	// Group the array to 4 elements.
	groupBinaryArray := []string{}

	// Value to push inside the groups array.
	group := ""

	for i := 0; i < len(newBinaryArray); i++ {
		if len(group) == 3 {
			groupBinaryArray = append(groupBinaryArray, group+strconv.FormatInt(newBinaryArray[i], 10))
			group = ""
		} else {
			group = group + strconv.FormatInt(newBinaryArray[i], 10)
		}
	}

	// Final value to return.
	hexadecimal := ""

	// Handle the equivalent of the group in the octalToHexadecimal map.
	for i := 0; i < len(groupBinaryArray); i++ {
		hexadecimal = hexadecimal + octalToHexadecimalMap[groupBinaryArray[i]]
	}

	return hexadecimal
}
