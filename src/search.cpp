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
 	Connect conn;  ///creating object of curl from header Connect.h
	Cgicc cgi;

      // Sends HTTP header
      cout<<HTTPHTMLHeader();

      form_iterator name = cgi.getElement("name");
      if(name != cgi.getElements().end()) {
	data = name->getValue();
      }
        ///Getting request can be change according to the need by changing the arguments of conn.connection("/"+id); , conn.connectionetc..
	conn.connection("/search/"+data);
    }
   catch(exception& e) {   	
   }
}

