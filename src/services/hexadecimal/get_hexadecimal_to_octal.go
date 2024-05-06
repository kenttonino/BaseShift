package hexadecimal

import (
	"strconv"
	"strings"
)

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
