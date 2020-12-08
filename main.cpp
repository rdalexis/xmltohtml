#include <iostream>
#include <fstream>
#include <unistd.h>
#include "XMLParser.hpp"
#include "XMLToHTML.hpp"

int main(int argc, char *argv[])
{
    set<string> titleinfo;
    vector<map<string, string>> xmldata;
    if(argc == 1)
    {
	cout << "ERROR: xml file should be passed as an argument" << endl;
        return -1;
    }
    
    XMLParser parser(argv[1]);
    XMLToHTML converter;
    
    // Parses XML file
    if(parser.xmlparser(titleinfo, xmldata))
    {
	ofstream outFile("result.html");
	if(!outFile.is_open())
	{
		cout << "Failed to open output.html" << endl;
		return -3;
	}

        // Gets converted to HTML 
    	string htmlinfo = converter.xmltohtmlconverter(titleinfo, xmldata);
    	outFile << htmlinfo;
    	outFile.close();
    }
    else 
        return -2;

    return 0;	
}
