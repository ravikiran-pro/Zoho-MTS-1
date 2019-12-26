#include <iostream>
#include <string>
#include <string.h>
#include "curl/curl.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
//#include "cgicc/HTMLClasses.h"
//#include <json/json.h>
using namespace std;
using namespace cgicc;

int main()
{
   	
    CURL *curl;
    CURLcode res;
    string data;
    string url1 = "https://superheroapi.com/api/106555427509424/search/";
    try {
      Cgicc cgi;

      // Send HTTP header

      cout<<HTTPHTMLHeader();
      // Set up the HTML document
      //cout << html() << head(title("cgicc example")) << endl;
      //cout << body() << endl;

      // Print out the submitted element
      form_iterator name = cgi.getElement("name");
      if(name != cgi.getElements().end()) {
	data = name->getValue();
      }
      //data=cgi("name");
      //Close the HTML document
      //cout << body() << html();
    }
   catch(exception& e) {
      // handle any errors - omitted for brevity
   }

	struct curl_slist *headers=NULL; // init to NULL is important
	headers = curl_slist_append(headers, "Accept: application/json");
	headers = curl_slist_append(headers, "Content-Type: application/json");
	headers = curl_slist_append(headers, "charsets: utf-8"); 

	curl = curl_easy_init(); 
  
  if(curl) {
    url1=url1+data;
    curl_easy_setopt(curl, CURLOPT_URL, url1.c_str());

    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
    /* Perform the request, res will get the return code */ 
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    res = curl_easy_perform(curl);
    /* Check for errors */ 	
    if(res != CURLE_OK)
    	 curl_easy_strerror(res);
    /*always cleanup */ 
    curl_easy_cleanup(curl); 
  }
}
