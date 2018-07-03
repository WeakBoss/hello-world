//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......    pa=N/m^2=kg*m/s^2 / m^2=kg/(m*s^2)
//还有很多单位转换，有些单位是其它单位组合出来的
#include<iostream>
#include<string>
#include<vector> 
#include<cstdio>
//写得太繁琐 出现了很多小问题 最后解决了。。。。 
using namespace std;
double POW(double num, int n) {
	if (n == 0) return 1;
	double temp = num;
	while (n--) {
		num = num*temp;
	}
	return num;
}
class unit_trans {//单位转换关系类 
public:
	unit_trans() {
		weight_trans[0] = 1;weight_trans[1] = 1000000;weight_trans[2] = 1000;weight_trans[3] = 0.001;weight_trans[4] = 2.2046226;weight_trans[5] = 564.3833912;weight_trans[6] = 35.2739619;
		time_trans[0] = 1;time_trans[1] = 60;time_trans[2] = 3600;time_trans[3] = 3600000;time_trans[4] = 0.0416666;
		length_trans[0] = 1;length_trans[1] = 100;length_trans[2] = 0.001;length_trans[3] = 3.2808399;length_trans[4] = 39.3700787;
	}
	double get_trans(int Type, int a) {
		switch (Type) {
		case 1:return weight_trans[a];break;
		case 2:return time_trans[a];break;
		case 3:return length_trans[a];break;
		}
	}
private:
	//代表单位和国际单位的关系 
	double weight_trans[7];
	double time_trans[5];
	double length_trans[5];
};
class num_unit :public unit_trans {
public:
	num_unit(double x, string s1, string s2) {
		num = x;
		ori_unit = s1;
		goa_unit = s2;
		if ("kg" == ori_unit) { type = 1;ori = 0; }
		else if ("mg" == ori_unit) { type = 1;ori = 1; }
		else if ("g" == ori_unit) { type = 1;ori = 2; }
		else if ("t" == ori_unit) { type = 1;ori = 3; }
		else if ("lb" == ori_unit) { type = 1;ori = 4; }
		else if ("dr" == ori_unit) { type = 1;ori = 5; }
		else if ("oz" == ori_unit) { type = 1;ori = 6; }
		else if ("hour" == ori_unit) { type = 2;ori = 0; }
		else if ("minute" == ori_unit) { type = 2;ori = 1; }
		else if ("s" == ori_unit) { type = 2;ori = 2; }
		else if ("ms" == ori_unit) { type = 2;ori = 3; }
		else if ("day" == ori_unit) { type = 2;ori = 4; }
		else if ("m" == ori_unit) { type = 3;ori = 0; }
		else if ("cm" == ori_unit) { type = 3;ori = 1; }
		else if ("km" == ori_unit) { type = 3;ori = 2; }
		else if ("ft" == ori_unit) { type = 3;ori = 3; }
		else if ("in" == ori_unit) { type = 3;ori = 4; }


		if ("kg" == goa_unit) { type = 1;goal = 0; }
		else if ("mg" == goa_unit) { goal = 1; }
		else if ("g" == goa_unit) { goal = 2; }
		else if ("t" == goa_unit) { goal = 3; }
		else if ("lb" == goa_unit) { goal = 4; }
		else if ("dr" == goa_unit) { goal = 5; }
		else if ("oz" == goa_unit) { goal = 6; }
		else if ("hour" == goa_unit) { goal = 0; }
		else if ("minute" == goa_unit) { goal = 1; }
		else if ("s" == goa_unit) { goal = 2; }
		else if ("ms" == goa_unit) { goal = 3; }
		else if ("day" == goa_unit) { goal = 4; }
		else if ("m" == goa_unit) { goal = 0; }
		else if ("cm" == goa_unit) { goal = 1; }
		else if ("km" == goa_unit) { goal = 2; }
		else if ("ft" == goa_unit) { goal = 3; }
		else if ("in" == goa_unit) { goal = 4; }    //发现这样效率太低了   写一个函数来找到标签更好 

	}
	void transfort() {
		num = num / get_trans(type, ori)*get_trans(type, goal);
	}
	double getnum() {
		return num;
	}
	void print() {
		cout << "转换结果：" << num;
	}
private:
	double num;
	string ori_unit;
	string goa_unit;
	int type;
	int ori;
	int goal;       
};
//使用组合类 
class mix_num_unit :public unit_trans {
public:
	mix_num_unit(double Num, int index_len, int index_tim, int index_wei, double a, string s1, string s2, double b, string s3, string s4, double c, string s5, string s6) :len(a, s1, s2), tim(b, s3, s4), wei(c, s5, s6) {
		this->Num = Num;
		this->index_len = index_len;
		this->index_tim = index_tim;
		this->index_wei = index_wei;
	}
	num_unit len;
	num_unit tim;
	num_unit wei;
	double getNum() {
		return Num;
	}
	int getindex_len() {
		return index_len;
	}
	int getindex_tim() {
		return index_tim;
	}
	int getindex_wei() {
		return index_wei;
	}
private:
	double Num;

	int index_len;

	int index_tim;

	int index_wei;
};
int main() {
	cout << "单位转换程序" << endl;
	cout << "可以转化的 单位包括 1国际基本单位类: 长度类：米m 厘米cm 千米km 英尺ft 英寸in" << endl;
	cout << "                                     时间类：毫秒ms 秒s 分钟minute 小时hour 天day" << endl;
	cout << "                                     质量类：克g 吨t 盎司oz 千克kg 毫克mg 磅lb 打兰dr" << endl;
	cout << "                     2非基本单位类:  密度类  千克/立方米kg/m^3 克/立方厘米g/cm^3" << endl;
	cout << "                                     速度类  米/秒m/s 英尺/秒ft/s" << endl;    //这些单位可以有基本单位组合而来 
	cout << "请先选择单位种类";
	cout << "使用示例：" << endl << "    输入：" << endl << "           1       5kg g" << endl << "    输出：" << endl << "         5000g" << endl;
	string s1, s2;
	double num;
	int mark;
	cin >> mark;
	if (mark==1) {
		while (cin >> num >> s1 >> s2) {
			num_unit unit(num, s1, s2);
			unit.transfort();
			unit.print();
		}                                            //len tim wei
	}
	else {
		while (cin >> num >> s1 >> s2) {   
			string A, B, C;
			string a, b, c;
			int AA, BB, CC;
			if (s1 == "kg/m^3") {
				A = "m";
				B = "s";
				C = "kg";
				AA = -3;
				BB = 0;
				CC = 1;
			}
			else if (s1 == "g/cm^3") {
				A = "cm";
				B = "s";
				C = "g";
				AA = -3;
				BB = 0;
				CC = 1;
			}
			else if (s1 == "m/s") {
				A = "m";
				B = "s";
				C = "kg";
				AA = 1;
				BB = -1;
				CC = 0;
			}
			else if (s1 == "kt/s") {
				A = "kt";
				B = "s";
				C = "kg";
				AA = 1;
				BB = -1;
				CC = 0;
			}

			if (s2 == "kg/m^3") {
				a = "m";
				b = "s";
				c = "kg";

			}
			else if (s2 == "g/cm^3") {
				a = "cm";
				b = "s";
				c = "g";

			}
			else if (s2 == "m/s") {
				a = "m";
				b = "s";
				c = "kg";

			}
			else if (s2 == "kt/s") {
				a = "kt";
				b = "s";
				c = "kg";
			} //mix_num_unit(doublt Num,int index_len,int index_tim,int index_wei,double a,string s1,string s2,double b,string s3,string s4,double c,string s5,string s6):len(a,s1,s2),tim(b,s3,s4),wei(c,s5,s6)
			mix_num_unit unit(num, AA, BB, CC, 1.0, A, a, 1.0, B, b, 1.0, C, c);
			unit.len.transfort();
			unit.tim.transfort();
			unit.wei.transfort();
			double N = unit.getNum();
			if (unit.getindex_len()<0) {
				N = N/POW(unit.len.getnum(), -unit.getindex_len());
			}
			else {
				N = N*POW(unit.len.getnum(), unit.getindex_len());
			}
			if (unit.getindex_tim()<0) {
				N = N/POW(unit.tim.getnum(), -unit.getindex_tim());
			}
			else {
				N = N*POW(unit.tim.getnum(), unit.getindex_tim());
			}
			if (unit.getindex_wei()<0) {
				N = N/POW(unit.wei.getnum(), -unit.getindex_wei());
			}
			else {
				N = N*POW(unit.wei.getnum(), unit.getindex_wei());
			}
			cout << N;
		}
	}

	return 0;
}
