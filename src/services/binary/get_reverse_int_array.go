package binary

// Reversed the array of int64.
func getReverseIntArray(array []int64) []int64 {
	lastIndex := len(array) - 1
	reversedArray := []int64{}

	for i := lastIndex; i >= 0; i-- {
		reversedArray = append(reversedArray, array[i])
	}

	return reversedArray
}
