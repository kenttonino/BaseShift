package services

import (
	"fmt"

	"github.com/kentlouisetonino/baseshift/src/displays"
	"github.com/kentlouisetonino/baseshift/src/errors"
	"github.com/kentlouisetonino/baseshift/src/helpers"
)

func OctalToBinary() {
	optionMenu := "0"
	optionInput := int64(0)
	optionHasError := false
	backToMainMenu := false

	for backToMainMenu == false {
		helpers.Clear()
		displays.Option7Description()
		helpers.AddNewLine()

		// Display error message.
		if optionHasError {
			errors.InvalidOption()
			helpers.AddNewLine()
		}

		// Ask binary input.
		optionInput = getOctalInput()

		if optionInput == -1 {
			// Signal the app that there is an error.
			optionHasError = true

			continue
		} else {
			fmt.Println(helpers.TwoSpace, "Binary", helpers.FourSpace, ":", getOctalToBinary(optionInput))
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

func OctalToDecimal() {
	optionMenu := "0"
	optionInput := int64(0)
	optionHasError := false
	backToMainMenu := false

	for backToMainMenu == false {
		helpers.Clear()
		displays.Option8Description()
		helpers.AddNewLine()

		// Display error message.
		if optionHasError {
			errors.InvalidOption()
			helpers.AddNewLine()
		}

		// Ask binary input.
		optionInput = getOctalInput()

		if optionInput == -1 {
			// Signal the app that there is an error.
			optionHasError = true

			continue
		} else {
			fmt.Println(helpers.TwoSpace, "Decimal", helpers.ThreeSpace, ":", getOctalToDecimal(optionInput))
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

func OctalToHexadecimal() {
	optionMenu := "0"
	optionInput := int64(0)
	optionHasError := false
	backToMainMenu := false

	for backToMainMenu == false {
		helpers.Clear()
		displays.Option9Description()
		helpers.AddNewLine()

		// Display error message.
		if optionHasError {
			errors.InvalidOption()
			helpers.AddNewLine()
		}

		// Ask binary input.
		optionInput = getOctalInput()

		if optionInput == -1 {
			// Signal the app that there is an error.
			optionHasError = true

			continue
		} else {
			fmt.Println(helpers.TwoSpace, "Hexadecimal", ":", getOctalToHexadecimal(optionInput))
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
