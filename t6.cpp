#include<iostream>


//�ο��˻ʺ�Ļ��ݷ� 

using namespace std;

#define M 100 

typedef struct{
	int x,y,flag;
}Node;

int main(){
	Node stack[M];	//�����ݴ����·�� 
	int top=-1;	
	Node stack_Max[M];	//���ڴ洢·������·��
	int mtop=-1;
	int path_Max=0;		//�·������ 
	int sou[M][M];
	int size;
	cout<<"������б�����εĸ߶ȣ�";
	cin>>size;
	cout<<"�밴������б�����Σ�"<<endl;
	for(int i=0;i<size;i++){
		for(int j=i;j<size;j++){
			cin>>sou[i][j];
		}
	}
	for(int i=0;i<size;i++){
		Node no; no.x=0; no.y=i; no.flag=0;
		stack[++top]=no;
		stack_Max[++mtop]=no;
		path_Max+=sou[0][i];
	}
	while(top!=-1){
		Node no=stack[top];
		if(no.y==size-1||no.x==size-1){
			int path=0;
			for(int i=0;i<=top;i++) path+=sou[stack[i].x][stack[i].y];
			if(path>path_Max){
				path_Max=path;
				for(int i=0;i<=top;i++) stack_Max[i]=stack[i];
				mtop=top; 
			} 
			top--;
		}else{
			if
		}
	}
	return 0;
} 
