#ifndef FLAGWORDS_H
#define FLAGWORDS_H
#include <iostream>
#include <fstream>
#include <vector>
#include <QDebug>
#include <QFile>
#include <string>
using namespace std;

//beginning of flagWords class
class flagWords
{
    private:
        QFile *flagWordsInfile; //pointer to infile containing words that will raise flags
        int flagCounter=0;
        int flagGrade=0;
        vector<string> flagText; //vector to hold the words found in flagWordsInfile
        vector<string> flagMatches;  //vector for flags found in text given by user
    public:
        // constructor and destructor for flagWords
        flagWords(QString filename);
        ~flagWords();
        void flagCheck(string userInput);
        int flagGradeCalculator();
        QString getFlaggedWords();
        int getflagCount();
        virtual void print()=0;  //function to make this class abstract
};

#endif // FLAGWORDS_H
