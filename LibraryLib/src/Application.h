#pragma once
#include "LibraryLib.h"
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <string>


class Application
{
private:
	int choice;
	Library& library = Library::Get();
	std::vector<std::unique_ptr<User>> users;
public:
	Application();
	~Application() {};
	void run();
	void read_from_file(std::string path);
	void write_to_file(std::string path);
	void start_window();
	void admin_library_menu();
	void list_of_books();

	void book_menu(std::string msg, Book* book)
	{
		std::cout.width(40);
		std::cout
			<< std::internal << "Book" << std::endl
			<< book->info() << std::endl
			<< (msg.empty() ? "": "\n1. ") << msg
			<< "\n0. Back to list of " << library.get_name() << " books.\n"
			<< "\nSelect one option: ";
	}

	void admin_add_new_book();

	void admin_remove_book(Book* book)
	{
		if (book->get_status()) {
			library.remove_book(book);
		}
		else {
			std::cout << "Can't delete this book, because it has not been returned.\n";
		}
	}

	void user_window();
	void list_of_users();
	void user_menu(User* user);

	void user_issue_book(User* user, Book* book)
	{
		user->issue_book(book);
		std::cout << "Book was successfully issued!\n";
	}
	void user_list_of_issued_books(User* user);

	void user_return_book(User* user, Book *book)
	{
		user->return_book(book);
		std::cout << "Book was successfully returned!\n";
	}

	void remove_user(User* user);
	void create_user();
};
