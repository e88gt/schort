#include "parser.hpp"

namespace schort
{
	parser::parser(const std::vector<token> &tokens)
		: m_index{ 0 }, m_length{ tokens.size() }, m_tokens{ tokens }
	{
	}

	parser::~parser() = default;
} // schort
