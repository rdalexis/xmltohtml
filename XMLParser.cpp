#include "XMLParser.hpp"

XMLParser::XMLParser(string filename)
{
	this->filename = filename;
}

XMLParser::~XMLParser()
{}

bool XMLParser::xmlparser(set<string>& parsedtitleinfo, vector<map<string, string>>& parsedxmlinfo)
{
    xml_document doc;
    map<string, string> xmlentry;

    if(!this->filename.empty())
    {
    	xml_parse_result result = doc.load_file(this->filename.c_str());
    	if (!result)
	{
		cout << "XML [" << this->filename << "] parsed with errors" << endl;
		cout << "Error description:" << result.description() << endl;
		return false;
        }
    }
    else
    {
       cout << "Invalid value for filename " << this->filename << endl;
       return false; 
    }
      
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

    return true;
}
