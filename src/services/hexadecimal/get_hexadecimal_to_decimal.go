package hexadecimal

import (
	"math"
	"strconv"
	"strings"
)

func getHexadecimalToDecimal(hexadecimal string) string {
	decimal := 0

	// Split the hexadecimal string.
	hexadecimalArray := strings.SplitAfter(hexadecimal, "")

	// Get the exponent value to use in 16 multiplier.
	exponent := len(hexadecimalArray) - 1

	for i := 0; i < len(hexadecimalArray); i++ {
		hexadecimal := hexadecimalArray[i]
		switch hexadecimal {
		case "A":
			decimal = decimal + int(10*math.Pow(16, float64(exponent)))
			exponent = exponent - 1
			break
		case "B":
			decimal = decimal + int(11*math.Pow(16, float64(exponent)))
			exponent = exponent - 1
			break
		case "C":
			decimal = decimal + int(12*math.Pow(16, float64(exponent)))
			exponent = exponent - 1
			break
		case "D":
			decimal = decimal + int(13*math.Pow(16, float64(exponent)))
			exponent = exponent - 1
			break
		case "E":
			decimal = decimal + int(14*math.Pow(16, float64(exponent)))
			exponent = exponent - 1
			break
		case "F":
			decimal = decimal + int(15*math.Pow(16, float64(exponent)))
			exponent = exponent - 1
			break
		default:
			numHexadecimal, _ := strconv.Atoi(hexadecimal)
			decimal = decimal + int(float64(numHexadecimal)*math.Pow(16, float64(exponent)))
			exponent = exponent - 1
			break
		}
	}

	return strconv.Itoa(decimal)
}
