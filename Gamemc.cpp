#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
string name,place="��ׯ";//������֣���ҵص� 
long long maxhealth=20,health=20,basicattack=2,attack=basicattack,attack2=basicattack,defense=0,money=0,experience=0,level=1,speed=2;//��һ������� 
int credit=50;//����ֵ������޷����� 
int weapon1=0,weapon2=0,tool1=0,tool2=0,attackdis1=2,attackdis2;//������װ�� 
int armor1=0,armor2=0,armor3=0,armor4=0; 
string weapon1name[10]={"����","ľ��","ʯ��","��","����","��ʯ��","�½�Ͻ�"}; 
int weapon1attack[10]={0,4,5,6,7,8};
string weapon2name[10]={"��","��","��"}; 
string tool1name[10]={"��","ľ��","ʯ��","��","����","��ʯ��","�½�Ͻ�"}; 
string tool2name[10]={"��","ľ��","ʯ��","���","����","��ʯ��","�½�Ͻ��"}; 
string armor1name[10]={"��","Ƥ��ͷ��","����ͷ��","��ͷ��","��ͷ��","��ʯͷ��","�½�Ͻ�ͷ��"};
string armor2name[10]={"��","Ƥ���ؼ�","�����ؼ�","���ؼ�","���ؼ�","��ʯ�ؼ�","�½�Ͻ��ؼ�"};
string armor3name[10]={"��","Ƥ�ﻤ��","��������","����","������","��ʯ����","�½�Ͻ���"};
string armor4name[10]={"��","Ƥ��ѥ��","����ѥ��","��ѥ��","��ѥ��","��ʯѥ��","�½�Ͻ�ѥ��"};
int armor1defense[10]={0,1,2,2,3,4,5};
int armor2defense[10]={0,3,4,3,5,7,8};
int armor3defense[10]={0,2,3,3,4,6,7};
int armor4defense[10]={0,1,2,1,3,3,4}; 
//0���� 
bool nether=false,ender=false;//������&ĩ���� ����/���� 
bool dead=false,defend=false,blessing=false;//�������� ����״̬ notchף�� 
bool crafttable=false,furnace=false;//����̨ ��¯ 
bool undeadattack=false;//�������� 
int badguy=0,weaponcheck=0,blesscold=0;
int task1=0;//task1:���м� �ռ�10��ľ 
int choose;//���� 
long long bag[1000]={0,100};//���� 
string itemname[1000]={"","��ľ","����ľ","��Ҷľ","糺����","��ľľ��","����ľľ��","��Ҷľľ��","糺�ľ��","����̨","ľ��","ľ��","ľ��","ľ��","Բʯ","ʯ��","ʯ��","ʯ��","��¯","ú̿","����ʯ","����","����","����","����","��ͷ��","���ؼ�","������","��ѥ��","����","��","���ʯ","��","��","��","���","ƻ��","��ƻ��","��","��ͷ��","���ؼ�","����","��ѥ��"};//��Ʒ�� 
/*��Ʒ��ţ�
1��ľ 2����ľ 3��Ҷľ 4糺���� 5��ľľ�� 6����ľľ�� 7��Ҷľľ�� 8糺�ľ�� 
9����̨ 10ľ�� 11ľ�� 12ľ�� 13ľ�� 14Բʯ 15ʯ�� 16ʯ�� 
17ʯ�� 18��¯ 19ú̿ 20����ʯ 21���� 22���� 23���� 24����
25��ͷ�� 26���ؼ� 27������ 28��ѥ�� 29���� 30�� 31���ʯ 32��
33�� 34�� 35��� 36ƻ�� 37��ƻ�� 38�� 39��ͷ�� 40���ؼ� 
41���� 42��ѥ��  
*/ 
int levelup(int xp){
	if(xp<level*100){
		experience=xp;
		return 0;
	} 
	else{
		xp-=level*100;
		level++;
		return 1+levelup(xp);
	}
}
void create(){//�ϳ� 
	system("cls");
	cout<<"����������Ժϳɵ���Ʒ�б�"<<endl;
	cout<<"����ϳɱ���Ժϳɡ�"<<endl<<endl;
	if(bag[1]>0) cout<<"���"<<5<<": �ϳ� "<<itemname[5]<<"x4 ��Ҫ "<<itemname[1]<<"x1"<<endl; //ľ�� 
	if(bag[2]>0) cout<<"���"<<6<<": �ϳ� "<<itemname[6]<<"x4 ��Ҫ "<<itemname[2]<<"x1"<<endl;
	if(bag[3]>0) cout<<"���"<<7<<": �ϳ� "<<itemname[7]<<"x4 ��Ҫ "<<itemname[3]<<"x1"<<endl;
	if(bag[4]>0) cout<<"���"<<8<<": �ϳ� "<<itemname[8]<<"x4 ��Ҫ "<<itemname[4]<<"x1"<<endl;
	if(bag[5]>3) cout<<"���"<<9<<": �ϳ� "<<itemname[9]<<"x1 ��Ҫ "<<itemname[5]<<"x4"<<endl;//����̨ 
	if(bag[6]>3) cout<<"���"<<9<<": �ϳ� "<<itemname[9]<<"x1 ��Ҫ "<<itemname[6]<<"x4"<<endl;
	if(bag[7]>3) cout<<"���"<<9<<": �ϳ� "<<itemname[9]<<"x1 ��Ҫ "<<itemname[7]<<"x4"<<endl;
	if(bag[8]>3) cout<<"���"<<9<<": �ϳ� "<<itemname[9]<<"x1 ��Ҫ "<<itemname[8]<<"x4"<<endl;
	if(bag[5]>=2) cout<<"���"<<10<<": �ϳ� "<<itemname[10]<<"x4 ��Ҫ "<<itemname[5]<<"x2"<<endl;//ľ�� 
	if(bag[6]>=2) cout<<"���"<<10<<": �ϳ� "<<itemname[10]<<"x4 ��Ҫ "<<itemname[6]<<"x2"<<endl;
	if(bag[7]>=2) cout<<"���"<<10<<": �ϳ� "<<itemname[10]<<"x4 ��Ҫ "<<itemname[7]<<"x2"<<endl;
	if(bag[8]>=2) cout<<"���"<<10<<": �ϳ� "<<itemname[10]<<"x4 ��Ҫ "<<itemname[8]<<"x2"<<endl;
	if(bag[5]>=2&&bag[10]>=1&&crafttable) cout<<"���"<<11<<": �ϳ� "<<itemname[11]<<"x1 ��Ҫ "<<itemname[5]<<"x2,"<<itemname[10]<<"x1"<<endl;//ľ�� 
	if(bag[6]>=2&&bag[10]>=1&&crafttable) cout<<"���"<<11<<": �ϳ� "<<itemname[11]<<"x1 ��Ҫ "<<itemname[6]<<"x2,"<<itemname[10]<<"x1"<<endl;
	if(bag[7]>=2&&bag[10]>=1&&crafttable) cout<<"���"<<11<<": �ϳ� "<<itemname[11]<<"x1 ��Ҫ "<<itemname[7]<<"x2,"<<itemname[10]<<"x1"<<endl;
	if(bag[8]>=2&&bag[10]>=1&&crafttable) cout<<"���"<<11<<": �ϳ� "<<itemname[11]<<"x1 ��Ҫ "<<itemname[8]<<"x2,"<<itemname[10]<<"x1"<<endl;
	if(bag[5]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<12<<": �ϳ� "<<itemname[12]<<"x1 ��Ҫ "<<itemname[5]<<"x3,"<<itemname[10]<<"x2"<<endl;//ľ�� 
	if(bag[6]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<12<<": �ϳ� "<<itemname[12]<<"x1 ��Ҫ "<<itemname[6]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[7]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<12<<": �ϳ� "<<itemname[12]<<"x1 ��Ҫ "<<itemname[7]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[8]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<12<<": �ϳ� "<<itemname[12]<<"x1 ��Ҫ "<<itemname[8]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[5]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<13<<": �ϳ� "<<itemname[13]<<"x1 ��Ҫ "<<itemname[5]<<"x3,"<<itemname[10]<<"x2"<<endl;//ľ�� 
	if(bag[6]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<13<<": �ϳ� "<<itemname[13]<<"x1 ��Ҫ "<<itemname[6]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[7]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<13<<": �ϳ� "<<itemname[13]<<"x1 ��Ҫ "<<itemname[7]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[8]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<13<<": �ϳ� "<<itemname[13]<<"x1 ��Ҫ "<<itemname[8]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[14]>=2&&bag[10]>=1&&crafttable) cout<<"���"<<15<<": �ϳ� "<<itemname[15]<<"x1 ��Ҫ "<<itemname[14]<<"x2,"<<itemname[10]<<"x1"<<endl;//ʯ�� 
	if(bag[14]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<16<<": �ϳ� "<<itemname[16]<<"x1 ��Ҫ "<<itemname[14]<<"x3,"<<itemname[10]<<"x2"<<endl;//ʯ�� 
	if(bag[14]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<17<<": �ϳ� "<<itemname[17]<<"x1 ��Ҫ "<<itemname[14]<<"x3,"<<itemname[10]<<"x2"<<endl;//ʯ�� 
	if(bag[14]>=8&&crafttable) cout<<"���"<<18<<": �ϳ�"<<itemname[18]<<"x1 ��Ҫ"<<itemname[14]<<"x8"<<endl;//��¯ 
	if(bag[19]>=1&&bag[20]>=1&&furnace) cout<<"���"<<21<<": ����"<<itemname[21]<<"x1 ��Ҫ"<<itemname[19]<<"x1,"<<itemname[20]<<"x1"<<endl;//���� 
	if(bag[21]>=2&&bag[10]>=1&&crafttable) cout<<"���"<<22<<": �ϳ� "<<itemname[22]<<"x1 ��Ҫ "<<itemname[21]<<"x2,"<<itemname[10]<<"x1"<<endl;//���� 
	if(bag[21]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<23<<": �ϳ� "<<itemname[23]<<"x1 ��Ҫ "<<itemname[21]<<"x3,"<<itemname[10]<<"x2"<<endl;//���� 
	if(bag[21]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<24<<": �ϳ� "<<itemname[24]<<"x1 ��Ҫ "<<itemname[21]<<"x3,"<<itemname[10]<<"x2"<<endl;//���� 
	if(bag[21]>=5&&crafttable) cout<<"���"<<25<<": �ϳ� "<<itemname[25]<<"x1 ��Ҫ "<<itemname[21]<<"x5"<<endl;//��ͷ�� 
	if(bag[21]>=8&&crafttable) cout<<"���"<<26<<": �ϳ� "<<itemname[26]<<"x1 ��Ҫ "<<itemname[21]<<"x8"<<endl;//���ؼ� 
	if(bag[21]>=7&&crafttable) cout<<"���"<<27<<": �ϳ� "<<itemname[27]<<"x1 ��Ҫ "<<itemname[21]<<"x7"<<endl;//������ 
	if(bag[21]>=4&&crafttable) cout<<"���"<<28<<": �ϳ� "<<itemname[28]<<"x1 ��Ҫ "<<itemname[21]<<"x4"<<endl;//��ѥ�� 
	if(bag[5]>=6&&bag[21]>=1&&crafttable) cout<<"���"<<29<<": �ϳ� "<<itemname[29]<<"x1 ��Ҫ "<<itemname[21]<<"x1,"<<itemname[5]<<"x6"<<endl;//���� 
	if(bag[6]>=6&&bag[21]>=1&&crafttable) cout<<"���"<<29<<": �ϳ� "<<itemname[29]<<"x1 ��Ҫ "<<itemname[21]<<"x1,"<<itemname[6]<<"x6"<<endl;
	if(bag[7]>=6&&bag[21]>=1&&crafttable) cout<<"���"<<29<<": �ϳ� "<<itemname[29]<<"x1 ��Ҫ "<<itemname[21]<<"x1,"<<itemname[7]<<"x6"<<endl;
	if(bag[8]>=6&&bag[21]>=1&&crafttable) cout<<"���"<<29<<": �ϳ� "<<itemname[29]<<"x1 ��Ҫ "<<itemname[21]<<"x1,"<<itemname[8]<<"x6"<<endl;
	if(bag[38]>=3&&bag[10]>=3&&crafttable) cout<<"���"<<30<<": �ϳ� "<<itemname[30]<<"x1 ��Ҫ "<<itemname[38]<<"x3,"<<itemname[10]<<"x3"<<endl;//���� 
	if(bag[19]>=1&&bag[31]>=1&&furnace) cout<<"���"<<32<<": ����"<<itemname[32]<<"x1 ��Ҫ"<<itemname[19]<<"x1,"<<itemname[31]<<"x1"<<endl;//�� 
	if(bag[32]>=2&&bag[10]>=1&&crafttable) cout<<"���"<<33<<": �ϳ� "<<itemname[33]<<"x1 ��Ҫ "<<itemname[32]<<"x2,"<<itemname[10]<<"x1"<<endl;//�� 
	if(bag[32]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<34<<": �ϳ� "<<itemname[34]<<"x1 ��Ҫ "<<itemname[32]<<"x3,"<<itemname[10]<<"x2"<<endl;//�� 
	if(bag[32]>=3&&bag[10]>=2&&crafttable) cout<<"���"<<35<<": �ϳ� "<<itemname[35]<<"x1 ��Ҫ "<<itemname[32]<<"x3,"<<itemname[10]<<"x2"<<endl;//���
	if(bag[32]>=8&&bag[36]>=1&&crafttable) cout<<"���"<<37<<": �ϳ� "<<itemname[37]<<"x1 ��Ҫ "<<itemname[32]<<"x8,"<<itemname[36]<<"x1"<<endl;//��ƻ�� 
	if(bag[32]>=5&&crafttable) cout<<"���"<<39<<": �ϳ� "<<itemname[39]<<"x1 ��Ҫ "<<itemname[32]<<"x5"<<endl;//��ͷ�� 
	if(bag[32]>=8&&crafttable) cout<<"���"<<40<<": �ϳ� "<<itemname[40]<<"x1 ��Ҫ "<<itemname[32]<<"x8"<<endl;//���ؼ� 
	if(bag[32]>=7&&crafttable) cout<<"���"<<41<<": �ϳ� "<<itemname[41]<<"x1 ��Ҫ "<<itemname[32]<<"x7"<<endl;//���� 
	if(bag[32]>=4&&crafttable) cout<<"���"<<42<<": �ϳ� "<<itemname[42]<<"x1 ��Ҫ "<<itemname[32]<<"x4"<<endl;//��ѥ��	
	cout<<endl<<"����0����"<<endl;
	cin>>choose;
	switch(choose){
		case 0:
			return;	
		break;
		case 5://��ľľ�� 
			if(bag[1]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[1]--;
			bag[5]+=4;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;	
		case 6://����ľľ�� 
			if(bag[2]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[2]--;
			bag[6]+=4;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 7://��Ҷľľ�� 
			if(bag[3]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[3]--;
			bag[7]+=4;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 8://糺�ľ�� 
			if(bag[4]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[4]--;
			bag[8]+=4;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 9://����̨ craft(ing)table 
			if(bag[5]>=4) cout<<"1��ʹ����ľľ��ϳ�";
			if(bag[6]>=4)" 2������ľľ��";
			if(bag[7]>=4)" 3����Ҷľľ��";
			if(bag[8]>=4)" 4��糺�ľ��";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<4){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=4;
					bag[9]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<4){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=4;
					bag[9]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<4){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=4;
					bag[9]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<4){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=4;
					bag[9]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;	
		case 10://ľ�� 
			if(bag[5]>=2) cout<<"1��ʹ����ľľ��ϳ�";
			if(bag[6]>=2)" 2������ľľ��";
			if(bag[7]>=2)" 3����Ҷľľ��";
			if(bag[8]>=2)" 4��糺�ľ��";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<2){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=2;
					bag[10]+=4;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<2){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=2;
					bag[10]+=4;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<2){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=2;
					bag[10]+=4;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<2){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=2;
					bag[10]+=4;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;
		case 11://ľ�� 
			if(bag[10]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			if(bag[5]>=2) cout<<"1��ʹ����ľľ��ϳ�";
			if(bag[6]>=2)" 2������ľľ��";
			if(bag[7]>=2)" 3����Ҷľľ��";
			if(bag[8]>=2)" 4��糺�ľ��";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<2){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<2){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<2){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<2){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;
		case 12://ľ�� 
			if(bag[10]<2){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			if(bag[5]>=3) cout<<"1��ʹ����ľľ��ϳ�";
			if(bag[6]>=3)" 2������ľľ��";
			if(bag[7]>=3)" 3����Ҷľľ��";
			if(bag[8]>=3)" 4��糺�ľ��";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<3){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=3;
					bag[10]-=2;
					bag[12]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<3){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=3;
					bag[10]-=2;
					bag[12]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<3){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=3;
					bag[10]-=2;
					bag[12]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<3){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=3;
					bag[10]-=2;
					bag[12]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;
		case 13://ľ�� 
			if(bag[10]<2){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			if(bag[5]>=3) cout<<"1��ʹ����ľľ��ϳ�";
			if(bag[6]>=3)" 2������ľľ��";
			if(bag[7]>=3)" 3����Ҷľľ��";
			if(bag[8]>=3)" 4��糺�ľ��";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<3){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=3;
					bag[10]-=2;
					bag[13]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<3){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=3;
					bag[10]-=2;
					bag[13]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<3){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=3;
					bag[10]-=2;
					bag[13]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<3){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=3;
					bag[10]-=2;
					bag[13]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;
		case 15://ʯ�� 
			if(bag[14]<2||bag[10]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[14]-=2;
			bag[10]-=1;
			bag[15]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 16://ʯ�� 
			if(bag[14]<3||bag[10]<2){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[14]-=3;
			bag[10]-=2;
			bag[16]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 17://ʯ�� 
			if(bag[14]<3||bag[10]<2){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[14]-=3;
			bag[10]-=2;
			bag[17]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 18://��¯furnace 
			if(bag[14]<8){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[14]-=8;
			bag[18]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 21://���� 
			if(bag[19]<1||bag[20]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[19]-=1;
			bag[20]-=1;
			bag[21]+=1;
			cout<<"�����ɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 22://���� 
			if(bag[21]<2||bag[10]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=1;
			bag[21]-=2;
			bag[22]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 23://���� 
			if(bag[21]<3||bag[10]<2){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=2;
			bag[21]-=3;
			bag[23]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 24://���� 
			if(bag[21]<3||bag[10]<2){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=2;
			bag[21]-=3;
			bag[24]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 25://��ͷ�� 
			if(bag[21]<5){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[21]-=5;
			bag[25]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 26://���ؼ� 
			if(bag[21]<8){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[21]-=8;
			bag[27]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 27://������ 
			if(bag[21]<7){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[21]-=7;
			bag[27]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 28://��ѥ�� 
			if(bag[21]<4){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[21]-=4;
			bag[28]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 29://���� 
			if(bag[21]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			if(bag[5]>=6) cout<<"1��ʹ����ľľ��ϳ�";
			if(bag[6]>=6)" 2������ľľ��";
			if(bag[7]>=6)" 3����Ҷľľ��";
			if(bag[8]>=6)" 4��糺�ľ��";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<6){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=6;
					bag[21]-=1;
					bag[29]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<6){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=6;
					bag[21]-=1;
					bag[29]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<6){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=6;
					bag[21]-=1;
					bag[29]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<6){
						cout<<"�������䣡"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=6;
					bag[21]-=1;
					bag[29]+=1;
					cout<<"�ϳɳɹ���"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;
		case 30://�� 
			if(bag[38]<3||bag[10]<3){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=3;
			bag[38]-=3;
			bag[30]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 32://�� 
			if(bag[19]<1||bag[31]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[19]-=1;
			bag[31]-=1;
			bag[32]+=1;
			cout<<"�����ɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 33://�� 
			if(bag[32]<2||bag[10]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=1;
			bag[32]-=2;
			bag[33]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 34://�� 
			if(bag[32]<3||bag[10]<2){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=2;
			bag[32]-=3;
			bag[34]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 35://��� 
			if(bag[32]<3||bag[10]<2){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=2;
			bag[32]-=3;
			bag[35]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 37://��ƻ�� 
			if(bag[32]<8||bag[36]<1){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[36]-=1;
			bag[32]-=8;
			bag[37]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 39://��ͷ�� 
			if(bag[32]<5){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[32]-=5;
			bag[39]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 40://���ؼ� 
			if(bag[32]<8){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[32]-=8;
			bag[39]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 41://���� 
			if(bag[32]<7){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[32]-=7;
			bag[39]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
		case 42://��ѥ�� 
			if(bag[32]<4){
				cout<<"�������䣡"<<endl;
				Sleep(1000);
				create();
			}
			bag[32]-=4;
			bag[39]+=1;
			cout<<"�ϳɳɹ���"<<endl;
			Sleep(1000);
			create();
		break;
	}
} 
void fight(string MN,int MH,int MA,int Mrand,int MD,int MS,int dis,int Adis,int xp,int Mmoney){//ս�� ������ �������� ������С���� ����ֵ ���˷��� �����ٶ� ��ǰ���� ���˹������� ����ֵ �̱�ʯ 
	bool back=true;
	system("cls");
	while(!dead){
		cout<<"���Ѫ����"<<health<<"/"<<maxhealth<<"��"<<"   "<<"����Ѫ���� "<<MH<<endl;
		cout<<"������"<<attack<<endl;
		cout<<"������"<<defense<<endl;
		cout<<"�ٶȣ�"<<speed<<endl;
		cout<<"��ǰ��͵��˵ľ���Ϊ"<<dis<<endl<<endl;
		cout<<"��������Ļغϣ�"<<endl;
		cout<<"��Ҫ��"<<endl;
		cout<<"1��������ʹ�õ�ǰ����������  2��ʹ�ø���װ��  3��ʹ��ҩˮ  4���򿪱���  5������  6���ƶ�"<<endl;
		cin>>choose;
		switch(choose){
			case 1:
				if(dis<=attackdis1){
					cout<<"��ʹ�� "<<weapon1name[weapon1]<<" �� "<<MN<<" ���й�����"<<endl;
					Sleep(1000);
					int damage=attack*(100+rand()%20-rand()%20)/100*(100-MD)/100; //�����˺� 
					cout<<MN<<" �ܵ��� "<<damage<<" ���˺���" <<endl;
					MH-=damage;
					Sleep(1000);
					cout<<"��ǰ "<<MN<<" ���� "<<MH<<" ������ֵ��" <<endl;    
					Sleep(1500);         
					system("cls");
				}else{
					cout<<"����̫Զ���޷�������"<<endl;	
					Sleep(2000);
					cout<<"�������˱��غ�"<<endl;
					Sleep(2000); 
					system("cls");
				} 
			break;
			case 2:
				if(weapon2==0){
					cout<<"����δװ��������" <<endl;
					Sleep(2000);
					cout<<"�������˱��غ�"<<endl;
					Sleep(2000); 
					system("cls");
				}
				if(weapon2==1){//�� 
					if(dis<=attackdis2){
						cout<<"��ʹ�� "<<weapon2name[weapon2]<<" �� "<<MN<<" ���й�����"<<endl;
						Sleep(1000);
						int damage=attack2*(100+rand()%20-rand()%20)/100*(100-MD)/100; //�����˺� 
						MH-=damage;
						cout<<MN<<" �ܵ��� "<<damage<<" ���˺���" <<endl;
						Sleep(1000);
						cout<<"��ǰ "<<MN<<" ���� "<<MH<<" ������ֵ��" <<endl;    
						Sleep(1500);         
						system("cls");
					}else{
						cout<<"����̫Զ���޷�������"<<endl;
						Sleep(2000);
						cout<<"�������˱��غ�"<<endl;
						Sleep(2000); 
						system("cls");
					}
				}
				if(weapon2==2){
					cout<<"�������ƣ��´��ܵ��˺�ʱ��ķ���������ӣ�"<<endl;//���� 
					defend=true;//����״̬ 
					defense+=20;
				}
			break;	
			case 3:
			break;
			case 4:
			break;
			case 5:
			break;	
			case 6:
				cout<<"1����ǰ�ƶ� 2������ƶ�"<<endl;//�ƶ� 
				cin>>choose;
				switch(choose){
					case 1:
						cout<<"�ƶ����ٸ�"<<endl;
						cin>>choose;
						if(choose<=speed){
							if(dis>=choose) dis-=choose;
							else dis=0;
						}
						cout<<name<<" �� "<<MN<<" �ƽ��ˣ�"<<endl;
						Sleep(1000);
						cout<<"��ǰ��͵��˵ľ���Ϊ"<<dis<<endl;
						Sleep(1500);
						system("cls");
					break;
					case 2:
						cout<<"�ƶ����ٸ�"<<endl;
						cin>>choose;
						if(choose<=speed) dis+=choose;
						cout<<name<<" �����ˣ�"<<endl;
						Sleep(1000);
						cout<<"��ǰ��͵��˵ľ���Ϊ"<<dis<<endl;
						Sleep(1500);
						system("cls");
					break;
				}
			break;
		} 
		if(MH<=0){
			cout<<MN<<" ս�ܣ�"<<endl;//�ҷ�ʤ�� 
			Sleep(1500);
			cout<<"��ʤ���ˣ�"<<endl;
			Sleep(1000);
			cout<<"��þ��� "<<xp<<" ��"<<endl; 
			experience+=xp;
			Sleep(1000);
			cout<<"������ "<<levelup(experience)<<" ����"<<endl;
			level+=levelup(experience);
			Sleep(500);
			cout<<"��ǰ�ȼ���"<<level<<endl;
         	dead=true;
			Sleep(1000);
			cout<<"���� "<<Mmoney<<" ���̱�ʯ"<<endl;
			money+=Mmoney;
			Sleep(2000);
			system("cls");
			return;
		}
		cout<<"���Ѫ����"<<health<<"/"<<maxhealth<<"��"<<"   "<<"����Ѫ���� "<<MH<<endl;//���˻غ� 
		cout<<"������"<<attack<<endl;
		cout<<"������"<<defense<<endl;
		cout<<"�ٶȣ�"<<speed<<endl;
		cout<<"��ǰ��͵��˵ľ���Ϊ"<<dis<<endl<<endl;
		cout<<MN<<" �Ļغϣ�"<<endl; 
		if(Adis<5){//��ս����AI 
			if(dis<=Adis){
				cout<<MN<<" �� "<<name<<" ���й�����"<<endl; 
				Sleep(1000);
				int damage;
				if(defend){
					defend=false;
					damage=(MA+rand()%Mrand)*(100+rand()%20-rand()%20)*(100-defense-40)/10000; 
				}else damage=damage=(MA+rand()%Mrand)*(100+rand()%20-rand()%20)*(100-defense)/10000;//�����˺� 
				health-=damage;
				cout<<"���ܵ��� "<<damage<<" ���˺���"<<endl;
				Sleep(1000);
				cout<<"�㻹ʣ "<<health<<" ��������"<<endl;
				Sleep(1500);
				system("cls");	
			}else{
				if(dis>=MS) dis-=MS;
				else dis=0;
				cout<<MN<<" �� "<<name<<" �ƽ��ˣ�"<<endl;
				Sleep(1000);
				cout<<"��ǰ��͵��˵ľ���Ϊ"<<dis<<endl;
				Sleep(1500);
				system("cls");
			}	
		}else{//Զ�̹���AI 
			if(dis<=Adis/3&&back==true){//����Ҿ���С��1/3�������룬���� 
				dis+=MS;
				cout<<MN<<" �����ˣ�"<<endl;
				Sleep(1000);
				cout<<"��ǰ��͵��˵ľ���Ϊ"<<dis<<endl;
				Sleep(1500);
				system("cls");
				back=false;	
			}else{
				back=true;
				if(dis>Adis){//�����Զ��ǰ�� 
					if(dis-=MS>=0) dis-=MS;
					else dis=0;
					cout<<MN<<" �� "<<name<<" �ƽ��ˣ�"<<endl;
					Sleep(1000);
					cout<<"��ǰ��͵��˵ľ���Ϊ"<<dis<<endl;
					Sleep(1500);
					system("cls");
				}else{//����Ҿ����ʺϣ����� 
					cout<<MN<<" �� "<<name<<" ���й�����"<<endl;
					Sleep(1000);
					int damage;
					if(defend){
						defend=false;
						damage=(MA+rand()%Mrand)*(100+rand()%20-rand()%20)*(100-defense-40)/10000;  
					}else damage=(MA+rand()%Mrand)*(100+rand()%20-rand()%20)*(100-defense)/10000;//�����˺�
					health-=damage;
					cout<<"���ܵ��� "<<damage<<" ���˺���"<<endl;
					Sleep(1000);
					cout<<"�㻹ʣ "<<health<<" ��������"<<endl;
					Sleep(1500);
					system("cls");
				}	
			}
		}
		if(health<=0){
			if(blessing){//ף�������� ����1/4Ѫ 
				cout<<"Notch֮ף����Ч��"<<endl;
				Sleep(2000);
				health=0;
				health+=maxhealth/4;
				blessing=false;
				cout<<"��ظ�25%����ֵ������ս����"<<endl; 
				Sleep(2000);
				system("cls");
			}else{
				cout<<"�����ˣ�"<<endl;
				place="��ׯ"; 
				Sleep(3000);
				health=2;
				system("cls");
			return;
			}
		}
	}
	return;	
}
void shop(string place){//�̵� 
	if(place=="��ׯ"){
		cout<<"��ӭ������ׯ�̵꣡"<<endl;
		Sleep(500);
		cout<<"������Ҫ��ʲô��"<<endl; 
		cout<<"(��ǰ����"<<money<<"���̱�ʯ)"<<endl;
		cout<<"0���뿪  1������  2������  3��ҩˮ"<<endl; 
		cin>>choose;
		switch(choose){
			case 0:
				return;
			break;
			case 1:
				cout<<"ľ��-�۸�3�̱�ʯ \n";
				cout<<"ʯ��-�۸�8�̱�ʯ \n";	
		} 
	}
}
void explore(string place){//̽�� 
	if(place=="��ׯ"){		
		switch(rand()%10){
			case 0:
			cout<<"�������������ܣ�"<<endl;
			cout<<"0���뿪  1����ŭ"<<endl;
			cin>>choose;
			if(choose==1){
				fight("������",100,8,6,40,2,10,3,500,5);
				credit-=20;
				if(dead){
					dead=false;
					cout<<"��� 2 ��������"<<endl;
					bag[21]+=2;
				}
			}else{
				cout<<"��Զ����������"<<endl; 
				Sleep(1000);
				break;
			}
			break;
			case 1:
			if(badguy==0){
				cout<<"�㿴����һ����������۸�һ������..."<<endl;
				cout<<"1����ֹ  2���뿪  3��һ���۸�"<<endl;
				cin>>choose;
				if(choose==1){
					cout<<"ս����"<<endl;
					Sleep(2000);
					fight("��Դ���",20,1,1,0,2,5,2,100,1);
					if(dead){
						credit+=5;
						dead=false;
						Sleep(2000);
						cout<<"���ߵ����������ǰ��˵��"<<endl;
						Sleep(2000);
						cout<<"�Ժ�Ҫ���۸������ˣ�"<<endl;
						Sleep(2000);
						cout<<"��Կ�����һ�ۣ������������"<<endl;
						badguy=2;
						Sleep(2000);
						cout<<"���۸��Ĵ���ʮ�ָм���������3���̱�ʯ"<<endl;
              		 	money+=3;      
						Sleep(3000);
					}else{
						credit-=5;
						cout<<"����ߵ�����ǰ���������������ˣ����������Ϊ��"<<endl;
						Sleep(2000);
						cout<<"���Ҿͳ�ȫ�㣬����Ǯ�Ҳ�Ҫ�ˣ����Ǯ���ң�����"<<endl;
						Sleep(2000);
						money=0;
						cout<<"���Ǯ�����ȫ��������..."<<endl; 
						Sleep(2000);
					}
				}else{
					if(choose==2){
						cout<<"��ĬĬ�߿��ˡ�"<<endl;
						Sleep(2000);
						credit-=15;
					}else{
						cout<<"����ȥ���ƿ��˶�ԣ��Լ����ߴ����������е��̱�ʯ��"<<endl;
						money+=6;
						Sleep(1500);
						cout<<"�����6���̱�ʯ��"<<endl;
						credit-=25;
						badguy=1;
						Sleep(2000);
					}
				}
			}else if(badguy==2){
				cout<<"����������֮ǰ�۸��˵Ĵ���"<<endl;
				Sleep(1500);
				cout<<"��λ��������㣬ѩ����һ�����񷢲�����������˾��з��Ľ�Ʒ"<<endl;
				Sleep(2000);
				cout<<"����ǰ����������2���̱�ʯ"<<endl;
				money+=2;
				badguy=3;
				Sleep(2000);
			}
			break;	
			case 2:
				cout<<"���ڵ��Ϸ�����1���̱�ʯ��"<<endl;
				money+=1;
				Sleep(2000);	
			break;
			case 3:
				cout<<"�������˴�ׯ�ù�"<<endl;
				Sleep(1000);
				cout<<"0���뿪  1������"<<endl;
				cin>>choose;
				if(choose==1){
					if(credit<=30){
						cout<<"��ս�ȥ�����и��˺������Ǹ����ˣ�"<<endl;
						Sleep(2000);
						cout<<"������˿����㣬��æ����ϳ�ȥ"<<endl;
						Sleep(2000);
						cout<<"���������㣬˵���㲻��ס�ҵ��ùݣ�"<<endl;
                 Sleep(2000);     
					}else{
						cout<<"���߽��ù�"<<endl;
						Sleep(2000);
						cout<<"��ǰ���� "<<money<<" ���̱�ʯ"<<endl; 
						cout<<"Ҫ��Ϣ����Ҫ5���̱�ʯ����Ϣ�ɻָ�����ֵ��"<<endl;
						cout<<"0���뿪  1����Ϣ"<<endl;
						cin>>choose;
						if(choose==1){
							if(money<5){
								cout<<"��ͻȻ�����Լ���Ǯ��������ֻ�����ε�����"<<endl;
								Sleep(2000);
								credit-=10;
							}else{
								system("cls");
								cout<<"�������㿪��һ�䷿����������������˯��һ��..."<<endl;
								money-=5;
								Sleep(1000);
								health=maxhealth;
								cout<<"zzzZZZ"<<endl;
								Sleep(5000);
							} 
						}
					}
				}
			break;	
			case 4:
				cout<<"�������˴�ׯ�е¸����ص�����-ͼ�����Ա"<<endl; 
				Sleep(1000);
				cout<<"��λ����֪����������ϵ���������..."<<endl<<endl;
				Sleep(1500);
				if(credit<=30){
					cout<<"ͼ�����Աֻ������ɨ�ӹ������ϣ���͸о����ķ·�������һ��"<<endl;
					Sleep(1500);
					cout<<"��о������������ļ���..."<<endl;
					Sleep(1500);
					cout<<"���㶼����ʲô��û���˱�����������ʹ��������С��Ҳ��Ը����Ԯ������������ΪŰ...��"<<endl;
					Sleep(1500);
					cout<<"��̼䣬ͼ�����Ա����ʧ�����������..."<<endl;
					Sleep(2000); 
				}else{
					cout<<"��Ҫ��ͼ�����Ա��̸�𣿣�0���뿪  1����̸��"<<endl;
					cin>>choose;
					if(choose==1){
						cout<<"��Ҫѯ��ʲô��"<<endl;
						cout<<"1������Զ��ʱ�ڵ�ս��"<<endl;
						cout<<"2��Herobrine����ͽ/����"<<endl;
						cout<<"3��Herobrine�����Ĵ���"<<endl;
						cout<<"4�����ڴ���֮��"<<endl;
						cout<<"5��������������"<<endl; 
						cout<<"6�����ڵ���"<<endl;
						cout<<"7������ĩ��"<<endl;
						cin>>choose;
						switch(choose){
							case 1:
								system("cls");
								Sleep(2000); 
								cout<<"��Զ��ʱ�ڣ�Ҳ�����������ձ��������ʱ������������λ��Ҳ����Notch��Herobrine��������λ�����ֵܡ�"<<endl; 
								cout<<"��Herobrine���������������������𽥲��ͣ��������ǵĹ�ϵ�ֱ�������"<<endl;
								cout<<"Notch����Herobrine�������棬��Herobrine��������������������һ֧������----"<<endl;
								cout<<"��֧�������Ĵ�ǰ��������֮��Ѫ���ɺӣ�ʬ�Ǳ��..."<<endl;
								cout<<"Notch���ŷ�����������Ϳ̿��������ֹHerobrine���������ս���ĵ�����..."<<endl;
								cout<<"����������Խ���ȥ������ת��Ϊ���飬��ʱ������ֻ���Ĵ�������"<<endl;
								cout<<"Notchʹ���˴����ġ� ����֮�����ųɹ������һ�󲿷ֵ����飬�����в���������һ���������"<<endl;
								cout<<"����Notch�Ѿ�û���㹻�������Ը�Herobrine�ˣ���ֻ���ó�ʣ��ġ� ����֮��������Herobrine��ӡ���˵���..."<<endl;
								cout<<"���ǣ��ƺ�Herobrine���������������ƿ���ӡ..."<<endl<<endl;
								cout<<"ͼ�����Ա̾�˿�����"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								}     
							break;
							case 2:
								system("cls");
								Sleep(2000); 
								cout<<"���ڴ������ڣ�Herobrine��չʾ���������ĸ���Ȼ��ͬ���Ը�"<<endl; 
								cout<<"���ŵ�������Լ��������������ף������統���Լ�����Ϸ��"<<endl;
								cout<<"���ڣ�Herobrine����������Щ̫��������顣"<<endl;
								cout<<"������ʱ�����ƣ�HerobrineԽ��Խ��������ʼ��������ؽ����Լ���������"<<endl;
								cout<<"�����Լ��ġ� ����֮���������鴴�����һ����һ��������ʵ���¡�"<<endl;
								cout<<"����������ƾ�����Լ�ǿ����������շ���������ص�һ����ǿ�ߣ������Լ�������ʹ���Ǳ�ø�ǿ��"<<endl;
								cout<<"��Herobrine����Ҳ������������һЩ�Լ�����Ӱ����Щ��Ӱ������Herobrine����ʵ�����б����ǧ��֮һ��"<<endl;
								cout<<"�� NULL���־�ħ����Entity_303��...����Herobrine��ʵ�����¡�"<<endl;
								cout<<"�����������������������е�������Herobrine�ܿ��ܽ����ƿ���ӡ���ػ�����..."<<endl<<endl;
								cout<<"ͼ�����Ա����ɫ������ء�"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 3: 
								system("cls");
								Sleep(2000); 
								cout<<"Herobrine�Ĺ���..."<<endl; 
								cout<<"�ⲻ��ҥ�ԣ�Ҳ��ܿ�ͻᷢ��...������Notch�Ѳ�֪���٣������Ŀ־�ħ���Ѿ������������ǣ�Herobrine�ܿ��ܻ��ƿ���ӡ��"<<endl;
								cout<<"��ңԶ�ı߾�֮�أ��������Ŵ���֮�������֮�������汻�����һ�¸�ǽ��һ�����ﶼ��û��ҡ�"<<endl;
								cout<<"��Null�����ڱ߾�֮��..."<<endl;
								cout<<"Herobrine�������������ؽ��᲻ϧ���д��ۣ�ǿ�д���Herobrine�ķ�ӡ..."<<endl;
								cout<<"ͼ�����Ա����ɫ������ء�"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 4:
								system("cls");
								Sleep(2000); 
								cout<<"����֮��������Notch��ӵ�е�������"<<endl; 
								cout<<"��������ӵ���Ŵ��������������⣬��ǿ���������"<<endl;
								cout<<"Herobrine��ӵ�еģ����ǻ���֮������Notch�෴���������ƻ������ȶ��ԡ�"<<endl;
								cout<<"���ǵ���Notch��Herobrine���֣������˴����������Ŵ������������硣"<<endl;
								cout<<"��Ҳֻ�д���֮�������ܿ���Herobrine�Ļ���֮����"<<endl;
								cout<<"��Notch�ڴ�ս�����ʧ���ټ�������֮��Ҳ��֪��������..."<<endl;
								cout<<"ͼ�����Ա����ɫ������ء�"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 5:
								system("cls");
								Sleep(2000); 
								cout<<"���������Herobrine������֮�������֮��������ġ�"<<endl; 
								cout<<"����������Խ���ȥ������ת������顣"<<endl;
								cout<<"Ҳ����˵��ͨ��������Ĵ����ɣ���Ⱦ���������׵����һ֧��������"<<endl;
								cout<<"��Herobrine����ƾ���������Ӵ��������ӣ��ŵ�����Notch���⡣"<<endl;
								cout<<"Herobrine�������Ĺ�����������������쵼��Blackbone��֯������������..."<<endl;
								cout<<"����Notchӵ�д���֮������Ҳ�޷����׳������顣"<<endl;
								cout<<"���⽫��һ����������в����ͼ�����Ա����ɫ������ء�"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 	
							break;	
							case 6:
								system("cls");
								Sleep(2000); 
								cout<<"������һ��������ҽ������ҵĵط�����˵Ҳ�Ƿ�ӡHerobrine�ĵط�..."<<endl; 
								cout<<"����Σ�����أ�Ҫʱ��С�ĵ����ҽ�����Ҫ������µĶ�꣬�ҽ���"<<endl;
								cout<<"���ڵ����У���һ�����������--���顣"<<endl;
								cout<<"������һ��̰�Ƶ���������ǽ𶧱��������ǽ��ף�����ȴ����֪���Լ��ܵõ�ʲô��"<<endl;
								cout<<"���������������һ���ؽ��������½�Ͻ���Щ�Ͻ���Ҫ�ڵ�������ھ��Ӳ��Զ�Ųк��������ɡ�"<<endl;
								cout<<"���⣬�����л�������һЩ����ı��ݣ��Լ��½�Ҫ������Щ�ط������������ı��أ��Լ�--�����Σ����"<<endl;
								cout<<"ͼ�����Ա��̾�˿�����"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 7:
								system("cls");
								Sleep(2000); 
								cout<<"ĩ�أ�һ��λ����յ���һά�ȡ�"<<endl; 
								cout<<"���ﴣ���ż�������ʯ������ĩ�ص������ϻ���һ��������"<<endl;
								cout<<"��ĩ����Ĵ������ĩӰ�ˡ������ĩӰ�˶�����ʱ�շ�϶�в�С�Ĵ�Խ�����ġ�"<<endl;
								cout<<"���ĩӰ���󣬾Ϳ���ǰ��ĩ�ص��⵺�ˡ��⵺��ɢ����һЩĩ�سǣ���Щ�������������౦�ء�"<<endl;
								cout<<"��Ҫ���ĩӰ���ɲ����ף�����ʯ���ϵ�ĩӰˮ����ΪĩӰ�������ָ�������"<<endl;
								cout<<"������Ҫǰ��ĩ�أ�����Ҫ�ҵ�������ĩ�ص���Ծ���ӿڣ�����˵�ڵ���������һ��������Ҫ�������湩����ĩ��֮��..."<<endl;
								cout<<"ͼ�����Ա��̾�˿�����"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 
							break;	
						}
					}
				} 
			break;
			case 5:
				cout<<"�㷢����һ��˯�ŵ�ũ��"<<endl;
				Sleep(1000);
				cout<<"0������  1��͵����"<<endl;
				cin>>choose;
				if(choose==1){
					credit-=20;
					int add=rand()%4;
					if(add==0){
						cout<<"��͵͵������ũ��Ŀڴ������ֿտ���Ҳ��"<<endl;
						Sleep(1500);
						cout<<"ũ�����ˣ��󺰣�С͵������"<<endl;
						Sleep(1500);
						cout<<"һ�Ե������ܳ���!"<<endl;
						Sleep(2000);
						fight("������",100,8,6,40,2,10,3,200,5);
						if(dead){
							dead=false;
							cout<<"��� 2 ��������"<<endl;
							bag[21]+=2;
							cout<<"���߿��������ܣ���æ������"<<endl; 
							Sleep(2000);
						}else{
							cout<<"���Ǯ��������ȫ�������ˣ�"<<endl;
							money=0; 
							Sleep(2000);
							return;
						}
					}else{
						cout<<"��͵͵������ũ��Ŀڴ��������� "<<add<<" ���̱�ʯ��"<<endl;
						money+=add;
						Sleep(1500);
						cout<<"�������ĵ�����"<<endl;
						Sleep(2000);
					}
				}else{
					cout<<"�������ũ��"<<endl;
					Sleep(1500);
					cout<<"ũ����㲻ͣ��л"<<endl;
					credit+=1;
					Sleep(2000);
				}
			break;
			case 6:
				cout<<"���ߵ���ׯ���ģ�������һ������..."<<endl;
				Sleep(1500);
				cout<<"����ϸһ�����Ǵ�����Notch�ĵ���"<<endl;
				Sleep(1500);
				cout<<"���㻷�����ܣ����־�û��һ��������ݵ���"<<endl;
				Sleep(1500);
				cout<<"������Ҳ��������ʮ���ƾɡ�"<<endl<<endl;
				Sleep(1500);
				if(credit<=20){
					cout<<"����ŵ�����Цһ��������һ�ڿ�ˮ����ȥ��"<<endl;
					Sleep(2000);
					credit-=5;
					return;
				}
				cout<<"0���뿪  1�����ݵ���"<<endl;
				cin>>choose;
				if(choose==1){
					system("cls");
					cout<<"����������ʱ��һ��������㺰������Ҫ���ݣ�"<<endl;
					Sleep(1500);
					cout<<"�����֣���Ϊʲô���ܼ��ݡ�"<<endl;
					Sleep(1500);
					cout<<"����˵��һ�����Ǽ����˴�����ĵ�����Χ������������е���в��ǰ���������ǵĴ�ׯ��"<<endl<<endl;
					Sleep(2000);
					cout<<"0���뿪  1����������"<<endl;
					cin>>choose;
					if(choose==1){
						credit+=5;
						cout<<"��û����ԥ�����ŵ��������ȥ..."<<endl; 
						Sleep(2000);
						if(blesscold==0){
							cout<<"���Notch֮ף�����´�ս��ʱ��Ч"<<endl;
							blessing=true;
							Sleep(2000);
							blesscold=2;
						}else blesscold--;	
						if(1+rand()%2==1){
							undeadattack=true;
							cout<<"Ȼ������ͻȻ����һ�ֲ����Ԥ��..."<<endl;
							Sleep(2000); 
						} 
					} 
				} 
			break;
			case 7:
				cout<<"��ʲô��û����..."<<endl;
				Sleep(2000); 
			break;
			case 8:
			cout<<"�������������ܣ�"<<endl;
			cout<<"0���뿪  1����ŭ"<<endl;
			cin>>choose;
			if(choose==1){
				fight("������",100,8,6,40,2,10,3,500,5);
				credit-=20;
				if(dead){
					dead=false;
					cout<<"��� 2 ��������"<<endl;
					bag[21]+=2;
				}
			}else{
				cout<<"��Զ����������"<<endl; 
				Sleep(1000);
				break;
			}
			break;	
			case 9:
				cout<<"�������˴�ׯ�е¸����ص�����-ͼ�����Ա"<<endl; 
				Sleep(1000);
				cout<<"��λ����֪����������ϵ���������..."<<endl<<endl;
				Sleep(1500);
				if(credit<=30){
					cout<<"ͼ�����Աֻ������ɨ�ӹ������ϣ���͸о����ķ·�������һ��"<<endl;
					Sleep(1500);
					cout<<"��о������������ļ���..."<<endl;
					Sleep(1500);
					cout<<"���㶼����ʲô��û���˱�����������ʹ��������С��Ҳ��Ը����Ԯ������������ΪŰ...��"<<endl;
					Sleep(1500);
					cout<<"��̼䣬ͼ�����Ա����ʧ�����������..."<<endl;
					Sleep(2000); 
				}else{
					cout<<"��Ҫ��ͼ�����Ա��̸�𣿣�0���뿪  1����̸��"<<endl;
					cin>>choose;
					if(choose==1){
						cout<<"��Ҫѯ��ʲô��"<<endl;
						cout<<"1������Զ��ʱ�ڵ�ս��"<<endl;
						cout<<"2��Herobrine����ͽ/����"<<endl;
						cout<<"3��Herobrine�����Ĵ���"<<endl;
						cout<<"4�����ڴ���֮��"<<endl;
						cout<<"5��������������"<<endl; 
						cout<<"6�����ڵ���"<<endl;
						cout<<"7������ĩ��"<<endl;
						cin>>choose;
						switch(choose){
							case 1:
								system("cls");
								Sleep(2000); 
								cout<<"��Զ��ʱ�ڣ�Ҳ�����������ձ��������ʱ������������λ��Ҳ����Notch��Herobrine��������λ�����ֵܡ�"<<endl; 
								cout<<"��Herobrine���������������������𽥲��ͣ��������ǵĹ�ϵ�ֱ�������"<<endl;
								cout<<"Notch����Herobrine�������棬��Herobrine��������������������һ֧������----"<<endl;
								cout<<"��֧�������Ĵ�ǰ��������֮��Ѫ���ɺӣ�ʬ�Ǳ��..."<<endl;
								cout<<"Notch���ŷ�����������Ϳ̿��������ֹHerobrine���������ս���ĵ�����..."<<endl;
								cout<<"����������Խ���ȥ������ת��Ϊ���飬��ʱ������ֻ���Ĵ�������"<<endl;
								cout<<"Notchʹ���˴����ġ� ����֮�����ųɹ������һ�󲿷ֵ����飬�����в���������һ���������"<<endl;
								cout<<"����Notch�Ѿ�û���㹻�������Ը�Herobrine�ˣ���ֻ���ó�ʣ��ġ� ����֮��������Herobrine��ӡ���˵���..."<<endl;
								cout<<"���ǣ��ƺ�Herobrine���������������ƿ���ӡ..."<<endl<<endl;
								cout<<"ͼ�����Ա̾�˿�����"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								}     
							break;
							case 2:
								system("cls");
								Sleep(2000); 
								cout<<"���ڴ������ڣ�Herobrine��չʾ���������ĸ���Ȼ��ͬ���Ը�"<<endl; 
								cout<<"���ŵ�������Լ��������������ף������統���Լ�����Ϸ��"<<endl;
								cout<<"���ڣ�Herobrine����������Щ̫��������顣"<<endl;
								cout<<"������ʱ�����ƣ�HerobrineԽ��Խ��������ʼ��������ؽ����Լ���������"<<endl;
								cout<<"�����Լ��ġ� ����֮���������鴴�����һ����һ��������ʵ���¡�"<<endl;
								cout<<"����������ƾ�����Լ�ǿ����������շ���������ص�һ����ǿ�ߣ������Լ�������ʹ���Ǳ�ø�ǿ��"<<endl;
								cout<<"��Herobrine����Ҳ������������һЩ�Լ�����Ӱ����Щ��Ӱ������Herobrine����ʵ�����б����ǧ��֮һ��"<<endl;
								cout<<"�� NULL���־�ħ����Entity_303��...����Herobrine��ʵ�����¡�"<<endl;
								cout<<"�����������������������е�������Herobrine�ܿ��ܽ����ƿ���ӡ���ػ�����..."<<endl<<endl;
								cout<<"ͼ�����Ա����ɫ������ء�"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 3: 
								system("cls");
								Sleep(2000); 
								cout<<"Herobrine�Ĺ���..."<<endl; 
								cout<<"�ⲻ��ҥ�ԣ�Ҳ��ܿ�ͻᷢ��...������Notch�Ѳ�֪���٣������Ŀ־�ħ���Ѿ������������ǣ�Herobrine�ܿ��ܻ��ƿ���ӡ��"<<endl;
								cout<<"��ңԶ�ı߾�֮�أ��������Ŵ���֮�������֮�������汻�����һ�¸�ǽ��һ�����ﶼ��û��ҡ�"<<endl;
								cout<<"��Null�����ڱ߾�֮��..."<<endl;
								cout<<"Herobrine�������������ؽ��᲻ϧ���д��ۣ�ǿ�д���Herobrine�ķ�ӡ..."<<endl;
								cout<<"ͼ�����Ա����ɫ������ء�"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 4:
								system("cls");
								Sleep(2000); 
								cout<<"����֮��������Notch��ӵ�е�������"<<endl; 
								cout<<"��������ӵ���Ŵ��������������⣬��ǿ���������"<<endl;
								cout<<"Herobrine��ӵ�еģ����ǻ���֮������Notch�෴���������ƻ������ȶ��ԡ�"<<endl;
								cout<<"���ǵ���Notch��Herobrine���֣������˴����������Ŵ������������硣"<<endl;
								cout<<"��Ҳֻ�д���֮�������ܿ���Herobrine�Ļ���֮����"<<endl;
								cout<<"��Notch�ڴ�ս�����ʧ���ټ�������֮��Ҳ��֪��������..."<<endl;
								cout<<"ͼ�����Ա����ɫ������ء�"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 5:
								system("cls");
								Sleep(2000); 
								cout<<"���������Herobrine������֮�������֮��������ġ�"<<endl; 
								cout<<"����������Խ���ȥ������ת������顣"<<endl;
								cout<<"Ҳ����˵��ͨ��������Ĵ����ɣ���Ⱦ���������׵����һ֧��������"<<endl;
								cout<<"��Herobrine����ƾ���������Ӵ��������ӣ��ŵ�����Notch���⡣"<<endl;
								cout<<"Herobrine�������Ĺ�����������������쵼��Blackbone��֯������������..."<<endl;
								cout<<"����Notchӵ�д���֮������Ҳ�޷����׳������顣"<<endl;
								cout<<"���⽫��һ����������в����ͼ�����Ա����ɫ������ء�"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 	
							break;	
							case 6:
								system("cls");
								Sleep(2000); 
								cout<<"������һ��������ҽ������ҵĵط�����˵Ҳ�Ƿ�ӡHerobrine�ĵط�..."<<endl; 
								cout<<"����Σ�����أ�Ҫʱ��С�ĵ����ҽ�����Ҫ������µĶ�꣬�ҽ���"<<endl;
								cout<<"���ڵ����У���һ�����������--���顣"<<endl;
								cout<<"������һ��̰�Ƶ���������ǽ𶧱��������ǽ��ף�����ȴ����֪���Լ��ܵõ�ʲô��"<<endl;
								cout<<"���������������һ���ؽ��������½�Ͻ���Щ�Ͻ���Ҫ�ڵ�������ھ��Ӳ��Զ�Ųк��������ɡ�"<<endl;
								cout<<"���⣬�����л�������һЩ����ı��ݣ��Լ��½�Ҫ������Щ�ط������������ı��أ��Լ�--�����Σ����"<<endl;
								cout<<"ͼ�����Ա��̾�˿�����"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 7:
								system("cls");
								Sleep(2000); 
								cout<<"ĩ�أ�һ��λ����յ���һά�ȡ�"<<endl; 
								cout<<"���ﴣ���ż�������ʯ������ĩ�ص������ϻ���һ��������"<<endl;
								cout<<"��ĩ����Ĵ������ĩӰ�ˡ������ĩӰ�˶�����ʱ�շ�϶�в�С�Ĵ�Խ�����ġ�"<<endl;
								cout<<"���ĩӰ���󣬾Ϳ���ǰ��ĩ�ص��⵺�ˡ��⵺��ɢ����һЩĩ�سǣ���Щ�������������౦�ء�"<<endl;
								cout<<"��Ҫ���ĩӰ���ɲ����ף�����ʯ���ϵ�ĩӰˮ����ΪĩӰ�������ָ�������"<<endl;
								cout<<"������Ҫǰ��ĩ�أ�����Ҫ�ҵ�������ĩ�ص���Ծ���ӿڣ�����˵�ڵ���������һ��������Ҫ�������湩����ĩ��֮��..."<<endl;
								cout<<"ͼ�����Ա��̾�˿�����"<<endl;
								cout<<"0���뿪  1������ѯ��"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"����Ա���Ժ������ɣ�����������..."<<endl;
									Sleep(3000); 
								} 
							break;	
						}
					}
				} 
			break;
		}
	}
	if(place=="ƽԭ"){
		switch(rand()%1){
			case 0:
				if(task1==0){
					cout<<"��������һ�����мң�"<<endl;
					Sleep(1500);
					cout<<"���мҶ���˵��������û��ľͷ�ˣ����ܲ��ܸ�������10����ľ��"<<endl;
					cout<<endl<<"0���ܾ�  1������"<<endl;
					cin>>choose;
					if(choose==1){
						cout<<"��������ռ���ľ��"<<endl;
						task1=1;
						Sleep(2000);
						cout<<"ע�������������ҵ�ð�ռҽ������񷽿���ȡ������"<<endl;
						Sleep(2000);
					}else{
						cout<<"��ܾ������м�"<<endl;
						Sleep(1500);
					}
				}else{
					if(bag[1]<10){
						cout<<"���ҵ������м�"<<endl;
						Sleep(1500);
						cout<<"������ֻ�� "<<bag[1]<<" ����ľ����û���������"<<endl;
						Sleep(1500);
						cout<<"�����߿����㣬����������"<<endl;
						Sleep(1500);
						cout<<"�������ϣ�"<<endl;
						task1=2;
						credit-=15;
						Sleep(1500); 
					}else{
						cout<<"���ҵ������м�"<<endl;
						Sleep(1500);
						cout<<"�㽻�������м�10����ľ��"<<endl;
						bag[1]-=10; 
						Sleep(1500);
						cout<<"���м�ʮ�ָ��ˣ�������3���̱�ʯ��Ϊ������"<<endl;
						money+=3;
						Sleep(1500);
						cout<<"��������ɣ�"<<endl;
						task1=0;
						credit+=5;
						Sleep(2000);
					}
				}
			break;
			case 1:
			break;	
		}
	}
	system("cls");
	return;
}
void go(){//ǰ�� ���ĵص� 
	system("cls");
	cout<<"��Ҫȥ���"<<endl;
	cout<<"0������  1����ׯ  2��ƽԭ  3��ɭ��  4����Ѩ  5��ɳĮ  6������  7��ѩ��  8������  9��ĩ��";
	cout<<endl;
	cin>>choose;
	switch(choose){
		case 0:
		return;	
		break; 
		case 1:
		if(place=="��ׯ"){
			cout<<"���Ѿ��ڴ�ׯ�ˣ�"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"ǰ����..."<<endl;
			Sleep(3000);
			system("cls");
			place="��ׯ";
			cout<<"�ѵ��� "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 2:
		if(place=="ƽԭ"){
			cout<<"���Ѿ���ƽԭ�ˣ�"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"ǰ����..."<<endl;
			Sleep(3000);
			system("cls");
			place="ƽԭ";
			cout<<"�ѵ��� "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 3:
		if(place=="ɭ��"){
			cout<<"���Ѿ���ɭ���ˣ�"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"ǰ����..."<<endl;
			Sleep(3000);
			system("cls");
			place="ɭ��";
			cout<<"�ѵ��� "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 4:
		if(place=="��Ѩ"){
			cout<<"���Ѿ��ڶ�Ѩ�ˣ�"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"ǰ����..."<<endl;
			Sleep(3000);
			system("cls");
			place="��Ѩ";
			cout<<"�ѵ��� "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		case 5:
		if(place=="ɳĮ"){
			cout<<"���Ѿ���ɳĮ�ˣ�"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"ǰ����..."<<endl;
			Sleep(3000);
			system("cls");
			place="ɳĮ";
			cout<<"�ѵ��� "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 6:
		if(place=="����"){
			cout<<"���Ѿ��ڴ����ˣ�"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"ǰ����..."<<endl;
			Sleep(3000);
			system("cls");
			place="����";
			cout<<"�ѵ��� "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 7:
		if(place=="ѩ��"){
			cout<<"���Ѿ���ѩ���ˣ�"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"ǰ����..."<<endl;
			Sleep(3000);
			system("cls");
			place="ѩ��";
			cout<<"�ѵ��� "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 8:
		if(place=="����"){
			cout<<"���Ѿ��ڵ����ˣ�"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			if(nether){
				cout<<"ǰ����..."<<endl;
				Sleep(3000);
				system("cls");
				place="ѩ��";
				cout<<"�ѵ��� "<<place<<"!"<<endl;
				Sleep(1000); 
				return; 
			}else{
				cout<<"�޷�ǰ������û�н���/���ֵ���������"<<endl;
				Sleep(1000);
				go(); 
			}
		}
		break;
		case 9:
		if(place=="ĩ��"){
			cout<<"���Ѿ���ĩ���ˣ�"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			if(nether){
				cout<<"ǰ����..."<<endl;
				Sleep(3000);
				system("cls");
				place="ĩ��";
				cout<<"�ѵ��� "<<place<<"!"<<endl;
				Sleep(1000); 
				return; 
			}else{
				cout<<"�޷�ǰ������û�з���ĩ�ش�����"<<endl;
				Sleep(1000);
				go(); 
			}
		}
		break;
	} 
}
void chop(string place){//���� 
	cout<<"������ľ��"<<endl;
	Sleep(1000);
	cout<<"��ʼ����..."<<endl;
	Sleep(1000);
	system("cls");
	switch(tool1){
		case 0:
			for(int i=1;i<=20;i++){
				cout<<"�����"<<i*5<<"%"<<endl; 
				Sleep(2000);
				system("cls");
			}
		break;
		case 1: 
			for(int i=1;i<=20;i++){
				cout<<"�����"<<i*5<<"%"<<endl; 
				Sleep(1500);
				system("cls");
			}
		break;
		case 2: 
			for(int i=1;i<=20;i++){
				cout<<"�����"<<i*5<<"%"<<endl; 
				Sleep(1250);
				system("cls");
			}
		break;
		case 3: 
			for(int i=1;i<=20;i++){
				cout<<"�����"<<i*5<<"%"<<endl; 
				Sleep(250);
				system("cls");
			}
		break;
		case 4:
			for(int i=1;i<=20;i++){
				cout<<"�����"<<i*5<<"%"<<endl; 
				Sleep(750);
				system("cls");
			}	
		break;
		case 5:
			for(int i=1;i<=20;i++){
				cout<<"�����"<<i*5<<"%"<<endl; 
				Sleep(500);
				system("cls");
			}
		break;
		case 6:
			for(int i=1;i<=20;i++){
				cout<<"�����"<<i*5<<"%"<<endl; 
				Sleep(300);
				system("cls");
			}
		break; 
	}
	if(place=="ƽԭ"||place=="ɭ��"){
		int add=5+rand()%8;
		cout<<"�����ľ"<<add<<"����"<<endl; 
		bag[1]+=add;
		cout<<"��ǰӵ����ľ"<<bag[1]<<"��"<<endl;	
		Sleep(2000);
	}
	if(place=="����"){
		int add=7+rand()%3;
		cout<<"��ô���ľ"<<add<<"����"<<endl; 
		bag[2]+=add;
		cout<<"��ǰӵ�д���ľ"<<bag[2]<<"��"<<endl;	
		Sleep(2000);
	}
	if(place=="ѩ��"){
		int add=8+rand()%6;
		cout<<"�����Ҷľ"<<add<<"����"<<endl; 
		bag[3]+=add;
		cout<<"��ǰӵ����Ҷľ"<<bag[3]<<"��"<<endl;	
		Sleep(2000);
	}
	if(place=="����"){
		int add=6+rand()%6; 
		cout<<"���糺�ľ"<<add<<"����"<<endl; 
		bag[4]+=add;
		cout<<"��ǰӵ��糺�ľ"<<bag[4]<<"��"<<endl;	
		Sleep(3000);
	}
	int apple=1+rand()%3,appleadd=1+rand()%2;
	if(apple==3&&place!="����"){
		cout<<"�������Ϸ����� "<<appleadd<<" ��ƻ����"<<endl;
		bag[36]+=appleadd;
		Sleep(2000);
	}		
	return;
} 
void tree(string place){//���� 
	if(place=="��ׯ"){
		system("cls");
		cout<<"�ƺ�����û����...�ѵ�������˴���ķ��ӣ�"<<endl<<endl;
		cout<<"ϵͳ��ʾ����ȥ��ĵط�������"<<endl;
		Sleep(1500);
		return; 
	}
	if(place=="��Ѩ"){
		system("cls");
		cout<<"��Ѩ��ֻ�м�Ӳ��ʯͷ��û����..."<<endl<<endl;
		cout<<"ϵͳ��ʾ����ȥ��ĵط�������"<<endl;
		Sleep(1500);
		return; 
	}
	if(place=="ɳĮ"){
		system("cls");
		cout<<"�ƺ�����û�������е�ֻ�ǳ����˼�̵�������..."<<endl<<endl;
		cout<<"ϵͳ��ʾ����ȥ��ĵط�������"<<endl;
		Sleep(1500);
		return; 
	}
	if(place=="ĩ��"){
		system("cls");
		cout<<"��ݿ���ɲ���ľͷ��"<<endl<<endl;
		cout<<"ϵͳ��ʾ����ȥ��ĵط�������"<<endl;
		Sleep(1500);
		return; 
	}
	system("cls");
	if(tool1==0){
		cout<<"��������û�и��ӣ���ƾ��Ӳ��˫�֣�Ҳ�����������Щľͷ..."<<endl<<endl; 
		cout<<"�������һ�Ѹ��ӣ�����ӿ쿳�����ٶȡ�"<<endl;
		Sleep(3000);
		cout<<endl;
	}
	cout<<"��ǰ��װ����";
	cout<<tool1name[tool1]<<endl<<endl; 
	cout<<"��ʾ����������λ�þ������㷢����ľ���ٶȡ�"<<endl;
	cout<<"      ͬʱ����ĸ�ͷ������㿳����ľ���ٶȡ�"<<endl<<endl;
	Sleep(2000);
	cout<<"0������  1������"<<endl;
	cin>>choose;
	system("cls");
	if(choose==1){
		if(place=="ƽԭ"){
			cout<<"��Լ��Ҫ20��..."<<endl; 
			cout<<"Ѱ����ľ��..."<<endl; 
			Sleep(15000+rand()%8000); 
			chop("ƽԭ");
		}
		if(place=="ɭ��"){
			cout<<"��Լ��Ҫ5��..."<<endl; 
			cout<<"Ѱ����ľ��..."<<endl; 
			Sleep(2000+rand()%5000); 
			chop("ɭ��");
		}
		if(place=="����"){
			cout<<"��Լ��Ҫ10��..."<<endl; 
			cout<<"Ѱ����ľ��..."<<endl; 
			Sleep(6000+rand()%8000); 
			chop("����");
		}
		if(place=="ѩ��"){
			cout<<"��Լ��Ҫ30��..."<<endl; 
			cout<<"Ѱ����ľ��..."<<endl; 
			Sleep(25000+rand()%10000); 
			chop("ѩ��");
		}
		if(place=="����"){
			cout<<"��Լ��Ҫ10��..."<<endl; 
			cout<<"Ѱ����ľ��..."<<endl; 
			Sleep(8000+rand()%6000); 
			chop("����");
		}
	}
	else return;
}
void dig(string place){
		if(place!="��Ѩ"&&place!="����"){
			cout<<"�˴��޷��ڿ���ȥ�����ط��ڿ�"<<endl;
			Sleep(1500);
			return;
		}
		if(tool2==0){
			cout<<"�����޷��ڿ���װ�����Ӻ������ڿ�"<<endl;
			Sleep(2000);				
			return; 
		}
		cout<<"�������ڣ�"<<place<<endl;
		if(place=="��Ѩ"){	
			system("cls");
			cout<<"������װ����"<<tool2name[tool2]<<endl<<endl;
			cout<<"��ʾ��һЩ��ʯֻ���ض����㹻�õĸ��Ӳ����ھ�"<<endl;
			cout<<"      ��ĸ��Ӿ��������ھ��ʯʱ���ٶȡ�"<<endl<<endl; 
			Sleep(2000);
			cout<<"0������  1���ڿ�"<<endl;
			cin>>choose;
			if(choose==1){
				cout<<"0����Բʯ  1���ڿ���"<<endl;
				cin>>choose;
				if(choose==0){//��ʯͷ 
					cout<<"��Ҫ�ڶ��ٿ�Բʯ��"<<endl;
					cin>>choose;
					cout<<"��ʼ�ھ�..."<<endl;
					Sleep(2000); 
					system("cls");
					switch(tool2){
						case 1: 
							for(int i=1;i<=20;i++){
								cout<<"�����"<<i*5<<"%"<<endl; 
								Sleep(225*choose);
								system("cls");
							}
						break;
						case 2: 
							for(int i=1;i<=20;i++){
							cout<<"�����"<<i*5<<"%"<<endl; 
							Sleep(187*choose);
							system("cls");
							}
						break;
						case 3: 
							for(int i=1;i<=20;i++){
								cout<<"�����"<<i*5<<"%"<<endl; 
								Sleep(62*choose);
								system("cls");
							}
						break;
						case 4:
							for(int i=1;i<=20;i++){
								cout<<"�����"<<i*5<<"%"<<endl; 
								Sleep(137*choose);
								system("cls");
							}	
						break;
						case 5:
							for(int i=1;i<=20;i++){
								cout<<"�����"<<i*5<<"%"<<endl; 
								Sleep(100*choose);
								system("cls");
							}
						break;
						case 6:
							for(int i=1;i<=20;i++){
								cout<<"�����"<<i*5<<"%"<<endl; 
								Sleep(75*choose);
								system("cls");
							}
						break; 
					}
					cout<<"���Բʯ "<<choose<<" ��!"<<endl;	
					bag[14]+=choose;
					cout<<"��ǰӵ��Բʯ "<<bag[14]<<" ��"<<endl;
					Sleep(2000);	
					return;
				}else{//�ڿ�ʯ 
				system("cls");
				cout<<"̽������..."<<endl;	
				Sleep(8000+rand()%12000);
				int add;
				switch(1+rand()%3){
					case 1://����ú̿ 
						add=8+1+rand()%8;
						cout<<"�㷢���� "<<add<<" ��ú̿��"<<endl;
						Sleep(1000);
						cout<<"0���뿪  1���ھ�"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							switch(tool2){
								case 1: 
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(250*add);
										system("cls");
									}
								break;
								case 2: 
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(200*add);
										system("cls");
									}
								break;
								case 3: 
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(75*add);
										system("cls");
									}
								break;
								case 4:
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(150*add);
										system("cls");
									}	
								break;
								case 5:
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(120*add);
										system("cls");
									}
								break;
								case 6:
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(90*add);
										system("cls");
									}
								break; 
							}
							cout<<"�ھ���ϣ���� "<<itemname[19]<<" "<<add<<" ����"<<endl;
							bag[19]+=add;
							cout<<"��ǰ�� "<<itemname[19]<<" "<<bag[19]<<" ����"<<endl;
							Sleep(2000);
							dig(place); 
						}else dig(place);
					break;
					case 2://�������� 
						add=2+1+rand()%8;
						cout<<"�㷢���� "<<add<<" ������ʯ��"<<endl;
						Sleep(1000);
						cout<<"0���뿪  1���ھ�"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							if(tool2<2||tool2==3){
								cout<<"��ǰ�����޷��ھ�˿�ʯ��"<<endl;
								Sleep(2000);
								dig(place);
							} 
							switch(tool2){
								case 2: 
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(225*add);
										system("cls");
									}
								break;
								case 4:
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(175*add);
										system("cls");
									}	
								break;
								case 5:
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(140*add);
										system("cls");
									}
								break;
								case 6:
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(120*add);
										system("cls");
									}
								break; 
							}
							cout<<"�ھ���ϣ���� "<<itemname[20]<<" "<<add<<" ����"<<endl;
							bag[20]+=add;
							cout<<"��ǰ�� "<<itemname[20]<<" "<<bag[20]<<" ����"<<endl;
							Sleep(2000);
							dig(place); 
						}else dig(place);
					break;
					case 3://���ֽ�� 
						int add=4+1+rand()%3;
						cout<<"�㷢���� "<<add<<" ����ʯ��"<<endl;
						Sleep(1000);
						cout<<"0���뿪  1���ھ�"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							if(tool2<4){
								cout<<"��ǰ�����޷��ھ�˿�ʯ��"<<endl;
								Sleep(2000);
								dig(place);
							}
							switch(tool2){
								case 4:
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(200*add);
										system("cls");
									}	
								break;
								case 5:
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(160*add);
										system("cls");
									}
								break;
								case 6:
									for(int i=1;i<=20;i++){
										cout<<"�����"<<i*5<<"%"<<endl; 
										Sleep(140*add);
										system("cls");
									}
								break; 
							}
							cout<<"�ھ���ϣ���� "<<itemname[31]<<" "<<add<<" ����"<<endl;
							bag[31]+=add;
							cout<<"��ǰ�� "<<itemname[31]<<" "<<bag[31]<<" ����"<<endl;
							Sleep(2000);
							dig(place); 
						}else dig(place);
					break;	
				}
			}
		}else return;
	}
}
void jvqing(){//������� 
	system("cls");
	cout<<"���ؾ�����..."<<endl;
	Sleep(2000);
	cout<<"������ϣ�"<<endl;
	Sleep(1000);
	system("cls"); 
	Sleep(500);
	cout<<"�ܾ�֮ǰ,���������λ�񣬷ֱ���Notch��Herobrine��"<<endl<<endl;
	Sleep(1500);
	cout<<"���Ǳ���һ���ֵܣ�����ƽ�����£�Notch��Herobrine��ͬ���֣�������һ���������硣"<<endl<<endl;
	Sleep(1500);
	cout<<"Notch����������࣬���ʹ���������������"<<endl<<endl;
	Sleep(1500);
	cout<<"�����ĵܵ�Herobrine��Ϊ��̫�����ģ��ִ��������������"<<endl<<endl;
	Sleep(1500);
	cout<<"��������ܿ�㲻�ϣ�����Notch��Herobrine�������У��Ʋ�������"<<endl<<endl;
	Sleep(1500);
	cout<<"Herobrine�������ڶ����飬Ѫϴ�˷����½�ϵ�һ������......"<<endl<<endl;
	Sleep(1500);
	cout<<"Notch��״���ľ��˽������е���������Herobrine��ӡ�������˵�����"<<endl<<endl;
	Sleep(1500);
	cout<<"��������ˣ�Herobrine��������������ѱ鲼���磬�޷�������"<<endl<<endl;
	Sleep(1500);
	cout<<"��HerobrineҲ�����������������źڰ�������׼�����ˡ�"<<endl<<endl;
	Sleep(1500);
	system("cls");
	for(int i=1;i<=12;i++){
		cout<<"."<<" ";
		Sleep(100);
	}
	cout<<endl<<endl<<"�������ȥ�ˣ���ƽ�����ľ��󼴽�������......"<<endl<<endl;
	Sleep(1500); 
	cout<<"�ܹ������������ģ���ֻ��--"<<endl<<endl;
	Sleep(800); 
	cout<<"�㣬�����������磬���Herobrine����������ĺ�ƽ��"<<endl<<endl;
	Sleep(1000);
	cout<<"������Ĵ��棬���ڿ�ʼ......"<<endl<<endl;
	Sleep(3000);
	return; 
}
void checkbag(){//��鱳�� 
	cout<<"��ʾ˳��Ϊ ���-��Ʒ��-����"<<endl<<endl;
	cout<<"��δ��ʾ��Ϊ����Ʒ"<<endl<<endl;
	for(int i=1;i<=100;i++){
		if(bag[i]>0) cout<<"��� "<<i<<"  "<<itemname[i]<<" ������"<<bag[i]<<" ��"<<endl;
		else continue;
	}
	if(weaponcheck==1) return;
	cout<<endl<<"����0����"<<endl;
	cin>>choose;
	switch(choose){
		case 0:
			return;
		break;
		case 1:
			system("cls");
			cout<<"��Ʒ��"<<itemname[1]<<endl; 
			cout<<"������ľͷ������ƽԭ��ɭ�ֿ�����á�����������ľľ�塣"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 2:
			system("cls");
			cout<<"��Ʒ��"<<itemname[2]<<endl; 
			cout<<"������ľͷ�����ڴ��ֿ�����á�������������ľ�塣"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 3:
			system("cls");
			cout<<"��Ʒ��"<<itemname[3]<<endl; 
			cout<<"������ľͷ������ѩ�ؿ�����á�����������Ҷľľ�塣"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 4:
			system("cls");
			cout<<"��Ʒ��"<<itemname[4]<<endl; 
			cout<<"���Ե�����ľͷ���ܷ��𣬿��ڵ���������á���������糺�ľ�塣"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 5:
			system("cls");
			cout<<"��Ʒ��"<<itemname[5]<<endl; 
			cout<<"������ľ�壬������������ľ��Ʒ��"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 6:
			system("cls");
			cout<<"��Ʒ��"<<itemname[6]<<endl; 
			cout<<"������ľ�壬������������ľ��Ʒ��"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 7:
			system("cls");
			cout<<"��Ʒ��"<<itemname[7]<<endl; 
			cout<<"������ľ�壬������������ľ��Ʒ��"<<endl;
			Sleep(3000);
			system("cls");
			checkbag();
		break;
		case 8:
			system("cls");
			cout<<"��Ʒ��"<<itemname[8]<<endl; 
			cout<<"���Ե�����ľ�壬�ܷ��𣬿�����������ľ��Ʒ��"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 9:
			system("cls");
			cout<<"��Ʒ��"<<itemname[9]<<endl; 
			cout<<"һ������վ����<����>�н�����ñ�ɺϳɸ�������Ʒ��"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 10:
			system("cls");
			cout<<"��Ʒ��"<<itemname[10]<<endl;
			cout<<"ľ�ƵĹ��ӣ�����װ�����͹��߱ر��Ĳ��ϡ�"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 11:
			system("cls");
			cout<<"��Ʒ��"<<itemname[11]<<endl;
			cout<<"ľ�ƵĽ����򵥺��á�"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 12:
			system("cls");
			cout<<"��Ʒ��"<<itemname[12]<<endl;
			cout<<"ľ�Ƶĸ�������΢�����������ٶȡ�"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 13:
			system("cls");
			cout<<"��Ʒ��"<<itemname[13]<<endl;
			cout<<"ľ�Ƶĸ壬�����ھ�ʯͷ��ú̿��"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 14:
			system("cls");
			cout<<"��Ʒ��"<<itemname[14]<<endl;
			cout<<"�����Ĵ��ɲɼ���ʯͷ��������ʯ�ƹ��ߵı�Ҫ���ϡ�"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 15:
			system("cls");
			cout<<"��Ʒ��"<<itemname[15]<<endl;
			cout<<"ʯ�ʵĽ�����ʵ�޻��������á�"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 16:
			system("cls");
			cout<<"��Ʒ��"<<itemname[16]<<endl;
			cout<<"ʯ�ʵĸ�����С�������������ٶȡ�"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 17:
			system("cls");
			cout<<"��Ʒ��"<<itemname[17]<<endl;
			cout<<"ʯ�ʵĸ壬��ľ����ھ��ٶȸ��죬�����ھ�����"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 18:
			system("cls");
			cout<<"��Ʒ��"<<itemname[18]<<endl;
			cout<<"�����Ż��⡱����<����>�н�����ñ���������"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 19:
			system("cls");
			cout<<"��Ʒ��"<<itemname[19]<<endl;
			cout<<"������ȼ�ϣ��������������"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 20:
			system("cls");
			cout<<"��Ʒ��"<<itemname[20]<<endl;
			cout<<"�м��Ŀ�ʯ����������¯�����ɻ��������"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 21:
			system("cls");
			cout<<"��Ʒ��"<<itemname[21]<<endl;
			cout<<"�м��Ŀ󶧣�������������������װ����"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 22:
			system("cls");
			cout<<"��Ʒ��"<<itemname[22]<<endl;
			cout<<"���ʵĽ����������ã��������������"<<endl; 
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 23:
			system("cls");
			cout<<"��Ʒ��"<<itemname[23]<<endl;
			cout<<"���ʵĸ����ɽϿ����������ٶȡ�"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 24:
			system("cls");
			cout<<"��Ʒ��"<<itemname[24]<<endl;
			cout<<"���ʵĸ壬�����ھ���ʯ�����ʯ���и߼�����ҿɽϿ������ھ��ٶȡ�"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 25:
			system("cls");
			cout<<"��Ʒ��"<<itemname[25]<<endl;
			cout<<"���ʵĸ����ɽϿ����������ٶȡ�"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 26:
			system("cls");
			cout<<"��Ʒ��"<<itemname[26]<<endl;
			cout<<"���ʵ�ͷ�����ɵֵ��ܵ����˺���"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 27:
			system("cls");
			cout<<"��Ʒ��"<<itemname[27]<<endl;
			cout<<"���ʵ��ؼף��ɵֵ��ܵ����˺���"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 28:
			system("cls");
			cout<<"��Ʒ��"<<itemname[28]<<endl;
			cout<<"���ʵĻ��ȣ��ɵֵ��ܵ����˺���"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 29:
			system("cls");
			cout<<"��Ʒ��"<<itemname[29]<<endl;
			cout<<"���ʵ�ѥ�ӣ��ɵֵ��ܵ����˺���"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 30:
			system("cls");
			cout<<"��Ʒ��"<<itemname[20]<<endl;
			cout<<"�и߼��Ŀ�ʯ����������¯�����ɻ�ý𶧡�"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 31:
			system("cls");
			cout<<"��Ʒ��"<<itemname[31]<<endl;
			cout<<"�и߼��Ŀ󶧣����������ٶȼ���Ľ���װ����"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
	}	
}
void weapon(){//װ�� 
	system("cls");
	weaponcheck=1;
	cout<<"��ǰ��װ��ͷ����"<<armor1name[armor1]<<endl; 
	cout<<"��ǰ��װ���ؼף�"<<armor2name[armor2]<<endl; 
	cout<<"��ǰ��װ�����ȣ�"<<armor3name[armor3]<<endl; 
	cout<<"��ǰ��װ��ѥ�ӣ�"<<armor4name[armor4]<<endl; 
	cout<<"��ǰ������װ����"<<weapon1name[weapon1]<<"(+"<<weapon1attack[weapon1]<<")"<<endl; 
	cout<<"��ǰ�㸱��װ����"<<weapon2name[weapon2]<<endl;
	cout<<"��ǰ��ʹ�ø��ӣ�"<<tool1name[tool1]<<endl;
	cout<<"��ǰ��ʹ�ø��ӣ�"<<tool2name[tool2]<<endl<<endl;
	checkbag();
	weaponcheck=0;
	cout<<endl<<"0���˳�  1��ж������  2��װ������"<<endl;
	cin>>choose;
	switch(choose){
		case 0:
			return;
		break;
		case 1://ж��װ�� 
			cout<<"��Ҫж�£�"<<endl;
			cout<<"0������  1��ͷ��  2���ؼ�  3������  4��ѥ��  5������  6������  7������  8������"<<endl;
			cin>>choose;
			switch(choose){
				case 0:
					weapon();
				break; 
				case 1://ж��ͷ�� 
					switch(armor1){//
						case 0:
							cout<<"��û��װ��ͷ����"<<endl;
							Sleep(1500);
							weapon();	
						break;
						case 3:
							bag[39]+=1;
							cout<<"��ж�� "<<itemname[39]<<" ��"<<endl; 
							armor1=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[25]+=1;
							cout<<"��ж�� "<<itemname[25]<<" ��"<<endl; 
							armor1=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 2://ж���ؼ� 
					switch(armor2){//
						case 0:
							cout<<"��û��װ���ؼף�"<<endl;
							Sleep(1500);
							weapon();	
						break;
						case 3:
							bag[40]+=1;
							cout<<"��ж�� "<<itemname[40]<<" ��"<<endl; 
							armor2=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[26]+=1;
							cout<<"��ж�� "<<itemname[26]<<" ��"<<endl; 
							armor2=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 3://ж�»��� 
					switch(armor3){//
						case 0:
							cout<<"��û��װ�����ȣ�"<<endl;
							Sleep(1500);
							weapon();	
						break;
						case 3:
							bag[41]+=1;
							cout<<"��ж�� "<<itemname[41]<<" ��"<<endl; 
							armor3=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[27]+=1;
							cout<<"��ж�� "<<itemname[27]<<" ��"<<endl; 
							armor3=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 4://ж��ѥ�� 
				switch(armor4){//
						case 0:
							cout<<"��û��װ��ѥ�ӣ�"<<endl;
							Sleep(1500);
							weapon();	
						break;
						case 3:
							bag[42]+=1;
							cout<<"��ж�� "<<itemname[42]<<" ��"<<endl; 
							armor4=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[28]+=1;
							cout<<"��ж�� "<<itemname[28]<<" ��"<<endl; 
							armor4=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 5:
					switch(weapon1){//ж������ 
						case 0:
							cout<<"��û��װ������������"<<endl;
							Sleep(1500);
							weapon();	
						break;
						case 1:
							bag[11]+=1;
							cout<<"��ж�� "<<itemname[11]<<" ��"<<endl; 
							weapon1=0;
							Sleep(1500);
							weapon();
						break;
						case 2:
							bag[15]+=1;
							cout<<"��ж�� "<<itemname[15]<<" ��"<<endl; 
							weapon1=0;
							Sleep(1500);
							weapon();
						break;
						case 3:
							bag[33]+=1;
							cout<<"��ж�� "<<itemname[33]<<" ��"<<endl; 
							weapon1=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[22]+=1;
							cout<<"��ж�� "<<itemname[22]<<" ��"<<endl; 
							weapon1=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 6:
					switch(weapon2){//ж�¸��� 
					}
				break;	
				case 7:
					switch(tool1){//ж�¸��� 
						case 0:
							cout<<"��û��װ������!"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 1:
							bag[12]+=1;
							cout<<"��ж�� "<<itemname[12]<<" ��"<<endl; 
							tool1=0;
							Sleep(1500);
							weapon();
						break;
						case 2:
							bag[16]+=1;
							cout<<"��ж�� "<<itemname[16]<<" ��"<<endl; 
							tool1=0;
							Sleep(1500);
							weapon();
						break;
						case 3:
							bag[34]+=1;
							cout<<"��ж�� "<<itemname[33]<<" ��"<<endl; 
							tool1=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[23]+=1;
							cout<<"��ж�� "<<itemname[34]<<" ��"<<endl; 
							tool1=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 8:
					switch(tool2){//ж�¸��� 
						case 0:
							cout<<"��û��װ�����ӣ�"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 1:
							bag[13]+=1;
							cout<<"��ж�� "<<itemname[13]<<" ��"<<endl; 
							tool2=0;
							Sleep(1500);
							weapon();
						break;
						case 2:
							bag[17]+=1;
							cout<<"��ж�� "<<itemname[17]<<" ��"<<endl; 
							tool2=0;
							Sleep(1500);
							weapon();
						break;
						case 3:
							bag[35]+=1;
							cout<<"��ж�� "<<itemname[33]<<" ��"<<endl; 
							tool2=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[24]+=1;
							cout<<"��ж�� "<<itemname[24]<<" ��"<<endl; 
							tool2=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
			}	
		break;
		case 2: //װ������ 
			cout<<"�����㱳���е�����/����/װ������Ը���װ��,��Ҫ����������Ʒ�ı�ţ�"<<endl<<endl;
			cout<<"��Ҫװ��ʲô������"<<endl;
			cout<<"0������  1��ͷ��  2���ؼ�  3������  4��ѥ��  5������  6������  7������  8������"<<endl;
			cin>>choose;
			switch(choose){
				case 0:
					weapon();
				break;	
				case 1:
					if(armor1!=0){
						cout<<"��װ��ͷ������ж�º���װ����"<<endl;
						Sleep(2000);
						weapon();
					}
					cout<<"������Ҫװ����ͷ���ı�ţ���Ҫ����������"<<endl;
					cin>>choose;
					switch(armor1){//
						case 39:
							armor1=3; 
							cout<<"��װ�� "<<armor1name[armor1]<<" ��"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 25:
							armor1=4;
							cout<<"��װ�� "<<armor1name[armor1]<<" ��"<<endl; 
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 2:
					if(armor2!=0){
						cout<<"��װ���ؼף���ж�º���װ����"<<endl;
						Sleep(2000);
						weapon();
					}
					cout<<"������Ҫװ�����ؼ׵ı�ţ���Ҫ����������"<<endl;
					cin>>choose; 
					switch(armor2){//
						case 40:
							armor2=3; 
							cout<<"��װ�� "<<armor2name[armor2]<<" ��"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 26:
							armor2=2;
							cout<<"��װ�� "<<armor2name[armor2]<<" ��"<<endl; 
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 3:
					if(armor3!=0){
						cout<<"��װ�����ȣ���ж�º���װ����"<<endl;
						Sleep(2000);
						weapon();
					}
					cout<<"������Ҫװ���Ļ��ȵı�ţ���Ҫ����������"<<endl;
					cin>>choose;
					switch(armor3){//
						case 41:
							armor3=3; 
							cout<<"��װ�� "<<armor3name[armor3]<<" ��"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 27:
							armor3=4;
							cout<<"��װ�� "<<armor3name[armor3]<<" ��"<<endl; 
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 4:
					if(armor4!=0){
						cout<<"��װ��ѥ�ӣ���ж�º���װ����"<<endl;
						Sleep(2000);
						weapon();
					}
					cout<<"������Ҫװ����ѥ�ӵı�ţ���Ҫ����������"<<endl;
					cin>>choose;
					switch(armor4){//
						case 42:
							armor4=3; 
							cout<<"��װ�� "<<armor4name[armor4]<<" ��"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 28:
							armor4=4;
							cout<<"��װ�� "<<armor4name[armor4]<<" ��"<<endl; 
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 5://װ������
					if(weapon1!=0){
						cout<<"������װ����������ж�º���װ����"<<endl;
						Sleep(2000);
						weapon();
					} 
					cout<<"������Ҫװ���Ľ��ı�ţ���Ҫ����������"<<endl;
					cin>>choose; 
					switch(choose){
						case 11:
							weapon1=1;
							bag[11]-=1;
							cout<<"��װ�� "<<weapon1name[weapon1]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 15:
							weapon1=2;
							bag[15]-=1;
							cout<<"��װ�� "<<weapon1name[weapon1]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 22:
							weapon1=3;
							bag[22]-=1;
							cout<<"��װ�� "<<weapon1name[weapon1]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 33:
							weapon1=4;
							bag[33]-=1;
							cout<<"��װ�� "<<weapon1name[weapon1]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;	
					}
				break;
				case 6://װ������ 
				break;
				case 7://װ������ 
					if(tool1!=0){
						cout<<"��װ�����ӣ���ж�º���װ����"<<endl;
						Sleep(2000);
						weapon();
					} 
					cout<<"������Ҫװ���ĸ��ӵı�ţ���Ҫ����������"<<endl;
					cin>>choose; 
					switch(choose){
						case 12:
							tool1=1;
							bag[12]-=1;
							cout<<"��װ�� "<<tool1name[tool1]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 16:
							tool1=2;
							bag[16]-=1;
							cout<<"��װ�� "<<tool1name[tool1]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 23:
							tool1=3;
							bag[23]-=1;
							cout<<"��װ�� "<<tool1name[tool1]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 34:
							tool1=4;
							bag[34]-=1;
							cout<<"��װ�� "<<tool1name[tool1]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;	
					}
				break;
				case 8://װ������ 
					if(tool2!=0){
						cout<<"��װ�����ӣ���ж�º���װ����"<<endl;
						Sleep(2000);
						weapon();
					} 
					cout<<"������Ҫװ���ĸ��ӵı�ţ���Ҫ����������"<<endl;
					cin>>choose; 
					switch(choose){
						case 13:
							tool2=1;
							bag[13]-=1;
							cout<<"��װ�� "<<tool2name[tool2]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 17:
							tool2=2;
							bag[17]-=1;
							cout<<"��װ�� "<<tool2name[tool2]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 24:
							tool2=3;
							bag[22]-=1;
							cout<<"��װ�� "<<tool2name[tool2]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 35:
							tool2=4;
							bag[35]-=1;
							cout<<"��װ�� "<<tool2name[tool2]<<" ��"<<endl;
							Sleep(2000);
							weapon();
						break;	
					}
				break;
			}
		break;
	}
	return;
}
void build(){//���� 
	system("cls");
	cout<<"�����Ž��콨��"<<endl<<endl; 
	cout<<"����0�˳�"<<endl<<endl;
	if(bag[9]>=1) cout<<"1 ����̨"<<endl;
	if(bag[18]>=1) cout<<"2 ��¯"<<endl; 
	cin>>choose;
	switch(choose){
		case 0:
			return;
		break; 
		case 1:
			if(bag[9]<1){
				cout<<"�������䣡"<<endl;
				Sleep(2000);
				build();
			}
			if(crafttable){
				cout<<"���Ѿ������ ����̨ �ˣ�"<<endl;
				Sleep(1500);
				build();
			}
			bag[9]-=1;
			cout<<"����ɹ������ڿɺϳɸ�����Ʒ��"<<endl;
			crafttable=true;
			Sleep(2000);
			build();
		break;
		case 2:
			if(bag[18]<1){
				cout<<"�������䣡"<<endl;
				Sleep(2000);
				build();
			}
			if(furnace){
				cout<<"���Ѿ������ ��¯ �ˣ�"<<endl;
				Sleep(1500); 
				build();
			}
			bag[18]-=1;
			cout<<"����ɹ������ڿ�������ʯ������<�ϳ�>���������������ö�дһ��������"<<endl;
			furnace=true;
			Sleep(3000);
			build();
		break;	
	}
}
void enemyattack(){
	
}
int main(){
	srand(time(0));
	cout<<"  	Welcome to MINECRAFT ! "<<endl;
	cout<<" 	 ��ӭ�����ҵ����磡    "<<endl<<endl;
	cout<<" 	 Made By Chenxuanhan   "<<endl;
	Sleep(1000);
	cout<<endl<<endl<<"��1��ʼ..."<<endl;
	cin>>choose;
	if(choose!=1){
		Sleep(1000);
		cout<<"������ͦ���ĵİ�...�����1����Ը��ô��"<<endl;
		Sleep(1500);
		cout<<"�Ǿ���������ĵ��..."<<endl;
		Sleep(3000);
		system("cls");
		int n=120;
		for(int i=1;i<=120;i++){
			cout<<"�㻹��Ҫ�ȴ�"<<n-i<<"��ſɽ�����Ϸ"<<endl;
			cout<<"��������϶����˳��ؿ���..."<<endl;
			Sleep(1000);
			system("cls");
		}
		cout<<"��ֻ�Ǹ���Ϸ��������"<<endl;
		Sleep(2000);
		cout<<"������ܵ������ӣ�����Ҳȷʵ�����ĵġ�"<<endl;
		Sleep(2000);
		cout<<"���ˣ���Ҳ���������ˣ�������Ҳ������д��ô��Ĵ��뻹û�����˿��ˡ�"<<endl;
		Sleep(2000);
	} 
	system("cls");
	cout<<"�����������..."<<endl; 
	cin>>name;
	cout<<"��..."<<endl;
	Sleep(1000);
	cout<<"����������������"<<name<<"��...��������֡�"<<endl;
	Sleep(2000);
	system("cls");
	cout<<"���� 1 �ۿ����飬�������������"<<endl;
	cin>>choose;
	if(choose==1) jvqing();
	system("cls");
	cout<<"���ڣ���ʼ��Ĵ���ɣ�"<<endl;
	cout<<"Create World..."<<endl; 
	Sleep(3000); 
	while(1){
		attack=basicattack+weapon1attack[weapon1];
		system("cls");
		cout<<"�������"<<name<<endl;
		cout<<"������λ��"<<place<<"."<<endl;
		cout<<"Ѫ����"<<health<<"/"<<maxhealth<<endl;
		cout<<"������"<<attack<<endl;
		cout<<"������"<<defense<<endl;
		cout<<"�ٶȣ�"<<speed<<endl;
		cout<<"�̱�ʯ��"<<money<<endl;
		cout<<"�ȼ���"<<level<<" ���飺"<<experience<<"/"<<level*100<<endl; 
		cout<<"-----------------------------------" <<endl; 
		cout<<"��Ҫ��ʲô��"<<endl;
		cout<<"1��ð��  2���̵�  3������  4���ڿ�  5������  6��ǰ��  7���ϳ�  8������  9��װ��"<<endl;
		cin>>choose;
		switch(choose){//ѡ�� 
			case 1://ð�� 
				system("cls");
				cout<<"�㿪ʼ��"<<place<<"ð��..."<<endl;
				Sleep(1000);
				explore(place);
			break;
			case 2://�̵� 
				system("cls");
				cout<<"������̵�"<<endl;
				Sleep(1000);
				shop(place);
			break;
			case 3://��鱳��1/2���鿴��ϸ��Ϣ�� 
				system("cls"); 
				cout<<"������Ʒ��ſɲ鿴��ϸ��Ϣ"<<endl<<endl;
				checkbag();
			break;
			case 4://�ڿ� 
				dig(place); 
			break;
			case 5://������ 
				tree(place);	
			break;
			case 6: //ǰ��ת��λ�á� 
				go();
			break;
			case 7://�ϳ� 
				create();
			break;
			case 8://���� 
				build();
			break;
			case 9://װ��
				weapon();
			break; 
		}
	}
	return 0;
}
