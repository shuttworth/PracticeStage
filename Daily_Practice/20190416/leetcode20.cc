#include <iostream>
#include <string>
#include <stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;

//Valid Parentheses
class Solution
{
public:
	bool isValid(const string s) 
	{
		if(s.empty()) //字符串是否为空
			return true;
		if(s.size() % 2) //字符串的长度是否为偶数
			return false;

		stack<char> st;
		auto it = s.begin();
		for(; it != s.end(); ++it) {
			if(st.empty())
			{
				st.push(*it);
				continue;
			} //执行完这一步以后，第一个it的值已经被push进去了，指针已经移到了第二个
			char ch = st.top();
			switch(ch) {
			case '(':
				if(*it == ')')
					st.pop(); //对于st的栈来说，以（）为例，（是在st里面的，外面的指针是在）处的，pop（，break以后进行下一个for循环
				else
					st.push(*it);
				break;
			case '[':
				if(*it == ']')
					st.pop();
				else 
					st.push(*it);
				break;
			case '{':
				if(*it == '}')
					st.pop();
				else
					st.push(*it);
				break;
			default:
				return false;
			}
		}
		if(st.empty())
			return true;
		else 
			return false;
	}
};
 
int main(void)
{
	Solution s;
	cout << "() " << s.isValid("()") << endl;
	cout << "()[]{} " << s.isValid("()[]{}") << endl;
	cout << "(] " << s.isValid("(]") << endl;
	cout << "([)] " << s.isValid("([)]") << endl;
	cout << "{[]} " << s.isValid("{[]}") << endl;

	return 0;
}
