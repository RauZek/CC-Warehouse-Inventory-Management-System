# CC-Warehouse Inventory Manager
A C++ console-based application designed to assist warehouse operations by managing food inventory. 
It supports input, organization, and search of food items, distinguishing between regular and special goods, and generates formatted reports for stock analysis.

# Technologies Used
- *Language*: C++;
- *Environment*: Console application.

# Features
# 1. Data Entry
- Accepts an integer *n* in the range [0, 1000], representing the number of food items.
- For each item, the following fields are entered:
  - *Code*: Alphanumeric string (max 5 characters);
  - *Name*: String (max 60 characters);
  - *Quantity*: Positive integer (in kilograms);
  - *Shelf Life*: Positive integer (in days);
  - *Group Type*:  
    - *G* – Regular goods;  
    - *S* – Special goods;
  - *Date of Entry*: Format DD.MM.YYYY;
  - *Storage Position*: String (max 10 characters);
  - *Storage Temperature*: Real number (only for special goods, up to 2 decimal places).

# 2. Full Inventory Report
- Displays all items currently in stock;
- Each line includes:
- Storage position;
- Item code;
- Item name;
- Quantity in kilograms;
- Entry date;
- Shelf life;
- Storage temperature (only for special goods, formatted as tC=4.0);
- The list is sorted lexicographically by storage position.

# 3. Special Goods Report
- Displays only special goods (S) currently in stock;
- Sorted chronologically by entry date, and for items with the same date, sorted by descending shelf life;
- Output format matches the full inventory report.
  
# 4. Item Search by Code
- Allows the user to input an item code;
- Searches and displays all matching items in the warehouse;
- Calculates and displays:
- Total quantity available for that item;
- Minimum storage temperature (if applicable).

