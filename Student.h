class Student
{
  public:
    Student();
    Student(int aTime, int wTime);
    ~Student();

    int arrival;
    int waited;
    int timeSpent;
    int timeNeeded;

    void isIdle();
    void isHelped();
    bool isDone();
    int getArrival();
    int getWait();
};
