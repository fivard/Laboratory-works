#include "message.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

void MessageLog::saveToTxt(){
    ofstream file("data.txt", ios_base::app);
    if (file)
        cout << "txt is opened \n";
    else{
        cout << "txt is closed \n";
        return;
    }

    file << this->id << ' ' << this->text << ' ' << this->loading << ' '
         << this->typeOfError << ' ' << this->priority << ' ' << ctime(&this->timeInSec);

    file.close();
}

void MessageLog::saveToBin(){
    ofstream file("binary.bin", ios_base::binary|ios_base::app);
    if (file)
        cout << "binary is opened \n";
    else{
        cout << "binary is closed \n";
        return;
    }
    char* normalTime = ctime(&this->timeInSec);
    file.write((char*)&this->id, sizeof(this->id)); //id

    int lengthText = text.size();
    file.write((char*)&lengthText, sizeof(lengthText));
    file << this->text; //text

    file.write((char*)&this->loading, sizeof(this->loading)); //loading

    int lengthTypeOfError = text.size();
    file.write((char*)&typeOfError, sizeof(typeOfError));
    file << this->typeOfError; //typeOfError

    file.write((char*)&this->priority, sizeof(this->priority)); //priority

    int length = strlen(normalTime);
    file.write((char*)&length, sizeof(length));
    file << normalTime; //time

    file.close();
}

void MessageLog::readFromTxt(){
    ifstream file("data.txt");
    string s;
    while(getline(file, s))
        cout << s << endl;
    file.close();
}

void MessageLog::readFromBin(){
    ifstream file("binary.bin", ios_base::binary);
    char S[255] = {};
    file.read((char*)&S, sizeof(S));
    cout << S << endl;
    file.close();
}
