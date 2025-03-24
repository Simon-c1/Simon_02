#ifndef TIME1_H
#define TIME1_H

#include <iostream>

class Time{
    int sec;

public:
    Time(int sec =0);
    int getSec() const {return sec; }

    void inputTime(std::istream& is){
        int hours;
        int minutes;
        int seconds;

        char separate;

        is >> hours >> separate >> minutes >> separate >> seconds;
        sec = hours * 3600 + minutes *60 + seconds;
    }

    void printTime(std::ostream& os) const{
        int hours = sec/3600;
        int minutes = (sec%3600)/60;
        int seconds = sec%60;
        os << hours << "h:" << minutes << "m;" << seconds << "s:";
    }
    Time operator+(const Time&other) const { return Time (sec + other.sec);}
    Time operator-(const Time&other) const { return Time (sec - other.sec);}
    Time operator*(const Time&other) const { return Time (sec * other.sec);}
    operator int() const {return sec;}
};

inline std::istream& operator>>(std::istream& is, Time& t){
    t.inputTime(is);
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Time& t){
    t.printTime(os);
    return os;
}

#endif // TIME1_H
