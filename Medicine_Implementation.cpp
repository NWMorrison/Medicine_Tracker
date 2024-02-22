#include "Medicine_Header.h"
#include <iostream>

///------------------------------------------------------------------------------------------------------------------///
///--------------------------------------------Initialized Objects---------------------------------------------------///
data_Patient data;
month m;
menus menu;
calendar cal;
testing tst;


///------------------------------------------Initialized Objects End-------------------------------------------------///
///------------------------------------------------------------------------------------------------------------------///




///------------------------------------------------------------------------------------------------------------------///
///--------------------------------------------Class Calendar Start--------------------------------------------------///
std::string calendar::get_Month_Name(int month_Number)
{
    try
    {
        if (month_Number > 0 && month_Number <= 12)
        {
            std::string month[] =
                    {
                            "January","February","March","April","May","June",
                            "July","August","September","October","November",
                            "December"
                    };
            return (month[--month_Number]);
        }
        else
        {
            throw (month_Number);
        }
    }
    catch(int thrown_Num)
    {
        std::cout << "Your input of " << thrown_Num << " is invalid for a month. Exception caught.";
        exit(-1);
    }
}


int calendar::number_Of_Days_For_Months(int month_Number, int year)
{
    int days_By_Month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month_Number == 2)
    {
        --month_Number;
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            return 29;
        }
        else
        {
            return (days_By_Month[month_Number]);
        }
    }
    else
    {
        return (days_By_Month[--month_Number]);
    }
}


int calendar::day_Number(int day, int month, int year)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}


void calendar::visual_Calendar_By_Year(int year)
{
    std::cout << "\t Calendar - " << year << std::endl;
    int days;

    // Index of the day from 0 to 6
    int current = day_Number(1, 1, year);

    // i --> Iterate through all the months
    // j --> Iterate through all the days of the
    //       month - i
    for (int i = 1; i < 13; i++)
    {
        days = number_Of_Days_For_Months (i, year);

        // Print the current month name
        // For singular months, get_Month_Name() & number_Of_Days_For_Months() must be set to the month day
        std::cout << "\n\t-----" << get_Month_Name(i) << "-----\n";

        // Print the columns
        std::cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++)
        {
            std::cout << "     ";
        }

        //This is where token manipulation can go for each date.
        for (int j = 1; j <= days; j++)
        {
            std::cout << std::setw(5) << j;// This line -> use for token manipulation.
            //std::cout << token(1);

            if (++k > 6)
            {
                k = 0;
                std::cout << "\n";
            }
        }

        if (k)
            std::cout << "\n";

        current = k;
    }
}


void calendar::visual_Calendar_By_Month(int month, int year)
{
        std::cout << "\t Calendar - " << year << std::endl;
        int days;

        // Index of the day from 0 to 6
        int current = day_Number(1, month, year);

        // i --> Iterate through the month
        // j --> Iterate through all the days of the
        //       month - i
        for (int i = 1; i < 2; i++)
        {
            days = number_Of_Days_For_Months(month, year);

            // Print the current month name
            // For singular months, get_Month_Name() & number_Of_Days_For_Months() must be set to the month day
            std::cout << "\n\t-----" << get_Month_Name(month) << "-----\n";

            // Print the columns
            std::cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

            // Print appropriate spaces
            int k;
            for (k = 0; k < current; k++)
            {
                std::cout << "     ";
            }

            //This is where token manipulation can go for each date.
            for (int j = 1; j <= days; j++)
            {
                std::cout << std::setw(5) << j;// This line -> use for token manipulation.
                //std::cout << token(1);

                if (++k > 6)
                {
                    k = 0;
                    std::cout << "\n";
                }
            }
            if (k)
                std::cout << "\n";

            current = k;
        }
}

void calendar::create_Month_And_Year()
{
    std::cout << "Enter the Month Number (Jan = 1, Feb = 2, Etc.):" << std::endl;
    std::cin >> global_Var_Month;
    std::cout << "Enter The Year Number (2020, 2021, Etc.):" << std::endl;
    std::cin >> global_Var_Year;
}
///--------------------------------------------Class Calendar End----------------------------------------------------///
///------------------------------------------------------------------------------------------------------------------///




///------------------------------------------------------------------------------------------------------------------///
///--------------------------------------------Class Months Start----------------------------------------------------///
// This actually does fuck all right now. Probably will not use this function. We will see.
void month::all_Months(/*int month, int year*/)
{
    // Switch case in each month function for a menu to write and modify information.
    // Option to write days & time you have taken your medicine.
    // Option to report the visual calendar w/ and w/o the tokens after writing.
    visual_Calendar_By_Month(1,2024);
}


// Work this into a virtual function
std::string month::token(int token)
{
    if (token == 0)
    {
        return "[]";
    }
    else if (token == 1)
    {
        return "[x]";
    }
    else
    {
        return "";
    }
}

// Overloaded Insertion Operator
std::ostream& operator<<(std::ostream& cout, month& obj)
{
    return  cout << obj.token(1);
}
///--------------------------------------------Class Months End------------------------------------------------------///
///------------------------------------------------------------------------------------------------------------------///





///------------------------------------------------------------------------------------------------------------------///
///--------------------------------------------Class Patient Start---------------------------------------------------///
void data_Patient::patient_Report()
{
    std::cout << name_First << " " << name_Last << std::endl << height_In_Feet << "ft " << height_In_Inches << "in "
              << std::endl << weight << " lbs" << std::endl;
    std::cout << current_Medicine;
}

bool data_Patient::isLoggedIn()
{
    std::string username, password;
    std::string un, pw;


    std::cout << "Enter a Username: " << std::endl;
    std::cin >> username;

    std::cout << "Enter a Password: " << std::endl;
    std::cin >> password;


    std::ifstream read(username + ".txt");
    std::getline(read, un);
    std::getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int data_Patient::create_Registration()
{

    std::string username, password;

    std::cout << "[Registration]" << std::endl << "Select a Username: " << std::endl;
    std::cin >> username;

    std::cout << "Select a Password: " << std::endl;
    std::cin >> password;

    std::ofstream file;
    file.open(username + ".txt");
    file << username << std::endl << password << std::endl;
    file.close();
    std::cout << "Welcome " << username << "!" << "\nRegistration Successful.." << std::endl;

    return menu.login_Menu();
}

void data_Patient::create_Patient()
{
    std::cout << "\nPatient Creation:\n"
                 "What is your First Name:\n";
    std::cin >> name_First;
    std::cout << "What is your Last Name:\n";
    std::cin >> name_Last;
    std::cout << "Approximate Height Starting With Feet:\n";
    std::cin >> height_In_Feet;
    std::cout << "Now Your Inches:\n";
    std::cin >> height_In_Inches;
    std::cout << "Approximate Weight:\n";
    std::cin >> weight;



    std::cout << "Enter Your Current Telephone Number: \n";
    std::cin >> phone_Number_Patient;
    std::cout << "Enter Your Email Address: \n";
    std::cin >> email_Patient;

    std::cout << "Please Enter Your Current Main Care Physician: \n";
    std::cin.ignore();
    std::cin.getline(current_Doctor,30);

    std::cout << "Enter Their Phone Number: \n";
    std::cin >> phone_Number_Doctor;

    /// When you are reading all of this information into this file...///
    /// You can setw() to actually format the .txt document to look much neater///
    std::ofstream file;

    file.open((name_First + ".txt") , std::ios::in|std::ios::app);

    file << "---Patient Information---" << std::endl
         << name_First << " " << name_Last << std::endl
         << height_In_Feet << "ft " << height_In_Inches << "in " << std::endl
         << weight << " lbs" << std::endl
         << "---Patient Telephone Number---" << std::endl
         << phone_Number_Patient << std::endl
         << "---Email Address---" << std::endl
         << email_Patient << std::endl
         << "---Current Medication---" << std::endl
         << current_Medicine << std::endl

         << std::endl << "---Current Doctor---" << std::endl
         << current_Doctor << std::endl
         << "Doctor Telephone Number---" << std::endl
         << phone_Number_Doctor << std::endl
         ;

    file.close();

    std::cout << "Patient Created Successfully!" << std::endl;
}


void data_Patient::create_Date_and_Time(std::vector<std::string>& user_date,std::vector<std::string>& user_time)
{
    std::string answer_date;
    char answer_time[12];

    int choice;

    /*std::cout << "\nPlease Enter Your Name: \n"; // This will probably be changed into asking for the month.
    std::cin >> name;                            // This allows for separate files to be made based off month.*/

    std::ofstream file;

    file.open((name_First + ".txt"), std::ios::in|std::ios::app);
    do
    {
        // This for loop pushes user input into our data & time vectors.
        for (int i = 0; i < 1; i++)
        {
            std::cout << std::endl;
            std::cout << "Enter the date of the medicine taken:\n";
            std::cin >> answer_date;
            user_date.push_back(answer_date);
            std::cout << std::endl;
            std::cout << "Enter the time you took your medicine: " << std::endl;
            std::cin.ignore();
            std::cin.getline(answer_time,12);
            user_time.emplace_back(answer_time);
        }

        std::cout << "\nPress 1 to add another date and time."
                     "\nPress 2 to return to the main menu."
                     "\nEnter: \n";

        std::cin >> choice;

    }while (choice == 1);



    // File error handling.
    if (!file)
    {
        std::cout << "Error Opening The File.\n";
    }

    else
    {
        file << std::endl << "---Day/Time Medication Taken---" << std::endl;

        // This for loop inserts our vector values of date & time into our file.
        // May not need the nested for-loop with this. Need to test but I believe I can remove.
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < user_date.size() && j < user_time.size(); j++)
            {
                // Test set-precision() with [x] to make it neat in the file.
                file << user_date[j] << " " << user_time[j] << " " << "[x]" << std::endl;
            }
        }
    }
    file.close();
}


void data_Patient::create_Other_Medicines()
{
    std::string name;
    int choice;
    char medicine[20];

    /*std::cout << "\nPlease Enter Your Name: \n"; // This will probably be changed into asking for the month.
    std::cin >> name;                            // This allows for separate files to be made based off month.*/

    std::ofstream file;

    file.open((name_First + ".txt"), std::ios::in|std::ios::app);
    do
    {
        for (int i = 0; i < 1; i++)
        {
            std::cout << std::endl;
            std::cout << "Enter Each Medication you take" << std::endl;
            std::cin.ignore();
            std::cin.getline(medicine,20);
            data.set_Other_Medicine(medicine);
            // other_Medicine.emplace_back(medicine);
        }



        std::cout << "\nPress 1 to add another Medicine."
                     "\nPress 2 to return to the main menu."
                     "\nEnter: \n";

        std::cin >> choice;

    }while (choice == 1);


    // File error handling.
    if (!file)
    {
        std::cout << "Error Opening The File.\n";
    }

    else
    {
        file << std::endl << "---Other Medication---" << std::endl;
        // This for loop inserts our vector values of date & time into our file.
        for (int i = 0; i < 1; i++)
        {
            for (const auto & j : other_Medicine)
            {
                file << j << std::endl;
            }
        }
    }
    file.close();
}


void data_Patient::date_And_Time_Report() // Prints to console our 2 vectors of date And Time
{
    for (int i = 0; i < date.size() && i < time.size(); i++)
    {
        std::cout << std::setprecision(1) << date[i] << " " << time[i] << " " << m.token(1) << std::endl;
    }
}


void data_Patient::get_Other_Medicine()
{
    for (const auto & i : other_Medicine)
    {
        std::cout << i  << std::endl;
    }
}


void data_Patient::set_Other_Medicine(std::string medicine)
{
    other_Medicine.emplace_back(medicine);
}


void data_Patient::get_Allergies()
{
    for (const auto & i : allergies)
    {
        std::cout << i << std::endl;
    }
}


void data_Patient::set_Allergies(std::string allergy)
{
    allergies.emplace_back(allergy);
}


std::string data_Patient::mood_Questionnaire()
{return "";}


void data_Patient::create_Allergies()
{
    std::string name;
    int choice;
    char allergy[20];

    std::cout << "\nPlease Enter Your Name: \n"; // This will probably be changed into asking for the month.
    std::cin >> name;                            // This allows for separate files to be made based off month.

    std::ofstream file;

    file.open((name_First + ".txt"), std::ios::in|std::ios::app);
    do
    {
        // This for loop pushes user input into our data & time vectors.
        for (int i = 0; i < 1; i++)
        {
            std::cout << std::endl;
            std::cout << "Enter Each Medication you take" << std::endl;
            std::cin.ignore();
            std::cin.getline(allergy,20);
            data.set_Allergies(allergy);
            // allergies.emplace_back(allergy);
        }


        std::cout << "\nPress 1 to add more Allergies."
                     "\nPress 2 to return to the main menu."
                     "\nEnter: \n";

        std::cin >> choice;

    }while (choice == 1);


    // File error handling.
    if (!file)
    {
        std::cout << "Error Opening The File.\n";
    }
    else
    {
        file << std::endl << "---Allergies---" << std::endl;
        // This for loop inserts our vector values of date & time into our file.
        for (int i = 0; i < 1; i++)
        {
            for (const auto & j : allergies)
            {
                file << j << std::endl;
            }
        }
    }
    file.close();
}
///--------------------------------------------Class Patient End-----------------------------------------------------///
///------------------------------------------------------------------------------------------------------------------///





///------------------------------------------------------------------------------------------------------------------///
///--------------------------------------------Class Tests Start----------------------------------------------------///
// Testing Derived Classes
int testing::test()
{
    all_Months();
    return 0;
}

///Testing modifying data from our file.///
/*void data_Patient::modify_function_test()
{
    std::string n;
    int found = 0;

    std::cout << "Modify Data and Time: \n"
                 "Enter The Date you want to modify: (Example 1/2, 12/23, 4/28)" << std::endl;
    std::cin >> n;

    std::fstream file;

    // I believe the program runs into an error here, try moving the function into data_patient class and using
    // name_first pvt data member to properly open the file.
    file.open((name_First + ".txt"),std::ios::in|std::ios::out);

    std::cout << "Test";

    int marker = tst.get_vector_Test(n);

    while(file.read((char*)&data, sizeof(data_Patient)) && found == 0)
    {
        if (marker == 0)
        {
            std::cout << "\n\t\t  Enter The New Details: " << std::endl;
            data.create_Date_and_Time(data.date,data.time);
            int position = -1*sizeof(data_Patient);
            file.seekp(position, std::ios::cur);
            file.write((char*)&data,sizeof(data_Patient));
            std::cout << "\n\t\t  Record Updated Successfully: ";
            found = 1;
        }
    }

    file.close();

    if (found == 0)
    {
        std::cout << "\n\t\t  Record Does Not Exist: ";
    }
}*/

///Currently Testing///
/*int data_Patient::get_vector_Test(std::string test)
{
    for (int i = 0; i < date.size(); i++)
    {
        if (date[i] == test)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}*/
///---------------------------------------------Class Tests End------------------------------------------------------///
///------------------------------------------------------------------------------------------------------------------///





///------------------------------------------------------------------------------------------------------------------///
///--------------------------------------------Class Menus Start-----------------------------------------------------///
int menus::login_Menu()
{
    int choice;

    std::cout << std::setw(25) << "Login Menu: \n" << std::setw(27) << "-----------------\n";
    std::cout << std::setw(26) << "1.) Registration: \n"
              << std::setw(18) << "2.) Login: " << std::endl;
    std::cout << std::setw(16) << "3.) Exit:" << std::endl;
    std::cout << std::setw(27) << "--Pick A Choice--\n";

    std::cin >> choice;

    if (choice == 1)
    {
        data.create_Registration();
    }

    else if (choice == 2)
    {

        bool status = data.isLoggedIn();

        if (!status)
        {
            std::cout << "Error, Invalid Login!" << std::endl;
            return login_Menu();
        }
        else
        {
            std::cout << "Successfully Logged In!" << std::endl;
            return 0;
        }
    }

    else if (choice == 3)
    {
        std::cout << "Exiting The Program" << std::endl;
        exit(0);
    }

    else
    {
        std::cout << "Invalid Input. Please Try Again" << std::endl;
        return menu.login_Menu();
    }

    return 0;
}


int menus::main_Menu()
{
    int choice;
    std::cout << "Main Menu\n"
                 "Choose an Option:\n";

    ///Add console out options///


    std::cin >> choice;
    switch(choice)
    {
        case 1:
            menu.patient_Menu();
            break;
        case 2:
            menu.report_Menu();
            break;
        case 3:
            menu.login_Menu();
            break;
        default:
            exit(0);
    }

    return 0;
}


int menus::patient_Menu()
{


    int choice;
    std::cout << "Main Menu\n"
                 "Choose an Option:\n";


    ///Add console out options///

    std::cin >> choice;
    switch(choice)
    {
        case 1:
            data.create_Patient();
            break;
        case 2:
            data.create_Date_and_Time(data.date,data.time);
            break;
        case 3:
            data.create_Other_Medicines();
            break;
        case 4:
            data.create_Allergies();
            break;
        case 5:
            data.mood_Questionnaire();
            break;
        default:
            menu.main_Menu();
            break;
    }

    return 0;
}



int menus::report_Menu()
{
    int choice;
    std::cout << "Main Menu\n"
                 "Choose an Option:\n";


    ///Add console out options///

    std::cin >> choice;
    switch(choice)
    {
        case 1:
            data.patient_Report();
            break;
        case 2:
            // Visual_Cal Should also write into file along with writing out to console. This is why it was not showing
            // up in the file itself. Will work on this soon.
            cal.visual_Calendar_By_Month(global_Var_Month,global_Var_Year);
            data.date_And_Time_Report();
            break;
        case 3:
            data.get_Other_Medicine();
            break;
        case 4:
            data.get_Allergies();
            break;
        case 5:
            cal.visual_Calendar_By_Year(global_Var_Year);
            break;
        case 6:
            menu.main_Menu();
        default:
            break;
    }

    return 0;
}
///----------------------------------------------Class Menus End-----------------------------------------------------///
///------------------------------------------------------------------------------------------------------------------///