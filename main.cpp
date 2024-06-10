#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#import <cstdio>

using namespace std;
struct pesawat { //struct pesawat3
    int jmlh_penumpang, asal, tujuan, kls_pen, kls_penumpang, pil_penerbangan, rin_harga, total_harga, bayar, bank, elek, konf, biaya_kelas, biaya_maskapai, biaya_perjalanan, biaya_perorang, biaya_total, jmlh_anak, biaya_anak;
    string nama, tgl, nama_depan, nama_belakang, no_telp, email, kota, kota_asal, kota_tujuan, kode_pesawat, seat, waktu_penerbangan, maskapai_penerbangan, kelas_penerbangan;
    int edell[5] = {1, 5, 4, 2, 3}; //array

    pesawat *next;
};

struct User //struct user
{
    string usern, pass;
    User *Log; //tanda bintang adalah untuk memasukkan data dari variabel Log ke struct user
    User *Lnjt;
};

pesawat pst;
pesawat *tiket, *hapus, *newtiket, *tail; //tree
pesawat *pmbyrn;

User usr;
User *Log, *Yuhu;

void kota(int a) //membuat fungsi untuk menampilkan nama kota
{
    switch(a) //percabangan
        {
            case 1 :
                pst.kota = "Medan";
                break;
            case 2:
                pst.kota = "Lombok";
                break;
            case 3 :
                pst.kota = "Riau";
                break;
            case 4 :
                pst.kota = "Palu";
                break;
        }
}

void infoperjalanan(string kota_asal, string kota_tujuan) //fungsi untuk menampilkan info perjalanan pada menu pemesanan tiket
{
    if (kota_asal == "Medan") //percabangan
        {
            if (kota_tujuan == "Lombok")
                {
                    pst.biaya_perjalanan = 1000000;
                }
            else if (kota_tujuan == "Riau")
                {
                    pst.biaya_perjalanan = 900000;
                }
            else if (kota_tujuan == "Palu")
                {
                    pst.biaya_perjalanan = 1500000;
                }
        }
    else if (kota_asal == "Lombok")
        {
            if (kota_tujuan == "Medan")
                {
                    pst.biaya_perjalanan = 1000000;
                }
            else if (kota_tujuan == "Riau")
                {
                    pst.biaya_perjalanan = 900000;
                    }
            else if (kota_tujuan == "Palu")
                {
                    pst.biaya_perjalanan = 1500000;
                }
        }
    else if (kota_asal == "Riau")
        {
            if (kota_tujuan == "Medan")
                {
                    pst.biaya_perjalanan = 900000;
                }
            else if (kota_tujuan == "Riau")
                {
                    pst.biaya_perjalanan = 900000;
                }
            else if (kota_tujuan == "Lombok")
                {
                    pst.biaya_perjalanan = 700000;
                }
        }
    else if (kota_asal == "Palu")
        {
        if (kota_tujuan == "Medan")
            {
                pst.biaya_perjalanan = 1500000;
            }
        else if (kota_tujuan == "Lombok")
            {
                pst.biaya_perjalanan = 1200000;
            }
        else if (kota_tujuan == "Riau")
            {
                pst.biaya_perjalanan = 1000000;
            }
        }
}

void kelas(int v) //fungsi untuk menampilkan kelas penerbangan yang diambil //fungsi
{
    switch(v)
        {
            case 1 :
                pst.kelas_penerbangan = "Economy";
                pst.biaya_kelas = 1000000;
                pst.seat = "402";
                break;
            case 2 :
                pst.kelas_penerbangan = "Premium";
                pst.biaya_kelas = 1500000;
                pst.seat = "312";
                break;
            case 3 :
                pst.kelas_penerbangan = "Business";
                pst.biaya_kelas = 2000000;
                pst.seat = "151";
                break;
            case 4 :
                pst.kelas_penerbangan = "First class";
                pst.biaya_kelas = 2500000;
                pst.seat = "088";
                break;
        }
}

void maskapai (int n) //fungsi untuk menampilkan maskapai penerbangan
{
switch(n)
    {
        case 1 :
            pst.maskapai_penerbangan = "Lion Air";
            pst.biaya_maskapai = 2000000;
            pst.kode_pesawat = "LA" + pst.no_telp;
            pst.waktu_penerbangan = "02:40";
            break;
        case 2 :
            pst.maskapai_penerbangan = "Batik Air";
            pst.biaya_maskapai = 2600000;
            pst.kode_pesawat = "BA" + pst.no_telp;
            pst.waktu_penerbangan = "03:00";
            break;
        case 3 :
            pst.maskapai_penerbangan = "Citilink";
            pst.biaya_maskapai = 2100000;
            pst.kode_pesawat = "CT" + pst.no_telp;
            pst.waktu_penerbangan = "04:30";
            break;
    }
}
void Pemesanan(int i) //fungsi untuk menampilknan pemesanan tiket
{
        //string r;
    cout<<"INPUT DATA PELANGGAN\n";
    cout<<endl;
    cout<<"Nama Depan            : ";cin>>pst.nama_depan;
    cout<<"Nama Belakang         : ";cin>>pst.nama_belakang;
    cout<<"Nomor Telpon          : ";cin>>pst.no_telp;
    cout<<"Email                 : ";cin>>pst.email;
    cout<<endl;
}
void rin_harga (int k) //fungsi untuk menampilkan rincian harga setelah pemesanan tiket
{
        //string r;
    cout<<"Rincian Pembelian  : Mohon di cek, apakah pemesanan sudah benar?"<<endl;
    cout<<endl;
    cout<<"Maskapai Penerbangan  : " <<pst.maskapai_penerbangan<<endl;
    cout<<"Waktu Penerbangan     : " <<pst.waktu_penerbangan<<endl;
    cout<<"Kelas Penerbangan     : " <<pst.kelas_penerbangan<<endl;
    cout<<"Asal Penerbangan      : " <<pst.kota_asal<<endl;
    cout<<"Tujuan Penerbangan    : " <<pst.kota_tujuan<<endl;
    cout<<endl;
    pst.biaya_perorang = (pst.biaya_perjalanan + pst.biaya_maskapai + pst.biaya_kelas); //penjumlahan sesuai pemesanan tiket
    pst.biaya_anak = pst.biaya_perorang - 600000; // untuk menghitung biaya tiker anak
    pst.biaya_total = pst.biaya_perorang + pst.biaya_anak; //total biaya
    cout<< "Biaya Total" << k << "penumpang : " <<pst.biaya_total<<endl;
}
int pembayaran (int r) //fungsi untuk menampilkan metode pembayaran
{
        //string r;
    pmbyrn = new pesawat ();
    int bayar, lanjut;
    cout<<"          MetodePembayaran          " <<endl;
    cout<<"=====================================" <<endl;
    cout<<"1. Pembayaran Elektrik               " <<endl;
    cout<<"2. Pembayaran Bank                   " <<endl;
    cout<<"=====================================" <<endl;
    cout<<"Pilihan Anda : "; cin>>bayar;
    if (bayar==1){
            cout<<"==============================================================================="<<endl;
            cout<<"                          Cara Pembayaran GOPAY/OVO/DANA                       "<<endl;
            cout<<"==============================================================================="<<endl;
            cout<<"1. Masukan kode pembayaran ke menu transaksi pada masing-masing aplikasi"<<endl;
            cout<<"   Dengan total yang sudah tertera"<<endl;
            cout<<endl;
            cout<<"2. Setelah pembayaran sukses, dimohon untuk konfirmasi pembayaran"<<endl;
            cout<<endl;
            cout<<"Kode Pembayaran  : TKI"<<pst.no_telp<<endl;
            cout<<endl;
    }
    else
    if (bayar==2){
            cout<<"==============================================================================="<<endl;
            cout<<"                          CARA PEMBAYARAN BANK TRANSFER                        "<<endl;
            cout<<"==============================================================================="<<endl;
            cout<<endl;
            cout<<"1. BCA            : CZAB + 08xxxxxxxxxx (no tlp) padatransaksi virtual account"<<endl;
            cout<<endl;
            cout<<"2. BRI            : HXYS + 08xxxxxxxxxx (no tlp) padatransaksi virtual account"<<endl;
            cout<<endl;
            cout<<"3. Mandiri        : GJKL + 08xxxxxxxxxx (no tlp) padatransaksi virtual account"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"Setelah pembayara nsukses, dimohon untuk konfirmasi pembayaran"<<endl;
            cout<<endl;
    }
    return 0;
}

//fungsi untuk menampilkan data pemesan tiket
void push (string nama_depan, string nama_belakang, string email, string no_telp, string k_asal, string k_tujuan, int jpnp, int jank, string tggl, string kls_pen, string mas_pen, int biaya_perorang, int biaya_anak, int biaya_total, string waktu_penerbangan, string kode_pesawat, string seat)
{
    if (tiket == NULL)
        {
            tiket = new pesawat ();
            tiket->nama_depan = nama_depan;
            tiket->nama_belakang = nama_belakang;
            tiket->email = email;
            tiket->no_telp = no_telp;
            tiket->kota_asal = k_asal;
            tiket->kota_tujuan = k_tujuan;
            tiket->jmlh_penumpang = jpnp;
            tiket->jmlh_anak = jank;
            tiket->tgl = tggl;
            tiket->kelas_penerbangan = kls_pen;
            tiket->maskapai_penerbangan = mas_pen;
            tiket->biaya_perorang = biaya_perorang;
            tiket->biaya_anak = biaya_anak;
            tiket->biaya_total = biaya_total;
            tiket->waktu_penerbangan = waktu_penerbangan;
            tiket->kode_pesawat = kode_pesawat;
            tiket->seat = seat;
            tiket->next = NULL;
            tail = tiket;
        }
    else
        {
            newtiket = new pesawat ();
            newtiket->nama_depan = nama_depan; // linked list
            newtiket->nama_belakang = nama_belakang;
            newtiket->email = email;
            newtiket->no_telp = no_telp;
            newtiket->kota_asal = k_asal;
            newtiket->kota_tujuan = k_tujuan;
            newtiket->jmlh_penumpang = jpnp;
            newtiket->tgl = tggl;
            newtiket->kelas_penerbangan = kls_pen;
            newtiket->maskapai_penerbangan = mas_pen;
            newtiket->biaya_perorang = biaya_perorang;
            newtiket->biaya_anak = biaya_anak;
            newtiket->biaya_total = biaya_total;
            newtiket->waktu_penerbangan = waktu_penerbangan;
            newtiket->kode_pesawat = kode_pesawat;
            newtiket->seat = seat;
            newtiket->next = tiket;
            tiket = newtiket;

        }
}

void pop () //fungsi untuk membatalkan pemesanan
{
    hapus = tiket;
    tiket = tiket->next;
    delete hapus;
}

void rin_pemesanan(int q) //rincian pemesanan
{
    cout<<"==============================================================================================================="<<endl;
    cout<<": Nama : No Telpon : Kota Asal : Kota Tujuan : Jumlah Penumpang : Tanggal Keberangkatan : kelas Penerbangan   :"<<endl;
    cout<<"==============================================================================================================="<<endl;
    cout<<setw(0)<<tiket->nama_depan<<"  " <<tiket->nama_belakang<<setw(15) <<tiket->no_telp<<setw(11) <<tiket->kota_asal<<setw(15)<<tiket->kota_tujuan<<setw(15) <<tiket->jmlh_penumpang<<setw(15) <<tiket->tgl<<setw(10) <<tiket->kelas_penerbangan<<setw(10);
    cout<<endl;
    cout<<"============================================================================================================"<<endl;
    cout<<": Maskapai Penerbangan : Waktu Penerbangan : Kode Pesawat : Seat : Biaya Dewasa : Biaya Anak : Biaya Total :"<<endl;
    cout<<"============================================================================================================"<<endl;
    cout<<setw(19)<<tiket->maskapai_penerbangan<<setw(25) <<tiket->waktu_penerbangan<<setw(20) <<tiket->kode_pesawat<<setw(14) <<tiket->seat <<setw(14)<<tiket->biaya_perorang<<setw(15) <<tiket->biaya_anak<<setw(10) <<tiket->biaya_total<<setw(20);
    cout<<endl;
    cout<<"============================================================================================================"<<endl;
    cout<<endl;
}

void utama(); //fungsi utama();
const string currentDateTime(); //fungsi waktu
void domestik () //fungsi untuk memesan tiket
{
    system("cls"); //menghapus layar
    int lanjut, inputmenu2;
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "¯¯¯                     SISTEM PEMESANAN TIKET PESAWAT                      ¯¯¯\n";
        cout << "¯¯¯                      -- MENU USER/PESAN TIKET --                        ¯¯¯\n";
        cout << "¯¯¯                          SEKARANG PUKUL " << currentDateTime() <<"                           ¯¯¯\n";
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << endl;
    cout<<"==============Asal Kota==============" <<endl;
    cout<<"1. Medan (MDN)" <<endl;
    cout<<"2. Lombok (LB)" <<endl;
    cout<<"3. Riau (RA)" <<endl;
    cout<<"4. Palu (PL)" <<endl;
    cout<<"Pilih  : "; cin>>pst.asal;
    kota(pst.asal);
    pst.kota_asal = pst.kota; //struct
    cout<<endl;
    cout<<"==============Kota Tujuan==============" <<endl;
    cout<<"1. Medan (MDN)" <<endl;
    cout<<"2. Lombok (LB)" <<endl;
    cout<<"3. Riau (RA)" <<endl;
    cout<<"4. Palu (PL)" <<endl;
    cout<<"Pilih  : "; cin>>pst.tujuan;
    kota(pst.tujuan);
    pst.kota_tujuan = pst.kota;
    infoperjalanan(pst.kota_asal, pst.kota_tujuan);
    cout<<endl;
    cout<<"Tanggal Keberangkatan (DDMMYYY) : "; cin>>pst.tgl;
    cout<<endl;
    cout<<"==============Jumlah Penumpang==============" <<endl;
    cout<<"Penumpang Dewasa  : "; cin>>pst.jmlh_penumpang;
    cout<<"Penumpang Anak  : "; cin>>pst.jmlh_anak;
    cout<<endl;
    cout<<"==============Kelas Penerbangan==============" <<endl;
    cout<<"1. Economy" <<endl;
    cout<<"2. Premium" <<endl;
    cout<<"3. Business" <<endl;
    cout<<"4. First Class" <<endl;
    cout<<"Pilih  : "; cin>>pst.kls_pen;
    kelas(pst.kls_pen);
    cout<<endl;
    cout<<"========================Maskapai Penerbangan=======================" <<endl;
    cout<<endl;
    cout<<"1. Lion Air             02:40 -> 04:10      RP.1.200.000" <<endl;
    cout<<"2. Batik Air            03:00 -> 04:30      RP.1.260.000" <<endl;
    cout<<"3. Citilink             04:30 -> 06:00      RP.1.210.000" <<endl;
    cout<<"Pilih  : "; cin>>pst.pil_penerbangan;
    maskapai(pst.pil_penerbangan);
    cout<<endl;
    Pemesanan(lanjut);
    cout<<"==============Rincian Harga==============" <<endl;
    rin_harga(pst.jmlh_penumpang);
    cout<<endl;
    cout<<"Lanjut ke Pembayaran ?" <<endl;
    cout<<"1. YA" <<endl;
    cout<<"2. TIDAK" <<endl;
    cout<<"Pilih  : "; cin>>lanjut;
    cout<<endl;
    switch (lanjut) { //percabangan
        case 1:
                {
                    pembayaran(lanjut);
                    break;
                }
        case 2:
                {
                    domestik();
                }
    }
    cout<<"======================Konfirmasi Pembayaran=======================" <<endl;
    cout<<"1. Sudah Bayar      " <<endl;
    cout<<"2. Batal            " <<endl;
    cout<<"==================================================================" <<endl;
    cout<<"PilihAnda  : "; cin>> inputmenu2;
    cout<<endl;
    switch (inputmenu2) {
    case 1:
            {
                push(pst.nama_depan, pst.nama_belakang, pst.email, pst.no_telp, pst.kota_asal, pst.kota_tujuan, pst.jmlh_penumpang, pst.jmlh_anak, pst.tgl, pst.kelas_penerbangan, pst.maskapai_penerbangan, pst.biaya_anak, pst.biaya_perorang, pst.biaya_total, pst.waktu_penerbangan, pst.kode_pesawat, pst.seat);
                rin_pemesanan(inputmenu2);
                return utama(); // memanggil fungsi utama
            }
    case 2:
            {
                pop(); //fungsi membatalkan pesanan
                cout<< "Pesanan Anda Sudah Dibatalkan" <<endl;
                exit(0); //keluar
                break;
            }
        }
    }

void useraja(); //fungsi user
const string currentDateTime(); //fungsi waktu
void hargatiket() //fungsi untuk menampilkan harga tiket
{
    system("cls");
    string maskapai[3] = {"Lion Air","Batik Air","Citilink"};
    int biaya_maskapai[3] = {1200000,1260000,1210000}; //harga maskapai didalamnya ada array yang berisi 3 data
    int inputmenu;
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "¯¯¯                     SISTEM PEMESANAN TIKET PESAWAT                      ¯¯¯\n";
        cout << "¯¯¯                      -- MENU USER/HARGA TIKET --                        ¯¯¯\n";
        cout << "¯¯¯                          SEKARANG PUKUL " << currentDateTime() <<"                           ¯¯¯\n";
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << endl;
    for (int i=0; i<=2; i++){ //perulangan untuk menampilkan maskapai //perulangan
        cout << i+1 << ". " << maskapai[i] << endl;
    }
    cout <<"Masukkan Maskapai Penerbangan : ";
    cin >> inputmenu;
    switch (inputmenu)
    {
    case 1:
        {
            cout << "Nama Maskapai  : " << maskapai[inputmenu-1] << endl;
            cout << "Biaya Maskapai : " << biaya_maskapai[inputmenu-1] << endl;
            cout << "Economy        : 1000000" << endl;
            cout << "Premium        : 1500000" << endl;
            cout << "Bussines       : 2000000" << endl;
            cout << "First Class    : 2500000" << endl;
            break;
        }
    case 2:
        {
            cout << "Nama Maskapai  : " << maskapai[inputmenu-1] << endl;
            cout << "Biaya Maskapai : " << biaya_maskapai[inputmenu] << endl;
            cout << "Economy        : 1000000" << endl;
            cout << "Premium        : 1500000" << endl;
            cout << "Bussines       : 2000000" << endl;
            cout << "First Class    : 2500000" << endl;
            break;
        }
    case 3:
        {
            cout << "Nama Maskapai  : " << maskapai[inputmenu-1] << endl;
            cout << "Biaya Maskapai : " << biaya_maskapai[inputmenu] << endl;
            cout << "Economy        : 1000000" << endl;
            cout << "Premium        : 1500000" << endl;
            cout << "Bussines       : 2000000" << endl;
            cout << "First Class    : 2500000" << endl;
            break;
        }
    }
    return useraja(); //memanggil fungsi useraja();
}
void utama();
void hargatiketadm();
const string currentDateTime();
void menupilih()
{
        system("cls");
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "¯¯¯                     SISTEM PEMESANAN TIKET PESAWAT                      ¯¯¯\n";
        cout << "¯¯¯                            -- MENU USER --                              ¯¯¯\n";
        cout << "¯¯¯                          SEKARANG PUKUL " << currentDateTime() <<"                           ¯¯¯\n";
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        useraja(); //memanggil fungsi useraja
}
void useraja() //fungsi useraja
{
        int inputmenu;
        cout << endl;
        cout << "1. Beli Tiket" << endl;
        cout << "2. Lihat Harga Tiket" << endl;
        cout << "3. Keluar" << endl;
        cout << "----------------------" << endl;
        cout << "Pilihan Anda :";
        cin >> inputmenu;
        switch (inputmenu)
        {
        case 1 :
            {
                domestik();
                break;
            }
        case 2 :
            {
                hargatiket();
                break;
            }
        case 3 :
            {
                exit;
                break;
            }
        default :
            {
                cout <<"Pilihan Tidak Tersedia"<<endl;
                return menupilih();
            }
        }
    while (inputmenu > 3);
    return utama();
}

void merge(int low, int mid, int high){ //sorting
int a, b, c, edel[50], d;
a = low;
b = low;
c = mid+1;
while ((a <= mid)&&(c <=high)){
    if((pst.edell)[a]<=pst.edell[c]){
        edel[b]=pst.edell[a]; a++;}
    else {
        edel[b] = pst.edell[c]; c++;
    } b++;}
if ( a>mid) {
        for (d=c; d<=high; d++){
            edel[b] = pst.edell[d]; b++; }
}

else {
     for (d=a; d<=mid; d++){
            edel[b] = pst.edell[d]; b++;
     }
}
for (d=low; d<high; d++)
    pst.edell[d] = edel[d];
}

void marge_sort(int low, int high) {
    int mid;
    if(low<high) {
        mid = (low<high/2);
        marge_sort(low, high);
        marge_sort(mid+1, high);
        marge_sort(low, high);
    cout << endl;
    }
}
void Admin();
const std::string currentDateTime();
void lihatDataUser() //fungsi untuk menampilkan data user yang sudah memesan tiket
{
        system("cls");
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "¯¯¯                     SISTEM PEMESANAN TIKET PESAWAT                      ¯¯¯\n";
        cout << "¯¯¯                   -- LOGIN ADMIN/DATA PENGGUNA TIKET --                 ¯¯¯\n";
        cout << "¯¯¯                          SEKARANG PUKUL " << currentDateTime() <<"                           ¯¯¯\n";
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << endl;

    if (tiket == NULL)
    {
        cout << "Maaf, Belum Ada Pemesanan Tiket." << endl;
        getchar();
        return Admin();
    }

    pesawat *current = tiket; //deklarasi variabel current ke dalam linkedlist pesawat

    while (current != NULL)
    {
        cout << "Nama                  : " << current->nama_depan << " " << current->nama_belakang << endl;
        cout << "Nomor Telepon         : " << current->no_telp << endl;
        cout << "Email                 : " << current->email << endl;
        cout << "Kota Asal             : " << current->kota_asal << endl;
        cout << "Kota Tujuan           : " << current->kota_tujuan << endl;
        cout << "Tanggal Keberangkatan : " << current->tgl << endl;
        cout << "Kelas Penerbangan     : " << current->kelas_penerbangan << endl;
        cout << "Maskapai Penerbangan  : " << current->maskapai_penerbangan << endl;
        cout << "Biaya Total           : " << current->biaya_total << endl;
        cout <<endl;

        current = current->next;
    }
    getchar(); // Menunggu pengguna menekan tombol "Enter"
    return Admin();   // Kembali ke fungsi Admin()
}
void Admin();
void hargatiketadm() //fungsi ad,im
{
    system("cls");
    string maskapaiadm[3] = {"Lion Air","Batik Air","Citilink"};
    int biaya_maskapaiadm[3] = {1200000,1260000,1210000};
    int inputmenuadm;
    cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
    cout << "¯¯¯                     SISTEM PEMESANAN TIKET PESAWAT                      ¯¯¯\n";
    cout << "¯¯¯                      -- LOGIN ADMIN/DATA TIKET --                       ¯¯¯\n";
    cout << "¯¯¯                          SEKARANG PUKUL " << currentDateTime() <<"                           ¯¯¯\n";
    cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
    cout << endl;
    for (int i = 0; i < 3; i++){
        cout << i+1 << ". " << maskapaiadm[i] << endl;
    }
    cout <<"Pilih Maskapai Penerbangan : ";
    cin >> inputmenuadm;
    switch (inputmenuadm)
    {
    case 1:
        {
            cout << "Nama Maskapai : " << maskapaiadm[inputmenuadm-1] << endl; //menampilkan nama maskapai
            cout << "Biaya Maskapai : " << biaya_maskapaiadm[inputmenuadm-1] << endl; //menampilkan biaya maskapai
            cout << "Economy     : 1000000" << endl;
            cout << "Premium     : 1500000" << endl;
            cout << "Business    : 2000000" << endl;
            cout << "First Class : 2500000" << endl;
            break;
        }
    case 2:
        {
            cout << "Nama Maskapai : " << maskapaiadm[inputmenuadm-1] << endl;
            cout << "Biaya Maskapai : " << biaya_maskapaiadm[inputmenuadm-1] << endl;
            cout << "Economy     : 1000000" << endl;
            cout << "Premium     : 1500000" << endl;
            cout << "Business    : 2000000" << endl;
            cout << "First Class : 2500000" << endl;
            break;
        }
    case 3:
        {
            cout << "Nama Maskapai : " << maskapaiadm[inputmenuadm-1] << endl;
            cout << "Biaya Maskapai : " << biaya_maskapaiadm[inputmenuadm-1] << endl;
            cout << "Economy     : 1000000" << endl;
            cout << "Premium     : 1500000" << endl;
            cout << "Business    : 2000000" << endl;
            cout << "First Class : 2500000" << endl;
            break;
        }
    }
    return Admin(); //kembali ke fungsi admin
}

void Admin() //fungsi admin
{
        int adminpilih;
        cout<<endl;
        cout <<"Pilih Menu Dibawah Ini :"<<endl;
        cout <<"1. Lihat Data Penerbangan"<<endl;
        cout <<"2. Lihat Data Tiket"<<endl;
        cout <<"3. Keluar"<<endl;
        cout <<endl;
        cout <<"Pilih Menu : ";
        cin  >> adminpilih;

        switch (adminpilih)
        {
        case 1 :
            {
                cout<<endl;
                lihatDataUser(); //untuk memanggil fungsi LihatDataUser();
                break;
            }
        case 2 :
            {
                hargatiketadm();
                break;
            }
        case 3 :
            {
                exit;
                break;
            }

        default :
            {
                cout<<"Pilihan Tidak Tersedia.";
                return Admin();
            }

        }
}

const string currentDateTime();
void loginAdmin() //fungsi login admin
{
    system("cls");
    string username, password;
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "¯¯¯                     SISTEM PEMESANAN TIKET PESAWAT                      ¯¯¯\n";
        cout << "¯¯¯                           -- LOGIN ADMIN --                             ¯¯¯\n";
        cout << "¯¯¯                          SEKARANG PUKUL " << currentDateTime() <<"                           ¯¯¯\n";
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << endl;

    // Meminta input username dan password dari admin
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    // Memeriksa kecocokan username dan password
    if (username == "admin" && password == "admin123")
    {
        cout << "Login berhasil. Selamat datang, Admin!" << endl;
        Admin();

    }
    else
    {
        system("cls");
    }
}

void registerUser() //fungsi untuk register user
{
        system("cls");
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "¯¯¯                     SISTEM PEMESANAN TIKET PESAWAT                      ¯¯¯\n";
        cout << "¯¯¯                         -- REGISTRASI USER --                           ¯¯¯\n";
        cout << "¯¯¯                          SEKARANG PUKUL " << currentDateTime() <<"                           ¯¯¯\n";
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << endl;

    User *newUser = new User();

    // Meminta input data pengguna yang akan diregistrasi
    cout << "Username: ";
    cin >> newUser->usern;
    cout << "Password: ";
    cin >> newUser->pass;

    // Menghubungkan pengguna baru ke linked list user
    newUser->Log = NULL;
    if (Log == NULL)
    {
        Log = newUser;
        Yuhu = newUser;
    }
    else
    {
        Yuhu->Lnjt = newUser;
        Yuhu = newUser;
    }

    cout << "Registrasi berhasil. Selamat datang, " << newUser->usern << "!" << endl;
    utama();
}

void menuUser() //fungsi untuk menampilkan menu user
{
            menupilih();
            cout<<endl;
            marge_sort(0, 5);
            for (int b=1; b<5; b++)
            cout << pst.edell[b] << " ";
            cout<<"Terimakasih Atas Pesanan Anda"<<endl;
            cout<<endl;
            cin.get();
}
void loginUser() //fungsi logim user
{
    system("cls");
    string username, password;
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "¯¯¯                     SISTEM PEMESANAN TIKET PESAWAT                      ¯¯¯\n";
        cout << "¯¯¯                            -- LOGIN USER --                             ¯¯¯\n";
        cout << "¯¯¯                          SEKARANG PUKUL " << currentDateTime() <<"                           ¯¯¯\n";
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << endl;

    // Meminta input username dan password dari pengguna
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    User *current = Log;
    bool loginSuccess = false;

    // Memeriksa kecocokan username dan password
    while (current != NULL)
    {
        if (username == current->usern && password == current->pass)
        {
            cout << "Login berhasil. Selamat datang, " << current->usern<< "!" << endl;
            loginSuccess = true;
            break;
        }
        current = current->Lnjt;
    }

    if (!loginSuccess)
    {
        cout << "Username atau password salah. Login gagal!" << endl;
        return;
    }

    // Panggil fungsi menu pilihan setelah berhasil login
    menuUser();
}

//get time now
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    //strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	strftime(buf, sizeof(buf), "%H:%M", &tstruct);

    return buf;
}

const std::string currentTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    //strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	strftime(buf, sizeof(buf), "%H%M", &tstruct);

    return buf;
}

void utama() //fungsi utama
{
    int pilihmenu1;
    while (pilihmenu1 != 4)
    {

        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "¯¯¯                     SISTEM PEMESANAN TIKET PESAWAT                      ¯¯¯\n";
        cout << "¯¯¯                                                                         ¯¯¯\n";
        cout << "¯¯¯                          SEKARANG PUKUL " << currentDateTime() <<"                           ¯¯¯\n";
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << endl;
        cout << "1. Login Admin" << endl;
        cout << "2. Login User" << endl;
        cout << "3. Register User" << endl;
        cout << "4. Keluar" << endl;
        cout << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilihmenu1;

        switch (pilihmenu1)
        {
        case 1:
            {
                loginAdmin();
                break;
            }
        case 2:
            {
                loginUser();
                break;
            }
        case 3:
            {
                registerUser();
                break;
            }
        case 4:
            {
                cout << "Terimakasih Telah Menggunakan Program Ini." << endl;
                exit(0);
                break;
            }
        default :
            {
                cout <<"Pilihan Tidak Tersedia. Coba Lagi"<<endl;
                return utama();
            }
        }
        cout << endl;
    }
}

int main() //fungsi utama
{
    utama(); //memanggil fungsi utama
    return 0;
}
