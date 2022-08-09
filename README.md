# Bank-Accounts
## Exercise description
Write a program for managing a bank's current accounts. Current accounts can be of 3 different types:
• Type A: it is possible to have a negative balance of up to -2000 euros
• Type B: it is possible to have a negative balance of up to -1500 euros
• Type C: it is possible to have a negative balance of up to -1000 euros

The data relating to each current account are:
• Current Account Code (A string of 8 characters), key field
• Current account topology (One character [A / B / C])
• Surname of the account holder (A string of 15 characters)
• Name of the account holder (A string of 15 characters)
• Number of payment operations (One whole)
• Number of withdrawal operations (One integer)
• Balance (A real)

## Features to implement
The program stores the data relating to the current accounts in a hash table with collision lists and a bucket of size 4. The hash function adds the ascii codes of the characters of the key and calculates the rest of the integer division by 4. The program realizes the following features:
• Inserting a new current account. (Functionality already provided)
• Withdrawal or deposit for a current account.
• Calculation of the total number of deposit and withdrawal operations and the sum of the balances for all current accounts.
• Search for the current account with the largest balance.
• Screen printing of current accounts. (Functionality already provided)

## Given files
For the implementation of the application, the student has at his disposal:
• The files needed to create the entire project;
• The standard functions for the management of the hash table that must be used without making any changes to them (neither to the prototypes nor to their implementation provided);
• The definition of the prototypes of the functions to be implemented.

The files provided are as follows:
• info.h (not to be changed)
Contains the definition of the TInfo type and the prototypes of the functions for its management.

• info.c (not to be changed)
Contains the implementation of the functions for the management of TInfo.

• list.h (not to be modified)
Contains the definition of the TList type and the prototypes of the functions for managing TList (standard functions)

• list.c (not to be modified)
Contains the implementation of the functions for managing TList (standard functions)

• hash.h (not to be changed)
Contains the definition of the THash type and the prototypes of the functions for the management of THash (standard functions)

• hash.c (to be completed)
Contains the implementation of the functions for the management of THash (standard functions). The student will have to implement the int f_hash (TKey key) function;

• menu.h (not to be changed)
Contains prototypes of user interface functions.

• menu.c (not to be changed)
Contains the implementation of the user interface functions.

• management_cc.h (not to be modified)
Contains the prototypes of the functions required by the application:
> int insert_cc (current THash);

• The function reads the TInfo data and inserts a new node in the hash table. The function returns 1 if the insertion is successful, -1 otherwise. (The function is already provided)
> int withdrawal_versamento_cc (THash with currents);

• The function reads the current account code and the operation to be carried out. Then he looks for the current account and if he finds it he reads the amount of the operation. If the operation is a withdrawal, the balance is decreased by the amount entered and the number of withdrawals is increased by 1; if the operation is a payment, the balance is increased by the amount entered and the number of payments is increased by 1. For the withdrawal operation, the conditions on the type must be checked, if the balance does not allow withdrawal, the operation is not carried out. The function returns 2 if the payment operation is successful, 1 if the withdrawal operation is successful, 0 if the balance is not sufficient to carry out the operation, -1 if the current account is not is found.
> void compute_values ​​(THash with currents);

• The function calculates the sum of the balances of all current accounts, the sum of all withdrawal operations and all deposit operations. At the end it prints the three calculated values. The function does not return any value.
> void seek_rich (THash with currents);

• The function searches the hash table for the account with the highest balance and prints the information. The auxiliary function TNode * search (TList list) is used for the search.
> TNode * search (TList list);

• The search function searches within a list for the account with the highest balance. (The function must be recursive)
> void stampa_cc (current THash);
• The print function, the information of all current accounts in the archive. The function does not return any value. (The function is already provided)

• management_cc.c (to be completed)
Contains the implementation of the functions required by the application

• current_accounts.c (to be completed)
Contains the main funntion