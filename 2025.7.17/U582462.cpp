#include <bits/stdc++.h>
using namespace std;
void CompileError(string error_message, int line_number)
{
	cout << "Compile Error\n"
		 << line_number << ": " << error_message << '\n';
	exit(0);
}
void RuntimeError(string error_message)
{
	cout << "Runtime Error\n"
		 << error_message << '\n';
	exit(0);
}
namespace DataTypes
{
	class number;
	class string;
	class boolean;
	class number
	{
	private:
		unsigned long long value; // 值
		bool negative;			  // 是否为负数
	public:
		number()
		{
			value = 0;
			negative = false;
		}
		number(unsigned long long _value, bool _negative)
		{
			value = _value;
			if (_value == 0)
				negative = false; // 0 不是负数
			else
				negative = _negative;
		}
		number(long long _value)
		{
			value = llabs(_value);
			negative = _value < 0;
		}
		operator boolean();
		number operator+(number other)
		{
			if (negative == other.negative)
				return number(value + other.value, negative);
			else if (value > other.value)
				return number(value - other.value, negative);
			else
				return number(other.value - value, other.negative);
		}
		number operator-(number other)
		{
			return *this + number(other.value, !other.negative);
		}
		number operator*(number other)
		{
			return number(value * other.value, negative ^ other.negative);
		}
		number operator/(number other)
		{
			return number(value / other.value, negative ^ other.negative);
		}
		number operator%(number other)
		{
			return number(value % other.value, negative);
		}
		bool operator>(number other)
		{
			if (negative == other.negative)
				return (value > other.value) ^ negative;
			else
				return !negative;
		}
		bool operator<(number other)
		{
			return other > *this;
		}
		bool operator>=(number other)
		{
			return !(*this < other);
		}
		bool operator<=(number other)
		{
			return !(*this > other);
		}
		bool operator==(number other)
		{
			return value == other.value && negative == other.negative;
		}
		bool operator!=(number other)
		{
			return !(*this == other);
		}
		friend ostream &operator<<(ostream &os, const number &num)
		{
			if (num.negative)
				os << '-';
			os << num.value;
			return os;
		}
	};
	class string
	{
	private:
		::string value; // 值
	public:
		string()
		{
			value = "";
		}
		string(::string _value)
		{
			value = _value;
		}
		operator ::string()
		{
			return value;
		}
		friend ostream &operator<<(ostream &os, const string &s)
		{
			os << s.value;
			return os;
		}
	};
	class boolean
	{
	private:
		bool value; // 值
	public:
		boolean()
		{
			value = false;
		}
		boolean(bool _value)
		{
			value = _value;
		}
		operator number()
		{
			return number(value ? 1 : 0, false);
		}
		friend ostream &operator<<(ostream &os, const boolean &b)
		{
			os << (b.value ? "true" : "false");
			return os;
		}
	};
	number::operator boolean()
	{
		return boolean(value != 0);
	}
}
/// @brief token 类型
enum token_type
{
	token_number,			 // 整数
	token_string,			 // 字符串
	token_boolean,			 // 布尔
	token_operator,			 // 运算符
	token_left_parentheses,	 // 左括号
	token_right_parentheses, // 右括号
	token_endline,			 // 换行
	token_keyword,			 // 关键字
	token_variable			 // 变量
};
/// @brief 运算符类型
enum operator_type
{
	operator_add,			// 加法
	operator_sub,			// 减法
	operator_mul,			// 乘法
	operator_div,			// 除法
	operator_mod,			// 取模
	operator_greater,		// 大于
	operator_greater_equal, // 大于等于
	operator_equal,			// 等于
	operator_less_equal,	// 小于等于
	operator_less,			// 小于
	operator_not_equal,		// 不等于
};
/// @brief 关键字类型
enum keyword_type
{
	keyword_new,	  // set
	keyword_set,	  // set
	keyword_to,		  // to
	keyword_input,	  // input
	keyword_get_line, // get_line
	keyword_output,	  // output
	keyword_if,		  // if
	keyword_then,	  // then
	keyword_else,	  // else
	keyword_endif,	  // endif
	keyword_while,	  // while
	keyword_do,		  // do
	keyword_endwhile, // endwhile
};
enum variable_type
{
	variable_number, // 整数
	variable_string, // 字符串
	variable_boolean // 布尔
};
/// @brief token 值
struct token_value
{
	DataTypes::number number_value;
	DataTypes::string string_value;
	DataTypes::boolean boolean_value;
	operator_type operator_value;
	keyword_type keyword_value;
	token_value()
	{
	}
	token_value(DataTypes::number _number_value)
	{
		number_value = _number_value;
	}
	token_value(DataTypes::string _string_value)
	{
		string_value = _string_value;
	}
	token_value(DataTypes::boolean _boolean_value)
	{
		boolean_value = _boolean_value;
	}
	token_value(operator_type _operator_value)
	{
		operator_value = _operator_value;
	}
	token_value(keyword_type _keyword_value)
	{
		keyword_value = _keyword_value;
	}
};
/// @brief 关键字及其字符串表示的对应
map<string, keyword_type> keywords = {
	{"new", keyword_new},
	{"set", keyword_set},
	{"to", keyword_to},
	{"input", keyword_input},
	{"getline", keyword_get_line},
	{"output", keyword_output},
	{"if", keyword_if},
	{"then", keyword_then},
	{"else", keyword_else},
	{"endif", keyword_endif},
	{"while", keyword_while},
	{"do", keyword_do},
	{"endwhile", keyword_endwhile}};
/// @brief 运算符及其字符串表示的对应
map<string, operator_type> operators = {
	{"+", operator_add},
	{"-", operator_sub},
	{"*", operator_mul},
	{"/", operator_div},
	{"%", operator_mod},
	{">", operator_greater},
	{">=", operator_greater_equal},
	{"==", operator_equal},
	{"<=", operator_less_equal},
	{"<", operator_less},
	{"!=", operator_not_equal}};
/// @brief 单字符运算符及其字符表示的对应
map<char, operator_type> operators_char = {
	{'+', operator_add},
	{'-', operator_sub},
	{'*', operator_mul},
	{'/', operator_div},
	{'%', operator_mod}};
/// @brief 双字符运算符及其字符表示的对应
map<string, operator_type> operators_string = {
	{">", operator_greater},
	{">=", operator_greater_equal},
	{"==", operator_equal},
	{"<=", operator_less_equal},
	{"<", operator_less},
	{"!=", operator_not_equal}};
/// @brief token 结构体
struct token
{
	token_type type;
	token_value value;
	token(token_type _type, token_value _value)
	{
		type = _type;
		value = _value;
	}
};
/// @brief 判断是否是空白字符
/// @param c 需要判断的字符
/// @return 是否是空白字符
bool is_blank(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}
/// @brief 字符串转整数
/// @param s 要转换的字符串
/// @return 转换后的整数
/// @throws 如果字符串不是整数，则抛出异常 `runtime_error`，内容为“Not a number!”
DataTypes::number string_to_number(string s)
{
	unsigned long long res = 0;
	if (s[0] == '-')
	{
		for (size_t i = 1; i < s.size(); ++i)
			if ('0' <= s[i] && s[i] <= '9')
				res = res * 10 + (s[i] - '0');
			else
				throw runtime_error("Not a number!");
		return DataTypes::number(res, true);
	}
	else if (s[0] == '+')
	{
		for (size_t i = 1; i < s.size(); ++i)
			if ('0' <= s[i] && s[i] <= '9')
				res = res * 10 + (s[i] - '0');
			else
				throw runtime_error("Not a number!");
		return DataTypes::number(res, false);
	}
	else
	{
		for (size_t i = 0; i < s.size(); ++i)
			if ('0' <= s[i] && s[i] <= '9')
				res = res * 10 + (s[i] - '0');
			else
				throw runtime_error("Not a number!");
		return DataTypes::number(res, false);
	}
}
vector<token> tokens;
string program;
map<string, token> variables;
void add_token(string str)
{
	map<string, keyword_type>::iterator it_keyword = keywords.find(str);
	if (it_keyword != keywords.end())
		tokens.push_back(token(token_keyword, it_keyword->second));
	else
	{
		map<string, operator_type>::iterator it_operator = operators.find(str);
		if (it_operator != operators.end())
			tokens.push_back(token(token_operator, it_operator->second));
		else if (str == "(")
		{
			tokens.push_back(token(token_left_parentheses, token_value()));
			str.clear();
		}
		else if (str == ")")
		{
			tokens.push_back(token(token_right_parentheses, token_value()));
			str.clear();
		}
		else if (str == "true")
			tokens.push_back(token(token_boolean, DataTypes::boolean(true)));
		else if (str == "false")
			tokens.push_back(token(token_boolean, DataTypes::boolean(false)));
		else
		{
			try
			{
				tokens.push_back(token(token_number, string_to_number(str)));
			}
			catch (runtime_error &e)
			{
				tokens.push_back(token(token_variable, DataTypes::string(str)));
			}
		}
	}
}
/// @brief 词法分析函数
void lexer()
{
	string t;
	bool in_string = false;
	for (const char &c : program)
	{
		if (is_blank(c) && !in_string)
		{
			if (!t.empty())
			{
				add_token(t);
				t.clear();
			}
			if (c == '\n')
				tokens.push_back(token(token_endline, token_value()));
		}
		else
		{
			if (c == '"')
			{
				in_string = !in_string;
				if (!in_string)
				{
					tokens.push_back(token(token_string, DataTypes::string(t)));
					t.clear();
				}
			}
			else if (c == '\n')
				CompileError("Unclosed string", program.size());
			else
				t += c;
			if (t.back() == '(')
			{
				string tmp(t.begin(), t.end() - 1);
				if (!tmp.empty())
				{
					add_token(tmp);
					t.clear();
				}
				tokens.push_back(token(token_left_parentheses, token_value()));
				t.clear();
			}
			else if (t.back() == ')')
			{
				string tmp(t.begin(), t.end() - 1);
				if (!tmp.empty())
				{
					add_token(tmp);
					t.clear();
				}
				tokens.push_back(token(token_right_parentheses, token_value()));
				t.clear();
			}
			else
			{
				map<char, operator_type>::iterator it_operator_char = operators_char.find(t.back());
				if (it_operator_char != operators_char.end())
				{
					string tmp(t.begin(), t.end() - 1);
					if (!tmp.empty())
					{
						add_token(tmp);
						t.clear();
					}
					tokens.push_back(token(token_operator, it_operator_char->second));
					t.clear();
				}
				else
				{
					map<string, operator_type>::iterator it_operator_string = operators_string.find(string(t.end() - 2, t.end()));
					if (it_operator_string != operators_string.end())
					{
						string tmp(t.begin(), t.end() - 2);
						if (!tmp.empty())
						{
							add_token(tmp);
							t.clear();
						}
						tokens.push_back(token(token_operator, it_operator_string->second));
						t.clear();
					}
				}
			}
		}
	}
}
void parser();
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (cin.get() != '\n')
		;
	for (int i = 0; i < n; ++i)
	{
		string s;
		getline(cin, s);
		program += s + '\n';
	}
	lexer();
	for (size_t i = 0; i < tokens.size(); ++i)
		if (tokens[i].type == token_number)
			cout << "Number: " << tokens[i].value.number_value << '\n';
		else if (tokens[i].type == token_string)
			cout << "String: " << tokens[i].value.string_value << '\n';
		else if (tokens[i].type == token_boolean)
			cout << "Boolean: " << tokens[i].value.boolean_value << '\n';
		else if (tokens[i].type == token_variable)
			cout << "Variable: " << tokens[i].value.string_value << '\n';
		else if (tokens[i].type == token_keyword)
			cout << "Keyword: " << tokens[i].value.keyword_value << '\n';
		else if (tokens[i].type == token_operator)
			cout << "Operator: " << tokens[i].value.operator_value << '\n';
		else if (tokens[i].type == token_left_parentheses)
			cout << "Left parentheses\n";
		else if (tokens[i].type == token_right_parentheses)
			cout << "Right parentheses\n";
		else if (tokens[i].type == token_endline)
			cout << "Endline\n";
	return 0;
}