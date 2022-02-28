#include <iostream>
using namespace std;

long int faktorial (int A);

int main(){

	int r,hasil;

	cout<<"Masukan Nilai = ";
	cin>>r;

	hasil=faktorial(r);
	cout<<"Faktorial "<<r<<"!= "<<hasil<<endl;
}

long int faktorial (int A){
	if (A==1)
		return(A);
		else
		return (A*faktorial(A-1));
}