#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

int monedas(int i, vector<int> v, int M, vector<vector<int>> &mem){

        if(mem[i][M]>0){ // Si ya está calculado
                return mem[i][M];
        }

        if(i==0){ // No quedan monedas disponibles
                return 0;
        }

        if(M<v[i-1]){ // La moneda no cabe paso a la siguiente
                mem[i][M] = monedas(i-1,v,M,mem);
        }
        else{
                mem[i][M] = min(monedas(i-1,v,M,mem),
                                monedas(i,v,M-v[i-1],mem)+1);
        }
        return mem[i][M];
}

int main(){

	int i=3;
	int M; cin>>M;

	vector<int> v(i);
	for(int j=0; j<i; j++){
		cin>>v[j];
	}
	
	vector<vector<int>> mem(i+1,vector<int>(M+1,-1));
	for(int j=0; j<i; j++){
		mem[j][0]=0;
	}

	cout<<monedas(i,v,M,mem);


	return 0;
}
