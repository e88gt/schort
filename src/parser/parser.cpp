#include "parser.hpp"

namespace schort
{
	parser::~parser() = default;

	parser::parser(const std::vector<token> &tokens)
		: m_index{ 0 }, m_length{ tokens.size() }, m_tokens{ tokens }
	{
	}

	ast parser::parse()
	{
		ast ast{};

		while (!is_eof())
		{
		}

		return ast;
	}

	token parser::advance()
	{
		return m_tokens.at(m_index++);
	}

	std::optional<token> parser::peek() const
	{
		return m_tokens.at(m_index);
	}

	inline bool parser::is_eof() const
	{
		return (m_index >= m_length);
	}
} // schort
