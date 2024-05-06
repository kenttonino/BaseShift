package binary

import "strconv"

// Converts binary number to octal.
func getBinaryToOctal(binary int64) string {
	reversedBinaryArray := getReversedBinaryArray(binary)
	octal := ""
	arrayOfOctal := []int64{}
	groupSum := int64(0)

	for i := 0; i < len(reversedBinaryArray); i++ {
		numWeight := i % 3
		isLastIndex := i == (len(reversedBinaryArray) - 1)

		// If remainder is 0, weight is 1.
		if numWeight == 0 {
			groupSum += reversedBinaryArray[i] * 1

			// Push the value right away, if it is the last index.
			if isLastIndex {
				arrayOfOctal = append(arrayOfOctal, groupSum)
			}
		}

		// If remainder is 1, weight is 2.
		if numWeight == 1 {
			groupSum += reversedBinaryArray[i] * 2

			// Push the value right away, if it is the last index.
			if isLastIndex {
				arrayOfOctal = append(arrayOfOctal, groupSum)
			}
		}

		// If remainder is 2, weight is 4.
		if numWeight == 2 {
			arrayOfOctal = append(arrayOfOctal, groupSum+(reversedBinaryArray[i]*4))
			groupSum = 0
		}
	}

	// Reversed the octal array.
	reversedArrayOfOctal := getReverseIntArray(arrayOfOctal)

	// Loop through the array, and concatenate it to the string.
	for i := 0; i < len(reversedArrayOfOctal); i++ {
		octal += strconv.Itoa(int(reversedArrayOfOctal[i]))
	}

	return octal
}
