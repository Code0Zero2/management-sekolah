#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int totaldata = 100;
const string siswaData = "data_siswa.txt";
const string guruData = "data_guru.txt";
string usnAdmin = "FUFU", passAdmin = "fafa";
int jumlahdata = 0, jumlahdataguru = 0;

struct siswa{
    string nama;
    int nisn;
    string kelas;
    string jurusan;
    float nilai1;
    float nilai2;
    float nilai3;
    float rerata;
};
siswa datasiswa[totaldata];

struct guru{
    string nama;
    int npsn;
    string mapel;
    string waliKls;
}; 
guru dataguru[totaldata];

string gantiSpasi(string str);
string gantiUnscore(string str);
void tarikData(int *jumlahData, int *jumlahData2);
void quicksort(int low, int high);
void tmbhssw(int nbh);
void tmbhgru(int nbh);
void adminMenu();
void siswaMenu();
void waliKelas();
void guruMenu();
void rangking();
void userMenu();
void cetakNilai();
void tampilSemuaSiswaMipa();
void tampilSemuaSiswaIps();

int main(){
    int pilmain;
    string usnMimin, pwMimin;
    int coba = 3;
    do{
        system("cls");
        cout << "Selamat Datang di E-rapor Akademi Konoha\n";
        cout << "Login sebagai : \n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Exit\n";
        cout << "Masukkan pilihan : ";
        cin >> pilmain;
        switch (pilmain) {
            case 1:
                while (coba--){
                    system("cls");
                    cout << "Silahkan Login Sebagai Admin\n";
                    cout << "Username : ";
                    cin >> usnMimin;
                    cout << "Password : ";
                    cin >> pwMimin;
                    if(usnMimin == usnAdmin && pwMimin == passAdmin){
                        cout << "login Berhasil\n";
                        break;
                    } else {
                        cout << "Username atau Password salah!!\n";
                        cout << "Silahkan mengulang\n";
                        cout << "Sisa kesempatan : " << coba << endl;            
                        if(coba == 0){
                            system("cls");
                            cout << "Kesempatan Habis\n";
                            cout << "Coba beberapa saat lagi\n";
                            system("exit");
                        }   
                    }
                    system("pause");
                }
                system("pause");
                adminMenu();
            break;
            case 2 : 
                userMenu();
            break;
            case 3 :
                system("exit");
            break;
            default:
                cout << "pilihan tidak valid\n";
            break;
        }
    } while (pilmain != 3);
    return 0;
}

void adminMenu(){
    int nbh, pilmain, tmbh; 
    do{
        system("cls");
        cout << "---- Admin ----\n";
        cout << "1. menambahkan data siswa\n";
        cout << "2. menambahkan data guru\n";\
        cout << "3. kembali ke login menu \n";
        cout << "4. exit\n";
        cout << "Masukkan pilihan : ";
        cin >> pilmain;
        switch (pilmain){
            case 1 :
                cout << "Ingin menambahkan berapa data siswa : ";
                cin >> nbh;
                tmbhssw(nbh);
            break;
            case 2 :
                cout << "Ingin menambahkan berapa data guru : ";
                cin >> tmbh;
                cin.ignore();
                tmbhgru(tmbh);
            break;
            case 3 :
                return;
            break;
            case 4 :
                cout << "Terimakasih Sudah Menggunakan E-rapor\n";
                exit(0);
            break;
            default:
                cout << "Pilihan tidak valid\n";
                cout << "Silahkan mengulang\n";
                system("pause");
            break;
        }
    } while (pilmain !=4);
}

void userMenu(){
    int pilmain;
    tarikData(&jumlahdata, &jumlahdataguru);
    do{
        system("cls");
        cout << "------Menu Utama------\n";\
        cout << "1. Siswa\n";
        cout << "2. Guru\n";
        cout << "3. Kembali ke login menu\n";
        cout << "4. exit\n";
        cout << "masukkan pilihan : ";
        cin >> pilmain;
        switch(pilmain){
            case 1 :
                siswaMenu();
            break;
            case 2 :
                guruMenu();
            break;
            case 3 :
                return;
            break;
            case 4 :
                cout << "Terimakasih Sudah Menggunakan E-rapor\n";
                exit(0);
            break;
            default :
                cout << "Pilihan tidak valid\n";
                cout << "Silahkan mengulang\n";
                system("pause");
            break;
        }
    }while(pilmain != 4);
}

void siswaMenu(){
    int pilssw, nbh;
    do{
        system("cls");
        cout << "---- Siswa ----\n";
        cout << "1. Menampilkan ranking pararel siswa\n";
        cout << "2. Cetak transkirp nilai\n";
        cout << "3. Kembali ke menu utama\n";
        cout << "4. exit\n";
        cout << "masukkan pilihan : ";
        cin >> pilssw;
        switch(pilssw){
            case 1 :
                system("cls");
                rangking();
                system("pause");
            break;
            case 2 :
                system("cls");
                cetakNilai();
                system("pause");
            break;
            case 3 :
                return;
            break;
            case 4 : 
                cout << "Terimakasih Sudah Menggunakan E-rapor\n";
                exit(0);
            break;
            default :
                cout << "input salah\n";
                cout << "silahkan kembali ke menu siswa\n";
                system("pause");
            break;
        }
    }while(pilssw != 4);
} 

void guruMenu(){
    int nbh, pilmain;
    do{
        system("cls");
        cout << "---- Guru ----\n";
        cout << "1. menampilkan data seluruh siswa\n";
        cout << "2. menampilkan data guru\n";
        cout << "3. menampilkan data siswa kelas diampu\n";
        cout << "4. kembali ke menu utama\n";
        cout << "5. exit\n";
        cout << "masukkan pilihan : ";
        cin >> pilmain;
        switch(pilmain){
            case 1 :
                system("cls");
                cout << "Data Siswa\n";
                tampilSemuaSiswaMipa();
                cout << endl;
                tampilSemuaSiswaIps();
                system("pause");
            break;
            case 2 :
                system("cls");
                cout << "===========================================================\n";
                cout << "| " << left << setw(5) << "NPSN"  
                     << "| " << setw(20) << "Nama" 
                     << "| " << setw(15) << "Mata Pelajaran"
                     << "| " << setw(10) << "Wali Kelas" << "|\n";
                    cout << "-----------------------------------------------------------\n";
                for(int i = 0; i < jumlahdataguru; i++){
                    cout << "| " << left << setw(5) << dataguru[i].npsn  
                        << "| " << setw(20) << dataguru[i].nama 
                        << "| " << setw(15) << dataguru[i].mapel
                        << "| " << setw(10) << dataguru[i].waliKls << "|\n";
                }
                cout << "===========================================================\n";
                system("pause");
            break;
            case 3 :
                system("cls");
                waliKelas();
                system("pause");
            break;
            case 4 : 
                return;
            break;
            case 5 : 
                cout << "Terimakasih Sudah Menggunakan E-rapor\n";
                exit(0);
            break;
            default :
                cout << "input salah\n";
                cout << "silahkan kembali ke menu guru\n";
                system("pause");
            break;
        }
    }while(pilmain !=5);
}

void tmbhssw(int nbh){
    ofstream keFileSsw(siswaData, ios::app);
    if(nbh <= 0){
        keFileSsw.close();
        cout << "Data berhasil ditambahkan\n";
        system("pause");
        return;
    }
    cout << "Nama : ";
    cin.ignore();
    getline(cin, datasiswa[nbh].nama);
    cout << "NISN : ";
    cin >> datasiswa[nbh].nisn;
    cout << "Kelas : ";
    cin.ignore();
    getline(cin, datasiswa[nbh].kelas);
    cout << "Jurusan : ";
    getline(cin, datasiswa[nbh].jurusan);
    cout << "Masukkan nilai\n";
    for(char& c : datasiswa[nbh].jurusan) c = toupper(c);
    for(char& c : datasiswa[nbh].kelas) c = toupper(c);
    if(datasiswa[nbh].jurusan == "MIPA"){
        cout << "Matematika : ";
        cin >> datasiswa[nbh].nilai1;
        cout << "Kimia : ";
        cin >> datasiswa[nbh].nilai2;
        cout << "Fisika : ";
        cin >> datasiswa[nbh].nilai3;
    } else if(datasiswa[nbh].jurusan == "IPS"){
        cout << "Sosiologi : ";
        cin >> datasiswa[nbh].nilai1;
        cout << "Geografi : ";
        cin >> datasiswa[nbh].nilai2;
        cout << "Ekonomi : ";
        cin >> datasiswa[nbh].nilai3;
    }
    if(keFileSsw.is_open()){
        keFileSsw << gantiSpasi(datasiswa[nbh].nama) << " "
                  << datasiswa[nbh].nisn << " "
                  << datasiswa[nbh].kelas << " "
                  << datasiswa[nbh].jurusan << " "
                  << datasiswa[nbh].nilai1 << " "
                  << datasiswa[nbh].nilai2 << " "
                  << datasiswa[nbh].nilai3
                  << endl;
        keFileSsw.close();
    }
    return tmbhssw(nbh - 1);
}

void tmbhgru(int tmbh){
    ofstream keFileSsw(guruData, ios::app);
    if(tmbh <= 0){
        keFileSsw.close();
        cout << "Data berhasil ditambahkan\n";
        system("pause");
        return;
    }
    cout << "Nama : ";
    getline(cin, dataguru[tmbh].nama);
    cout << "NPSN : ";
    cin >> dataguru[tmbh].npsn;
    cout << "Matapelajaran diampu : ";
    cin.ignore();
    getline(cin, dataguru[tmbh].mapel);
    cout << "Kelas diampu : ";
    getline(cin, dataguru[tmbh].waliKls);
    for(char& c : dataguru[tmbh].waliKls) c = toupper(c);
    cout << endl;
    if(keFileSsw.is_open()){
        keFileSsw << gantiSpasi(dataguru[tmbh].nama) << " "
                  << dataguru[tmbh].npsn << " "
                  << dataguru[tmbh].mapel << " "
                  << dataguru[tmbh].waliKls
                  << endl;
        keFileSsw.close();
    }
    return tmbhgru(tmbh - 1);
}

void rangking(){
    int j = 1;
    if (jumlahdata == 0) {
        cout << "Belum ada data!\n";
    }
    quicksort(0, jumlahdata - 1);
    cout << "Rangking siswa prarel sekolah:\n";
    cout << "==============================================================\n";
    cout << "| " << left << setw(3) << "No"  
         << "| " << setw(20) << "Nama" 
         << "| " << setw(8) << "Kelas"
         << "| " << setw(10) << "Jurusan"
         << "| " << setw(10) << "Rata-rata" << "|\n";
    cout << "==============================================================\n";
        for (int i =jumlahdata - 1; i >= 0; i--) {
            cout << "| " <<  left   << setw(3) << j  
                << "| " << setw(20) << datasiswa[i].nama 
                << "| " << setw(8) << datasiswa[i].kelas
                << "| " << setw(10) << datasiswa[i].jurusan
                << "| " << setw(10) << datasiswa[i].rerata << "|\n";
        j++;
    }
    cout << "==============================================================\n";
}

void cetakNilai(){
    string nama;
    int j = -1, nisn;
    bool ketemu = false;
    cout << "Isi data dibawah ini :\n";
    cout << "Nama : ";
    cin.ignore();
    getline(cin, nama);
    cout << "NISN : ";
    cin >> nisn;
    for (int i = 0; i < jumlahdata; i++){
        if(datasiswa[i].nama == nama && datasiswa[i].nisn == nisn){
            j = i;
            break;
        }
    }
    if(j != -1 ){
        system("cls");
        cout << "         Transkrip Nilai           ";
        cout << "\n=================================\n";
        cout << "Nama\t: " << datasiswa[j].nama << endl;
        cout << "NISN\t: " << datasiswa[j].nisn << endl;
        cout << "Kelas\t: " << datasiswa[j].kelas << endl;
        cout << "Jurusan : " << datasiswa[j].jurusan << endl;
        cout << "=================================\n";
        cout << "| " <<  left   << setw(20) << "Mata Pelajaran"  
        << "| " << setw(8) << "Nilai" << "|\n";
        if(datasiswa[j].jurusan == "MIPA"){
            cout << "| " <<  left   << setw(20) << "Matematika"  
                 << "| " << setw(8) << datasiswa[j].nilai1 << "|\n";
            cout << "| " <<  left   << setw(20) << "Kimia"  
                 << "| " << setw(8) << datasiswa[j].nilai2 << "|\n";
            cout << "| " <<  left   << setw(20) << "Fisika"  
                 << "| " << setw(8) << datasiswa[j].nilai3 << "|\n";
        } else if(datasiswa[j].jurusan == "IPS"){
            cout << "| " <<  left   << setw(20) << "Sosiologi"  
                 << "| " << setw(8) << datasiswa[j].nilai1 << "|\n";
            cout << "| " <<  left   << setw(20) << "Geografi"  
                 << "| " << setw(8) << datasiswa[j].nilai2 << "|\n";
            cout << "| " <<  left   << setw(20) << "Ekonomi"  
                 << "| " << setw(8) << datasiswa[j].nilai3 << "|\n";
        }
        cout << "=================================\n";
        cout << "| " <<  left   << setw(20) << "Rata-rata"  
             << "| " << setw(8) << datasiswa[j].rerata << "|\n";
        cout << "=================================\n";
    } else {
        cout << "Data yang dicari tidak ditemukan!" << endl;
    }
}

void waliKelas(){
    string nama, tmpkelas;
    int j = -1, npsn, n = 1;
    cout << "Masukkan data anda\n";
    cout << "Nama : ";
    cin.ignore();
    getline(cin, nama);
    cout << "NPSN : ";
    cin >> npsn;
    for (int i = 0; i < jumlahdataguru; i++){
        if(dataguru[i].nama == nama && dataguru[i].npsn == npsn){
            j = i;
            tmpkelas = dataguru[i].waliKls;
            break;
        }
    }
    if(j != -1){
        cout << "\nBerikut daftar siswa dari kelas "<< tmpkelas << " yang anda ampu :\n";
        cout << "================================================\n";
        cout << "| " << left << setw(3) << "No"  
             << "| "<< setw(20) << "Nama" 
             << "| " << setw(8) << "Kelas"
             << "| " << setw(8) << "Jurusan" << "|\n";
        cout << "================================================\n";
        for(int k = 0; k < jumlahdata; k++){
            if(datasiswa[k].kelas == tmpkelas){
                cout << "| " << left << setw(3) << n  
                     << "| "<< setw(20) << datasiswa[k].nama 
                     << "| " << setw(8) << datasiswa[k].kelas
                     << "| " << setw(8) << datasiswa[k].jurusan << "|\n";
                n++;
            } 
        }
       cout << "================================================\n";
    } else {
        cout << "Data tidak ditemukan\n";
    }
}

void tampilSemuaSiswaMipa(){
    int low = 0, high = jumlahdata - 1;
    if (low < high) {
        string pivot = datasiswa[high].kelas;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (datasiswa[j].kelas < pivot) {
                i++;
                swap(datasiswa[i], datasiswa[j]);
            }
        }
        swap(datasiswa[i+1], datasiswa[high]);

        int pi = i + 1;
        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
    cout << setw(101) << setfill('=') << "\n" << setfill(' ');
    cout << "\n| " <<  left   << setw(5) << "NISN"  
         << "| " << setw(20) << "Nama" 
         << "| " << setw(8) << "Kelas"
         << "| " << setw(10) << "Jurusan"
         << "| " << setw(10) << "Matematika"  
         << "| " << setw(10) << "Kimia" 
         << "| " << setw(10) << "Fisika"
         << "| " << setw(10) << "Rata-rata" << "|";
    cout << setw(101) << setfill('-') << "\n" << setfill(' ');
    for(int i = 0; i < jumlahdata; i++){
        if(datasiswa[i].jurusan == "MIPA"){
            cout << "\n| " << left << setw(5) << datasiswa[i].nisn 
                 << "| " << setw(20) << datasiswa[i].nama 
                 << "| " << setw(8) << datasiswa[i].kelas
                 << "| " << setw(10) << datasiswa[i].jurusan
                 << "| " << setw(10) << datasiswa[i].nilai1
                 << "| " << setw(10) << datasiswa[i].nilai2
                 << "| " << setw(10) << datasiswa[i].nilai3
                 << "| " << setw(10) << datasiswa[i].rerata << "|";
        } 
    }
    cout << setw(101) << setfill('=') << "\n" << setfill(' ') << endl;
}

void tampilSemuaSiswaIps(){
    int low = 0, high = jumlahdata - 1;
    if (low < high) {
        string pivot = datasiswa[high].kelas;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (datasiswa[j].kelas < pivot) {
                i++;
                swap(datasiswa[i], datasiswa[j]);
            }
        }
        swap(datasiswa[i+1], datasiswa[high]);

        int pi = i + 1;
        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
    cout << setw(101) << setfill('=') << "\n" << setfill(' ');
    cout << "\n| " <<  left   << setw(5) << "NISN"  
         << "| " << setw(20) << "Nama" 
         << "| " << setw(8) << "Kelas"
         << "| " << setw(10) << "Jurusan"
         << "| " << setw(10) << "Sosiologi"  
         << "| " << setw(10) << "Geografi" 
         << "| " << setw(10) << "Ekonomi"
         << "| " << setw(10) << "Rata-rata" << "|";
    cout << setw(101) << setfill('-') << "\n" << setfill(' ');
    for(int i = 0; i < jumlahdata; i++){
        if(datasiswa[i].jurusan == "IPS"){
            cout << "\n| " << left << setw(5) << datasiswa[i].nisn 
                 << "| " << setw(20) << datasiswa[i].nama 
                 << "| " << setw(8) << datasiswa[i].kelas
                 << "| " << setw(10) << datasiswa[i].jurusan
                 << "| " << setw(10) << datasiswa[i].nilai1
                 << "| " << setw(10) << datasiswa[i].nilai2
                 << "| " << setw(10) << datasiswa[i].nilai3
                 << "| " << setw(10) << datasiswa[i].rerata << "|";
        }
    }
    cout << setw(101) << setfill('=') << "\n" << setfill(' ') << endl;
}

string gantiSpasi(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' '){
            str.replace(i,1,1,'_');
        }
    }
    return str;
}

string gantiUnscore(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '_'){
            str.replace(i,1,1,' ');
        }
    }
    return str;
}

void tarikData(int *jumlahData, int *jumlahData2){
        ifstream keStruct(siswaData);
        if(!keStruct.is_open()){
            ofstream bikinDulu(siswaData);
            bikinDulu.close(); 
        }
        
        string tmpNama, tmpKls, tmpJrs;
        float tmpNilai1, tmpNilai2, tmpNilai3;
        int i = 0, tmpNisn;
        while (keStruct >> tmpNama >> tmpNisn >> tmpKls >> tmpJrs >> tmpNilai1 >> tmpNilai2 >> tmpNilai3){
            tmpNama = gantiUnscore(tmpNama);
            datasiswa[i].nama = tmpNama;
            datasiswa[i].nisn = tmpNisn;
            datasiswa[i].kelas = tmpKls;
            datasiswa[i].jurusan = tmpJrs;
            datasiswa[i].nilai1 = tmpNilai1;
            datasiswa[i].nilai2 = tmpNilai2;
            datasiswa[i].nilai3 = tmpNilai3;
            datasiswa[i].rerata = (tmpNilai1 + tmpNilai2 + tmpNilai3) / 3;
            i++;
            if(i>=totaldata) {
                break;
            }
        }
        keStruct.close();
        *jumlahData = i; 
        
        ifstream keStructRt(guruData);
        if(!keStructRt.is_open()){
            ofstream bikinDulu(guruData);
            bikinDulu.close(); 
        }
    
        string  tmpMapel, tmpWalikls;
        int j = 0, tmpNpsn;
        while (keStructRt >> tmpNama >> tmpNpsn >> tmpMapel >> tmpWalikls){
            dataguru[j].nama = gantiUnscore(tmpNama);
            dataguru[j].npsn = tmpNpsn;
            dataguru[j].mapel = tmpMapel;
            dataguru[j].waliKls = tmpWalikls;
            j++;
            if(j>=totaldata) {
                break;
            }
        }
        keStructRt.close();
        *jumlahData2 = j; 
    }

void quicksort(int low, int high) {
    if (low < high) {
        float pivot = datasiswa[high].rerata;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (datasiswa[j].rerata < pivot) {
                i++;
                swap(datasiswa[i], datasiswa[j]);
            }
        }
        swap(datasiswa[i+1], datasiswa[high]);

        int pi = i + 1;
        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
}