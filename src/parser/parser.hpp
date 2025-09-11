#ifndef SCHORT_PARSER_HPP
#define SCHORT_PARSER_HPP

#include <vector>

#include "../ast/ast.hpp"
#include "../tokenaries/token.hpp"

namespace schort
{
	struct token;

	class parser
	{
	public:
		explicit parser(const std::vector<token> &tokens);

		~parser();

		[[nodiscard]] ast parse();

	public:
		parser() = delete;

		parser(const parser &) = delete;

		parser &operator=(const parser &) = delete;

	private:
		token advance();

		[[nodiscard]] std::optional<token> peek() const;

		[[nodiscard]] inline bool is_eof() const;

	private:
		std::size_t m_index{};

		const std::size_t m_length{};

		const std::vector<token> m_tokens{};
	};
} // schort

#endif //SCHORT_PARSER_HPP
