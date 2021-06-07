#ifndef METATOOLS_H
#define METATOOLS_H
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <fstream>
#include <ios>
#include <unistd.h>
#include <streambuf>
#include <regex>

//Created By Jacob Hodgkins

using  namespace std;

string String2Hex(string str);
string Data2Meta(string data,int mode);
string contents_of(string files);
string File2Hex(string file);
void CreateMetaFile(string data, int mode);
string RemoveHeaderFooter(string data,int mode);
string RemoveDoubleZero(string data);
string SpaceEvery2(string data);
string Meta2Data(string data, int mode);
string lastN(string input,int n);

#endif // METATOOLS_H
