#include <iostream>
using namespace std; 

class Prime {
public:
  Prime(int num):mNum(num){
  	
  }
  
  ~Prime(){
  }

  bool isPrime(){
  	for(int j=2;j<mNum;j++){
  		if(mNum%j==0){
  			return false;
  		}
  		int aa=0;
  	}
  	return true;
  }
private:
  const int mNum;
};

class SuperPrime : public Prime {
public:
  SuperPrime(int num):num(num),Prime(num){

  }
  ~SuperPrime(){
  }

  bool isPrime(){
  	if(sumBit().isPrime()&&multiBit().isPrime()&&sqaureSumBit().isPrime()){
  		return true;
  	}
  	return false;
  }

  Prime sumBit(){
  	int Sum=0,Temp=num;
  	while(Temp!=0){
  		int t_bit=Temp%10;
  		Temp/=10;
  		Sum+=t_bit;
  	}
  	Prime Psum(Sum);
  	return Psum;
  }
  Prime multiBit(){
  	int Mul=1,Temp=num;
  	while(Temp!=0){
  		int t_bit=Temp%10;
  		Temp/=10;
  		Mul*=t_bit;
  	}
  	Prime Pmul(Mul);
  	return Pmul;
  }
  Prime sqaureSumBit(){
  	int Sqr=0,Temp=num;
  	while(Temp!=0){
  		int t_bit=Temp%10;
  		Temp/=10;
  		Sqr+=t_bit*t_bit;
  	}
  	Prime Psqr(Sqr);
  	return Psqr;
  }
private:
  const int num;
};
int main()
{
    SuperPrime sp(113);
    if(sp.isPrime()) {
        cout<<"It is a super prime."<<endl;
    }
}
