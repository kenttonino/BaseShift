package displays

import (
	"fmt"

	"github.com/kentlouisetonino/baseshift/src/helpers"
)

func AppDescription() {
	fmt.Println(helpers.OneSpace, helpers.ColorBlue, "--------------------------------------  ", helpers.ColorReset)
	helpers.AddNewLine()
	fmt.Println(helpers.OneSpace, helpers.ColorGreen, "             BaseShift                 ", helpers.ColorReset)
	fmt.Println(helpers.OneSpace, helpers.ColorWhite, "                                       ", helpers.ColorReset)
	fmt.Println(helpers.OneSpace, helpers.ColorWhite, "    A CLI tool that allows you to    ", helpers.ColorReset)
	fmt.Println(helpers.OneSpace, helpers.ColorWhite, "  convert a number system to another.  ", helpers.ColorReset)
	helpers.AddNewLine()
	fmt.Println(helpers.OneSpace, helpers.ColorBlue, "--------------------------------------  ", helpers.ColorReset)
}
