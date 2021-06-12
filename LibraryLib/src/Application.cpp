#include "Application.h"
#include "LibraryLib.h"
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

Application::Application()
{
	choice = -1;
}

void Application::run()
{
	while (choice != 0)
	{
		start_window();
		std::cin >> choice;
		system("CLS");
		if (choice == 1)
		{
			while (choice != 0) {
				admin_library_menu();
				std::cin >> choice;
				system("CLS");
				if (choice == 1)
				{
					while (choice != 0) {
						list_of_books();
						std::cin >> choice;
						system("CLS");
						int size_of_encyclopedias = library.get_list_of_encyclopedias().size();
						int size_of_fictions = library.get_list_of_fictions().size();
						int size_of_maps = library.get_list_of_maps().size();
						int list_of_books_size = size_of_encyclopedias + size_of_fictions + size_of_maps;
						if (choice > 0 && choice <= list_of_books_size)
						{
							if (choice <= size_of_encyclopedias)
							{
								Encyclopedia* book = library.get_list_of_encyclopedias()[choice - 1].get();
								book_menu("Remove book", book);
								std::cin >> choice;
								system("CLS");
								if (choice == 1)
								{
									admin_remove_book(book);
								}
							}
							else if (choice <= size_of_encyclopedias + size_of_fictions)
							{
								Fiction* book = library.get_list_of_fictions()[choice - size_of_encyclopedias - 1].get();
								book_menu("Remove book", book);
								std::cin >> choice;
								system("CLS");
								if (choice == 1)
								{
									admin_remove_book(book);
								}
							}
							else if (choice <= list_of_books_size)
							{
								Map* book = library.get_list_of_maps()[choice - size_of_encyclopedias - size_of_fictions - 1].get();
								book_menu("Remove book", book);
								std::cin >> choice;
								system("CLS");
								if (choice == 1)
								{
									admin_remove_book(book);
								}
							}
						}
					}
					choice = -1;
				}
				else if (choice == 2)
				{
					admin_add_new_book();
				}
			}
			choice = -1;
		
		}
		else if (choice == 2)
		{
			while (choice != 0) {
				user_window();
				std::cin >> choice;
				system("CLS");
				if (choice == 1)
				{
					while (choice != 0)
					{
						list_of_users();
						std::cin >> choice;
						system("CLS");
						if (choice > 0 && choice <= users.size())
						{
							User* user = users[choice - 1].get();
							while (choice != 0)
							{
								user_menu(user);
								std::cin >> choice;
								system("CLS");
								if (choice == 1)
								{
									while (choice != 0)
									{
										int size_of_encyclopedias = library.get_list_of_encyclopedias().size();
										int size_of_fictions = library.get_list_of_fictions().size();
										int size_of_maps = library.get_list_of_maps().size();
										int list_of_books_size = size_of_encyclopedias + size_of_fictions + size_of_maps;
										list_of_books();
										std::cin >> choice;
										system("CLS");
										if (choice > 0 && choice <= list_of_books_size)
										{
											if (choice <= size_of_encyclopedias)
											{
												Encyclopedia* book = library.get_list_of_encyclopedias()[choice - 1].get();
												book->get_status() ? book_menu("Issue book", book) : book_menu("", book);
												std::cin >> choice;
												system("CLS");
												if (choice == 1 && book->get_status())
												{
													user_issue_book(user, book);
												}
											}
											else if (choice <= size_of_encyclopedias + size_of_fictions)
											{
												Fiction* book = library.get_list_of_fictions()[choice - size_of_encyclopedias - 1].get();
												book->get_status() ? book_menu("Issue book", book) : book_menu("", book);
												std::cin >> choice;
												system("CLS");
												if (choice == 1 && book->get_status())
												{
													user_issue_book(user, book);
												}
											}
											else if (choice <= list_of_books_size)
											{
												Map* book = library.get_list_of_maps()[choice - size_of_encyclopedias - size_of_fictions - 1].get();
												book->get_status() ? book_menu("Issue book", book) : book_menu("", book);
												std::cin >> choice;
												system("CLS");
												if (choice == 1 && book->get_status())
												{
													user_issue_book(user, book);
												}
											}
										}
									}
									choice = -1;
								}
								else if (choice == 2)
								{
									while (choice != 0)
									{
										int size_of_encyclopedias = user->get_issued_encyclopedias().size();
										int size_of_fictions = user->get_issued_fictions().size();
										int size_of_maps = user->get_issued_maps().size();
										int list_of_books_size = size_of_encyclopedias + size_of_fictions + size_of_maps;
										user_list_of_issued_books(user);
										std::cin >> choice;
										system("CLS");
										if (choice > 0 && choice <= list_of_books_size)
										{
											if (choice <= size_of_encyclopedias)
											{
												Encyclopedia* book = 
													library.get_list_of_encyclopedias()[choice - 1].get();
												book_menu("Return book", book);
												std::cin >> choice;
												system("CLS");
												if (choice == 1)
												{
													user_return_book(user, book);
												}
											}
											else if (choice <= size_of_encyclopedias + size_of_fictions)
											{
												Fiction* book = 
													library.get_list_of_fictions()[choice - size_of_encyclopedias - 1].get();
												book_menu("Return book", book);
												std::cin >> choice;
												system("CLS");
												if (choice == 1)
												{
													user_return_book(user, book);
												}
											}
											else if (choice <= list_of_books_size)
											{
												Map* book = 
													library.get_list_of_maps()[choice - size_of_encyclopedias - size_of_fictions - 1].get();
												book_menu("Return book", book);
												std::cin >> choice;
												system("CLS");
												if (choice == 1)
												{
													user_return_book(user, book);
												}
											}
										}
										
									}
									choice = -1;
								}
								else if (choice == 3)
								{
									remove_user(user);
								}
							}
							choice = -1;
						}
					}
					choice = -1;
				}
				else if (choice == 2)
				{
					try {
						create_user();
					}
					catch (const char* error)
					{
						system("CLS");
						std::cerr << error << std::endl;
					}
				}
			}
			choice = -1;
		}
		else if (choice == 3)
		{
				std::string path;
				std::cout << "Enter file name (from /res/): ";
				std::cin.ignore();
				std::getline(std::cin, path);
				try {
					read_from_file(path);
				}
				catch (std::string error)
				{
					system("CLS");
					std::cerr << "Error: " << error << std::endl;
				}
				catch (const char* error)
				{
					system("CLS");
					std::cerr << error << std::endl;
				}
				catch (...)
				{
					system("CLS");
					std::cerr << "Error reading file." << std::endl;
				}
		}
	}
	write_to_file("save.txt");
	exit(0);
}

void Application::read_from_file(std::string path)
{
	std::string name, phone, title, author, year, topic, genre, area, type,
		subclass, part, user, empty;
	std::ifstream file("../res/" + path);
	if (file.is_open())
	{
		std::getline(file, part);
		if (part != "Users{")
		{
			throw "Invalid input file structure.";
		}
		while (true)
		{
			std::getline(file, name);
			std::getline(file, phone);
			std::getline(file, empty);
			for (auto it = users.begin(); it != users.end(); ++it)
			{
				if (name == (*it)->get_name())
					throw "Users with the same names are not allowed.";
			}
			users.emplace_back(
				new User(name, phone)
			);
			if (empty == "}") { break; }

		}
		std::getline(file, part);
		if (part != "Library{")
		{
			throw "Invalid input file structure.";
		}
		std::getline(file, name);
		std::getline(file, phone);

		std::getline(file, subclass);
		std::getline(file, subclass);
		std::string s;

		if (subclass == "Encyclopedias:") {
			while (std::getline(file, s))
			{
				if (!s.empty()) {
					std::istringstream iss(s);
					std::getline(iss, name, '\t');
					std::getline(iss, author, '\t');
					std::getline(iss, year, '\t');
					std::getline(iss, topic, '\t');
					std::getline(iss, user);
					Encyclopedia* book = new Encyclopedia(name, author, year, &library, topic);
					library.add_book(book);
					for (auto it = users.begin(); it != users.end(); ++it)
					{
						if ((*it)->get_name() == user)
						{
							user_issue_book((*it).get(), book);
						}
					}

				}
				else
					break;
			}
		}
		else
		{
			throw "Invalid input file structure.";
		}

		std::getline(file, subclass);
		if (subclass == "Fictions:") {
			while (std::getline(file, s))
			{
				if (!s.empty()) {
					std::istringstream iss(s);
					std::getline(iss, name, '\t');
					std::getline(iss, author, '\t');
					std::getline(iss, year, '\t');
					std::getline(iss, genre, '\t');
					std::getline(iss, user);
					Fiction* book = new Fiction(name, author, year, &library, genre);
					library.add_book(book);
					for (auto it = users.begin(); it != users.end(); ++it)
					{
						if ((*it)->get_name() == user)
						{
							user_issue_book((*it).get(), book);
						}
					}
				}
				else
					break;
			}
		}
		else
		{
			throw "Invalid input file structure.";
		}

		std::getline(file, subclass);
		if (subclass == "Maps:") {
			while (std::getline(file, s))
			{
				if (!s.empty() && s != "}") {
					std::istringstream iss(s);
					std::getline(iss, name, '\t');
					std::getline(iss, author, '\t');
					std::getline(iss, year, '\t');
					std::getline(iss, area, '\t');
					std::getline(iss, type, '\t');
					std::getline(iss, user);
					Map* book = new Map(name, author, year, &library, area, type);
					library.add_book(book);
					for (auto it = users.begin(); it != users.end(); ++it)
					{
						if ((*it)->get_name() == user)
						{
							user_issue_book((*it).get(), book);
						}
					}
				}
				else
					break;
			}
		}
		else
		{
			throw "Invalid input file structure";
		}

		library.set_name(name);
		library.set_phone(phone);


		file.close();
		system("CLS");
		std::cout << "Library successfully added\n";
	}
	else
	{
		std::string not_found = "File " + path + " not found.";
		throw not_found;
	}
}

void Application::write_to_file(std::string path)
{
	std::ofstream file("../res/" + path);
	file << "Users{";
	for (auto it = users.begin(); it != users.end(); ++it)
	{
		file << "\n" << (*it)->get_name() << "\n" << (*it)->get_phone() << "\n";
	}
	file << "}\nLibrary{\n" << library.get_name() << "\n" << library.get_phone() << "\n";
	file << "\nEncyclopedias:\n";
	for (auto it = library.get_list_of_encyclopedias().begin(); it != library.get_list_of_encyclopedias().end(); ++it)
	{
		file << (*it)->get_name() << "\t" << (*it)->get_author() << "\t" << (*it)->get_year() << "\t"
			<< (*it)->get_topic() << "\t"
			<< ((*it)->get_user()? (*it)->get_user()->get_name():"None") << "\n";
	}
	file << "\nFictions:\n";
	for (auto it = library.get_list_of_fictions().begin(); it != library.get_list_of_fictions().end(); ++it)
	{
		file << (*it)->get_name() << "\t" << (*it)->get_author() << "\t" << (*it)->get_year() << "\t"
			<< (*it)->get_genre() << "\t"
			<< ((*it)->get_user() ? (*it)->get_user()->get_name() : "None") << "\n";
	}
	file << "\nMaps:\n";
	for (auto it = library.get_list_of_maps().begin(); it != library.get_list_of_maps().end(); ++it)
	{
		file << (*it)->get_name() << "\t" << (*it)->get_author() << "\t" << (*it)->get_year() << "\t"
			<< (*it)->get_area() << "\t" << (*it)->get_type() << "\t"
			<< ((*it)->get_user() ? (*it)->get_user()->get_name() : "None") << "\n";
	}
	file << "}";
}

void Application::start_window()
{
	std::cout.width(40);
	std::cout
		<< std::internal << "Welcome to Library Manager" << std::endl
		<< "1. Log in as admin.\n"
		<< "2. Log in as user.\n"
		<< "\n3. Add library from file.\n"
		<< "\n0. Exit.\n"
		<< "\nSelect one option: ";
}

void Application::admin_library_menu()
{
	std::cout.width(80);
	std::cout << std::internal << "Welcome to " + library.get_name() + " Admin Panel" << std::endl;
	std::cout << info(&library) << std::endl;
	std::cout
		<< "\n1. Show list of books.\n"
		<< "2. Add new book.\n"
		<< "\n0. Log out.\n"
		<< "\nSelect one option: ";
}

void Application::list_of_books()
{
	std::cout.width(40);
	std::cout << std::internal << "List of " << library.get_name() << " books" << std::endl << std::endl;
	std::cout << std::left << std::setw(4) << "id" << std::setw(20) << "Name"
		<< std::setw(20) << "Type" << std::setw(20) << "Available" << std::endl;
	int i = 0;
	for (auto it = library.get_list_of_encyclopedias().begin(); it != library.get_list_of_encyclopedias().end(); ++it) {
		std::cout
			<< std::left << std::setw(4) << std::to_string(++i) + "."
			<< std::setw(20) << (*it)->get_name()
			<< std::setw(20) << "Encyclopedia"
			<< std::setw(20) << ((*it)->get_status() ? "Yes" : "No") << std::endl;
	}
	for (auto it = library.get_list_of_fictions().begin(); it != library.get_list_of_fictions().end(); ++it) {
		std::cout
			<< std::left << std::setw(4) << std::to_string(++i) + "."
			<< std::setw(20) << (*it)->get_name()
			<< std::setw(20) << "Fiction"
			<< std::setw(20) << ((*it)->get_status() ? "Yes" : "No") << std::endl;
	}
	for (auto it = library.get_list_of_maps().begin(); it != library.get_list_of_maps().end(); ++it) {
		std::cout
			<< std::left << std::setw(4) << std::to_string(++i) + "."
			<< std::setw(20) << (*it)->get_name()
			<< std::setw(20) << "Map"
			<< std::setw(20) << ((*it)->get_status() ? "Yes" : "No") << std::endl;
	}
	std::cout << "\n0. Back to " << library.get_name() << " Admin Panel.\n";
	std::cout << "\nSelect one option: ";
}

void Application::admin_add_new_book()
{
	std::cout.width(40);
	std::cout
		<< std::internal << "Add new book" << std::endl
		<< "1. Encyclopedia.\n"
		<< "2. Fiction.\n"
		<< "3. Map.\n"
		<< "\n0. Back to " << library.get_name() << " Admin Panel.\n"
		<< "Select one option: ";
	std::cin >> choice;
	system("CLS");
	std::string name;
	std::string author;
	std::string year;
	if (choice == 1) {
		// Add Encyclopedia
		std::string topic;
		std::cout << "Enter encyclopedia's name: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		std::cout << "Enter encyclopedia's author: ";
		std::getline(std::cin, author);
		std::cout << "Enter encyclopedia's year of issue: ";
		std::cin >> year;
		std::cout << "Enter encyclopedia's topic: ";
		std::cin.ignore();
		std::getline(std::cin, topic);
		library.add_book(
			new Encyclopedia(name, author, year, &library, topic)
		);
		system("CLS");
		std::cout << "Encyclopedia was successfully added!\n" << std::flush;
	}
	else if (choice == 2) {
		// Add Novel
		std::string genre;
		std::cout << "Enter book's genre: ";
		std::cin.ignore();
		std::getline(std::cin, genre);
		std::cout << "Enter book's name: ";
		std::getline(std::cin, name);
		std::cout << "Enter book's author: ";
		std::getline(std::cin, author);
		std::cout << "Enter book's year of issue: ";
		std::cin >> year;
		library.add_book(
			new Fiction(name, author, year, &library, genre)
		);
		system("CLS");
		std::cout << genre << " was successfully added!\n" << std::flush;
	}
	else if (choice == 3) {
		// Add Map
		std::string area;
		std::string type;
		std::cout << "Enter map's name: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		std::cout << "Enter map's author: ";
		std::getline(std::cin, author);
		std::cout << "Enter map's year of issue: ";
		std::cin >> year;
		std::cout << "Enter map's area: ";
		std::cin.ignore();
		std::getline(std::cin, area);
		std::cout << "Enter map's type: ";
		std::getline(std::cin, type);
		library.add_book(
			new Map(name, author, year, &library, area, type)
		);
		system("CLS");
		std::cout << "Map was successfully added!\n" << std::flush;
	}
}

void Application::user_window()
{
	std::cout.width(40);
	std::cout
		<< std::internal << "Welcome to User Panel!" << std::endl
		<< "1. Select user.\n"
		<< "2. Create new user.\n"
		<< "\n0. Log out\n"
		<< "Select one option: ";
}

void Application::list_of_users()
{
	std::cout.width(40);
	std::cout << std::internal << "List of Users" << std::endl;
	int i = 0;
	for (auto it = users.begin(); it != users.end(); ++it)
	{
		std::cout << ++i << ". " << (*it)->get_name() << std::endl;
	}
	std::cout << "\n0. Back to User Panel.\n"
		<< "Select one option: ";
}

void Application::user_menu(User* user)
{
	std::cout.width(40);
	std::cout
		<< std::internal << "Welcome " + user->get_name() << std::endl
		<< info(user) << std::endl
		<< "\n1. Show list of library's books.\n"
		<< "2. Show list of issued books.\n"
		<< "3. Remove user.\n"
		<< "\n0. Back to list of users.\n"
		<< "Select one option: ";
}


void Application::user_list_of_issued_books(User* user)
{
	std::cout.width(40);
	std::cout << std::internal << "List of Issued Books" << std::endl;
	std::cout << std::left << std::setw(4) << "id" << std::setw(20) << "Name"
		<< std::setw(20) << "Type" << std::endl;
	int i = 0;
	for (auto it = user->get_issued_encyclopedias().begin(); it != user->get_issued_encyclopedias().end(); ++it)
	{
		std::cout
			<< std::left << std::setw(4) << std::to_string(++i) + ". "
			<< std::setw(20) << (*it)->get_name()
			<< std::setw(20) << "Encyclopedia" << std::endl;
	}
	for (auto it = user->get_issued_fictions().begin(); it != user->get_issued_fictions().end(); ++it)
	{
		std::cout
			<< std::left << std::setw(4) << std::to_string(++i) + ". "
			<< std::setw(20) << (*it)->get_name()
			<< std::setw(20) << "Fiction" << std::endl;
	}
	for (auto it = user->get_issued_maps().begin(); it != user->get_issued_maps().end(); ++it)
	{
		std::cout
			<< std::left << std::setw(4) << std::to_string(++i) + ". "
			<< std::setw(20) << (*it)->get_name()
			<< std::setw(20) << "Map" << std::endl;
	}
	std::cout << "\n0. Back to " << user->get_name() << std::endl
		<< "Select one option: ";
}

void Application::remove_user(User* user)
{
	if (user->get_issued_encyclopedias().size() || user->get_issued_fictions().size()
		|| user->get_issued_maps().size())
	{
		std::cout << "Cannot be deleted until all books have been returned.\n";
	}
	else {
		for (int i = 0; i < users.size(); ++i)
		{
			if (users[i].get() == user)
			{
				users[i].release();
				users.erase(users.begin() + i);
				choice = 0;
			}
		}
		std::cout << "User was successfully removed.\n";
	}
}

void Application::create_user()
{
	std::string name;
	std::string number;
	std::cout.width(40);
	std::cout << std::internal << "Create new User" << std::endl
		<< "Enter user's name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Enter user's phone number: ";
	std::cin >> number;
	for (auto it = users.begin(); it != users.end(); ++it)
	{
		if (name == (*it)->get_name())
			throw "Users with the same names are not allowed.";
	}
	users.emplace_back(new User(name, number));
	system("CLS");
	std::cout << "User was successfully created!\n";
}