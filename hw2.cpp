#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>


using namespace std;

int main(int argc, const char * argv[]) {
    int option;
    int choice;
    int heightFt, age;
    float heightIn, weight, salary, percSave, desSav;
    void BMI(int heightFt, float heightIn, float weight);
    void retSav(int age, float salary, float percSave, float desSav);
    void validation();
    
    while (1)
    {
        cout << "Please select one of the options you desired to do" << endl;
        cout << "1. Body Mass Index\n2. Retirement Saving Goal\n3. Exit\n\n";
        cout << "Enter 1 or 2 or 3: ";
        cin >> option;
        validation();
        
        if (option == 1)
        {
            cout << endl;
            cout <<"You have chosen Body Mass Index\n";
            while (1)
            {
                cout <<"Please enter 1 to continue, 2 to restart and 3 to exit: ";
                cin >> choice;
                validation();
                
                if (choice == 1)
                {
                    while(1)
                    {
                        cout << endl;
                        cout << "Please enter your height in feet and inches, and your weight in pounds\n";
                        cout << "Height in ft: ";
                        cin >> heightFt;
                        validation();
                        
                        cout << "Height in in: ";
                        cin >> heightIn;
                        validation();
                        
                        
                        if (heightFt <= 0 && heightIn <= 0)
                        {
                            cout << "Invalid input.\n";
                            continue;
                        }
                        cout << "Weight in lbs: ";
                        cin >> weight;
                        validation();
                         if (weight  <= 0)
                         {
                           cout << "Invalid input.\n";
                           continue;
                        }
                        cout << endl;
                        BMI(heightFt,heightIn,weight);
                        exit(0);
                    }
                }
                
                else if (choice == 2)
                {
                    break;
                }
                
                else if (choice == 3)
                {
                    exit (0);
                }
                else
                {
                    cout <<"\nInvalid input. ";
                }
            }
        }
        
        else if (option == 2)
        {
            cout << endl;
            cout << "You have chosen Retirement Saving\n";
            while (1)
            {
                cout <<"Please enter 1 to continue and 2 to restart and 3 to exit: ";
                cin >> choice;
                
                validation();
                
                if (choice == 1)
                {
                    while (1)
                    {
                        cout << endl;
                        cout << "Please enter your age: ";
                        cin >> age;
                        validation();
                        cout << "Please enter your annual salary: ";
                        cin >> salary;
                        validation();
                        cout << "Please enter percentage of salary saved: ";
                        cin >> percSave;
                        validation();
                        cout << "Please enter savings goal: ";
                        cin >> desSav;
                        validation();
                        retSav(age,salary,percSave,desSav);
                        exit(0);
                    }
                }
                else if (choice == 2)
                {
                    break;
                }
                
                else if (choice == 3)
                {
                    exit (0);
                }
                else
                {
                    cout <<"Invalid input. ";
                }
            }
        }
        else if (option == 3)
            exit(0);
        
        else
        {
            cout << "Invalid Input." << endl << endl;
            continue;
        }
        cout << endl;
        
    }
}

//BMI value calculator
void BMI(int heightFt, float heightIn, float weight)
{
    float weightKg = weight * 0.453592;
    float temp = heightFt + heightIn / 12;
    float meter = temp * 0.3048;
    float sqMeter = pow(meter, 2);
    float BMI = weightKg / sqMeter;
    cout << "Height: " << heightFt <<" feet, " << heightIn << " inches\n";
    cout << "Weight: " << weight << " pounds\n\n";
    cout << fixed << setprecision(1) << "Your BMI is " << BMI;
    if (BMI <= 18.4)
        cout << " in Underweight category\n";
    else if(BMI >= 18.5 && BMI < 25.0)
        cout << " in Normal weight category\n";
    else if (BMI >= 25.0 && BMI < 30.0)
        cout << " in Overweight category\n";
    else if (BMI >= 30.0)
        cout << " in Obese category\n";
}

//retirement savings calculator
void retSav(int age, float salary, float percSave, float desSav)
{
    float save = (percSave / 100) * salary;
    float actSave = 0.35 * save + save;
    float years = desSav / actSave;
    float totalTime = years + age;
    cout << fixed << setprecision(1);
    cout << "Total age: " << totalTime << " years" << endl;
    
    if (totalTime <= 100)
    {
        cout << "You need " << years << " more years. Savings goal will be met at the age of " << totalTime << ".\n";
    }
    
    else if (totalTime > 100)
    {
        cout << "You need " << years << " more years. Savings goal will not be met\n";
    }
    
}

//validates if the input is of right data type
void validation()
{
    while(1)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if(!cin.fail())
            break;
    }
}
