#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct List {
    double a;
     List *next;
};
 List* Read(List *L){       // читам список
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

 void Printlist(List *L){   //Выводим
     while (L !=NULL){
         cout << L -> a << " ";
         L = L -> next;
     }
     cout << endl;
 }

 List *End (List *L){   //Конец
     while (L !=NULL){
         L = L->next;
     }
     return L;
 }

 List *First(List *L){
     return L;
 }

 void Add (List *&top, int pos, int x){
     int j = 1;
     int i ;
     List *pnew, *p = top;
     pnew = new List; pnew -> a = x;
     if (pos <= 1 || top == NULL){
         pnew -> next = top; top = pnew;
     }
     else {
         for (i = 1; i< pos - 1; i++)
             if (p -> next != NULL){
                 p = p -> next;
                 j++;
             }
             if (pos <= j + 1){
                 pnew -> next = p -> next = pnew;
             }
     }
 }


void Delete(int p, List *&L)  //Удаление элемента
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
          cout <<" Menu "<<endl<<" 1. Введите элемент"<< endl <<" 2. Удаление элемента"<< endl << "3. Сначало" << endl;
          cout <<"4. Вывести список" << endl;
          cout << "5. Добавить элемент" << endl;
          cout <<"Ведите команду: "<<endl;
          cin >> c;
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
              case 3:
                  if (First(L) != NULL)
                    cout << First(L) -> a << endl;
                  else
                      cout << "Список пуст "<< endl;
                  break;
              case 4:
                  Printlist(L);
                  break;
              case 5:
                  int pos, x;
                  cout << "Введите номер для добавления: ";
                  cin >> pos;
                  cout << "Введите элемент добавления: ";
                  cin >> x;
                  Add( L, pos, x);
          }
          system("pause");
      }
      while (c != 0);
 }

int main() {

     List* list = NULL;
     Menu (list);
     system("pause");

    return 0;
}