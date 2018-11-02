#include "Student.h"

using namespace std;

Student::Student()
{
  arrival = 0;
  waited = 0;
  timeNeeded = 0;
  timeSpent = 0;
}

Student::Student(int a, int tN)
{
  arrival = a;
  timeNeeded = tN;
  timeSpent = 0;
  waited = 0;
}

Student::~Student()
{

}

void Student::isIdle()
{
  waited += 1;
}

void Student::isHelped()
{
  timeSpent += 1;
}

bool Student::isDone()
{
  return timeSpent == timeNeeded;
}

int Student::getArrival()
{
  return arrival;
}

int Student::getWait()
{
  if(timeSpent == 0)
  {
    return 0;
  }
  return timeSpent - 1;
}
