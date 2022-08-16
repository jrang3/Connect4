# Connect4
Description/Features of My Project
- I built a Connect4 game in C++. Players would take turns entering a column to drop a disk in. First person to have 4 disks in any direction would win the game. I also set up the game in a way that the people playing the game can choose to have whatever size board they desire off

Motivation for Project
- After working on the tic-tac-toe project, I was looking for a project that’s similar to tic-tac-toe, but a bit more challenging than tic-tac-toe. That’s when I decided to work on building a Connect 4 Game

Difficulties Ran Into
- Unlike the Tic-Tac-Toe game whenever the user chooses a column to place a disk in, the disk should be placed at the bottom row. In tic-tac-toe, the user chooses whatever position they like. I at first had difficulty in accomplishing this. In order to resolve the issue, what I did was have a vector that would hold the highest value row for each column. Every time the user wants to place a disk in a particular row, the position of the column is used to get the value in that vector. Then I would subtract that value in the vector by 1. I would then be able to use this info to also determine if a row has been full and alert the user to choose a different row. For example if I had a 6 by 5 board (6 rows and 5 columns). I would have a vector of holding 5 5’s. All of them would be 5 since that’s the largest row index, and there 5 of them since there are 5 columns. Then when the user selects a specific column to place a disk in I would use that specific column value as an index for the vector and get that specific 5 as row index value. I would then use these two values to update the board, placing the disk there. Then I would subtract that 5 by 1 indicating that for that specific row row index 5 is no longer available. Thus they would place the disk in row 4. Once the value got -1, the column becomes full. 


ScreenShots

This represents the start of the game. The user enters in the width and the height of the board they desire to play on.


<img width="692" alt="Beginning" src="https://user-images.githubusercontent.com/87880723/184972966-f84c6524-1abf-4f58-bc6a-a2eac22d3458.png">





This represents an occurence of X winning the Game 


<img width="445" alt="X Winning" src="https://user-images.githubusercontent.com/87880723/184973083-97986ab8-d951-4fdf-bb7a-c952074d1a19.png">





This represents an occurence of O winning the Game


<img width="366" alt="O Winning" src="https://user-images.githubusercontent.com/87880723/184973169-3d06c3ff-5d17-42de-b37d-eed1307060ee.png">





This image represents a message being printed out to let the user know that a specific column is filled up in the event the user tries to place a disk in a filled up column


<img width="596" alt="Slots Filled Up" src="https://user-images.githubusercontent.com/87880723/184973347-16c7febf-ac30-418c-b05e-e9ed60cbfa12.png">
