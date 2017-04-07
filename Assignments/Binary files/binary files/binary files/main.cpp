#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define BINFILE "library.dat"
#define TEXTFILE "library.txt"

#define INLIB "1\r"
#define ONLOAN "2\r"
#define LOST "3\r"

using namespace std;

struct Record{
	string callNumber;
	string title;
	string author;
	string status;
	string dueDate;
	string borrower;
};

void loadTextFile(const char *filename, vector<Record> &library);
void displayRecords(vector<Record> &library);
void writeToFile(const char *filename, vector<Record> &library);
int findRecord(string callNum, vector<Record> &library);
void updateRecord(string callNum, vector<Record> &library);

int main(){
	vector<Record> library;
	vector<string> data;
	string line;
	Record *temp;

	//If binary file exist read into the Library
	ifstream binFile;
	binFile.open(BINFILE, ios::in | ios::binary);
	if(binFile.is_open()){
		//Reads data from binary and puts it to a vector
		while(!binFile.eof() && binFile.peek() != EOF){
			char a[200];
			binFile.read((char*)&a, sizeof(string));
			data.push_back(a);
		}
		//iterate through vector to create records
		for(vector<string>::iterator i = data.begin(); i != data.end(); ++i){
			temp = new Record();
			temp->callNumber = (*i);
			temp->title = *(i + 1);
			temp->author = *(i + 2);
			temp->status = *(i + 3);
			if(temp->status == ONLOAN){
				temp->dueDate = *(i + 4);
				temp->borrower = *(i + 5);
				i = i + 2;
			}
			i = i + 3;
			library.push_back(*temp);
		}
	}else{
		binFile.close();
		//If binary file doesn't exist create it from a text file
		loadTextFile(TEXTFILE, library);
		//creates binary file and writes records to it
		writeToFile(BINFILE, library);
	}

	//Once records are loaded let the user do what they want
	bool running = true;
	while(running == true){
		cout << "[1]display record\n[2]update status of record\n[3]Quit: ";
		int input;
		cin >> input;
		switch(input){
		case 1:
			displayRecords(library);
			break;
		case 2:
			//allows you to update the borrowed status of a book, with name and return date
			cout << "\nWhat is the call number of the record you wish to edit?: ";
			cin >> line;
			cout << endl;
			updateRecord(line, library);
			break;
		case 3:
			cout << "\nQuitting now\n";
			running = false;
			break;
		default:
			cout << "\nERROR invalid input\n";
			cin.clear();
			cin.ignore();
			break;
		}
	}
	system("pause");
	return 0;
}

//takes in a vector of all the records and a filename, copies the vector contents into the binary file
void writeToFile(const char *filename, vector<Record> &library){
	fstream binFile;
	binFile.open(filename, ios::out | ios::binary);
	for(vector<Record>::iterator i = library.begin(); i != library.end(); ++i){
		binFile.write(((*i).callNumber).c_str(), sizeof ((*i).callNumber));
		binFile.write(((*i).title).c_str(), sizeof((*i).title));
		binFile.write(((*i).author).c_str(), sizeof((*i).author));
		binFile.write(((*i).status).c_str(), sizeof((*i).status));
		if((*i).status == ONLOAN){
			binFile.write(((*i).dueDate).c_str(), sizeof((*i).dueDate));
			binFile.write(((*i).borrower).c_str(), sizeof((*i).borrower));
		}
	}
}

//Reads through file and puts records into library vector
void loadTextFile(const char *filename, vector<Record> &library){
	fstream binFile;
	string line;
	Record* temp;
	
	binFile.open(filename, ios::in | ios::binary);
	if(binFile.good()){
		for(int i = 0; !binFile.eof(); i++){
			temp = new Record();
			getline(binFile, line);
			temp -> callNumber = line;
			getline(binFile, line);
			temp -> title = line;
			getline(binFile, line);
			temp -> author = line;
			getline(binFile, line);
			temp -> status = line;
			if(line == ONLOAN){
				getline(binFile, line);
				temp -> dueDate = line;
				getline(binFile, line);
				temp -> borrower = line;
			}
			library.push_back(*temp);
		}
	}

}

//prints the current records in the vector to the terminal
void displayRecords(vector<Record> &library){
	for(vector<Record>::iterator i = library.begin(); i != library.end(); ++i){
		cout << (*i).callNumber << endl;
		cout << (*i).title << endl;
		cout << (*i).author << endl;
		cout << (*i).status << endl;
		if((*i).status.compare(ONLOAN) == 0){
			cout << (*i).dueDate << endl;
			cout << (*i).borrower << endl;
		}
	}
}

//takes in a call number and returns the index it's located at in the vector, -1 if it can't be found
int findRecord(string callNum, vector<Record> &library){
	for(size_t i = 0; i < library.size(); i++){
		if(library[i].callNumber.compare(0,9,callNum) == 0){
			return i;
		}
	}
	return -1;
}

//takes in a call number and vector of records, lets user change the status of a record and updates the binary file accordingly
void updateRecord(string callNum, vector<Record> &library){
	int position = findRecord(callNum, library);
	if(position == -1){
		cout << "\nError: Record not found\n";
		return;
	}
	string newStatus;
	cout << "What is the records new status?: ";
	cin.clear();
	cin.ignore();
	cin >> newStatus;
	newStatus = newStatus + "\r";
	if(newStatus == ONLOAN){
		string newDate;
		string newBorrower;
		cout << "\nWhat is the due date?: ";
		cin.clear();
		cin.ignore();
		getline(cin,newDate);
		cout << "\nWho borrowed it?: ";
		getline(cin, newBorrower);
		library[position].dueDate = newDate;
		library[position].borrower = newBorrower;
	}else if(library[position].status == ONLOAN && newStatus != ONLOAN){
		library[position].dueDate = "";
		library[position].borrower = "";
	}
	cout << endl;
	library[position].status = newStatus;
	//write new records to binary
	writeToFile(BINFILE, library);
}
