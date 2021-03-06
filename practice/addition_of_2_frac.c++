#include <iostream>
#include <vector>
using namespace std;

class fraction{
	public:
		long long a;
		long long b;
};

long long gcd(long long a,long long b){
	if(a<b){
		int temp = a;
		a = b;
		b = temp;
	}
	long long rem = a % b;
	while(rem!=0){
		a=b;
		b=rem;
		rem = a % b;
	}
	return b;
}
long long lcm(long long a, long long b){  
    return (a*b)/gcd(a, b);  
}  


fraction addfraction(fraction num1, fraction num2){
	fraction result;
	long long l = lcm(num1.b,num2.b);
	result.a = ((l/num1.b) * num1.a) + ((l/num2.b) * num2.a);
	result.b = l;
	return result;
}
void inputfraction(fraction& num1, fraction& num2){
	cout<<"Enter first fractions: ";
	cin>>num1.a>>num1.b;
	if(num1.b == 0){
		cout<<"You can't have 0 in denominator\n.Terminating Program\n";
		exit(0);
	}
	cout<<"Enter second fractions: ";
	cin>>num2.a>>num2.b;
	if(num2.b == 0){
		cout<<"You can't have 0 in denominator.\nTerminating Program\n";
		exit(0);
	}
}
void displayfraction(fraction& num1, fraction& num2, fraction& res){
	cout<<num1.a<<"/"<<num1.b<<" + ";
	cout<<num2.a<<"/"<<num2.b<<" = ";
	cout<<res.a<<"/"<<res.b<<"\n";
}

int main(){
	fraction num1, num2,res;
	inputfraction(num1,num2);		
	res = addfraction(num1,num2);
	long long normalize = gcd(res.a,res.b);
	res.a = res.a/normalize;
	res.b = res.b/normalize;
	displayfraction(num1,num2,res);
}
