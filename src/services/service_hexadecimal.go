package services

import (
	"fmt"

	"github.com/kentlouisetonino/baseshift/src/displays"
	"github.com/kentlouisetonino/baseshift/src/errors"
	"github.com/kentlouisetonino/baseshift/src/helpers"
)

func HexadecimalToBinary() {
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

		// Ask hexadecmial input.
		optionInput = getHexadecimalInput()

		if optionInput == "-1" {
			// Signal the app that there is an error.
			optionHasError = true
			continue
		} else {
			fmt.Println(helpers.TwoSpace, "Binary", helpers.SixSpace, ":", getHexadecimalToBinary(optionInput))
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
}

func HexadecimalToDecimal() {
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

		// Ask hexadecmial input.
		optionInput = getHexadecimalInput()

		if optionInput == "-1" {
			// Signal the app that there is an error.
			optionHasError = true
			continue
		} else {
			fmt.Println(helpers.TwoSpace, "Binary", helpers.SixSpace, ":", getHexadecimalToBinary(optionInput))
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
}
