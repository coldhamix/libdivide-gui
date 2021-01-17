#include <QLibrary>
#include <QDebug>
#include <QMessageBox>
#include "libdivide_wrapper.h"
#include "libdivide.h"

typedef int (*LibDivideFunction)(unsigned int, unsigned int);

static QLibrary *loadLibrary()
{
    QLibrary *library = new QLibrary("libdivide.dll");
    if (!library->load())
    {
        QMessageBox::critical(0, "Ошибка", "Не найдена библиотека LibDivide.dll");
        qDebug() << "Error: LibDivide.dll coudn't be found!\n";
        exit(1);
    } else {
        qDebug() << "LibDivide.dll loaded\n";
    }
    return library;
}

int LibDivide::divide(unsigned int dividend, unsigned int divisor)
{
    QLibrary *libDivide = loadLibrary();
    LibDivideFunction divideFunction = (LibDivideFunction) libDivide->resolve("divide");
    return divideFunction(dividend, divisor);
}

int LibDivide::remainder(unsigned int dividend, unsigned int divisor)
{
    QLibrary *libDivide = loadLibrary();
    LibDivideFunction remainderFunction = (LibDivideFunction) libDivide->resolve("mod");
    return remainderFunction(dividend, divisor);
}
