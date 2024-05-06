package main

import (
	"slices"

	"github.com/kentlouisetonino/baseshift/src/displays"
	"github.com/kentlouisetonino/baseshift/src/errors"
	"github.com/kentlouisetonino/baseshift/src/helpers"
	"github.com/kentlouisetonino/baseshift/src/services"
	"github.com/kentlouisetonino/baseshift/src/services/binary"
	"github.com/kentlouisetonino/baseshift/src/services/decimal"
)

func main() {
	validOptions := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}
	isValidMainOption := false
	hasError := false

	for {
		// Clear up the screen first.
		helpers.Clear()
		helpers.AddNewLine()

		// Display the app description.
		displays.AppDescription()
		helpers.AddNewLine()

		// Display error message.
		if hasError {
			errors.InvalidOption()
			helpers.AddNewLine()
		}

		// Display the options.
		displays.AppOptions()
		helpers.AddNewLine()

		// Ask input.
		userInput := helpers.MainOptionInput()

		// Exit the application.
		if userInput == 13 {
			break
		}

		// Check if the option is valid.
		isValidMainOption = slices.Contains(validOptions, userInput)

		if isValidMainOption {
			// helpers.Clear()
			hasError = false

			if userInput == 1 {
				binary.ConvertToDecimal()
			}

			if userInput == 2 {
				binary.ConvertToOctal()
			}

			if userInput == 3 {
				binary.ConvertToHexadecimal()
			}

			if userInput == 4 {
				decimal.ConvertToBinary()
			}

			if userInput == 5 {
				decimal.ConvertToOctal()
			}

			if userInput == 6 {
				decimal.ConvertToHexadecimal()
			}

			if userInput == 7 {
				services.OctalToBinary()
			}

			if userInput == 8 {
				services.OctalToDecimal()
			}

			if userInput == 9 {
				services.OctalToHexadecimal()
			}

			if userInput == 10 {
				services.HexadecimalToBinary()
			}

			if userInput == 11 {
				services.HexadecimalToDecimal()
			}

			if userInput == 12 {
				services.HexadecimalToOctal()
			}
		} else {
			hasError = true
		}
	}

	// Clear the terminal upon exit.
	helpers.Clear()
}
