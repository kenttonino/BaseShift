package decimal

import (
	"strconv"
)

func getDecimalToHexadecimal(decimal int64) string {
	hexStringArray := []string{}

	// Divide the dividend with 16 until it reaches zero.
	for i := decimal; i != 0; i = i / 16 {
		// Append the reminder.
		hexStringArray = append([]string{strconv.Itoa(int(i - 16*(i/16)))}, hexStringArray...)
	}

	// Value to return.
	hex := ""

	// Append the necessary equivalent hex value.
	for i := 0; i < len(hexStringArray); i++ {
		currentHex := hexStringArray[i]

		switch currentHex {
		case "10":
			hex += "A"
			break
		case "11":
			hex += "B"
			break
		case "12":
			hex += "C"
			break
		case "13":
			hex += "D"
			break
		case "14":
			hex += "E"
			break
		case "15":
			hex += "F"
			break
		default:
			hex += currentHex
		}
	}

	return hex
}
