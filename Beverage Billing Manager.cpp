#include <iostream>
#include <string>
using namespace std;

int main()
{
    // variables
    int choice;
    int qty;

    char more;
    float total = 0;
    float grandTotal = 0;

    float gst = 0;
    float finalTotal = 0;

    // customer details
    string customerName;

    // arrays to store multiple items
    string itemName[100];
    int itemQty[100];
    float itemPrice[100];
    float itemTotal[100];

    int i = 0;

    cout << "=====================================\n";
    cout << "      BEVERAGE BILLING MANAGER\n";
    cout << "=====================================\n";

    cout << "Enter Customer Name: ";
    cin >> customerName;

    // start loop
    do
    {
        cout << "\n------ MENU ------\n";
        cout << "1. Tea        - Rs 10\n";
        cout << "2. Coffee     - Rs 20\n";
        cout << "3. Juice      - Rs 30\n";
        cout << "4. Cold Drink - Rs 40\n";
        cout << "5. Milkshake  - Rs 50\n";
        cout << "6. Exit\n";
        cout << "-------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            cout << "Enter quantity: ";
            cin >> qty;

            itemQty[i] = qty;

            switch (choice)
            {
                case 1:
                    itemName[i] = "Tea";
                    itemPrice[i] = 10;
                    break;

                case 2:
                    itemName[i] = "Coffee";
                    itemPrice[i] = 20;
                    break;

                case 3:
                    itemName[i] = "Juice";
                    itemPrice[i] = 30;
                    break;

                case 4:
                    itemName[i] = "Cold Drink";
                    itemPrice[i] = 40;
                    break;

                case 5:
                    itemName[i] = "Milkshake";
                    itemPrice[i] = 50;
                    break;
            }

            // calculate item total
            itemTotal[i] = itemPrice[i] * itemQty[i];

            // add to grand total
            grandTotal = grandTotal + itemTotal[i];

            cout << "Item Added Successfully!\n";
            i++;
        }
        else if (choice == 6)
        {
            cout << "Exiting billing...\n";
            break;
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }

        cout << "Do you want to add more items? (y/n): ";
        cin >> more;

    } while (more == 'y' || more == 'Y');

    // GST only (no discount)
    gst = grandTotal * 0.05;
    finalTotal = grandTotal + gst;

    // print final bill
    cout << "\n=====================================\n";
    cout << "            FINAL BILL\n";
    cout << "=====================================\n";

    cout << "Customer Name: " << customerName << endl;
    cout << "-------------------------------------\n";

    // print all items
    for (int j = 0; j < i; j++)
    {
        cout << "Item Name : " << itemName[j] << endl;
        cout << "Price     : " << itemPrice[j] << endl;
        cout << "Quantity  : " << itemQty[j] << endl;
        cout << "Total     : " << itemTotal[j] << endl;
        cout << "-------------------------------------\n";
    }

    cout << "Grand Total : " << grandTotal << endl;
    cout << "GST (5%)    : " << gst << endl;
    cout << "Final Amount: " << finalTotal << endl;

    cout << "=====================================\n";
    cout << "Thank You! Visit Again :)\n";

    return 0;
}
