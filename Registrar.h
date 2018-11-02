#include "Student.h"
#include "Queue.h"

class Registrar
{
  public:
    Registrar();
    ~Registrar();
    Registrar(string fileName);

    int students;
    int totalStudents;
    int windows;
    int time;

    Queue<Student> studentLine;
    Queue<Student> line;

    int *idleTimes;
    int *waitTimes;
    bool *window;
    Student *atWindow;

    bool empty();
    void enterLine();
    void clearWindows();
    int openWindows();
    void updateWindows();
    void updateTime();
    double calcMedian();
    void calcStats();

    void simulate();
};
