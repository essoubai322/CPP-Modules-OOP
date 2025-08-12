#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}

std::ostream& operator<<(std::ostream& stream, const Form& other)
{
	stream << "Form name : " << other.getName() << std::endl;
	stream << "required to sign : " << other.get_gradeToSign() << std::endl;
	stream << "required to execute : " << other.get_gradeToExecute() << std::endl;
	stream << "signed : " << other.get_isSigned();
	return (stream);
}


int main()
{
	Bureaucrat apa("Chef", 1);
	Form opo("tajnid", 50, 25);

	try
	{
		apa.signForm(opo);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << apa << std::endl << opo << std::endl;
	return (0);
}
