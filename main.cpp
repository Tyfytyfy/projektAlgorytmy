#include <iostream>
#include <ctime>
#include <chrono>
#include <conio.h>
using namespace std;
using namespace chrono;

//funkcja do wypisania tablicy w formie spirali, przyjmuje trzy arguemnty tablicê, liczbê wierszy(rows - r), liczbê kolumn(columns - c)
void printSpiral(int A[][5],int r,int c){
    //4 zmienne pomocnicze oraz zmienna dir która okreœla kierunek po którym poruszamy siê po tablicy
    int T=0, B = r - 1, L = 0, R = c - 1, dir = 0;

    while(T <= B && L <= R){
        //je¿eli dir == 0 wtedy poruszamy siê w lewo
        if(dir == 0){
            for(int i = L; i<=R; i++)
                cout<<A[T][i]<<" ";
                T++;
        }
        //je¿eli dir == 1 wtedy poruszamy siê w dó³
        else if(dir == 1){
            for(int i = T; i<=B; i++)
                cout<<A[i][R]<<" ";
                R--;
        }
        //je¿eli dir == 2 wtedy poruszamy siê w prawo
        else if(dir == 2){
            for(int i = R; i>=L; i--)
                cout<<A[B][i]<<" ";
                B--;
        }
        //je¿eli dir == 3 wtedy poruszamy siê w górê
        else if(dir == 3){
            for(int i = B; i>=T; i--)
                cout<<A[i][L]<<" ";
                L++;
        }
        //tu siê zmienia kierunek tablicy
        dir = (dir+1)%4;
    }
}


int main() {
    srand (time(NULL));
    int rows=5, columns=5 ;

    //tu zaczyna siê liczenie ile czasu wykonuje siê program
    auto start = high_resolution_clock::now();

    int arr[5][5] = {{1,2,3,4,5}, {16,17,18,19,6}, {15,24,25,20,7}, {14,23,22,21,8}, {13,12,11,10,9}};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout<<arr[i][j]<<" \n"[j == columns-1];
        }
    }

    cout<<endl;
    cout<<"spirala"<<endl;
    printSpiral(arr,rows,columns);
    //tu koñczy siê liczenie
    auto stop = high_resolution_clock::now();
    //obliczanie ile czasu w mikrosekundach
    auto duration = duration_cast<microseconds>(stop - start);
    //wypisanie czasu
    cout <<endl<< duration.count() << endl;
    getch();
    return 0;
}
