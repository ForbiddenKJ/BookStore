// Includes

#include <iostream>
#include <string>
#include <array>

// FUNCTION Clear Screen

void clear(){
  std::cout << "\x1B[2J\x1B[H";
}

// CLASS Backend Class

class BookStore{
public:

  // STRUCTURE Book Struct

  struct Book{
    int id;
    std::string name;
    std::string authorName;
    float price;
  };

  // VARIABLES inStore Variables

  Book inStore[128];
  int inStoreNext;

  // FUNCTION Add Book

  void addBook(Book book){

    // Set Values For inStore Index

    inStore[inStoreNext].id         = book.id;
    inStore[inStoreNext].name       = book.name;
    inStore[inStoreNext].authorName = book.authorName;
    inStore[inStoreNext].price      = book.price;

    // Increment inStoreNext By 1

    inStoreNext++;
  }

  // FUNCTION Remove Book

  void removeBook(int id){

    // Set Values To Default

    inStore[inStoreNext].id         = -1;
    inStore[inStoreNext].name       = "";
    inStore[inStoreNext].authorName = "";
    inStore[inStoreNext].price      = -1;

    // Decrement inStoreNext By 1

    inStoreNext--;
  }

  // FUNCTION Find Book

  int findBook(Book book){

    // Linear Search

    for (int i = 0; i < inStoreNext; i++){
      int total;

      if (inStore[i].name == book.name){
        total++;
      }

      if (inStore[i].id == book.id){
        total++;
      }

      if (inStore[i].authorName == book.authorName){
        total++;
      }

      if (inStore[i].price == book.price){
        total++;
      }

      if (total >= 4){
        return i;
      }

    }

    // Return -1 If book Not In inStore

    return -1;
  }

  // FUNCTION Display Results

  void showBook(Book book){

    // Print Out Data

    std::cout << "ID     " << book.id         << std::endl;
    std::cout << "Name   " << book.name       << std::endl;
    std::cout << "Author " << book.authorName << std::endl;
    std::cout << "Price  " << book.price      << std::endl;
  }
};

// CLASS Frontend Class

class Frontend{

  // FUNCTION Main Screen

  void mainScreen(){

    int operation;

    // Print Actions

    std::cout << "0 : Exit" std::endl;
    std::cout << "1 : Add Book" << std::endl;
    std::cout << "2 : Remove Book" << std::endl;
    std::cout << "3 : Find Book" << std::endl;

    std::cin >> operation;

    // Switch Menus

    switch(operation){
      case 0:
        break;

      case 1:
        addBookScreen();
        break;

      // TODO: Add Remove Book

      case 2:
        break;

      case 3:
        findBookScreen();
        break;

      default:
        break;
    }

  }

  // FUNCTION Add Book Menu

  void addBookScreen(){

    // VARIABLES Create Place Holders

    int id;
    std::string name;
    std::string authorName;
    float price;

    // Recive I/O

    std::cout << "ID:          " << std::endl;
    std::cin >> id;
    std::cout << "Name:        " << std::endl;
    std::cin >> name;
    std::cout << "Author Name: " << std::endl;
    std::cin >> authorName;
    std::cout << "Price:       " << std::endl;
    std::cin >> price;

    // Create and Add Book

    BookStore::Book book = {id, name, authorName, price};
    myBookStore.addBook(book);

    // Move Back to mainScreen

    mainScreen();

  }

  void findBookScreen(){
    // VARIABLES Create Place Holders

    int id;
    std::string name;
    std::string authorName;
    float price;

    // Recive I/O

    std::cout << "ID:          " << std::endl;
    std::cin >> id;
    std::cout << "Name:        " << std::endl;
    std::cin >> name;
    std::cout << "Author Name: " << std::endl;
    std::cin >> authorName;
    std::cout << "Price:       " << std::endl;
    std::cin >> price;

    // Create and Find Book

    BookStore::Book book = {id, name, authorName, price};
    int uuid = myBookStore.findBook(book);

    // Display Results

    if (uuid == -1){
      std::cout << "Hmmm. We could not find your requested book!" << std::endl;
    }

    else{
      std::cout << book.name << " has the UUID " << uuid << std::endl;
    }

    // Move Back to mainScreen

    mainScreen();

  }

};

// FUNCTION Main Function

int main(){

  // Create Frontend Class

  Frontend front;
  front.mainScreen();

  return 0;
}
