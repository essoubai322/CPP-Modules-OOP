#pragma once

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    public :
        AForm();
		AForm(const std::string& name, int grade_sign, int grade_exec);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);

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
                    return "AForm Grade too high";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "AForm Grade too low";
                }
        };

        class ExecuteException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "AAForm can't be executed : AForm not signed";
				}
		};

        virtual void execute(Bureaucrat const & executor) const = 0;
};