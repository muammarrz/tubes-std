#include "olshop.h"

//implementasi order

void createListOrder(listOrder &L){
    first(L) = nil;
}

adrOrder allocateOrder(infoorder O){
    adrOrder P = new elmOrder;
    info(P) = O;
    next(P) = nil;
    return P;
}

void insertOrder(listOrder &L, adrOrder P){
    if(first(L) == nil){
        first(L) = P;
    }else{
        adrOrder Q = first(L);
        while(next(Q) != nil){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteOrder(listOrder &L, adrOrder &P){
    if(first(L) == nil){
        cout << "Data Tidak Ditemukan";
    }
    if (first(L) == P){
        first(L) = next(P);
        next(P) = nil;
    }else{
        adrOrder Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        next(Q) = next(P);
        next(P) = nil;
    }
}

void printInfoOrder(adrOrder P){
    if(P == nil){
        cout << "Data Tidak Ditemukan";
    }
    display("ID", info(P).id);
    display("Produk", info(P).product);
    display("Jumlah", to_string(info(P).jumlah));
    cout << setw(20) << left << "Harga";
    cout << ": Rp.";
    cout << setprecision(2) << fixed << info(P).harga << endl;
}

void printListOrder(listOrder L){
    if(first(L) == nil){
        cout << "Data Tidak Ditemukan";
    }else{
        adrOrder P = first(L);
        while(P != nil){
            printInfoOrder(P);
            P = next(P);
            if(P != nil){
                cout << endl;
            }
        }
    }
}

adrOrder searchOrder(listOrder L, string id){
    if(first(L) == nil){
        cout << "Data Tidak Ditemukan";
    }else{
        adrOrder P = first(L);
        while(P != nil && info(P).id != id){
            P = next(P);
        }
        return P;
    }
}
string IdOrder(listOrder L, string prefix){
    if(first(L) == nil){
        return prefix + "01";
    }else{
        adrOrder P = first(L);
        while(next(P) != nil){
            P = next(P);
        }
        string last = info(P).id;
        int num = stoi(last.substr(last.length() - 2, 2));
        num++;

        string id = to_string(num);
        while (id.length() < 2)
            id = "0" + id;
        return prefix + id;
    }
}

//implementasi Customer
void createListCustomer(listCustomer &L){
    first(L) = nil;
}

adrCustomer allocateCust(infocustomer x){
    adrCustomer P = new elmCustomer;
    info(P) = x;
    next(P) = nil;

    createListOrder(child(P));

    return P;
}
void insertCustomer(listCustomer &L, adrCustomer P){
    if(first(L) == nil){
        first(L) = P;
    }else{
        adrCustomer Q = first(L);
        while(next(Q) != nil){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void deleteCustomer(listCustomer &L, adrCustomer &P){
    if(first(L) == nil){
        cout << "Data Tidak Ditemukan";
    }
    if(first(L) == P){
        first(L) = next(P);
        next(P) = nil;
    }else{
        adrCustomer Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        next(Q) = next(P);
        next(P) = nil;
    }
}
void printInfoCustomer(adrCustomer P){
    if(P == nil){
        cout << "Data Tidak Ditemukan";
    }else{
        display("ID", info(P).id);
        display("Nama", info(P).nama);
        display("Alamat", info(P).alamat);
        display("Jenis Kelamin", info(P).gender);
        display("No. Telp", info(P).telp);
    }
}
void printListCustomer(listCustomer L){
    if(first(L) == nil){
        cout << "Data Tidak Ditemukan";
    }else{
        adrCustomer P = first(L);
        while(P != nil){
            printInfoCustomer(P);
            P = next(P);
            if(P != nil){
                cout << endl;
            }
        }
    }
}

adrCustomer searchCustomer(listCustomer L, string id){
    if(first(L) == nil){
        cout << "Data Tidak Ditemukan";
    }else{
        adrCustomer P = first(L);
        while(P != nil && info(P).id != id){
            P = next(P);
        }
        return P;
    }
}
string IdCustomer(listCustomer L, string prefix){
    if(first(L) == nil){
        return prefix + "01";
    }else{
        adrCustomer P = first(L);
        while(next(P) != nil){
            P = next(P);
        }
        string last = info(P).id;
        int num = stoi(last.substr(last.length() - 2, 2));
        num++;


        string id = to_string(num);
        while (id.length() < 2)
            id = "0" + id;
        return prefix + id;
    }

}
