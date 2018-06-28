//
// Created by Shira on 27/06/18.
//

#include <iostream>
#include "File.h"

const string &File::getName() const { //gets the name of the file
	return name;
}

void File::setName(const string &name) { //sets the name of the file
	File::name = name;
}

void File::touch() {

}

File::File(string name) { //constructor
	this->name = name;

	outputStream.open(name.c_str(),ios_base::out);
	inputStream.open(name.c_str(),ios_base::in);

	if (!inputStream.is_open()){
		throw errorOpeningFileException();
	}
	if (!outputStream.is_open()){
		throw errorOpeningFileException();
	}
}

File *File::clone() { //cloning file
	File *copy = new File(name);
	char c;
	int pos=0;

	inputStream.seekg(0); //sets index on place 0

	while (!inputStream.eof()){ //while not end of file
		inputStream >> c;
		copy->operator[](pair<int,char>(c,++pos));
	}

	return copy;
}

void File::operator[](pair<int, char> p) {
	outputStream.seekp(p.first); 	//sets index on place 0
	outputStream << p.second;		//second is a copy of the second object
	outputStream.flush();

	outputStream.seekp(0);	//sets index back to place 0
}

const char File::operator[](int pos){ //writes to output
	char c;

	inputStream.seekg(pos); 	//sets index on wanted place
	inputStream.get(c);			//writes said character

	return c;
}

void File::getContent(){ //get the content of file
	inputStream.seekg(0); 		//sets index on place 0
	string line;
	while(getline(inputStream, line)) //read whole line
		cout<<line<<endl;
	inputStream.seekg(0);		//sets index back to place 0
}

void File::getfirstLines(int n){ 	//get the first lines of file
	inputStream.seekg(0);		//sets index on place 0
	string line;
	for(int i=0; i<n; i++)		//read whole line
		if(getline(inputStream, line))
			cout<<line<<endl;
	inputStream.seekg(0);		//sets index back to place 0
}

void File::getlastLines(int n){		//get the last lines of file
	inputStream.seekg(0);
	string line;
	int numOfLines = getNumberOfLines();	//returns number of lines in file
	for (int i=0; i<numOfLines-n; i++)
		takeCursorToNextLine();	//moves cursor to after '\n'
	for(int i=0; i<n; i++)
		if(getline(inputStream, line))
			cout<<line<<endl;
	inputStream.seekg(0);
}

int File::getNumberOfLines(){ //counts how many lines are there in the file
	char c;
	int count=0;
	inputStream.seekg(0);
	while (!inputStream.eof()){
		inputStream >> c;
		if (c == '\n')
			count++;

	}
	return count;
}

void File::takeCursorToNextLine(){ //helps to read last wanted lines
	char c;
	inputStream.seekg(0);
	inputStream >> c;
	while (c == '\n'){
		inputStream >> c;
	}
}
