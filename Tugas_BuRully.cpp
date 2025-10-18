#include <iostream>
using namespace std;

// Struktur tanggal lahir
struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

// Struktur nilai ujian
struct Nilai {
    float uas;
    float uts;
    float tugas;
};

// Struktur data pelajar
struct pelajar {
    string nama;
    int umur;
    string jurusan;
    Tanggal lahir;
    Nilai us;
};


// Fungsi untuk menghitung nilai akhir berdasarkan bobot
float hitungNilaiAkhir(Nilai n) {
    return n.uas * 0.4 + n.uts * 0.35 + n.tugas * 0.25;
}


void tampil(int jumlah, pelajar p[]){

    for(int i=0;i<jumlah;i++){

        cout<<"<<==========  INPUT DATA SISWA KE-"<<i+1<<"  ==========>>"<<endl;
        cout<<"Masukkan Nama : ";
        cin>>p[i].nama;
        cout<<"Masukkan Umur : ";
        cin>>p[i].umur;
        cout<<"Masukkan Jurusan : ";
        cin>>p[i].jurusan;
        cout << "Masukkan Tanggal Lahir : ";
        cin >> p[i].lahir.hari;
        cout << "Masukkan Bulan Lahir : ";
        cin >> p[i].lahir.bulan;
        cout << "Masukkan Tahun Lahir : ";
        cin >> p[i].lahir.tahun;
        cout << "Masukkan Nilai UAS : ";
        cin >> p[i].us.uas;
        cout << "Masukkan Nilai UTS : ";
        cin >> p[i].us.uts;
        cout << "Masukkan Nilai TUGAS : ";
        cin >> p[i].us.tugas;
        cout << endl;
    }
}

void hasil(int jumlah, pelajar p[]){

    for(int i=0;i<jumlah;i++){

        cout <<"***----------------------------------------------------------***"<<endl;
        cout << endl;
        cout <<"<<<<=================================   HASIL DATA SISWA KE-"<<(i+1)<<"   =================================>>>>"<<endl;
        cout << "Nama : " << p[i].nama << endl;
        cout << "Umur : " << p[i].umur << endl;
        cout << "Jurusan : " << p[i].jurusan << endl;
        cout << "Tanggal Lahir : " <<p[i].lahir.hari<<"-"<<p[i].lahir.bulan<<"-"<<p[i].lahir.tahun<<endl;
        cout << endl;
        cout << "  >>>  NILAI  <<<  "<<endl;
        cout << "Nilai Uas : "<<p[i].us.uas<<endl;
        cout << "Nilai Uts : "<<p[i].us.uts<<endl;
        cout << "Nilai Tugas : "<<p[i].us.tugas<<endl;
        cout << endl;
        cout << " ->>  BOBOT NILAI AKHIR  <<- "<<endl;
        cout << "UAS 40% : "<<p[i].us.uas * 0.4 <<endl;
        cout << "UTS 35% : "<<p[i].us.uts * 0.35 <<endl;
        cout << "TUGAS 25% : "<<p[i].us.tugas * 0.25 <<endl;


        // Cetak nilai akhir menggunakan fungsi hitungNilaiAkhir
        float nilaiAkhir = hitungNilaiAkhir(p[i].us);
        cout << "NILAI AKHIR YAITU: " << nilaiAkhir << endl;
        cout<<">>>>=============================================================================================<<<<"<<endl;
        cout << endl;
    }
}


int main() {
    int jumlah;
    cout << "Masukkan Jumlah Pelajar : ";
    cin >> jumlah;
    if (jumlah <= 0) {
        cout << " Jumlah Tidak Valid ";
        return 0;
    }

    pelajar p [jumlah];

    tampil(jumlah, p);
    hasil(jumlah, p);
    
    return 0;
}