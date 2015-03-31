#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define N 10

//1.建立数据系统
//2.输入输出
//3.修改数据

void Work(); //工作
void Respond(); //响应用户输入
void Record(); //将数据导出到computer.txt中
void Menu();//打印工作菜单
void Draw();//初始化仓库
void In();//入库
void Out();//出库
void Type();//在控制台中打印

struct node{
    int amount;
    char*  name;
    };

node computer[N];

int num=1000;

int main()
{
    Work();
    return 0;
}

void Work(){
    Menu();
    Respond();
    Record();
    Work();
    }

void Menu(){
    system("cls");
    cout<<"*************仓库管理系统*************"<<endl;
    cout<<endl;
    cout<<"1.初始化库存数据    2.入库            "<<endl;
    cout<<endl;
    cout<<"3.出库              4.打印当前库存数据"<<endl;
    cout<<endl;
    cout<<"5.退出系统                 "<<endl<<endl;
    }

void Respond(){
    int input;
    cout<<"请输入指令"<<endl;
    cin>>input;
    switch(input){
        case 1:Draw();break;
        case 2:In();break;
        case 3:Out();break;
        case 4:Type();break;
        case 5:exit(0);
        default:cout<<"输入有误"<<endl;Work();
        }
    }

void Record(){
    FILE *fp;
    fp=fopen("computer.dat","w");
    for(int i=1;i<=num;i++)
        fprintf(fp, "%s %d\n", computer[i].name, computer[i].amount);
    fclose(fp);
    }

void Draw(){
    cout<<"请输入品牌数"<<endl;
    cin>>num;
    cout<<"请输入电脑品牌以及仓库内数量"<<endl;
     for(int i=1;i<=num;i++){
           computer[i].name=(char *)malloc(100*sizeof(char));
           scanf("%s%d",computer[i].name,&computer[i].amount);
           }
    cout<<"新建仓库成功"<<endl;
    system("pause");
    }


void Type(){
    for(int i=1;i<=num;i++)
        cout<<computer[i].name<<' '<<computer[i].amount<<endl;
    system("pause");
    }

void Out(){
    int temp,data;
    system("cls");
    for(int i=1;i<=num;i++){
        cout<<i<<'.'<<computer[i].name<<endl;
        }
    cout<<"请输入产品编号以及出库数量"<<endl;
    cin>>temp>>data;
    computer[temp].amount-=data ;
    cout<<"数据修改成功"<<endl;
    system("pause");

    }

void In(){
    int temp,data;
    system("cls");
    for(int i=1;i<=num;i++){
        cout<<i<<'.'<<computer[i].name<<endl;
        }
    cout<<"请输入产品编号以及入库数量"<<endl;
    cin>>temp>>data;
    computer[temp].amount+=data ;
    cout<<"数据修改成功"<<endl;
    system("pause");
    }
