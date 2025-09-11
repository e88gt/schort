#include "tokenizer.hpp"

#include <iostream>

namespace schort
{
	tokenizer::tokenizer(std::string source)
		: m_index{ 0 }, m_errors{ false }, m_length{ source.length() }, m_source{ std::move(source) }
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
				advance();
				continue;
			}

			if (std::isalpha(peek().value()) || peek().value() == '_')
			{
				std::string buffer{};

				while (std::isalpha(peek().value()) || std::isdigit(peek().value()) || peek().value() == '_')
				{
					buffer += peek().value();
					advance();
				}

				// you can't compare strings with switch case in C++
				if (buffer == "const")
				{
					tokens.push_back(token{ token_type::CONST });
				}
				else if (buffer == "mut")
				{
					tokens.push_back(token{ token_type::MUT });
				}
				else if (buffer == "met")
				{
					tokens.push_back(token{ token_type::MET });
				}
				else if (buffer == "void")
				{
					tokens.push_back(token{ token_type::VOID });
				}
				else if (buffer == "bool")
				{
					tokens.push_back(token{ token_type::BOOL });
				}
				else if (buffer == "float")
				{
					tokens.push_back(token{ token_type::FLOAT });
				}
				else if (buffer == "double")
				{
					tokens.push_back(token{ token_type::DOUBLE });
				}
				else if (buffer == "unsigned")
				{
					tokens.push_back(token{ token_type::UNSIGNED });
				}
				else if (buffer == "signed")
				{
					tokens.push_back(token{ token_type::SIGNED });
				}
				else if (buffer == "byte")
				{
					tokens.push_back(token{ token_type::BYTE });
				}
				else if (buffer == "short")
				{
					tokens.push_back(token{ token_type::SHORT });
				}
				else if (buffer == "int")
				{
					tokens.push_back(token{ token_type::INT });
				}
				else if (buffer == "long")
				{
					tokens.push_back(token{ token_type::LONG });
				}
				else if (buffer == "struct")
				{
					tokens.push_back(token{ token_type::STRUCT });
				}
				else if (buffer == "impl")
				{
					tokens.push_back(token{ token_type::IMPL });
				}
				else if (buffer == "trait")
				{
					tokens.push_back(token{ token_type::TRAIT });
				}
				else if (buffer == "enum")
				{
					tokens.push_back(token{ token_type::ENUM });
				}
				else if (buffer == "self")
				{
					tokens.push_back(token{ token_type::SELF });
				}
				else if (buffer == "super")
				{
					tokens.push_back(token{ token_type::SUPER });
				}
				else if (buffer == "is")
				{
					tokens.push_back(token{ token_type::IS });
				}
				else if (buffer == "as")
				{
					tokens.push_back(token{ token_type::AS });
				}
				else if (buffer == "new")
				{
					tokens.push_back(token{ token_type::NEW });
				}
				else if (buffer == "for")
				{
					tokens.push_back(token{ token_type::FOR });
				}
				else if (buffer == "do")
				{
					tokens.push_back(token{ token_type::DO });
				}
				else if (buffer == "while")
				{
					tokens.push_back(token{ token_type::WHILE });
				}
				else if (buffer == "if")
				{
					tokens.push_back(token{ token_type::IF });
				}
				else if (buffer == "else")
				{
					tokens.push_back(token{ token_type::ELSE });
				}
				else if (buffer == "when")
				{
					tokens.push_back(token{ token_type::WHEN });
				}
				else if (buffer == "matches")
				{
					tokens.push_back(token{ token_type::MATCHES });
				}
				else if (buffer == "default")
				{
					tokens.push_back(token{ token_type::DEFAULT });
				}
				else if (buffer == "return")
				{
					tokens.push_back(token{ token_type::RETURN });
				}
				else if (buffer == "goto")
				{
					tokens.push_back(token{ token_type::GOTO });
				}
				else if (buffer == "continue")
				{
					tokens.push_back(token{ token_type::CONTINUE });
				}
				else if (buffer == "break")
				{
					tokens.push_back(token{ token_type::BREAK });
				}
				else if (buffer == "pub")
				{
					tokens.push_back(token{ token_type::PUB });
				}
				else if (buffer == "prot")
				{
					tokens.push_back(token{ token_type::PROT });
				}
				else if (buffer == "priv")
				{
					tokens.push_back(token{ token_type::PRIV });
				}
				else if (buffer == "static")
				{
					tokens.push_back(token{ token_type::STATIC });
				}
				else if (buffer == "throw")
				{
					tokens.push_back(token{ token_type::THROW });
				}
				else if (buffer == "try")
				{
					tokens.push_back(token{ token_type::TRY });
				}
				else if (buffer == "unless")
				{
					tokens.push_back(token{ token_type::UNLESS });
				}
				else if (buffer == "finally")
				{
					tokens.push_back(token{ token_type::FINALLY });
				}
				else if (buffer == "null")
				{
					tokens.push_back(token{ token_type::NULLPTR });
				}
				else if (buffer == "true")
				{
					tokens.push_back(token{ token_type::TRUE });
				}
				else if (buffer == "false")
				{
					tokens.push_back(token{ token_type::FALSE });
				}
				else if (buffer == "export")
				{
					tokens.push_back(token{ token_type::EXPORT });
				}
				else if (buffer == "import")
				{
					tokens.push_back(token{ token_type::IMPORT });
				}
				else if (buffer == "macro")
				{
					tokens.push_back(token{ token_type::MACRO });
				}
				else
				{
					tokens.push_back(token{ token_type::IDENTIFIER, buffer });
				}
			}
			else if (std::isdigit(peek().value()))
			{
				std::string buffer{};

				while (std::isdigit(peek().value()))
				{
					buffer += peek().value();
					advance();
				}

				tokens.push_back(token{ token_type::NUMBER, buffer });
			}
			else if (peek().value() == '!')
			{
				tokens.push_back(token{ token_type::EXCLAMATION });
				advance();
			}
			else if (peek().value() == '@')
			{
				tokens.push_back(token{ token_type::AT_SIGN });
				advance();
			}
			else if (peek().value() == '#')
			{
				tokens.push_back(token{ token_type::HASHTAG });
				advance();
			}
			else if (peek().value() == '%')
			{
				tokens.push_back(token{ token_type::PERCENT });
				advance();
			}
			else if (peek().value() == '~')
			{
				tokens.push_back(token{ token_type::TILDE });
				advance();
			}
			else if (peek().value() == '^')
			{
				tokens.push_back(token{ token_type::CARET });
				advance();
			}
			else if (peek().value() == '&')
			{
				tokens.push_back(token{ token_type::AMPERSAND });
				advance();
			}
			else if (peek().value() == '+')
			{
				tokens.push_back(token{ token_type::PLUS });
				advance();
			}
			else if (peek().value() == '-')
			{
				tokens.push_back(token{ token_type::DASH });
				advance();
			}
			else if (peek().value() == '*')
			{
				tokens.push_back(token{ token_type::STAR });
				advance();
			}
			else if (peek().value() == '/')
			{
				tokens.push_back(token{ token_type::SLASH });
				advance();
			}
			else if (peek().value() == '=')
			{
				tokens.push_back(token{ token_type::EQUAL });
				advance();
			}
			else if (peek().value() == ':')
			{
				tokens.push_back(token{ token_type::COLON });
				advance();
			}
			else if (peek().value() == ';')
			{
				tokens.push_back(token{ token_type::SEMICOLON });
				advance();
			}
			else if (peek().value() == '`')
			{
				tokens.push_back(token{ token_type::GRAVE });
				advance();
			}
			else if (peek().value() == '\'')
			{
				tokens.push_back(token{ token_type::APOSTROPHE });
				advance();
			}
			else if (peek().value() == '"')
			{
				tokens.push_back(token{ token_type::QUOTE });
				advance();
			}
			else if (peek().value() == ',')
			{
				tokens.push_back(token{ token_type::COMMA });
				advance();
			}
			else if (peek().value() == '.')
			{
				tokens.push_back(token{ token_type::PERIOD });
				advance();
			}
			else if (peek().value() == '\\')
			{
				tokens.push_back(token{ token_type::BACKSLASH });
				advance();
			}
			else if (peek().value() == '|')
			{
				tokens.push_back(token{ token_type::BAR });
				advance();
			}
			else if (peek().value() == '?')
			{
				tokens.push_back(token{ token_type::QUESTION });
				advance();
			}
			else if (peek().value() == '(')
			{
				tokens.push_back(token{ token_type::LEFT_PAREN });
				advance();
			}
			else if (peek().value() == ')')
			{
				tokens.push_back(token{ token_type::RIGHT_PAREN });
				advance();
			}
			else if (peek().value() == '[')
			{
				tokens.push_back(token{ token_type::LEFT_SQUARE });
				advance();
			}
			else if (peek().value() == ']')
			{
				tokens.push_back(token{ token_type::RIGHT_SQUARE });
				advance();
			}
			else if (peek().value() == '{')
			{
				tokens.push_back(token{ token_type::LEFT_BRACE });
				advance();
			}
			else if (peek().value() == '}')
			{
				tokens.push_back(token{ token_type::RIGHT_BRACE });
				advance();
			}
			else if (peek().value() == '<')
			{
				tokens.push_back(token{ token_type::LESS_THAN });
				advance();
			}
			else if (peek().value() == '>')
			{
				tokens.push_back(token{ token_type::MORE_THAN });
				advance();
			}
			else
			{
				std::cout << "Error: unknown character '" << peek().value() << "' at index of " << m_index << "\n";
				advance();
			}
		}

		return tokens;
	}

	char tokenizer::advance()
	{
		return m_source.at(m_index++);
	}

	[[nodiscard]] std::optional<char> tokenizer::peek() const
	{
		return is_eof() ? -1 : m_source.at(m_index);
	}

	[[nodiscard]] bool tokenizer::is_eof() const
	{
		return (m_index >= m_length);
	}

	[[nodiscard]] bool tokenizer::has_error() const
	{
		return (!m_errors.empty());
	}

	[[nodiscard]] std::vector<std::string> tokenizer::error_messages() const
	{
		return m_errors;
	}
} // schort
