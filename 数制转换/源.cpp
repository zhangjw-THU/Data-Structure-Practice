#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cout<<"������ʮ������n=";
	cin>>n;
	cout<<"��������Ҫת���Ľ���m=";
	cin>>m;
	cout<<n<<"��"<<m<<"���Ʊ�ʾΪ��";
	int a[20],i=0;
	while(n)
	{
		a[i]=n%m;
		n=n/m;
		i++;
	}
	
	while(i!=0)
	{
		i--;
		cout<<a[i];
	}
	cout<<endl;
	system("pause");
	return 0;
}

