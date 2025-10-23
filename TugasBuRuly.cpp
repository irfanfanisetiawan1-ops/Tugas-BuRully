#include <fstream>
#include <iostream>
using namespace std;

// Struktur tanggal lahir
struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

// Struktur nilai ujian dan pelajaran
struct Nilai {
    float uas;
    float uts;
    float tugas;

    float Mtk, BIn, Big, IPA;
};

// Struktur data pelajar
struct pelajar {
    string nama;
    string NISN;
    int umur;
    string jurusan;
    Tanggal lahir;
    Nilai us;
    Nilai Nilai;
};


// Fungsi untuk menghitung nilai akhir berdasarkan bobot
float hitungNilaiAkhir(Nilai n) {
    return n.uas * 0.4 + n.uts * 0.35 + n.tugas * 0.25;
}

// Fungsi untuk menghitung nilai akhir berdasarkan mata pelajaran
float nilaiAkhir(Nilai n) {
    return (n.Mtk * 0.35) + (n.IPA * 0.25) + (n.BIn * 0.20) + (n.Big * 0.20);
}


// INPUT DATA DARI USER 
void tampil(int jumlah, pelajar p[]){

    for(int i=0;i<jumlah;i++){

        cout<<"<<==========  INPUT DATA SISWA KE-"<<i+1<<"  ==========>>"<<endl;
        cout << "Masukkan Nama : ";
        cin >> p[i].nama;
        cout << "Masukkan NISN Siswa : ";
        cin >> p[i].NISN;
        cout << "Masukkan Umur : ";
        cin >> p[i].umur;
        cout << "Masukkan Jurusan : ";
        cin >> p[i].jurusan;
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

        cout << "Masukkan nilai Matematika: ";
        cin >> p[i].Nilai.Mtk;

        cout << "Masukkan nilai B. Indonesia: ";
        cin >> p[i].Nilai.BIn;

        cout << "Masukkan nilai B. Inggris: ";
        cin >> p[i].Nilai.Big;

        cout << "Masukkan nilai IPA: ";
        cin >> p[i].Nilai.IPA;

        cout << endl;
    }
}

// SIMPAN DATA KE FILE
void tambahDataSiswa(int jumlah, pelajar p[]) {
    ofstream file("data_siswa.txt", ios::app);
    
    for (int i = 0; i < jumlah; i++) {
        file << p[i].nama << " "
             << p[i].NISN << " "
             << p[i].umur << " "
             << p[i].jurusan << " "
             << p[i].lahir.hari << " " 
             << p[i].lahir.bulan << " " 
             << p[i].lahir.tahun << " "
             << p[i].us.uas << " "
             << p[i].us.uts << " " 
             << p[i].us.tugas << " "
             << p[i].Nilai.Mtk << " " 
             << p[i].Nilai.BIn << " "
             << p[i].Nilai.Big << " "
             << p[i].Nilai.IPA << endl;
    }
    file.close();
    cout << "Data siswa berhasil disimpan ke file 'data_siswa.txt'!"<<endl;
    cout << endl;
}


// MENAMBAHKAN FUNGSI UNTUK MEMBACA DATA dari file "data_siswa.txt" dan Menampilkannya
void tampilDataSiswa() {
    ifstream file("data_siswa.txt");
    if (!file.is_open()) {
        cout << "File 'data_siswa.txt' tidak dapat dibuka atau tidak ada.\n";
        return;
    }

    pelajar p;
    int adaa = 0;
    while (file >> p.nama >> p.NISN >> p.umur >> p.jurusan
                >> p.lahir.hari >> p.lahir.bulan >> p.lahir.tahun
                >> p.us.uas >> p.us.uts >> p.us.tugas
                >> p.Nilai.Mtk >> p.Nilai.BIn >> p.Nilai.Big >> p.Nilai.IPA) {
        adaa++;
        cout <<"-------------------------------------------------------------"<<endl;
        cout <<">>>====== DATA SISWA KE-"<< adaa <<" ======<<<"<<endl;
        cout << "Nama: " << p.nama << endl;
        cout << "NISN: " << p.NISN << endl;
        cout << "Umur: " << p.umur << endl;
        cout << "Jurusan: " << p.jurusan << endl;
        cout << "Tanggal Lahir: " << p.lahir.hari << "-" << p.lahir.bulan << "-" << p.lahir.tahun << endl;
        cout << "  --NILAI--  "<<endl;
        cout << "Nilai Uas : "<<p.us.uas<<endl;
        cout << "Nilai Uts : "<<p.us.uts<<endl;
        cout << "Nilai Tugas : "<<p.us.tugas<<endl;
        cout << "--NILAI PELAJARAN--" << endl;
        cout << "Matematika : " << p.Nilai.Mtk << endl;
        cout << "B. Indonesia : " << p.Nilai.BIn << endl;
        cout << "B. Inggris : " << p.Nilai.Big << endl;
        cout << "IPA : " << p.Nilai.IPA << endl;
        cout << "--BOBOT NILAI AKHIR-- \n";
        cout << "Nilai Akhir (Rata-rata umum): " << hitungNilaiAkhir(p.us) << endl;
        cout << "Nilai Akhir (Rata-rata mapel): " << nilaiAkhir(p.Nilai) << endl;
    }

    if (adaa == 0) {
        cout << "Tidak ada data dalam file 'data_siswa.txt'.";
    } 

    file.close();
}


// CARI DATA SISWA BERDASARKAN NISN 
void cariSiswa(string nisn) {
    ifstream file("data_siswa.txt");

    if (!file.is_open()) {
        cout << "File 'data_siswa.txt' tidak dapat dibuka atau tidak ada.\n";
        return;
    }

    pelajar p;
    bool ditemukan = false;

    while (file >> p.nama >> p.NISN >> p.umur >> p.jurusan
                >> p.lahir.hari >> p.lahir.bulan >> p.lahir.tahun
                >> p.us.uas >> p.us.uts >> p.us.tugas
                >> p.Nilai.Mtk >> p.Nilai.BIn >> p.Nilai.Big >> p.Nilai.IPA) {
        if (p.NISN == nisn) {
            cout << "\nData ditemukan!\n";
            cout << "Nama : " << p.nama << endl;
            cout << "Umur : " << p.umur << endl;
            cout << "Jurusan: " << p.jurusan << endl;
            cout << "Tanggal lahir : " << p.lahir.hari <<" "<< p.lahir.bulan <<" "<< p.lahir.tahun << endl;
            cout << "Nilai Akhir : " << nilaiAkhir(p.Nilai) << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
        cout << "Data dengan NISN " << nisn << " tidak ditemukan!" << endl;

    file.close();
}


// FUNGSI MENAMPILKAN DATA BERDASARKAN PERINGKAT 
void tampilRanking() {
    ifstream file("data_siswa.txt");

    pelajar data[100];
    int jumlah = 0;

    while (file >> data[jumlah].nama >> data[jumlah].NISN >> data[jumlah].umur >> data[jumlah].jurusan
           >> data[jumlah].lahir.hari >> data[jumlah].lahir.bulan >> data[jumlah].lahir.tahun
           >> data[jumlah].us.uas >> data[jumlah].us.uts >> data[jumlah].us.tugas
           >> data[jumlah].Nilai.Mtk >> data[jumlah].Nilai.BIn >> data[jumlah].Nilai.Big >> data[jumlah].Nilai.IPA) {
        jumlah++;
    }
    file.close();

    if (jumlah == 0) {
        cout << "Belum ada data siswa di file.\n";
        return;
    }

    // urutkan dengan (bubble sort) berdasarkan nilai akhir 
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (nilaiAkhir(data[j].Nilai) < nilaiAkhir(data[j + 1].Nilai)) {
                pelajar temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    // Tampilkan hasil ranking
    cout << "<<===== DAFTAR PERINGKAT SISWA BERDASARKAN NILAI AKHIR =====>>"<<endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << data[i].nama
             << " (NISN: " << data[i].NISN << ")"
             << " - Nilai Akhir: " << nilaiAkhir(data[i].Nilai) << endl;
    }
    cout << "===========================================================\n";
}


// TAMPILKAN HASIL DI KONSOL 
void hasil(int jumlah, pelajar p[]){
    for(int i=0;i<jumlah;i++){

        cout <<"-------------------------------------------------------------"<<endl;
        cout <<">>>====== DATA SISWA KE-"<<(i+1)<<" ======<<<"<<endl;
        cout << "Nama: " << p[i].nama << endl;
        cout << "Umur: " << p[i].umur << endl;
        cout << "Jurusan: " << p[i].jurusan << endl;
        cout << "Tanggal Lahir: " <<p[i].lahir.hari<<"-"<<p[i].lahir.bulan<<"-"<<p[i].lahir.tahun<<endl;
        cout << "  --NILAI--  "<<endl;
        cout << "Nilai Uas : "<<p[i].us.uas<<endl;
        cout << "Nilai Uts : "<<p[i].us.uts<<endl;
        cout << "Nilai Tugas : "<<p[i].us.tugas<<endl;
        cout << "--NILAI PELAJARAN--" << endl;
        cout << "Matematika : " << p[i].Nilai.Mtk << endl;
        cout << "B. Indonesia : " << p[i].Nilai.BIn << endl;
        cout << "B. Inggris : " << p[i].Nilai.Big << endl;
        cout << "IPA : " << p[i].Nilai.IPA << endl;
        cout << "--BOBOT NILAI AKHIR-- \n";

        float nilaiA = hitungNilaiAkhir(p[i].us);
        float nilaiB = nilaiAkhir(p[i].Nilai);
        cout << "Nilai Akhir (Rata-rata umum): " << nilaiA << endl;
        cout << "Nilai Akhir (Rata-rata mapel): " << nilaiB << endl;

        cout <<"================================="<<endl;
    }
}



// BAGIAN UNTUK MAIN PROGRAM 
int main() {
    int jumlah;
    cout << "Masukkan Jumlah Pelajar : ";
    cin >> jumlah;

    pelajar p[jumlah];

    tampil(jumlah, p);
    tambahDataSiswa(jumlah, p);
    hasil(jumlah, p);

    
    char cari;
    cout << " Ingin mencari data siswa ? (y/t): ";
    cin >> cari;
    if (cari == 'y' || cari == 'Y') {
        string nisn;
        cout << "Masukkan NISN Yang Ingin Dicari : ";
        cin >> nisn;
        cariSiswa(nisn);
    }
    char tampillagi;
    cout << " Ingin membaca data dari file siswa.txt dan ditampilkan ? (y/t): ";
    cin >> tampillagi;
    if (tampillagi == 'y' || tampillagi == 'Y') {
        tampilDataSiswa();       // Menampilkan semua data dari file data_siswa.txt
    }
    char tampilrank;
    cout << "Ingin menampilkan data berdasarkan peringkat? (y/t): ";
    cin >> tampilrank;
    if (tampilrank == 'y' || tampilrank == 'Y') {
        tampilRanking();
    }

    return 0;
}