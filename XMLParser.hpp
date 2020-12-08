#include <iostream>
#include <map>
#include <vector>
#include <set>
#include "./thirdparty/pugixml.hpp"

using namespace std;
using namespace pugi;
class XMLParser
{
public:
        XMLParser(string filename);
        ~XMLParser();
	bool xmlparser(set<string>& parsedtitleinfo, vector<map<string, string>>& parsedxmlinfo);
private:
        string filename="";
};
