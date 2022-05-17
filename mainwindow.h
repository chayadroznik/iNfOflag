#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_scan_button_clicked();

    void on_go_to_links_clicked();

    void on_past_scans_clicked();

    void on_go_to_flags_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
