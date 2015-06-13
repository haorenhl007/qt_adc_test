#include <QCoreApplication>
#include "analogread.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  AnalogRead adc;
  adc.start();
  adc.wait();
  return a.exec();
}
