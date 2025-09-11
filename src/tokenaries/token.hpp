#ifndef SCHORT_TOKEN_HPP
#define SCHORT_TOKEN_HPP

#include <optional>
#include <string>

#include "token_type.hpp"

namespace schort
{
	struct token
	{
		token_type type{};

		std::optional<std::string> value{};
	};
}

#endif // SCHORT_TOKEN_HPP
