#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "libdivide_wrapper.h"

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
    void on_calculateButton_clicked();

private:

    void showResult(LibDivide::IntegerDivisionResult result);
    LibDivide::IntegerDivisionResult calculateResult(unsigned int dividend, unsigned int divisor);


    void toggleResultVisibility(bool visible);
    void setupValidation();

    bool validateInputs();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
