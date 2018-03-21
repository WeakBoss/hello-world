#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
class Clock {
public:
	Clock(int h, int m, int s);
	Clock();
	~Clock() {};
	void tick();
	void show();
	void adjust();
	void alarm();
	void system();
	void rang();
private:
	time_t timep;
	time_t timea;
	bool is_alarm;
	bool is_rang;
	int rang_time;
};
Clock::Clock(int h, int m, int s) {
	time(&timep);
	struct tm*p = localtime(&timep);
	p->tm_hour = h;
	p->tm_min = m;
	p->tm_sec = s;
	timep = mktime(p);
	timep++;
	is_alarm = false;
	is_rang=false;
	rang_time= 60;
}
Clock::Clock() {
	time(&timep);
	timep++;
	is_alarm =is_rang= false;
	rang_time = 60;
}
void Clock::tick() {
	timep++;
}
void Clock::show() {
	cout << ctime(&timep)<<endl;
	
}
void Clock::system() {
	if (_kbhit() != 0) {
		cout << "选择" << endl << "1 调整时间 2 设闹钟" << endl;
		int key;
		cin >> key;
		switch (key) {
		case 1:
			adjust();
			break;
		case 2:
			alarm();
			break;
		}
	}
	if (is_alarm) {
		struct tm*p = localtime(&timea);
		cout << "alarm:" << p->tm_hour << ":" << p->tm_min << ":" << p->tm_sec <<"\t";
	}
	else {
		cout << "no alarm \t" ;
	}
	if (is_rang) {
		cout << "ranging\t" <<"letf "<<rang_time<<" seconds"<< endl;
	}
	else {
		cout << "no rang" << endl;
	}
	if (timep == timea) {
		is_rang = true;
	}
	if (rang_time == 0) {
		is_alarm = is_rang = false;
		rang_time = 60;
	}
}
void Clock::adjust() {
	
	
		cout << "输入  时 分 秒" << endl;
		int h, m, s;
		cin >> h >> m >> s;
		struct tm*p = localtime(&timep);
		p->tm_hour = h;
		p->tm_min = m;
		p->tm_sec = s;
		timep = mktime(p);
}
void Clock::alarm() {
	    cout << "输入  时 分 秒" << endl;
		int h, m, s;
		cin >> h >> m >> s;
		time(&timea);
		struct tm*p = localtime(&timea);
		p->tm_hour = h;
		p->tm_min = m;
		p->tm_sec = s;
		timea = mktime(p);
		is_alarm = true;
		timep += 5;
}
void Clock::rang() {
	if (is_rang) {
		cout << '\a';
		rang_time--;
	}
}
int main() {
	Clock ck;
	while (true) {
		ck.show();
		cout << "调整时间或设闹钟 请按任意键" << endl;
		ck.tick();
		ck.system();
		ck.rang();
		Sleep(890);
		system("cls");
	}
}
