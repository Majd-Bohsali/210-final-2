#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <deque> 
using namespace std; 

struct Customer { 
    string name;
    string order; 
    Customer* next; 
};

const int NEW_CUSTOMER_PROP = 50; 

int main() {
    srand(time(NULL));
    int namesCount = 20, drinksCount = 20, muffinCount = 20;; 
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
    string muffins[] = {
    "Blueberry Muffin", "Chocolate Chip Muffin", "Banana Nut Muffin",
    "Lemon Poppy Seed Muffin", "Cinnamon Streusel Muffin", "Pumpkin Spice Muffin",
    "Apple Crumble Muffin", "Double Chocolate Muffin", "Raspberry White Chocolate Muffin",
    "Strawberry Muffin", "Coffee Cake Muffin", "Zucchini Muffin",
    "Carrot Muffin", "Maple Pecan Muffin", "Peach Cobbler Muffin",
    "Cranberry Orange Muffin", "Blackberry Muffin", "Almond Muffin",
    "Mocha Muffin", "Nutella Swirl Muffin"
    };

    Customer* coffeeHead = nullptr; 
    deque<Customer> muffinsDqeue; 

    for(int i = 0; i < 3; i++) { 
        Customer* tempCustomer = new Customer; 
        tempCustomer->name = names[rand() % namesCount]; 
        tempCustomer->order = drinks[rand() % drinksCount];
        tempCustomer->next = nullptr; 

        if(coffeeHead == nullptr) { 
            coffeeHead = tempCustomer; 
        } else { 
            Customer* currCustomer = coffeeHead; 
            while(currCustomer->next) { 
                currCustomer = currCustomer->next; 
            }
            currCustomer->next = tempCustomer; 
        }
    }

    for(int i = 0; i < 10; i++) { 
        cout << "Round " << i+1 << ":" << endl;
        if(coffeeHead) { 
            Customer* frontCustomer = coffeeHead;
            cout << frontCustomer->name << " was served " << frontCustomer->order << endl; 
            coffeeHead = frontCustomer->next; 
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

            if(coffeeHead == nullptr) { 
            coffeeHead = tempCustomer; 
            } else { 
                Customer* currCustomer = coffeeHead; 
                while(currCustomer->next) { 
                    currCustomer = currCustomer->next; 
                }
                currCustomer->next = tempCustomer; 
            }
        }
        cout << endl;

        if(!muffinsDqeue.empty()) { 
            
        } else { 
            cout << "Muffins queue is currently empty" << endl;
        }

        if(rand() % 100 < NEW_CUSTOMER_PROP) {
            Customer* tempCustomer = new Customer; 
            tempCustomer->name = names[rand() % namesCount]; 
            tempCustomer->order = muffins[rand() % muffinCount];
            muffinsDqeue.push_back(tempCustomer);
        }
        cout << endl;
    }

    return 0;
}