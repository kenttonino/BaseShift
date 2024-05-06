package hexadecimal

import "strings"

func getHexadecimalToBinary(hexadecimal string) string {
	// Store the equivalent of each hex value.
	binaryArray := []string{}

	// Split the hexadecimal string.
	hexadecimalArray := strings.SplitAfter(hexadecimal, "")

	for i := 0; i < len(hexadecimalArray); i++ {
		binaryArray = append(binaryArray, hexadecimalToBinaryMap[hexadecimalArray[i]])
	}

	return strings.Join(binaryArray, "")
}
