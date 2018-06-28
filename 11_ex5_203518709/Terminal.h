//
// Created by Shira on 27/06/18.
//

#ifndef SHIRA_TERMINAL_TERMIANL_H
#define SHIRA_TERMINAL_TERMIANL_H
#include <vector>
#include <string>
#include "File.h"
#include <iostream>
using namespace std;

class Terminal {
public: //cpp file contains explanation
    void touch(const string & fileName);
    void ls();

    void copy(const string &source, const string &destination);
    void move(const string &source, const string &destination);
    File* getFile(const string & fileName);
    void remove(const string & fileName);
    void cat(const string& text);
    void write(const string& fileName, const int pos, const char c);
    void read(const string& fileName, const int pos);
    void head(const string& fileName, const int chars);
    void tail(const string& fileName, const int chars);


private:
    vector<File*> files; 		//vector to work with file list
};

struct noSuchFileException : public exception {
        virtual const char * what() const throw(){
            return "ERROR: no such file";
        }
    };
#endif //SHIRA_TERMINAL_TERMIANL_H
