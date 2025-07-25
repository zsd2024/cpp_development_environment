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
}
DataTypes::number string_to_number(string s);
void getline(istream &in, DataTypes::string &str);
namespace DataTypes
{
	class number;
	class string;
	class boolean;
	class number
	{
		friend class boolean;

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
		number(boolean _value);
		number operator+(const number other) const
		{
			if (negative == other.negative)
				return number(value + other.value, negative);
			else if (value > other.value)
				return number(value - other.value, negative);
			else
				return number(other.value - value, other.negative);
		}
		number operator-(const number other) const
		{
			return *this + number(other.value, !other.negative);
		}
		number operator*(const number other) const
		{
			return number(value * other.value, negative ^ other.negative);
		}
		number operator/(const number other) const
		{
			return number(value / other.value, negative ^ other.negative);
		}
		number operator%(const number other) const
		{
			return number(value % other.value, negative);
		}
		bool operator>(number other) const
		{
			if (negative == other.negative)
				return (value > other.value) ^ negative;
			else
				return !negative;
		}
		bool operator<(number other) const
		{
			return other > *this;
		}
		bool operator>=(number other) const
		{
			return !(*this < other);
		}
		bool operator<=(number other) const
		{
			return !(*this > other);
		}
		bool operator==(number other) const
		{
			return value == other.value && negative == other.negative;
		}
		bool operator!=(number other) const
		{
			return !(*this == other);
		}
		/// @throws 如果输入的字符串不是整数，则抛出异常 `runtime_error`，内容为“Not a number!”
		friend istream &operator>>(istream &in, number &num)
		{
			::string str;
			in >> str;
			num = string_to_number(str);
			return in;
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
		friend void ::getline(istream &in, string &str);

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
		::string &to_string()
		{
			return value;
		}
		string operator+(const string &other) const
		{
			return string(value + other.value);
		}
		bool operator>(const string &other) const
		{
			return value > other.value;
		}
		bool operator>=(const string &other) const
		{
			return value >= other.value;
		}
		bool operator==(const string &other) const
		{
			return value == other.value;
		}
		bool operator<=(const string &other) const
		{
			return value <= other.value;
		}
		bool operator<(const string &other) const
		{
			return value < other.value;
		}
		bool operator!=(const string &other) const
		{
			return value != other.value;
		}
		friend istream &operator>>(istream &in, string &s)
		{
			in >> s.value;
			return in;
		}
		friend ostream &operator<<(ostream &os, const string &s)
		{
			os << s.value;
			return os;
		}
	};
	class boolean
	{
		friend class number;

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
		operator bool() const
		{
			return value;
		}
		boolean(number _value);
		/// @throws 如果输入的字符串不是布尔值，则抛出异常 `runtime_error`，内容为“Not a boolean!”
		friend istream &operator>>(istream &in, boolean &b)
		{
			::string str;
			in >> str;
			for (char &c : str)
				c = tolower(c);
			if (str == "1" || str == "true" || str == "yes")
				b.value = true;
			else if (str == "0" || str == "false" || str == "no")
				b.value = false;
			else
				throw runtime_error("Not a boolean!");
			return in;
		}
		friend ostream &operator<<(ostream &os, const boolean &b)
		{
			os << (b.value ? "true" : "false");
			return os;
		}
	};
	inline number::number(boolean _value)
	{
		value = _value.value ? 1 : 0;
	}
	boolean::boolean(number _value)
	{
		value = _value.value != 0;
	}
}
void getline(istream &in, DataTypes::string &str)
{
	getline(in, str.value);
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
	token_data_type,		 // 类型
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
	keyword_new,	  // new
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
	variable_null,		  // 无
	variable_type_number, // 整数
	variable_type_string, // 字符串
	variable_type_boolean // 布尔
};
/// @brief token 值
struct token_value
{
	DataTypes::number number_value;
	DataTypes::string string_value;
	DataTypes::boolean boolean_value;
	operator_type operator_value;
	keyword_type keyword_value;
	variable_type variable_type_value;
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
	token_value(variable_type _variable_type_value)
	{
		variable_type_value = _variable_type_value;
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
/// @brief 变量类型及其字符串表示的对应
map<string, variable_type> variables_type_string = {
	{"number", variable_type_number},
	{"string", variable_type_string},
	{"boolean", variable_type_boolean}};
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
void add_token(string str)
{
	if (str == "(")
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
			map<string, keyword_type>::iterator it_keyword = keywords.find(str);
			if (it_keyword != keywords.end())
				tokens.push_back(token(token_keyword, it_keyword->second));
			else
			{
				map<string, operator_type>::iterator it_operator = operators.find(str);
				if (it_operator != operators.end())
					tokens.push_back(token(token_operator, it_operator->second));
				else
				{
					map<string, variable_type>::iterator it_variable = variables_type_string.find(str);
					if (it_variable != variables_type_string.end())
						tokens.push_back(token(token_data_type, it_variable->second));
					else
					{
						regex reg("[a-zA-Z_][a-zA-Z0-9_]*");
						if (!regex_match(str, reg))
							throw runtime_error("Wrong name!");
						tokens.push_back(token(token_variable, DataTypes::string(str)));
					}
				}
			}
		}
	}
}
/// @brief 词法分析函数
void lexer()
{
	string t;
	bool in_string = false;
	int line_number = 1;
	for (const char &c : program)
	{
		if (is_blank(c) && !in_string)
		{
			if (!t.empty())
			{
				try
				{
					add_token(t);
				}
				catch (runtime_error &e)
				{
					CompileError("Invalid identifier", line_number);
				}
				t.clear();
			}
			if (c == '\n')
			{
				tokens.push_back(token(token_endline, token_value()));
				++line_number;
			}
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
				CompileError("Unclosed string", line_number);
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
struct variable_value
{
	variable_type type;
	DataTypes::number number_value;
	DataTypes::string string_value;
	DataTypes::boolean boolean_value;
	variable_value()
	{
	}
	variable_value(variable_type _type)
	{
		type = _type;
	}
	variable_value(DataTypes::number _number_value)
	{
		type = variable_type_number;
		number_value = _number_value;
	}
	variable_value(DataTypes::string _string_value)
	{
		type = variable_type_string;
		string_value = _string_value;
	}
	variable_value(DataTypes::boolean _boolean_value)
	{
		type = variable_type_boolean;
		boolean_value = _boolean_value;
	}
	variable_value operator=(const variable_value &other)
	{
		if (this->type == variable_type_number)
		{
			if (other.type == variable_type_number)
				this->number_value = other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot assign string to non-string variable");
			else if (other.type == variable_type_boolean)
				this->number_value = other.boolean_value;
		}
		else if (this->type == variable_type_string)
		{
			if (other.type == variable_type_number)
				throw runtime_error("Cannot assign string to non-string variable");
			else if (other.type == variable_type_string)
				this->string_value = other.string_value;
			else if (other.type == variable_type_boolean)
				throw runtime_error("Cannot assign string to non-string variable");
		}
		else if (this->type == variable_type_boolean)
		{
			if (other.type == variable_type_number)
				this->boolean_value = other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot assign string to non-string variable");
			else if (other.type == variable_type_boolean)
				this->boolean_value = other.boolean_value;
		}
	}
	variable_value operator+(const variable_value &other)
	{
		if (this->type == variable_type_number)
			if (other.type == variable_type_number)
				return this->number_value + other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot add string to non-string variable");
			else if (other.type == variable_type_boolean)
				return this->number_value + other.boolean_value;
			else if (this->type == variable_type_string)
				if (other.type == variable_type_number)
					throw runtime_error("Cannot add string to non-string variable");
				else if (other.type == variable_type_string)
					return this->string_value + other.string_value;
				else if (other.type == variable_type_boolean)
					throw runtime_error("Cannot add string to non-string variable");
				else if (this->type == variable_type_boolean)
					if (other.type == variable_type_number)
						return DataTypes::number(this->boolean_value) + other.number_value;
					else if (other.type == variable_type_string)
						throw runtime_error("Cannot add string to non-string variable");
					else if (other.type == variable_type_boolean)
						throw runtime_error("Cannot add string to non-string variable");
	}
	variable_value operator-(const variable_value &other)
	{
		if (this->type == variable_type_number)
			if (other.type == variable_type_number)
				return this->number_value - other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot subtract string from non-string variable");
			else if (other.type == variable_type_boolean)
				return this->number_value - other.boolean_value;
			else if (this->type == variable_type_string)
				if (other.type == variable_type_number)
					throw runtime_error("Cannot subtract string from non-string variable");
				else if (other.type == variable_type_string)
					throw runtime_error("Cannot subtract string from non-string variable");
				else if (other.type == variable_type_boolean)
					throw runtime_error("Cannot subtract string from non-string variable");
				else if (this->type == variable_type_boolean)
					if (other.type == variable_type_number)
						return DataTypes::number(this->boolean_value) - other.number_value;
					else if (other.type == variable_type_string)
						throw runtime_error("Cannot subtract string from non-string variable");
					else if (other.type == variable_type_boolean)
						throw runtime_error("Cannot subtract string from non-string variable");
	}
	variable_value operator*(const variable_value &other)
	{
		if (this->type == variable_type_number)
			if (other.type == variable_type_number)
				return this->number_value * other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot multiply string to non-string variable");
			else if (other.type == variable_type_boolean)
				return this->number_value * other.boolean_value;
			else if (this->type == variable_type_string)
				if (other.type == variable_type_number)
					throw runtime_error("Cannot multiply string to non-string variable");
				else if (other.type == variable_type_string)
					throw runtime_error("Cannot multiply string to non-string variable");
				else if (other.type == variable_type_boolean)
					throw runtime_error("Cannot multiply string to non-string variable");
				else if (this->type == variable_type_boolean)
					if (other.type == variable_type_number)
						return DataTypes::number(this->boolean_value) * other.number_value;
					else if (other.type == variable_type_string)
						throw runtime_error("Cannot multiply string to non-string variable");
					else if (other.type == variable_type_boolean)
						throw runtime_error("Cannot multiply string to non-string variable");
	}
	variable_value operator/(const variable_value &other)
	{
		if (this->type == variable_type_number)
		{
			if (other.type == variable_type_number)
				if (other.number_value == (DataTypes::number)0)
					throw runtime_error("Division by zero");
				else
					return this->number_value / other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot divide string to non-string variable");
			else if (other.type == variable_type_boolean)
				if ((DataTypes::number)other.boolean_value == (DataTypes::number)0)
					throw runtime_error("Division by zero");
				else
					return this->number_value / other.boolean_value;
		}
		else if (this->type == variable_type_string)
		{
			if (other.type == variable_type_number)
				throw runtime_error("Cannot divide string to non-string variable");
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot divide string to non-string variable");
			else if (other.type == variable_type_boolean)
				throw runtime_error("Cannot divide string to non-string variable");
		}
		else if (this->type == variable_type_boolean)
		{
			if (other.type == variable_type_number)
				if (other.number_value == (DataTypes::number)0)
					throw runtime_error("Division by zero");
				else
					return DataTypes::number(this->boolean_value) / other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot divide string to non-string variable");
			else if (other.type == variable_type_boolean)
				throw runtime_error("Cannot divide string to non-string variable");
		}
	}
	variable_value operator%(const variable_value &other)
	{
		if (this->type == variable_type_number)
		{
			if (other.type == variable_type_number)
				if (other.number_value == (DataTypes::number)0)
					throw runtime_error("Modulus by zero");
				else
					return this->number_value % other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot modulus string to non-string variable");
			else if (other.type == variable_type_boolean)
				if ((DataTypes::number)other.boolean_value == (DataTypes::number)0)
					throw runtime_error("Modulus by zero");
				else
					return this->number_value % other.boolean_value;
		}
		else if (this->type == variable_type_string)
		{
			if (other.type == variable_type_number)
				throw runtime_error("Cannot modulus string to non-string variable");
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot modulus string to non-string variable");
			else if (other.type == variable_type_boolean)
				throw runtime_error("Cannot modulus string to non-string variable");
		}
		else if (this->type == variable_type_boolean)
		{
			if (other.type == variable_type_number)
				if (other.number_value == (DataTypes::number)0)
					throw runtime_error("Modulus by zero");
				else
					return DataTypes::number(this->boolean_value) % other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot modulus string to non-string variable");
			else if (other.type == variable_type_boolean)
				if ((DataTypes::number)other.boolean_value == (DataTypes::number)0)
					throw runtime_error("Modulus by zero");
				else
					return DataTypes::number(this->boolean_value) % other.boolean_value;
		}
	}
	bool operator>(const variable_value &other) const
	{
		if (this->type == variable_type_number)
		{
			if (other.type == variable_type_number)
				return this->number_value > other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot compare string to non-string variable");
			else if (other.type == variable_type_boolean)
				return this->number_value > other.boolean_value;
		}
		else if (this->type == variable_type_string)
		{
			if (other.type == variable_type_number)
				throw runtime_error("Cannot compare string to non-string variable");
			else if (other.type == variable_type_string)
				return this->string_value > other.string_value;
			else if (other.type == variable_type_boolean)
				throw runtime_error("Cannot compare string to non-string variable");
		}
		else if (this->type == variable_type_boolean)
		{
			if (other.type == variable_type_number)
				return (DataTypes::number)this->boolean_value > other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot compare string to non-string variable");
			else if (other.type == variable_type_boolean)
				return (DataTypes::number)this->boolean_value > (DataTypes::number)other.boolean_value;
		}
	}
	bool operator<(const variable_value &other) const
	{
		if (this->type == variable_type_number)
		{
			if (other.type == variable_type_number)
				return this->number_value < other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot compare string to non-string variable");
			else if (other.type == variable_type_boolean)
				return this->number_value < other.boolean_value;
		}
		else if (this->type == variable_type_string)
		{
			if (other.type == variable_type_number)
				throw runtime_error("Cannot compare string to non-string variable");
			else if (other.type == variable_type_string)
				return this->string_value < other.string_value;
			else if (other.type == variable_type_boolean)
				throw runtime_error("Cannot compare string to non-string variable");
		}
		else if (this->type == variable_type_boolean)
		{
			if (other.type == variable_type_number)
				return (DataTypes::number)this->boolean_value < other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot compare string to non-string variable");
			else if (other.type == variable_type_boolean)
				return (DataTypes::number)this->boolean_value < (DataTypes::number)other.boolean_value;
		}
	}
	bool operator<=(const variable_value &other) const
	{
		return !(*this > other);
	}
	bool operator>=(const variable_value &other) const
	{
		return !(*this < other);
	}
	bool operator==(const variable_value &other) const
	{
		if (this->type == variable_type_number)
		{
			if (other.type == variable_type_number)
				return this->number_value == other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot compare string to non-string variable");
			else if (other.type == variable_type_boolean)
				return this->number_value == other.boolean_value;
		}
		else if (this->type == variable_type_string)
		{
			if (other.type == variable_type_number)
				throw runtime_error("Cannot compare string to non-string variable");
			else if (other.type == variable_type_string)
				return this->string_value == other.string_value;
			else if (other.type == variable_type_boolean)
				throw runtime_error("Cannot compare string to non-string variable");
		}
		else if (this->type == variable_type_boolean)
		{
			if (other.type == variable_type_number)
				return (DataTypes::number)this->boolean_value == other.number_value;
			else if (other.type == variable_type_string)
				throw runtime_error("Cannot compare string to non-string variable");
			else if (other.type == variable_type_boolean)
				return (DataTypes::number)this->boolean_value == (DataTypes::number)other.boolean_value;
		}
	}
	bool operator!=(const variable_value &other) const
	{
		return !(*this == other);
	}
	friend istream &operator>>(istream &in, variable_value &v)
	{
		if (v.type == variable_type_number)
			return in >> v.number_value;
		else if (v.type == variable_type_string)
			return in >> v.string_value;
		else if (v.type == variable_type_boolean)
			return in >> v.boolean_value;
	}
	friend ostream &operator<<(ostream &out, const variable_value &v)
	{
		if (v.type == variable_type_number)
			return out << v.number_value;
		else if (v.type == variable_type_string)
			return out << v.string_value;
		else if (v.type == variable_type_boolean)
			return out << v.boolean_value;
	}
};
map<string, variable_value> variables;
class expression
{
private:
	vector<token> tokens;
	int line_number;
	map<operator_type, int> operator_priority = {
		{operator_add, 1},
		{operator_sub, 1},
		{operator_mul, 2},
		{operator_div, 2},
		{operator_mod, 2},
		{operator_equal, 3},
		{operator_not_equal, 3},
		{operator_less, 3},
		{operator_less_equal, 3},
		{operator_greater, 3},
		{operator_greater_equal, 3}};
	struct stack_item
	{
		bool is_left_parentheses;
		variable_value value;
		bool is_operator;
		operator_type op_type;
		stack_item(bool _is_left_parentheses = false)
		{
			is_left_parentheses = _is_left_parentheses;
			is_operator = false;
		}
		stack_item(variable_value _value)
		{
			value = _value;
			is_left_parentheses = false;
			is_operator = false;
		}
		stack_item(operator_type _op_type)
		{
			op_type = _op_type;
			is_left_parentheses = false;
			is_operator = true;
		}
	};

public:
	expression(vector<token> _tokens, int _line_number)
	{
		tokens = _tokens;
		line_number = _line_number;
	}
	variable_value exec()
	{
		stack<stack_item> token_stack;
		for (token item : tokens)
		{
			if (item.type == token_left_parentheses)
				token_stack.push(stack_item(true));
			else if (item.type == token_right_parentheses)
			{
				while (token_stack.top().is_left_parentheses == false)
				{
					stack_item first_token = token_stack.top();
					if (first_token.is_operator)
						CompileError("Invalid expression", line_number);
					token_stack.pop();
					stack_item operator_token = token_stack.top();
					if (!operator_token.is_operator)
						CompileError("Invalid expression", line_number);
					token_stack.pop();
					stack_item second_token = token_stack.top();
					if (second_token.is_operator)
						CompileError("Invalid expression", line_number);
					token_stack.pop();
					try
					{
						switch (operator_token.op_type)
						{
						case operator_add:
							token_stack.push(stack_item(second_token.value + first_token.value));
							break;
						case operator_sub:
							token_stack.push(stack_item(second_token.value - first_token.value));
							break;
						case operator_mul:
							token_stack.push(stack_item(second_token.value * first_token.value));
							break;
						case operator_div:
							token_stack.push(stack_item(second_token.value / first_token.value));
							break;
						case operator_mod:
							token_stack.push(stack_item(second_token.value % first_token.value));
							break;
						case operator_equal:
							token_stack.push(stack_item(second_token.value == first_token.value));
							break;
						case operator_not_equal:
							token_stack.push(stack_item(second_token.value != first_token.value));
							break;
						case operator_less:
							token_stack.push(stack_item(second_token.value < first_token.value));
							break;
						case operator_greater:
							token_stack.push(stack_item(second_token.value > first_token.value));
							break;
						case operator_less_equal:
							token_stack.push(stack_item(second_token.value <= first_token.value));
							break;
						case operator_greater_equal:
							token_stack.push(stack_item(second_token.value >= first_token.value));
						default:
							break;
						}
					}
					catch (runtime_error e)
					{
						CompileError("Invalid expression", line_number);
					}
				}
			}
			else if (item.type == token_operator)
			{
				while (!token_stack.empty() && operator_priority[token_stack.top().op_type] >= operator_priority[item.value.operator_value])
				{
					stack_item first_token = token_stack.top();
					token_stack.pop();
					stack_item operator_token = token_stack.top();
					token_stack.pop();
					stack_item second_token = token_stack.top();
					token_stack.pop();
					try
					{
						switch (operator_token.op_type)
						{
						case operator_add:
							token_stack.push(stack_item(second_token.value + first_token.value));
							break;
						case operator_sub:
							token_stack.push(stack_item(second_token.value - first_token.value));
							break;
						case operator_mul:
							token_stack.push(stack_item(second_token.value * first_token.value));
							break;
						case operator_div:
							token_stack.push(stack_item(second_token.value / first_token.value));
							break;
						case operator_mod:
							token_stack.push(stack_item(second_token.value % first_token.value));
							break;
						case operator_equal:
							token_stack.push(stack_item(second_token.value == first_token.value));
							break;
						case operator_not_equal:
							token_stack.push(stack_item(second_token.value != first_token.value));
							break;
						case operator_less:
							token_stack.push(stack_item(second_token.value < first_token.value));
							break;
						case operator_greater:
							token_stack.push(stack_item(second_token.value > first_token.value));
							break;
						case operator_less_equal:
							token_stack.push(stack_item(second_token.value <= first_token.value));
							break;
						case operator_greater_equal:
							token_stack.push(stack_item(second_token.value >= first_token.value));
						default:
							break;
						}
					}
					catch (runtime_error e)
					{
						CompileError("Invalid expression", line_number);
					}
				}
				token_stack.push(stack_item(item.value.operator_value));
			}
		}
		while (!token_stack.empty())
		{
			stack_item first_token = token_stack.top();
			token_stack.pop();
			stack_item operator_token = token_stack.top();
			token_stack.pop();
			stack_item second_token = token_stack.top();
			token_stack.pop();
			try
			{
				switch (operator_token.op_type)
				{
				case operator_add:
					token_stack.push(stack_item(second_token.value + first_token.value));
					break;
				case operator_sub:
					token_stack.push(stack_item(second_token.value - first_token.value));
					break;
				case operator_mul:
					token_stack.push(stack_item(second_token.value * first_token.value));
					break;
				case operator_div:
					token_stack.push(stack_item(second_token.value / first_token.value));
					break;
				case operator_mod:
					token_stack.push(stack_item(second_token.value % first_token.value));
					break;
				case operator_equal:
					token_stack.push(stack_item(second_token.value == first_token.value));
					break;
				case operator_not_equal:
					token_stack.push(stack_item(second_token.value != first_token.value));
					break;
				case operator_less:
					token_stack.push(stack_item(second_token.value < first_token.value));
					break;
				case operator_greater:
					token_stack.push(stack_item(second_token.value > first_token.value));
					break;
				case operator_less_equal:
					token_stack.push(stack_item(second_token.value <= first_token.value));
					break;
				case operator_greater_equal:
					token_stack.push(stack_item(second_token.value >= first_token.value));
				default:
					break;
				}
			}
			catch (runtime_error e)
			{
				CompileError("Invalid expression", line_number);
			}
		}
	}
};
class statement
{
public:
	/// @brief 执行语句
	virtual void exec();

protected:
	int line_number; // 行号
};
class statement_new : public statement
{
private:
	variable_type type;	  // 变量类型
	string variable_name; // 变量名
public:
	statement_new(int _line_number, variable_type _type, string _variable_name)
	{
		line_number = _line_number;
		type = _type;
		variable_name = _variable_name;
	}
	void exec() override
	{
		if (variables.count(variable_name))
			CompileError("Variable redefinition", line_number);
		else
			variables[variable_name] = variable_type(type);
	}
};
class statement_set : public statement
{
private:
	string variable_name;
	variable_value other_value;
	expression *exp;

public:
	statement_set(int _line_number, string _variable_name, variable_value _other_value)
	{
		line_number = _line_number;
		variable_name = _variable_name;
		other_value = _other_value;
	}
	statement_set(int _line_number, string _variable_name, expression *_exp)
	{
		line_number = _line_number;
		variable_name = _variable_name;
		exp = _exp;
	}
	void exec() override
	{
		if (exp)
		{
			try
			{
				other_value = exp->exec();
			}
			catch (runtime_error &e)
			{
				CompileError("Invalid expression", line_number);
			}
		}
		if (!variables.count(variable_name))
			CompileError("Undefined identifier", line_number);
		else
		{
			try
			{
				variables[variable_name] = other_value;
			}
			catch (runtime_error &e)
			{
				CompileError("Invalid argument", line_number);
			}
		}
	}
};
class statement_input : public statement
{
private:
	string variable_name;

public:
	statement_input(int _line_number, string _variable_name)
	{
		line_number = _line_number;
		variable_name = _variable_name;
	}
	void exec() override
	{
		if (!variables.count(variable_name))
			CompileError("Undefined identifier", line_number);
		else
		{
			try
			{
				cin >> variables[variable_name];
			}
			catch (runtime_error &e)
			{
				CompileError("Invalid argument", line_number);
			}
		}
	}
};
class statement_get_line : public statement
{
private:
	string variable_name;

public:
	statement_get_line(int _line_number, string _variable_name)
	{
		line_number = _line_number;
		variable_name = _variable_name;
	}
	void exec() override
	{
		if (!variables.count(variable_name))
			CompileError("Undefined identifier", line_number);
		else if (variables[variable_name].type != variable_type_string)
			CompileError("Invalid argument", line_number);
		else
			getline(cin, variables[variable_name].string_value);
	}
};
class statement_output : public statement
{
private:
	string variable_name;
	variable_value value;
	expression *exp;

public:
	statement_output(int _line_number, string _variable_name)
	{
		line_number = _line_number;
		variable_name = _variable_name;
	}
	statement_output(int _line_number, variable_value _value)
	{
		line_number = _line_number;
		value = _value;
	}
	statement_output(int _line_number, expression *_exp)
	{
		line_number = _line_number;
		exp = _exp;
	}
	void exec() override
	{
		if (!variable_name.empty())
			if (!variables.count(variable_name))
				CompileError("Undefined identifier", line_number);
			else
				value = variables[variable_name];
		cout << value;
	}
};
class statement_if : public statement
{
private:
	expression *condition;
	vector<statement *> statements_true;
	vector<statement *> statements_false;

public:
	statement_if(int _line_number, expression *_condition)
	{
		line_number = _line_number;
		condition = _condition;
	}
	void add_statement_true(statement *s)
	{
		statements_true.push_back(s);
	}
	void add_statement_false(statement *s)
	{
		statements_false.push_back(s);
	}
	void exec() override
	{
		if (condition->exec().boolean_value)
			for (size_t i = 0; i < statements_true.size(); ++i)
				statements_true[i]->exec();
		else
			for (size_t i = 0; i < statements_false.size(); ++i)
				statements_false[i]->exec();
	}
};
class statement_while : public statement
{
private:
	expression *condition;
	vector<statement *> statements_true;

public:
	statement_while(int _line_number, expression *_condition)
	{
		line_number = _line_number;
		condition = _condition;
	}
	void add_statement(statement *s)
	{
		statements_true.push_back(s);
	}
	void exec() override
	{
		while (condition->exec().boolean_value)
			for (size_t i = 0; i < statements_true.size(); ++i)
				statements_true[i]->exec();
	}
};
vector<statement *> statements_global;
/// @brief 语法分析函数
void parser(vector<statement *> &statements = statements_global, int start_token_number = 0, int start_line_number = 1, bool next_endif = false, bool next_else = false, bool next_endwhile = false)
{
	int line_number = start_line_number;
	for (size_t i = 0; i < tokens.size(); ++i)
	{
		if (tokens[i].type != token_keyword)
			CompileError("Undefined identifier", line_number);
		else
		{
			if (tokens[i].value.keyword_value == keyword_new)
			{
				if (tokens[++i].type != token_data_type)
					CompileError("Invalid argument", line_number);
				else
					statements.push_back(new statement_new(line_number, tokens[i].value.variable_type_value, tokens[++i].value.string_value.to_string()));
			}
			else if (tokens[i].value.keyword_value == keyword_set)
			{
				if (tokens[++i].type != token_variable)
					CompileError("Invalid argument", line_number);
				if (tokens[++i].type != token_keyword)
					CompileError("Invalid argument", line_number);
				if (tokens[i].value.keyword_value != keyword_to)
					CompileError("Invalid argument", line_number);
				if (tokens[++i].type == token_number)
					statements.push_back(new statement_set(line_number, tokens[i].value.string_value.to_string(), tokens[++i].value.number_value));
				else if (tokens[i].type == token_string)
					statements.push_back(new statement_set(line_number, tokens[i].value.string_value.to_string(), tokens[++i].value.string_value));
				else if (tokens[i].type == token_boolean)
					statements.push_back(new statement_set(line_number, tokens[i].value.string_value.to_string(), tokens[++i].value.boolean_value));
				else if (tokens[i].type == token_left_parentheses)
				{
					vector<token> exp_tokens;
					while (true)
					{
						if (tokens[++i].type == token_right_parentheses)
							break;
						else
							exp_tokens.push_back(tokens[i]);
					};
					statements.push_back(new statement_set(line_number, tokens[i].value.string_value.to_string(), new expression(exp_tokens, line_number)));
				}
			}
			else if (tokens[i].value.keyword_value == keyword_input)
			{
				if (tokens[++i].type != token_variable)
					CompileError("Invalid argument", line_number);
				statements.push_back(new statement_input(line_number, tokens[i].value.string_value.to_string()));
			}
			else if (tokens[i].value.keyword_value == keyword_get_line)
			{
				if (tokens[++i].type != token_variable)
					CompileError("Invalid argument", line_number);
				statements.push_back(new statement_get_line(line_number, tokens[i].value.string_value.to_string()));
			}
			else if (tokens[i].value.keyword_value == keyword_output)
			{
				if (tokens[++i].type == token_variable)
					statements.push_back(new statement_output(line_number, tokens[i].value.string_value.to_string()));
				else if (tokens[i].type == token_number)
					statements.push_back(new statement_output(line_number, tokens[i].value.number_value));
				else if (tokens[i].type == token_string)
					statements.push_back(new statement_output(line_number, tokens[i].value.string_value));
				else if (tokens[i].type == token_boolean)
					statements.push_back(new statement_output(line_number, tokens[i].value.boolean_value));
				else if (tokens[i].type == token_left_parentheses)
				{
					vector<token> exp_tokens;
					while (true)
					{
						if (tokens[++i].type == token_right_parentheses)
							break;
						else
							exp_tokens.push_back(tokens[i]);
					}
					statements.push_back(new statement_output(line_number, new expression(exp_tokens, line_number)));
				}
			}
			else if (tokens[i].value.keyword_value == keyword_if)
			{
				vector<token> exp_tokens;
				if (tokens[++i].type == token_variable)
					exp_tokens.push_back(tokens[i]);
				else if (tokens[i].type == token_number)
					exp_tokens.push_back(tokens[i]);
				else if (tokens[i].type == token_string)
					CompileError("Invalid argument", line_number);
				else if (tokens[i].type == token_boolean)
					exp_tokens.push_back(tokens[i]);
				else if (tokens[i].type == token_left_parentheses)
					while (true)
					{
						if (tokens[++i].type == token_right_parentheses)
							break;
						else
							exp_tokens.push_back(tokens[i]);
					}
				statements.push_back(new statement_if(line_number, new expression(exp_tokens, line_number)));
				if (tokens[++i].type != token_keyword)
					CompileError("Invalid argument", line_number);
				if (tokens[i].value.keyword_value != keyword_then)
					CompileError("Invalid argument", line_number);
				vector<statement *> then_statements;
				if (tokens[++i].type != token_endline)
					CompileError("Undefined identifier", line_number);
				else
					++line_number;
				size_t now_i = i;
				bool has_else = false;
				int ll = line_number;
				while (i < tokens.size())
				{
					if (tokens[i].type == token_keyword)
						if (tokens[i].value.keyword_value == keyword_else)
						{
							has_else = true;
							break;
						}
						else if (tokens[i].value.keyword_value == keyword_endif)
						{
							break;
						}
					++i;
				}
				if (has_else)
				{
					parser(then_statements, now_i + 1, i, false, true, false);
				}
			}
		}
	}
}
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
		else if (tokens[i].type == token_data_type)
			cout << "Data type: " << tokens[i].value.variable_type_value << '\n';
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