# xmltohtml
xmltohtml is a utility which converts the given input xml file to html in a table format. This utility makes use of a third party application called pugixml to parse the input xml file. pugixml is an open source XML processing library in C++, which consists of a DOM-like interface with rich traversal/modification capabilities.

## Documentation
The easiest way to use pugixml is to compile the source files of pugixml along with our application. Source files of pugixml are available under the folder thirdparty. PUGIXML_HEADER_ONLY is defined in thirdparty/pugiconfig.hpp to enable header-only mode.

## Usage
To compile this project, you can use the following command:

make

To run this project, you can use the following command:

./xmltohtml cd_catalog.xml

Xml file should be passed as an argument when we run this project. Otherwise, it will throw an error. You can find the output(result.html) in the same directory.

## References
https://github.com/zeux/pugixml
https://www.it2051229.com/cpphtmltable.html
https://pugixml.org/docs/quickstart.html
