#include "analogread.h"

AnalogRead::AnalogRead(QObject *parent) :
  QThread(parent)
{
}

void AnalogRead::run(void)
{
  int battry_val;
  int hall_val;
  FILE *fp_batt;
  FILE *fp_hall;

  fp_batt = fopen("/sys/class/misc/adc/ch0_value","r");
  fp_hall = fopen("/sys/class/misc/adc/ch1_value","r");
  while(1){
    mutexq.lock();
    waitq.wait(&mutexq,1000);
    fread(&battry_val,sizeof(int),1,fp_batt);
    printf("bat:%d\n",battry_val);
    fread(&hall_val,sizeof(int),1,fp_hall);
    printf("hall:%d\n",hall_val);
    mutexq.unlock();
  }
}
