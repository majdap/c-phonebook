# Phonebook Programs (C Procedural vs Java Object-Oriented)
These are a phonebook programs where you can store numbers, delete and display all contacts. There is both a Procedural and Object Oriented version of the program.
This project demonstrates a binary tree data structure and how it can be used to quickly search for relevant information.


# Menu Options
Options presented within the user menus can be selected by entering the corresponding number displayed within the CLI
- Add a contact
- Delete a contact by name and number
- Search by Name
- Search by Phone number
- Display contacts
- Add Test Contacts to Phonebook
- Quit

# Example Text Cases

##    1) Adding a Contact
```
[Enter 1]

Enter Name: Benjamin
Enter Number: 0854326374
Address: 99 address road

[Enter 1]

Enter Name: Sham
Enter Number: 0837628354
Address: 10 address road

[Enter 5]

- When option 5 is selected for displaying contacts, both of these contacts will be displayed
(Benjamin, 0854326374, 99 address road)
(Sham, 0837628354, 10 address road)

```

##    2) Deleting a Contact
```
[Enter 2]

Enter Name: Benjamin
Enter Number: 0854326374

[Enter 5]

- Only the contact for Sham should be displayed (Sham, 0837628354, 10 address road)


```

##    3) Searching for a Contact

```
[Enter 3]
Enter Name: Benjamin

- Should return "Record not found"

[Enter 3]
Enter Name: Sham

- Should return Sham, 0837628354, 10 address road
[Enter 4]
Enter Number: 0854326374

- Should return "Record not found"

[Enter 3]
Enter Number: 0837628354

- Should return Sham, 0837628354, 10 address road

```

# Executing programs
With the GCC compiler, the C program can be compiled within a UNIX-based CLI by typing "gcc -o phonebook.c phonebook". The executable can then be ran by typing "./phonebook".

The Java program can be compiled to bytecode by typing "javac phonebook.java" and executed within a JVM by typing "java phonebook".

Alternatively, both programs can be compiled with the makefile using the commnand "make".
