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
    
    XMLParser parser = XMLParser(argv[1]);
    XMLToHTML converter = XMLToHTML();
    
    if(parser.xmlparser(titleinfo, xmldata))
    {
	ofstream outFile("output.html");
	if(!outFile.is_open())
	{
		cout << "Failed to open output.html" << endl;
		return -3;
	}
    	string htmlinfo = converter.xmltohtmlconverter(titleinfo, xmldata);
    	outFile << htmlinfo;
    	outFile.close();
    }
    else 
        return -2;

    return 0;	
}
