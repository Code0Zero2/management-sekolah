#include <iostream>
using namespace std;

struct siswa{
    string nama;
    string nisn;
    string kelas;
    string jurusan;
};

struct guru{
    string nama;
    string npsn;
    string mapel;
}; 

int totaldata = 100;
void pilmenu();
void datassw();
void mengulang();
//void datagru();
int pilmain;
bool ulang;
char balik;

int main(){
    do{
        system("cls");
        cout << "-------------------\n";
        cout << "selamat datang di SekolahKu\n\n";
        cout << "1. Data siswa\n";
        cout << "2. Data guru\n";
        cout << "3. exit\n";
        cout << "masukkan pilihan : ";
        cin >> pilmain;
        switch(pilmain){
            case 1 :
                datassw();
            break;
            case 2 :
                //datagru();
            break;
            case 3 :
                cout << "Terimakasih Sudah Menggunakan SekolahKu\n";
                system("exit");
            break;
            default :
                cout << "Pilihan tidak valid\n";
                cout << "Silahkan mengulang\n";
                system("pause");
            break;
        }
        if(pilmain > 3) {
            ulang = true;
        } else {
            ulang = false;
        }
    }while(ulang);
    return 0;
}

void pilmenu(){
    if(pilmain == 1){
        
        datassw();
    } else if(pilmain == 2){
        cout << "---- Guru ----\n";
        cout << "1. menambahkan data guru\n";
        cout << "2. menampilkan data guru\n";
        cout << "3. kembali ke menu utama\n";
        cout << "4. exit\n";
        cout << "masukkan pilihan";
        //datagru();
    } else {
        cout << "Terimakasih Sudah Menggunakan SekolahKu\n";
        system("exit");
    }
}

void datassw(){
    int tambahdata1 = 0;
    siswa datasiswa[totaldata];
    int pilssw, nbh;
    do{
        cout << "---- Siswa ----\n";
        cout << "1. menambahkan data siswa\n";
        cout << "2. menampilkan data siswa\n";
        cout << "3. kembali ke menu utama\n";
        cout << "4. exit\n";
        cout << "masukkan pilihan";
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
            case 3 :
                main();
            break;
            case 4 : 
                cout << "terimakasih";
                system("exit");
            break;
            default :
                cout << "input salah\n";
                cout << "silahkan kembali ke menu utama\n";
                system("pause");
            break;
        }
        if(pilssw == 4 || pilssw == 3){
            ulang = false;
        } else if(pilssw > 4) {
            ulang = true;
        } else {
            cout << "\nApakah Anda ingin kembali ke menu siswa?(y/n) : ";
            cin >> balik;
            if(balik == 'y'){
                ulang = true;
            } else {
                ulang = false;
                cout << "Terimakasih sudah menggunakan platform ini";
            }
        }
    }while(ulang);
} 

void datagru(){
    int tambahdata2 = 0;
    guru dataguru[totaldata];
    int pilgru, nbh;
    do{
        cout << "---- Siswa ----\n";
        cout << "1. menambahkan data guru\n";
        cout << "2. menampilkan data gurun\n";
        cout << "3. kembali ke menu utama\n";
        cout << "4. exit\n";
        cout << "masukkan pilihan";
        cin >> pilgru;
        switch(pilgru){
            case 1 :
            cout << "Ingin menambahkan berapa data guru : ";
            cin >> nbh;
            cin.ignore();
                if(tambahdata2 + nbh <= totaldata){
                    for(int i = 0; i < nbh; i++){
                        cout << "masukkan nama : ";
                        getline(cin, dataguru[tambahdata2].nama);
                        cout << "masukkan npsn : ";
                        getline(cin, dataguru[tambahdata2].npsn);
                        cout << "masukkan mapel : ";
                        getline(cin, dataguru[tambahdata2].mapel);
                        tambahdata2++;
                    }
                } else {
                    cout << "kapasitas sudah penuh\n";
                }
            break;
            case 2 :
                cout << "Data Siswa\n";
                for(int i = 0; i < tambahdata2; i++){
                    cout << "masukkan nama : " << dataguru[i].nama << endl ;
                    cout << "masukkan npsn : " << dataguru[i].npsn << endl;
                    cout << "masukkan mapel : " << dataguru[i].mapel << endl;
                    //cout << "masukkan jurusan : " << dataguru[i].jurusan << endl;
                }
            break;
            case 3 :
                main();
            break;
            case 4 : 
                cout << "terimakasih";
                system("exit");
            break;
            default :
                cout << "input salah\n";
                cout << "silahkan kembali ke menu utama\n";
                system("pause");
            break;
        }
        if(pilgru== 4 || pilgru == 3){
            ulang = false;
        } else if(pilgru > 4) {
            ulang = true;
        } else {
            cout << "\nApakah Anda ingin kembali ke menu guru?(y/n) : ";
            cin >> balik;
            if(balik == 'y'){
                ulang = true;
            } else {
                ulang = false;
                cout << "Terimakasih sudah menggunakan platform ini";
            }
        }
    }while(ulang);
}




void mengulang(){
    if(pilmain == 3){
        ulang = false;
    } else if(pilmain > 3) {
        ulang = true;
    } else {
        cout << "\nApakah Anda ingin kembali ke menu utama?(y/n) : ";
        cin >> balik;
        if(balik == 'y'){
            ulang = true;
        } else {
            ulang = false;
            cout << "Terimakasih sudah menggunakan platform ini";
        }
    }
}