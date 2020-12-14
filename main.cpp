#include <iostream>
#include "pokemon.h"
using namespace std;

// Fixed array size constant and global array size
int const MAX_POKEMON_COLLECTION_SIZE = 30;
int POKEMON_COLLECTION_SIZE = 0;

// Gets user input for the commands 1-8 and error checks, re-runs if not valid
int getCommandInput(int &commandNumber) {

    cout << "> ";
    cin >> commandNumber;

    if (commandNumber <= 0 || commandNumber > 8) {
        cout << "Invalid command number. Please try again." << endl;
        return getCommandInput(commandNumber);
    } else {
        return commandNumber;
    }

}

// Clears the pokemonCollection array before re-reading the Pokedex into the array
void clearPokedex(pokemon pokemonCollection[]) {

    ifstream din;
    din.open("pokemon.txt");

    for (int i = 0; i < MAX_POKEMON_COLLECTION_SIZE; i++) {
        pokemon card;
        pokemonCollection[i] = card;
    }

    din.close();

    POKEMON_COLLECTION_SIZE = 0;

}

// Reads the pokedex file into the array
void readPokedex(pokemon pokemonCollection[]) {

    // Clear Pokedex file
    clearPokedex(pokemonCollection);

    // Open Pokedex file
    ifstream din;
    din.open("pokemon.txt");

    // Loop through file and create objects
    for (int i = 0; i < MAX_POKEMON_COLLECTION_SIZE; i++) {

        pokemon card;
        card.read(din);
        if (card.getNumber() == 0) {
            break;
        } else {
            pokemonCollection[i] = card;
            POKEMON_COLLECTION_SIZE++;
        }

    }

    din.close();

}

// Writes the array to the pokedex file
void writePokedex(pokemon pokemonCollection[]) {

    // Open Pokedex file
    ofstream dout;
    dout.open("pokemon.txt");

    // Loop through array and write to file
    for (int i = 0; i < POKEMON_COLLECTION_SIZE; i++) {

        pokemon card;
        card = pokemonCollection[i];
        card.write(dout);

    }

    dout.close();

}

// Buys pokemon card and gets relevant info from user
void buyPokemonCard(pokemon pokemonCollection[]) {

    int number, grade = 0;
    string name, edition = "none";
    float purchase = 0;

    if ((MAX_POKEMON_COLLECTION_SIZE - POKEMON_COLLECTION_SIZE) != 0) {

        cout << "Purchase a New Card!" << endl;
        cout << endl;

        pokemon newCard;

        cout << "Number (1 - 102): ";
        cin >> number;
        newCard.setNumber(number);

        cout << "Name: ";
        cin >> name;
        newCard.setName(name);

        cout << "Grade (1 - 10): ";
        cin >> grade;
        newCard.setGrade(grade);

        cout << "Edition (First, Shadowless, or Unlimited): ";
        cin >> edition;
        newCard.setEdition(edition);

        cout << "Purchase Price: $";
        cin >> purchase;
        newCard.setPurchasePrice(purchase);

        newCard.setSalePrice(0);

        pokemonCollection[POKEMON_COLLECTION_SIZE] = newCard;
        POKEMON_COLLECTION_SIZE++;

    } else {

        cout << "Sorry! Your Pokedex is already full!" << endl;

    }

}

// Sells card if card exists or hasn't been previously sold
void sellPokemonCard(pokemon pokemonCollection[]) {

    string cardName;
    float salePrice;
    bool found = false;

    cout << "Card name to sell (exactly as seen on card): ";
    cin >> cardName;

    for (int i = 0; i < POKEMON_COLLECTION_SIZE; i++) {

        if (pokemonCollection[i].getName() == cardName) {

            if (pokemonCollection[i].getSalePrice() == 0) {

                cout << "Sale Price: $";
                cin >> salePrice;
                pokemonCollection[i].setSalePrice(salePrice);
                found = true;

            } else if (pokemonCollection[i].getSalePrice() != 0) {

                cout << "Card has already been sold, sorry nice try!" << endl;
                found = true;

            }

        }

    }

    if (!found) {

        cout << "Card does not exist in your Pokedex!" << endl;

    }

}

// Gets the total worth of the pokemon collection array, skipping over sold cards
void worthOfPokedex(pokemon pokemonCollection[], float &valueOfPokedex) {

    for (int i = 0; i < POKEMON_COLLECTION_SIZE; i++) {

        if (pokemonCollection[i].getSalePrice() == 0) {

            valueOfPokedex += pokemonCollection[i].getPurchasePrice();

        }

    }

    cout << "Value of your Pokedex: $" << valueOfPokedex << endl;

}

// Finds most valuable card in array and prints out the name and price of the card
void findMostValuable(pokemon pokemonCollection[], float &mostValuablePrice, string &mostValuableName) {

    for (int i = 0; i < POKEMON_COLLECTION_SIZE; i++) {

        if (pokemonCollection[i].getPurchasePrice() > mostValuablePrice) {

            mostValuablePrice = pokemonCollection[i].getPurchasePrice();
            mostValuableName = pokemonCollection[i].getName();

        }

    }

    cout << "Most Valuable Card" << endl;
    cout << "Name: " << mostValuableName << endl;
    cout << "Price: " << mostValuablePrice << endl;

}

int main()
{

    bool quit = false;

    // Initialize pokemon object array with fixed size
    pokemon pokemonCollection[MAX_POKEMON_COLLECTION_SIZE];

    // Read in initial Pokedex
    readPokedex(pokemonCollection);
    cout << "Existing Pokemon cards in the Pokedex have been loaded in..." << endl;
    cout << endl;

    cout << "Welcome to your Virtual Pokedex!" << endl;
    cout << "Enter a number to execute the command below." << endl;
    cout << endl;

    while (!quit) {

        int commandNumber = 0;
        float valueOfPokedex = 0;
        float mostValuablePrice = 0;
        string mostValuableName;

        cout << "Current # of cards: " << POKEMON_COLLECTION_SIZE << endl;
        cout << "1. Read" << endl;
        cout << "2. Write" << endl;
        cout << "3. Print" << endl;
        cout << "4. Buy" << endl;
        cout << "5. Sell" << endl;
        cout << "6. Valuable" << endl;
        cout << "7. Worth" << endl;
        cout << "8. Quit" << endl;
        getCommandInput(commandNumber);

        switch (commandNumber) {
            case 1:
                readPokedex(pokemonCollection);
                break;
            case 2:
                writePokedex(pokemonCollection);
                break;
            case 3:
                for (int i = 0; i < POKEMON_COLLECTION_SIZE; i++) {
                    pokemonCollection[i].print();
                }
                break;
            case 4:
                buyPokemonCard(pokemonCollection);
                break;
            case 5:
                sellPokemonCard(pokemonCollection);
                break;
            case 6:
                findMostValuable(pokemonCollection, mostValuablePrice, mostValuableName);
                break;
            case 7:
                worthOfPokedex(pokemonCollection, valueOfPokedex);
                break;
            case 8:
                quit = true;
                break;
            default:
                break;
        }

    }

    return 0;

}