#include <iostream>
using namespace std;
struct Node
{
    int nomer_antrian;
    string nama_pasien;
    string keluhan;
    Node *kanan;
    Node *kiri;
};
Node *head = nullptr, *tail = nullptr, *newNode, *temp;
void tambah_data()
{
    newNode = new Node;
    newNode->kanan = nullptr;
    newNode->kiri = nullptr;
    cout << "Masukkan Nomer Antrian: ";
    cin >> newNode->nomer_antrian;
    cin.ignore();
    cout << "Masukkan Nama Pasien: ";
    getline(cin, newNode->nama_pasien);
    cout << "Masukkan Keluhan: ";
    getline(cin, newNode->keluhan);

    if (head == nullptr) // jika linked list kosong
    {
        head = newNode;
        tail = head;
    }
    else if (newNode->nomer_antrian < head->nomer_antrian) // Data akan tersisip di depan
    {
        newNode->kanan = head;
        head->kiri = newNode;
        head = newNode;
    }
    else if (newNode->nomer_antrian > tail->nomer_antrian) // Data akan tersisip di belakang
    {
        newNode->kiri = tail;
        tail->kanan = newNode;
        tail = newNode;
    }
    else // Data akan tersisip di tengah
    {
        Node *bantu = head;
        while (bantu != nullptr && bantu->nomer_antrian < newNode->nomer_antrian)
        {
            bantu = bantu->kanan;
        }
        // Jika nomer antrian sudah ada
        if (bantu != nullptr && bantu->nomer_antrian == newNode->nomer_antrian)
        {
            cout << "Nomer antrian sudah ada! Data tidak dapat disisipkan.\n";
            system("pause");
            delete newNode;
            return;
        }
        newNode->kanan = bantu;
        newNode->kiri = bantu->kiri;
        bantu->kiri != nullptr;
        bantu->kiri->kanan = newNode;
        bantu->kiri = newNode;
    }
    cout << "Pasien berhasil ditambahkan ke daftar\n";
    system("pause");
}
void tampilkan_data_awal()
{
    if (head == nullptr)
    {
        cout << "Data kosong.\n";
        return;
    }
    else
    {
        temp = head;
        cout << "=== Data Antrian Pasien dari Awal ===" << '\n';
        cout << "====================================" << '\n';
        do
        {
            cout << "Nomer Antrian: " << temp->nomer_antrian << '\n';
            cout << "Nama Pasien: " << temp->nama_pasien << '\n';
            cout << "Keluhan: " << temp->keluhan << '\n';
            cout << "-------------------------------------" << '\n';
            temp = temp->kanan;
        } while (temp != nullptr);
    }
    system("pause");
}
void tampilkan_data_akhir()
{
    if (tail == nullptr)
    {
        cout << "Tidak ada data.\n";
        return;
    }
    else
    {
        temp = tail;
        cout << "=== Data Antrian Pasien dari Akhir ===" << '\n';
        cout << "====================================" << '\n';
        do
        {
            cout << "Nomer Antrian: " << temp->nomer_antrian << '\n';
            cout << "Nama Pasien: " << temp->nama_pasien << '\n';
            cout << "Keluhan: " << temp->keluhan << '\n';
            cout << "-------------------------------------" << '\n';
            temp = temp->kiri;
        } while (temp != nullptr);
    }
    system("pause");
}
void cari_data()
{
    bool found = false;
    if (head == nullptr)
    {
        cout << "Data kosong" << '\n';
        return;
    }
    cout << "Masukkan Nomer Antrian yang dicari: ";
    cin >> newNode->nomer_antrian;
    temp = head;
    cout << "Pasian ditemukan" << '\n';
    cout << "=== Data Antrian Pasien yang dicari ===" << '\n';
    cout << "====================================" << '\n';
    while (temp != nullptr)
    {
        if (temp->nomer_antrian == newNode->nomer_antrian)
        {
            cout << "Nomer Antrian: " << temp->nomer_antrian << '\n';
            cout << "Nama Pasien: " << temp->nama_pasien << '\n';
            cout << "Keluhan: " << temp->keluhan << '\n';
            break;
            found = true;
        }
        temp = temp->kanan;
    }
    if (!found)
    {
        cout << "Nomer Antrian tidak ditemukan" << '\n';
    }
    cout << "====================================" << '\n';
    system("pause");
}
void hapus_data()
{
    bool found = false;
    cout << "Masukkan Nomer Antrian yang ingin dihapus: ";
    cin >> newNode->nomer_antrian;
    temp = head;
    while (temp != nullptr)
    {
        if (temp->nomer_antrian == newNode->nomer_antrian)
        {
            found = true;
            if (temp == head && temp == tail)
            {
                delete temp;
                head = tail = nullptr;
            }
            else if (temp == head)
            {
                head = head->kanan;
                head->kiri = nullptr;
                delete temp;
            }
            else if (temp == tail)
            {
                tail = tail->kiri;
                tail->kanan = nullptr;
                delete temp;
            }
            else
            {
                temp->kiri->kanan = temp->kanan;
                temp->kanan->kiri = temp->kiri;
                delete temp;
            }
            cout << "Data berhasil dihapus.\n";
            return;
        }
        temp = temp->kanan;
    }
    if (!found)
    {
        cout << "Nomer Antrian tidak ditemukan.\n";
    }
}
void menu()
{
    int pilihan;
    do
    {
        cout << "=== MENU ANTRIAN PASIEN KLINIK SEHAT SELALU ===" << '\n';
        cout << "1. Tambah Data Pasien" << '\n';
        cout << "2. Tampilkan Antrian dari Awal" << '\n';
        cout << "3. Tampilkan Antrian dari Akhir" << '\n';
        cout << "4. Cari Data Pasien" << '\n';
        cout << "5. Hapus Data Pasien" << '\n';
        cout << "6. Keluar" << '\n';
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tambah_data();
            break;
        case 2:
            tampilkan_data_awal();
            break;
        case 3:
            tampilkan_data_akhir();
            break;
        case 4:
            cari_data();
            break;
        case 5:
            hapus_data();
            break;
        };
    } while (pilihan != 6);
};
int main()
{
    menu();
}
