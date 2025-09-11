#ifndef SCHORT_PARSER_HPP
#define SCHORT_PARSER_HPP

#include <vector>

#include "../tokenaries/token.hpp"

namespace schort
{
	struct token;

	class parser
	{
	public:
		explicit parser(const std::vector<token> &tokens);

		~parser();

	public:
		parser() = delete;

		parser(const parser &) = delete;

		parser &operator=(const parser &) = delete;

	private:
		std::size_t m_index{};

		const std::size_t m_length{};

		const std::vector<token> m_tokens{};
	};
} // schort

#endif //SCHORT_PARSER_HPP
