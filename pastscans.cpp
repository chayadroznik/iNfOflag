#include "pastscans.h"
#include "ui_pastscans.h"
#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
#include <QLabel>
#include <QString>
#include <QHBoxLayout>
using namespace std;


//function that retrieves all the past scans from the outfile specified, pushes them into a vector, and returns the vector
vector<string> openFile(string fileName){
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
}//end of openFile()



//pastScans constructor
pastScans::pastScans(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pastScans)
{
    ui->setupUi(this);
    QWidget* window= new QWidget;
    vector<string> list =openFile("pastScans.txt");    //call openFile() function to set list to the flags in "pastScans.txt" outfile
    QVBoxLayout* layout=new QVBoxLayout(window);
    for(int i=0;i<list.size();i++){
        //create a new label to print every flag
        QLabel* label=new QLabel(this);
        layout->addWidget(label);
        label->setText(QString::fromStdString(list[i]));
    }
    setLayout(layout);
}//end of pastScans constructor


pastScans::~pastScans()
{
    delete ui;
}
