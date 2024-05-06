package binary

// Reversed the binary and return an array of binary.
func getReversedBinaryArray(binary int64) []int64 {
	var arrayOfBinary []int64

	for binary != 0 {
		arrayOfBinary = append(arrayOfBinary, binary%10)
		binary /= 10
	}

	return arrayOfBinary
}
