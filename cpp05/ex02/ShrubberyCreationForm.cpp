#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Execute the form - create file with ASCII trees
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    
    std::string filename = this->target + "_shrubbery";
    

    std::ofstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: Could not create file " << filename << std::endl;
        return;
    }

    file << "                 ,@@@@@@@,\n";
    file << "         ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    file << "      ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    file << "     ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    file << "     %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    file << "     %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    file << "     `&%\\ ` /%&'    |.|        \\ '|8'\n";
    file << "         |o|        | |         | |\n";
    file << "         |.|        | |         | |\n";
    file << "      \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
    
    file.close();
    std::cout << "Shrubbery has been planted at " << this->target << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->target;
}