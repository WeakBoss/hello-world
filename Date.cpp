#include <iostream>
using namespace std;
class Date {
public:
	Date(int y, int m, int d);
	~Date();

	void nextDay();
	void previousDay();
	bool equal(Date other);
	void show();
	int getyear() {
		return year;
	}
	int getmonth() {
		return month;
	}
	int getday() {
		return day;
	}
private:
	int year;
	int month;
	int day;
};
Date::Date(int y, int m, int d) :year(y), month(m), day(d) {
	;
}
Date::~Date() {
	;
}
void Date::nextDay() {
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31) {
		month++;
		day = 1;
		if (month == 12) {
			year++;
			month = 1;
		}
	}
	else if (( month == 4 || month == 6 || month == 9 || month == 11) && day == 30) {
		month++;
		day = 1;
	}
	else if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day == 29) {
		month++;
		day = 1;
	}
	else if (month == 2 && year % 4 != 0 && day == 28) {
		month++;
		day = 1;
	}
	else {
		day++;
	}

}
void Date::previousDay() {
	if ((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11 || month == 1) && day == 1) {
		month--;
		day = 31;
		if (month == 1) {
			year--;
			month = 12;
		}
	}
	else if (( month == 5 || month == 6 || month == 10 || month == 12) && day == 1) {
		month--;
		day = 30;
	}
	else if (month == 3 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day == 1) {
		month--;
		day = 29;
	}
	else if (month == 3 && year % 4 != 0 && day == 1) {
		month--;
		day = 28;
	}
	else {
		day--;
	}
}
bool Date::equal(Date other) {
	if (year == other.getyear() && month == other.getmonth() && day == other.getday()) {
		return true;
	}
	else {
		return false;
	}
}
void Date::show() {
	cout << year << "." << month << "." << day << endl;
}
int main() {
	Date today(2018, 3, 20);
	Date day(2018, 3, 20);
	day.show();
	for (int i = 0;i<30;i++)
		day.nextDay();
	day.show();
	for (int i = 0;i<30;i++)
		day.previousDay();
	day.show();
	if (day.equal(today))
		printf("Very Good!\n");
	else
		printf("Very Bad!\n");
	return 0;
}
