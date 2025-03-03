# CornerGrocer
# App for CornerGrocer
# Summarize the project and what problem it was solving. 
This project is an item-tracking program designed for a grocery store, specifically the Corner Grocer. The goal was to process a text file containing a list of produce items purchased throughout the day and analyze the frequency of each item. The program not only reads and counts these occurrences using a case-insensitive approach, but also backs up the frequency data to an output file. Additionally, it provides an interactive menu for users to search for a specific item, display all items and their frequencies, or view a histogram that visually represents purchase frequencies.

# What did you do particularly well?
I feel that I particularly excelled in the input validation of this project, making sure the only valid choices from the user are the numbers 1-4. I also feel that I did very well with case-insensitive handling for when the user types the item they are searching for, to account for whether or not the user is typing with caps or not.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I could enhance my code by incorporating try-catch blocks around file I/O operations to manage unexpected errors better. 


# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
Creating the loop for validating user input was probably the most challenging to write for this assignment. Although I had attempted something similar in a previous assignment, now that I had more knowledge on C++ through our course, I was able to look back at the book and used online resources like Stack Overflow to understand the logic I would need to develop this loop.

# What skills from this project will be particularly transferable to other projects or course work?
The skills from this project that will be particularyly transferable to other projects or course work would be the creation of the loop for user validation, the ability to process file handling and the utilization of containers such as map for data processing.

# How did you make this program maintainable, readable, and adaptable?
I made this program maintainable, readable and adaptable by having clear comments and names for the functions. I also created a structure by having the GroceryTracker class to support any potential expansion or new features that may be added by others. 
