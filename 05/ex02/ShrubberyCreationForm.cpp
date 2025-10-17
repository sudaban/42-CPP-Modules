#include "ShrubberyCreationForm.h"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm(target, 137, 145), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		this->target = other.target;
	return *this;
}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename = this->getName() + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (!ofs)
		return;
	ofs << "       _-_\n";
	ofs << "    /~~   ~~\\\n";
	ofs << " /~~         ~~\\\n";
	ofs << "{               }\n";
	ofs << " \\  _-     -_  /\n";
	ofs << "   ~  \\ //  ~\n";
	ofs << "_- -   | | _- _\n";
	ofs << "  _ -  | |   -_\n";
	ofs << "      // \\";
	ofs.close();
}
