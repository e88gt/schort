#include "tokenizer.hpp"

#include <iostream>

namespace schort
{
	tokenizer::tokenizer(std::string source)
		: m_index{ 0 }, m_errors{}, m_length{ source.length() }, m_source{ std::move(source) }
	{
	}

	tokenizer::~tokenizer() = default;

	std::vector<token> tokenizer::tokenize()
	{
		std::vector<token> tokens{};

		while (!is_eof())
		{
			if (std::isspace(peek().value()))
			{
				next();
				continue;
			}

			if (std::isalpha(peek().value()) || peek().value() == '_')
			{
				std::string buffer{};

				while (std::isalpha(peek().value()) || std::isspace(peek().value()) || peek().value() == '_')
				{
					buffer += peek().value();
					next();
				}

				if (buffer == "return")
				{
					tokens.push_back(token{ token_type::RETURN });
				}
				else
				{
					tokens.push_back(token{ token_type::IDENTIFIER });
				}
			}
			else if (std::isdigit(peek().value()))
			{
				std::string buffer{};

				while (std::isdigit(peek().value()))
				{
					buffer += peek().value();
					next();
				}

				std::cout << buffer << '\n';
			}
			else if (peek().value() == ';')
			{
				std::cout << "Semi\n";
				next();
			}
			else
			{
				std::cout << "Error: unknown character '" << peek().value() << "' at index of " << m_index << "\n";
				next();
			}
		}

		return tokens;
	}

	char tokenizer::next()
	{
		return m_source.at(m_index++);
	}

	std::optional<char> tokenizer::peek() const
	{
		return is_eof() ? -1 : m_source.at(m_index);
	}

	bool tokenizer::is_eof() const
	{
		return (m_index >= m_length);
	}
} // schort
