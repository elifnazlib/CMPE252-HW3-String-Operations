# CMPE 252 C Programming

## Homework 3

In this assignment, you are going to write a C program that reads, processes, and displays attendance records in a Zoom meeting report provided as a txt file.

<br>

**Getting to know input file:**

A sample Zoom meeting report (**input1.txt**) is given as follows:

![image](https://github.com/user-attachments/assets/af7e528f-154b-4081-86a2-546d7e437d3a)

<br>

The first line of the input file is a header line which includes title of each column of the data file:

- **Join Time**: Date and time when participants join the meeting

- **Leave Time**: Date and time when participants leave the meeting

- **Duration**: Duration (in terms of minutes) passed between join and leave time
  
- **Name**: Name & surname

- **Email**: Email address

<br>

Each of the remaining lines includes a record for a connection of an attendee to the meeting where attendees are uniquely recognized by their name & surname. Name of an attendee might include more than one word but surname is always a single word at the end of name & surname.

<br>

Name & surname refer to the same attendee if they are the same without considering uppercase/lowercase distinction of the letters. For example:

- Eda Nur Yilmaz and EDA NUR YILMAZ refer to the same attendee.
  
- Eda Nur Yilmaz and Eda Nur YILMAZ refer to the same attendee.

<br>

Of course, order and number of the words in name & surname matters. For example:

- Eda Nur Yilmaz and Nur Eda Yilmaz refer to different attendees.

- EDA NUR YILMAZ and EDA YILMAZ refer to different attendees.

<br>

Assume that there is a single space character between words in name & surname column of input file. For example:

- EDA NUR YILMAZ and EDANUR YILMAZ refer to different attendees.

<br>

Of course, if there is a difference between surnames or names, they refer to different attendees. For example:

- EDANUR YILMAZ and EDA YILMAZ refer to different attendees.

- EDA YILMAZ and EDA YILMAZCAN refer to different attendees.

<br>

Notice that it is possible that e-mail address is not provided in some records.

<br>

Also, notice that there might be more than one record for some of attendees as they leave and join the meeting multiple times. Assume that there is no time overlap between multiple connections made by each attendee. That means each attendee has at most one connection at each moment of the meeting.

<br>

Assume that duration is always provided for each record and it is compatible with the difference between join and leave time so you will consider duration of each connection as the number at the middle of its corresponding line (you do not need to compute duration of each connection from join and leave time).

<br>

Assume that the number of attendees in a Zoom session is not greater than 500.

<br>
<br>

**What the program is expected to do:**



Your program is supposed to do the following tasks:

- Read input file so that, for each connection, store name & surname of the corresponding attendee along with duration of the connection.

- If there are multiple connections made by the same attendee:
  - Update duration of the first connection by adding durations of the remaining connections.
  
  - Keep the first connection (whose duration is updated) and remove the remaining connections.

- Write surname, name of attendees along with duration of their total connection
  - If *sortedAnswer=no*, the order of attendees in the output file will be in their original order in the input file.
  
  - If *sortedAnswer=yes* is provided (as sorted), the order of attendees in the output file will be based on alphabetical order of their surname & name.

<br>
<br>

**Sample Runs:**

<ins>*Sample run 1:*</ins>
```
Enter the input file name: input1.txt

Sort the results? (yes/no): yes

Ceyhun Taner 117.00
Duman Feyza Nur 122.00
Gencel Asya Hale 118.00
Safak Aytekin 120.00
Tekin Ilhan 118.00
TERZI Sevil 110.00
Yamac Duru 117.00
YAMAC Serhat Gokhan 118.00
YILMAZ Eda Nur 97.00
```

<ins>*Sample run 2:*</ins>
```
Enter the input file name: input1.txt

Sort the results? (yes/no): no

Duman Feyza Nur 122.00
YILMAZ Eda Nur 97.00
YAMAC Serhat Gokhan 118.00
Yamac Duru 117.00
Gencel Asya Hale 118.00
Ceyhun Taner 117.00
TERZI Sevil 110.00
Tekin Ilhan 118.00
Safak Aytekin 120.00
```

<ins>*Sample run 3:*</ins>
```
Enter the input file name: input2.txt

Sort the results? (yes/no): yes

Ceyhun Taner 61.00
Gencel Asya Hale 118.00
TERZI Sevil 85.00
YAMAC Serhat Gokhan 118.00
Yilmaz Eda Nur 95.00
```

<ins>*Sample run 4:*</ins>
```
Enter the input file name: input2.txt

Sort the results? (yes/no): no

YAMAC Serhat Gokhan 118.00
Gencel Asya Hale 118.00
Yilmaz Eda Nur 95.00
Ceyhun Taner 61.00
TERZI Sevil 85.00
```

<br>
<br>

> [!TIP]
> - You can use any available string sorting algorithm in your source code in the literature, but your source code is expected to be comprised by only 1 source file (so all your functions including the sorting function should be in the same file).
> - In this homework, you are mainly expected to use your skills from Chapter 8 Strings of the book.
> - Check out string.h library functions
> - Check also character functions available in ctype.h.
> - You may also consider using fgets, fputs functions under stdio.h, if applicable to your solution.
