#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target(other.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Execute the form - robotomize target (50% success rate)
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    
    std::cout << "* DRILLING NOISES *" << std::endl;
    std::cout << "BZZZZZZT! WHIRRRRR! CLANK CLANK!" << std::endl;

    std::srand(std::time(0));
    // 50% chance of success
    if (std::rand() % 2 == 0)
    {   
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy on " << this->target << " failed!" << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->target;
}