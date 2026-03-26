🎮 C++ Tic-Tac-Toe (SFML Edition)
Welcome to our final project! This is a fully object-oriented, graphical Tic-Tac-Toe game built from scratch in C++ using the SFML graphics library.

Because this game opens a separate graphical window, running it inside a web-based GitHub Codespace requires a few specific setup steps. Don't worry—just follow the instructions below exactly as written, and you'll be playing in minutes!

🚀 Step 1: Get the Code
Open a brand new GitHub Codespace.

Open the Terminal at the bottom of the screen (Press Ctrl + ` if you don't see it).

Copy and paste the following command to download the game files, then hit Enter:

git clone https://github.com/Theawesomepossum-07/Cpp-Final-project-Tic-Tac-Toe-.git

Move inside the downloaded folder:

cd Cpp-Final-project-Tic-Tac-Toe-

🛠️ Step 2: Prepare the Codespace
A fresh Codespace doesn't know what "SFML" is yet. We need to install the graphics library so the code can compile.

Run this command to update the package list:

sudo apt-get update

Run this command to install the SFML library (type Y and press Enter if it asks for permission):

sudo apt-get install libsfml-dev

📺 Step 3: Setup the Virtual Machine Display
Because Codespaces run in the cloud, they don't have a physical monitor. We have to route the game's window to a virtual display tab.

Look at the bottom terminal panel and click the PORTS tab (next to "Terminal" and "Output").

Ensure your Codespace Desktop/VNC port is active.

Hover over the Forwarded Address column for the active port and click the Globe Icon (Open in Browser).

A new browser tab will open showing a virtual Linux desktop. Keep this tab open! This is where the game board will appear.

⚙️ Step 4: Compile the Game
Now we need to translate the C++ code into a runnable game. Go back to your main VS Code tab and paste this exact command into the terminal:

g++ *.cpp -o tic_tac_toe -lsfml-graphics -lsfml-window -lsfml-system

(If it works, it will silently drop you to a new line with no red text. That means success!)

🎲 Step 5: Play!
To launch the game and send the window to your virtual display, run this command:

DISPLAY=:1 ./tic_tac_toe

Look at your Terminal: It will ask for Player 1 and Player 2's names. Type them in and hit Enter.

Switch to your Virtual Desktop Tab: The graphical Tic-Tac-Toe board will now be open!

Click the squares to play. The terminal will keep a running log of the score.

🚑 Troubleshooting (If things go wrong)
Error: fatal error: SFML/Graphics.hpp: No such file or directory

Fix: You skipped Step 2! Run sudo apt-get install libsfml-dev in the terminal.

Error: Failed to open X11 display; make sure the DISPLAY environment variable is set correctly

Fix: You forgot the DISPLAY=:1 part of the run command in Step 5. Make sure you are using DISPLAY=:1 ./tic_tac_toe

Error: Permission denied when trying to run the game.

Fix: The computer isn't letting you execute the file. Run this command to fix it: chmod +x tic_tac_toe, then try running it again.

Problem: The terminal is spamming Failed to open joystick.

Fix: Ignore it! It just means SFML is looking for an Xbox controller that doesn't exist in the cloud. The game will still play perfectly.

Problem: I don't see the graphical window!

Fix: Ensure you completed Step 3. The game opens in a completely separate browser tab via the PORTS menu, not inside the VS Code editor itself.