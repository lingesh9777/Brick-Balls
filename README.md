# BrickBalls

BrickBalls is a console-based game where players strategically aim to clear bricks from a grid using a ball. Players control the ball's movement through commands to achieve the ultimate goal: clear the grid and win the game!

## Features
- **Dynamic Gameplay**: Players can move the ball in different directions (straight, left diagonal, or right diagonal).
- **Various Brick Types**:
  - `'1'`: A single-hit brick.
  - `'B'`: A blast brick that clears an entire row.
  - `'S'`: A surround brick that clears bricks in its surrounding area.
- **Challenging Objectives**: Players need to clear all bricks within a limited number of attempts.

## How to Play
1. **Initialize the Game**:
   - Set the grid size during game creation.
   - Add bricks to the grid by specifying their positions and types.
2. **Start Playing**:
   - Control the ball with commands:
     - `ST`: Move straight up.
     - `LD`: Move left diagonally.
     - `RD`: Move right diagonally.
   - Use strategic moves to clear bricks.
3. **Win Condition**:
   - Clear all bricks to win the game.
   - If you run out of balls, the game ends.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., GCC, Clang).

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/BrickBalls.git
   ```
2. Navigate to the project directory:
   ```bash
   cd BrickBalls
   ```
3. Compile the game:
   ```bash
   g++ BrickBalls.cpp -o BrickBalls
   ```
4. Run the game:
   ```bash
   ./BrickBalls
   ```

## Game Demo
1. The game starts by asking you to input brick positions and their types.
2. Use commands (`ST`, `LD`, `RD`) to control the ball.
3. Example grid layout:
   ```
   W W W W W W W W
   W             W
   W      1      W
   W   S         W
   W             W
   W   B         W
   G G G G G G G W
   ```

## Controls
- `ST`: Move the ball straight up.
- `LD`: Move the ball left diagonally.
- `RD`: Move the ball right diagonally.

## Example Run
```
Enter the brick's position and the brick type: 2 3 1
Do you want to continue(Y or N)? Y
Enter the brick's position and the brick type: 3 4 S
Do you want to continue(Y or N)? N
Enter the direction in which the ball needs to traverse(ST/LD/RD): ST
Ball count: 3
...
Congratulations..You've Won!
```

## Code Structure
- **Class `BrickBalls`**: Handles game initialization, brick management, ball movement, and win/lose conditions.
- **Key Methods**:
  - `setBricks`: Places bricks on the grid.
  - `displayGame`: Displays the current game state.
  - `moveStraight`, `moveLeft`, `moveRight`: Moves the ball in the specified direction.
  - `blastRow`, `blastsurr`: Special brick effects.
  - `gameResult`: Checks if the game is won.

