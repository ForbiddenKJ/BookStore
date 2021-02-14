#include <iostream>
#include <string>
#include <array>

void clear(){
  std::cout << "\x1B[2J\x1B[H";
}

int close(){
  clear();
  std::cout << "Closing";
  return 0;
};

class BookStore{
public:
  struct Book{
    unsigned int id;
    std::string name;
    std::string authorFirst;
    std::string authorSecond;
    float price;
    std::string authorName = authorFirst + " " + authorSecond;
  };

  Book inStore[128];
  unsigned int inStoreNext;

  Book addBook(int id,
               std::string name,
               std::string authorFirst,
               std::string authorSecond,
               float price)
  {
    inStore[inStoreNext].id = id;
    inStore[inStoreNext].name = name;
    inStore[inStoreNext].authorFirst = authorFirst;
    inStore[inStoreNext].authorSecond = authorSecond;
    inStore[inStoreNext].price = price;
    inStore[inStoreNext].authorName = inStore[inStoreNext].authorFirst + " " + inStore[inStoreNext].authorSecond;

    inStoreNext++;

    return inStore[inStoreNext - 1];
  }

  Book addBook(Book book){

    inStore[inStoreNext].id = book.id;
    inStore[inStoreNext].name = book.name;
    inStore[inStoreNext].authorFirst = book.authorFirst;
    inStore[inStoreNext].authorSecond = book.authorSecond;
    inStore[inStoreNext].price = book.price;
    inStore[inStoreNext].authorName = book.authorName;

    inStoreNext++;

    return inStore[inStoreNext - 1];
  }

  int length(){ return (sizeof(inStore)/sizeof(*inStore)); }

  bool compare(Book b1, Book b2){
    int total = 0;

    if (b1.name == b2.name){
      total++;
    }

    if (b1.authorName == b2.authorName){
      total++;
    }

    if (b1.price == b2.price){
      total++;
    }

    if (total == 3){
      return true;
    }

    if (total != 3){
      return false;
    }

    return false;
  }

};



class Frontend{
public:
  BookStore myBookStore;

  void mainScreen(){
    clear();

    int operation;

    std::cout << "0 : Exit" << std::endl;
    std::cout << "1 : Add Book" << std::endl;
    std::cout << "2 : Remove Book" << std::endl;
    std::cout << "3 : View Books" << std::endl;

    std::cin >> operation;

    switch (operation) {
      case 0:
        close();
        break;

      case 1:
        addBook();
        break;

      case 3:
        viewBook();
        break;

      default:
        close();
        break;
    }
  }

  void viewBook(){
    clear();

    unsigned int id;

    std::cout << "Book ID: " << std::endl;
    std::cin >> id;

    clear();

    std::cout << "Name: " << myBookStore.inStore[id].name << std::endl;
    std::cout << "Author Name: " << myBookStore.inStore[id].authorName << std::endl;
    std::cout << "Price: " << myBookStore.inStore[id].price << std::endl;

    std::string _continue;

    std::cout << "Continue? [Y/n]" << std::endl;
    std::cin >> _continue;

    if (_continue == "n"){
      close();
    }

    else{
      mainScreen();
    }

    mainScreen();
  }

  void addBook(){
    clear();

    unsigned int id;
    std::string name;
    std::string authorFirst;
    std::string authorSecond;
    float price;

    std::cout << "Book ID: " << std::endl;
    std::cin >> id;
    std::cout << "Book Name: " << std::endl;
    std::cin >> name;
    std::cout << "Author Forename Name: " << std::endl;
    std::cin >> authorFirst;
    std::cout << "Author Surname Name: " << std::endl;
    std::cin >> authorSecond;
    std::cout << "Price: " << std::endl;
    std::cin >> price;

    BookStore::Book book = {id, name, authorFirst, authorSecond, price};

    BookStore::Book a = myBookStore.addBook(book);
    BookStore::Book b = myBookStore.inStore[myBookStore.inStoreNext - 1];

    if (myBookStore.compare(a, b)){
      mainScreen();
    }

    if (!(myBookStore.compare(a, b))){
      std::cout << std::endl << "Error." << std::endl;
    }

  }
};

int main(){
  Frontend front;
  front.mainScreen();

  return 0;
}
