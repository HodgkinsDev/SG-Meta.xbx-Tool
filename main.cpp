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
#include <stdlib.h>
#include <regex>
#include "MetaTools.h"

//Created By Jacob Hodgkins

using  namespace std;

void ttl(){
    system("clear");
    cout << "Savegame Meta.xbx Tool 0.1" << endl;
    cout << "--------------------------" << endl;
    cout << "Created by Jacob Hodgkins" << endl;
    cout << "--------------------------" << endl;
}

void anykey(){
    string anykeyy;
    cout << endl << "Enter Any Key to Return..." << endl;
    cin >> anykeyy;
}

inline bool FileExist(const std::string & name)
{
	ifstream f(name.c_str());
	return f.good();
}

//program (CR) (ST) FILE

int main(int argc, char *argv[]){
    string choice;
    string name;
    string file_location;
    if(argc > 1){
        string arg1 = argv[1];
        if(argc == 2){
            if(arg1 == "-help"){
                cout << endl << "Usage ./SG-Meta.xbx-Tool -MODE -FILE_TYPE INPUT" << endl;
                cout << endl << "Created by Jacob Hodgkins" << endl;
                cout << endl << "Modes:" << endl;
                cout << "-------------------------" << endl;
                cout << "-c/-C ----- Create" << endl;
                cout << "-r/-R ----- Read" << endl;
                cout << "-help ----- Help" << endl;
                cout << "-------------------------" << endl;
                cout << "File Types:" << endl;
                cout << "-s/-S ----- SaveMeta.xbx" << endl;
                cout << "-t/-T ----- TitleMeta.xbx" << endl;
                cout << "-------------------------" << endl;
                cout << "Input:" << endl;
                cout << "If you are using -c/-C, then the input is the data you want the program to use when creating a SaveMeta.xbx/Title.xbx file." << endl;
                cout << "If you are using -r/-R, then the location of the SaveMeta.xbx/Title.xbx file" << endl << endl;
                cout << "If you don't add any arguments, you'll be able to use the CLI menu and create/read files without using command arguments." << endl << endl;
            }
            else{cout << "Invalid Usage" << endl;}
        }
        else if(argc == 4){
            //string arg1 = argv[1];
            string arg2 = argv[2];
            string arg3 = argv[3];
            if(arg1 == "-c" or arg1 == "-C" or arg1 == "-r" or arg1 == "-R"){
                if(arg2 == "-s" or arg2 == "-S" or arg2 == "-t" or arg2 == "-T"){
                    if(arg1 == "-c" and arg2 == "-s" or arg1 == "-C" and arg2 == "-s" or arg1 == "-c" and arg2 == "-S" or arg1 == "-C" and arg2 == "-S"){
                        cout << endl << "Save Block Name:" << arg3 << endl;
                        cout << endl << "Hex:";
                        cout << endl << "---------------------" << endl << SpaceEvery2(String2Hex(arg3)) << endl << endl;
                        cout << ".xbx Format(Raw Data):";
                        cout << endl << "---------------------" << endl << SpaceEvery2(Data2Meta(String2Hex(arg3),1)) << endl << endl;
                        cout << "Creating SaveMeta.xbx..." << endl << endl;
                        CreateMetaFile(arg3,1);
                        cout << "SaveMeta.xbx Created!" << endl << endl;
                    }
                    else if(arg1 == "-c" and arg2 == "-t" or arg1 == "-C" and arg2 == "-t" or arg1 == "-c" and arg2 == "-T" or arg1 == "-C" and arg2 == "-T"){
                        cout << endl << "Save Game Name:" << arg3 << endl;
                        cout << endl << "Hex:";
                        cout << endl << "---------------------" << endl << SpaceEvery2(String2Hex(arg3)) << endl << endl;
                        cout << ".xbx Format(Raw Data):";
                        cout << endl << "---------------------" << endl << SpaceEvery2(Data2Meta(String2Hex(arg3),2)) << endl << endl;
                        cout << "Creating TitleMeta.xbx..." << endl << endl;
                        CreateMetaFile(arg3,2);
                        cout << "TitleMeta.xbx Created!" << endl << endl;
                    }
                    else if(arg1 == "-r" and arg2 == "-s" or arg1 == "-R" and arg2 == "-s" or arg1 == "-r" and arg2 == "-S" or arg1 == "-R" and arg2 == "-S"){
                        if(FileExist(arg3) and arg3 == "SaveMeta.xbx" or FileExist(arg3) and lastN(arg3,13) == "/SaveMeta.xbx" and arg3.length() > 12){
                            cout << endl << ".xbx Format(Raw Data)";
                            cout << endl << "---------------------" << endl << SpaceEvery2(File2Hex(arg3)) << endl << endl;
                            cout << "Hex:";
                            cout << endl << "---------------------" << endl << SpaceEvery2(RemoveDoubleZero(RemoveHeaderFooter(File2Hex(arg3),1))) << endl << endl;
                            cout << "File Content:";
                            cout << endl << "---------------------" << endl << Meta2Data(File2Hex(arg3),1) << endl << endl;
                        }
                        else{cout << "Error:Invalid File or File Doesn't Exist" << endl;}
                    }
                    else if(arg1 == "-r" and arg2 == "-t" or arg1 == "-R" and arg2 == "-t" or arg1 == "-r" and arg2 == "-T" or arg1 == "-R" and arg2 == "-T"){
                        if(FileExist(arg3) and arg3 == "TitleMeta.xbx" or FileExist(arg3) and lastN(arg3,14) == "/TitleMeta.xbx" and arg3.length() > 13){
                            cout << endl << ".xbx Format(Raw Data)";
                            cout << endl << "---------------------" << endl << SpaceEvery2(File2Hex(arg3)) << endl << endl;
                            cout << "Hex:";
                            cout << endl << "---------------------" << endl << SpaceEvery2(RemoveDoubleZero(RemoveHeaderFooter(File2Hex(arg3),2))) << endl << endl;
                            cout << "File Content:";
                            cout << endl << "---------------------" << endl << Meta2Data(File2Hex(arg3),2) << endl << endl;
                        }
                        else{cout << "Error:Invalid File or File Doesn't Exist" << endl;}
                    }
                    else{cout << "Invalid Usage" << endl;}
                }
                else{cout << "Invalid Usage" << endl;}
            }
            else{cout << "Invalid Usage" << endl;}
        }
        else{cout << "Invalid Usage" << endl;}
    }
    else{cout << "Invalid Usage" << endl;}
    if(argc == 1){
        while(true){
            ttl();
            cout << "This will Create/Read a SaveMeta.xbx or a TitleMeta.xbx file for you!" << endl << endl;
            cout << "[1]Create SaveMeta.xbx File" << endl;
            cout << "[2]Create TitleMeta.xbx File" << endl << endl;
            cout << "[3]Read SaveMeta.xbx File" << endl;
            cout << "[4]Read TitleMeta.xbx File" << endl << endl;
            cout << "[5]Exit" << endl;
            cout << endl << "Choice:";
            cin >> choice;
            if(choice == "5"){return 0;}
            ttl();
            if(choice == "1"){
                cout << "SaveMeta.xbx File Creator" << endl << endl;
                cout << "Save Block Name:";
                cin.ignore();
                getline(cin,name);
                cout << endl << "Hex:";
                cout << endl << "---------------------" << endl << SpaceEvery2(String2Hex(name)) << endl << endl;
                cout << ".xbx Format(Raw Data):";
                cout << endl << "---------------------" << endl << SpaceEvery2(Data2Meta(String2Hex(name),1)) << endl << endl;
                cout << "Creating SaveMeta.xbx..." << endl << endl;
                CreateMetaFile(name,1);
                cout << "SaveMeta.xbx Created!" << endl;
                anykey();

            }
            if(choice == "2"){
                cout << "TitleMeta.xbx File Creator" << endl << endl;
                cout << "Save Game Name:";
                cin.ignore();
                getline(cin,name);
                cout << endl << "Hex:";
                cout << endl << "---------------------" << endl << SpaceEvery2(String2Hex(name)) << endl << endl;
                cout << ".xbx Format(Raw Data):";
                cout << endl << "---------------------" << endl << SpaceEvery2(Data2Meta(String2Hex(name),2)) << endl << endl;
                cout << "Creating TitleMeta.xbx..." << endl << endl;
                CreateMetaFile(name,2);
                cout << "TitleMeta.xbx Created!" << endl;
                anykey();

            }
            if(choice == "3"){
                cout << "SaveMeta.xbx File Reader" << endl << endl;
                cout << "Location of SaveMeta.xbx:";
                cin.ignore();
                getline(cin,file_location);
                if(FileExist(file_location) && file_location.length() == 12 && lastN(file_location,12) == "SaveMeta.xbx" || FileExist(file_location) && file_location.length() > 12 && lastN(file_location,13) == "/SaveMeta.xbx"){
                    cout << endl << ".xbx Format(Raw Data)";
                    cout << endl << "---------------------" << endl << SpaceEvery2(File2Hex(file_location)) << endl << endl;
                    cout << "Hex:";
                    cout << endl << "---------------------" << endl << SpaceEvery2(RemoveDoubleZero(RemoveHeaderFooter(File2Hex(file_location),1))) << endl << endl;
                    cout << "File Content:";
                    cout << endl << "---------------------" << endl << Meta2Data(File2Hex(file_location),1) << endl;
                }
                else{cout << endl << "Invalid File!" << endl;}
                anykey();
            }
            if(choice == "4"){
                cout << "TitleMeta.xbx File Reader" << endl << endl;
                cout << "Location of TitleMeta.xbx:";
                cin.ignore();
                getline(cin,file_location);
                if(FileExist(file_location) && file_location.length() == 13 && lastN(file_location,13) == "TitleMeta.xbx" || FileExist(file_location) && file_location.length() > 13 && lastN(file_location,14) == "/TitleMeta.xbx"){
                    cout << endl << ".xbx Format(Raw Data)";
                    cout << endl << "---------------------" << endl << SpaceEvery2(File2Hex(file_location)) << endl << endl;
                    cout << "Hex:";
                    cout << endl << "---------------------" << endl << SpaceEvery2(RemoveDoubleZero(RemoveHeaderFooter(File2Hex(file_location),2))) << endl << endl;
                    cout << "File Content:";
                    cout << endl << "---------------------" << endl << Meta2Data(File2Hex(file_location),2) << endl;
                }
                else{cout << endl << "Invalid File!" << endl;}
                anykey();

            }
        }
    }
}
