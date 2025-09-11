#include <iostream>

#include "tokenaries/tokenizer.hpp"

int main()
{
	const std::string source = "return 0;";

	schort::tokenizer tokenizer{ source };

	const std::vector<schort::token> tokens{ tokenizer.tokenize() };

	return EXIT_SUCCESS;
}
