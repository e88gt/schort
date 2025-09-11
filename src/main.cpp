#include <iostream>
#include <fstream>
#include <sstream>

#include "parser/parser.hpp"
#include "tokenaries/tokenizer.hpp"

bool load_file(const std::string &filepath, std::string &content)
{
	const std::ifstream file{ filepath, std::ios::binary };

	if (!file)
	{
		content.clear();
		return false;
	}

	std::ostringstream string{};
	string << file.rdbuf();
	content = string.str();

	return true;
}

int main(const int argc, const char *const *const argv)
{
	if (argc < 2)
	{
		std::cerr << "Must have at least 1 argument";
		return EXIT_FAILURE;
	}

	std::string source{};

	if (!load_file(argv[1], source))
	{
		std::cerr << "Can't load file from path '" << argv[1] << "'";
		return EXIT_FAILURE;
	}

	schort::tokenizer tokenizer{ source };

	if (tokenizer.has_error())
	{
		for (const std::string &error : tokenizer.error_messages())
		{
			std::cerr << error << '\n';
		}

		std::cerr << '\n';
	}

	const std::vector<schort::token> tokens{ tokenizer.tokenize() };

	for (const schort::token &token : tokens)
	{
		std::cout << static_cast<std::string>(token) << '\n';
	}

	schort::parser parser{ tokens };

	schort::ast ast = parser.parse();

	return EXIT_SUCCESS;
}
