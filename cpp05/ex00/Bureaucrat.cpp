#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}


Bureaucrat &Bureaucrat::operator++()
{
    *this = Bureaucrat(this->name, this->grade - 1);
    return *this;
}

Bureaucrat &Bureaucrat::operator--()
{
    *this = Bureaucrat(this->name, this->grade + 1);
    return *this;
}


std::string Bureaucrat::getName() const
{
    return name;
}

Bureaucrat::Bureaucrat() : name("walo") , grade(150) {}

Bureaucrat::~Bureaucrat(){};



int Bureaucrat::getGrade() const
{
    return grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}
