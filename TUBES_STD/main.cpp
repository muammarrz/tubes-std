#include <iostream>
#include "olshop.h"

using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    listCustomer customers;
    listOrder orders;

    createListCustomer(customers);
    createListOrder(orders);

    bool loop = true;

    while(loop){
        cout << "Main Menu" << endl;

        cout << "1. Menambahkan Pelanggan Baru" << endl;
        cout << "2. Menampilkan Data Pelanggan X" << endl;
        cout << "3. Menghapus Pelanggan Tertentu" << endl;
        cout << "4. Mencari Pelanggan X" << endl;
        cout << "5. Menambahkan Pesanan dari Pelanggan X" << endl;
        cout << "6. Menambahkan Pesanan yang Tersedia" << endl;
        cout << "7. Menghapus Pesanan dari Pelanggan X" << endl;
        cout << "8. Menampilkan Seluruh Pesanan dari Pelanggan X" << endl;
        cout << "9. Mencari Pesanan Y dari Pelanggan X" << endl;
        cout << "10. Membuat Relasi antara Pelanggan X dan Pesanan Y" << endl;
        cout << "11. Menghapus Relasi" << endl;
        cout << "12. Menampilkan Pelanggan dengan Jumlah Pesanan Terbanyak" << endl;
        cout << "13. Mencari Nama Pelanggan dari Pesanan" << endl;
        cout << "14. Exit" << endl;
        cout << endl;

        int pilihan;
        prompt("Silahkan Masukkan Angka");
        cin >> pilihan;

        cin.ignore();

        if(pilihan >=1 && pilihan <= 13){
            system("cls");
        }
        switch(pilihan){
        case 1:
            {
                cout << "Tambah Pelanggan Baru" << endl;

                infocustomer customer;
                customer.id = IdCustomer(customers, "C");

                prompt("Nama Pelanggan");
                getline(cin, customer.nama);
                prompt("Alamat Pelanggan");
                getline(cin, customer.alamat);
                prompt("Jenis Kelamin");
                getline(cin, customer.gender);
                prompt("No. Telp");
                getline(cin, customer.telp);

                adrCustomer pointer = allocateCust(customer);
                insertCustomer(customers, pointer);
                cout << "Data Pelanggan Berhasil Ditambah" << endl;
                break;
            }
        case 2:
            {
                cout << "Data Pelanggan" << endl;

                if(first(customers) == nil){
                    cout << "Data Pelanggan Kosong!" << endl;
                    break;
                }
                else{
                    printListCustomer(customers);
                    break;
                }
            }
        case 3:
            {
                cout << "Hapus Data Pelanggan" << endl;

                if(first(customers) == nil){
                    cout << "Data Pelanggan Kosong!" << endl;
                    break;
                }else{
                    string id;
                    prompt("ID Pelanggan");
                    getline(cin, id);

                    adrCustomer pointer = searchCustomer(customers,id);
                    if(pointer == nil){
                        cout << "ID Tidak Ditemukan" << endl;
                        break;
                    }
                    deleteCustomer(customers, pointer);
                    cout << "Data Pelanggan Berhasil Dihapus" << endl;
                    break;
                }
            }
        case 4:
            {
                cout << "Cari Pelanggan" << endl;

                if(first(customers) == nil){
                    cout << "Data Pelanggan Tidak Ditemukan" << endl;
                    break;
                }
                string id;
                prompt("ID Pelanggan");
                getline(cin, id);

                adrCustomer pointer = searchCustomer(customers, id);
                if(pointer == nil){
                    cout << "ID Tidak Ditemukan" << endl;
                    break;
                }
                printInfoCustomer(pointer);
                cout << endl;

                listOrder list = child(pointer);
                if(first(list) == nil){
                    cout << "Data Pesanan Tidak Ditemukan" << endl;
                    break;
                }else{
                    cout << "Data Pesanan" << endl;
                    printListOrder(list);
                    break;
                }
            }
        case 5:
            {
                cout << "Menambahkan Pesanan" << endl;

                if(first(customers) == nil){
                    cout << "Data Pelanggan Tidak Ditemukan" << endl;
                    break;
                }

                string cid;
                prompt("ID Pelanggan");
                getline(cin, cid);

                adrCustomer pointer = searchCustomer(customers, cid);
                if(pointer == nil){
                    cout << "ID Tidak Ditemukan" << endl;
                    break;
                }
                system("cls");

                bool inner = true;
                infocustomer customer = info(pointer);
                while(inner){
                    cout << "1. Tambah Pesanan" << endl;
                    cout << "2. Tampilkan Pesanan" << endl;
                    cout << "3. Hapus Pesanan" << endl;
                    cout << "4. Cari Pesanan" << endl;
                    cout << "5. Kembali" << endl;
                    cout << endl;

                    int choice;
                    prompt("Pilihan");
                    cin >> choice;

                    cin.ignore();

                    if(choice >= 1 && choice <= 4){
                        system("cls");
                    }
                    switch(choice){
                    case 1:
                        {
                            cout << "Tambah Pesanan" << endl;

                            listOrder *list = &child(pointer);

                            infoorder order;
                            order.id = IdOrder(*list, cid + "O");

                            prompt("Nama Produk");
                            getline(cin, order.product);
                            prompt("Jumlah Pesanan");
                            cin >> order.jumlah;
                            prompt("Harga");
                            cin >> order.harga;

                            adrOrder temp = allocateOrder(order);
                            insertOrder(*list, temp);\
                            cout << "Pesanan Berhasil Ditambah" << endl;
                            break;
                        }
                    case 2:
                        {
                            cout << "Data Pesanan" << endl;

                            listOrder list = child(pointer);

                            if(first(list) == nil){
                                cout << "Data Pesanan Tidak Ditemukan" << endl;
                                break;
                            }
                            printListOrder(list);
                            break;
                        }
                    case 3:
                        {
                            cout << "Hapus Pesanan" << endl;

                            listOrder *list = &child(pointer);

                            if(first(*list) == nil){
                                cout << "Data Pesanan Tidak Ditemukan" << endl;
                                break;
                            }
                            string id;
                            prompt("ID Pesanan");
                            getline(cin, id);

                            adrOrder pointer = searchOrder(*list, id);
                            if(pointer == nil){
                                cout << "ID Tidak Ditemukan" << endl;
                                break;
                            }
                            deleteOrder(*list, pointer);
                            cout << "Pesanan Berhasil Dihapus" << endl;
                            break;
                        }
                    case 4:
                        {
                            cout << "Cari Pesanan" << endl;

                            listOrder list = child(pointer);

                            if(first(list) == nil){
                                cout << "Data Pesanan Tidak Ditemukan" << endl;
                                break;
                            }
                            string id;
                            prompt("ID Pesanan");
                            getline(cin, id);

                            adrOrder pointer = searchOrder(list, id);
                            if(pointer == nil){
                                cout << "ID Tidak Ditemukan" << endl;
                                break;
                            }
                            printInfoOrder(pointer);
                            break;
                        }
                    case 5:
                        {
                            inner = false;
                            break;
                        }
                    default:
                        {
                            cout << "Pilihan Salah" << endl;
                            break;
                        }
                    }
                    if(inner){
                        cout << endl;
                        system("pause");
                        system("cls");
                    }
                }
                break;
            }
        case 6:
            {
                cout << "Menambahkan Pesanan yang Tersedia" << endl;

                infoorder order;
                order.id = IdOrder(orders, "O");

                prompt("Nama Produk");
                getline(cin, order.product);
                prompt("Jumlah Pesanan");
                cin >> order.jumlah;
                prompt("Harga");
                cin >> order.harga;

                adrOrder pointer = allocateOrder(order);
                insertOrder(orders, pointer);
                cout << "Berhasil Menambahkan Pesanan Baru" << endl;
                break;
            }
        case 7:
            {
                cout << "Menghapus Pelanggan" << endl;

                if(first(orders) == nil){
                    cout << "Data Pesanan Tidak Ditemukan" << endl;
                    break;
                }
                string id;
                prompt("ID Pesanan");
                getline(cin, id);

                adrOrder pointer = searchOrder(orders, id);
                if(pointer == nil){
                    cout << "ID Tidak Ditemukan" << endl;
                    break;
                }
                deleteOrder(orders, pointer);
                cout << "Pesanan Berhasil Dihapus" << endl;
                break;
            }
        case 8:
            {
                cout << "Menampilkan Seluruh Pesanan" << endl;

                if(first(orders) == nil){
                    cout << "Data Pesanan Tidak Ditemukan" << endl;
                    break;
                }
                printListOrder(orders);
                break;
            }
        case 9:
            {
                cout << "Mencari Pesanan dari Pelanggan" << endl;
                if(first(orders) == nil){
                    cout << "Data Pesanan Tidak Ditemukan" << endl;
                    break;
                }
                string id;
                prompt("ID Pesanan");
                getline(cin, id);

                adrOrder pointer = searchOrder(orders, id);
                if(pointer == nil){
                    cout << "ID Tidak Ditemukan" << endl;
                    break;
                }
                printInfoOrder(pointer);
                break;
            }
        case 10:
            {
                cout << "Membuat Relasi" << endl;

                if(first(customers) == nil){
                    cout << "Data Pelanggan Tidak Ditemukan" << endl;
                    break;
                }
                if(first(orders) == nil){
                    cout << "Data Pesanan Tidak Ditemukan" << endl;
                    break;
                }
                string cid;
                prompt("ID Pelanggan");
                getline(cin, cid);

                adrCustomer pCust = searchCustomer(customers, cid);
                if(pCust == nil){
                    cout << "ID Tidak Ditemukan" << endl;
                    break;
                }

                string oid;
                prompt("ID Pesanan");
                getline(cin, oid);

                adrOrder pOrd = searchOrder(orders, oid);
                if(pOrd == nil){
                    cout << "ID Tidak Ditemukan" << endl;
                    break;
                }

                listOrder *list = &child(pCust);

                infoorder order = info(pOrd);
                order.id = IdOrder(*list, cid + "O");
                adrOrder temp = allocateOrder(order);
                insertOrder(*list, temp);

                deleteOrder(orders, pOrd);
                cout << "Relasi Berhasil Dibuat" << endl;
                break;
            }
        case 11:
            {
                cout << "Hapus Relasi" << endl;

                if(first(customers) == nil){
                    cout << "Data Pelanggan Tidak Ditemukan" << endl;
                    break;
                }
                string cid;
                prompt("ID Pelanggan");
                getline(cin, cid);

                adrCustomer pCust = searchCustomer(customers, cid);
                if(pCust == nil){
                    cout << "ID Tidak Ditemukan" << endl;
                    break;
                }

                listOrder *list = &child(pCust);
                if(first(*list) == nil){
                    cout << "Data Pesanan Tidak Ditemukan" << endl;
                    break;
                }
                string oid;
                prompt("ID Pesanan");
                getline(cin, oid);

                adrOrder pOrd = searchOrder(*list, oid);
                if(pOrd == nil){
                    cout << "ID Tidak Ditemukan" << endl;
                    break;
                }

                infoorder order = info(pOrd);
                order.id = IdOrder(orders, "O");
                adrOrder temp = allocateOrder(order);
                insertOrder(orders, temp);

                deleteOrder(*list, pOrd);
                cout << "Relasi Berhasil Dihapus" << endl;
                break;
            }
        case 12:
            {
                cout << "Pelanggan dengan Pesanan Terbanyak" << endl;

                if(first(customers) == nil){
                    cout << "Data Pelanggan Tidak Ditemukan" << endl;
                    break;
                }
                adrCustomer pointer = first(customers);
                adrCustomer max = pointer;

                while(pointer != nil){
                    listOrder pointerlist = child(pointer);
                    listOrder maxlist = child(max);

                    int currsize = size(pointerlist);
                    int maxsize = size(maxlist);

                    if(currsize > maxsize){
                        max = pointer;
                    }
                    pointer = next(pointer);
                }
                printInfoCustomer(max);

                cout << endl;

                listOrder list = child(max);
                if(first(list) == nil){
                    cout << "Data Pesanan Tidak Ditemukan" << endl;
                    break;
                }
                cout << "Data Pesanan" << endl;
                printListOrder(list);
                break;
            }
        case 13:
            {
                cout << "Mencari Pelanggan dari Pesanan" << endl;

                if(first(customers) == nil){
                    cout << "Data Pelanggan Tidak Ditemukan" << endl;
                    break;
                }
                string oid;
                prompt("ID Pesanan");
                getline(cin, oid);

                adrCustomer pointer = first(customers);
                while(pointer != nil){
                    listOrder list = child(pointer);

                    adrOrder aPointer = searchOrder(list, oid);
                    if(aPointer != nil){
                        printInfoCustomer(pointer);

                        cout << endl;
                        cout << "Data Pesanan" << endl;
                        printListOrder(list);
                        break;
                    }
                    pointer = next(pointer);
                }
                if(pointer == nil){
                    cout << "Pesanan Tidak Ditemukan" << endl;
                }
                break;
            }
        case 14:
            {
                cout << "Keluar dari Program" << endl;
                loop = false;
                break;
            }
        default:
            {
                cout << "Masukan Salah" << endl;
                break;
            }
    }
    if(loop){
        cout << endl;
        system("pause");
        system("cls");
        }
    }
    return 0;
}
