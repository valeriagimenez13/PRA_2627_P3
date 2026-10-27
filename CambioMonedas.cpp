#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;


const int INF = 1000000000;

int Cambio(int i, int M, vector<int>& v,
           vector<vector<int>>& memo) {

    // Caso base: ya hemos conseguido la cantidad
    if (M == 0) {
        return 0;
    }

    // Caso base: no quedan monedas y falta dinero
    if (i >= v.size() && M>0) {
        return INF; //devuelvo un numero imposible
    }

    // Si ya hemos calculado este resultado
    if (memo[i][M] != -1) {
        return memo[i][M];
    }

    // Si la moneda actual vale más de lo que necesitamos
    if (M < v[i]) {
        memo[i][M] = Cambio(i + 1, M, v, memo); //pasamos a a la siguiente
    } else {
        // Opción 1: no coger la moneda
        int no_coger = Cambio(i + 1, M, v, memo);

        // Opción 2: coger la moneda
        int coger = Cambio(i, M - v[i], v, memo); //le resto al valor, el valor de la moneda

        if (coger != INF) { //si la cojo y se puede coger, sumo 1 
            coger = coger + 1;
        }

        // Elegir el mínimo
        memo[i][M] = min(no_coger, coger);
    }

    return memo[i][M];
}


int main(){

	int i=3;
	int M; cin>>M;

	vector<int> v(i);
	for(int j=0; j<i; j++){
		cin>>v[j];
	}
	
	vector<vector<int>> memo(i+1,vector<int>(M+1,-1));
	for(int j=0; j<i; j++){ //por que el valor 0 a devolver hara que la opcion de coger las monedas sea siempre no_coger
		memo[j][0]=0;
	}

	cout<<Cambio(0,M,v,memo); //llamo a la funcion desde la primera moneda



	return 0;
}
