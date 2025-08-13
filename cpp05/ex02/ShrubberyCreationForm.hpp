#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
    
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    
    void execute(const Bureaucrat& executor) const;
    

    std::string getTarget() const;
};