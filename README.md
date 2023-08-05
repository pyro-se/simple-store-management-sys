# Simple Store System (C++/Web) - late 2021

 The project was created for the purpose of passing the 'Programming in C++' course at the university on December 2021 is a simple web application that functions as a virtual store, allowing users to browse and purchase products. The project is implemented in PHP and utilizes HTML, CSS (Bootstrap), and text files as a simple form of data storage. I made it as a student and only focus to make it at least work.

## Features

- Admin console for user and storage management
- Browse available products in the store
- Purchase selected products
- Check user's balance before making a purchase
- Transaction history - recording purchased products by users

## Data Files

The project uses three text files to store data:

1. `shop.txt` - contains information about products in the store in the format: Product_ID Product_Name Price
2. `user.txt` - stores user data in the format: User_ID Username Password Score Balance
3. `transactions.txt` - contains the history of transactions in the format: Transaction_Number Username Product_ID Product_Name Product_Price

## Requirements
- PHP version 5.6 or higher
- Web browser with HTML5 and CSS3 support (Bootstrap)

## Running the Project

1. Copy all project files to a server that supports PHP. (I've used XAMPP server.)
2. Open a web browser and enter the application's address to start using the online store.
3. For store management use C++ "admin console" program.

## Note

This project is a very simple example of an store and is not suitable for any applications. To apply this project in practice, it is necessary to refine and expand it with proper security mechanisms, authentication, a proper database to store user and product data. I made it as a student and only focus to make it at least work.

There are nav-icons that are used in Web section of project, also framework for frontend is Bootstrap. I've downloaded them from [(Flaticon.com)](https://www.flaticon.com/free-icons/user).
- Those icons use Flaticon license.
- [(Bootstrap)](https://getbootstrap.com/docs/4.0/about/license/) uses MIT License.


## Author

This project was developed by [pyro-se](https://github.com/pyro-se).



