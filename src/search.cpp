#include <iostream>
#include <string>
#include <string.h>
#include "Connect.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
using namespace std;
using namespace cgicc;
int main()
{
    string data;
    try {
 	Connect conn;
	Cgicc cgi;

      // Send HTTP header
      cout<<HTTPHTMLHeader();

      form_iterator name = cgi.getElement("name");
      if(name != cgi.getElements().end()) {
	data = name->getValue();
      }
	conn.connection("Batman");
    }
   catch(exception& e) {   	
   }
}

