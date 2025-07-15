#include <bits/stdc++.h>
using namespace std;
int n;
map<string, string> mp;
string hong_replace(string str, vector<string> replaced)
{
	vector<string> tokens;
	vector<string> not_tokens;
	string token_t, not_token_t;
	for (char ch : str)
		if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			token_t += ch;
			if (not_token_t.empty())
				continue;
			not_tokens.push_back(not_token_t);
			not_token_t = "";
		}
		else
		{
			not_token_t += ch;
			if (token_t.empty())
				continue;
			tokens.push_back(token_t);
			not_tokens.push_back("");
			token_t = "";
		}
	{
		if (!not_token_t.empty())
		{
			not_tokens.push_back(not_token_t);
			not_token_t = "";
		}
	}
	{
		if (!token_t.empty())
		{
			tokens.push_back(token_t);
			not_tokens.push_back("");
			token_t = "";
		}
	}
	for (string &token : tokens)
		if (find(replaced.begin(), replaced.end(), token) == replaced.end())
		{
			std::map<std::string, std::string>::iterator it = mp.find(token);
			if (it != mp.end())
			{
				replaced.push_back(token);
				token = hong_replace(it->second, replaced);
				replaced.pop_back();
			}
		}
	size_t tokens_pos = 0;
	string result;
	for (const string &not_token : not_tokens)
		if (not_token.empty())
			result += tokens[tokens_pos++];
		else
			result += not_token;
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin.get();
	for (int i = 1; i <= n; ++i)
	{
		string s;
		getline(cin, s);
		if (s.substr(0, 7) == "#define")
		{
			size_t pos_t = s.find(' ');
			size_t pos = s.find(' ', pos_t + 1);
			mp[s.substr(pos_t + 1, pos - pos_t - 1)] = s.substr(pos + 1);
			cout << '\n';
		}
		else if (s.substr(0, 6) == "#undef")
		{
			size_t pos_t = s.find(' ');
			mp.erase(s.substr(pos_t + 1));
			cout << '\n';
		}
		else
			cout << hong_replace(s, vector<string>()) << '\n';
	}
}