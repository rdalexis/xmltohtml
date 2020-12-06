#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <unistd.h>
#include "./thirdparty/pugixml.hpp"
using namespace pugi;
using namespace std;


/* This function converts parsed xml info to html table format
   Input heading: parsed column headings
   Input xmlinfo: parsed xml data
   Output : html information stored as string */
string xmltohtml(set<string> heading, vector<map<string, string>> xmlinfo)
{
    stringstream ss;
    ss << "<html>";
    ss << "<head>";
    ss << "<meta charset='UTF-8'> <title>XML To HTML Conversion</title>";
    ss << "</head>";
    ss << "<body>";
    ss << "<table border=1>";
    ss << "<thead> <tr>";
    
    for(auto itr = heading.begin(); itr != heading.end(); itr++)
    {
	ss << "<th>" << *itr << "</th>";
    }
    ss << "</tr> </thead>";    
    ss << "<tbody>";
 
    for (auto itr = xmlinfo.begin(); itr != xmlinfo.end(); itr++)
    {
       ss << "<tr>";
       for(auto itr_map = itr->begin(); itr_map != itr->end(); itr_map++)
       {
	   ss << "<td>" << itr_map->second << "</td>";
       }
       ss << "</tr>";
    }

    ss <<"</table></body></html>";
    
    return ss.str();
}

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
	cerr << "ERROR: xml file should be passed as an argument" << endl;
        return 1;
    }
    set<string> parsedtitleinfo;
    vector<map<string, string>> parsedxmlinfo;
    map<string, string> xmlentry;
    
    xml_document doc;
    xml_parse_result result = doc.load_file(argv[1]);
    if (!result)
        return -1;
      
    xml_node catalog = doc.child("CATALOG");

    for (xml_node cd = catalog.first_child(); cd; cd = cd.next_sibling())
    {
        for (xml_node child: cd.children())
        {
              parsedtitleinfo.insert(child.name());
	      xmlentry[child.name()] = child.child_value(); 	
	}

        parsedxmlinfo.push_back(xmlentry);
        xmlentry.clear();
    }  

    ofstream outFile("output.html");
    if(!outFile.is_open())
    {
	cout << "Failed to open output.html" << endl;
        return 1;
    }

    string htmlinfo = xmltohtml(parsedtitleinfo, parsedxmlinfo);
    outFile << htmlinfo;
    outFile.close();

    return 0;	
}
