#include "token.hpp"

namespace schort
{
	token::operator std::string() const
	{
		std::string out{};

		out = "token [" + token_type_to_string(type);

		if (value.has_value())
		{
			out += ", " + value.value();
		}

		out += "]";

		return out;
	}
}
