#include <iostream>
using namespace std;

struct siswa{
    string nama;
    string nisn;
    string kelas;
    string jurusan;
};
int totaldata = 100;
void pilmenu();
void datassw();
void datagru();
int pilmain;

int main(){
    cout << "-------------------\n";
    cout << "selamat datang di SekolahKu\n\n";
    cout << "1. Data siswa\n";
    cout << "2. Data guru\n";
    cout << "3. exit\n";
    cout << "masukkan pilihan : ";
    pilmenu();   
}

void pilmenu(){
    cin >> pilmain;
    if(pilmain == 1){
        cout << "---- Siswa ----\n";
        cout << "1. menambahkan data siswa\n";
        cout << "2. menampilkan data siswa\n";
        cout << "3. exit\n";
        cout << "masukkan pilihan";
        datassw();
    } else if(pilmain == 2){

    } else {
        cout << "Terimakasih Sudah Menggunakan SekolahKu\n";
        system("exit");
    }
}

void datassw(){
    int tambahdata1 = 0;
    siswa datasiswa[totaldata];
    int pilssw, nbh;
    cin >> pilssw;
    switch(pilssw){
        case 1 :
        cout << "Ingin menambahkan berapa data siswa : ";
        cin >> nbh;
        cin.ignore();
            if(tambahdata1 + nbh <= totaldata){
                for(int i = 0; i < nbh; i++){
                    cout << "masukkan nama : ";
                    getline(cin, datasiswa[tambahdata1].nama);
                    cout << "masukkan nisn : ";
                    getline(cin, datasiswa[tambahdata1].nisn);
                    cout << "masukkan kelas : ";
                    getline(cin, datasiswa[tambahdata1].kelas);
                    cout << "masukkan jurusan : ";
                    getline(cin, datasiswa[tambahdata1].jurusan);
                    tambahdata1++;
                }
            } else {
                cout << "kapasitas sudah penuh\n";
            }
        break;
        case 2 :
            cout << "Data Siswa\n";
            for(int i = 0; i < tambahdata1; i++){
                cout << "masukkan nama : " << datasiswa[i].nama << endl ;
                cout << "masukkan nisn : " << datasiswa[i].nisn << endl;
                cout << "masukkan kelas : " << datasiswa[i].kelas << endl;
                cout << "masukkan jurusan : " << datasiswa[i].jurusan << endl;
            }  
        break;
        default :
        system("pause");
        break;
    }
}