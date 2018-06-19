//��λת����������ֵ��ԭ��λ���µ�λ�������µ�λ�µ�ֵ��
//������λ��Kg, g, lb, gr,......
//ѹ����λ��Pa, MPa, psi,......
//���ȵ�λ��m, km, ft, in,......
//������λ��md, cp,......
//���кܶ൥λת������Щ��λ��������λ��ϳ�����
#include<iostream>
#include<string>
using namespace std;
class unit_trans{//��λת����ϵ�� 
	public:
		unit_trans(){
			weight_trans[0]=1;weight_trans[1]=1000000;weight_trans[2]=1000;weight_trans[3]=0.001;weight_trans[4]=2.2046226;weight_trans[5]=564.3833912;weight_trans[6]=35.2739619;
			time_trans[0]=1;time_trans[1]=60;time_trans[2]=3600;time_trans[3]=3600000;time_trans[4]=0.0416666;
			length_trans[0]=1;length_trans[1]=100;length_trans[2]=0.001;length_trans[3]=3.2808399;length_trans[4]=39.3700787;
		}
		double get_trans(int Type,int a){
			switch(Type){
				case 1:return weight_trans[a];break;
				case 2:return time_trans[a];break;
				case 3:return length_trans[a];break;
			}
		}
	private:
		//����λ�͹��ʵ�λ�Ĺ�ϵ 
		double weight_trans[7];
		double time_trans[5];
		double length_trans[5];
};
class num_unit:public unit_trans{
	public:
	   num_unit(double x,string s1,string s2){
	   	num=x;
	   	ori_unit=s1;
	   	goa_unit=s2;
	   	if("kg"==ori_unit){type=1;ori=0;}
	   	else if("mg"==ori_unit){type=1;ori=1;}
	   	else if("g"==ori_unit){type=1;ori=2;}
	   	else if("t"==ori_unit){type=1;ori=3;}
	   	else if("lb"==ori_unit){type=1;ori=4;}
	   	else if("dr"==ori_unit){type=1;ori=5;}
	   	else if("oz"==ori_unit){type=1;ori=6;}
	   	else if("hour"==ori_unit){type=2;ori=0;}
	   	else if("minute"==ori_unit){type=2;ori=1;}
	   	else if("s"==ori_unit){type=2;ori=2;}
	   	else if("ms"==ori_unit){type=2;ori=3;}
	   	else if("day"==ori_unit){type=2;ori=4;}
	   	else if("m"==ori_unit){type=3;ori=0;}
	   	else if("cm"==ori_unit){type=3;ori=1;}
	   	else if("km"==ori_unit){type=3;ori=2;}
	   	else if("ft"==ori_unit){type=3;ori=3;}
	   	else if("in"==ori_unit){type=3;ori=4;}
	   	
	   	
	   	if("kg"==goa_unit){type=1;goal=0;}
	   	else if("mg"==goa_unit){goal=1;}
	   	else if("g"==goa_unit){goal=2;}
	   	else if("t"==goa_unit){goal=3;}
	   	else if("lb"==goa_unit){goal=4;}
	   	else if("dr"==goa_unit){goal=5;}
	   	else if("oz"==goa_unit){goal=6;}
	   	else if("hour"==goa_unit){goal=0;}
	   	else if("minute"==goa_unit){goal=1;}
	   	else if("s"==goa_unit){goal=2;}
	   	else if("ms"==goa_unit){goal=3;}
	   	else if("day"==goa_unit){goal=4;}
	   	else if("m"==goa_unit){goal=0;}
	   	else if("cm"==goa_unit){goal=1;}
	   	else if("km"==goa_unit){goal=2;}
	   	else if("ft"==goa_unit){goal=3;}
	   	else if("in"==goa_unit){goal=4;}    //��������Ч��̫���� 
		
	   }
	   void transfort(){
	   	num=num/get_trans(type,ori)*get_trans(type,goal);
	   }
	   void print(){
	   	cout<<num<<goa_unit;
	   }
	private:
	   double num;
	   string ori_unit;
	   string goa_unit;
	   int type;
	   int ori;
	   int goal;
};
int main(){
	cout<<"��λת������"<<endl;
	cout<<"����ת���� ��λ���� �����ࣺ��m ����cm ǧ��km Ӣ��ft Ӣ��in"<<endl;
	cout<<"                    ʱ���ࣺ����ms ��s ����minute Сʱhour ��day"<<endl;
	cout<<"                    �����ࣺ��g ��t ��˾oz ǧ��kg ����mg ��lb ����dr"<<endl;
	cout<<"ʹ��ʾ����"<<endl<<"    ���룺"<<endl<<"         5kg g"<<endl<<"    �����"<<endl<<"         5000g"<<endl;
	string s1,s2;
	double num;
	while(cin>>num>>s1>>s2){
		num_unit unit(num,s1,s2);
		unit.transfort();
		unit.print();
	}
	return 0;
}
