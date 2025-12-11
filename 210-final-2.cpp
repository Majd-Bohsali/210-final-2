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

const int NEW_CUSTOMER_PROP = 50; 

int main() {
    srand(time(NULL));
    int namesCount = 20, drinksCount = 20; 
    string names[] = {
        "Caleb", "Zoe", "Jackson", "Lila", "Mateo", "Chloe", "Lucas", "Hazel",
        "Aiden", "Nora", "Emma", "Liam", "Olivia", "Noah", "Ava", "Mason",
        "Isabella", "Elijah", "Sophia", "Ethan"
                    };
    string drinks[] = {
        "Vanilla Cold Brew", "Iced Mocha", "Flat White", "Americano", "Chai Latte",
        "Matcha Latte", "Hot Chocolate", "Pumpkin Spice Latte", "Honey Almond Latte",
        "Iced Espresso", "Caramel Macchiato", "Hazelnut Latte", "Mocha Frappé",
        "Cinnamon Dolce Latte", "London Fog Tea", "Dirty Chai", "Iced Matcha Lemonade",
        "White Chocolate Mocha", "Cold Foam Cold Brew", "Peppermint Mocha"
    };
    
    Customer* head = nullptr; 

    for(int i = 0; i < 3; i++) { 
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

        if(rand() % 100 < NEW_CUSTOMER_PROP) {
            Customer* tempCustomer = new Customer; 
            tempCustomer->name = names[rand() % namesCount]; 
            tempCustomer->order = drinks[rand() % drinksCount];
            tempCustomer->next = nullptr;  

            cout << tempCustomer->name << " joined the coffee line" << endl;

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
        cout << endl;
    }

    return 0;
}