#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct List {
    double *a;
     List *next;
};
 List* Read(List *L){
     List *a = new List;
     a -> next = NULL;
     cout << "Введите элемент: "<< endl;
     cin >> a-> a;

     if (L == NULL){
         L == a;
     }
     else{
         List *c = L;
         while (c -> next !=NULL) c = c -> next;
         c ->next = a;
     }
     return L;
 }

void Delete(int p, List *&L)
{
    List*& a = L;
    List* b = a->next;
    if (p == 1) {
        a = a->next;
        cout << "Элемент удален" << endl;
    }
    else{

        while (p>2)
        {
            p--;
            a = a->next;
            b = b->next;
            if (b == NULL) break;
        }
        if (b != NULL) {
            a->next = b->next;
            cout << "Элемент удален" << endl;
        }
        else cout << "Такой позиции нет" << endl;
    }
}

 void Menu(List *&L){
      int c;
      do{
          system("csl");
          cout<<" Menu "<<endl<<" 1. Введите элемент"<<endl<<" 2. Удаление элемента"<<endl;
          cout<<"Ведите команду: "<<endl;
          cin>>c;
          switch (c){
              case 1:
                  L = Read(L);
                  break;

              case 2:
                  int p;
                  cout << "Введите p: ";
                  cin >> p;
                  Delete(p, L);
                  break;
          }

      }
 }

int main() {

     List* list = NULL;
     Menu (List);
     system("pause");

    return 0;
}