#include <iostream>

using namespace std; 

struct Customer { 
    string name;
    string order; 
    Customer* next; 
};

int main() {

    string names[] = {"Caleb", "Zoe", "Jackson", "Lila", "Mateo", "Chloe", "Lucas", "Hazel", "Aiden", "Nora"};
    string drinks[] = {"Vanilla Cold Brew", "Iced Mocha", "Flat White", "Americano", "Chai Latte",
                        "Matcha Latte", "Hot Chocolate", "Pumpkin Spice Latte",
                        "Honey Almond Latte", "Iced Espresso"};
    
    Customer* coffeListHead = nullptr; 

    return 0;
}