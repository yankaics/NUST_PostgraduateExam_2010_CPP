#include<iostream>


//参考八皇后的回溯法 

using namespace std;

#define M 100 

typedef struct{
	int x,y,flag;
}Node;

int main(){
	Node stack[M];	//用于暂存遍历路径 
	int top=-1;	
	Node stack_Max[M];	//用于存储路径最大的路径
	int mtop=-1;
	int path_Max=0;		//最长路径长度 
	int sou[M][M];
	int size;
	cout<<"请输入斜三角形的高度：";
	cin>>size;
	cout<<"请按行输入斜三角形："<<endl;
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
