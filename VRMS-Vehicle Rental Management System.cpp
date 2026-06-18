#include <iostream>
#include <windows.h>    // For console manipulation (text color, clearing screen)
#include <algorithm>    // For string transformation
#include <vector>       // For storing rented vehicle details
#include <ctime>        // For generating random codes
#include <cstdlib>      // For random number generation

using namespace std;

// Structure to hold details of a rented vehicle
struct RentedVehicle
{
    string code;            // Unique code for the rented vehicle
    string vehicleType;     // Type of vehicle (e.g., bike, car, van)
    string color;           // Color of the vehicle
    string brand;           // Brand of the vehicle
    string model;           // Model of the vehicle
    string durationTime;    // Duration unit (hours, days, weeks)
    int duration;           // Duration of the rental
    double rentalFee;       // Total rental fee
    double advanceFee;      // Advance payment fee (50% of total)
    string paymentMethod;   // Payment method (cash or bank)
    string name;            // Renter's name
    string phoneNumber;     // Renter's phone number
    string cnic;            // Renter's CNIC (Computerized National Identity Card)
    bool returned;          // Flag indicating if the vehicle has been returned
    bool damaged;           // Flag indicating if the vehicle was returned damaged
};

// Function to clear the console screen
void clearScreen();

// Function to convert a string to lowercase
string toLowercase(string str);

// Function to generate a random 4-digit code for the rented vehicle
string generateRandomCode();

// Function to calculate the rental fee based on vehicle type, brand, model, and duration
double calculateRentalFee(const string &vehicleType, const string &brand, const string &model, const string &durationTime, int duration);

// Function to display the welcome screen with ASCII art
void displayWelcomeScreen();

// Function to display the menu options
void displayMenu();

// Function to rent a vehicle
void rentVehicle(vector<RentedVehicle> &rentedVehicles);

// Function to return a vehicle
void returnVehicle(vector<RentedVehicle> &rentedVehicles);

// Function to display details of all rented vehicles
void displayRentedVehicleDetails(const vector<RentedVehicle> &rentedVehicles);

// Function to clear the console screen and display welcome screen and menu
void clearScreen()
{
    system("cls");
    displayWelcomeScreen();
    displayMenu();
}

// Function to convert a string to lowercase
string toLowercase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to generate a random 4-digit code for the rented vehicle
string generateRandomCode()
{
    string code = "";
    const string charset = "0123456789";
    const int codeLength = 4;
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < codeLength; ++i)
    {
        code += charset[rand() % charset.length()]; // Append a random digit from charset
    }
    return code;
}

// Function to calculate the rental fee based on vehicle type, brand, model, and duration
double calculateRentalFee(const string &vehicleType, const string &brand, const string &model, const string &durationTime, int duration)
{
    // Base rate for different vehicle types
    double baseRate = 0.0;
    if (vehicleType == "bike")
    {
        baseRate = 50.0;
    }
    else if (vehicleType == "car")
    {
        baseRate = 100.0;
    }
    else if (vehicleType == "van")
    {
        baseRate = 150.0;
    }

    // Additional charges based on brand and model
    if (brand == "honda")
    {
        baseRate += 15.0;
    }
    else if (brand == "ford")
    {
        baseRate += 35.0;
    }

    if (model == "sport")
    {
        baseRate += 50.0;
    }
    else if (model == "suv")
    {
        baseRate += 75.0;
    }

    // Adjust base rate based on duration and duration unit
    if (durationTime == "hours")
    {
        baseRate *= duration;
    }
    else if (durationTime == "days")
    {
        baseRate *= (duration * 24);
    }
    else if (durationTime == "weeks")
    {
        baseRate *= (duration * 24 * 7);
    }

    return baseRate;
}

// Function to display the welcome screen with ASCII art
void displayWelcomeScreen()
{
	// Set text color for welcome message
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    
    // Display welcome message with ASCII art
    cout << "===================================================" << endl;
    cout << "   Welcome to the Vehicle Rental Management System   " << endl;
    cout << "===================================================" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "   /$$    /$$ /$$$$$$$  /$$      /$$  /$$$$$$ " << endl;
    cout << "  | $$   | $$| $$__  $$| $$$    /$$$ /$$__  $$" << endl;
    cout << "  | $$   | $$| $$  \\ $$| $$$$  /$$$$| $$  \\__/" << endl;
    cout << "  |  $$ / $$/| $$$$$$$/| $$ $$/$$ $$|  $$$$$$ " << endl;
    cout << "   \\  $$ $$/ | $$__  $$| $$  $$$| $$ \\____  $" << endl;
    cout << "    \\  $$$/  | $$  \\ $$| $$\\  $ | $$ /$$  \\ $" << endl;
    cout << "     \\  $/   | $$  | $$| $$ \\/  | $$|  $$$$$$/" << endl;
    cout << "      \\_/    |__/  |__/|__/     |__/ \\______/ " << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "===================================================" << endl;
}

    // Function to display the menu options
    void displayMenu()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        cout << "=================" << endl;
        cout << "   Menu Options  " << endl;
        cout << "=================" << endl;
        cout << "1. Rent a Vehicle" << endl;
        cout << "2. Return a Vehicle" << endl;
        cout << "3. Rented Vehicle Details" << endl; 
        cout << "4. Exit" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }

    // Function to rent a vehicle
    void rentVehicle(vector<RentedVehicle> &rentedVehicles)
    {
        // Console text color setup
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                         
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); 

        // Display terms and conditions
        cout << "\nTerms and Conditions:\n" << endl;
        cout << " > 50% advance payment is required." << endl;
        cout << " > Damage coverage is available with additional charges." << endl;
        cout << " > Vehicles must be returned in the same condition." << endl;

        string agree;
        do
        {
            // Ask for agreement to terms and conditions
            cout << "\nDo you agree to the terms and conditions? (yes/no): ";
            cin >> agree;
            agree = toLowercase(agree);
        } while (agree != "yes" && agree != "no");

        clearScreen();
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); 

        if (agree == "yes")
        {
            // Display available vehicle types
            cout << "\nAvailable Vehicle Types to Rent:\n" << endl;
            cout << " > Bike" << endl;
            cout << " > Car" << endl;
            cout << " > Van" << endl;

            string vehicleType;
            do
            {
                // Ask for the chosen vehicle type
                cout << "\nPlease choose a vehicle type (bike/car/van): ";
                cin >> vehicleType;
                vehicleType = toLowercase(vehicleType);
            } while (vehicleType != "bike" && vehicleType != "car" && vehicleType != "van");

            clearScreen();
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

            if (vehicleType == "bike")
            {
                // Display available options for bike
                cout << "\nAvailable Colors --> Red, Blue, Green" << endl;
                cout << "Available Brands --> Honda, Yamaha, Suzuki" << endl;
                cout << "Available Models --> Sport, Cruiser, Dirt" << endl;
            }
            else if (vehicleType == "car")
            {
                // Display available options for car
                cout << "\nAvailable Colors --> Black, White, Silver" << endl;
                cout << "Available Brands -->  Toyota, Honda, Ford" << endl;
                cout << "Available Models --> Sedan, SUV, Hatchback" << endl;
            }
            else if (vehicleType == "van")
            {
                // Display available options for van
                cout << "\nAvailable Colors --> Blue, Gray, Red" << endl;
                cout << "Available Brands --> Ford, Volkswagen, Mercedes-Benz" << endl;
                cout << "Available Models --> Cargo, Passenger, Minivan" << endl;
            }

            string color, brand, model;
            bool validChoices = false;
            while (!validChoices)
            {
                // Ask for vehicle color, brand, and model
                cout << "\nChoose a color: ";
                cin >> color;
                cout << "Choose a brand: ";
                cin >> brand;
                cout << "Choose a model: ";
                cin >> model;

                color = toLowercase(color);
                brand = toLowercase(brand);
                model = toLowercase(model);

                // Validate user choices based on vehicle type
                bool validColor = false, validBrand = false, validModel = false;

                // Validate color based on the chosen vehicle type
                if (vehicleType == "bike")
                {
                    validColor = (color == "red" || color == "blue" || color == "green");
                }
                else if (vehicleType == "car")
                {
                    validColor = (color == "black" || color == "white" || color == "silver");
                }
                else if (vehicleType == "van")
                {
                    validColor = (color == "blue" || color == "gray" || color == "red");
                }

                // Validate brand based on the chosen vehicle type
                if (vehicleType == "bike")
                {
                    validBrand = (brand == "honda" || brand == "yamaha" || brand == "suzuki");
                }
                else if (vehicleType == "car")
                {
                    validBrand = (brand == "toyota" || brand == "honda" || brand == "ford");
                }
                else if (vehicleType == "van")
                {
                    validBrand = (brand == "ford" || brand == "volkswagen" || brand == "mercedes-benz");
                }

                // Validate model based on the chosen vehicle type
                if (vehicleType == "bike")
                {
                    validModel = (model == "sport" || model == "cruiser" || model == "dirt");
                }
                else if (vehicleType == "car")
                {
                    validModel = (model == "sedan" || model == "suv" || model == "hatchback");
                }
                else if (vehicleType == "van")
                {
                    validModel = (model == "cargo" || model == "passenger" || model == "minivan");
                }

                if (validColor && validBrand && validModel)
                {
                    validChoices = true;
                }
                else
                {
                    cout << "Invalid choice for color, brand, or model. Please try again." << endl;
                }
            }

            clearScreen();
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); 

            // Convert user's input to lowercase for case-insensitive comparison
            color = toLowercase(color);
            brand = toLowercase(brand);
            model = toLowercase(model);

            // Ask for duration and duration unit
            string durationTime;
            do
            {
                cout << "\nPlease choose the duration time (hours/days/weeks): ";
                cin >> durationTime;
                durationTime = toLowercase(durationTime);
            } while (durationTime != "hours" && durationTime != "days" && durationTime != "weeks");

            int duration;
            cout << "Enter the duration in " << durationTime << ": ";
            cin >> duration;

            clearScreen();
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

            // Calculate rental fee
            double rentalFee = calculateRentalFee(vehicleType, brand, model, durationTime, duration);

            // Calculate 
            // Calculate 50% advance fee
            double advanceFee = rentalFee * 0.5;

            // Generate a random code for the rented vehicle
            string code = generateRandomCode();

            cout << "\nTotal Fee: Rs." << rentalFee << endl;
            cout << "Advance Fee (50%): Rs." << advanceFee << endl;
            cout << "Rental Code: " << code << endl;

            // Ask if the user wants to proceed with payment
            string proceed;
            do
            {
                cout << "\nDo you want to proceed with payment? (yes/no): ";
                cin >> proceed;
                proceed = toLowercase(proceed);
            } while (proceed != "yes" && proceed != "no");

            clearScreen();
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

            if (proceed == "yes")
            {
                // Choose a payment method
                string paymentMethod;
                do
                {
                    cout << "\nChoose a payment method (cash/bank): ";
                    cin >> paymentMethod;
                    paymentMethod = toLowercase(paymentMethod);
                } while (paymentMethod != "cash" && paymentMethod != "bank");

                clearScreen();
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

                // Get contact details
                string name, phoneNumber, cnic;
                cout << "\nPlease provide your contact details:" << endl;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                do
                {
                    cout << "Phone Number (11 digits): ";
                    cin >> phoneNumber;
                } while (phoneNumber.length() != 11 || !all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit));
                do
                {
                    cout << "CNIC (13 digits): ";
                    cin >> cnic;
                } while (cnic.length() != 13 || !all_of(cnic.begin(), cnic.end(), ::isdigit));

                // Store rented vehicle details
                RentedVehicle rentedVehicle = {code, vehicleType, color, brand, model, durationTime, duration, rentalFee, advanceFee, paymentMethod, name, phoneNumber, cnic, false, false};
                rentedVehicles.push_back(rentedVehicle);

                cout << "\nThank you, " << name << "! Your payment has been processed." << endl;
            }
            else
            {
                cout << "\nThank you for visiting. Have a great day!" << endl;
            }
        }
        else
        {
            cout << "\nThank you for visiting. Have a great day!" << endl;
        }

        // Reset text color to default
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }

    // Function to return a vehicle
    void returnVehicle(vector<RentedVehicle> &rentedVehicles)
    {
        // Console text color setup
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED); 

        // Ask for vehicle details
        string returnedCode;
        cout << "\nEnter the code of the returned vehicle: ";
        cin >> returnedCode;

        // Search for the rented vehicle in the list
        auto it = rentedVehicles.begin();
        bool found = false;
        while (it != rentedVehicles.end())
        {
            // Check if the returned code matches the rented vehicle code
            if ((*it).code == returnedCode)
            {
                found = true;
                // Assess for damages and duration
                cout << "\nIs the returned vehicle damaged? (yes/no): ";
                string damageResponse;
                cin >> damageResponse;
                damageResponse = toLowercase(damageResponse);
                while (damageResponse != "yes" && damageResponse != "no")
                {
                    cout << "Invalid input. Please enter 'yes' or 'no': ";
                    cin >> damageResponse;
                    damageResponse = toLowercase(damageResponse);
                }
                (*it).damaged = (damageResponse == "yes");

                // Calculate the total rental fee
                double totalFee = (*it).rentalFee;

                if ((*it).damaged)
                {
                    double damageFee = 1000.0; 
                    cout << "\nExtra fee for damages: Rs." << damageFee << endl;
                    totalFee += damageFee;
                }

                if ((*it).durationTime == "hours" && (*it).duration > 24)
                {
                    cout << "\nThe vehicle has been returned after the agreed duration." << endl;
                    double extraFee = 0.1 * totalFee;
                    cout << "\nExtra fee for returning after the duration: Rs." << extraFee << endl;
                    totalFee += extraFee;
                }
                else if ((*it).durationTime == "days" && (*it).duration > 7)
                {
                    cout << "\nThe vehicle has been returned after the agreed duration." << endl;
                    double extraFee = 0.1 * totalFee; 
                    cout << "\nExtra fee for returning after the duration: Rs." << extraFee << endl;
                    totalFee += extraFee;
                }
                else if ((*it).durationTime == "weeks" && (*it).duration > 1)
                {
                    cout << "\nThe vehicle has been returned after the agreed duration." << endl;
                    double extraFee = 0.1 * totalFee; 
                    cout << "\nExtra fee for returning after the duration: Rs." << extraFee << endl;
                    totalFee += extraFee;
                }
                else
                {
                    cout << "\nThe vehicle has been returned within the agreed duration." << endl;
                }

                // Calculate remaining fee after deducting the advance fee
                double remainingFee = totalFee - (*it).advanceFee;

                // Ask for payment method
                string paymentMethod;
                cout << "\nThe remaining fee to be paid is: Rs." << remainingFee << endl;
                cout << "\nPlease pay the remaining fee through cash or bank: ";
                cin >> paymentMethod;
                paymentMethod = toLowercase(paymentMethod);
                while (paymentMethod != "cash" && paymentMethod != "bank")
                {
                    cout << "\nInvalid payment method. Please enter 'cash' or 'bank': ";
                    cin >> paymentMethod;
                    paymentMethod = toLowercase(paymentMethod);
                }
                cout << "\nPayment successful. Thank you!" << endl;

                (*it).returned = true;
                (*it).duration = 0; 

                // Remove the returned vehicle from the list
                it = rentedVehicles.erase(it);
                break;
            }
            else
            {
                ++it;
            }
        }

        if (!found)
        {
            cout << "\nThe returned vehicle was not found in the rented vehicle list." << endl;
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }

    // Function to display rented vehicle details
    void displayRentedVehicleDetails(const vector<RentedVehicle> &rentedVehicles)
    {
        // Console text color setup
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                    
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN); 
		
        cout << "================================" << endl;
        cout << "      Rented Vehicle Details    " << endl;
        cout << "================================" << endl;

        // Display rented vehicle details
        for (const auto &rentedVehicle : rentedVehicles)
        {

            cout << "\nVehicle Code:     " << rentedVehicle.code << endl;
            cout << "Vehicle Type:     " << rentedVehicle.vehicleType << endl;
            cout << "Color:            " << rentedVehicle.color << endl;
            cout << "Brand:            " << rentedVehicle.brand << endl;
            cout << "Model:            " << rentedVehicle.model << endl;
            cout << "Duration:         " << rentedVehicle.duration << " " << rentedVehicle.durationTime << endl;

            cout << "................................." << endl;

            cout << "Total Fee:        Rs." << rentedVehicle.rentalFee << endl;
            cout << "Advance Fee :     Rs." << rentedVehicle.advanceFee << endl;
            cout << "Payment Method:   " << rentedVehicle.paymentMethod << endl;

            cout << "................................." << endl;

            cout << "Renter's Name:    " << rentedVehicle.name << endl;
            cout << "Phone Number:     " << rentedVehicle.phoneNumber << endl;
            cout << "CNIC:             " << rentedVehicle.cnic << endl;

            cout << "\n================================" << endl;
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }

    int main()
    {
        displayWelcomeScreen();
        string choice;
        vector<RentedVehicle> rentedVehicles;

        do
        {
            displayMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (stoi(choice))
            {
            case 1:
                rentVehicle(rentedVehicles);
                break;
            case 2:
                returnVehicle(rentedVehicles);
                break;
            case 3:
                displayRentedVehicleDetails(rentedVehicles);
                break;
            case 4:
                cout << "\nExiting the system. Thank you!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please enter a valid option." << endl;
            }

            cout << "\nPress any key to continue...";
            cin.ignore();
            cin.get(); // acessing character array including spaces
            system("cls");
            displayWelcomeScreen();
        } while (choice != "4");

        return 0;
    }

