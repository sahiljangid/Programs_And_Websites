import pygame
import random

# Initialize Pygame
pygame.init()

# Set up the game window
window_width = 600
window_height = 400
window = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption("Snake Game")

# Define colors
white = (255, 255, 255)
black = (0, 0, 0)
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)

# Set up the snake
snake_block_size = 10
snake_speed = 15
snake_list = []
snake_length = 1

# Set up the food
food_block_size = 10
food_x = round(random.randrange(0, window_width - food_block_size) / 10.0) * 10.0
food_y = round(random.randrange(0, window_height - food_block_size) / 10.0) * 10.0

# Set up the font
font_style = pygame.font.SysFont(None, 30)

# Function to display message
def message(msg, color):
    message_text = font_style.render(msg, True, color)
    window.blit(message_text, [window_width / 6, window_height / 3])

# Function to draw the snake
def draw_snake(snake_list):
    for block in snake_list:
        pygame.draw.rect(window, white, [block[0], block[1], snake_block_size, snake_block_size])

# Function to generate new food
def generate_food():
    food_x = round(random.randrange(0, window_width - food_block_size) / 10.0) * 10.0
    food_y = round(random.randrange(0, window_height - food_block_size) / 10.0) * 10.0
    return food_x, food_y

# Function to update the score
def update_score(score):
    score_text = font_style.render("Score: " + str(score), True, blue)
    window.blit(score_text, [0, 0])

# Main game loop
game_over = False
game_pause = False
clock = pygame.time.Clock()
score = 0

while not game_over:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game_over = True
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_p:
                game_pause = not game_pause

    if not game_pause:
        # Move the snake
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            x_change = -snake_block_size
            y_change = 0
        elif keys[pygame.K_RIGHT]:
            x_change = snake_block_size
            y_change = 0
        elif keys[pygame.K_UP]:
            x_change = 0
            y_change = -snake_block_size
        elif keys[pygame.K_DOWN]:
            x_change = 0
            y_change = snake_block_size

        # Update the snake's position
        snake_head = []
        snake_head.append(snake_list[-1][0] + x_change)
        snake_head.append(snake_list[-1][1] + y_change)
        snake_list.append(snake_head)
        if len(snake_list) > snake_length:
            del snake_list[0]

        # Check for collision with the food
        if snake_head[0] == food_x and snake_head[1] == food_y:
            food_x, food_y = generate_food()


    # Increase the snake's length and update the score
        snake_length += 1
        score += 10

    # Draw the window
    window.fill(black)
    pygame.draw.rect(window, red, [food_x, food_y, food_block_size, food_block_size])
    draw_snake(snake_list)
    update_score(score)
    pygame.display.update()

    # Check for collision with the wall or the snake's body
    if snake_head[0] >= window_width or snake_head[0] < 0 or snake_head[1] >= window_height or snake_head[1] < 0:
        game_over = True
    for block in snake_list[:-1]:
        if block == snake_head:
            game_over = True

    # Set the game's speed
    clock.tick(snake_speed)

message("Game Over!", red)
update_score(score)
pygame.display.update()

pygame.time.wait(2000)
pygame.quit()
quit()