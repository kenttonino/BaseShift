package binary

import "strconv"

func getBinaryToHexadecimal(binary int64) string {
	hexadecimal := ""
	reversedBinaryArray := getReversedBinaryArray(binary)
	arrayOfHexadecimal := []int64{}
	groupSum := int64(0)

	for i := 0; i < len(reversedBinaryArray); i++ {
		numWeight := i % 4
		isLastIndex := i == (len(reversedBinaryArray) - 1)

		// If remainder is 0, weight is 1.
		if numWeight == 0 {
			groupSum += reversedBinaryArray[i] * 1

			// Push the value right away, if it is the last index.
			if isLastIndex {
				arrayOfHexadecimal = append(arrayOfHexadecimal, groupSum)
			}
		}

		// If remainder is 1, weight is 2.
		if numWeight == 1 {
			groupSum += reversedBinaryArray[i] * 2

			// Push the value right away, if it is the last index.
			if isLastIndex {
				arrayOfHexadecimal = append(arrayOfHexadecimal, groupSum)
			}
		}

		// If remainder is 2, weight is 4.
		if numWeight == 2 {
			groupSum += reversedBinaryArray[i] * 4

			// Push the value right away, if it is the last index.
			if isLastIndex {
				arrayOfHexadecimal = append(arrayOfHexadecimal, groupSum)
			}
		}

		if numWeight == 3 {
			arrayOfHexadecimal = append(arrayOfHexadecimal, groupSum+(reversedBinaryArray[i]*8))
			groupSum = 0
		}
	}

	// Reversed the hexadecimal array first before processing it.
	reversedArrayOfHexadecimal := getReverseIntArray(arrayOfHexadecimal)

	// Loop the array of hexadecimal.
	for i := 0; i < len(reversedArrayOfHexadecimal); i++ {
		hex := strconv.FormatInt(int64(reversedArrayOfHexadecimal[i]), 10)

		switch hex {
		case "10":
			hexadecimal += "A"
			break
		case "11":
			hexadecimal += "B"
			break
		case "12":
			hexadecimal += "C"
			break
		case "13":
			hexadecimal += "D"
			break
		case "14":
			hexadecimal += "E"
			break
		case "15":
			hexadecimal += "F"
			break
		default:
			hexadecimal += hex
		}
	}

	return hexadecimal
}
