#include <iostream>
#include <fstream>
#include <unistd.h>
#include "XMLParser.hpp"
#include "XMLToHTML.hpp"

// Checks if the given xml file is valid
bool isXMLFileValid(string filename)
{
    ifstream inFile(filename);
    if(!inFile.good())
    { 
        cout << "ERROR: XML file doesn't exist" << endl;
   	return false;
    }    
    else if(filename.find(".xml") == string::npos)
    {
        cout << "ERROR: Invalid file extension" << endl;
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    set<string> titleinfo;
    vector<map<string, string>> xmldata;
    if(argc == 1)
    {
	cout << "ERROR: xml file should be passed as an argument" << endl;
        return -1;
    }
    
    if(!isXMLFileValid(argv[1]))
	return -2;

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
        return -4;

    return 0;	
}
