#include "MetaTools.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <fstream>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <unistd.h>
#include <streambuf>
#include <regex>

//Created By Jacob Hodgkins

using  namespace std;

//Get Contents of File
string contents_of(string files)
{
    std::ifstream file(files) ;
    string contents = { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>{}};
    contents.erase(std::remove(contents.begin(), contents.end(), '\n'),contents.end());
    return contents;
}

string String2Hex(string str){
    string s2;
    stringstream ss;
    for (const auto &item : str) {ss << hex << int(item);}
    s2 = ss.str();
    transform(s2.begin(), s2.end(),s2.begin(), ::toupper);
    return s2;
}

string Data2Meta(string data,int mode){ //Converts Data to .xbx Format
    string data_tmp;
    int a = 0;
    while(true){ //Adds 00 between each pair of 2 characters
        string subdata = data.substr(a,2);
        data_tmp = data_tmp + subdata + "00";
        a = a + 2;
        if(a == data.length()){break;}
    }
    if(mode == 1){data_tmp = "fffe4E0061006d0065003d00" + data_tmp + "0d000a00";} //SaveMeta.xbx
    if(mode == 2){data_tmp = "fffe5400690074006c0065004e0061006d0065003d00" + data_tmp + "0d000a00";} //TitleMeta.xbx
    transform(data_tmp.begin(), data_tmp.end(),data_tmp.begin(), ::toupper);
    return data_tmp;
}

void CreateMetaFile(string data, int mode){
    string data_tmp;
    if(mode == 1){data_tmp = Data2Meta(String2Hex(data),1);}
    if(mode == 2){data_tmp = Data2Meta(String2Hex(data),2);}
    //string data_tmp = Data2Meta(String2Hex(data),1);
    basic_string<uint8_t> bytes;
    for (size_t i = 0; i < data_tmp.length(); i += 2){
        uint16_t byte;
        string nextbyte = data_tmp.substr(i, 2);
        istringstream(nextbyte) >> hex >> byte;
        bytes.push_back(static_cast<uint8_t>(byte));
    }
    string result(begin(bytes), end(bytes));
    if(mode == 1){
        ofstream output_file("SaveMeta.xbx", std::ios::binary | std::ios::out);
        output_file << result;
        output_file.close();
    }
        if(mode == 2){
        ofstream output_file("TitleMeta.xbx", std::ios::binary | std::ios::out);
        output_file << result;
        output_file.close();
    }
}

string File2Hex(string file){
    ofstream cfile;
    cfile.open("hexdump.txt");
    char* Byte = new char;
    int   byteCount = 0;
    ifstream binFile(file, ios::in | ios::binary);
    binFile.read(Byte, 1);
    while (binFile) {
      byteCount++;
      cfile << hex << setw(2) << (short(*Byte) & 0x00FF);
      binFile.read(Byte, 1);
    }
    binFile.close();
    cfile.close();
    string Result = contents_of("hexdump.txt");
    replace(Result.begin(), Result.end(), ' ', '0');
    transform(Result.begin(), Result.end(),Result.begin(), ::toupper);
    remove("hexdump.txt");
    return Result;
}

string RemoveHeaderFooter(string data, int mode){
    string data_tmp = data;
    if(mode == 1){data_tmp = data_tmp.substr(24,data_tmp.length());}
    if(mode == 2){data_tmp = data_tmp.substr(44,data_tmp.length());}
    data_tmp = data_tmp.substr(0,data_tmp.length() - 8);
    return data_tmp;
}

string RemoveDoubleZero(string data){
    int a = 0;
    string result;
    while(true){
        string tmp = data.substr(a,2);
        result = result + tmp;
        a = a + 4;
        if(a > data.length()){break;}
    }
    return result;
}

string SpaceEvery2(string data){
    string result;
    int a = 0;
    while(true){
        string tmp = data.substr(a,2);
        result = result + tmp + " ";
        a = a + 2;
        if(a > data.length()){break;}
    }
    return result;
}

string Meta2Data(string data, int mode){
    string data_tmp;
    if(mode == 1){data_tmp = RemoveHeaderFooter(data,1);}
    if(mode == 2){data_tmp = RemoveHeaderFooter(data,2);}
    string tmpstr = RemoveDoubleZero(data_tmp);
    string result;
    result.reserve(tmpstr.size() / 2);
    for (int i = 0; i < tmpstr.size(); i += 2)
    {
        istringstream iss(tmpstr.substr(i, 2));
        int temp;
        iss >> hex >> temp;
        result += static_cast<char>(temp);
    }
    return result;
}

string lastN(string input,int n){return input.substr(input.size() - n);}

