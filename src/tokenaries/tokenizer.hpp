#ifndef SCHORT_TOKENIZER_HPP
#define SCHORT_TOKENIZER_HPP

#include <optional>
#include <string>
#include <vector>

#include "token.hpp"

namespace schort
{
	class tokenizer
	{
	public:
		explicit tokenizer(std::string source);

		~tokenizer();

		std::vector<token> tokenize();

		tokenizer() = delete;

		tokenizer(const tokenizer &) = delete;

		tokenizer &operator=(const tokenizer &) = delete;

	private:
		char next();

		[[nodiscard]] std::optional<char> peek() const;

		[[nodiscard]] bool is_eof() const;

	private:
		std::size_t m_index{};

		std::vector<std::string> m_errors{};

		const std::size_t m_length{};

		const std::string m_source{};
	};
} // schort

#endif //SCHORT_TOKENIZER_HPP
