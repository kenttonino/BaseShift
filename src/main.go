package main

import (
	"slices"

	"github.com/kentlouisetonino/baseshift/src/displays"
	"github.com/kentlouisetonino/baseshift/src/errors"
	"github.com/kentlouisetonino/baseshift/src/helpers"
	"github.com/kentlouisetonino/baseshift/src/services/binary"
	"github.com/kentlouisetonino/baseshift/src/services/decimal"
	"github.com/kentlouisetonino/baseshift/src/services/hexadecimal"
	"github.com/kentlouisetonino/baseshift/src/services/octal"
)

func main() {
	validOptions := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
	isValidMainOption := false
	hasError := false

	for {
		helpers.Clear()
		helpers.AddNewLine()
		displays.AppDescription()
		helpers.AddNewLine()

		if hasError {
			errors.InvalidOption()
			helpers.AddNewLine()
		}

		displays.AppOptions()
		helpers.AddNewLine()

		userInput := helpers.MainOptionInput()

		if userInput == 13 {
			break
		}

		isValidMainOption = slices.Contains(validOptions, userInput)

		if isValidMainOption {
			hasError = false

			switch userInput {
			case 1:
				binary.ConvertToDecimal()
			case 2:
				binary.ConvertToOctal()
			case 3:
				binary.ConvertToHexadecimal()
			case 4:
				decimal.ConvertToBinary()
			case 5:
				decimal.ConvertToOctal()
			case 6:
				decimal.ConvertToHexadecimal()
			case 7:
				octal.ConvertToBinary()
			case 8:
				octal.ConvertToDecimal()
			case 9:
				octal.ConvertToHexadecimal()
			case 10:
				hexadecimal.ConvertToBinary()
			case 11:
				hexadecimal.ConvertToDecimal()
			case 12:
				hexadecimal.ConvertToOctal()
			default:
				hasError = true
			}
		} else {
			hasError = true
		}
	}

	helpers.Clear()
}
