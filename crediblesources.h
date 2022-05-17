#ifndef CREDIBLESOURCES_H
#define CREDIBLESOURCES_H

#include <QDialog>

namespace Ui {
class credibleSources;
}

class credibleSources : public QDialog
{
    Q_OBJECT

public:
    explicit credibleSources(QWidget *parent = nullptr);
    ~credibleSources();

private:
    Ui::credibleSources *ui;
};

#endif // CREDIBLESOURCES_H
