#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define N 10

//1.��������ϵͳ
//2.�������
//3.�޸�����

void Work(); //����
void Respond(); //��Ӧ�û�����
void Record(); //�����ݵ�����computer.txt��
void Menu();//��ӡ�����˵�
void Draw();//��ʼ���ֿ�
void In();//���
void Out();//����
void Type();//�ڿ���̨�д�ӡ

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
    cout<<"*************�ֿ����ϵͳ*************"<<endl;
    cout<<endl;
    cout<<"1.��ʼ���������    2.���            "<<endl;
    cout<<endl;
    cout<<"3.����              4.��ӡ��ǰ�������"<<endl;
    cout<<endl;
    cout<<"5.�˳�ϵͳ                 "<<endl<<endl;
    }

void Respond(){
    int input;
    cout<<"������ָ��"<<endl;
    cin>>input;
    switch(input){
        case 1:Draw();break;
        case 2:In();break;
        case 3:Out();break;
        case 4:Type();break;
        case 5:exit(0);
        default:cout<<"��������"<<endl;Work();
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
    cout<<"������Ʒ����"<<endl;
    cin>>num;
    cout<<"���������Ʒ���Լ��ֿ�������"<<endl;
     for(int i=1;i<=num;i++){
           computer[i].name=(char *)malloc(100*sizeof(char));
           scanf("%s%d",computer[i].name,&computer[i].amount);
           }
    cout<<"�½��ֿ�ɹ�"<<endl;
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
    cout<<"�������Ʒ����Լ���������"<<endl;
    cin>>temp>>data;
    computer[temp].amount-=data ;
    cout<<"�����޸ĳɹ�"<<endl;
    system("pause");

    }

void In(){
    int temp,data;
    system("cls");
    for(int i=1;i<=num;i++){
        cout<<i<<'.'<<computer[i].name<<endl;
        }
    cout<<"�������Ʒ����Լ��������"<<endl;
    cin>>temp>>data;
    computer[temp].amount+=data ;
    cout<<"�����޸ĳɹ�"<<endl;
    system("pause");
    }
