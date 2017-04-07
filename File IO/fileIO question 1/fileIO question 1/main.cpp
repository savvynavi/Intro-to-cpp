#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//creates a text file, and lets user either display the contents in the console, write more text to it, or clear it completely
int main(){
	fstream file;
	bool running = true;
	int choice;
	string writeInput;
	const streamsize size = 200;
	char writeOutput[size];
	while(running == true){
		file << "testing test test" << endl;
		cout << "do you want to display[1], write[2] or clear[3] the file mtLog.txt?, [0] to quit: ";
		cin >> choice;
		switch(choice){
		case 1:
			file.open("myLog.txt", ios::in);
			if(file.is_open()){
				while(file.eof() == false){
					char line[256];
					file.getline(line, 256);
					cout << line << endl;
				}
			}
			cout << endl;
			file.close();
			break;
		case 2:
			cin.clear();
			cin.ignore();
			file.open("myLog.txt", ios::app);
			cout << "\nEnter what you want to put into the file: ";
			if(file.is_open()){
				char line[256];
				cin.getline(line, 256);
				file << line << endl;
			}
			file.close();
			break;
		case 3:
			cin.clear();
			cin.ignore();
			cout << "\nClearing file\n";
			file.open("myLog.txt", ios::out);
			file.close();
			break;
		case 0:
			cin.clear();
			cin.ignore();
			cout << "\nExiting now\n";
			running = false;
			break;
		default:
			cin.clear();
			cin.ignore();
			cout << "\nERROR not valid input\n";
			break;
		}
	}	
	system("pause");
	return 0;
}