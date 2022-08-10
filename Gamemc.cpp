#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
string name,place="村庄";//玩家名字，玩家地点 
long long maxhealth=20,health=20,basicattack=2,attack=basicattack,attack2=basicattack,defense=0,money=0,experience=0,level=1,speed=2;//玩家基础数据 
int credit=50;//信誉值，玩家无法看见 
int weapon1=0,weapon2=0,tool1=0,tool2=0,attackdis1=2,attackdis2;//武器，装备 
int armor1=0,armor2=0,armor3=0,armor4=0; 
string weapon1name[10]={"空手","木剑","石剑","金剑","铁剑","钻石剑","下界合金剑"}; 
int weapon1attack[10]={0,4,5,6,7,8};
string weapon2name[10]={"无","弓","盾"}; 
string tool1name[10]={"无","木斧","石斧","金斧","铁斧","钻石斧","下界合金斧"}; 
string tool2name[10]={"无","木稿","石稿","金稿","铁稿","钻石稿","下界合金稿"}; 
string armor1name[10]={"无","皮革头盔","锁链头盔","金头盔","铁头盔","钻石头盔","下界合金头盔"};
string armor2name[10]={"无","皮革胸甲","锁链胸甲","金胸甲","铁胸甲","钻石胸甲","下界合金胸甲"};
string armor3name[10]={"无","皮革护腿","锁链护腿","金护腿","铁护腿","钻石护腿","下界合金护腿"};
string armor4name[10]={"无","皮革靴子","锁链靴子","金靴子","铁靴子","钻石靴子","下界合金靴子"};
int armor1defense[10]={0,1,2,2,3,4,5};
int armor2defense[10]={0,3,4,3,5,7,8};
int armor3defense[10]={0,2,3,3,4,6,7};
int armor4defense[10]={0,1,2,1,3,3,4}; 
//0空手 
bool nether=false,ender=false;//地狱门&末地门 建造/发现 
bool dead=false,defend=false,blessing=false;//敌人死亡 防御状态 notch祝福 
bool crafttable=false,furnace=false;//工作台 熔炉 
bool undeadattack=false;//亡灵入侵 
int badguy=0,weaponcheck=0,blesscold=0;
int task1=0;//task1:旅行家 收集10橡木 
int choose;//工具 
long long bag[1000]={0,100};//背包 
string itemname[1000]={"","橡木","丛林木","针叶木","绯红菌柄","橡木木板","从林木木板","针叶木木板","绯红木板","工作台","木棍","木剑","木斧","木稿","圆石","石剑","石斧","石稿","熔炉","煤炭","铁矿石","铁锭","铁剑","铁斧","铁镐","铁头盔","铁胸甲","铁护腿","铁靴子","护盾","弓","金矿石","金锭","金剑","金斧","金稿","苹果","金苹果","线","金头盔","金胸甲","金护腿","金靴子"};//物品名 
/*物品编号：
1橡木 2从林木 3针叶木 4绯红菌柄 5橡木木板 6从林木木板 7针叶木木板 8绯红木板 
9工作台 10木棍 11木剑 12木斧 13木稿 14圆石 15石剑 16石斧 
17石稿 18熔炉 19煤炭 20铁矿石 21铁锭 22铁剑 23铁斧 24铁镐
25铁头盔 26铁胸甲 27铁护腿 28铁靴子 29护盾 30弓 31金矿石 32金锭
33金剑 34金斧 35金稿 36苹果 37金苹果 38线 39金头盔 40金胸甲 
41金护腿 42金靴子  
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
void create(){//合成 
	system("cls");
	cout<<"以下是你可以合成的物品列表。"<<endl;
	cout<<"输入合成编号以合成。"<<endl<<endl;
	if(bag[1]>0) cout<<"编号"<<5<<": 合成 "<<itemname[5]<<"x4 需要 "<<itemname[1]<<"x1"<<endl; //木板 
	if(bag[2]>0) cout<<"编号"<<6<<": 合成 "<<itemname[6]<<"x4 需要 "<<itemname[2]<<"x1"<<endl;
	if(bag[3]>0) cout<<"编号"<<7<<": 合成 "<<itemname[7]<<"x4 需要 "<<itemname[3]<<"x1"<<endl;
	if(bag[4]>0) cout<<"编号"<<8<<": 合成 "<<itemname[8]<<"x4 需要 "<<itemname[4]<<"x1"<<endl;
	if(bag[5]>3) cout<<"编号"<<9<<": 合成 "<<itemname[9]<<"x1 需要 "<<itemname[5]<<"x4"<<endl;//工作台 
	if(bag[6]>3) cout<<"编号"<<9<<": 合成 "<<itemname[9]<<"x1 需要 "<<itemname[6]<<"x4"<<endl;
	if(bag[7]>3) cout<<"编号"<<9<<": 合成 "<<itemname[9]<<"x1 需要 "<<itemname[7]<<"x4"<<endl;
	if(bag[8]>3) cout<<"编号"<<9<<": 合成 "<<itemname[9]<<"x1 需要 "<<itemname[8]<<"x4"<<endl;
	if(bag[5]>=2) cout<<"编号"<<10<<": 合成 "<<itemname[10]<<"x4 需要 "<<itemname[5]<<"x2"<<endl;//木棍 
	if(bag[6]>=2) cout<<"编号"<<10<<": 合成 "<<itemname[10]<<"x4 需要 "<<itemname[6]<<"x2"<<endl;
	if(bag[7]>=2) cout<<"编号"<<10<<": 合成 "<<itemname[10]<<"x4 需要 "<<itemname[7]<<"x2"<<endl;
	if(bag[8]>=2) cout<<"编号"<<10<<": 合成 "<<itemname[10]<<"x4 需要 "<<itemname[8]<<"x2"<<endl;
	if(bag[5]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<11<<": 合成 "<<itemname[11]<<"x1 需要 "<<itemname[5]<<"x2,"<<itemname[10]<<"x1"<<endl;//木剑 
	if(bag[6]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<11<<": 合成 "<<itemname[11]<<"x1 需要 "<<itemname[6]<<"x2,"<<itemname[10]<<"x1"<<endl;
	if(bag[7]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<11<<": 合成 "<<itemname[11]<<"x1 需要 "<<itemname[7]<<"x2,"<<itemname[10]<<"x1"<<endl;
	if(bag[8]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<11<<": 合成 "<<itemname[11]<<"x1 需要 "<<itemname[8]<<"x2,"<<itemname[10]<<"x1"<<endl;
	if(bag[5]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<12<<": 合成 "<<itemname[12]<<"x1 需要 "<<itemname[5]<<"x3,"<<itemname[10]<<"x2"<<endl;//木斧 
	if(bag[6]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<12<<": 合成 "<<itemname[12]<<"x1 需要 "<<itemname[6]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[7]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<12<<": 合成 "<<itemname[12]<<"x1 需要 "<<itemname[7]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[8]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<12<<": 合成 "<<itemname[12]<<"x1 需要 "<<itemname[8]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[5]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<13<<": 合成 "<<itemname[13]<<"x1 需要 "<<itemname[5]<<"x3,"<<itemname[10]<<"x2"<<endl;//木稿 
	if(bag[6]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<13<<": 合成 "<<itemname[13]<<"x1 需要 "<<itemname[6]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[7]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<13<<": 合成 "<<itemname[13]<<"x1 需要 "<<itemname[7]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[8]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<13<<": 合成 "<<itemname[13]<<"x1 需要 "<<itemname[8]<<"x3,"<<itemname[10]<<"x2"<<endl;
	if(bag[14]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<15<<": 合成 "<<itemname[15]<<"x1 需要 "<<itemname[14]<<"x2,"<<itemname[10]<<"x1"<<endl;//石剑 
	if(bag[14]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<16<<": 合成 "<<itemname[16]<<"x1 需要 "<<itemname[14]<<"x3,"<<itemname[10]<<"x2"<<endl;//石斧 
	if(bag[14]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<17<<": 合成 "<<itemname[17]<<"x1 需要 "<<itemname[14]<<"x3,"<<itemname[10]<<"x2"<<endl;//石稿 
	if(bag[14]>=8&&crafttable) cout<<"编号"<<18<<": 合成"<<itemname[18]<<"x1 需要"<<itemname[14]<<"x8"<<endl;//熔炉 
	if(bag[19]>=1&&bag[20]>=1&&furnace) cout<<"编号"<<21<<": 熔炼"<<itemname[21]<<"x1 需要"<<itemname[19]<<"x1,"<<itemname[20]<<"x1"<<endl;//铁锭 
	if(bag[21]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<22<<": 合成 "<<itemname[22]<<"x1 需要 "<<itemname[21]<<"x2,"<<itemname[10]<<"x1"<<endl;//铁剑 
	if(bag[21]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<23<<": 合成 "<<itemname[23]<<"x1 需要 "<<itemname[21]<<"x3,"<<itemname[10]<<"x2"<<endl;//铁斧 
	if(bag[21]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<24<<": 合成 "<<itemname[24]<<"x1 需要 "<<itemname[21]<<"x3,"<<itemname[10]<<"x2"<<endl;//铁稿 
	if(bag[21]>=5&&crafttable) cout<<"编号"<<25<<": 合成 "<<itemname[25]<<"x1 需要 "<<itemname[21]<<"x5"<<endl;//铁头盔 
	if(bag[21]>=8&&crafttable) cout<<"编号"<<26<<": 合成 "<<itemname[26]<<"x1 需要 "<<itemname[21]<<"x8"<<endl;//铁胸甲 
	if(bag[21]>=7&&crafttable) cout<<"编号"<<27<<": 合成 "<<itemname[27]<<"x1 需要 "<<itemname[21]<<"x7"<<endl;//铁护腿 
	if(bag[21]>=4&&crafttable) cout<<"编号"<<28<<": 合成 "<<itemname[28]<<"x1 需要 "<<itemname[21]<<"x4"<<endl;//铁靴子 
	if(bag[5]>=6&&bag[21]>=1&&crafttable) cout<<"编号"<<29<<": 合成 "<<itemname[29]<<"x1 需要 "<<itemname[21]<<"x1,"<<itemname[5]<<"x6"<<endl;//护盾 
	if(bag[6]>=6&&bag[21]>=1&&crafttable) cout<<"编号"<<29<<": 合成 "<<itemname[29]<<"x1 需要 "<<itemname[21]<<"x1,"<<itemname[6]<<"x6"<<endl;
	if(bag[7]>=6&&bag[21]>=1&&crafttable) cout<<"编号"<<29<<": 合成 "<<itemname[29]<<"x1 需要 "<<itemname[21]<<"x1,"<<itemname[7]<<"x6"<<endl;
	if(bag[8]>=6&&bag[21]>=1&&crafttable) cout<<"编号"<<29<<": 合成 "<<itemname[29]<<"x1 需要 "<<itemname[21]<<"x1,"<<itemname[8]<<"x6"<<endl;
	if(bag[38]>=3&&bag[10]>=3&&crafttable) cout<<"编号"<<30<<": 合成 "<<itemname[30]<<"x1 需要 "<<itemname[38]<<"x3,"<<itemname[10]<<"x3"<<endl;//铁稿 
	if(bag[19]>=1&&bag[31]>=1&&furnace) cout<<"编号"<<32<<": 熔炼"<<itemname[32]<<"x1 需要"<<itemname[19]<<"x1,"<<itemname[31]<<"x1"<<endl;//金锭 
	if(bag[32]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<33<<": 合成 "<<itemname[33]<<"x1 需要 "<<itemname[32]<<"x2,"<<itemname[10]<<"x1"<<endl;//金剑 
	if(bag[32]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<34<<": 合成 "<<itemname[34]<<"x1 需要 "<<itemname[32]<<"x3,"<<itemname[10]<<"x2"<<endl;//金斧 
	if(bag[32]>=3&&bag[10]>=2&&crafttable) cout<<"编号"<<35<<": 合成 "<<itemname[35]<<"x1 需要 "<<itemname[32]<<"x3,"<<itemname[10]<<"x2"<<endl;//金稿
	if(bag[32]>=8&&bag[36]>=1&&crafttable) cout<<"编号"<<37<<": 合成 "<<itemname[37]<<"x1 需要 "<<itemname[32]<<"x8,"<<itemname[36]<<"x1"<<endl;//金苹果 
	if(bag[32]>=5&&crafttable) cout<<"编号"<<39<<": 合成 "<<itemname[39]<<"x1 需要 "<<itemname[32]<<"x5"<<endl;//金头盔 
	if(bag[32]>=8&&crafttable) cout<<"编号"<<40<<": 合成 "<<itemname[40]<<"x1 需要 "<<itemname[32]<<"x8"<<endl;//金胸甲 
	if(bag[32]>=7&&crafttable) cout<<"编号"<<41<<": 合成 "<<itemname[41]<<"x1 需要 "<<itemname[32]<<"x7"<<endl;//金护腿 
	if(bag[32]>=4&&crafttable) cout<<"编号"<<42<<": 合成 "<<itemname[42]<<"x1 需要 "<<itemname[32]<<"x4"<<endl;//金靴子	
	cout<<endl<<"输入0返回"<<endl;
	cin>>choose;
	switch(choose){
		case 0:
			return;	
		break;
		case 5://橡木木板 
			if(bag[1]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[1]--;
			bag[5]+=4;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;	
		case 6://从林木木板 
			if(bag[2]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[2]--;
			bag[6]+=4;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 7://针叶木木板 
			if(bag[3]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[3]--;
			bag[7]+=4;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 8://绯红木板 
			if(bag[4]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[4]--;
			bag[8]+=4;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 9://工作台 craft(ing)table 
			if(bag[5]>=4) cout<<"1，使用橡木木板合成";
			if(bag[6]>=4)" 2，从林木木板";
			if(bag[7]>=4)" 3，针叶木木板";
			if(bag[8]>=4)" 4，绯红木板";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<4){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=4;
					bag[9]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<4){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=4;
					bag[9]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<4){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=4;
					bag[9]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<4){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=4;
					bag[9]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;	
		case 10://木棍 
			if(bag[5]>=2) cout<<"1，使用橡木木板合成";
			if(bag[6]>=2)" 2，从林木木板";
			if(bag[7]>=2)" 3，针叶木木板";
			if(bag[8]>=2)" 4，绯红木板";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=2;
					bag[10]+=4;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=2;
					bag[10]+=4;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=2;
					bag[10]+=4;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=2;
					bag[10]+=4;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;
		case 11://木剑 
			if(bag[10]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			if(bag[5]>=2) cout<<"1，使用橡木木板合成";
			if(bag[6]>=2)" 2，从林木木板";
			if(bag[7]>=2)" 3，针叶木木板";
			if(bag[8]>=2)" 4，绯红木板";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;
		case 12://木斧 
			if(bag[10]<2){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			if(bag[5]>=3) cout<<"1，使用橡木木板合成";
			if(bag[6]>=3)" 2，从林木木板";
			if(bag[7]>=3)" 3，针叶木木板";
			if(bag[8]>=3)" 4，绯红木板";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<3){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=3;
					bag[10]-=2;
					bag[12]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<3){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=3;
					bag[10]-=2;
					bag[12]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<3){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=3;
					bag[10]-=2;
					bag[12]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<3){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=3;
					bag[10]-=2;
					bag[12]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;
		case 13://木稿 
			if(bag[10]<2){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			if(bag[5]>=3) cout<<"1，使用橡木木板合成";
			if(bag[6]>=3)" 2，从林木木板";
			if(bag[7]>=3)" 3，针叶木木板";
			if(bag[8]>=3)" 4，绯红木板";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<3){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=3;
					bag[10]-=2;
					bag[13]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<3){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=3;
					bag[10]-=2;
					bag[13]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<3){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=3;
					bag[10]-=2;
					bag[13]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<3){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=3;
					bag[10]-=2;
					bag[13]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;
		case 15://石剑 
			if(bag[14]<2||bag[10]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[14]-=2;
			bag[10]-=1;
			bag[15]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 16://石斧 
			if(bag[14]<3||bag[10]<2){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[14]-=3;
			bag[10]-=2;
			bag[16]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 17://石稿 
			if(bag[14]<3||bag[10]<2){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[14]-=3;
			bag[10]-=2;
			bag[17]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 18://熔炉furnace 
			if(bag[14]<8){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[14]-=8;
			bag[18]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 21://铁锭 
			if(bag[19]<1||bag[20]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[19]-=1;
			bag[20]-=1;
			bag[21]+=1;
			cout<<"熔炼成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 22://铁剑 
			if(bag[21]<2||bag[10]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=1;
			bag[21]-=2;
			bag[22]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 23://铁斧 
			if(bag[21]<3||bag[10]<2){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=2;
			bag[21]-=3;
			bag[23]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 24://铁稿 
			if(bag[21]<3||bag[10]<2){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=2;
			bag[21]-=3;
			bag[24]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 25://铁头盔 
			if(bag[21]<5){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[21]-=5;
			bag[25]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 26://铁胸甲 
			if(bag[21]<8){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[21]-=8;
			bag[27]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 27://铁护腿 
			if(bag[21]<7){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[21]-=7;
			bag[27]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 28://铁靴子 
			if(bag[21]<4){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[21]-=4;
			bag[28]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 29://护盾 
			if(bag[21]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			if(bag[5]>=6) cout<<"1，使用橡木木板合成";
			if(bag[6]>=6)" 2，从林木木板";
			if(bag[7]>=6)" 3，针叶木木板";
			if(bag[8]>=6)" 4，绯红木板";
			cout<<endl;
			cin>>choose;
			switch(choose){
				case 1:
					if(bag[5]<6){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[5]-=6;
					bag[21]-=1;
					bag[29]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 2:
					if(bag[6]<6){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[6]-=6;
					bag[21]-=1;
					bag[29]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 3:
					if(bag[7]<6){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[7]-=6;
					bag[21]-=1;
					bag[29]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
				case 4:
					if(bag[8]<6){
						cout<<"请勿乱输！"<<endl;
						Sleep(1000);
						create();
					}
					bag[8]-=6;
					bag[21]-=1;
					bag[29]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(1000);
					create();
				break;
			}
		break;
		case 30://弓 
			if(bag[38]<3||bag[10]<3){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=3;
			bag[38]-=3;
			bag[30]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 32://金锭 
			if(bag[19]<1||bag[31]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[19]-=1;
			bag[31]-=1;
			bag[32]+=1;
			cout<<"熔炼成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 33://金剑 
			if(bag[32]<2||bag[10]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=1;
			bag[32]-=2;
			bag[33]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 34://金斧 
			if(bag[32]<3||bag[10]<2){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=2;
			bag[32]-=3;
			bag[34]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 35://金稿 
			if(bag[32]<3||bag[10]<2){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[10]-=2;
			bag[32]-=3;
			bag[35]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 37://金苹果 
			if(bag[32]<8||bag[36]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[36]-=1;
			bag[32]-=8;
			bag[37]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 39://金头盔 
			if(bag[32]<5){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[32]-=5;
			bag[39]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 40://金胸甲 
			if(bag[32]<8){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[32]-=8;
			bag[39]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 41://金护腿 
			if(bag[32]<7){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[32]-=7;
			bag[39]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
		case 42://金靴子 
			if(bag[32]<4){
				cout<<"请勿乱输！"<<endl;
				Sleep(1000);
				create();
			}
			bag[32]-=4;
			bag[39]+=1;
			cout<<"合成成功！"<<endl;
			Sleep(1000);
			create();
		break;
	}
} 
void fight(string MN,int MH,int MA,int Mrand,int MD,int MS,int dis,int Adis,int xp,int Mmoney){//战斗 敌人名 敌人生命 敌人最小攻击 浮动值 敌人防御 敌人速度 当前距离 敌人攻击距离 经验值 绿宝石 
	bool back=true;
	system("cls");
	while(!dead){
		cout<<"你的血量（"<<health<<"/"<<maxhealth<<"）"<<"   "<<"敌人血量： "<<MH<<endl;
		cout<<"攻击："<<attack<<endl;
		cout<<"防御："<<defense<<endl;
		cout<<"速度："<<speed<<endl;
		cout<<"当前你和敌人的距离为"<<dis<<endl<<endl;
		cout<<"现在是你的回合！"<<endl;
		cout<<"你要？"<<endl;
		cout<<"1，攻击（使用当前主手武器）  2，使用副手装备  3，使用药水  4，打开背包  5，技能  6，移动"<<endl;
		cin>>choose;
		switch(choose){
			case 1:
				if(dis<=attackdis1){
					cout<<"你使用 "<<weapon1name[weapon1]<<" 对 "<<MN<<" 进行攻击！"<<endl;
					Sleep(1000);
					int damage=attack*(100+rand()%20-rand()%20)/100*(100-MD)/100; //浮动伤害 
					cout<<MN<<" 受到了 "<<damage<<" 点伤害！" <<endl;
					MH-=damage;
					Sleep(1000);
					cout<<"当前 "<<MN<<" 还有 "<<MH<<" 点生命值！" <<endl;    
					Sleep(1500);         
					system("cls");
				}else{
					cout<<"距离太远，无法攻击！"<<endl;	
					Sleep(2000);
					cout<<"你跳过了本回合"<<endl;
					Sleep(2000); 
					system("cls");
				} 
			break;
			case 2:
				if(weapon2==0){
					cout<<"副手未装备武器！" <<endl;
					Sleep(2000);
					cout<<"你跳过了本回合"<<endl;
					Sleep(2000); 
					system("cls");
				}
				if(weapon2==1){//弓 
					if(dis<=attackdis2){
						cout<<"你使用 "<<weapon2name[weapon2]<<" 对 "<<MN<<" 进行攻击！"<<endl;
						Sleep(1000);
						int damage=attack2*(100+rand()%20-rand()%20)/100*(100-MD)/100; //浮动伤害 
						MH-=damage;
						cout<<MN<<" 受到了 "<<damage<<" 点伤害！" <<endl;
						Sleep(1000);
						cout<<"当前 "<<MN<<" 还有 "<<MH<<" 点生命值！" <<endl;    
						Sleep(1500);         
						system("cls");
					}else{
						cout<<"距离太远，无法攻击！"<<endl;
						Sleep(2000);
						cout<<"你跳过了本回合"<<endl;
						Sleep(2000); 
						system("cls");
					}
				}
				if(weapon2==2){
					cout<<"你举起盾牌！下次受到伤害时你的防御大幅增加！"<<endl;//盾牌 
					defend=true;//防御状态 
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
				cout<<"1，向前移动 2，向后移动"<<endl;//移动 
				cin>>choose;
				switch(choose){
					case 1:
						cout<<"移动多少格？"<<endl;
						cin>>choose;
						if(choose<=speed){
							if(dis>=choose) dis-=choose;
							else dis=0;
						}
						cout<<name<<" 向 "<<MN<<" 逼近了！"<<endl;
						Sleep(1000);
						cout<<"当前你和敌人的距离为"<<dis<<endl;
						Sleep(1500);
						system("cls");
					break;
					case 2:
						cout<<"移动多少格？"<<endl;
						cin>>choose;
						if(choose<=speed) dis+=choose;
						cout<<name<<" 后退了！"<<endl;
						Sleep(1000);
						cout<<"当前你和敌人的距离为"<<dis<<endl;
						Sleep(1500);
						system("cls");
					break;
				}
			break;
		} 
		if(MH<=0){
			cout<<MN<<" 战败！"<<endl;//我方胜利 
			Sleep(1500);
			cout<<"你胜利了！"<<endl;
			Sleep(1000);
			cout<<"获得经验 "<<xp<<" 点"<<endl; 
			experience+=xp;
			Sleep(1000);
			cout<<"你升了 "<<levelup(experience)<<" 级！"<<endl;
			level+=levelup(experience);
			Sleep(500);
			cout<<"当前等级："<<level<<endl;
         	dead=true;
			Sleep(1000);
			cout<<"你获得 "<<Mmoney<<" 颗绿宝石"<<endl;
			money+=Mmoney;
			Sleep(2000);
			system("cls");
			return;
		}
		cout<<"你的血量（"<<health<<"/"<<maxhealth<<"）"<<"   "<<"敌人血量： "<<MH<<endl;//敌人回合 
		cout<<"攻击："<<attack<<endl;
		cout<<"防御："<<defense<<endl;
		cout<<"速度："<<speed<<endl;
		cout<<"当前你和敌人的距离为"<<dis<<endl<<endl;
		cout<<MN<<" 的回合！"<<endl; 
		if(Adis<5){//近战怪物AI 
			if(dis<=Adis){
				cout<<MN<<" 对 "<<name<<" 进行攻击！"<<endl; 
				Sleep(1000);
				int damage;
				if(defend){
					defend=false;
					damage=(MA+rand()%Mrand)*(100+rand()%20-rand()%20)*(100-defense-40)/10000; 
				}else damage=damage=(MA+rand()%Mrand)*(100+rand()%20-rand()%20)*(100-defense)/10000;//浮动伤害 
				health-=damage;
				cout<<"你受到了 "<<damage<<" 点伤害！"<<endl;
				Sleep(1000);
				cout<<"你还剩 "<<health<<" 点生命！"<<endl;
				Sleep(1500);
				system("cls");	
			}else{
				if(dis>=MS) dis-=MS;
				else dis=0;
				cout<<MN<<" 向 "<<name<<" 逼近了！"<<endl;
				Sleep(1000);
				cout<<"当前你和敌人的距离为"<<dis<<endl;
				Sleep(1500);
				system("cls");
			}	
		}else{//远程怪物AI 
			if(dis<=Adis/3&&back==true){//与玩家距离小于1/3攻击距离，后退 
				dis+=MS;
				cout<<MN<<" 后退了！"<<endl;
				Sleep(1000);
				cout<<"当前你和敌人的距离为"<<dis<<endl;
				Sleep(1500);
				system("cls");
				back=false;	
			}else{
				back=true;
				if(dis>Adis){//距离过远，前进 
					if(dis-=MS>=0) dis-=MS;
					else dis=0;
					cout<<MN<<" 向 "<<name<<" 逼近了！"<<endl;
					Sleep(1000);
					cout<<"当前你和敌人的距离为"<<dis<<endl;
					Sleep(1500);
					system("cls");
				}else{//与玩家距离适合，攻击 
					cout<<MN<<" 对 "<<name<<" 进行攻击！"<<endl;
					Sleep(1000);
					int damage;
					if(defend){
						defend=false;
						damage=(MA+rand()%Mrand)*(100+rand()%20-rand()%20)*(100-defense-40)/10000;  
					}else damage=(MA+rand()%Mrand)*(100+rand()%20-rand()%20)*(100-defense)/10000;//浮动伤害
					health-=damage;
					cout<<"你受到了 "<<damage<<" 点伤害！"<<endl;
					Sleep(1000);
					cout<<"你还剩 "<<health<<" 点生命！"<<endl;
					Sleep(1500);
					system("cls");
				}	
			}
		}
		if(health<=0){
			if(blessing){//祝福，复活 保留1/4血 
				cout<<"Notch之祝福生效！"<<endl;
				Sleep(2000);
				health=0;
				health+=maxhealth/4;
				blessing=false;
				cout<<"你回复25%生命值，继续战斗！"<<endl; 
				Sleep(2000);
				system("cls");
			}else{
				cout<<"你死了！"<<endl;
				place="村庄"; 
				Sleep(3000);
				health=2;
				system("cls");
			return;
			}
		}
	}
	return;	
}
void shop(string place){//商店 
	if(place=="村庄"){
		cout<<"欢迎来到村庄商店！"<<endl;
		Sleep(500);
		cout<<"请问您要买什么？"<<endl; 
		cout<<"(当前你有"<<money<<"个绿宝石)"<<endl;
		cout<<"0，离开  1，武器  2，工具  3，药水"<<endl; 
		cin>>choose;
		switch(choose){
			case 0:
				return;
			break;
			case 1:
				cout<<"木剑-价格3绿宝石 \n";
				cout<<"石剑-价格8绿宝石 \n";	
		} 
	}
}
void explore(string place){//探索 
	if(place=="村庄"){		
		switch(rand()%10){
			case 0:
			cout<<"你遇到了铁傀儡！"<<endl;
			cout<<"0，离开  1，激怒"<<endl;
			cin>>choose;
			if(choose==1){
				fight("铁傀儡",100,8,6,40,2,10,3,500,5);
				credit-=20;
				if(dead){
					dead=false;
					cout<<"获得 2 个铁锭！"<<endl;
					bag[21]+=2;
				}
			}else{
				cout<<"你远离了铁傀儡"<<endl; 
				Sleep(1000);
				break;
			}
			break;
			case 1:
			if(badguy==0){
				cout<<"你看见了一名恶霸正在欺负一名村民..."<<endl;
				cout<<"1，阻止  2，离开  3，一起欺负"<<endl;
				cin>>choose;
				if(choose==1){
					cout<<"战斗！"<<endl;
					Sleep(2000);
					fight("恶霸村民",20,1,1,0,2,5,2,100,1);
					if(dead){
						credit+=5;
						dead=false;
						Sleep(2000);
						cout<<"你走到那名恶霸面前，说："<<endl;
						Sleep(2000);
						cout<<"以后不要再欺负别人了！"<<endl;
						Sleep(2000);
						cout<<"恶霸看了你一眼，灰溜溜的跑了"<<endl;
						badguy=2;
						Sleep(2000);
						cout<<"被欺负的村民十分感激，给了你3颗绿宝石"<<endl;
              		 	money+=3;      
						Sleep(3000);
					}else{
						credit-=5;
						cout<<"恶霸走到你面前，嘲讽道：不过如此！还想见义勇为？"<<endl;
						Sleep(2000);
						cout<<"那我就成全你，他的钱我不要了，你的钱给我！！！"<<endl;
						Sleep(2000);
						money=0;
						cout<<"你的钱被恶霸全部拿走了..."<<endl; 
						Sleep(2000);
					}
				}else{
					if(choose==2){
						cout<<"你默默走开了。"<<endl;
						Sleep(2000);
						credit-=15;
					}else{
						cout<<"你冲过去，推开了恶霸，自己抢走村民身上所有的绿宝石。"<<endl;
						money+=6;
						Sleep(1500);
						cout<<"获得了6颗绿宝石！"<<endl;
						credit-=25;
						badguy=1;
						Sleep(2000);
					}
				}
			}else if(badguy==2){
				cout<<"你又遇到了之前欺负人的村民"<<endl;
				Sleep(1500);
				cout<<"那位村民告诉你，雪地有一个村民发布了任务，完成了就有丰厚的奖品"<<endl;
				Sleep(2000);
				cout<<"临走前，他给了你2颗绿宝石"<<endl;
				money+=2;
				badguy=3;
				Sleep(2000);
			}
			break;	
			case 2:
				cout<<"你在地上发现了1颗绿宝石！"<<endl;
				money+=1;
				Sleep(2000);	
			break;
			case 3:
				cout<<"你来到了村庄旅馆"<<endl;
				Sleep(1000);
				cout<<"0，离开  1，进入"<<endl;
				cin>>choose;
				if(choose==1){
					if(credit<=30){
						cout<<"你刚进去，就有个人喊：那是个坏人！"<<endl;
						Sleep(2000);
						cout<<"里面的人看到你，连忙将你赶出去"<<endl;
						Sleep(2000);
						cout<<"店主看到你，说：你不配住我的旅馆！"<<endl;
                 Sleep(2000);     
					}else{
						cout<<"你走进旅馆"<<endl;
						Sleep(2000);
						cout<<"当前你有 "<<money<<" 颗绿宝石"<<endl; 
						cout<<"要休息吗？需要5颗绿宝石（休息可恢复生命值）"<<endl;
						cout<<"0，离开  1，休息"<<endl;
						cin>>choose;
						if(choose==1){
							if(money<5){
								cout<<"你突然发现自己的钱不够，你只好尴尬的走了"<<endl;
								Sleep(2000);
								credit-=10;
							}else{
								system("cls");
								cout<<"店主给你开了一间房，你在里面美美的睡了一觉..."<<endl;
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
				cout<<"你遇见了村庄中德高望重的老者-图书管理员"<<endl; 
				Sleep(1000);
				cout<<"这位老者知晓这个世界上的种种事情..."<<endl<<endl;
				Sleep(1500);
				if(credit<=30){
					cout<<"图书管理员只是轻轻扫视过你身上，你就感觉内心仿佛被审视了一般"<<endl;
					Sleep(1500);
					cout<<"你感觉罪恶爬上了你的脊梁..."<<endl;
					Sleep(1500);
					cout<<"“你都做了什么，没有人比你更清楚，即使是遇见弱小者也不愿伸手援助，甚至助纣为虐...”"<<endl;
					Sleep(1500);
					cout<<"顷刻间，图书管理员便消失在你的视线中..."<<endl;
					Sleep(2000); 
				}else{
					cout<<"你要与图书管理员交谈吗？（0，离开  1，交谈）"<<endl;
					cin>>choose;
					if(choose==1){
						cout<<"你要询问什么？"<<endl;
						cout<<"1，关于远古时期的战争"<<endl;
						cout<<"2，Herobrine的信徒/势力"<<endl;
						cout<<"3，Herobrine归来的传言"<<endl;
						cout<<"4，关于创世之力"<<endl;
						cout<<"5，关于亡灵势力"<<endl; 
						cout<<"6，关于地狱"<<endl;
						cout<<"7，关于末地"<<endl;
						cin>>choose;
						switch(choose){
							case 1:
								system("cls");
								Sleep(2000); 
								cout<<"在远古时期，也就是这个世界刚被创造出的时候，世界上有两位神，也就是Notch和Herobrine，而这两位神是兄弟。"<<endl; 
								cout<<"因Herobrine创造了亡灵生物，两人意见逐渐不和，最终他们的关系分崩离析。"<<endl;
								cout<<"Notch本与Herobrine互不干涉，但Herobrine创造出的亡灵生物组成了一支亡灵大军----"<<endl;
								cout<<"这支亡灵大军四处前进，所过之处血流成河，尸骨遍地..."<<endl;
								cout<<"Notch看着方块世界生灵涂炭，决心阻止Herobrine，而这就是战争的导火索..."<<endl;
								cout<<"亡灵生物可以将死去的生灵转变为亡灵，当时的人类只得四处逃亡。"<<endl;
								cout<<"Notch使用了大量的「 创世之力」才成功解决了一大部分的亡灵，但仍有部分亡灵侥幸活了下来。"<<endl;
								cout<<"而后，Notch已经没有足够的力量对付Herobrine了，他只好用出剩余的「 创世之力」，将Herobrine封印在了地狱..."<<endl;
								cout<<"但是，似乎Herobrine正积蓄着力量，破开封印..."<<endl<<endl;
								cout<<"图书管理员叹了口气。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								}     
							break;
							case 2:
								system("cls");
								Sleep(2000); 
								cout<<"早在创世初期，Herobrine就展示出了与他的哥哥截然不同的性格。"<<endl; 
								cout<<"他放荡不羁，将自己当作众生的主宰，将世界当作自己的游戏。"<<endl;
								cout<<"早期，Herobrine还不至于做些太出格的事情。"<<endl;
								cout<<"但随着时间推移，Herobrine越来越狂妄，开始向世界各地建立自己的势力。"<<endl;
								cout<<"他用自己的「 混沌之力」和亡灵创造出了一个又一个他的忠实手下。"<<endl;
								cout<<"后来，他又凭借着自己强大的力量，收服了世界各地的一个个强者，并用自己的力量使他们变得更强。"<<endl;
								cout<<"而Herobrine自身也在世界上留有一些自己的虚影。这些虚影代表着Herobrine，但实力仅有本体的千分之一。"<<endl;
								cout<<"像 NULL，恐惧魔王，Entity_303等...都是Herobrine忠实的手下。"<<endl;
								cout<<"若他们联合起来，集结所有的力量，Herobrine很可能将会破开封印，重回世界..."<<endl<<endl;
								cout<<"图书管理员的面色变得凝重。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 3: 
								system("cls");
								Sleep(2000); 
								cout<<"Herobrine的归来..."<<endl; 
								cout<<"这不是谣言，也许很快就会发生...创世神Notch已不知所踪，地狱的恐惧魔王已经集结了猪人们，Herobrine很可能会破开封印。"<<endl;
								cout<<"在遥远的边境之地，那里混合着创世之力与混沌之力，地面被拉伸成一堵高墙，一切事物都变得混乱。"<<endl;
								cout<<"而Null，就在边境之地..."<<endl;
								cout<<"Herobrine曾经的势力，必将会不惜所有代价，强行打破Herobrine的封印..."<<endl;
								cout<<"图书管理员的面色变得凝重。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 4:
								system("cls");
								Sleep(2000); 
								cout<<"创世之力，便是Notch所拥有的神力。"<<endl; 
								cout<<"这种神力拥有着创造的能力，是最纯粹，最强大的力量。"<<endl;
								cout<<"Herobrine所拥有的，便是混沌之力。与Notch相反，充满着破坏，不稳定性。"<<endl;
								cout<<"正是当初Notch和Herobrine联手，消耗了大量神力，才创造出了这个世界。"<<endl;
								cout<<"而也只有创世之力，才能抗衡Herobrine的混沌之力。"<<endl;
								cout<<"但Notch在大战后便消失了踪迹，创世之力也不知道在哪里..."<<endl;
								cout<<"图书管理员的面色变得凝重。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 5:
								system("cls");
								Sleep(2000); 
								cout<<"亡灵生物，是Herobrine用亡灵之力与混沌之力创造出的。"<<endl; 
								cout<<"这种生物可以将死去的生灵转变成亡灵。"<<endl;
								cout<<"也就是说，通过亡灵的四处吞噬，感染，可以轻易的组成一支亡灵大军。"<<endl;
								cout<<"而Herobrine正是凭借着数量庞大的亡灵军队，才得以与Notch抗衡。"<<endl;
								cout<<"Herobrine曾经忠心耿耿的下属，亡灵的领导者Blackbone组织着亡灵生物们..."<<endl;
								cout<<"尽管Notch拥有创世之力，但也无法彻底除掉亡灵。"<<endl;
								cout<<"“这将是一个致命的威胁。”图书管理员的面色变得凝重。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 	
							break;	
							case 6:
								system("cls");
								Sleep(2000); 
								cout<<"地狱，一个充斥着岩浆与狱岩的地方。传说也是封印Herobrine的地方..."<<endl; 
								cout<<"地狱危机重重，要时刻小心跌入岩浆，还要提防可怕的恶魂，岩浆怪"<<endl;
								cout<<"而在地狱中，有一种特殊的种族--猪灵。"<<endl;
								cout<<"猪灵是一种贪财的生物，给他们金锭便能与他们交易，但你却不能知道自己能得到什么。"<<endl;
								cout<<"地狱的深处还隐藏着一种重金属，叫下界合金。这些合金需要在地狱的深处挖掘坚硬的远古残骸提炼而成。"<<endl;
								cout<<"另外，地狱中还暗藏着一些猪灵的堡垒，以及下界要塞，这些地方都隐藏着珍贵的宝藏，以及--无穷的危机。"<<endl;
								cout<<"图书管理员的叹了口气。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 7:
								system("cls");
								Sleep(2000); 
								cout<<"末地，一个位于虚空的另一维度。"<<endl; 
								cout<<"那里矗立着几根黑曜石柱，在末地的主岛上还有一条巨龙。"<<endl;
								cout<<"在末地里，四处充斥着末影人。这里的末影人都是在时空缝隙中不小心穿越过来的。"<<endl;
								cout<<"打败末影龙后，就可以前往末地的外岛了。外岛中散布着一些末地城，这些城市里面藏着许多宝藏。"<<endl;
								cout<<"但要打败末影龙可不容易，黑曜石柱上的末影水晶会为末影龙持续恢复力量。"<<endl;
								cout<<"不过，要前往末地，必须要找到世界与末地的折跃链接口，我听说在地下曾经有一个废弃的要塞，里面供奉着末地之门..."<<endl;
								cout<<"图书管理员的叹了口气。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 
							break;	
						}
					}
				} 
			break;
			case 5:
				cout<<"你发现了一个睡着的农民"<<endl;
				Sleep(1000);
				cout<<"0，叫醒  1，偷东西"<<endl;
				cin>>choose;
				if(choose==1){
					credit-=20;
					int add=rand()%4;
					if(add==0){
						cout<<"你偷偷摸了摸农民的口袋，发现空空如也！"<<endl;
						Sleep(1500);
						cout<<"农民惊醒了，大喊：小偷！！！"<<endl;
						Sleep(1500);
						cout<<"一旁的铁傀儡冲来!"<<endl;
						Sleep(2000);
						fight("铁傀儡",100,8,6,40,2,10,3,200,5);
						if(dead){
							dead=false;
							cout<<"获得 2 个铁锭！"<<endl;
							bag[21]+=2;
							cout<<"你踹开了铁傀儡，连忙跑走了"<<endl; 
							Sleep(2000);
						}else{
							cout<<"你的钱被铁傀儡全部夺走了！"<<endl;
							money=0; 
							Sleep(2000);
							return;
						}
					}else{
						cout<<"你偷偷摸了摸农民的口袋，发现有 "<<add<<" 颗绿宝石！"<<endl;
						money+=add;
						Sleep(1500);
						cout<<"你又悄悄地走了"<<endl;
						Sleep(2000);
					}
				}else{
					cout<<"你叫醒了农民"<<endl;
					Sleep(1500);
					cout<<"农民对你不停感谢"<<endl;
					credit+=1;
					Sleep(2000);
				}
			break;
			case 6:
				cout<<"你走到村庄中心，发现了一个雕像..."<<endl;
				Sleep(1500);
				cout<<"你仔细一看，是创世神Notch的雕像！"<<endl;
				Sleep(1500);
				cout<<"但你环顾四周，发现竟没有一个村民祭拜雕像。"<<endl;
				Sleep(1500);
				cout<<"而雕像也无人清理，十分破旧。"<<endl<<endl;
				Sleep(1500);
				if(credit<=20){
					cout<<"你对着雕像，冷笑一声，吐了一口口水便离去了"<<endl;
					Sleep(2000);
					credit-=5;
					return;
				}
				cout<<"0，离开  1，祭拜雕像"<<endl;
				cin>>choose;
				if(choose==1){
					system("cls");
					cout<<"你正欲祭拜时，一个村民对你喊道：不要祭拜！"<<endl;
					Sleep(1500);
					cout<<"你很奇怪，问为什么不能祭拜。"<<endl;
					Sleep(1500);
					cout<<"村民说：一旦我们祭拜了创世神的雕像，周围的亡灵生物便会感到威胁，前来攻打我们的村庄！"<<endl<<endl;
					Sleep(2000);
					cout<<"0，离开  1，继续祭拜"<<endl;
					cin>>choose;
					if(choose==1){
						credit+=5;
						cout<<"你没有犹豫，对着雕像拜了下去..."<<endl; 
						Sleep(2000);
						if(blesscold==0){
							cout<<"获得Notch之祝福！下次战斗时生效"<<endl;
							blessing=true;
							Sleep(2000);
							blesscold=2;
						}else blesscold--;	
						if(1+rand()%2==1){
							undeadattack=true;
							cout<<"然而，你突然有了一种不祥的预感..."<<endl;
							Sleep(2000); 
						} 
					} 
				} 
			break;
			case 7:
				cout<<"你什么都没遇见..."<<endl;
				Sleep(2000); 
			break;
			case 8:
			cout<<"你遇到了铁傀儡！"<<endl;
			cout<<"0，离开  1，激怒"<<endl;
			cin>>choose;
			if(choose==1){
				fight("铁傀儡",100,8,6,40,2,10,3,500,5);
				credit-=20;
				if(dead){
					dead=false;
					cout<<"获得 2 个铁锭！"<<endl;
					bag[21]+=2;
				}
			}else{
				cout<<"你远离了铁傀儡"<<endl; 
				Sleep(1000);
				break;
			}
			break;	
			case 9:
				cout<<"你遇见了村庄中德高望重的老者-图书管理员"<<endl; 
				Sleep(1000);
				cout<<"这位老者知晓这个世界上的种种事情..."<<endl<<endl;
				Sleep(1500);
				if(credit<=30){
					cout<<"图书管理员只是轻轻扫视过你身上，你就感觉内心仿佛被审视了一般"<<endl;
					Sleep(1500);
					cout<<"你感觉罪恶爬上了你的脊梁..."<<endl;
					Sleep(1500);
					cout<<"“你都做了什么，没有人比你更清楚，即使是遇见弱小者也不愿伸手援助，甚至助纣为虐...”"<<endl;
					Sleep(1500);
					cout<<"顷刻间，图书管理员便消失在你的视线中..."<<endl;
					Sleep(2000); 
				}else{
					cout<<"你要与图书管理员交谈吗？（0，离开  1，交谈）"<<endl;
					cin>>choose;
					if(choose==1){
						cout<<"你要询问什么？"<<endl;
						cout<<"1，关于远古时期的战争"<<endl;
						cout<<"2，Herobrine的信徒/势力"<<endl;
						cout<<"3，Herobrine归来的传言"<<endl;
						cout<<"4，关于创世之力"<<endl;
						cout<<"5，关于亡灵势力"<<endl; 
						cout<<"6，关于地狱"<<endl;
						cout<<"7，关于末地"<<endl;
						cin>>choose;
						switch(choose){
							case 1:
								system("cls");
								Sleep(2000); 
								cout<<"在远古时期，也就是这个世界刚被创造出的时候，世界上有两位神，也就是Notch和Herobrine，而这两位神是兄弟。"<<endl; 
								cout<<"因Herobrine创造了亡灵生物，两人意见逐渐不和，最终他们的关系分崩离析。"<<endl;
								cout<<"Notch本与Herobrine互不干涉，但Herobrine创造出的亡灵生物组成了一支亡灵大军----"<<endl;
								cout<<"这支亡灵大军四处前进，所过之处血流成河，尸骨遍地..."<<endl;
								cout<<"Notch看着方块世界生灵涂炭，决心阻止Herobrine，而这就是战争的导火索..."<<endl;
								cout<<"亡灵生物可以将死去的生灵转变为亡灵，当时的人类只得四处逃亡。"<<endl;
								cout<<"Notch使用了大量的「 创世之力」才成功解决了一大部分的亡灵，但仍有部分亡灵侥幸活了下来。"<<endl;
								cout<<"而后，Notch已经没有足够的力量对付Herobrine了，他只好用出剩余的「 创世之力」，将Herobrine封印在了地狱..."<<endl;
								cout<<"但是，似乎Herobrine正积蓄着力量，破开封印..."<<endl<<endl;
								cout<<"图书管理员叹了口气。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								}     
							break;
							case 2:
								system("cls");
								Sleep(2000); 
								cout<<"早在创世初期，Herobrine就展示出了与他的哥哥截然不同的性格。"<<endl; 
								cout<<"他放荡不羁，将自己当作众生的主宰，将世界当作自己的游戏。"<<endl;
								cout<<"早期，Herobrine还不至于做些太出格的事情。"<<endl;
								cout<<"但随着时间推移，Herobrine越来越狂妄，开始向世界各地建立自己的势力。"<<endl;
								cout<<"他用自己的「 混沌之力」和亡灵创造出了一个又一个他的忠实手下。"<<endl;
								cout<<"后来，他又凭借着自己强大的力量，收服了世界各地的一个个强者，并用自己的力量使他们变得更强。"<<endl;
								cout<<"而Herobrine自身也在世界上留有一些自己的虚影。这些虚影代表着Herobrine，但实力仅有本体的千分之一。"<<endl;
								cout<<"像 NULL，恐惧魔王，Entity_303等...都是Herobrine忠实的手下。"<<endl;
								cout<<"若他们联合起来，集结所有的力量，Herobrine很可能将会破开封印，重回世界..."<<endl<<endl;
								cout<<"图书管理员的面色变得凝重。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 3: 
								system("cls");
								Sleep(2000); 
								cout<<"Herobrine的归来..."<<endl; 
								cout<<"这不是谣言，也许很快就会发生...创世神Notch已不知所踪，地狱的恐惧魔王已经集结了猪人们，Herobrine很可能会破开封印。"<<endl;
								cout<<"在遥远的边境之地，那里混合着创世之力与混沌之力，地面被拉伸成一堵高墙，一切事物都变得混乱。"<<endl;
								cout<<"而Null，就在边境之地..."<<endl;
								cout<<"Herobrine曾经的势力，必将会不惜所有代价，强行打破Herobrine的封印..."<<endl;
								cout<<"图书管理员的面色变得凝重。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 4:
								system("cls");
								Sleep(2000); 
								cout<<"创世之力，便是Notch所拥有的神力。"<<endl; 
								cout<<"这种神力拥有着创造的能力，是最纯粹，最强大的力量。"<<endl;
								cout<<"Herobrine所拥有的，便是混沌之力。与Notch相反，充满着破坏，不稳定性。"<<endl;
								cout<<"正是当初Notch和Herobrine联手，消耗了大量神力，才创造出了这个世界。"<<endl;
								cout<<"而也只有创世之力，才能抗衡Herobrine的混沌之力。"<<endl;
								cout<<"但Notch在大战后便消失了踪迹，创世之力也不知道在哪里..."<<endl;
								cout<<"图书管理员的面色变得凝重。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 5:
								system("cls");
								Sleep(2000); 
								cout<<"亡灵生物，是Herobrine用亡灵之力与混沌之力创造出的。"<<endl; 
								cout<<"这种生物可以将死去的生灵转变成亡灵。"<<endl;
								cout<<"也就是说，通过亡灵的四处吞噬，感染，可以轻易的组成一支亡灵大军。"<<endl;
								cout<<"而Herobrine正是凭借着数量庞大的亡灵军队，才得以与Notch抗衡。"<<endl;
								cout<<"Herobrine曾经忠心耿耿的下属，亡灵的领导者Blackbone组织着亡灵生物们..."<<endl;
								cout<<"尽管Notch拥有创世之力，但也无法彻底除掉亡灵。"<<endl;
								cout<<"“这将是一个致命的威胁。”图书管理员的面色变得凝重。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 	
							break;	
							case 6:
								system("cls");
								Sleep(2000); 
								cout<<"地狱，一个充斥着岩浆与狱岩的地方。传说也是封印Herobrine的地方..."<<endl; 
								cout<<"地狱危机重重，要时刻小心跌入岩浆，还要提防可怕的恶魂，岩浆怪"<<endl;
								cout<<"而在地狱中，有一种特殊的种族--猪灵。"<<endl;
								cout<<"猪灵是一种贪财的生物，给他们金锭便能与他们交易，但你却不能知道自己能得到什么。"<<endl;
								cout<<"地狱的深处还隐藏着一种重金属，叫下界合金。这些合金需要在地狱的深处挖掘坚硬的远古残骸提炼而成。"<<endl;
								cout<<"另外，地狱中还暗藏着一些猪灵的堡垒，以及下界要塞，这些地方都隐藏着珍贵的宝藏，以及--无穷的危机。"<<endl;
								cout<<"图书管理员的叹了口气。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 
							break;
							case 7:
								system("cls");
								Sleep(2000); 
								cout<<"末地，一个位于虚空的另一维度。"<<endl; 
								cout<<"那里矗立着几根黑曜石柱，在末地的主岛上还有一条巨龙。"<<endl;
								cout<<"在末地里，四处充斥着末影人。这里的末影人都是在时空缝隙中不小心穿越过来的。"<<endl;
								cout<<"打败末影龙后，就可以前往末地的外岛了。外岛中散布着一些末地城，这些城市里面藏着许多宝藏。"<<endl;
								cout<<"但要打败末影龙可不容易，黑曜石柱上的末影水晶会为末影龙持续恢复力量。"<<endl;
								cout<<"不过，要前往末地，必须要找到世界与末地的折跃链接口，我听说在地下曾经有一个废弃的要塞，里面供奉着末地之门..."<<endl;
								cout<<"图书管理员的叹了口气。"<<endl;
								cout<<"0，离开  1，继续询问"<<endl;
								cin>>choose;
								if(choose==1){
									cout<<"管理员：以后再来吧，现在我累了..."<<endl;
									Sleep(3000); 
								} 
							break;	
						}
					}
				} 
			break;
		}
	}
	if(place=="平原"){
		switch(rand()%1){
			case 0:
				if(task1==0){
					cout<<"你遇见了一个旅行家！"<<endl;
					Sleep(1500);
					cout<<"旅行家对你说，他身上没有木头了，你能不能给他带来10个橡木？"<<endl;
					cout<<endl<<"0，拒绝  1，接受"<<endl;
					cin>>choose;
					if(choose==1){
						cout<<"获得任务：收集橡木！"<<endl;
						task1=1;
						Sleep(2000);
						cout<<"注：完成任务后，需找到冒险家结算任务方可领取奖励。"<<endl;
						Sleep(2000);
					}else{
						cout<<"你拒绝了旅行家"<<endl;
						Sleep(1500);
					}
				}else{
					if(bag[1]<10){
						cout<<"你找到了旅行家"<<endl;
						Sleep(1500);
						cout<<"你现在只有 "<<bag[1]<<" 个橡木，你没有完成任务！"<<endl;
						Sleep(1500);
						cout<<"旅行者看着你，生气的走了"<<endl;
						Sleep(1500);
						cout<<"任务作废！"<<endl;
						task1=2;
						credit-=15;
						Sleep(1500); 
					}else{
						cout<<"你找到了旅行家"<<endl;
						Sleep(1500);
						cout<<"你交给了旅行家10个橡木！"<<endl;
						bag[1]-=10; 
						Sleep(1500);
						cout<<"旅行家十分高兴，给了你3颗绿宝石作为奖励！"<<endl;
						money+=3;
						Sleep(1500);
						cout<<"任务已完成！"<<endl;
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
void go(){//前进 更改地点 
	system("cls");
	cout<<"你要去哪里？"<<endl;
	cout<<"0，返回  1，村庄  2，平原  3，森林  4，洞穴  5，沙漠  6，丛林  7，雪地  8，地狱  9，末地";
	cout<<endl;
	cin>>choose;
	switch(choose){
		case 0:
		return;	
		break; 
		case 1:
		if(place=="村庄"){
			cout<<"你已经在村庄了！"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="村庄";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 2:
		if(place=="平原"){
			cout<<"你已经在平原了！"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="平原";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 3:
		if(place=="森林"){
			cout<<"你已经在森林了！"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="森林";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 4:
		if(place=="洞穴"){
			cout<<"你已经在洞穴了！"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="洞穴";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		case 5:
		if(place=="沙漠"){
			cout<<"你已经在沙漠了！"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="沙漠";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 6:
		if(place=="丛林"){
			cout<<"你已经在丛林了！"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="丛林";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 7:
		if(place=="雪地"){
			cout<<"你已经在雪地了！"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="雪地";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
		case 8:
		if(place=="地狱"){
			cout<<"你已经在地狱了！"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			if(nether){
				cout<<"前进中..."<<endl;
				Sleep(3000);
				system("cls");
				place="雪地";
				cout<<"已到达 "<<place<<"!"<<endl;
				Sleep(1000); 
				return; 
			}else{
				cout<<"无法前进，你没有建造/发现地狱传送门"<<endl;
				Sleep(1000);
				go(); 
			}
		}
		break;
		case 9:
		if(place=="末地"){
			cout<<"你已经在末地了！"<<endl;
			Sleep(1000);
			go();
			return;			
		}else{
			if(nether){
				cout<<"前进中..."<<endl;
				Sleep(3000);
				system("cls");
				place="末地";
				cout<<"已到达 "<<place<<"!"<<endl;
				Sleep(1000); 
				return; 
			}else{
				cout<<"无法前进，你没有发现末地传送门"<<endl;
				Sleep(1000);
				go(); 
			}
		}
		break;
	} 
}
void chop(string place){//砍树 
	cout<<"发现树木！"<<endl;
	Sleep(1000);
	cout<<"开始砍树..."<<endl;
	Sleep(1000);
	system("cls");
	switch(tool1){
		case 0:
			for(int i=1;i<=20;i++){
				cout<<"已完成"<<i*5<<"%"<<endl; 
				Sleep(2000);
				system("cls");
			}
		break;
		case 1: 
			for(int i=1;i<=20;i++){
				cout<<"已完成"<<i*5<<"%"<<endl; 
				Sleep(1500);
				system("cls");
			}
		break;
		case 2: 
			for(int i=1;i<=20;i++){
				cout<<"已完成"<<i*5<<"%"<<endl; 
				Sleep(1250);
				system("cls");
			}
		break;
		case 3: 
			for(int i=1;i<=20;i++){
				cout<<"已完成"<<i*5<<"%"<<endl; 
				Sleep(250);
				system("cls");
			}
		break;
		case 4:
			for(int i=1;i<=20;i++){
				cout<<"已完成"<<i*5<<"%"<<endl; 
				Sleep(750);
				system("cls");
			}	
		break;
		case 5:
			for(int i=1;i<=20;i++){
				cout<<"已完成"<<i*5<<"%"<<endl; 
				Sleep(500);
				system("cls");
			}
		break;
		case 6:
			for(int i=1;i<=20;i++){
				cout<<"已完成"<<i*5<<"%"<<endl; 
				Sleep(300);
				system("cls");
			}
		break; 
	}
	if(place=="平原"||place=="森林"){
		int add=5+rand()%8;
		cout<<"获得橡木"<<add<<"个！"<<endl; 
		bag[1]+=add;
		cout<<"当前拥有橡木"<<bag[1]<<"个"<<endl;	
		Sleep(2000);
	}
	if(place=="丛林"){
		int add=7+rand()%3;
		cout<<"获得丛林木"<<add<<"个！"<<endl; 
		bag[2]+=add;
		cout<<"当前拥有丛林木"<<bag[2]<<"个"<<endl;	
		Sleep(2000);
	}
	if(place=="雪地"){
		int add=8+rand()%6;
		cout<<"获得针叶木"<<add<<"个！"<<endl; 
		bag[3]+=add;
		cout<<"当前拥有针叶木"<<bag[3]<<"个"<<endl;	
		Sleep(2000);
	}
	if(place=="地狱"){
		int add=6+rand()%6; 
		cout<<"获得绯红木"<<add<<"个！"<<endl; 
		bag[4]+=add;
		cout<<"当前拥有绯红木"<<bag[4]<<"个"<<endl;	
		Sleep(3000);
	}
	int apple=1+rand()%3,appleadd=1+rand()%2;
	if(apple==3&&place!="地狱"){
		cout<<"你在树上发现了 "<<appleadd<<" 个苹果！"<<endl;
		bag[36]+=appleadd;
		Sleep(2000);
	}		
	return;
} 
void tree(string place){//砍树 
	if(place=="村庄"){
		system("cls");
		cout<<"似乎这里没有树...难道你想拆了村民的房子？"<<endl<<endl;
		cout<<"系统提示：请去别的地方砍树！"<<endl;
		Sleep(1500);
		return; 
	}
	if(place=="洞穴"){
		system("cls");
		cout<<"洞穴里只有坚硬的石头，没有树..."<<endl<<endl;
		cout<<"系统提示：请去别的地方砍树！"<<endl;
		Sleep(1500);
		return; 
	}
	if(place=="沙漠"){
		system("cls");
		cout<<"似乎这里没有树，有的只是长满了尖刺的仙人掌..."<<endl<<endl;
		cout<<"系统提示：请去别的地方砍树！"<<endl;
		Sleep(1500);
		return; 
	}
	if(place=="末地"){
		system("cls");
		cout<<"紫菘果可不是木头！"<<endl<<endl;
		cout<<"系统提示：请去别的地方砍树！"<<endl;
		Sleep(1500);
		return; 
	}
	system("cls");
	if(tool1==0){
		cout<<"看起来你没有斧子，但凭坚硬的双手，也许可以拿下这些木头..."<<endl<<endl; 
		cout<<"如果你有一把斧子，会大大加快砍树的速度。"<<endl;
		Sleep(3000);
		cout<<endl;
	}
	cout<<"当前你装备：";
	cout<<tool1name[tool1]<<endl<<endl; 
	cout<<"提示：你所处的位置决定了你发现树木的速度。"<<endl;
	cout<<"      同时，你的斧头会决定你砍伐树木的速度。"<<endl<<endl;
	Sleep(2000);
	cout<<"0，返回  1，砍树"<<endl;
	cin>>choose;
	system("cls");
	if(choose==1){
		if(place=="平原"){
			cout<<"大约需要20秒..."<<endl; 
			cout<<"寻找树木中..."<<endl; 
			Sleep(15000+rand()%8000); 
			chop("平原");
		}
		if(place=="森林"){
			cout<<"大约需要5秒..."<<endl; 
			cout<<"寻找树木中..."<<endl; 
			Sleep(2000+rand()%5000); 
			chop("森林");
		}
		if(place=="丛林"){
			cout<<"大约需要10秒..."<<endl; 
			cout<<"寻找树木中..."<<endl; 
			Sleep(6000+rand()%8000); 
			chop("丛林");
		}
		if(place=="雪地"){
			cout<<"大约需要30秒..."<<endl; 
			cout<<"寻找树木中..."<<endl; 
			Sleep(25000+rand()%10000); 
			chop("雪地");
		}
		if(place=="地狱"){
			cout<<"大约需要10秒..."<<endl; 
			cout<<"寻找树木中..."<<endl; 
			Sleep(8000+rand()%6000); 
			chop("地狱");
		}
	}
	else return;
}
void dig(string place){
		if(place!="洞穴"&&place!="地狱"){
			cout<<"此处无法挖矿！请去其他地方挖矿！"<<endl;
			Sleep(1500);
			return;
		}
		if(tool2==0){
			cout<<"空手无法挖矿！请装备稿子后再来挖矿！"<<endl;
			Sleep(2000);				
			return; 
		}
		cout<<"现在你在："<<place<<endl;
		if(place=="洞穴"){	
			system("cls");
			cout<<"你现在装备："<<tool2name[tool2]<<endl<<endl;
			cout<<"提示：一些矿石只有特定或足够好的稿子才能挖掘。"<<endl;
			cout<<"      你的稿子决定了你挖掘矿石时的速度。"<<endl<<endl; 
			Sleep(2000);
			cout<<"0，返回  1，挖矿"<<endl;
			cin>>choose;
			if(choose==1){
				cout<<"0，挖圆石  1，挖矿物"<<endl;
				cin>>choose;
				if(choose==0){//挖石头 
					cout<<"你要挖多少块圆石？"<<endl;
					cin>>choose;
					cout<<"开始挖掘..."<<endl;
					Sleep(2000); 
					system("cls");
					switch(tool2){
						case 1: 
							for(int i=1;i<=20;i++){
								cout<<"已完成"<<i*5<<"%"<<endl; 
								Sleep(225*choose);
								system("cls");
							}
						break;
						case 2: 
							for(int i=1;i<=20;i++){
							cout<<"已完成"<<i*5<<"%"<<endl; 
							Sleep(187*choose);
							system("cls");
							}
						break;
						case 3: 
							for(int i=1;i<=20;i++){
								cout<<"已完成"<<i*5<<"%"<<endl; 
								Sleep(62*choose);
								system("cls");
							}
						break;
						case 4:
							for(int i=1;i<=20;i++){
								cout<<"已完成"<<i*5<<"%"<<endl; 
								Sleep(137*choose);
								system("cls");
							}	
						break;
						case 5:
							for(int i=1;i<=20;i++){
								cout<<"已完成"<<i*5<<"%"<<endl; 
								Sleep(100*choose);
								system("cls");
							}
						break;
						case 6:
							for(int i=1;i<=20;i++){
								cout<<"已完成"<<i*5<<"%"<<endl; 
								Sleep(75*choose);
								system("cls");
							}
						break; 
					}
					cout<<"获得圆石 "<<choose<<" 个!"<<endl;	
					bag[14]+=choose;
					cout<<"当前拥有圆石 "<<bag[14]<<" 个"<<endl;
					Sleep(2000);	
					return;
				}else{//挖矿石 
				system("cls");
				cout<<"探索矿洞中..."<<endl;	
				Sleep(8000+rand()%12000);
				int add;
				switch(1+rand()%3){
					case 1://发现煤炭 
						add=8+1+rand()%8;
						cout<<"你发现了 "<<add<<" 块煤炭！"<<endl;
						Sleep(1000);
						cout<<"0，离开  1，挖掘"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							switch(tool2){
								case 1: 
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(250*add);
										system("cls");
									}
								break;
								case 2: 
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(200*add);
										system("cls");
									}
								break;
								case 3: 
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(75*add);
										system("cls");
									}
								break;
								case 4:
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(150*add);
										system("cls");
									}	
								break;
								case 5:
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(120*add);
										system("cls");
									}
								break;
								case 6:
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(90*add);
										system("cls");
									}
								break; 
							}
							cout<<"挖掘完毕！获得 "<<itemname[19]<<" "<<add<<" 个！"<<endl;
							bag[19]+=add;
							cout<<"当前有 "<<itemname[19]<<" "<<bag[19]<<" 个！"<<endl;
							Sleep(2000);
							dig(place); 
						}else dig(place);
					break;
					case 2://发现铁矿 
						add=2+1+rand()%8;
						cout<<"你发现了 "<<add<<" 块铁矿石！"<<endl;
						Sleep(1000);
						cout<<"0，离开  1，挖掘"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							if(tool2<2||tool2==3){
								cout<<"当前稿子无法挖掘此矿石！"<<endl;
								Sleep(2000);
								dig(place);
							} 
							switch(tool2){
								case 2: 
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(225*add);
										system("cls");
									}
								break;
								case 4:
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(175*add);
										system("cls");
									}	
								break;
								case 5:
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(140*add);
										system("cls");
									}
								break;
								case 6:
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(120*add);
										system("cls");
									}
								break; 
							}
							cout<<"挖掘完毕！获得 "<<itemname[20]<<" "<<add<<" 个！"<<endl;
							bag[20]+=add;
							cout<<"当前有 "<<itemname[20]<<" "<<bag[20]<<" 个！"<<endl;
							Sleep(2000);
							dig(place); 
						}else dig(place);
					break;
					case 3://发现金矿 
						int add=4+1+rand()%3;
						cout<<"你发现了 "<<add<<" 块金矿石！"<<endl;
						Sleep(1000);
						cout<<"0，离开  1，挖掘"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							if(tool2<4){
								cout<<"当前稿子无法挖掘此矿石！"<<endl;
								Sleep(2000);
								dig(place);
							}
							switch(tool2){
								case 4:
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(200*add);
										system("cls");
									}	
								break;
								case 5:
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(160*add);
										system("cls");
									}
								break;
								case 6:
									for(int i=1;i<=20;i++){
										cout<<"已完成"<<i*5<<"%"<<endl; 
										Sleep(140*add);
										system("cls");
									}
								break; 
							}
							cout<<"挖掘完毕！获得 "<<itemname[31]<<" "<<add<<" 个！"<<endl;
							bag[31]+=add;
							cout<<"当前有 "<<itemname[31]<<" "<<bag[31]<<" 个！"<<endl;
							Sleep(2000);
							dig(place); 
						}else dig(place);
					break;	
				}
			}
		}else return;
	}
}
void jvqing(){//剧情输出 
	system("cls");
	cout<<"加载剧情中..."<<endl;
	Sleep(2000);
	cout<<"加载完毕！"<<endl;
	Sleep(1000);
	system("cls"); 
	Sleep(500);
	cout<<"很久之前,虚空中有两位神，分别是Notch和Herobrine。"<<endl<<endl;
	Sleep(1500);
	cout<<"他们本是一对兄弟，两人平安无事，Notch与Herobrine共同联手，创造了一个方块世界。"<<endl<<endl;
	Sleep(1500);
	cout<<"Notch创造出了人类，动物，使世界充满了生机。"<<endl<<endl;
	Sleep(1500);
	cout<<"但他的弟弟Herobrine认为这太过无聊，又创造出了亡灵大军。"<<endl<<endl;
	Sleep(1500);
	cout<<"两人意见很快便不合，最终Notch与Herobrine背道而行，势不两立。"<<endl<<endl;
	Sleep(1500);
	cout<<"Herobrine率领着众多亡灵，血洗了方块大陆上的一切生灵......"<<endl<<endl;
	Sleep(1500);
	cout<<"Notch见状，耗尽了近乎所有的神力，将Herobrine封印起来到了地狱。"<<endl<<endl;
	Sleep(1500);
	cout<<"但尽管如此，Herobrine创造出的亡灵早已遍布世界，无法根除。"<<endl<<endl;
	Sleep(1500);
	cout<<"而Herobrine也积蓄着力量，集结着黑暗的势力准备反扑。"<<endl<<endl;
	Sleep(1500);
	system("cls");
	for(int i=1;i<=12;i++){
		cout<<"."<<" ";
		Sleep(100);
	}
	cout<<endl<<endl<<"数百年过去了，和平安宁的景象即将被打破......"<<endl<<endl;
	Sleep(1500); 
	cout<<"能够拯救这个世界的，就只有--"<<endl<<endl;
	Sleep(800); 
	cout<<"你，才能拯救世界，打败Herobrine，保护世界的和平！"<<endl<<endl;
	Sleep(1000);
	cout<<"属于你的传奇，现在开始......"<<endl<<endl;
	Sleep(3000);
	return; 
}
void checkbag(){//检查背包 
	cout<<"显示顺序为 编号-物品名-数量"<<endl<<endl;
	cout<<"若未显示则为无物品"<<endl<<endl;
	for(int i=1;i<=100;i++){
		if(bag[i]>0) cout<<"编号 "<<i<<"  "<<itemname[i]<<" 数量："<<bag[i]<<" 个"<<endl;
		else continue;
	}
	if(weaponcheck==1) return;
	cout<<endl<<"输入0返回"<<endl;
	cin>>choose;
	switch(choose){
		case 0:
			return;
		break;
		case 1:
			system("cls");
			cout<<"物品："<<itemname[1]<<endl; 
			cout<<"基础的木头，可在平原，森林砍树获得。可以制作橡木木板。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 2:
			system("cls");
			cout<<"物品："<<itemname[2]<<endl; 
			cout<<"基础的木头，可在丛林砍树获得。可以制作丛林木板。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 3:
			system("cls");
			cout<<"物品："<<itemname[3]<<endl; 
			cout<<"基础的木头，可在雪地砍树获得。可以制作针叶木木板。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 4:
			system("cls");
			cout<<"物品："<<itemname[4]<<endl; 
			cout<<"来自地狱的木头，能防火，可在地狱砍树获得。可以制作绯红木板。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 5:
			system("cls");
			cout<<"物品："<<itemname[5]<<endl; 
			cout<<"基础的木板，可以制作各种木制品。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 6:
			system("cls");
			cout<<"物品："<<itemname[6]<<endl; 
			cout<<"基础的木板，可以制作各种木制品。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 7:
			system("cls");
			cout<<"物品："<<itemname[7]<<endl; 
			cout<<"基础的木板，可以制作各种木制品。"<<endl;
			Sleep(3000);
			system("cls");
			checkbag();
		break;
		case 8:
			system("cls");
			cout<<"物品："<<itemname[8]<<endl; 
			cout<<"来自地狱的木板，能防火，可以制作各种木制品。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 9:
			system("cls");
			cout<<"物品："<<itemname[9]<<endl; 
			cout<<"一个制作站，在<建造>中将其放置便可合成更多新物品。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 10:
			system("cls");
			cout<<"物品："<<itemname[10]<<endl;
			cout<<"木制的棍子，是组装武器和工具必备的材料。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 11:
			system("cls");
			cout<<"物品："<<itemname[11]<<endl;
			cout<<"木制的剑，简单好用。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 12:
			system("cls");
			cout<<"物品："<<itemname[12]<<endl;
			cout<<"木制的斧，可略微提升砍树的速度。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 13:
			system("cls");
			cout<<"物品："<<itemname[13]<<endl;
			cout<<"木制的稿，可以挖掘石头和煤炭。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 14:
			system("cls");
			cout<<"物品："<<itemname[14]<<endl;
			cout<<"地下四处可采集的石头，是制作石制工具的必要材料。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 15:
			system("cls");
			cout<<"物品："<<itemname[15]<<endl;
			cout<<"石质的剑，朴实无华，简单耐用。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 16:
			system("cls");
			cout<<"物品："<<itemname[16]<<endl;
			cout<<"石质的斧，可小幅提升砍树的速度。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 17:
			system("cls");
			cout<<"物品："<<itemname[17]<<endl;
			cout<<"石质的稿，比木稿的挖掘速度更快，还可挖掘铁矿。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 18:
			system("cls");
			cout<<"物品："<<itemname[18]<<endl;
			cout<<"“热门话题”！在<建造>中将其放置便可熔炼矿物。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 19:
			system("cls");
			cout<<"物品："<<itemname[19]<<endl;
			cout<<"基础的燃料，可用于熔炼矿物。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 20:
			system("cls");
			cout<<"物品："<<itemname[20]<<endl;
			cout<<"中级的矿石，将其用熔炉熔炼可获得铁锭。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 21:
			system("cls");
			cout<<"物品："<<itemname[21]<<endl;
			cout<<"中级的矿锭，可以制作精良的铁质装备。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 22:
			system("cls");
			cout<<"物品："<<itemname[22]<<endl;
			cout<<"铁质的剑，锋利耐用，是优秀的武器。"<<endl; 
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 23:
			system("cls");
			cout<<"物品："<<itemname[23]<<endl;
			cout<<"铁质的斧，可较快提升砍树速度。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 24:
			system("cls");
			cout<<"物品："<<itemname[24]<<endl;
			cout<<"铁质的稿，可以挖掘钻石，金矿石的中高级矿物，且可较快提升挖掘速度。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 25:
			system("cls");
			cout<<"物品："<<itemname[25]<<endl;
			cout<<"铁质的斧，可较快提升砍树速度。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 26:
			system("cls");
			cout<<"物品："<<itemname[26]<<endl;
			cout<<"铁质的头盔，可抵挡受到的伤害。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 27:
			system("cls");
			cout<<"物品："<<itemname[27]<<endl;
			cout<<"铁质的胸甲，可抵挡受到的伤害。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 28:
			system("cls");
			cout<<"物品："<<itemname[28]<<endl;
			cout<<"铁质的护腿，可抵挡受到的伤害。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 29:
			system("cls");
			cout<<"物品："<<itemname[29]<<endl;
			cout<<"铁质的靴子，可抵挡受到的伤害。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 30:
			system("cls");
			cout<<"物品："<<itemname[20]<<endl;
			cout<<"中高级的矿石，将其用熔炉熔炼可获得金锭。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
		case 31:
			system("cls");
			cout<<"物品："<<itemname[31]<<endl;
			cout<<"中高级的矿锭，可以制作速度极快的金质装备。"<<endl;
			Sleep(3000);
			system("cls"); 
			checkbag();
		break;
	}	
}
void weapon(){//装备 
	system("cls");
	weaponcheck=1;
	cout<<"当前你装备头盔："<<armor1name[armor1]<<endl; 
	cout<<"当前你装备胸甲："<<armor2name[armor2]<<endl; 
	cout<<"当前你装备护腿："<<armor3name[armor3]<<endl; 
	cout<<"当前你装备靴子："<<armor4name[armor4]<<endl; 
	cout<<"当前你主手装备："<<weapon1name[weapon1]<<"(+"<<weapon1attack[weapon1]<<")"<<endl; 
	cout<<"当前你副手装备："<<weapon2name[weapon2]<<endl;
	cout<<"当前你使用斧子："<<tool1name[tool1]<<endl;
	cout<<"当前你使用稿子："<<tool2name[tool2]<<endl<<endl;
	checkbag();
	weaponcheck=0;
	cout<<endl<<"0，退出  1，卸下武器  2，装备武器"<<endl;
	cin>>choose;
	switch(choose){
		case 0:
			return;
		break;
		case 1://卸下装备 
			cout<<"你要卸下？"<<endl;
			cout<<"0，返回  1，头盔  2，胸甲  3，护腿  4，靴子  5，主手  6，副手  7，斧子  8，稿子"<<endl;
			cin>>choose;
			switch(choose){
				case 0:
					weapon();
				break; 
				case 1://卸下头盔 
					switch(armor1){//
						case 0:
							cout<<"你没有装备头盔！"<<endl;
							Sleep(1500);
							weapon();	
						break;
						case 3:
							bag[39]+=1;
							cout<<"已卸下 "<<itemname[39]<<" ！"<<endl; 
							armor1=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[25]+=1;
							cout<<"已卸下 "<<itemname[25]<<" ！"<<endl; 
							armor1=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 2://卸下胸甲 
					switch(armor2){//
						case 0:
							cout<<"你没有装备胸甲！"<<endl;
							Sleep(1500);
							weapon();	
						break;
						case 3:
							bag[40]+=1;
							cout<<"已卸下 "<<itemname[40]<<" ！"<<endl; 
							armor2=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[26]+=1;
							cout<<"已卸下 "<<itemname[26]<<" ！"<<endl; 
							armor2=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 3://卸下护腿 
					switch(armor3){//
						case 0:
							cout<<"你没有装备护腿！"<<endl;
							Sleep(1500);
							weapon();	
						break;
						case 3:
							bag[41]+=1;
							cout<<"已卸下 "<<itemname[41]<<" ！"<<endl; 
							armor3=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[27]+=1;
							cout<<"已卸下 "<<itemname[27]<<" ！"<<endl; 
							armor3=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 4://卸下靴子 
				switch(armor4){//
						case 0:
							cout<<"你没有装备靴子！"<<endl;
							Sleep(1500);
							weapon();	
						break;
						case 3:
							bag[42]+=1;
							cout<<"已卸下 "<<itemname[42]<<" ！"<<endl; 
							armor4=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[28]+=1;
							cout<<"已卸下 "<<itemname[28]<<" ！"<<endl; 
							armor4=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 5:
					switch(weapon1){//卸下主手 
						case 0:
							cout<<"你没有装备主手武器！"<<endl;
							Sleep(1500);
							weapon();	
						break;
						case 1:
							bag[11]+=1;
							cout<<"已卸下 "<<itemname[11]<<" ！"<<endl; 
							weapon1=0;
							Sleep(1500);
							weapon();
						break;
						case 2:
							bag[15]+=1;
							cout<<"已卸下 "<<itemname[15]<<" ！"<<endl; 
							weapon1=0;
							Sleep(1500);
							weapon();
						break;
						case 3:
							bag[33]+=1;
							cout<<"已卸下 "<<itemname[33]<<" ！"<<endl; 
							weapon1=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[22]+=1;
							cout<<"已卸下 "<<itemname[22]<<" ！"<<endl; 
							weapon1=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 6:
					switch(weapon2){//卸下副手 
					}
				break;	
				case 7:
					switch(tool1){//卸下斧子 
						case 0:
							cout<<"你没有装备斧子!"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 1:
							bag[12]+=1;
							cout<<"已卸下 "<<itemname[12]<<" ！"<<endl; 
							tool1=0;
							Sleep(1500);
							weapon();
						break;
						case 2:
							bag[16]+=1;
							cout<<"已卸下 "<<itemname[16]<<" ！"<<endl; 
							tool1=0;
							Sleep(1500);
							weapon();
						break;
						case 3:
							bag[34]+=1;
							cout<<"已卸下 "<<itemname[33]<<" ！"<<endl; 
							tool1=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[23]+=1;
							cout<<"已卸下 "<<itemname[34]<<" ！"<<endl; 
							tool1=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 8:
					switch(tool2){//卸下稿子 
						case 0:
							cout<<"你没有装备稿子！"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 1:
							bag[13]+=1;
							cout<<"已卸下 "<<itemname[13]<<" ！"<<endl; 
							tool2=0;
							Sleep(1500);
							weapon();
						break;
						case 2:
							bag[17]+=1;
							cout<<"已卸下 "<<itemname[17]<<" ！"<<endl; 
							tool2=0;
							Sleep(1500);
							weapon();
						break;
						case 3:
							bag[35]+=1;
							cout<<"已卸下 "<<itemname[33]<<" ！"<<endl; 
							tool2=0;
							Sleep(1500);
							weapon();
						break;
						case 4:
							bag[24]+=1;
							cout<<"已卸下 "<<itemname[24]<<" ！"<<endl; 
							tool2=0;
							Sleep(1500);
							weapon();
						break;
					}
				break;
			}	
		break;
		case 2: //装备武器 
			cout<<"输入你背包中的武器/工具/装备编号以更换装备,不要乱输其他物品的编号！"<<endl<<endl;
			cout<<"你要装备什么武器？"<<endl;
			cout<<"0，返回  1，头盔  2，胸甲  3，护腿  4，靴子  5，主手  6，副手  7，斧子  8，稿子"<<endl;
			cin>>choose;
			switch(choose){
				case 0:
					weapon();
				break;	
				case 1:
					if(armor1!=0){
						cout<<"已装备头盔！请卸下后再装备！"<<endl;
						Sleep(2000);
						weapon();
					}
					cout<<"请输入要装备的头盔的编号，不要乱输其他！"<<endl;
					cin>>choose;
					switch(armor1){//
						case 39:
							armor1=3; 
							cout<<"已装备 "<<armor1name[armor1]<<" ！"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 25:
							armor1=4;
							cout<<"已装备 "<<armor1name[armor1]<<" ！"<<endl; 
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 2:
					if(armor2!=0){
						cout<<"已装备胸甲！请卸下后再装备！"<<endl;
						Sleep(2000);
						weapon();
					}
					cout<<"请输入要装备的胸甲的编号，不要乱输其他！"<<endl;
					cin>>choose; 
					switch(armor2){//
						case 40:
							armor2=3; 
							cout<<"已装备 "<<armor2name[armor2]<<" ！"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 26:
							armor2=2;
							cout<<"已装备 "<<armor2name[armor2]<<" ！"<<endl; 
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 3:
					if(armor3!=0){
						cout<<"已装备护腿！请卸下后再装备！"<<endl;
						Sleep(2000);
						weapon();
					}
					cout<<"请输入要装备的护腿的编号，不要乱输其他！"<<endl;
					cin>>choose;
					switch(armor3){//
						case 41:
							armor3=3; 
							cout<<"已装备 "<<armor3name[armor3]<<" ！"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 27:
							armor3=4;
							cout<<"已装备 "<<armor3name[armor3]<<" ！"<<endl; 
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 4:
					if(armor4!=0){
						cout<<"已装备靴子！请卸下后再装备！"<<endl;
						Sleep(2000);
						weapon();
					}
					cout<<"请输入要装备的靴子的编号，不要乱输其他！"<<endl;
					cin>>choose;
					switch(armor4){//
						case 42:
							armor4=3; 
							cout<<"已装备 "<<armor4name[armor4]<<" ！"<<endl; 
							Sleep(1500);
							weapon();
						break;
						case 28:
							armor4=4;
							cout<<"已装备 "<<armor4name[armor4]<<" ！"<<endl; 
							Sleep(1500);
							weapon();
						break;
					}
				break;
				case 5://装备主手
					if(weapon1!=0){
						cout<<"主手已装备武器！请卸下后再装备！"<<endl;
						Sleep(2000);
						weapon();
					} 
					cout<<"请输入要装备的剑的编号，不要乱输其他！"<<endl;
					cin>>choose; 
					switch(choose){
						case 11:
							weapon1=1;
							bag[11]-=1;
							cout<<"已装备 "<<weapon1name[weapon1]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 15:
							weapon1=2;
							bag[15]-=1;
							cout<<"已装备 "<<weapon1name[weapon1]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 22:
							weapon1=3;
							bag[22]-=1;
							cout<<"已装备 "<<weapon1name[weapon1]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 33:
							weapon1=4;
							bag[33]-=1;
							cout<<"已装备 "<<weapon1name[weapon1]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;	
					}
				break;
				case 6://装备副手 
				break;
				case 7://装备斧子 
					if(tool1!=0){
						cout<<"已装备斧子！请卸下后再装备！"<<endl;
						Sleep(2000);
						weapon();
					} 
					cout<<"请输入要装备的斧子的编号，不要乱输其他！"<<endl;
					cin>>choose; 
					switch(choose){
						case 12:
							tool1=1;
							bag[12]-=1;
							cout<<"已装备 "<<tool1name[tool1]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 16:
							tool1=2;
							bag[16]-=1;
							cout<<"已装备 "<<tool1name[tool1]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 23:
							tool1=3;
							bag[23]-=1;
							cout<<"已装备 "<<tool1name[tool1]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 34:
							tool1=4;
							bag[34]-=1;
							cout<<"已装备 "<<tool1name[tool1]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;	
					}
				break;
				case 8://装备稿子 
					if(tool2!=0){
						cout<<"已装备稿子！请卸下后再装备！"<<endl;
						Sleep(2000);
						weapon();
					} 
					cout<<"请输入要装备的稿子的编号，不要乱输其他！"<<endl;
					cin>>choose; 
					switch(choose){
						case 13:
							tool2=1;
							bag[13]-=1;
							cout<<"已装备 "<<tool2name[tool2]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 17:
							tool2=2;
							bag[17]-=1;
							cout<<"已装备 "<<tool2name[tool2]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 24:
							tool2=3;
							bag[22]-=1;
							cout<<"已装备 "<<tool2name[tool2]<<" ！"<<endl;
							Sleep(2000);
							weapon();
						break;
						case 35:
							tool2=4;
							bag[35]-=1;
							cout<<"已装备 "<<tool2name[tool2]<<" ！"<<endl;
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
void build(){//建造 
	system("cls");
	cout<<"输入编号建造建筑"<<endl<<endl; 
	cout<<"输入0退出"<<endl<<endl;
	if(bag[9]>=1) cout<<"1 工作台"<<endl;
	if(bag[18]>=1) cout<<"2 熔炉"<<endl; 
	cin>>choose;
	switch(choose){
		case 0:
			return;
		break; 
		case 1:
			if(bag[9]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(2000);
				build();
			}
			if(crafttable){
				cout<<"你已经建造过 工作台 了！"<<endl;
				Sleep(1500);
				build();
			}
			bag[9]-=1;
			cout<<"建造成功！现在可合成更多物品！"<<endl;
			crafttable=true;
			Sleep(2000);
			build();
		break;
		case 2:
			if(bag[18]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(2000);
				build();
			}
			if(furnace){
				cout<<"你已经建造过 熔炉 了！"<<endl;
				Sleep(1500); 
				build();
			}
			bag[18]-=1;
			cout<<"建造成功！现在可熔炼矿石！（在<合成>处熔炼，作者懒得多写一个函数）"<<endl;
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
	cout<<" 	 欢迎来到我的世界！    "<<endl<<endl;
	cout<<" 	 Made By Chenxuanhan   "<<endl;
	Sleep(1000);
	cout<<endl<<endl<<"按1开始..."<<endl;
	cin>>choose;
	if(choose!=1){
		Sleep(1000);
		cout<<"看来你挺无聊的啊...输入个1都不愿意么？"<<endl;
		Sleep(1500);
		cout<<"那就让你更无聊点吧..."<<endl;
		Sleep(3000);
		system("cls");
		int n=120;
		for(int i=1;i<=120;i++){
			cout<<"你还需要等待"<<n-i<<"秒才可进入游戏"<<endl;
			cout<<"我相信你肯定会退出重开的..."<<endl;
			Sleep(1000);
			system("cls");
		}
		cout<<"这只是个游戏，不是吗？"<<endl;
		Sleep(2000);
		cout<<"如果你能等两分钟，那你也确实够无聊的。"<<endl;
		Sleep(2000);
		cout<<"算了，我也不再整你了，反正我也不想再写那么多的代码还没几个人看了。"<<endl;
		Sleep(2000);
	} 
	system("cls");
	cout<<"输入你的名字..."<<endl; 
	cin>>name;
	cout<<"唔..."<<endl;
	Sleep(1000);
	cout<<"这就是你的名字了吗，"<<name<<"？...不错的名字。"<<endl;
	Sleep(2000);
	system("cls");
	cout<<"输入 1 观看剧情，按其余键跳过。"<<endl;
	cin>>choose;
	if(choose==1) jvqing();
	system("cls");
	cout<<"现在，开始你的传奇吧！"<<endl;
	cout<<"Create World..."<<endl; 
	Sleep(3000); 
	while(1){
		attack=basicattack+weapon1attack[weapon1];
		system("cls");
		cout<<"玩家名："<<name<<endl;
		cout<<"你现在位于"<<place<<"."<<endl;
		cout<<"血量："<<health<<"/"<<maxhealth<<endl;
		cout<<"攻击："<<attack<<endl;
		cout<<"防御："<<defense<<endl;
		cout<<"速度："<<speed<<endl;
		cout<<"绿宝石："<<money<<endl;
		cout<<"等级："<<level<<" 经验："<<experience<<"/"<<level*100<<endl; 
		cout<<"-----------------------------------" <<endl; 
		cout<<"你要做什么？"<<endl;
		cout<<"1，冒险  2，商店  3，背包  4，挖矿  5，砍树  6，前进  7，合成  8，建造  9，装备"<<endl;
		cin>>choose;
		switch(choose){//选择 
			case 1://冒险 
				system("cls");
				cout<<"你开始在"<<place<<"冒险..."<<endl;
				Sleep(1000);
				explore(place);
			break;
			case 2://商店 
				system("cls");
				cout<<"你进入商店"<<endl;
				Sleep(1000);
				shop(place);
			break;
			case 3://检查背包1/2（查看详细信息） 
				system("cls"); 
				cout<<"输入物品编号可查看详细信息"<<endl<<endl;
				checkbag();
			break;
			case 4://挖矿 
				dig(place); 
			break;
			case 5://砍树√ 
				tree(place);	
			break;
			case 6: //前进转移位置√ 
				go();
			break;
			case 7://合成 
				create();
			break;
			case 8://建造 
				build();
			break;
			case 9://装备
				weapon();
			break; 
		}
	}
	return 0;
}
