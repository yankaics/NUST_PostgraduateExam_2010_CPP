#include<iostream>

using namespace std;

#define M 100

int main(){
	int a[M],top=-1;
	cout<<"�������飬��-1������";
	int buf;
	cin>>buf;
	while(buf!=-1){
		a[++top]=buf;
		cin>>buf;
	}
	top++;
	cout<<"������λ��λ����";
	int p;
	cin>>p;
	int start=(top-p)%top;
	bool isstart=false;
	cout<<"λ��֮��";
	for(int i=start;!isstart||i!=start;i=(i+1)%top,isstart=true){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
