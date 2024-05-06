package octal

import "math"

func getOctalToDecimal(octal int64) int64 {
	octalArray := getNumberArray(octal)
	multiplier := len(octalArray) - 1
	octalSum := 0

	for i := 0; i < len(octalArray); i++ {
		indexValue := float64(octalArray[i])
		octalSum = octalSum + int((indexValue * math.Pow(8.0, float64(multiplier))))
		multiplier = multiplier - 1
	}

	return int64(octalSum)
}
