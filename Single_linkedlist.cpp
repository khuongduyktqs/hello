#include<stdio.h>
#include<stdlib.h>
//khai bao linkedlist
struct LinkedList{
    int data;
    struct LinkedList *next;
};
//tao moi 1 node
typedef struct LinkedList *node;
node CreateNode(int value){
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    temp->data = value;
    return temp;
}
//them node vao dau linkedlist
node AddHead(node head, int value){
    node temp = CreateNode(value);
    if(head == NULL){
        head = temp;
    }else{
        temp->next = head;
        head = temp;
    }
    return head;
}
//them node vao cuoi linkedlist
node AddTail(node head, int value){
    node temp, p;
    temp = CreateNode(value);
    if(head == NULL ){
        head = temp;
    }else{
        p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
        //temp = p;
    }
    return head;
}
//them node vi tri bat ki
node AddAt(node head, int value, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, value);
    }else{
        int k = 1;
        node p = head;
        while (p != NULL && k != position){
            p = p->next;
            ++k;
        }
        if(k != position){
            head = AddTail(head, value);
        }else{
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
//xoa node dau khoi linkedlist
node DelHead(node head){
    if(head == NULL){
        printf("\nKhong co gi de xoa !");
    }else{
        head = head->next;
    }
    return head;
}
//xoa node cuoi khoi linkedlist
node DelTail(node head){
    if(head == NULL || head->next == NULL){
        return DelHead(head);
    }
    node p = head;
    while (p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next;
    // p->next = NULL;
    return head;
}
//xoa node o vi tri bat ki 
node DelAt(node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = DelHead(head);
    }else{
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
        if(k != position){
            head = DelTail(head);
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
//lay gia tri o vi tri bat ki
int Get(node head, int index){
    int k = 0;
    node p = head;
    while(p->next != NULL && k != index){
        ++k;
        p = p->next;
    }
    return p->data;
}
//tim kiem trong linkedlist
int Search(node head, int value){
    int position = 0;
    for(node p = head; p != NULL; p = p->next){
        if(p->data == value){
            return position;
        }
        ++position;
    }
    return -1;
}
// xoa tat ca cac node co gia tri chi dinh
node DelByVal(node head, int value){
    int position = Search(head, value);
    while(position != -1){
        DelAt(head,position);
        position = Search(head,value);
    }
    return head;
}
//duyet danh sach lien ket
void Traverser(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%5d",p->data);
    }
}
//ham khoi tao node head
node InitHead(){
    node head;
    head = NULL;
    return head;
}
// ham lay so phan tu Linkedlist
int Length(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
//ham nhap danh sach lien ket
node Input(){
    node head = InitHead();
    int n, value;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d",&n);
    }while(n <= 0);
    for(int i = 0; i < n; ++i){
        printf("\nPhan tu thu %d la: ", i);
        scanf("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}
int main(){
    printf("\n==Tao 1 danh sach lien ket==");
    node head = Input();
    Traverser(head);
 
    printf("\n==Thu them 1 phan tu vao linked list==");
    head = AddAt(head, 100, 2);
    Traverser(head);
 
    printf("\n==Thu xoa 1 phan tu khoi linked list==");
    head = DelAt(head, 1);
    Traverser(head);
 
    printf("\n==Thu tim kiem 1 phan tu trong linked list==");
    int index = Search(head, 5);
    printf("\nTim thay tai chi so %d", index);
 
    printf("\n==Xoa cac phan tu co gia tri bang value==");
    head = DelByVal(head, 4);
    Traverser(head);
 
}