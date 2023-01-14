#ifndef OLSHOP_H_INCLUDED
#define OLSHOP_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
inline void display(string label, string value){
    cout << setw(20) << left << label << ": " << value << endl;
}

inline void prompt(string prompt){
    cout << setw(20) << left << prompt << ": ";
}


#define info(P) (P)->info
#define next(P) (P)->next
#define child(P) (P)->child
#define first(L) ((L).first)
#define size(L) ((L).size)
#define nil NULL


//header untuk "Order"
struct order{
    string id;
    string product;
    int jumlah;
    float harga;
};

typedef struct order infoorder;
typedef struct elmOrder *adrOrder;

struct elmOrder{
    infoorder info;
    adrOrder next;
};

struct listOrder{
    adrOrder first;
    int size;
};

void createListOrder(listOrder &L);
adrOrder allocateOrder(infoorder O);
void insertOrder(listOrder &L, adrOrder P);
void deleteOrder(listOrder &L, adrOrder &P);
void printInfoOrder(adrOrder P);
void printListOrder(listOrder L);
adrOrder searchOrder(listOrder L, string id);
string IdOrder(listOrder L, string prefix);

//header untuk "Customer"
struct customer{
    string id, nama, alamat, telp, gender;
};

typedef struct customer infocustomer;
typedef struct elmCustomer *adrCustomer;

struct elmCustomer{
    infocustomer info;
    listOrder child;
    adrCustomer next;
};

struct listCustomer{
    adrCustomer first;
    int size;
};

void createListCustomer(listCustomer &L);
adrCustomer allocateCust(infocustomer x);
void insertCustomer(listCustomer &L, adrCustomer P);
void deleteCustomer(listCustomer &L, adrCustomer &P);
void printInfoCustomer(adrCustomer P);
void printListCustomer(listCustomer L);
adrCustomer searchCustomer(listCustomer L, string id);
string IdCustomer(listCustomer L, string prefix);


#endif // OLSHOP_H_INCLUDED
