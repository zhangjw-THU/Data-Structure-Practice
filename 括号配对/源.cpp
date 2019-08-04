#include<iostream>
using namespace std;

struct SqStack{
	int l[20];
	int top;
};
int correct(char* s)
{
	char st[20];
	int top=-1,i=0;
	int tag=1;
	while(s[i]!='\0'&&tag)
	{
		if(s[i]=='('||s[i]=='['||s[i]=='{')
		{
			top++;
			st[top]=s[i];
		}
		if(s[i]==')')
		{
			if(top!=-1&&st[top]=='(')
				top--;
			else
				tag=0;
		}
		if(s[i]==']')
		{
			if(top!=-1&&st[top]=='[')
				top--;
			else
				tag=0;
		}
		if(s[i]=='}')
		{
			if(top!=-1&&st[top]=='{')
				top--;
			else
				tag=0;
		}
		i++;
	}
	if(top!=-1)
		tag=0;
	return tag;
}
void main()
{
	char a[20];
	int i=0;
	while((a[i]=cin.get())!='\n')
	{
		i++;
	}
	a[i]='\0';
	cout<<correct(a)<<endl;
	system("pause");
}
			
		
