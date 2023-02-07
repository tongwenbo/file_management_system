#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define N 5
struct student
{
	char num[6];
	int score;
	char key[15];
};
void menu()
{
	 system("cls");	   	
	 cout<<"********************************\n";
     cout<<"* 1 ��Ӽ�¼    2 ��ʾ��¼     *\n";
     cout<<"* 3 �޸ļ�¼    4 �����¼     *\n";
	 cout<<"* 5 Ѱ�Ҽ�¼    6 ɾ����¼     *\n";
	 cout<<"* 7 ͳ�Ƽ�¼                   *\n";
	 cout<<"********************************\n";
}
void display(student stu[],int len)
{
	system("cls");
	int i,j(0);
	int len1(0);
	if(len==0) 
	{
	    cout<<"�޼�¼"<<endl;
	    return;
	}
	cout<<"ѧ��\t�ɼ�\t����\t"<<endl;
	for(i=0;i<len;i++)
	{
		cout<<stu[len].num<<'\t'<<stu[len].score<<'\t'<<stu[len].key<<'\t'<<endl;
		//len1=strlen(stu[len].key);
		//for(j=0;j<len1;i++)
		//{
		//	cout<<"*";
	//	}
		//cout<<'\t'<<endl;
	}
}
void save(student stu[],int len)
{
	FILE *p;
	p=fopen("d:\\CT3\student.dat","wb");
	if(p==NULL)
	{
		cout<<"�ļ���ʧ��"<<endl;
		return;
	}
	for(int i=0;i<len;i++)
	{
		fwrite(&stu[i],sizeof(student),1,p);
	}
	if(len>0)
	{
		cout<<"����ɹ�����¼��Ϊ"<<len<<endl;
	}
	else
	{
		system("cls");
		cout<<"����ʧ��"<<endl;
	}
	fclose(p);
}
void modify(student stu[],int len)
{
	char c[6];
	int s;
	char k[15];
	if(len==0)
	{
			cout<<"�˱�Ϊ�ձ�";
			return;
	}
	while(1)
	{
		cout<<"����Ҫ�޸ĵ�ѧ��ѧ��";
		cin>>c;
		for(int i=0;i<=len-1;i++)
		{
			if(strcmp(stu[i].num,c)==0)
			{
				cout<<"����Ҫ�޸ĵĳɼ�";
				cin>>s;
				stu[i].score=s;
				cout<<"�����µ�����";
				cin>>k;
				strcpy(stu[i].key,k);
				return;
			}
		}
		cout<<"���������ѧ��"<<endl;
	}
}
int append(student stu[],int len)
{
	int i;
	char num[6],ch;
	system("cls");
	while(1)
	{
		cout<<"����ѧ�ţ�����0���أ�;"<<endl;
		cin>>num;
		if(strcmp(num,"0")==0)
			return len;
		for(i=0;i<len;i++)
		{
			if(strcmp(stu[i].num,num)==0)
				{
					cout<<"��ѧ���Ѿ�����,���ԣ�y/n)";
			cin>>ch;
			if(ch=='y'||ch=='Y')
				break;
			else
			{
		        cout<<"�����������"<<endl;
		        getchar();  
		        return len;
	        }
		        }
		}
		if(i==len)
			break;
	}
	strcpy(stu[len].num,num);
	cout<<"����ɼ�:"<<endl;
	cin>>stu[len].score;
	cout<<"��������:"<<endl;
	cin>>stu[len].key;
	len++;
	return len;
}
int readfile(student stu[])
{
	FILE *p;
	int i=0;
	int len;
	p=fopen("d:\\CT3\student.dat","ab+");
	if(p==NULL)
	{
		cout<<"�ļ���ʧ��"<<endl;
		exit(0);
	}
	while(!feof(p))
	{
		if(fread(&stu[i],sizeof(student),1,p)==1)
			i++;
	}
	len=i;
	fclose(p);
	cout<<"��¼��Ϊ"<<len<<endl;
	return len;
}
int putin(student stu[],int len)
{
	int i,j,k;
	cout<<"���������ѧ������Ϣ"<<endl;
	for(i=0;i<=4;i++)
	{
		cout<<"����ѧ��:";
		cin>>stu[i].num;
		cout<<"  ����ɼ�:";
		cin>>stu[i].score;
		cout<<"  ��������:";
		cin>>stu[i].key;
		cout<<endl;
		len++;
	}
	return len;
	for(k=0;k<=4;k++)
	{
	for(j=0;j<=3;j++)
	{
		if(stu[j].score>stu[j+1].score)
		{
			student t=stu[j];
			stu[j]=stu[j+1];
			stu[j+1]=t;
		}
	}
	}
}
void search(student stu[],int len)
{
	char n[6];
	cout<<"������Ҫ���ҵ�ѧ��:";
	cin>>n;
	for(int i=0;i<=4;i++)
	{
		if(strcmp(stu[i].num,n)==0)
		{
			cout<<"ѧ��\t�ɼ�\t����"<<endl;
			cout<<stu[i].num<<"\t"<<stu[i].score<<"\t"<<stu[i].key<<endl;
			return;
		}
	}
	cout<<"δ�ҵ�������¼"<<endl;
	return;
}
int del(student stu[],int len)
{
	int j;
	char c[6];
	cout<<"������Ҫɾ����ѧ��:";
	cin>>c;
	for(int i=0;i<=4;i++)
	{
		if(strcmp(stu[i].num,c)==0)
		{
			for(j=i;j<=4;j++)
			stu[i]=stu[i+1];
			len--;
			cout<<"ɾ���ɹ�"<<endl;
			return len;
		}
	}
}
void count(student stu[],int len)
{
	int a(0),b(0),c(0),d(0),f(0);
	for(int i=0;i<=4;i++)
	{
		if(stu[i].score>=90)
			a++;
		else if(stu[i].score>=80)
			b++;
		else if(stu[i].score>=70)
			c++;
		else if(stu[i].score>=60)
			d++;
		else if(stu[i].score<60)
			f++;
	}
	cout<<"�ŵ�������"<<a<<endl;
	cout<<"����������"<<b<<endl;
	cout<<"�е�������"<<c<<endl;
	cout<<"�����������"<<d<<endl;
	cout<<"�������������"<<f<<endl;
	getchar();
}
void main()
{
	struct student stu[N];
	int len,choice;
	len=readfile(stu);
	cout<<"�����������"<<endl;
	getchar();
	while(1)
	{
		system("cls");
		menu();
	system("pause");
	cout<<"ѡ��˵���(1~7)";
	cin>>choice;
	if(choice==4)
	{
		save(stu,len);
		cout<<"��ӭ�ٴ�ʹ�ã���������˳�"<<endl;
		getchar();
		break;
	}
	switch(choice)
	{
	case(1):len=putin(stu,len);break;
	case(2):display(stu,len);break;
	case(3):modify(stu,len);break;
	case(5):search(stu,len);break;
	case(6):len=del(stu,len);break;
	case(7):count(stu,len);break;	
	default:cout<<"�������"<<endl;
	}
	}
}