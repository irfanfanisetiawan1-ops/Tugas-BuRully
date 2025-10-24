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

// Fungsi menghitung nilai akhir umum
float hitungNilaiAkhir(Nilai n) {
    return n.uas * 0.4 + n.uts * 0.35 + n.tugas * 0.25;
}

// Fungsi menghitung nilai akhir mapel
float nilaiAkhir(Nilai n) {
    return (n.Mtk * 0.35) + (n.IPA * 0.25) + (n.BIn * 0.20) + (n.Big * 0.20);
}

// INPUT DATA SISWA DARI USER
void tampil(int jumlah, pelajar p[]) {
    for (int i = 0; i < jumlah; i++) {
        cout << "\n<<==========  INPUT DATA SISWA KE-" << i + 1 << "  ==========>>" << endl;

        cin.ignore();
        cout << "Masukkan Nama : ";
        getline(cin, p[i].nama);

        cout << "Masukkan NISN Siswa : ";
        cin >> p[i].NISN;

        cout << "Masukkan Umur : ";
        cin >> p[i].umur;

        cin.ignore();
        cout << "Masukkan Jurusan : ";
        getline(cin, p[i].jurusan);

        cout << "Masukkan Tanggal Lahir (hari bulan tahun): ";
        cin >> p[i].lahir.hari >> p[i].lahir.bulan >> p[i].lahir.tahun;

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
    }
}

// SIMPAN DATA KE FILE
void tambahDataSiswa(int jumlah, pelajar p[]) {
    ofstream file("data_siswa.txt", ios::app);

    for (int i = 0; i < jumlah; i++) {
        // Ganti spasi jadi tanda _
        string namaFix = p[i].nama;
        string jurusanFix = p[i].jurusan;
        for (int j = 0; j < namaFix.size(); j++)
            if (namaFix[j] == ' ') namaFix[j] = '_';
        for (int j = 0; j < jurusanFix.size(); j++)
            if (jurusanFix[j] == ' ') jurusanFix[j] = '_';

        file << namaFix << " "
             << p[i].NISN << " "
             << p[i].umur << " "
             << jurusanFix << " "
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
    cout << "\nData siswa berhasil disimpan ke file 'data_siswa.txt'!\n";
}

// TAMPILKAN DATA DARI FILE
void tampilDataSiswa() {
    ifstream file("data_siswa.txt");
    if (!file.is_open()) {
        cout << "File 'data_siswa.txt' tidak dapat dibuka atau tidak ada.\n";
        return;
    }

    pelajar p;
    int jumlah = 0;

    while (file >> p.nama >> p.NISN >> p.umur >> p.jurusan
                >> p.lahir.hari >> p.lahir.bulan >> p.lahir.tahun
                >> p.us.uas >> p.us.uts >> p.us.tugas
                >> p.Nilai.Mtk >> p.Nilai.BIn >> p.Nilai.Big >> p.Nilai.IPA) {

        // Kembalikan _ menjadi spasi
        for (int j = 0; j < p.nama.size(); j++)
            if (p.nama[j] == '_') p.nama[j] = ' ';
        for (int j = 0; j < p.jurusan.size(); j++)
            if (p.jurusan[j] == '_') p.jurusan[j] = ' ';

        jumlah++;

        cout << "\n-------------------------------------------------------------\n";
        cout << "DATA SISWA KE-" << jumlah << endl;
        cout << "Nama          : " << p.nama << endl;
        cout << "NISN          : " << p.NISN << endl;
        cout << "Umur          : " << p.umur << endl;
        cout << "Jurusan       : " << p.jurusan << endl;
        cout << "Tanggal Lahir : " << p.lahir.hari << "-" << p.lahir.bulan << "-" << p.lahir.tahun << endl;
        cout << "Nilai UAS     : " << p.us.uas << endl;
        cout << "Nilai UTS     : " << p.us.uts << endl;
        cout << "Nilai TUGAS   : " << p.us.tugas << endl;
        cout << "Matematika    : " << p.Nilai.Mtk << endl;
        cout << "B. Indonesia  : " << p.Nilai.BIn << endl;
        cout << "B. Inggris    : " << p.Nilai.Big << endl;
        cout << "IPA           : " << p.Nilai.IPA << endl;
        cout << "Nilai Akhir (Umum) : " << hitungNilaiAkhir(p.us) << endl;
        cout << "Nilai Akhir (Mapel): " << nilaiAkhir(p.Nilai) << endl;
    }

    if (jumlah == 0) {
        cout << "Tidak ada data dalam file 'data_siswa.txt'.\n";
    }

    file.close();
}

// CARI SISWA BERDASARKAN NISN
void cariSiswa(string nisn) {
    ifstream file("data_siswa.txt");
    if (!file.is_open()) {
        cout << "File 'data_siswa.txt' tidak dapat dibuka atau tidak ada.\n";
        return;
    }

    pelajar p;
    bool ketemu = false;

    while (file >> p.nama >> p.NISN >> p.umur >> p.jurusan
                >> p.lahir.hari >> p.lahir.bulan >> p.lahir.tahun
                >> p.us.uas >> p.us.uts >> p.us.tugas
                >> p.Nilai.Mtk >> p.Nilai.BIn >> p.Nilai.Big >> p.Nilai.IPA) {

        if (p.NISN == nisn) {
            // ubah _ jadi spasi
            for (int j = 0; j < p.nama.size(); j++)
                if (p.nama[j] == '_') p.nama[j] = ' ';
            for (int j = 0; j < p.jurusan.size(); j++)
                if (p.jurusan[j] == '_') p.jurusan[j] = ' ';

            cout << "\nData ditemukan!\n";
            cout << "Nama          : " << p.nama << endl;
            cout << "Umur          : " << p.umur << endl;
            cout << "Jurusan       : " << p.jurusan << endl;
            cout << "Tanggal Lahir : " << p.lahir.hari << "-" << p.lahir.bulan << "-" << p.lahir.tahun << endl;
            cout << "Nilai Akhir   : " << nilaiAkhir(p.Nilai) << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "Data dengan NISN " << nisn << " tidak ditemukan!\n";
    }

    file.close();
}

// URUTKAN DATA BERDASARKAN PERINGKAT NILAI AKHIR 
void tampilRangking(int jumlah, pelajar p[]) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (nilaiAkhir(p[j].Nilai) < nilaiAkhir(p[j + 1].Nilai)) {
                pelajar temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    cout << "\n=== URUTAN RANGKING SISWA ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Rangking " << i + 1 << ": " << p[i].nama
             << " | NISN: " << p[i].NISN
             << " | Nilai Akhir: " << nilaiAkhir(p[i].Nilai) << endl;
    }
}

// TAMPILKAN HASIL INPUT DI KONSOL
void hasil(int jumlah, pelajar p[]) {
    for (int i = 0; i < jumlah; i++) {
        cout << "\n-------------------------------------------------------------" << endl;
        cout << ">>>====== DATA SISWA KE-" << (i + 1) << " ======<<<" << endl;
        cout << "Nama: " << p[i].nama << endl;
        cout << "Umur: " << p[i].umur << endl;
        cout << "Jurusan: " << p[i].jurusan << endl;
        cout << "Tanggal Lahir: " << p[i].lahir.hari << "-" << p[i].lahir.bulan << "-" << p[i].lahir.tahun << endl;
        cout << "-- NILAI --" << endl;
        cout << "UAS: " << p[i].us.uas << " | UTS: " << p[i].us.uts << " | Tugas: " << p[i].us.tugas << endl;
        cout << "Matematika: " << p[i].Nilai.Mtk << " | B. Indonesia: " << p[i].Nilai.BIn
             << " | B. Inggris: " << p[i].Nilai.Big << " | IPA: " << p[i].Nilai.IPA << endl;
        cout << "Nilai Akhir (Umum): " << hitungNilaiAkhir(p[i].us)
             << " | Nilai Akhir (Mapel): " << nilaiAkhir(p[i].Nilai) << endl;
    }
}

// MAIN PROGRAM
int main() {
    int jumlah;
    cout << "Masukkan Jumlah Pelajar : ";
    cin >> jumlah;

    pelajar p[jumlah];

    tampil(jumlah, p);
    tambahDataSiswa(jumlah, p);
    hasil(jumlah, p);

    char cari;
    cout << "\nIngin Mencari Data Siswa ? (y/t): ";
    cin >> cari;
    if (cari == 'y' || cari == 'Y') {
        string nisn;
        cout << "Masukkan NISN Yang Ingin Dicari : ";
        cin >> nisn;
        cariSiswa(nisn);
    }

    char tampillagi;
    cout << "\nIngin Membaca Data Dari File siswa.txt Dan Ditampilkan ? (y/t): ";
    cin >> tampillagi;
    if (tampillagi == 'y' || tampillagi == 'Y') {
        tampilDataSiswa();       
    }

    char tampilrank;
    cout << "\nIngin Menampilkan Data Berdasarkan Peringkat? (y/t): ";
    cin >> tampilrank;
    if (tampilrank == 'y' || tampilrank == 'Y') {
        tampilRangking(jumlah, p);
    }

    return 0;
}
