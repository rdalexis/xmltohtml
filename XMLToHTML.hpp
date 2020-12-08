#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>

using namespace std;
class XMLToHTML
{
public:
        XMLToHTML();
        ~XMLToHTML();
	string xmltohtmlconverter(set<string> heading, vector<map<string, string>> xmlinfo);    
};
