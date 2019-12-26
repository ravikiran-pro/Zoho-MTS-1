#include <iostream>
#include <string.h>
#include <string>
#include "curl/curl.h"
using namespace std;
class Connect
{
public:
void connection(string data)
{
    string url = "https://superheroapi.com/api/106555427509424";
    CURL *curl;
    CURLcode res;
        struct curl_slist *headers=NULL; // init to NULL is important
        //headers = curl_slist_append(headers, "Accept: application/json");
        //headers = curl_slist_append(headers, "Content-Type: application/json");
        //headers = curl_slist_append(headers, "charsets: utf-8"); 

        curl = curl_easy_init();

  if(curl) {
    url=url+data;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    /* example.com is redirected, so we tell libcurl to follow redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Perform the request, res will get the return code */
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    res = curl_easy_perform(curl);
    char *ct;	
    //working successfuly receiving type
    res=curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE,&ct);
    //cout<<ct; 
    /* Check for errors */
    if(res != CURLE_OK)
         curl_easy_strerror(res);

    /*always cleanup */
    curl_easy_cleanup(curl);

  }
}
};
