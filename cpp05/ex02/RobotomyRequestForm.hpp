#pragma once

#include "AForm.hpp"
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

class RobotomyRequestForm : public AForm
{
private:
    std::string target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);    
    void execute(const Bureaucrat& executor) const;
    std::string getTarget() const;
};