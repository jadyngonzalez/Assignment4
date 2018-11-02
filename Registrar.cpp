#include <iostream>
#include <fstream>
#include <algorithm>
#include "Queue.h"
#include "Registrar.h"

using namespace std;

Registrar::Registrar()
{
  students = 0;
  time = 0;
}

Registrar::~Registrar()
{

}

Registrar::Registrar(string fileName)
{
  ifstream file; //opens file and reads in values
  string line;

  time = 0;
  students = 0;
  totalStudents = 0;

  int tick = 0;
  int count = 0;

  file.open(fileName);
  file >> line;
  windows  = stoi(line);

  atWindow = new Student[windows];
  idleTimes = new int[windows];
  window = new bool[windows];

  while(!file.eof()) //reads file then assigns values
  {
    file >> line;
    tick = stoi(line);
    file >>line;
    int studentsArriving = stoi(line);

    for(int i = 0; i < studentsArriving; i++)
    {
      file >> line;
      Student s(stoi(line), tick);
      studentLine.insert(s);
      ++totalStudents;
    }
  }
  waitTimes = new int[totalStudents];
}

bool Registrar::empty() //checks if the windows are empty
{
  for(int i = 0; i < windows; ++i)
  {
    if(window[i] == true)
    {
      return false;
    }
  }
  return true;
}

void Registrar::enterLine() //puts a student into the line
{
  Student s = studentLine.peek();
  while(s.getArrival() == time)
  {
    line.insert(s);
    studentLine.remove();
    s = studentLine.peek();
  }
}

void Registrar::clearWindows()  //opens up a spot after a student leaves
{
  for(int i = 0; i < windows; ++i)
  {
    if(window[i] == true)
    {
      if(atWindow[i].isDone())
      {
        window[i] = false;
        Student hold = atWindow[i];
        idleTimes[students] = hold.getWait();
        students++;
      }
    }
  }
}

int Registrar::openWindows()
{
  for(int i = 0; i < windows; ++i) //checks for any open windows
  {
    if(window[i] == false)
    {
      return i;
    }
  }
  return -1;
}

void Registrar::updateWindows() //if a window is idle after the next tick it will update its idle time
{
  for(int i = 0; i < windows; i++)
  {
    if(window[i] == false)
    {
      idleTimes[i] += 1;
    }
  }
}

void Registrar::updateTime()
{
  Queue<Student> temp;

  while(!line.isEmpty())
  {
    Student hold = temp.peek();
    temp.remove();
    hold.isIdle();
    studentLine.insert(hold);
  }
}

double Registrar::calcMedian() //calculates median using the sort funciton
{
  sort(waitTimes, waitTimes + totalStudents - 1);
  if((totalStudents % 2) == 1)
  {
    return waitTimes[totalStudents / 2];
  }
  else
  {
    int x = totalStudents / 2;
    int y = (totalStudents / 2) - 1;
    double avg = (waitTimes[x] + waitTimes[y]) / 2;
    return avg;
  }
}

void Registrar::calcStats() // calculates and outputs stats
{
  double mean = 0;
  int median = 0;
  int longestWait = 0;
  double averageIdle = 0;
  double longestIdle = 0;
  int overTen = 0;
  int overFive = 0;

  for(int i = 0; i < totalStudents; ++i)
  {
    mean += waitTimes[i];

    if(longestWait < waitTimes[i])
    {
      longestWait = waitTimes[i];
    }
    if(waitTimes[i] > 10)
    {
      overTen += 1;
    }
  }

  for(int i = 0; i < windows; ++i)
  {
    averageIdle += idleTimes[i];
    if(longestIdle < idleTimes[i])
    {
      longestIdle = idleTimes[i];
    }
    if(idleTimes[i] > 5)
    {
      overFive += 1;
    }
  }

  mean = mean / totalStudents;
  median = calcMedian();
  averageIdle = averageIdle / windows;

  cout << "Average Wait: " << mean << endl;
  cout << "Median Wait: " << median << endl;
  cout << "Longest Wait: " << longestWait << endl;
  cout << "Students waited over 10: " << overTen << endl;
  cout << "Average Window Idle: " << averageIdle << endl;;
  cout << "Longest Idle: " << longestIdle << endl;
  cout << "Windows Idle Over 5: " << overFive << endl;
}

void Registrar::simulate() //runs simulation
{
  while(!studentLine.isEmpty() || !line.isEmpty() || !empty())
  {
    if(!studentLine.isEmpty())
    {
      enterLine();
    }
    clearWindows();

    while(openWindows() != -1 && !line.isEmpty())
    {
      Student hold = line.peek();
      int opened = openWindows();
      window[opened] = true;
      atWindow[opened] = hold;
      line.remove();
    }

    for(int i = 0; i < windows; ++i)
    {
      atWindow[i].isHelped();
    }
    updateTime();
    updateWindows();

    if(time == 5)
    {
      Student st = line.peek();
    }
    time += 1;
  }
  calcStats();
}
