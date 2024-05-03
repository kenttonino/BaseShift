package services

import (
	"fmt"
	"strings"
)

func getHexadecimalToOctal(hexadecimal string) string {
	// Store the equivalent of each hex value.
	binaryArray := []string{}

	// Split the hexadecimal string.
	hexadecimalArray := strings.SplitAfter(hexadecimal, "")

	for i := 0; i < len(hexadecimalArray); i++ {
		binaryArray = append(binaryArray, hexadecimalToBinaryMap[hexadecimalArray[i]])
	}

	fmt.Println(binaryArray)

	return "1006"
}
