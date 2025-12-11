#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std; 

struct Customer { 
    string name;
    string order; 
    Customer* next; 
};

int main() {
    srand(time(NULL));
    int namesCount = 10, drinksCount = 10; 
    string names[] = {"Caleb", "Zoe", "Jackson", "Lila", "Mateo", "Chloe", "Lucas", "Hazel", "Aiden", "Nora"};
    string drinks[] = {"Vanilla Cold Brew", "Iced Mocha", "Flat White", "Americano", "Chai Latte",
                        "Matcha Latte", "Hot Chocolate", "Pumpkin Spice Latte",
                        "Honey Almond Latte", "Iced Espresso"};
    
    Customer* head = nullptr; 

    for(int i = 0; i < 5; i++) { 
        Customer* tempCustomer = new Customer; 
        tempCustomer->name = names[rand() % namesCount]; 
        tempCustomer->order = drinks[rand() % drinksCount];
        tempCustomer->next = nullptr; 

        if(head == nullptr) { 
            head = tempCustomer; 
        } else { 
            Customer* currCustomer = head; 
            while(currCustomer->next) { 
                currCustomer = currCustomer->next; 
            }
            currCustomer->next = tempCustomer; 
        }
    }

    for(int i = 0; i < 10; i++) { 
        cout << "Round " << i+1 << ":" << endl;
        if(head) { 
            Customer* frontCustomer = head;
            cout << frontCustomer->name << " was served " << frontCustomer->order << endl; 
            head = frontCustomer->next; 
            delete frontCustomer; 
        } else { 
            cout << "Coffee queue is currently empty" << endl;
        }
    }

    return 0;
}