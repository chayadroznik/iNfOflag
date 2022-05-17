#include "flagresponse.h"


//operator overloader
bool flagResponse::operator==(flagResponse other){
    flagGrade=other.flagGrade;
    qDebug()<<"operator overloader: "<<other.flagGrade;
    return flagGrade;
}

//function that prints the results of the flag scan, including the grade the scan recieved and how many flags were found
string flagResponse:: resultPrinter(string userInput){
  string SflagCount=to_string(getflagCount());
  string SflagGrade=to_string(flagGradeCalculator());
  if(flagGrade==0){
   return ("congratulations, your text has no potential flags! would you like to see credible sources on covid to strengthen your knowledge?");
  }
  else if(flagGrade==100){
    return ("your text raised "+SflagCount+" flags, so your text is "+SflagGrade+"% or more flagged. would you like to see credible sources on covid to strengthen your knowledge?");
  }
  else{
   return ("your text raised "+SflagCount+" flags, so your text is "+SflagGrade+"% flagged. would you like to see credible sources on covid to strengthen your knowledge?");
  }
}//end of flagGradeCalculator()
