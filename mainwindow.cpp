#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "flagsraised.h"
#include "flagwords.h"
#include "flagresponse.h"
#include "crediblesources.h"
#include "pastscans.h"
#include <fstream>
#include <vector>
#include <QVBoxLayout>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//sets all past scans to an outfile
bool toOutFile(QString text){
    ofstream pastScansFile("pastScans.txt", std::ofstream::app);
    if(pastScansFile){
        pastScansFile<<text.toStdString()<<endl;
        return true;
    }
    else{
        return false;
    }
}

//sets all flagged words to an outfile
bool flagMatchesOutfile(QString text){
    ofstream flagMatches("flagMatches.txt");
    if(flagMatches){
        flagMatches<<text.toStdString()<<endl;
        return true;
    }
    else{
        return false;
    }
}


void MainWindow::on_scan_button_clicked()
{
    try{
        QString val=ui->scan_text->toPlainText();
        ui->label->setText(val);
        flagResponse textCheck(":/input/flagWordsFile");
        textCheck.flagCheck(val.toStdString());
        string results = textCheck.resultPrinter(val.toStdString());
        ui->resultLabel->setText(QString::fromStdString(results));
        bool fileOpen=toOutFile(val);
        bool matchFileOpen=flagMatchesOutfile(textCheck.getFlaggedWords());
    }
    catch(QString msg){
        qDebug() <<msg;
    }
}

void MainWindow::on_go_to_links_clicked()
{
    credibleSources* links=new credibleSources();
    links->show();
}

void MainWindow::on_past_scans_clicked()
{
    pastScans* scans = new pastScans();
    scans->show();
}


void MainWindow::on_go_to_flags_clicked()
{
    flagsraised* raisedFlags = new flagsraised();
    raisedFlags->show();
}

