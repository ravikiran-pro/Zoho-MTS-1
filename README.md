# Zoho-mts-1<br>
<a href="https://github.com/ravikiran-pro/Zoho-mts-1">A web app based Assessment with c++ as backend</a>

## Project
- Fetching  SuperHero details form <a href="https://www.superheroapi.com/">superheroapi</a> using curl c++ 
- The frontend communicate with the backend build through common gateway interface using ajax js (client side request) and cgicc c++ on server side.
- The data's are fetched by the backend build using curl c++ and returned through cgi.
- The project was tested in a ubuntu 18.04 fresh bootable drive.

## Directories:Zoho-mts-1

             |--Header Files--
             |                |
             |                |-- include
             |                |-- lib
             |                |-- bin
             |                |-- share
             |                |-- docs
             |
             |--Ninja file----
             |                |
             |                |--ninja
             |                |--build.ninja
             |
             |--source code---
             |                |--Connect.h
             |                |--search.cpp
             |                |--Frontend ---
             |                               |--index.html
             |                               |--index.css
             |                               |--index.js
             |
             |--others--------|
                              |--performance.md (performance timing of webpage ajax,c++ and at final)
                              |--follow-ups.txt (Day2day Activities after starting the Assignmen)

## Build Instruction and installation
</br><i>Note: All commands are Executed from Zoho-mts-1 folder </i>
##### The ninja build will unpack the required resource and will compile the source code search.cpp.The executable build will be created in src/connection 
```
$ sudo ./ninja
```
##### libcurl is needed for the curl to connect to the Rest api.
```
$ sudo apt install libcurl4
```
##### I have use apache web server for implementing the web app.To intiate the apache and to allow c++ compile on the server side cgi should be enabled.
```
$ sudo apt install apache2
$ sudo a2enmod cgi
$ sudo service apache2 restart
```
##### The frontend and backendsource code should be added to the /var/www/html &&  /usr/lib/cgi-bin respectively
```
$ sudo apt update
$ cp src/connection /usr/lib/cgi-bin
$ cp src/frontend /var/www/html
```
##### Open your webbrowser
```
http://localhost/frontend/index.html
```
##### During search the ajax will work as front-end and will connect to c++ executable in /usr/lib/cgi-bin/connection through http://localhost/cgi-bin/connection?name="" and the c++ connect to SuperHeroApi through curl.
##### The cgi will stand as the bridge between front and the backend and communicates information via http.

## output
<a href="https://ibb.co/yqZNtb8"><img src="https://i.ibb.co/hV4gbtK/Screenshot-from-2019-12-27-15-03-07.png" alt="Screenshot-from-2019-12-27-15-03-07" border="0"></a>
<a href="https://ibb.co/MS01fXp"><img src="https://i.ibb.co/r0rp3WM/Screenshot-from-2019-12-27-15-06-04.png" alt="Screenshot-from-2019-12-27-15-06-04" border="0"></a>
<a href="https://ibb.co/tsbLNG9"><img src="https://i.ibb.co/3N0R83n/Screenshot-from-2019-12-27-15-06-09.png" alt="Screenshot-from-2019-12-27-15-06-09" border="0"></a>



                                            
      
