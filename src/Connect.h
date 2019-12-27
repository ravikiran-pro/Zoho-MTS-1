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
        struct curl_slist *headers=NULL;
        curl = curl_easy_init();

  if(curl) {
    url=url+data;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    res = curl_easy_perform(curl);
    char *ct;	
    res=curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE,&ct);
    //cout<<ct; Successfully printing return type as json
    if(res != CURLE_OK)
         curl_easy_strerror(res);

    curl_easy_cleanup(curl);

  }
}
};
