//
// Created by Shira on 27/06/18.
//

#ifndef SHIRA_TERMINAL_FILE_H
#define SHIRA_TERMINAL_FILE_H
#include <string>
#include <fstream>

using namespace std;

class File {
public:
    explicit File(string name);

    const string &getName() const;

    void operator[](pair<int,char> p);
    const char operator[](int pos);
    void setName(const string &name);
    void touch();
    void getContent();
    File *clone();
    void getfirstLines(int n);
    void getlastLines(int n);
    int getNumberOfLines();
    void takeCursorToNextLine();

    struct errorOpeningFileException : public exception {
        virtual const char * what() const throw(){
            return "ERROR: error opening file";
        }
    };
private:
    ifstream inputStream;
    ofstream outputStream;
    string name;
};


#endif //SHIRA_TERMINAL_FILE_H
