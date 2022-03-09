# Trimon - Project Specification
## Introduction
Our project simulates a turn-based battle between two creatures (mons), taking inspiration from Pokemon. The computer randomly selects a mon, then the user selects theirs. Players take turns, with the user going first, selecting moves which either inflict damage to the opponent or heal the user of the move. The battle is fought until either mon reaches 0 health, and the surviving mon wins, or the player chooses to exit. Additional multiplayer and simulation game modes have been added, allowing for PvP and CvC games which run as described above.

There are three mons to choose from, named ‘Fire Dino’, ‘Water Turtle’ and ‘Grass Dog’, each corresponding to one of three types: fire, water and grass. The damage dealt by offensive moves is dependent on the types of the attacking and defending mon, similar to the rock, paper, scissors configuration in Pokemon, where fire-type mons do more damage to grass and less to water, etc. The computer mon also has a ‘nature’ which dictates its move choices, with ‘neutral’ choosing a random move, ‘hostile’ the strongest, and ‘passive’ the weakest or a healing move. Furthermore moves have ‘PP’, a number indicating the amount of times a move can be used, which decreases after every use. If the computer can no longer choose the move(s) corresponding to its nature, it will become neutral, and if it uses all PP, it will give up.

## Installation
The program can be compiled and run with the below command.
```bash
make
```
Alternatively, the following command can be used to only compile it.
```bash
make compile
```

## Design Description
### Assessment Concepts
Memory allocation from stack and the heap:
- Arrays: Dynamic arrays are used when storing moves in Mon objects, allowing for mons to having differing numbers of moves, or even gain and lose moves. Moves and Mon objects within the main function are also stored with dynamic arrays.
- Strings: Many variables and attributes are stored as strings, such as move names, mon names, types, natures and nicknames.
- Objects: Move, Mon, Player, Com, Human

User input and output:
- Input: The user inputs through the command line, able to choose their mon, its nickname, and the move to make during their turn. These all run through input validation functions, to ensure no unexpected errors can occur.
- Output: The terminal is be used to display the program, being purely text-based apart from a health bar displayed using ASCII characters.

Object-oriented programming and design:
- Inheritance: Com and Human classes inherit from the Player abstract class, which contains many attributes and methods mutual between the two.
- Polymorphism: Although some methods in Player are defined, pure virtual functions like getMove() utilise polymorphism, with the Com definition using its nature and RNG, and the Human definition asking for input.
- Encapsulation: The Mon class contains an array of Move objects to use as a moveset, and the Player class, along with its children, each store their mon as a Mon object.
### Class Diagram (excl. Get functions)
![Imgur](https://i.imgur.com/Ro8ImcA.png)
### Class Descriptions
Move: Stores names, damage and MaxPP of moves with no (non-get) methods.

Mon: Stores mons with name, type, max HP and moves, no (non-get) methods

Player: Abstract parent class which stores mon, name (nickname) and current hp + pp, and contains method definitions to check if mon is alive, to lose (or gain) HP, to print HP (as health bar) and to perform a move on another mon.

Com: Child class used for computer player which inherits from Player, also storing nature of mon, and contains method definitions for generating random move and printing ‘wild mon appeared’ message. Contains two custom constructors: one for a given mon and nature, and another for a list of mon to randomly choose from.

Human: Child class used for human player which inherits from Player and contains method definitions for asking for move and printing ‘player sent out mon’ message. Contains two custom constructors: one for a given mon and nickname, and another for a list of mon for user to choose from.

### User Interface
Upon starting the program, the user is asked which gamemode they want to play then, if single player is chosen, a ‘mon appeared’ message is printed to the console, detailing the mon along with its nature. It then presents the user with the option to choose from the three mon previously mentioned, as shown below.

![Imgur](https://i.imgur.com/MxZMQJv.png)

After inputting a number, it then prints the chosen mon and allows the user to enter a nickname, as follows.

![Imgur](https://i.imgur.com/5A6S827.png)

It then displays a ‘sent out mon’ message, followed by the health bars of both mons, and then the list of possible moves, before asking once again for user input.

![Imgur](https://i.imgur.com/fdrtuU2.png)

Messages displaying the move used, damage dealt, and any type buffs are printed for both the user’s move and computer’s subsequent move, each followed by both health bars, before the previous section is repeated. As displayed below, choosing a move with no PP produces a warning.

![Imgur](https://i.imgur.com/oSpttW5.png)
![Imgur](https://i.imgur.com/JZp81MM.png)

This is repeated until either mon’s HP reaches 0, with the below image showing the user winning outcome.

![Imgur](https://i.imgur.com/WMnfwDx.png)
### Code Style
All code is formatted following C++ conventions, with indents where necessary and comments placed above functions and notable pieces of code. Classes begin with capital letters, and are stored using .h and .cpp files.
## Testing
All test files were be run through a makefile. These acted as regression testing, being called each time a file was changed or the program was compiled.
### Unit Testing
Each of the classes used in the program had its own unit test, with a corresponding file named ClassNameTest.cpp containing a main function that compares the actual output with the expected output for various inputs.
### Integration Testing
Integration testing was performed manually by varying inputs and trying to ‘break’ the program. This also allowed for game balance issues to be identified and fixed.
