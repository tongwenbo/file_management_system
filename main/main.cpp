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
     cout<<"* 1 添加记录    2 显示记录     *\n";
     cout<<"* 3 修改记录    4 保存记录     *\n";
	 cout<<"* 5 寻找记录    6 删除记录     *\n";
	 cout<<"* 7 统计记录                   *\n";
	 cout<<"********************************\n";
}
void display(student stu[],int len)
{
	system("cls");
	int i,j(0);
	int len1(0);
	if(len==0) 
	{
	    cout<<"无记录"<<endl;
	    return;
	}
	cout<<"学号\t成绩\t密码\t"<<endl;
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
		cout<<"文件打开失败"<<endl;
		return;
	}
	for(int i=0;i<len;i++)
	{
		fwrite(&stu[i],sizeof(student),1,p);
	}
	if(len>0)
	{
		cout<<"保存成功，记录数为"<<len<<endl;
	}
	else
	{
		system("cls");
		cout<<"保存失败"<<endl;
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
			cout<<"此表为空表";
			return;
	}
	while(1)
	{
		cout<<"输入要修改的学生学号";
		cin>>c;
		for(int i=0;i<=len-1;i++)
		{
			if(strcmp(stu[i].num,c)==0)
			{
				cout<<"输入要修改的成绩";
				cin>>s;
				stu[i].score=s;
				cout<<"输入新的密码";
				cin>>k;
				strcpy(stu[i].key,k);
				return;
			}
		}
		cout<<"不存在这个学号"<<endl;
	}
}
int append(student stu[],int len)
{
	int i;
	char num[6],ch;
	system("cls");
	while(1)
	{
		cout<<"输入学号（输入0返回）;"<<endl;
		cin>>num;
		if(strcmp(num,"0")==0)
			return len;
		for(i=0;i<len;i++)
		{
			if(strcmp(stu[i].num,num)==0)
				{
					cout<<"该学号已经存在,重试（y/n)";
			cin>>ch;
			if(ch=='y'||ch=='Y')
				break;
			else
			{
		        cout<<"按任意键返回"<<endl;
		        getchar();  
		        return len;
	        }
		        }
		}
		if(i==len)
			break;
	}
	strcpy(stu[len].num,num);
	cout<<"输入成绩:"<<endl;
	cin>>stu[len].score;
	cout<<"输入密码:"<<endl;
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
		cout<<"文件打开失败"<<endl;
		exit(0);
	}
	while(!feof(p))
	{
		if(fread(&stu[i],sizeof(student),1,p)==1)
			i++;
	}
	len=i;
	fclose(p);
	cout<<"记录数为"<<len<<endl;
	return len;
}
int putin(student stu[],int len)
{
	int i,j,k;
	cout<<"请输入五个学生的信息"<<endl;
	for(i=0;i<=4;i++)
	{
		cout<<"输入学号:";
		cin>>stu[i].num;
		cout<<"  输入成绩:";
		cin>>stu[i].score;
		cout<<"  输入密码:";
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
	cout<<"请输入要查找的学号:";
	cin>>n;
	for(int i=0;i<=4;i++)
	{
		if(strcmp(stu[i].num,n)==0)
		{
			cout<<"学号\t成绩\t密码"<<endl;
			cout<<stu[i].num<<"\t"<<stu[i].score<<"\t"<<stu[i].key<<endl;
			return;
		}
	}
	cout<<"未找到该生记录"<<endl;
	return;
}
int del(student stu[],int len)
{
	int j;
	char c[6];
	cout<<"请输入要删除的学号:";
	cin>>c;
	for(int i=0;i<=4;i++)
	{
		if(strcmp(stu[i].num,c)==0)
		{
			for(j=i;j<=4;j++)
			stu[i]=stu[i+1];
			len--;
			cout<<"删除成功"<<endl;
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
	cout<<"优的人数："<<a<<endl;
	cout<<"良的人数："<<b<<endl;
	cout<<"中的人数："<<c<<endl;
	cout<<"及格的人数："<<d<<endl;
	cout<<"不及格的人数："<<f<<endl;
	getchar();
}
void main()
{
	struct student stu[N];
	int len,choice;
	len=readfile(stu);
	cout<<"按任意键继续"<<endl;
	getchar();
	while(1)
	{
		system("cls");
		menu();
	system("pause");
	cout<<"选择菜单项(1~7)";
	cin>>choice;
	if(choice==4)
	{
		save(stu,len);
		cout<<"欢迎再次使用，按任意键退出"<<endl;
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
	default:cout<<"输入错误"<<endl;
	}
	}
}