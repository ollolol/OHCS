#ifndef OCSS_H
#define OCSS_H
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <algorithm>

#include "../bigint/BigIntegerLibrary.hh"
#include "omp.h"
using namespace std;
class OCSS
{
    public:
        OCSS();
        virtual ~OCSS();
        void Encrypt(string& Data,vector<char>& Key);
        void Decrypt(string& Data,vector<char>& Key);
        void ToBase(string& Data,int Original_Base,int New_Base);
        bool check();
        bool DMode;
    protected:

    private:
        string Char_List;
};

#endif // OCSS_H
