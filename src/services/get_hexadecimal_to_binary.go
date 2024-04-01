package services

import "strings"

func getHexadecimalToBinary(hexadecimal string) string {
	hexadecimalToBinaryMap := map[string]string{
		"0": "0000",
		"1": "0001",
		"2": "0010",
		"3": "0011",
		"4": "0100",
		"5": "0101",
		"6": "0110",
		"7": "0111",
		"8": "1000",
		"9": "1001",
		"A": "1010",
		"B": "1011",
		"C": "1100",
		"D": "1101",
		"E": "1110",
		"F": "1111",
	}

	// Store the equivalent of each hex value.
	binaryArray := []string{}

	// Split the hexadecimal string.
	hexadecimalArray := strings.SplitAfter(hexadecimal, "")

	for i := 0; i < len(hexadecimalArray); i++ {
		binaryArray = append(binaryArray, hexadecimalToBinaryMap[hexadecimalArray[i]])
	}

	return strings.Join(binaryArray, "")
}
