#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

class Time
{
public:
    //non-parameterized constructor, with defaults
    Time(){
        hour_ = 0;
        min_ = 0;
        second_ = 0;
    };

    //parameterized constructor, requires user to input h,m,s args
    Time(unsigned int hour, unsigned int min, unsigned int second){
        if (hour > 23) {throw std::invalid_argument("hour must be between [0,23]");}
        if (min > 59)  {throw std::invalid_argument("min must be between [0,59]");}
        if (second > 59)  {throw std::invalid_argument("second must be between [0,59]");}
        hour_ = hour;
        min_ = min;
        second_ = second;
    };
    Time(const Time &rhs); //... and another constructor

    //Method to print the time...
    //TODO: verify ok to use <iomanip> std::setfill() and std::setw()
    void Print(bool display_24){
        std::string am_or_pm;
        if (display_24 == true)
        {   
            am_or_pm = " (24 HR)";
            std::cout << std::setfill('0') << std::setw(2) << hour_ << ":" 
                      << std::setfill('0') << std::setw(2) << min_ << ":" 
                      << std::setfill('0') << std::setw(2) << second_ << am_or_pm << std::endl;
        }
        if (display_24 == false)
        {
            if (hour_ == 0)
            {
                am_or_pm = " (AM)";
                hour_ = 12;
            }
            else if (hour_ <= 11)
            {
                am_or_pm = " (AM)";                
            }
            else if (hour_ == 12)
            {
                am_or_pm = " (PM)";
            }
            else if (hour_ <= 23)
            {
                am_or_pm = " (PM)";
                hour_ -= 12;                
            }

            std::cout << std::setfill('0') << std::setw(2) << hour_ << ":" 
                      << std::setfill('0') << std::setw(2) << min_ << ":" 
                      << std::setfill('0') << std::setw(2) << second_ << am_or_pm << std::endl;
        }
    };

private:
    int hour_;
    int min_;
    int second_;
};

int main(){
    auto t = Time(12,3,22);
    t.Print(true);
    t.Print(false);

    t = Time(8,3,22);
    t.Print(true);
    t.Print(false);

    t = Time(23,58,12);
    t.Print(true);
    t.Print(false);

    t = Time();
    t.Print(true);
    t.Print(false);

}