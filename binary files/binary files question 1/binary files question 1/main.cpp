#include<fstream>
#include<iostream>
using namespace std;

const int bookInLibrary = 1;
const int bookOnLoan = 2;
const int bookLost = 3;

//currently random numbers based on guessing max length, change to vectors maybe?
struct BookRecord{
	char callNum[20];
	char title[200];
	char author[30];
	int status;
	char dueDate[10];
	char borrower[30];
};

struct Library{
	BookRecord *records;
	int maxEntries;
};

void loadRecordsFromText(const char *filename, Library &library);
void editOneRecord(const char *filename, int recordNum, BookRecord newRecord);

int main(){
	Library library;	
	fstream binFile;
	binFile.open("library.dat", ios::in | ios::binary);

	if(binFile.is_open()){
		binFile.seekg(0, ios::end);
		int position = binFile.tellg();		//sets position to be the end of the file
		binFile.seekg(0, ios::beg);			//sets the r/w marker to the start of the file
		library.maxEntries = position / sizeof(BookRecord);		//gets how many records there are in the file, should be in the first entry before the first call number
		library.records = new BookRecord[library.maxEntries];
		binFile.read((char*)library.records, library.maxEntries * sizeof(BookRecord));
	}else{
		binFile.close();
		loadRecordsFromText("RecordsText.txt", library);
		binFile.open("library.dat", ios::out | ios::binary);
		binFile.write((char*)library.records, library.maxEntries * sizeof(BookRecord));
		binFile.close();
	}

	system("pause");
	return 0;
}

//if no binary file is found, will create one from a .txt file, takes in a filename and a reference to a library struct
void loadRecordsFromText(const char *filename, Library &library){
	fstream txtFile;
	txtFile.open(filename, ios::in);
	if(txtFile.is_open()){
		txtFile >> library.maxEntries;
		txtFile.get();
		library.records = new BookRecord[library.maxEntries];

		for(int i = 0; i < library.maxEntries; i++){
			txtFile.getline(library.records[i].callNum, 20);
			txtFile.getline(library.records[i].title, 200);
			txtFile.getline(library.records[i].author, 30);
			if(library.records[i].status == bookOnLoan){
				txtFile.getline(library.records[i].dueDate, 30);
				txtFile.getline(library.records[i].borrower, 30);
			}
			txtFile.get();
		}
		txtFile.close();
	}
}

//allows you to edit one entry in the binary file
void editOneRecord(const char *filename, int recordNum, BookRecord newRecord){
	fstream binFile;
	binFile.open(filename);

	if(binFile.is_open()){
		binFile.seekp(recordNum * sizeof(BookRecord), ios:: beg);
		binFile.write((char*)&newRecord, sizeof(BookRecord));
	}
}