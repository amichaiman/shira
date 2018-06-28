//
// Created by Shira on 27/06/18.
//

#include "Terminal.h"

void Terminal::touch(const string &fileName) { 		//opens a new file
	File *file = getFile(fileName);

	if (file){
		file->touch();
	}else {
		files.push_back(new File(fileName)); 		//adding filename to list
	}
}

void Terminal::ls() {
	for (vector<File*>::iterator i=files.begin(); i !=files.end();i++ ){
		cout << (*i)->getName() << endl;
	}
}

void Terminal::copy(const string &source, const string &destination) { 		//copies file into new file
	File *sourceFile = getFile(source);

	if (sourceFile == NULL){
		throw noSuchFileException();
	}
	File *destinationFile = sourceFile->clone(); //func that copies the content of file

	destinationFile->setName(destination); 		//sets the name of the file

	files.push_back(destinationFile); 			//adding the file to the list

}

File *Terminal::getFile(const string &fileName) { 		//make sure that file does exists
	for (vector<File*>::iterator i=files.begin(); i !=files.end();i++ ){
		if ((*i)->getName() == fileName){
			return (*i);
		}
	}
	return NULL;
}

void Terminal::remove(const string &fileName) { 		//remove file from list
	for (vector<File*>::iterator i=files.begin(); i !=files.end();i++ ){
		if ((*i)->getName() == fileName){
			delete(*i);
			files.erase(i);
			return;
		}
	}

}

void Terminal::move(const string &source,const string &destination) {//copies content to new file and deletes the source file
	File *sourceFile = getFile(source);

	if (sourceFile == NULL){
		throw noSuchFileException();
	}

	copy(source,destination); //func assist
	remove(source); //func assist
}

void Terminal::write(const string &fileName, const int pos, const char c) { //writing to file
	File *file = getFile(fileName);

	if (file == NULL){
		throw noSuchFileException();
	}

	(*file).operator[](pair<int,char>(pos,c));
}

void Terminal::read(const string &fileName, const int pos) { //reading from file
	File *file = getFile(fileName);

	if (file == NULL){
		throw noSuchFileException();
	}

	cout << (*file).operator[](pos) << endl;
}

void Terminal::cat(const string& fileName){ //Concatenation to output stream
	File *file = getFile(fileName);
	if (file == NULL){
		throw noSuchFileException();
	}
	file->getContent();
}

void Terminal::head(const string& fileName, const int chars){ 	//prints the first n lines [default -10]
	File *file = getFile(fileName);
	if (file == NULL){
		throw noSuchFileException();
	}
	file->getfirstLines(chars);
}
void Terminal::tail(const string& fileName, const int chars){	//prints the last n lines [default -10]
	File *file = getFile(fileName);
	if (file == NULL){
		throw noSuchFileException();
	}
	file->getlastLines(chars);
}
