# Mini Market Online Platform

This repository contains the C++ source code for a Mini Market Online Platform, a system designed to transition a traditional grocery store in Kampar to an online platform. The project focuses on managing customer details, item lists, and transaction history.

## Table of Contents

- [About](#about)
- [Features](#features)
- [Modules](#modules)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Running the Program](#running-the-program)
- [Usage](#usage)
- [Contributors](#contributors)
- [License](#license)

## About

JSJK Mini Market, a traditional grocery store in Kampar, is moving to an online platform to better serve its customers. This C++ program provides the core functionalities for this online presence, including user registration and login, managing a list of items for purchase, and tracking financial transactions.

## Features

* **User Management:** Register new users and allow existing users to log in securely.
* **Item Management:** Read, add, and display details of vegetables and fruits available for purchase.
* **Transaction Tracking:** Record and display transaction history, including top-ups and spending.

## Modules

The program is structured into three main modules, each handling specific functionalities:

### Member 1: Login Modules (Developed by Stanley Chew Jun Xian)

* `readUserDetails`: Reads all user details from `user.txt`. 
* `registerNewUser`: Adds new registered user details to the records. 
* `login`: Validates username and password for secure user access. 

### Member 2: Purchase Modules (Developed by Chan Jie Yan)

* `readItemList`: Reads purchase details of vegetables or fruits from `XX_itemList.txt`. 
* `addItemList`: Adds purchase details of vegetables or fruits to `XX_itemList.txt`. 
* `displayItemList`: Displays the details of all purchased vegetables or fruits. 

### Member 3: Transaction Modules (Developed by Chong Jian Yi)

* `readTransaction`: Reads all details from `XX_transaction.txt`. 
* `transaction`: Allows users to add or subtract credits to their accounts, updating records for transparent tracking. 
* `displayTransactionDetails`: Displays all transaction history details. 

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

* A C++ compiler (e.g., g++)
* A text editor or IDE (e.g., VS Code, Dev-C++)

### Installation

1.  Clone the repository:
    ```bash
    git clone [https://github.com/StanleyCJX/MiniMarketOnlineStore](https://github.com/StanleyCJX/MiniMarketOnlineStore)
    ```
2.  Navigate to the project directory:
    ```bash
    cd JSJK-Mini-Market
    ```

### Running the Program

1.  Compile the source code:
    ```bash
    g++ your_program_name.cpp -o main
    ```
    (Replace `your_program_name.cpp` with the actual name of your combined C++ source file.)
2.  Run the executable:
    ```bash
    ./main
    ```

## Usage

Upon running the program, you will be presented with a menu.

### Registering a New User

1.  Select option `1` to "Register New User". 
2.  Enter the requested details: Username, Password, Gender, and Date of Birth. 
3.  The details will be saved to `user.txt`. 

### Logging In

1.  Select option `2` to "Login". 
2.  Enter your Username and Password. 
3.  If successful, you will see "Login Successfully!" 

### Main Menu Options (after successful login)

* **1. Display Item List:** Shows all items currently recorded in your `_itemList.txt` file. 
* **2. Add Item List:** Allows you to add new items (name, code, price per KG, purchasing weight) to your `_itemList.txt` file. 
* **3. Perform Transaction:** Enables you to add or subtract amounts from your balance, recording the transaction date. 
* **4. Display Transaction History:** Shows your available balance and a history of all transactions (top-ups and spending). 
* **5. Quit:** Exits the program. 

## Contributors

* **Stanley Chew Jun Xian** - Member 1 (Role: COMBINE CODE) – LOGIN modules (`readUserDetails`, `registerNewUser`, `login`) 
* **Chan Jie Yan** - Member 2 (Role: FIX ERRORS) – PURCHASE modules (`readItemList`, `addItemList`, `displayItemList`) 
* **Chong Jian Yi** - Member 3 (Role: ERROR CHECKING) – TRANSACTION modules (`readTransaction`, `transaction`, `displayTransactionDetails`) 

## License

This project is for academic purposes as part of the PROGRAMMING CONCEPTS AND PRACTICES course at Universiti Tunku Abdul Rahman.
