#include "Form.hpp"

Form::Form() : name("walo name") , isSigned(false), gradeToSign(150), gradeToExecute(150) {};

Form::~Form(){};

Form::Form(const std::string& name, int grade_sign, int grade_exec) : name(name) , gradeToSign(grade_sign), gradeToExecute(grade_exec) 
{
    isSigned=false;
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
}

Form::Form(const Form &other) : name(other.name) , gradeToSign(other.gradeToSign) , gradeToExecute(other.gradeToExecute)
{
    *this = other;
}

Form &Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

void Form::beSigned(Bureaucrat &other)
{
    if (other.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
    std::cout << other.getName() << " signed " << this->name << std::endl;
}

std::string Form::getName() const
{
    return name;
}

bool Form::get_isSigned() const
{
    return isSigned;
}

int Form::get_gradeToSign() const
{
    return (gradeToSign);
}

int Form::get_gradeToExecute() const
{
    return (gradeToExecute);
}