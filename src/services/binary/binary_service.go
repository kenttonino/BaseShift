package binary

import (
	"fmt"

	"github.com/kentlouisetonino/baseshift/src/displays"
	"github.com/kentlouisetonino/baseshift/src/errors"
	"github.com/kentlouisetonino/baseshift/src/helpers"
)

func BinaryToDecimal() {
	optionMenu := "0"
	optionInput := int64(0)
	optionHasError := false
	backToMainMenu := false

	for backToMainMenu == false {
		helpers.Clear()
		displays.Option1Description()
		helpers.AddNewLine()

		// Display error message.
		if optionHasError {
			errors.InvalidOption()
			helpers.AddNewLine()
		}

		// Ask binary input.
		optionInput = getBinaryInput()

		if optionInput == -1 {
			// Signal the app that there is an error.
			optionHasError = true

			continue
		} else {
			// Display the output of computation for option 1.
			fmt.Println(helpers.TwoSpace, "Decimal", helpers.ThreeSpace, ":", getBinaryToDecimal(optionInput))
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

func BinaryToOctal() {
	optionMenu := "0"
	optionInput := int64(0)
	optionHasError := false
	backToMainMenu := false

	for backToMainMenu == false {
		helpers.Clear()
		displays.Option2Description()
		helpers.AddNewLine()

		// Display error message.
		if optionHasError {
			errors.InvalidOption()
			helpers.AddNewLine()
		}

		// Ask binary input.
		optionInput = getBinaryInput()

		if optionInput == -1 {
			fmt.Println(optionInput)
			// Signal the app that there is an error.
			optionHasError = true

			continue
		} else {
			// Display the output of computation for option 2.
			fmt.Println(helpers.TwoSpace, "Octal", helpers.ThreeSpace, helpers.OneSpace, ":", getBinaryToOctal(optionInput))
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

func BinaryToHexadecimal() {
	optionMenu := "0"
	optionInput := int64(0)
	optionHasError := false
	backToMainMenu := false

	for backToMainMenu == false {
		helpers.Clear()
		displays.Option3Description()
		helpers.AddNewLine()

		// Display error message.
		if optionHasError {
			errors.InvalidOption()
			helpers.AddNewLine()
		}

		// Ask binary input.
		optionInput = getBinaryInput()

		if optionInput == -1 {
			fmt.Println(optionInput)
			// Signal the app that there is an error.
			optionHasError = true

			continue
		} else {
			// Display the output of computation for option 2.
			fmt.Println(helpers.TwoSpace, "Hexadecimal :", getBinaryToHexadecimal(optionInput))
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
