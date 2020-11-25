/*
    Program untuk encrpyt dan decrypt
    teks atau kalimat menggunakan teknik atau 
    rumus kriptografi
*/ 

#include <iostream>
#include <cstring>

using namespace std;

// prototype
void encrpyt();
void decrypt();
void banner(int &p);

int main(int argc, char const *argv[])
{
    int pil;
    bool stop;
    stop = false;
    
    while (!stop) 
    {
        banner(pil); // daftar menu
        switch(pil)
        {
            case 1 : encrpyt(); break;
            case 2 : decrypt(); break;
            case 3 : stop = true; break;
            default : cout << "Pilihan tidak terdaftar !\n"; break;
        }
    }
    return 0;
}
   
/* fungsi untuk meng-encrpyt
 menggunakan teknik kriptografi */
void encrpyt() {
    string plainteks, cipherteks;
    int i, k;
    char c;
    
    cout << "Masukan kalimat : ";
    cin.ignore(); // menghapus sisa karakter
    getline (cin, plainteks); // input teks / kalimat
    cout << "Masukan jumlah pergeseran 0-255 : "; cin >> k; // input jumlah untuk pergeserean 
    cipherteks = " "; // inisialisasi cipherteks dengan null string
    
    // penyajian data
    for (i=0; i < plainteks.length(); i++) 
    {
        c = plainteks[i];
        if (isalpha(c)) // hanya memproses huruf alfabet saja
        {
            c = toupper(c); // ubah menjadi huruf kapital
            c = c - 65; // kodekan huruf ke angka 0 s/d 25
            c = (c + k) % 26; // enkripisi, geser sejauh k ke kanan
            c = c + 65;
        }
        cipherteks = cipherteks + c; // sambungkan ke cipherteks
    }
    cout << "cipherteks : " << cipherteks << endl << endl; // cetak cipherteks
}


/* fungsi untuk meng-decrypt
 menggunakan teknik kriptografi */
void decrypt() {
    string plainteks, cipherteks;
    int i, k;
    char c;
    
    cout << "Masukan cipherteks : "; // teks yang sudah dienkripsi sebelumnya
    cin.ignore(); getline (cin, cipherteks);
    cout << "Masukan jumlah pergeseran 0-25 : "; cin >> k;
    plainteks = "";  // inisialisasi plainteks dengan null string
    
    for (i=0; i<cipherteks.length(); i++)
    {
        c = cipherteks[i];
        if (isalpha(c)) // hanya memproses alpabet
        {
            c = toupper(c); // ubah karakter ke huruf besar
            c = c - 65; // kodekan huruf ke angka 0 sampai 25
            if (c - k < 0) // kasus pembagian bilangan negatif
                c = 26 + (c - k);
            else
                c = (c - k) % 26;
            c = c + 65; // kodekan kembali ke huruf semula
            c = tolower(c); // plainteks dinyatakan dengan huruf kecil
        }
        plainteks = plainteks + c; // sambungkan ke plainteks
    }
    cout << "plainteks : " << plainteks << endl << endl; // cetak plainteks
}

void banner(int &p) {
    cout << "Menu : " << endl;
    cout << "1. encrpyt " << endl;
    cout << "2. decrypt " << endl;
    cout << "3. Exit " << endl;
    cout << "\nPilih menu : "; cin >> p;
}

