#ifndef SCHORT_TOKEN_TYPE_HPP
#define SCHORT_TOKEN_TYPE_HPP

#include <string>

namespace schort
{
	enum class token_type
	{
		IDENTIFIER, NUMBER,

		CONST, MUT, MET,

		VOID, BOOL,
		FLOAT, DOUBLE,

		UNSIGNED, SIGNED,

		BYTE, SHORT, INT, LONG,

		STRUCT, IMPL, TRAIT, ENUM,
		SELF, SUPER, IS, AS, NEW,

		FOR, DO, WHILE,
		IF, ELSE, WHEN, MATCHES, DEFAULT,
		RETURN, GOTO, CONTINUE, BREAK,

		PUB, PROT, PRIV, STATIC,
		THROW, TRY, UNLESS, FINALLY,

		NULLPTR, TRUE, FALSE,
		EXPORT, IMPORT, MACRO,

		EXCLAMATION,
		AT_SIGN, HASHTAG, PERCENT,
		TILDE, CARET, AMPERSAND,
		PLUS, DASH, STAR, SLASH, EQUAL,
		COLON, SEMICOLON,
		GRAVE, APOSTROPHE, QUOTE,
		COMMA, PERIOD,
		BACKSLASH, BAR,
		QUESTION,
		LEFT_PAREN, RIGHT_PAREN,
		LEFT_SQUARE, RIGHT_SQUARE,
		LEFT_BRACE, RIGHT_BRACE,
		LESS_THAN, MORE_THAN,
	};

	inline std::string token_type_to_string(const token_type &type)
	{
		switch (type)
		{
		case token_type::IDENTIFIER:
			return "IDENTIFIER";

		case token_type::NUMBER:
			return "NUMBER";

		case token_type::CONST:
			return "CONST";

		case token_type::MUT:
			return "MUT";

		case token_type::MET:
			return "MET";

		case token_type::VOID:
			return "VOID";

		case token_type::BOOL:
			return "BOOL";

		case token_type::FLOAT:
			return "FLOAT";

		case token_type::DOUBLE:
			return "DOUBLE";

		case token_type::UNSIGNED:
			return "UNSIGNED";

		case token_type::SIGNED:
			return "SIGNED";

		case token_type::BYTE:
			return "BYTE";

		case token_type::SHORT:
			return "SHORT";

		case token_type::INT:
			return "INT";

		case token_type::LONG:
			return "LONG";

		case token_type::STRUCT:
			return "STRUCT";

		case token_type::IMPL:
			return "IMPL";

		case token_type::TRAIT:
			return "TRAIT";

		case token_type::ENUM:
			return "ENUM";

		case token_type::SELF:
			return "SELF";

		case token_type::SUPER:
			return "SUPER";

		case token_type::IS:
			return "IS";

		case token_type::AS:
			return "AS";

		case token_type::NEW:
			return "NEW";

		case token_type::FOR:
			return "FOR";

		case token_type::DO:
			return "DO";

		case token_type::WHILE:
			return "WHILE";

		case token_type::IF:
			return "IF";

		case token_type::ELSE:
			return "ELSE";

		case token_type::WHEN:
			return "WHEN";

		case token_type::MATCHES:
			return "MATCHES";

		case token_type::DEFAULT:
			return "DEFAULT";

		case token_type::RETURN:
			return "RETURN";

		case token_type::GOTO:
			return "GOTO";

		case token_type::CONTINUE:
			return "CONTINUE";

		case token_type::BREAK:
			return "BREAK";

		case token_type::PUB:
			return "PUB";

		case token_type::PROT:
			return "PROT";

		case token_type::PRIV:
			return "PRIV";

		case token_type::STATIC:
			return "STATIC";

		case token_type::THROW:
			return "THROW";

		case token_type::TRY:
			return "TRY";

		case token_type::UNLESS:
			return "UNLESS";

		case token_type::FINALLY:
			return "FINALLY";

		case token_type::NULLPTR:
			return "NULLPTR";

		case token_type::TRUE:
			return "TRUE";

		case token_type::FALSE:
			return "FALSE";

		case token_type::EXPORT:
			return "EXPORT";

		case token_type::IMPORT:
			return "IMPORT";

		case token_type::MACRO:
			return "MACRO";

		case token_type::EXCLAMATION:
			return "EXCLAMATION";

		case token_type::AT_SIGN:
			return "AT_SIGN";

		case token_type::HASHTAG:
			return "HASHTAG";

		case token_type::PERCENT:
			return "PERCENT";

		case token_type::TILDE:
			return "TILDE";

		case token_type::CARET:
			return "CARET";

		case token_type::AMPERSAND:
			return "AMPERSAND";

		case token_type::PLUS:
			return "PLUS";

		case token_type::DASH:
			return "DASH";

		case token_type::STAR:
			return "STAR";

		case token_type::SLASH:
			return "SLASH";

		case token_type::EQUAL:
			return "EQUAL";

		case token_type::COLON:
			return "COLON";

		case token_type::SEMICOLON:
			return "SEMICOLON";

		case token_type::GRAVE:
			return "GRAVE";

		case token_type::APOSTROPHE:
			return "APOSTROPHE";

		case token_type::QUOTE:
			return "QUOTE";

		case token_type::COMMA:
			return "COMMA";

		case token_type::PERIOD:
			return "PERIOD";

		case token_type::BACKSLASH:
			return "BACKSLASH";

		case token_type::BAR:
			return "BAR";

		case token_type::QUESTION:
			return "QUESTION";

		case token_type::LEFT_PAREN:
			return "LEFT_PAREN";

		case token_type::RIGHT_PAREN:
			return "RIGHT_PAREN";

		case token_type::LEFT_BRACE:
			return "LEFT_BRACE";

		case token_type::RIGHT_BRACE:
			return "RIGHT_BRACE";

		case token_type::LEFT_SQUARE:
			return "LEFT_SQUARE";

		case token_type::RIGHT_SQUARE:
			return "RIGHT_SQUARE";

		case token_type::LESS_THAN:
			return "LESS_THAN";

		case token_type::MORE_THAN:
			return "MORE_THAN";

		default:
			return "UNKNOWN";
		}
	}
}

#endif // SCHORT_TOKEN_TYPE_HPP
