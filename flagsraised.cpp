#include "flagsraised.h"
#include "ui_flagsraised.h"
#include "flagwords.h"
#include <string.h>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>
#include "flagresponse.h"
#include <QLabel>

//function that retrieves all the flags from the outfile specified, pushes them into a vector, and returns the vector
vector<string> getRaisedFlags(string fileName){
    ifstream display(fileName);
    string line;
    vector<string> lines;
    if(display){
        while(getline(display, line)){
            lines.push_back(line);
        }
        return lines;
    }
    else{
        return lines;
    }
}//end of getRaisedFlags()

//constructor for flagsraised
flagsraised::flagsraised(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::flagsraised)
{
    ui->setupUi(this);
    QWidget* window= new QWidget;
    vector<string> matchList =getRaisedFlags("flagMatches.txt");   //call getRaisedFlags() function to set matchList to the flags in "flagMatches.txt" outfile
    QVBoxLayout* layout=new QVBoxLayout(window);
    //create a new label to print every flag
    for(int i=0;i<matchList.size();i++){
        QLabel* label=new QLabel(this);
        layout->addWidget(label);
        label->setText(QString::fromStdString(matchList[i]));
    }
    setLayout(layout);
}//end of flagsraised constructor

flagsraised::~flagsraised()
{
    delete ui;
}
