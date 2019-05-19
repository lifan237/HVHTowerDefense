#ifndef START_H
#define START_H

#include <QMainWindow>

namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();

private slots:
    void on_pushButton_clicked();

signals://信号声明--不需实现，后期直接通过emit 发送就可以了
    void mysignals();

private:
    Ui::Start *ui;
};

#endif // START_H
