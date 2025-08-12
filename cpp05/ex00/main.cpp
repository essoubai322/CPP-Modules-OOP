#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}


int main()
{
    try
    {
        Bureaucrat dave("Dave", 2);
        ++dave;
        std::cout << "after first increment: " << dave << std::endl;
        --dave;
        std::cout << "after second decrement: " << dave << std::endl;
    }
    catch (GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "caught exception : " << e.what() << std::endl;
    }
    return 0;
}