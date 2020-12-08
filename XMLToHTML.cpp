#include "XMLToHTML.hpp"

XMLToHTML::XMLToHTML()
{}

XMLToHTML::~XMLToHTML()
{}

/* This function converts parsed xml info to html table format
   Input Arguments:
   - heading: parsed column headings
   - xmlinfo: parsed xml data
   Output: 
   - returns html information stored as string */
string XMLToHTML::xmltohtmlconverter(set<string> heading, vector<map<string, string>> xmlinfo)
{
    stringstream ss;
    ss << "<html>";
    ss << "<head>";
    ss << "<meta charset='UTF-8'> <title>XML To HTML Conversion</title>";
    ss << "</head>";
    ss << "<body>";
    ss << "<table border=1>";
    ss << "<thead> <tr>";
    
    // Creates HTML statements for each column heading in the table
    for(auto itr = heading.begin(); itr != heading.end(); itr++)
    {
	ss << "<th>" << *itr << "</th>";
    }
    ss << "</tr> </thead>";    
    ss << "<tbody>";
 
    // Create HTML statements for each row in the table
    for (auto itr = xmlinfo.begin(); itr != xmlinfo.end(); itr++)
    {
       ss << "<tr>";
       for(auto itr_set = heading.begin(); itr_set != heading.end(); itr_set++)
       {
           auto itr_map = itr->find(*itr_set);
           if( itr_map != itr->end())
           {
		ss << "<td>" << itr_map->second << "</td>";		
           }
           else 
           {
                // If a particular cell value is missing, it will be displayed as blank in the table
		ss << "<td>" << "" << "</td>";
           }
       }
       ss << "</tr>";
    }

    ss << "</table> </body> </html>";
    
    return ss.str();
}

