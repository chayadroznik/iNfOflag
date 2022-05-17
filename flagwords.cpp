#include "flagwords.h"


//flagWords constructor
flagWords::flagWords(QString filename){
    QFile* file = new QFile(filename);
    flagWordsInfile = file;
    //exception handling to throw an exception if the file does not oen
    if(flagWordsInfile->open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() <<"success\n";
    }
    else{
        throw QString("error with opening file");
    }
    QTextStream in(file);
   while (!in.atEnd())
   {
      QString word = in.readLine();
      flagText.push_back(word.toStdString());  //push back words that raise flags into an array
   }
}//end of flagWords constructor


//flagWords deconstructor
flagWords::~flagWords(){
    delete flagWordsInfile;
}


//flag check function
//compares userInput with every index in the flagWords vector
//pushes any matches into the flagMatches vector
//sets flagCounter to the amount of flags found
void flagWords::flagCheck(string userInput){
    for (int j=0;j<(flagText.size());j++){
      for(size_t i=0;i!=string::npos;){
        const auto nextIndex = userInput.find(flagText[j],i);
        if(nextIndex!=string::npos){
          flagMatches.push_back(flagText[j]);
          flagCounter++;
          qDebug()<<(QString::fromStdString(flagText[j]));
        }
        if(nextIndex==string::npos)
          i=nextIndex;
        else
          i=(flagText[j].size()+nextIndex);
      }
    }
}// end of flagCheck()



//function to calculate the grade for the flag scan and returns flagGrade
int flagWords::flagGradeCalculator(){
  if(flagCounter==0){
    flagGrade=0;
  }
  else{
    if(flagCounter>=10){
      flagGrade= 100;
    }
    else{
      flagGrade=flagCounter*10;
    }
  }
  return flagGrade;
}//end of flagGradeCalculator()


//function that returns a QString with the flagged words
QString flagWords::getFlaggedWords(){
    string flagMatch;
    for (int i=0;i<flagMatches.size();i++){
        flagMatch=flagMatch+"\n"+flagMatches[i];
    }
    return QString::fromStdString(flagMatch);
}//end of getFlaggedWords()



//function returns flagCounter
int flagWords::getflagCount(){
  return flagCounter;
}//end of getflagCount()
