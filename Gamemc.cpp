#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
string name,place="村庄";//玩家名字，玩家地点 
long long maxhealth=20,health=20,attack=2,attack2,defense=0,money=0,experience=0,level=1,speed=2;//玩家基础数据 
int credit=50;//信誉值，玩家无法看见 
int weapon1=0,weapon2=0,tool1=0,tool2=0,attackdis1=2,attackdis2;//武器，装备 
int armor1=0,armor2=0,armor3=0,armor4=0; 
string weapon1name[10]={"空手","木剑","石剑","金剑","铁剑","钻石剑","下界合金剑"}; 
string weapon2name[10]={"无","弓","盾"}; 
string tool1name[10]={"无","木斧","石斧","金斧","铁斧","钻石斧","下界合金斧"}; 
string tool2name[10]={"无","木稿","石稿","金稿","铁稿","钻石稿","下界合金稿"}; 
string armor1name[10]={"无","皮革头盔","锁链头盔","金头盔","铁头盔","钻石头盔","下界合金头盔"};
string armor2name[10]={"无","皮革胸甲","锁链胸甲","金胸甲","铁胸甲","钻石胸甲","下界合金胸甲"};
string armor3name[10]={"无","皮革护腿","锁链护腿","金护腿","铁护腿","钻石护腿","下界合金护腿"};
string armor4name[10]={"无","皮革靴子","锁链靴子","金靴子","铁靴子","钻石靴子","下界合金靴子"};
//0空手 
bool nether=false,ender=false;//地狱门&末地门 建造/发现 
bool dead=false,defend=false;
bool crafttable=false;
int badguy=0;
int choose;//工具 
long long bag[1000]={};//背包 
string itemname[1000]={"","橡木","丛林木","针叶木","绯红菌柄","橡木木板","从林木木板","针叶木木板","绯红木板","工作台","木棍","木剑","木斧","木稿","圆石","石剑","石斧","石稿","熔炉","煤炭","铁矿石","铁锭","铁剑","铁斧","铁镐","铁头盔","铁胸甲","铁护腿","铁靴子","护盾","弓"};//物品名 
/*物品编号：
1橡木 2从林木 3针叶木 4绯红菌柄 5橡木木板 6从林木木板 7针叶木木板 8绯红木板 
9工作台 10木棍 11木剑 12木斧 13木稿 14圆石 15石剑 16石斧 
17石稿 18熔炉 19煤炭 20铁矿石 21铁锭 22铁剑 23铁斧 24铁镐
25铁头盔 26铁胸甲 27铁护腿 28铁靴子 29护盾 30弓 
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
	if(bag[1]>0) cout<<"编号"<<5<<": 合成 "<<itemname[5]<<"x4 需要 "<<itemname[1]<<"x1"<<endl; 
	if(bag[2]>0) cout<<"编号"<<6<<": 合成 "<<itemname[6]<<"x4 需要 "<<itemname[2]<<"x1"<<endl;
	if(bag[3]>0) cout<<"编号"<<7<<": 合成 "<<itemname[7]<<"x4 需要 "<<itemname[3]<<"x1"<<endl;
	if(bag[4]>0) cout<<"编号"<<8<<": 合成 "<<itemname[8]<<"x4 需要 "<<itemname[4]<<"x1"<<endl;
	if(bag[5]>3) cout<<"编号"<<9<<": 合成 "<<itemname[9]<<"x1 需要 "<<itemname[5]<<"x4"<<endl;
	if(bag[6]>3) cout<<"编号"<<9<<": 合成 "<<itemname[9]<<"x1 需要 "<<itemname[6]<<"x4"<<endl;
	if(bag[7]>3) cout<<"编号"<<9<<": 合成 "<<itemname[9]<<"x1 需要 "<<itemname[7]<<"x4"<<endl;
	if(bag[8]>3) cout<<"编号"<<9<<": 合成 "<<itemname[9]<<"x1 需要 "<<itemname[8]<<"x4"<<endl;
	if(bag[5]>=2) cout<<"编号"<<10<<": 合成 "<<itemname[10]<<"x4 需要 "<<itemname[5]<<"x2"<<endl;
	if(bag[6]>=2) cout<<"编号"<<10<<": 合成 "<<itemname[10]<<"x4 需要 "<<itemname[6]<<"x2"<<endl;
	if(bag[7]>=2) cout<<"编号"<<10<<": 合成 "<<itemname[10]<<"x4 需要 "<<itemname[7]<<"x2"<<endl;
	if(bag[8]>=2) cout<<"编号"<<10<<": 合成 "<<itemname[10]<<"x4 需要 "<<itemname[8]<<"x2"<<endl;
	if(bag[5]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<11<<": 合成 "<<itemname[11]<<"x1 需要 "<<itemname[5]<<"x2,"<<itemname[10]<<"x1"<<endl;
	if(bag[6]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<11<<": 合成 "<<itemname[11]<<"x1 需要 "<<itemname[6]<<"x2,"<<itemname[10]<<"x1"<<endl;
	if(bag[7]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<11<<": 合成 "<<itemname[11]<<"x1 需要 "<<itemname[7]<<"x2,"<<itemname[10]<<"x1"<<endl;
	if(bag[8]>=2&&bag[10]>=1&&crafttable) cout<<"编号"<<11<<": 合成 "<<itemname[11]<<"x1 需要 "<<itemname[8]<<"x2,"<<itemname[10]<<"x1"<<endl;
	cout<<endl<<"输入0返回"<<endl;
	cin>>choose;
	switch(choose){
		case 0:
			return;	
		break;
		case 5:
			if(bag[1]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(2000);
				create();
			}
			bag[1]--;
			bag[5]+=4;
			cout<<"合成成功！"<<endl;
			Sleep(2000);
			create();
		break;	
		case 6:
			if(bag[2]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(2000);
				create();
			}
			bag[2]--;
			bag[6]+=4;
			cout<<"合成成功！"<<endl;
			Sleep(2000);
			create();
		break;
		case 7:
			if(bag[3]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(2000);
				create();
			}
			bag[3]--;
			bag[7]+=4;
			cout<<"合成成功！"<<endl;
			Sleep(2000);
			create();
		break;
		case 8:
			if(bag[4]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(2000);
				create();
			}
			bag[4]--;
			bag[8]+=4;
			cout<<"合成成功！"<<endl;
			Sleep(2000);
			create();
		break;
		case 9:
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
						Sleep(2000);
						create();
					}
					bag[5]-=4;
					bag[9]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
				case 2:
					if(bag[6]<4){
						cout<<"请勿乱输！"<<endl;
						Sleep(2000);
						create();
					}
					bag[6]-=4;
					bag[9]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
				case 3:
					if(bag[7]<4){
						cout<<"请勿乱输！"<<endl;
						Sleep(2000);
						create();
					}
					bag[7]-=4;
					bag[9]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
				case 4:
					if(bag[8]<4){
						cout<<"请勿乱输！"<<endl;
						Sleep(2000);
						create();
					}
					bag[8]-=4;
					bag[9]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
			}
		break;	
		case 10:
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
						Sleep(2000);
						create();
					}
					bag[5]-=2;
					bag[10]+=4;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
				case 2:
					if(bag[6]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(2000);
						create();
					}
					bag[6]-=2;
					bag[10]+=4;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
				case 3:
					if(bag[7]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(2000);
						create();
					}
					bag[7]-=2;
					bag[10]+=4;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
				case 4:
					if(bag[8]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(2000);
						create();
					}
					bag[8]-=2;
					bag[10]+=4;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
			}
		break;
		case 11:
			if(bag[10]<1){
				cout<<"请勿乱输！"<<endl;
				Sleep(2000);
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
						Sleep(2000);
						create();
					}
					bag[5]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
				case 2:
					if(bag[6]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(2000);
						create();
					}
					bag[6]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
				case 3:
					if(bag[7]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(2000);
						create();
					}
					bag[7]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
				case 4:
					if(bag[8]<2){
						cout<<"请勿乱输！"<<endl;
						Sleep(2000);
						create();
					}
					bag[8]-=2;
					bag[10]-=1;
					bag[11]+=1;
					cout<<"合成成功！"<<endl;
					Sleep(2000);
					create();
				break;
			}
		break;
	}
} 
void fight(string MN,int MH,int MA,int Mrand,int MD,int MS,int dis,int Adis,int xp){//战斗 敌人名 敌人生命 敌人最小攻击 浮动值 敌人防御 敌人速度 当前距离 敌人攻击距离 经验值 
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
				if(weapon2==1){
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
					cout<<"你举起盾牌！下回合你的防御大幅增加！"<<endl;
					defend=true;
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
				cout<<"1，向前移动 2，向后移动"<<endl;
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
			cout<<MN<<" 战败！"<<endl;
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
		if(Adis<5){
			if(dis<=Adis){
				cout<<MN<<" 对 "<<name<<" 进行攻击！"<<endl; 
				Sleep(1000);
				int damage=(MA+rand()%Mrand)*(100+rand()%20-rand()%20)*(100-defense)/10000; //浮动伤害 
				if(defend) defend=false;
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
		}else{
			if(dis<=Adis/3&&back==true){
				dis+=MS;
				cout<<MN<<" 后退了！"<<endl;
				Sleep(1000);
				cout<<"当前你和敌人的距离为"<<dis<<endl;
				Sleep(1500);
				system("cls");
				back=false;	
			}else{
				back=true;
				if(dis>Adis){
					if(dis-=MS>=0) dis-=MS;
					else dis=0;
					cout<<MN<<" 向 "<<name<<" 逼近了！"<<endl;
					Sleep(1000);
					cout<<"当前你和敌人的距离为"<<dis<<endl;
					Sleep(1500);
					system("cls");
				}else{
					cout<<MN<<" 对 "<<name<<" 进行攻击！"<<endl;
					Sleep(1000);
					int damage=(MA+rand()%Mrand)*(100+rand()%20-rand()%20)/100*(100-defense)/100; //浮动伤害 
					if(defend) defend=false;
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
			cout<<"你死了！"<<endl;
			place="村庄"; 
			Sleep(3000);
			health=2;
			system("cls");
			return;
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
	}
}
void explore(string place){//探索 
	if(place=="村庄"){		
		switch(rand()%6){
			case 0:
			cout<<"你遇到了铁傀儡！"<<endl;
			cout<<"0，离开  1，激怒"<<endl;
			cin>>choose;
			if(choose==1){
				fight("铁傀儡",100,8,6,40,2,10,3,200);
				credit-=20;
			}else{
				cout<<"你远离了铁傀儡"<<endl; 
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
					fight("恶霸村民",20,1,1,0,2,5,2,100);
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
						cout<<"被欺负的村民十分感激，给了你5颗绿宝石"<<endl;
              		 	money+=5;      
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
						money+=10;
						Sleep(1500);
						cout<<"获得了10颗绿宝石！"<<endl;
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
				cout<<"临走前，他给了你3颗绿宝石"<<endl;
				badguy=3;
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
						cout<<"要休息吗？需要3颗绿宝石（休息可恢复生命值）"<<endl;
						cout<<"0，离开  1，休息"<<endl;
						cin>>choose;
						if(choose==1){
							if(money<3){
								cout<<"你突然发现自己的钱不够，你只好尴尬的走了"<<endl;
								Sleep(2000);
								credit-=10;
							}else{
								cout<<"店主给你开了一间房，你在里面美美的睡了一觉..."<<endl;
								health=maxhealth;
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
								cout<<"Herobrine忠心耿耿的下属，亡灵的领导者Blackbone组织着亡灵生物们..."<<endl;
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
						fight("铁傀儡",100,8,6,40,2,10,3,200);
						if(dead){
							cout<<"你支开了铁傀儡，连忙灰溜溜的跑走了"<<endl; 
							Sleep(2000);
						}else{
							cout<<"你的钱被铁傀儡全部夺走了！"<<endl;
							Sleep(2000);
						}
					}
					cout<<"你偷偷摸了摸农民的口袋，发现有 "<<add<<" 颗绿宝石！"<<endl;
					money+=add;
					Sleep(1500);
					cout<<"你又悄悄地走了"<<endl;
					Sleep(2000); 
				}else{
					cout<<"你叫醒了农民"<<endl;
					Sleep(1500);
					cout<<"农民对你不停感谢"<<endl;
					credit+=2;
					Sleep(2000);
				}
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
		Sleep(3000);
	}
	if(place=="丛林"){
		int add=7+rand()%3;
		cout<<"获得丛林木"<<add<<"个！"<<endl; 
		bag[2]+=add;
		cout<<"当前拥有丛林木"<<bag[2]<<"个"<<endl;	
		Sleep(3000);
	}
	if(place=="雪地"){
		int add=8+rand()%6;
		cout<<"获得针叶木"<<add<<"个！"<<endl; 
		bag[3]+=add;
		cout<<"当前拥有针叶木"<<bag[3]<<"个"<<endl;	
		Sleep(3000);
	}
	if(place=="地狱"){
		int add=6+rand()%6; 
		cout<<"获得绯红木"<<add<<"个！"<<endl; 
		bag[4]+=add;
		cout<<"当前拥有绯红木"<<bag[4]<<"个"<<endl;	
		Sleep(3000);
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
	if(tool1==0){
		system("cls");
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
	}else{
		if(place=="洞穴"){
			if(tool1==0){
				cout<<"空手无法挖矿！请装备稿子后再来挖矿！"<<endl;
				Sleep(2000);
				return; 
			}
			cout<<"你现在装备："<<tool2name[tool2]<<endl<<endl;
			cout<<"提示：一些矿石只有特定或足够好的稿子才能挖掘。"<<endl;
			cout<<"      你的稿子决定了你挖掘矿石时的速度。"<<endl<<endl; 
			Sleep(2000);
			cout<<"0，返回  1，挖矿"<<endl;
			cin>>choose;
			if(choose==1){
				cout<<"0，挖圆石  1，挖矿物"<<endl;
				cin>>choose;
				if(choose==1){
					cout<<"你要挖多少块圆石？"<<endl;
					cin>>choose;
					cout<<"开始挖掘..."<<endl;
					Sleep(2000); 
					switch(tool1){
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
				}
			}else{
				system("cls");
				cout<<"探索矿洞中..."<<endl;	
				Sleep(8000+rand()%12000);
			}
		}
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
	system("cls"); 
	cout<<"显示顺序为 编号-物品名-数量"<<endl<<endl;
	cout<<"输入物品编号可查看详细信息"<<endl<<endl;
	cout<<"若未显示则为无物品"<<endl<<endl;
	for(int i=1;i<=100;i++){
		if(bag[i]>0) cout<<"编号 "<<i<<"  "<<itemname[i]<<" 数量："<<bag[i]<<" 个"<<endl;
		else continue;
	}
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
			checkbag();
		break;
		case 2:
			system("cls");
			cout<<"物品："<<itemname[2]<<endl; 
			cout<<"基础的木头，可在丛林砍树获得。可以制作丛林木板。"<<endl;
			Sleep(3000);
			checkbag();
		break;
		case 3:
			system("cls");
			cout<<"物品："<<itemname[3]<<endl; 
			cout<<"基础的木头，可在雪地砍树获得。可以制作针叶木木板。"<<endl;
			Sleep(3000);
			checkbag();
		break;
		case 4:
			system("cls");
			cout<<"物品："<<itemname[4]<<endl; 
			cout<<"来自地狱的木头，能防火，可在地狱砍树获得。可以制作绯红木板。"<<endl;
			Sleep(3000);
			checkbag();
		break;
		case 5:
			system("cls");
			cout<<"物品："<<itemname[5]<<endl; 
			cout<<"基础的木板，可以制作各种木制品。"<<endl;
			Sleep(3000);
			checkbag();
		break;
		case 6:
			system("cls");
			cout<<"物品："<<itemname[6]<<endl; 
			cout<<"基础的木板，可以制作各种木制品。"<<endl;
			Sleep(3000);
			checkbag();
		break;
		case 7:
			system("cls");
			cout<<"物品："<<itemname[7]<<endl; 
			cout<<"基础的木板，可以制作各种木制品。"<<endl;
			Sleep(3000);
			checkbag();
		break;
		case 8:
			system("cls");
			cout<<"物品："<<itemname[8]<<endl; 
			cout<<"来自地狱的木板，能防火，可以制作各种木制品。"<<endl;
			Sleep(3000);
			checkbag();
		break;
		case 9:
			system("cls");
			cout<<"物品："<<itemname[9]<<endl; 
			cout<<"一个制作站，在<建造>中将其放置便可合成更多新物品。"<<endl;
			Sleep(3000);
			checkbag();
		break;
		case 10:
			system("cls");
			cout<<"物品："<<itemname[10]<<endl;
			cout<<"木制的棍子，是组装武器和工具必备的材料。"<<endl;
			Sleep(3000);
			checkbag();
		break;
	}	
}
void weapon(){//装备 
	system("cls");
	cout<<"当前你装备头盔："<<armor1name[armor1]<<endl; 
	cout<<"当前你装备胸甲："<<armor2name[armor2]<<endl; 
	cout<<"当前你装备护腿："<<armor3name[armor3]<<endl; 
	cout<<"当前你装备靴子："<<armor4name[armor4]<<endl; 
	cout<<"当前你主手装备："<<weapon1name[weapon1]<<endl; 
	cout<<"当前你副手装备："<<weapon2name[weapon2]<<endl; 
	cin>>choose;
	return;
}
void build(){
	system("cls");
	cout<<"输入编号建造建筑"<<endl<<endl; 
	cout<<"输入0退出"<<endl<<endl;
	if(bag[9]>=1) cout<<"1 工作台"<<endl;
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
			bag[9]-=1;
			cout<<"建造成功！现在可合成更多物品！"<<endl;
			crafttable=true;
			Sleep(2000);
			build();
		break;	
	}
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
