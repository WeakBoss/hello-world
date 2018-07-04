#include <iostream>
using namespace std;
class A{
	public :
		 void show(){
			cout<<1<<endl;
		}
		void show(int i){
			cout<<2<<endl;
		}	
}; 
class B:public A{
	public:
		void show(int i){
			cout <<3<<endl;
		}
};
int main(){
B b;	A *pa=&b;
	b.show(); 
	
	return 0;
}
