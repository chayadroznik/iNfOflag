#ifndef FLAGSRAISED_H
#define FLAGSRAISED_H

#include <QDialog>

namespace Ui {
class flagsraised;
}

class flagsraised : public QDialog
{
    Q_OBJECT

public:
    explicit flagsraised(QWidget *parent = nullptr);
    ~flagsraised();

private:
    Ui::flagsraised *ui;
};

#endif // FLAGSRAISED_H
