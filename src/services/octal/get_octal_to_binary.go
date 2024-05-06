package octal

func getOctalToBinary(octal int64) string {
	octalArray := getNumberArray(octal)
	binary := ""

	for i := 0; i < len(octalArray); i++ {
		binary = binary + octalSystemMap[int(octalArray[i])]
	}

	return binary
}
