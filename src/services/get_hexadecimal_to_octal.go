package services

import (
	"fmt"
	"strings"
)

var hexToBinaryArrayMap = map[string][]int{
	"0": {0, 0, 0, 0},
	"1": {0, 0, 0, 1},
	"2": {0, 0, 1, 0},
	"3": {0, 0, 1, 1},
	"4": {0, 1, 0, 0},
	"5": {0, 1, 0, 1},
	"6": {0, 1, 1, 0},
	"7": {0, 1, 1, 1},
	"8": {1, 0, 0, 0},
	"9": {1, 0, 0, 1},
	"A": {1, 0, 1, 0},
	"B": {1, 0, 1, 1},
	"C": {1, 1, 0, 0},
	"D": {1, 1, 0, 1},
	"E": {1, 1, 1, 0},
	"F": {1, 1, 1, 1},
}

func getHexadecimalToOctal(hexadecimal string) string {
	// Store the equivalent of each hex value.
	binaryArray := []int{}

	// Split the hexadecimal string.
	hexadecimalArray := strings.SplitAfter(hexadecimal, "")

	for i := 0; i < len(hexadecimalArray); i++ {
		binaryArray = append(binaryArray, hexToBinaryArrayMap[hexadecimalArray[i]]...)
	}

	fmt.Println(binaryArray)

	return "1006"
}
