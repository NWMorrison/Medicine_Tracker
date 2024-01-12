#include <iostream>
#include "Medicine_Header.h"

int main()
{
    int choice;
    menus menu;
    calendar cal;


    menu.login_Menu();
    do
    {
        std::cout << "Do You Need to Create A Month and Year?:\n"
                     "1.) Yes:\n"
                     "2.) No:"   << std::endl;
        std::cin >> choice;

        if (choice == 1)
        {
            cal.create_Month_And_Year();
        }

    }while(choice != 2);

    menu.main_Menu();

    
    return 0;
}