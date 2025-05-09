#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class Product {
private:
   int data;
   Product* next;
   int productID;
public:
   Product(){
        data = 0;
        next = NULL;
        productID = 0;
   }
   int getData(){
        return data;
   }
   void setData(int dt){
        data = dt;
   }
   Product* getNext(){
        return next;
   } 
    void setNext(Product* nxt) {
        next = nxt;
    }

    int getProductID() {
        return productID;
    }
   void setProductID(int pid) {
        productID = pid;
   }
};

class Queue {
private:
    Product* front;
    Product* rear;
public:
    Queue() {
          front = rear = NULL;
     }
    void enqueue(int data, int pid){
          Product* temp = new Product();
          temp->setData(data);
          temp->setProductID(pid);
          temp->setNext(NULL);
          
          if (rear == NULL) {
              front = rear = temp;
          } else {
              rear->setNext(temp);
              rear = temp;
          }
          cout << "Added -> Serial: " << data << ", Product ID: " << pid << "\n";
   }
   int dequeue() {
       if (front == NULL) {
          cout << "Queue is empty, nothing to dequeue. \n";
          return -1;
   }

   Product*temp = front;
   int serial = temp -> getData();
   cout << "Sold product with  serial: " << serial << "and ID: " << temp -> getProductID() << "\n";
   front = front -> getNext();
   
   if(front == NULL) {
      rear = NULL;
   }

   delete temp;
   return serial; 
  }
  
  void displayFront() {
     if(front != NULL) {
        cout << "First product in queue -> serial: " << front-> getData()<< ", Product ID: " << front-> getProductID() << "\n";
     } else {
        cout << "Queue is empty. \n";
     }   
  }
  void displayRear() {
     if (rear != NULL) {
        cout << "Last product in queue -> serial: " << rear -> getData() << ", Product ID: " << rear -> getProductID() << "\n";
     } else { 
        cout << "Queue is empty. \n";
     }
  }
};

int main(){
    string studentID = "BC234568789";
    int lastThreeDigits = atoi(studentID.substr(studentID.length() -3).c_str());

    int smartphones = lastThreeDigits / 100;
    int tables = (lastThreeDigits / 10) % 10;
    int smartWatch = lastThreeDigits % 10;

    int serial = 1;
    int productID = atoi(studentID.substr(studentID.length() -4).c_str());

    Queue inventory;
 
    cout << "Student ID: " << studentID << "\n";
    cout << "----------------------------------- \n";
    
    cout << smartphones << " Smartphones being added to inventory: \n";
        for (int i = 0; i< smartphones; i++) {
         inventory.enqueue(serial++, productID++);
    }
    cout << "\n";

    cout << tables << " Tables being added to inventory: \n";
        for (int i = 0; i< tables; i++) {
         inventory.enqueue(serial++, productID++);
    }
    cout << "\n";

    cout << smartWatch << " Smartwatch being added to inventory: \n";


    for (int i = 0; i< smartWatch; i++) {
         inventory.enqueue(serial++, productID++);
    }
    cout << "\n";

    cout << "------------------------------------\n";
    inventory.displayFront();
    cout << "-------------------------------------\n";
    inventory.displayRear();
    cout << "-------------------------------------\n";

    cout << "Selling 2 products... \n";
    inventory.dequeue();
    inventory.dequeue();
    cout << "-------------------------------------\n";
    inventory.displayFront();
    cout << "\n=================================================\n";

     return 0;
  }
