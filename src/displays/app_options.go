package displays

import (
	"fmt"
	"strconv"

	"github.com/kentlouisetonino/baseshift/src/helpers"
)

var openBracket = helpers.ColorBlue + "[" + helpers.ColorReset
var closeBracket = helpers.ColorBlue + "]" + helpers.ColorReset

func optionNumber(number int) string {
	return helpers.ColorGreen + strconv.Itoa(number) + helpers.ColorReset
}

func AppOptions() {
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(1), closeBracket, "Binary to Decimal")
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(2), closeBracket, "Binary to Octal")
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(3), closeBracket, "Binary to Hexadecimal")
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(4), closeBracket, "Decimal to Binary")
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(5), closeBracket, "Decimal to Octal")
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(6), closeBracket, "Decimal to Hexadecimal")
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(7), closeBracket, "Octal to Binary")
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(8), closeBracket, "Octal to Decimal")
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(9), closeBracket, "Octal to Hexadecimal")
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(10), closeBracket, "Hexadecimal to Binary")
	// fmt.Println(helpers.TwoSpace, openBracket, optionNumber(11), closeBracket, "Hexadecimal to Decimal")
	// fmt.Println(helpers.TwoSpace, openBracket, optionNumber(12), closeBracket, "Hexadecimal to Octal")
	// fmt.Println(helpers.TwoSpace, openBracket, optionNumber(13), closeBracket, "Exit Application")
	fmt.Println(helpers.TwoSpace, openBracket, optionNumber(11), closeBracket, "Exit Application")
}
