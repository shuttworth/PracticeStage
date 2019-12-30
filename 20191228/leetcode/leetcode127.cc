#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;
using std::queue;
 
//Word Ladder
//首先考虑层级关系，如从beginword开始为第一层，和beginword
//相邻（只有一个字母不同，且不包含beginword）的单词为第二层，
//而和所有beginword相邻集合内单词相邻的所有单词集合为第三层。
//以此类推。直到在某一层遇到可以转化为endword的单词，则表示
//该层为最低层。期间可以舍弃被访问过的在字典中的单词。

class Solution 
{
public:
	int ladderLength(const string & start, const string & end, const set<string> & dict)
	{
		if(dict.count(end) == 0) { //如果end不在wordlist中，则转换失败
			return 0;
		}

		set<string> visited;

		int level = 0;
		bool found = false;
		auto nextStates = [&](const string & word) {
			vector<string> result;
			for(size_t idx = 0; idx != word.size(); ++idx) {
				string copy(word);
				for(char ch = 'a'; ch <= 'z'; ++ch) {
					if(ch == copy[idx]) 
						continue;
					std::swap(ch, copy[idx]);//变换
					if((dict.count(copy) > 0 || copy == end) && !visited.count(copy)) {
						result.push_back(copy);		
						visited.insert(copy);
					}
					std::swap(ch, copy[idx]);//恢复
				}
			}
			return result;
		};

		queue<string> current, next; //状态数组
		current.push(start);
		while(!current.empty() && !found) {
			++level;
			while(!current.empty() && !found) {
				string str = current.front();
				current.pop();
				const auto newStates = nextStates(str);	
				for(auto & state : newStates) {
					next.push(state);
					if(state == end) {
						found = true;
						break;
					}
				}
			}
			swap(next, current);
		}
		if(found) 
			return level + 1;
		else 
			return 0;
	}
};
int main(void)
{
#if 0
	string start = "hit";
	string end = "cog";
	set<string> dict{"hot", "dot", "dog", "log", "lot"};
#endif

#if 1
	string start = "hit";
	string end = "cog";
	set<string> dict{"hot", "dot", "dog", "log", "lot", "cog"};
#endif

	Solution s;
	cout << s.ladderLength(start, end, dict) << endl;
	return 0;
}
