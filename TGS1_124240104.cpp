#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

Mahasiswa mhs[] = {
        {"Budi", "124240001", 3.5},
        {"Andi", "124240002", 3.6},
        {"Caca", "124240003", 3.7},
        {"Dedi", "124240004", 3.8},
        {"Euis", "124240005", 3.9},
        {"Feri", "124240006", 3.4},
        {"Gina", "124240007", 3.3},
        {"Hadi", "124240008", 3.2},
        {"Ika", "124240009", 3.1},
        {"Joko", "124240010", 3}
    };

void tampilkanData(Mahasiswa *mhs, int n) {
    cout << "\nData Mahasiswa" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama: " << mhs[i].nama << " NIM: " << mhs[i].nim << " IPK: " << mhs[i].ipk << endl;
    }
}

int sequential(Mahasiswa *mhs, int n, string nim) {
    for (int i = 0; i < n; i++) {
        if (mhs[i].nim == nim) {
            return i;
        }
    }
    return -1;
}

int binary(Mahasiswa *mhs, int left, int right, string nama) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mhs[mid].nama == nama)
            return mid;
        if (mhs[mid].nama < nama)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void quickSort(Mahasiswa *mhs, int low, int high) {
    if (low < high) {
        float pivot = mhs[high].ipk;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (mhs[j].ipk < pivot) {
                i++;
                swap(mhs[i], mhs[j]);
            }
        }
        swap(mhs[i + 1], mhs[high]);
        int pi = i + 1;
        quickSort(mhs, low, pi - 1);
        quickSort(mhs, pi + 1, high);
    }
}

void bubbleSort(Mahasiswa *mhs, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mhs[j].ipk < mhs[j + 1].ipk) {
                swap(mhs[j], mhs[j + 1]);
            }
        }
    }
}

int main() {
    system("cls");
    int n = sizeof(mhs) / sizeof(mhs[0]);
    int pil;
    string snim, sname;

    do {
        cout << "\nMENU :\n";
        cout << "1. Tampilkan Data Mahasiswa\n";
        cout << "2. Cari Mahasiswa Berdasarkan NIM\n";
        cout << "3. Cari Mahasiswa Berdasarkan Nama\n";
        cout << "4. Sort IPK Mahasiswa (Ascending)\n";
        cout << "5. Sort IPK Mahasiswa (Descending)\n";
        cout << "6. Exit\n";
        cout << "Pilih menu (1-6): ";
        cin >> pil;
        system("cls");
        
        switch (pil) {
            case 1:
                system("cls");
                tampilkanData(mhs, n);
                break;
            case 2: {
                system("cls");
                string snim;
                cout << "Masukkan NIM yang dicari: ";
                cin >> snim;
                int hasil = sequential(mhs, n, snim);
                if (hasil != -1){
                    cout << "Ditemukan: " << endl;
                    cout << mhs[hasil].nama << " dengan IPK " << mhs[hasil].ipk << endl;
                }else{
                    cout << "Mahasiswa tidak ditemukan" << endl;
                }   
                break;
            }
            case 3: {
                system("cls");
                string sname;
                cout << "Masukkan Nama yang dicari: ";
                cin >> sname;
                int hasil = binary(mhs, 0, n - 1, sname);
                if (hasil != -1){
                    cout << "Ditemukan: " << endl;
                    cout << mhs[hasil].nama << " dengan NIM " << mhs[hasil].nim << " dan IPK " << mhs[hasil].ipk << endl;
                }else{
                    cout << "Mahasiswa tidak ditemukan" << endl;
                }
                break;
            }
            case 4:
                system("cls");
                quickSort(mhs, 0, n - 1);
                cout << "Diurutkan berdasarkan IPK (asc) \n";
                tampilkanData(mhs, n);
                break;
            case 5:
                system("cls");
                bubbleSort(mhs, n);
                cout << "Diurutkan berdasarkan IPK (desc)\n";
                tampilkanData(mhs, n);
                break;
            case 6:
                cout << "Exit Program\n";
                exit(0);
                break;
            default:
                cout << "Unvalid choice. Try Again!\n";
        }
    } while (pil != 6);
    
    return 0;
}