#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int mochila(vector<vector<int>> &mem,int n, vector<int> p, vector<int> b, int m, vector<int> &s){

	//Caso: base n disminuye a el ultimo valor
	if(n<1 || m<=0){
		return 0;
	}

	else if(mem[n][m]!=-1){ //si ya está calculado
		return mem[n][m];
	}

	//caso recursivo: el objeto actual no cabe
	else if(p[n-1]>m){

		s[n-1]=0;
		mem[n][m]=mochila(mem,n-1,p,b,m,s);
		return mem[n][m]; //no lo cojo

	}else{

		//Caso recursivo: elijo coger o no coger 
	 	int si, no;
	 	vector<int> s_si = s;//iguales al vector pero creo una copia para que no hayan fallos
		vector<int> s_no = s; //cero un vector de eleccion para cada camino para luego devolver el del camino que da el maximo valor

	 	si=mochila(mem,n-1,p,b,m-p[n-1],s_si)+b[n-1];
	 	no=mochila(mem,n-1,p,b,m,s_no);
	 
	 	mem[n][m]=max(si,no);

	 	if(si>no){ //si el valor maximo es el de si, copio su contenido en s
			s=s_si;
			s[n-1]=1;
	 	}else{
			s=s_no;
			s[n-1]=0;
	 	}
	 
	 	return mem[n][m];

	}
}


int main(){

	int n=4;
	int m; cin>>m;
	vector<int> p(n); 
	for(int i=0; i<n; i++){
		cin>>p[i];
	}

	vector<int> b(n);
	for(int i=0; i<n; i++){
                cin>>b[i];
        }

        vector<vector<int>> mem(n+1, vector<int>(m+1, -1));
	vector<int> s(n);

	cout<<mochila(mem,n,p,b,m, s)<<endl;

	for(int i=0; i<n; i++){
		cout<<s[i];
	}

	return 0;

}
