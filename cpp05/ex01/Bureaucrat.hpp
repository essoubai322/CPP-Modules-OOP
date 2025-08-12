#pragma once

#include <iostream>
#include <exception> 

#include "Form.hpp"

class Form;
class Bureaucrat
{
    private : 
        const std::string name;
        int grade;
    public : 
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        Bureaucrat &operator++();
        Bureaucrat &operator--();
        std::string getName() const;
        int getGrade() const;
        void signForm(Form &form);

        class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw() {
                return "Grade is too high!";
            }
        };

        class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw() {
                return "Grade is too low!";
            }
        };
};