#include <iostream>

#include "tokenaries/tokenizer.hpp"

int main()
{
	const std::string source = "return testing 123;";

	schort::tokenizer tokenizer{ source };

	if (tokenizer.has_error())
	{
		for (const std::string &error : tokenizer.error_messages())
		{
			std::cerr << error << '\n';
		}
	}

	const std::vector<schort::token> tokens{ tokenizer.tokenize() };

	for (const schort::token &token : tokens)
	{
		std::cout << static_cast<std::string>(token) << '\n';
	}

	return EXIT_SUCCESS;
}
