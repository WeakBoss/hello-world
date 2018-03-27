#include <iostream>
class Prime {
public:
  Prime(int num);
  ~Prime();

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
  int Get();
private:
   int mNum;
};
Prime::Prime(int num){
  this->mNum=num; 
} 
Prime::~Prime(){
  ;
} 
bool Prime::isPrime(){
  for(int i=2;i<mNum;i++){
     if(mNum%i==0) return false; 
  }
  return true;
}
Prime Prime::sumBit(){
   int sumbit=0;
   int temp=mNum;
   while(temp>0){
     sumbit=sumbit+temp%10;
     temp/=10;
   }
   Prime pre(sumbit);
   return pre; 
}
Prime Prime::multiBit(){
   int multibit=1;
   int temp=mNum;
   while(temp>0){
     multibit=multibit*(temp%10);
	 temp/=10; 
   } 
   Prime pre(multibit);
   return pre; 
} 
Prime Prime::sqaureSumBit(){
   int sqauresumbit=0;
   int temp=mNum;
   while(temp>0){
     sqauresumbit=sqauresumbit+(temp%10)*(temp%10);
	 temp/=10; 
   } 
   Prime pre(sqauresumbit);
   return pre; 
} 
int Prime::Get(){
   return mNum;
} 
int main() {
  for(int i=100;i<=999;i++){ 
  Prime pm(i); 
  Prime sb = pm.sumBit();
  Prime mb = pm.multiBit();
  Prime ssb = pm.sqaureSumBit();
  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
    std::cout<<pm.Get()<<std::endl; //to do sth
}
  return 0;
}
