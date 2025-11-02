#include <stdio.h>
#include <string.h>

void getCustomerInfo(char name[], char cnic[]);
void displayInventory(int CodeNumber[], int quantity[], int price[], int size);
void addToCart(int CodeNumber[], int quantity[], int price[], int cartCode[], int CartQuantity[], int *cartCount, int size);
float calculateBill(int CodeNumber[], int price[], int cartCode[], int CartQuantity[], int cartCount, int size);
float applyPromo(float total);
void showInvoice(char name[], char cnic[], float total, float NewDiscounted);
void updateInventory(int CodeNumber[], int quantity[], int cartCode[], int CartQuantity[], int cartCount, int size);

int main() {
  
    char name[50], cnic[20];
    int CodeNumber[] = {1, 2, 3, 4};
    int quantity[] = {50, 10, 20, 8};
    int price[] = {100, 200, 300, 150};
    int cartCode[50], CartQuantity[50], cartCount = 0;
    int choice;
    float total = 0, NewDiscounted = 0;
    int size = 4;

    do {
      
        printf("\nSupermarket Menu\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Please Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
          
            case 1:
                getCustomerInfo(name, cnic);
                break;
          
            case 2:
                displayInventory(CodeNumber, quantity, price, size);
                break;
          
            case 3:
                addToCart(CodeNumber, quantity, price, cartCode, CartQuantity, &cartCount, size);
                updateInventory(CodeNumber, quantity, cartCode, CartQuantity, cartCount, size);
                break;
          
            case 4:
                total = calculateBill(CodeNumber, price, cartCode, CartQuantity, cartCount, size);
                NewDiscounted = applyPromo(total);
                break;
          
            case 5:
                showInvoice(name, cnic, total, NewDiscounted);
                break;
          
            case 6:
                printf("Exiting...\n");
                break;
          
            default:
                printf("Invalid choice. Please Try Again.\n");
          
        }
    } while (choice != 6);

    return 0;
  
}

void getCustomerInfo(char name[], char cnic[]) {
  
    printf("Enter customer name: ");
    scanf(" %[^\n]", name);
    printf("Enter CNIC number: ");
    scanf(" %[^\n]", cnic);
}

void displayInventory(int CodeNumber[], int quantity[], int price[], int size) {
  
    printf("\nProduct Code\tQuantity in Stock\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%03d\t\t%d\t\t\t%d\n", CodeNumber[i], quantity[i], price[i]);
      
    }
}

void addToCart(int CodeNumber[], int quantity[], int price[], int cartCode[], int CartQuantity[], int *cartCount, int size) {
  
    int inputCode, qty, found = 0;

    printf("Enter product code to add: ");
    scanf("%d", &inputCode);

    for (int i = 0; i < size; i++) {
      
        if (CodeNumber[i] == inputCode) {
          
            found = 1;
            printf("Enter quantity: ");
            scanf("%d", &qty);

            if (qty <= quantity[i]) {
              
                cartCode[*cartCount] = inputCode;
                CartQuantity[*cartCount] = qty;
                (*cartCount)++;
                printf("Item added to cart!\n");
              
            } else {
                printf("Not enough stock available!\n");
            }
            break;
        }
    }

    if (!found) {
      
        printf("Product not found.\n");
    }
}

void updateInventory(int CodeNumber[], int quantity[], int cartCode[], int CartQuantity[], int cartCount, int size) {
  
    for (int i = 0; i < cartCount; i++) {
      
        for (int j = 0; j < size; j++) {
          
            if (cartCode[i] == CodeNumber[j]) {
                quantity[j] -= CartQuantity[i];
              
            }
        }
    }
}

float calculateBill(int CodeNumber[], int price[], int cartCode[], int CartQuantity[], int cartCount, int size) {
  
    float total = 0;

  
    for (int i = 0; i < cartCount; i++) {
      
        for (int j = 0; j < size; j++) {
          
            if (cartCode[i] == CodeNumber[j]) {
              
                total += price[j] * CartQuantity[i];
            }
        }
    }
  
    printf("Total Bill: %.2f\n", total);
    return total;
}

float applyPromo(float total) {
  
    char PromoApplied[20];
    float NewDiscounted = total;
    printf("Do you have a promo code? ");
    scanf(" %[^\n]", PromoApplied);

    if (strcmp(PromoApplied, "Eid2025") == 0) {
      
        NewDiscounted = total * 0.75;
        printf("Promo code applied! 25%% discount given.\n");
    } else {
        printf("No valid promo code applied.\n");
    }

    printf("Final bill after discount (if any): %.2f\n", NewDiscounted);
    return NewDiscounted;
}

void showInvoice(char name[], char cnic[], float total, float NewDiscounted) {
  
    printf("\n===== INVOICE =====\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("Total Bill: %.2f\n", total);
    printf("Final Bill (after discount if any): %.2f\n", NewDiscounted);
    printf("===================\n");
}
