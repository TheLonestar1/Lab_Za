#include<iostream>
#include<cmath>
using namespace std;

int SuperMod(int a, int x, int p){
	int n = (int)log2(x);
	int* arr = new int(n);
	int i = 0;
	int dec = x;
	while (dec)
    {
        arr[i] = dec % 2;
        dec /= 2;
 		i++;
    }
    
    int buff = (int)pow(a,1) % p;
    arr[n-1] = pow(buff,arr[n-1]);
    int result = arr[n-1];
    for(int i = n-2; i >= 0; i--){
    	buff = (int)pow(buff,2) % p;
    	arr[i] = pow(buff,arr[i]);
    	result *= arr[i];
	}
	return result % p;
}

void ArrSwap(int A[3], int B[3]){
	for(int i = 0; i < 3; i++)
		A[i] = B[i];
}

int* gcb(int a, int b){
	int U[3] = {a,1,0};
	int V[3] = {b,0,1};
	int T[3];
	int res[2];
	while(V[0] != 0){
		int q = U[0]/V[0];
		T[0] = U[0] % V[0];
		T[1] = U[1] - q*V[1];
		T[2] = U[2] - q*V[2];
		ArrSwap(U,V);
		ArrSwap(V,T);
	}
	res[0] = U[1];
	res[1] = U[2];
	return res;
}



int main(){
	int a,x,p;
	int* U = new int(2);
	int q,xa,xb,ya,yb,zab,zba;
	int y,m,k;
	int g;
	int* ak;
	int* am;
	while(1){
	
		char A;
		cout << "SuperMOD s , GCB - b, Key - k, GigantBaby - g, exit - Any key : ";
		cin >> A;
	
		switch(A){
			case 's':
				cout << "Enter A X P : ";
				cin >> a >> x >> p;
				cout << SuperMod(a,x,p) << endl;
				break;
			case 'b':	
				cout << "Enter A B : ";
				cin >> U[0] >> U[1];
				U = gcb(U[0],U[1]);
				cout << U[0] <<" "<< U[1];
				break;
			case 'k':	
				cout << "Enter q xa xb : ";
				cin >> q >> xa >> xb;
				p = 2*q + 1;
				g = 11;
				ya = SuperMod(g,xa,p);
				yb = SuperMod(g,xb,p);
				zab = SuperMod(yb,xa,p);
				zba = SuperMod(ya,xb,p);
				cout << ya << " " << yb << " " << zab << " "  << zba;
				break;
			case 'g':	
				cout << "Enter A P Y: ";
				cin >> a >> p >> y;
				m = (int)sqrt(p) + 1;
				k = (int)sqrt(p) + 1;
				ak = new int(k);
				am = new int(m);
				for(int i = 0; i < k;i++){
					ak[i] = y*(int)pow(a,i) % p;
				}
				ak[0] = a;
				for(int i = 1; i < m;i*=2){
					am[i] = (int)pow(a,i*2) % p;
				}
				for(int i = 0;i < k; i++){
					for(int j = 0; j < m;j++){
						if(ak[i] == am[j]){
							x = ak[i]*i - j;
							if(x > 0) break;
						}
					}
				}                 	
				cout << x;
				break;
			default:
				 return 0;	
		}
	}
	return 0;
}
