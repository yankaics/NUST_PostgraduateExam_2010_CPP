#include<iostream>

using namespace std;

//��Ȱ˻ʺ��㷨 

#define M 100

typedef struct{
	int x;
	int y;
}Point;

int MaxPath,maxTop,nowTop;
Point maxStack[M],nowStack[M];
//MaxPath��¼��ǰ���������ֵ��maxStack��maxTop���ڼ�¼�����ֵ�������ĵ�
//nowStack��nowTop���ڼ�¼��ʱ��·�� 

//�ж���now���Ƿ�������ȥ
//type=1�������ߣ�type=2 ���������� 
bool isOk(int arc[M][M],int n,Point now,int type){
	if(now.y==n-1) return false;
	if(type==2){
		if(now.x==n-1) return false;
	}
	return true;
}

//�ݹ���ݱ���
//now�ǵ�ǰ��λ�� 
void Traver(int arc[M][M],int n,Point now){
	if(!isOk(arc,n,now,1)&&!isOk(arc,n,now,2)){
		//���������Ѿ�����������ȥ�ˣ���Ҫ�������ֵ 
		nowStack[++nowTop]=now;
		int max=0;
		for(int i=0;i<=nowTop;i++){
			max+=arc[nowStack[i].x][nowStack[i].y];
		}
		if(max>MaxPath){
			//ȡ���ֵ����·�� 
			MaxPath=max;
			maxTop=-1;
			for(int i=0;i<=nowTop;i++){
				maxStack[++maxTop]=nowStack[i];
			}
		}
		nowTop--; //����ǰ�ָ���ǰ״̬ 
	} else{
		if(isOk(arc,n,now,1)){
			//���ҿ��ߣ��������� 
			nowStack[++nowTop]=now;
			Point next; next.x=now.x; next.y=now.y+1;
			Traver(arc,n,next);
			nowTop--; //�ָ���������֮ǰ��״̬ 
		}
		if(isOk(arc,n,now,2)){
			//�����¿��ߣ����������� 
			nowStack[++nowTop]=now;
			Point next; next.x=now.x+1; next.y=now.y+1;
			Traver(arc,n,next);
			nowTop--; //�ָ�����������֮ǰ��״̬
		}
	}
}

int main(){
	int n;
	int arc[M][M];
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arc[i][j];
		}
	} 
	MaxPath=0;
	maxTop=nowTop=-1;
	Point now; now.x=now.y=0;
	Traver(arc,n,now);
	cout<<"MaxLength:"<<MaxPath<<endl;
	cout<<"Path:";
	for(int i=0;i<=maxTop;i++){
		cout<<arc[maxStack[i].x][maxStack[i].y]<<"  ";
	} 
	return 0;
} 
