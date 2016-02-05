#include "input_handler.h"

#include <iostream>
#include <ctype.h>

std::string InputHandler::defaultQuestion_ = "";
std::string InputHandler::defaultEnding_ = "";

// printQuestion
void InputHandler::printQuestion()
{
	std::cout << defaultQuestion_ << defaultEnding_;
}

void InputHandler::printQuestion(
	const std::string& question,
	bool useDefaultEnding)
{
	std::cout << question;

	if (useDefaultEnding)
		std::cout << defaultEnding_;
}

void InputHandler::printQuestion(
	const std::string& question,
	const std::string& ending,
	bool useDefaultEnding)
{
	std::cout << question;

	if (useDefaultEnding) {
		std::cout << defaultEnding_;
	}
	else {
		std::cout << ending;
	}
}



// ...Raw...
// getRawInput
std::string InputHandler::getRawInput()
{
	// Get the raw input.
	std::string inputString;
	std::getline(std::cin, inputString);

	// Return the unformatted string.
	return inputString;
}

void InputHandler::getRawInput(std::string& inputString)
{
	// Get the raw input.
	std::getline(std::cin, inputString);
}

// askRaw
std::string InputHandler::askRaw()
{
	printQuestion();
	return getRawInput();
}

std::string InputHandler::askRaw(
	const std::string& question,
	bool useDefaultEnding)
{
	printQuestion(question, useDefaultEnding);
	return getRawInput();
}

std::string InputHandler::askRaw(
	const std::string& question,
	const std::string& ending)
{
	printQuestion(question, ending);
	return getRawInput();
}



// askStripped
std::string InputHandler::getStrippedInput()
{
	std::string inputString;
	getRawInput(inputString);

	bool foundBody;

	// Once the body has been found,
	// white space is first added to this string,
	// then added to strippedString once another character is found.
	// This ensures white space at the end of the string will not be added.
	std::string whiteSpace = "";

	// The string to be returned.
	std::string strippedString = "";

	for (auto i = inputString.begin(); i != inputString.end(); ++i) {
		// If it's white space, add to whiteSpace if the body has started.
		if (std::isspace(*i)) {
			if (foundBody) {
				whiteSpace += *i;
			}
		}

		// If it's not white space, mark the body as being found,
		// add any middle white space, and add the character
		else {
			if (!foundBody) {
				foundBody = true;
			}
			if (whiteSpace.size() > 0) {
				strippedString += whiteSpace;
				whiteSpace = "";
			}
			strippedString += *i;
		}
	}

	return strippedString;
}

std::string InputHandler::askStripped()
{
	printQuestion();
	return getStrippedInput();
}

std::string InputHandler::askStripped(
	const std::string& question,
	bool useDefaultEnding)
{
	printQuestion(question, useDefaultEnding);
	return getStrippedInput();
}

std::string InputHandler::askStripped(
	const std::string& question,
	const std::string& ending)
{
	printQuestion(question, ending);
	return getStrippedInput();
}



// set...
// setDefault...
void InputHandler::setDefaultQuestion(const std::string& defaultQuestion)
{
	defaultQuestion_ = defaultQuestion;
}


void InputHandler::setDefaultEnding(const std::string& defaultEnding)
{
	defaultEnding_ = defaultEnding;
}











