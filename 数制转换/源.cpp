#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cout<<"请输入十进制数n=";
	cin>>n;
	cout<<"请输入你要转换的进制m=";
	cin>>m;
	cout<<n<<"的"<<m<<"进制表示为：";
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

