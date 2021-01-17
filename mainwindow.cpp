#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupValidation();
    toggleResultVisibility(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calculateButton_clicked()
{

    auto dividendTextField = findChild<QLineEdit*>("dividendTextField");
    auto dividend = dividendTextField->text().toInt();

    auto divisorTextField = findChild<QLineEdit*>("dividorTextField");
    auto divisor = divisorTextField->text().toInt();

    if (!validateInputs()) {
        return;
    }

    LibDivide::IntegerDivisionResult result = calculateResult(dividend, divisor);
    showResult(result);
}

void MainWindow::showResult(LibDivide::IntegerDivisionResult result)
{
    auto value = QString("Целочисленное деление: %1, остаток: %2").arg(QString::number(result.quotient), QString::number(result.remainder));
    auto quotientValue = findChild<QLabel*>("quotientValue");
    quotientValue->setText(value);

    toggleResultVisibility(true);
}

void MainWindow::toggleResultVisibility(bool visible)
{

    auto quotientLabel = findChild<QLabel*>("quotientLabel");
    quotientLabel->setVisible(visible);

    auto quotientValue = findChild<QLabel*>("quotientValue");
    quotientValue->setVisible(visible);
}

void MainWindow::setupValidation()
{
    auto dividendTextField = findChild<QLineEdit*>("dividendTextField");
    dividendTextField->setValidator(new QIntValidator(0, 100000000U, this));

    auto divisorTextField = findChild<QLineEdit*>("dividorTextField");
    divisorTextField->setValidator(new QIntValidator(0, 100000000U, this));
}

bool MainWindow::validateInputs()
{
    auto dividendTextField = findChild<QLineEdit*>("dividendTextField");
    auto dividendStr = dividendTextField->text();

    if (dividendStr.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Заполните поле \"Делимое\"");
        return false;
    }

    auto divisorTextField = findChild<QLineEdit*>("dividorTextField");
    auto divisorStr = divisorTextField->text();

    if (divisorStr.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Заполните поле \"Делитель\"");
        return false;
    }

    if (divisorStr.toInt() == 0) {
        QMessageBox::critical(this, "Ошибка", "Деление на ноль невозможно");
        return false;
    }

    return true;
}

LibDivide::IntegerDivisionResult MainWindow::calculateResult(unsigned int dividend, unsigned int divisor)
{
    LibDivide::IntegerDivisionResult result = {
        LibDivide::divide(dividend, divisor),
        LibDivide::remainder(dividend, divisor)
    };
    return result;
}
