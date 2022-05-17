#ifndef PASTSCANS_H
#define PASTSCANS_H

#include <QDialog>

namespace Ui {
class pastScans;
}

class pastScans : public QDialog
{
    Q_OBJECT

public:
    explicit pastScans(QWidget *parent = nullptr);
    ~pastScans();

private:
    Ui::pastScans *ui;
};

#endif // PASTSCANS_H
