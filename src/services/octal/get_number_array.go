package octal

// Split a number into array.
func getNumberArray(num int64) []int64 {
	slc := []int64{}
	for num > 0 {
		slc = append(slc, num%10)
		num /= 10
	}

	result := []int64{}
	for i := range slc {
		result = append(result, slc[len(slc)-1-i])
	}

	return result

}
