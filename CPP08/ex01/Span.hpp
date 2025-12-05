#pragma once

#include <list>
#include <algorithm>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <iostream>

class Span
{
	private :
		unsigned int size;
		std::list<int> numbers;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		
		void addNumber(int value);

		template <typename T>
		void addNumber(T first, T last)
		{
			while (first != last)
			{
				this->addNumber(*first);
				first++;
			}
		}

		int shortestSpan() const;
		int longestSpan() const;
};
