/*
 * Want to track me taking medicine every day.
 * How do I do that???
 * User input of day, time, (month)
   std::cin into an indexed array for day and time
 * Need some kind of counter
 * Writing to a file to store data. I can read it later on to see if I forgot to take meds for the day.
 * Read out the stored data based on the month
   Could use switch case with different files for each month.
   filestream with that switch case to display each month.
 * //Possibly create a calendar
 * Always remember to pre-decrement arrays based on indexing starting at 0 or start index [0] with a "0".
 * Went the pre-decrement route for practice.
*/

///--------------------------------------------Suggestions from Mikayla----------------------------------------------///
// Track medicine side effects
// frequency
// dosage
// Communication w/ Dr.
// Next refill date
// Medications that you cannot take
// When to call your Dr. (Adverse effects)
// Support Line

// Try Seekp() method for adding medicines, dates, times, etc. so everything stays organized.
// For this method I am just locating the position within the file, and then adding to existing data below it.
// I should look into the ability of modifying the data as well just in case the user messes up.

// For above comments, I could modify number_of_days_for_months function to file insert all the dates already
// on separate lines, so that way we can select a date to then go into the system to add more dates, medicine, etc.
// Using a modified version of our modify_book function in my last project, I believe I can achieve this result.

///---This is muy importante---///
// Write all the specific dates to file automatically and add an "/" and then seek with user input of the date (12/23)
// or just /23 to write into file with create user date and time function.
// reuse function in my last project
///-------------------------------------------------Suggestions End--------------------------------------------------///

#ifndef MEDICINE_TRACKER_MEDICINE_HEADER_H
#define MEDICINE_TRACKER_MEDICINE_HEADER_H

#define current_Medicine "Sertraline Titration 50 Mg"

#include <array>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstring> // For strcmpi() function. Messing around with this function again. Probably will not use.


// Global Variables to set the specific month and year that we want to work in.
int global_Var_Month = 0;
int global_Var_Year = 0;

class calendar
        {

        public:
            ///Use this function in tandem w/ global_Var_Month to use the string to open up that specific month file ///
            static std::string get_Month_Name(int);

            static int number_Of_Days_For_Months(int, int);
            static int day_Number(int, int, int);
            static void visual_Calendar_By_Year(int);

            // Visual_Cal Should also write into file along with writing out to console. This is why it was not showing
            // up in the file itself. Will work on this soon.
            static void visual_Calendar_By_Month(int, int);

            ///This should be after the login menu, but before the main menu???? not fucking sure tbh...///
            void create_Month_And_Year();


            // Overloaded Operator to handle printing out to console our visual calendar by specific month.
            /*friend std::istream& operator<<(std::istream&, calendar);*/
        };

class month:calendar
        {

        // May only need one month function to work all the other functions instead of 12 individual functions.
        public:

            ///Not sure what I want to do with this yet. Does absolutely fuck all. May get rid of it entirely.///
            static void all_Months(/*int, int*/);

            std::string token(int); //Put this token value "[x]" underneath each date to show when meds were taken.

            /// Going to need a month token to open specific month file. User input of the month/year everytime?

            friend std::ostream& operator<<(std::ostream&, month&); // Overloaded Insertion Operator.
                                                                     // Specifically for our token into a file & cout.

        };



class data_Patient:public month
        {
        private:
            std::string name_First;
            std::string name_Last;
            std::string height_In_Feet;
            std::string height_In_Inches;
            std::string email_Patient;
            std::string phone_Number_Patient;
            std::string phone_Number_Doctor;
            char current_Doctor[30];
            int weight;

            // Testing this to be utilized as a private data member.
            // Created a Get & Set function.
            std::vector <std::string> other_Medicine{}; // Vector that holds a patients other medications.


            std::vector <std::string> allergies{};  // Vector that holds allergies of a patient.

            ///--2D-Vector--///
            // I may or may not use this. What in the hell is this trickiness?

            /*std::vector<std::vector<std::string>> date_And_Time{};// {1, 2, 3}, <- could be date.
                                                                    // {4, 5, 6}  <- could be time.*/


        public:
            int create_Registration();     // Create registration to login into the main program.
            static bool isLoggedIn();      // Login program/Checks to see if you registered first.


            // Creates Patient that inserts data in private members along with a file.
            void create_Patient();

            // Reports Patient information w/in private data members.
            void patient_Report();

            // Reports date and time w/in private data members.
            void date_And_Time_Report();


            // Creates date and time data members to be placed into a file.
            void create_Date_and_Time(std::vector <std::string>&, std::vector <std::string>&);


            // Creates other medication to be placed into a file.
            void create_Other_Medicines();

            // Get/Set functions for our other_medicine private data member.
            void get_Other_Medicine();
            void set_Other_Medicine(std::string);

            // Creates Allergies to be placed into a file.
            void create_Allergies();

            // Get/Set functions for our allergy private data member.
            void get_Allergies();
            void set_Allergies(std::string);


            // Since these are public vectors, we do not need to create getter and setter functions.
            std::vector <std::string> date; // Vector that holds dates that you took your medicine.
            std::vector <std::string> time; // Vector that holds times that you took your medicine.


            // I want to toy around with the idea of an anxiety and depression questionnaire w/ (somewhat agree),
            // (absolutely agree) options. This allows the doctor to see how difficult things are given your
            // current levels of medication.

            // Could be a vector (Int depending on point scale?) depending on how I want to code this portion.
            ///Still Needs to be worked on. Nothing is done in this function.///
            std::string mood_Questionnaire();

            // May or may not need this get function with how this program functions.
            std::string get_Name_First() {return name_First;}


            ///Currently Testing///
            // void modify_function_test(); // Testing function that will modify date and time in our file.
            // int get_vector_Test(std::string); // Using for memory location to modify vector data.

}; // End Data_Patient Class.


///-Work On Menus Next-///
class menus:month
        {
        public:
            // Use Switch cases for the menus. Worked well for my last project.
            int login_Menu(); // Login Menu asking for Username and Password.

            int main_Menu();
            int patient_Menu();
            int report_Menu();
        };

///-Testing-///
class testing:public data_Patient
{
        public:
            static int test(); // Testing Derived Class.

}; // End testing Class.

#endif //MEDICINE_TRACKER_MEDICINE_HEADER_H