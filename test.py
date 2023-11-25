import random
# Define colors and their corresponding representation
colors = {"RED": "R", "GREEN": "G", "BLUE": "B"}
# Initialize the game state
tubes = []
for _ in range(5):
    tubes.append([])
# Create and distribute balls randomly
balls = []
for _ in range(20):
    color = random.choice(list(colors))
    balls.append(color)
    random_tube = random.randint(0, 4)
    tubes[random_tube].append(color)
# Function to print the current game state
def print_game_state():
    for tube in tubes:
        print(tube)
# Game loop
while True:
    print("\nCurrent Game State:")
    print_game_state()
    # Get user input for selecting tubes
    source_tube = int(input("Select source tube (0-4): "))
    destination_tube = int(input("Select destination tube (0-4): "))
    # Validate user input
    if source_tube < 0 or source_tube > 4 or destination_tube < 0 or destination_tube > 4:
        print("Invalid tube selection. Please enter a valid tube number (0-4).")
        continue
    # Check if the source tube is empty or the destination tube is full
    if len(tubes[source_tube]) == 0:
        print("Source tube is empty. Please select a non-empty tube.")
        continue
    if len(tubes[destination_tube]) == 4:
        print("Destination tube is full. Please select a non-full tube.")
        continue
    # Move the ball from source to destination
    ball_color = tubes[source_tube].pop()
    tubes[destination_tube].append(ball_color)
    print("Moved ball from tube", source_tube, "to tube", destination_tube)

    # Check if all balls are sorted correctly
    is_sorted = True
    for tube in tubes:
        if len(tube) == 0 or len(set(tube)) != 1:
            is_sorted = False
            break
    if is_sorted:
        print("Congratulations! You have successfully sorted all balls.")
        break