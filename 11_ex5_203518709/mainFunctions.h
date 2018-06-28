//
// Created by Shira on 27/06/18.
//

#ifndef SHIRA_TERMINAL_MAINFUNCTIONS_H
#define SHIRA_TERMINAL_MAINFUNCTIONS_H

#include <iostream>
#include "Terminal.h"

using namespace std;

enum queries{ //cause switch case does not work with strings
    read,
    write,
    touch,
    cp,
    rm,
    move,
    cat,
    head,
    tail,
    ls,
    exit,
    invalidQuery
};


void getUserQueries(Terminal *pTerminal);

struct invalidWriteQueryException : public exception { //exception for write
    virtual const char * what() const throw(){
        return "ERROR: USAGE write FILENAME POSITION CHARACTER";
    }
};

struct invalidReadQueryException : public exception {//exception for read
    virtual const char * what() const throw(){
        return "ERROR: USAGE read FILENAME POSITION";
    }
};

struct invalidCopyQueryException : public exception {//exception for copy
    virtual const char * what() const throw(){
        return "ERROR: USAGE copy SOURCE_FILENAME TARGET_FILENAME";
    }
};

struct invalidRemoveQueryException : public exception {//exception for remove
    virtual const char * what() const throw(){
        return "ERROR: USAGE remove FILENAME";
    }
};

struct invalidMoveQueryException : public exception {//exception for move
    virtual const char * what() const throw(){
        return "ERROR: USAGE move SOURCE_FILENAME TARGET_FILENAME";
    }
};

struct invalidCatQueryException : public exception {//exception for cat
    virtual const char * what() const throw(){
        return "ERROR: USAGE cat FILENAME";
    }
};
#endif //SHIRA_TERMINAL_MAINFUNCTIONS_H
