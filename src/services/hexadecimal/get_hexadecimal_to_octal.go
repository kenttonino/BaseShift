package hexadecimal

import (
	"strconv"
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
	octalArray := []string{}
	binaryArray := []int{}

	// Split the hexadecimal string.
	hexadecimalArray := strings.SplitAfter(hexadecimal, "")

	for i := 0; i < len(hexadecimalArray); i++ {
		binaryArray = append(binaryArray, hexToBinaryArrayMap[hexadecimalArray[i]]...)
	}

	// Add two zeroes at the beginning.
	if len(binaryArray)%3 == 1 {
		binaryArray = append([]int{0, 0}, binaryArray...)
	}

	// Add 1 zero at the beginning.
	if len(binaryArray)%3 == 2 {
		binaryArray = append([]int{0}, binaryArray...)
	}

	octalSum := 0
	for i := 0; i < len(binaryArray); i++ {
		if i%3 == 0 {
			octalSum += binaryArray[i] * 4
			continue
		}
		if i%3 == 1 {
			octalSum += binaryArray[i] * 2
			continue
		}
		if i%3 == 2 {
			octalArray = append(octalArray, strconv.Itoa(octalSum+binaryArray[i]*1))
			octalSum = 0
		}
	}

	return strings.Join(octalArray, "")
}
