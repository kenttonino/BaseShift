package services

var octalSystemMap = map[int]string{
	0: "000",
	1: "001",
	2: "010",
	3: "011",
	4: "100",
	5: "101",
	6: "110",
	7: "111",
}

func getOctalToBinary(octal int64) string {
	octalArray := getNumberArray(octal)
	binary := ""

	for i := 0; i < len(octalArray); i++ {
		binary = binary + octalSystemMap[int(octalArray[i])]
	}

	return binary
}
