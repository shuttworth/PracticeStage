// "" 加载头文件，搜索路径从当前路径下开始查找
// <> 加载头文件，搜索路径从系统路径下开始查找
#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <regex>

//#include <boost/regex.hpp>
using std::cout;
using std::endl;
using std::string;
using namespace tinyxml2;
 
int main(void)
{
	XMLDocument doc;
	doc.LoadFile("coolshell.xml");
	cout << doc.ErrorID() << endl;

	XMLElement * root = doc.FirstChildElement("rss");
	XMLElement * itemNode = root->FirstChildElement("channel")->FirstChildElement("item");
	int cnt = 0;
	do 
	{
		if(itemNode) {
			XMLElement * tileNode = itemNode->FirstChildElement("title");
			XMLElement * linkNode = itemNode->FirstChildElement("link");
			XMLElement * descriptionNode = itemNode->FirstChildElement("description");
			XMLElement * contentNode = itemNode->FirstChildElement("content:encoded");
			string title;
			string link;
			string description;
			string content;
			
			if(tileNode) title = tileNode->GetText();
			if(linkNode) link = linkNode->GetText();
			if(descriptionNode) description = descriptionNode->GetText(); 
			if(contentNode) 
				content = contentNode->GetText();
			else
				content = description;
			
			cout << ">>> title：" << title << endl << endl
				 << ">>> link:" << link << endl << endl;

			//boost::regex re("<(S*?)[^>]*>.*?|<.*? />");
			//boost::regex re("<.*?>");
			
			std::regex re("<.*?>");

			cout << ">>> content: \n\n" << content << endl << endl;
		}
		++cnt;
		cout << ">>> cnt = " << cnt << endl;
	} while((itemNode = itemNode->NextSiblingElement("item")));

	return 0;
}
