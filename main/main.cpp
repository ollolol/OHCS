





/*
    Copyright (C) 2017 CHAW-HUNG, HSIAO

---------------------------------------------------------------------------------------------------------------
    This file is part of Ollolol and Hsiaosvideo Cryptography System.

    Ollolol and Hsiaosvideo Cryptography System is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    Ollolol and Hsiaosvideo Cryptography System is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Ollolol and Hsiaosvideo Cryptography System.  If not, see <http://www.gnu.org/licenses/>.
*/
/* 
  This is the main file of OHCS
  Made by Hsiaosvideo
  2017/07/21
*/
#include "../include/main.hpp"
#include "../include/argv.hpp"
char file = 0;
char R[100];
char *ReadFile = R;

#include <fstream>
#include "../include/OCSS.hpp"
#include <thread>


using namespace std;
void threadtest(const string version){cout<<" Ollolol and Hsiaosvideo Crytography System\n Vesion "<<version<<'\n';}
int main(int argc, char* argv[]){
    string data;
    int _checkAlpha = 1;
    for(int a = 0;a < argc;a++){
        argvCheck(argv[a]);
    }
    if(ReadFile[0] == '\0'){
        _checkAlpha = 0;
    }
    if(_checkAlpha){
        ifstream fin(ReadFile, ios::in);
        if(!fin) { 
            printf("Error: Can not read the file."); 
            return 1; 
        }    
	getline(fin, data);
    }
    const string version = "1.1";
    threadtest(version);
    ios_base::sync_with_stdio(false);
    string new_data = "";
    OCSS x;
    if(_checkAlpha)
        cout<<"data: "<<data<<'\n';
    else{
        cout<<" Data:\n";
        getline(cin,data);
    }
    cout<<" Key:"<<'\n';

    string key;
    getline(cin,key);

    vector<char> keys;
    for (char &x : key) {
        keys.push_back(x);
    }
    string Select;
    cout<<"[E]ncrypt or [D]ecrypt?\n";
    cin>>Select;

    if(Select == "E"){
        x.Encrypt(data, keys);
        printf("\nResult:\n");
        cout<<data<<endl;
    }
    else if(Select == "ED"){
        time_t start, end;
        x.DMode = true;
        start = time(NULL);
        x.Encrypt(data, keys);
        end = time(NULL);
        double diff = difftime(end, start);
        printf("\nResult:\n");

        printf("Time = %f\n", diff);
        cout<<data<<endl;
    }
    else if(Select == "DD"){
        x.Decrypt(data, keys);
        printf("\nResult:\n");
        cout<<data<<endl;
    }
    else{
        x.Decrypt(data, keys);
        printf("\nResult:\n");
        cout<<data<<endl;
    }



    //x.Decrypt(data, keys);
    //a.Encrypt("Hello",);

    return 0;
}
