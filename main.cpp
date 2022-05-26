#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    while (true){
        int boyut;
        int boyutt;

        cout<<"1. Matrisin boyutunu giriniz = ";
        cin>>boyut;
        cin>>boyutt;

        int array[boyut][boyutt];

        for(int i = 0; i < boyut; i++){
            for(int j = 0; j < boyutt; j++){
                cout<<i + 1<<"x"<<j + 1<<" elemani giriniz = ";
                cin>>array[i][j];
            }
        }

        cout<<"Girdiniz = "<<endl;

        for(int i = 0; i < boyut; i++){
            for(int j = 0; j < boyutt; j++){
                cout<<array[i][j]<<"\t";
            }
            cout<<endl;
        }
    ////////////////////////////////ISLEMLER////////////////////////////////////////////
        int decide;
        cout<<"Ne islemi Yapmak istersiniz ?"<<"\n1-> Transpose\n2-> Carpim\n3-> Toplama\n4-> Cikarma\n5->Cikis"<<endl;
        cin>>decide;

        if (decide == 1){

            int temparray;

            if (boyut == boyutt){

                for(int i = 0; i < boyut; i++){
                    for(int j = i + 1; j < boyutt; j++){
                        temparray = array[i][j];
                        array[i][j] = array[j][i];
                        array[j][i] = temparray;
                    }
                }
                for(int i = 0; i < boyut; i++){
                    for(int j = 0; j < boyutt; j++){
                        cout<<array[i][j]<<"\t";
                    }
                    cout<<endl;
                }
            }

            else {
                if (boyut > boyutt){
                    int newarrboyut[boyutt][boyut];
                    int temparraysec;
                    for(int i = 0; i < boyutt; i++){
                        for(int j = i; j < boyut; j++){
                            temparraysec = array[i][j];
                            newarrboyut[i][j] = array[j][i];
                            newarrboyut[j][i] = temparraysec;
                        }
                    }
                    for(int i = 0; i < boyutt; i++){
                        for(int j = 0; j < boyut; j++){
                            cout<<newarrboyut[i][j]<<"\t";
                        }
                        cout<<endl;
                    }
                }
                else{
                    int newarrboyutt[boyut][boyutt];
                    int temparraythi;
                    for(int i = 0; i < boyutt; i++){
                        for(int j = 0; j < boyut; j++){
                            temparraythi = array[i][j];
                            newarrboyutt[i][j] = array[j][i];
                            newarrboyutt[j][i] = temparraythi;
                        }
                    }
                    for(int i = 0; i < boyutt; i++){
                        for(int j = 0; j < boyut; j++){
                            cout<<newarrboyutt[i][j]<<"\t";
                        }
                        cout<<endl;
                    }
                }
            }
        }

        else if(decide == 2){
            int secboyut;
            int secboyutt;
            cout<<"2. Matrisin boyutunu giriniz = ";
            cin>>secboyut;
            cin>>secboyutt;

            if(boyutt != secboyut){
                cout<<"Girdiginiz matrisin sutun sayisi satir sayisina esit degildir.";
            }
            else {
                int secarray[secboyut][secboyutt];

                for(int i = 0; i < secboyut; i++){
                    for(int j = 0; j < secboyutt; j++){
                        cout<<i + 1<<"x"<<j + 1<<" elemani giriniz = ";
                        cin>>secarray[i][j];
                    }
                }

                cout<<"Birinci Matris;"<<endl;

                for(int i = 0; i < boyut; i++){
                    for(int j = 0; j < boyutt; j++){
                        cout<<array[i][j]<<"\t";
                    }
                    cout<<endl;
                }

                cout<<"Ikinci matris;"<<endl;

                for(int i = 0; i < secboyut; i++){
                    for(int j = 0; j < secboyutt; j++){
                        cout<<secarray[i][j]<<"\t";
                    }
                    cout<<endl;
                }

                int result = 0;
                cout<<"\n*********Sonuc********"<<"\n";
                for(int i = 0; i < boyut; i++){
                    int j;
                    for(j = 0; j < secboyutt; j++){
                        for(int m = 0; m < boyutt; m++){
                            //#[1] array[i][j] 0, 0 | 0, 1 & secarray[j][i] 0, 0 | 1, 0;
                            result += array[i][m] * secarray[m][j];
                        }
                        cout<<result<<"\t";
                        result = 0;
                    }
                    cout<<"\n"<<endl;
                }
            }
        }

        else if(decide == 3){
            int topboyut;
            int topboyutt;
            cout<<"2. Matrisin boyutunu giriniz = ";
            cin>>topboyut;
            cin>>topboyutt;
            int topmatris[topboyut][topboyutt];

            if (topboyut == boyut && topboyutt == boyutt){
                for(int i = 0; i < topboyut; i++){
                    for(int j = 0; j < topboyutt; j++){
                        cout<<i + 1<<"x"<<j + 1<<" degerini giriniz = ";
                        cin>>topmatris[i][j];
                    }
                }
                cout<<"Birinci Matris"<<"\n";
                for(int i = 0; i < boyut; i++){
                    for(int j = 0; j < boyutt; j++){
                        cout<<array[i][j]<<"\t";
                    }
                    cout<<endl;
                }
                cout<<"Ikinci Matris"<<"\n";
                for(int i = 0; i < topboyut; i++){
                    for(int j = 0; j < topboyutt; j++){
                        cout<<topmatris[i][j]<<"\t";
                    }
                    cout<<endl;
                }
                ///////ISLEM-TOPLAMA/////////
                cout<<"*****Sonuc******"<<"\n";
                int topresult = 0;
                for(int i = 0; i < topboyut; i++){
                    for(int j = 0; j < topboyutt; j++){
                        topresult = array[i][j] + topmatris[i][j];
                        cout<<topresult<<"\t";
                    }
                    cout<<endl;
                }
            }
            else {
                cout<<"\nGecerli bir deger giriniz!";
            }
        }
        else if(decide == 4){
            int cikboyut;
            int cikboyutt;
            cout<<"Lutfen 2. Matrisin boyutunu giriniz = ";
            cin>>cikboyut;
            cin>>cikboyutt;
            int cikmatris[cikboyut][cikboyutt];

            if (cikboyut == boyut && cikboyutt == boyutt){
                for(int i = 0; i < cikboyut; i++){
                    for(int j = 0; j < cikboyutt; j++){
                        cout<<i + 1<<"x"<<j + 1<<" degerini giriniz = ";
                        cin>>cikmatris[i][j];
                    }
                }
                cout<<"Birinci Matris"<<"\n";
                for(int i = 0; i < boyut; i++){
                    for(int j = 0; j < boyutt; j++){
                        cout<<array[i][j]<<"\t";
                    }
                    cout<<endl;
                }
                cout<<"Ikinci Matris"<<"\n";
                for(int i = 0; i < cikboyut; i++){
                    for(int j = 0; j < cikboyutt; j++){
                        cout<<cikmatris[i][j]<<"\t";
                    }
                    cout<<endl;
                }
                ///////ISLEM-CIKARMA/////////
                cout<<"*****Sonuc******"<<"\n";
                int cikresult = 0;
                for(int i = 0; i < cikboyut; i++){
                    for(int j = 0; j < cikboyutt; j++){
                        cikresult = array[i][j] - cikmatris[i][j];
                        cout<<cikresult<<"\t";
                    }
                    cout<<endl;
                }
            }
            else {
                cout<<"\nGecerli bir deger giriniz!";
            }
        }

        else if(decide == 5){
            break;
        }
    }

    return 0;
}
