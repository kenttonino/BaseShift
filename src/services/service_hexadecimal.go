package services

import (
	"fmt"

	"github.com/kentlouisetonino/baseshift/src/displays"
	"github.com/kentlouisetonino/baseshift/src/errors"
	"github.com/kentlouisetonino/baseshift/src/helpers"
)

func HexadecimalToBinary() string {
	hexadecimalToBinaryMap := map[string]string{
		"0": "0000",
		"1": "0001",
		"2": "0010",
		"3": "0011",
		"4": "0100",
		"5": "0101",
		"6": "0110",
		"7": "0111",
		"8": "1000",
		"9": "1001",
		"A": "1010",
		"B": "1011",
		"C": "1100",
		"D": "1101",
		"E": "1110",
		"F": "1111",
	}

	fmt.Println(hexadecimalToBinaryMap)

	optionMenu := "0"
	optionInput := ""
	optionHasError := false
	backToMainMenu := false

	for backToMainMenu == false {
		helpers.Clear()
		displays.Option10Description()
		helpers.AddNewLine()

		// Display error message.
		if optionHasError {
			errors.InvalidOption()
			helpers.AddNewLine()
		}

		// Ask binary input.
		optionInput = getHexadecimalInput()

		if optionInput == "-2" {
			// Signal the app that there is an error.
			optionHasError = true

			continue
		} else {
			fmt.Println(helpers.TwoSpace, "Binary", ":", optionInput)
			helpers.AddNewLine()

			// Ask user if want to try again, go back, or quit.
			// Any other key except 1 and 2 will be treated as quit.
			fmt.Print(helpers.TwoSpace, helpers.ColorGreen, " [1-Retry, 2-Back] : ", helpers.ColorReset)
			fmt.Scan(&optionMenu)

			if optionMenu == "1" {
				optionHasError = false
				continue
			} else if optionMenu == "2" {
				backToMainMenu = true
			} else {
				helpers.Clear()
				helpers.Exit()
			}
		}
	}

	return "001000000110"
}
