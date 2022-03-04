#include <iostream>
using namespace std;

struct DataUser {
    string nama,nrp;
    DataUser *prev;
    DataUser *next;
};

DataUser *head,*tail,*cur,*newnode,*del,*afternode;

void createDoubleLinkedList(string data[2]){
    head = new DataUser();
    head->nama = data[0];
    head->nrp = data[1];
    head->prev = NULL;
    head->next = NULL;
    tail=head;
}

int countDoubleLinkedList(){
    if( head ==NULL ){
        cout << "Double Linked List belum dibuat ";
    }else{
        cur = head;
        int jumlah = 0;
    while ( cur !=NULL )
    {
        jumlah++;
        cur = cur->next;
     }
     return jumlah;
    }
}

void addFirst(string data[2]){
    if( head ==NULL ){
        cout << "Double Linked List belum dibuat ";
    }else{
    newnode = new DataUser();
    newnode->nama = data[0];
    newnode->nrp = data[1];
    newnode->prev = NULL;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    }
}

void addLast(string data[2]){
    if( head ==NULL ){
        cout << "Double Linked List belum dibuat ";
    }else{
    newnode = new DataUser();
    newnode->nama = data[0];
    newnode->nrp = data[1];
    newnode->prev = tail;
    newnode->next = NULL;
    tail->next = newnode;
    tail = newnode;
    }
}

void addMiddle (string data[2],int posisi){
    if( head ==NULL ){
        cout << "Double Linked List belum dibuat ";
    }else{
        if(posisi == 1){
            cout << "Posisi 1 bukan posisi tengah " <<endl;
        }else if( posisi < 1 || posisi > countDoubleLinkedList()){
            cout <<  "Posisi diluar jangkauan " <<endl;
        }else{
            newnode = new DataUser();
            newnode->nama = data[0];
            newnode->nrp = data[1];
            cur = head;
            int nomor = 1;
            while ( nomor < posisi -1) {
            cur = cur->next;
            nomor++;
            }
            afternode = cur->next;
            newnode->prev = cur;
            newnode->next = afternode;
            cur->next = newnode;
            afternode->prev = newnode;
            }
        }
    }

void removeFirst(){
    if( head ==NULL ){
        cout << "Double Linked List belum dibuat ";
    }else{
        del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
}

void removeLast(){
    if( head ==NULL ){
        cout << "Double Linked List belum dibuat ";
    }else{
        del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }
}

void removeMiddle(int posisi){
     if( head ==NULL ){
        cout << "Double Linked List belum dibuat ";
    }else{
        if ( posisi == 1 || posisi == countDoubleLinkedList()){
             cout << "Posisi bukan posisi tengah " <<endl;
        }else if( posisi < 1 || posisi > countDoubleLinkedList()){
            cout <<  "Posisi diluar jangkauan " <<endl;
        }else{
            int nomor = 1;
            cur = head;
            while ( nomor < posisi -1){}{
                cur = cur->next;
                nomor++;
            }
            del = cur->next;
            afternode = del->next;
            cur->next = afternode;
            afternode->prev = cur;
            delete del;
        }
    }
}

void printDoubleLinkedList(){
    if( head ==NULL ){
        cout << "Double Linked List belum dibuat ";
    }else{
        cout << "Jumlah Data " << countDoubleLinkedList() << endl;
        cur = head;
    while ( cur !=NULL )
    {
        cout <<"Nama "<< cur->nama << endl;
        cout <<"NRP "<< cur->nrp << endl;
        cur = cur->next;
     }
    }
}

int main (){

    cout <<"Awalan \n";
    string databaru[2] = {"Ammar","77"};
    createDoubleLinkedList(databaru);
    printDoubleLinkedList();

    cout <<"Insert Data di depan \n";
    string databaru1[2] = {"Izu","78"};
    addFirst(databaru1);
    printDoubleLinkedList();

    cout <<"Insert Data di belakang \n";
    string databaru2[2] = {"Cheno","79"};
    addLast(databaru2);
    printDoubleLinkedList();

    cout <<"Hapus Data di depan \n";
    removeFirst();
    printDoubleLinkedList();

    cout <<"Hapus Data di belakang \n";
    removeLast();
    printDoubleLinkedList();

    cout <<"Insert Data di n \n";
    string databaru3[2] = {"Popi","80"};
    addMiddle(databaru3,2);
    printDoubleLinkedList();

    cout <<"Hapus Data di n \n";
    removeMiddle(2);
    printDoubleLinkedList();
}