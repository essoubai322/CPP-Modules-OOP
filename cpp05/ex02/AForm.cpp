#include "AForm.hpp"

AForm::AForm() : name("walo name") , isSigned(false), gradeToSign(150), gradeToExecute(150) {};

AForm::~AForm(){};

AForm::AForm(const std::string& name, int grade_sign, int grade_exec) : name(name) , gradeToSign(grade_sign), gradeToExecute(grade_exec) 
{
    isSigned=false;
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm &other) : name(other.name) , gradeToSign(other.gradeToSign) , gradeToExecute(other.gradeToExecute)
{
    *this = other;
}

AForm &AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

void AForm::beSigned(Bureaucrat &other)
{
    if (other.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
    std::cout << other.getName() << " signed " << this->name << std::endl;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::get_isSigned() const
{
    return isSigned;
}

int AForm::get_gradeToSign() const
{
    return (gradeToSign);
}

int AForm::get_gradeToExecute() const
{
    return (gradeToExecute);
}