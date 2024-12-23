#include<iostream>
using namespace std;


void ttowerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    //cout << "Move disk " << n << " from rod " << from_rod
        // << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
     //return pow(2,n)-1;
}

   


     long long towerOfHanoi(int n, int from, int to, int aux) {
        // Your code here
        // tohcal(n,from,aux,to);
        
        ttowerOfHanoi(n,from,to,aux);
        
        return      pow(2,n)-1;
        
    
    }

int main(){

return 0;
}