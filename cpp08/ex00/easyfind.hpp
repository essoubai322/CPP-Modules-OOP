#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::value_type easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("exception : cant find the value!");
	return (*it);	
}
