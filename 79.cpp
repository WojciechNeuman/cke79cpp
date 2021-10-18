#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool czy_wspolne (double x1, double y1, double r1, double x2, double y2, double r2){
    double odleglosc = sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
    if (r1 + r2 >= odleglosc && odleglosc >= abs(r2-r1)) return true;
    else return false;
}

int main (){
    ifstream wejscie ("okregi.txt");
    ofstream wyjscie ("wyniki79.txt");
    double x[2000], y[2000], r[2000];
    for (int i = 0; i < 2000; i++){
        wejscie >> x[i] >> y[i] >> r[i];
    }
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
    //zadanie 1
    wyjscie << "OdpowiedŸ do zadania 1" << endl;
    for (int i = 0; i < 2000; i++){
        if (x[i] > 0 && y[i] > 0 && y[i] - r[i] > 0 && x[i] - r[i] > 0) c1++;
        else if (x[i] < 0 && y[i] < 0 && y[i] + r[i] < 0 && x[i] + r[i] < 0) c3++;
        else if (x[i] < 0 && y[i] > 0 && y[i] - r[i] > 0 && x[i] + r[i] < 0) c2++;
        else if (x[i] > 0 && y[i] < 0 && y[i] + r[i] < 0 && x[i] - r[i] > 0) c4++;
        else c5++;
    }
    wyjscie << c1 << " " << c2 << " " << c3 << " " << c4 << " " << c5 << endl;

    // zadanie 2
    wyjscie << endl << "OdpowiedŸ do zadania 2" << endl;
    int licznik2 = 0;
    for (int i = 0; i < 1999; i++){
        for (int j = i + 1; j < 2000; j++){
            if (r[i] == r[j]){
                if (x[i] == x[j] && -y[i] == y[j]) licznik2++;
                if (-x[i] == x[j] && y[i] == y[j]) licznik2++;
            }
        }
    }
    wyjscie << licznik2 << endl;

    //zadanie 3
    wyjscie << endl << "OdpowiedŸ do zadania 3" << endl;
    int licznik3 = 0;
    for (int i = 0; i < 1999; i++){
        for (int j = i + 1; j < 2000; j++){
            if (r[i] == r[j]){
                if (x[i] == y[j] && y[i] == -x[j]) licznik3++;
                if (x[i] == -y[j] && y[i] == x[j]) licznik3++;
            }
        }
    }
    wyjscie << licznik3 << endl;

    //zadanie 4
    wyjscie << endl << "OdpowiedŸ do zadania 4" << endl;
    int i = 0;
    int najdluzszy = 1;
    while (i < 1000){
        int check = 1;
        int ciag = 1;
        bool ok = true;
        while (ok){
            if (czy_wspolne(x[i],y[i],r[i],x[i+1],y[i+1],r[i+1])){
                i++; ciag++; check++;
            }
            else {
                    ok = false;
                    if (najdluzszy < check) najdluzszy = check;
            }
        }
        wyjscie << ciag << " ";
        i++;
    }
    wyjscie << endl << najdluzszy;

}
