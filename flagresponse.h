#include "flagwords.h"
#include <string>


//static QString message that prints that the program started running
static QString message = "iNfOflag program is now running!";


//beginning of flagResponse class
//derived class inherited from flagWords class
class flagResponse: public flagWords{
  private:
    //int flagGrade=0;
    int flagGrade;
  public:
    //inherited constructor from flagWords class, as well as a message printing call
    flagResponse(QString filename):flagWords(filename){ qDebug()<<message<<"\n"; }
    //copy constructor
    flagResponse(QString filename,const flagResponse &otherFlagResponse):flagWords(filename){
        flagGrade=otherFlagResponse.flagGrade;
        qDebug()<<"copy constructor: "<<otherFlagResponse.flagGrade;
    }
    bool operator==(flagResponse other);
    string resultPrinter(string userInput);
    void print(){}
};  //end of flagResponse class
