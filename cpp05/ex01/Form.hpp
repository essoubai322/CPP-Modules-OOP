#pragma once

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    public :
        Form();
		Form(const std::string& name, int grade_sign, int grade_exec);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);

        void beSigned(Bureaucrat &other);
        std::string getName() const;
        bool get_isSigned() const;
        int get_gradeToSign() const;
        int get_gradeToExecute() const;

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Form Grade too high";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Form Grade too low";
                }
        };
};