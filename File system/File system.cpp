#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean auctor justo vitae.";

    
    ofstream outFile("lipsum.txt");
    if (outFile.is_open()) {
        outFile << text;
        outFile.close();
        cout << "Text was written to lipsum.txt." << endl;
    }
    else {
        cout << "Cannot open the file for writing." << endl;
        return 1;
    }

    
    ifstream inFile("lipsum.txt");
    string fileContent;
    if (inFile.is_open()) {
        getline(inFile, fileContent, '\0'); 
        inFile.close();
        cout << "Text was read from the file." << endl;
    }
    else {
        cout << "Cannot open the file for reading." << endl;
        return 1;
    }

    
    for (char& c : fileContent) {
        if (c == 'A' || c == 'a') { 
            c = 'X';
        }
    }

    cout << "Modified text:" << endl;
    cout << fileContent << endl;

    return 0;
}
