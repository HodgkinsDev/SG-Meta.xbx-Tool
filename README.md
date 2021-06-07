# SG-Meta.xbx-Tool
A small tool to create and read SaveMeta.xbx and TitleMeta.xbx from the Original Xbox
## What is a TitleMeta.xbx / SaveMeta.xbx File?
- TitleMeta.xbx is a file that indicates the title of a save file that shows up in the Memory Browser.
- SaveMeta.xbx is a file that indicates the title of an individual save block within a save file. 
## Usage
```
Usage ./SG-Meta.xbx-Tool -MODE -FILE_TYPE INPUT

Modes:
-------------------------
-c/-C ----- Create
-r/-R ----- Read
-help ----- Help
-------------------------
File Types:
-s/-S ----- SaveMeta.xbx
-t/-T ----- TitleMeta.xbx
-------------------------
Input:
If you are using -c/-C, then the input is the data you want the program to 
use when creating a SaveMeta.xbx/Title.xbx file.

If you are using -r/-R, then the location of the SaveMeta.xbx/Title.xbx file

If you don't add any arguments, you'll be able to use the CLI menu and create/read
files without using command arguments.
```
## Disclaimer
This was written on Linux Mint, however the code itself is compatible with Windows. You'll just have to change the clearscreen in line 20 of the main.cpp file to the equivalent windows system command for clearing the console screen and compile it yourself.

```
Line 20 main.cpp:system("clear)"; ------> system("cls");
```
