#include "mainFunctions.h"

#include <climits>
#include <string>
#include <sstream>

queries getQuery(string s);

void getUserQueries(Terminal *terminal) { 	// defines every command and sends it to correct func
	string input;
	string fileName;
	cin >> input;

	while (getQuery(input) != exit) {
		try {
			switch (getQuery(input)) {
			case read:{
				int location;

				cin >> fileName >> location;
				if (cin.fail()){ 		//if failed reading file throw exception
					throw invalidReadQueryException();
				}

				terminal->read(fileName,location);
			} break;
			case write:{
				int location;
				char c;

				cin >> fileName >> location >> c;

				if (cin.fail()){		//if failed writing to file throw exception
					throw invalidWriteQueryException();
				}

				terminal->write(fileName,location,c);
			} break;
			case touch: {
				cin >> fileName;
				terminal->touch(fileName);
			}
			break;
			case cp: {
				stringstream ss;
				string data;
				string source;
				string destination;

				getline(cin,data,'\n');	 //gets whole line to 'data' from input
				ss << data;				 //sends it to stringstream

				ss >> source; 			//diving it to said variables
				ss >> destination;
				if (source.empty() || destination.empty()){
					throw invalidCopyQueryException();
				}
				terminal->copy(source, destination);
			} break;
			case rm:{
				string source;

				getline(cin,source,'\n');
				if (source.empty()){		//if variable empty throw exception
					throw invalidRemoveQueryException();
				}
				terminal->remove(fileName);
			} break;
			case move:{
				stringstream ss;
				string data;
				string source;
				string destination;

				getline(cin,data,'\n');		//gets whole line to 'data' from input
				ss << data;				 //sends it to stringstream

				ss >> source;			//diving it to said variables
				ss >> destination;
				if (source.empty() || destination.empty()){ 		//if variables empty throw exception
					throw invalidMoveQueryException();
				}
				terminal->move(source, destination);
			} break;
			case cat:{
				cin >> fileName;
				terminal->cat(fileName);
			}break;
			case head:{
				int n=10; 				//default n
				cin >> fileName >>n;
				terminal->head(fileName, n);
			}break;
			case tail:{
				int n=10;				//default n
				cin >> fileName >>n;
				terminal->tail(fileName, n);
			}break;
			case ls:
				terminal->ls();		 //case check
				break;
			case exit:
				break;
			default:
				cerr << "ERROR: command is not supported" << endl;
			}
		} catch (noSuchFileException &e){
			cerr << "ERROR: " << fileName << " does not exist or cannot be processed"<<endl;
		} catch (exception &e){
			cerr << e.what() << endl;
		}
		cin.clear(); 					//clears to buffer from inputs
		cin.ignore(INT_MAX,'\n');
		cin >> input;
	}

}

queries getQuery(string s) { 			//function to work with switch case
	if (s == "read") return read;
	if (s == "write") return write;
	if (s == "touch") return touch;
	if (s == "copy") return cp;
	if (s == "remove") return rm;
	if (s == "move") return move;
	if (s == "cat") return cat;
	if (s == "head") return head;
	if (s == "tail") return tail;
	if (s == "ls") return ls;
	if (s == "exit") return exit;
	return invalidQuery;
}
