class Date {
  
  private:
    int _day;
    int _month;
    int _year;

  public:
    Date(int day, int month, int year);
    Date(int month, int day, int year);
    Date(int year, int month, int day);

    int getDay() const;
    void setDay(int day);
  
    int getMonth() const;
    void setMonth(int month);
  
    int getYear() const;
    void setYear(int year);
    
    string getDate() const;
};
