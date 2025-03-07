import pygame
import random
import math

pygame.init()

WIDTH = 400
HEIGHT = 800
SCREEN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Dodge")

clock = pygame.time.Clock()

LANE = [50, 150, 250, 350]

class Ball:
    def __init__(self, x, y, radius, color, speed_y):
        self.x = x
        self.y = y
        self.radius = radius
        self.color = color
        self.speed_y = speed_y

    def draw(self, screen):
        pygame.draw.circle(screen, self.color, (self.x, self.y), self.radius)

    def move(self):
        self.y += self.speed_y

    def collision(self, player):
        distance = math.sqrt((self.x - player.x) ** 2 + (self.y - player.y) ** 2)
        if distance < self.radius + player.radius:
            return True
        return False


class Player:
    def __init__(self, x, y, radius, color):
        self.x = x
        self.y = y
        self.radius = radius
        self.color = color

    def draw(self, screen):
        pygame.draw.circle(screen, self.color, (self.x, self.y), self.radius)

    def move(self, direction):
        if direction == "left" and self.x > 50:
            self.x -= 100
        if direction == "right" and self.x < 350:
            self.x += 100


bullet = []
last_spawn = pygame.time.get_ticks()
spawn_delay = 500

player = Player(150, 700, 25, "black")
life = 3

font = pygame.font.SysFont(None, 50)

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                player.move("left")
            if event.key == pygame.K_RIGHT:
                player.move("right")

    SCREEN.fill("white")

    now = pygame.time.get_ticks()
    if len(bullet) <= 10 and now - last_spawn >= spawn_delay:
        lane = random.choice(LANE)
        bullet.append(Ball(lane, 0, 25, (255, 0, 0), 5))
        last_spawn = now

    for b in bullet:
        b.move()
        b.draw(SCREEN)

        if b.collision(player):
            bullet.remove(b)
            life -= 1

    player.draw(SCREEN)

    bullet = [b for b in bullet if b.y < HEIGHT]
    
    life_text = font.render(f"Lives: {life}", True, (0, 0, 0))
    SCREEN.blit(life_text, (10, 10))

    if life <= 0:
        game_over = font.render("GAME OVER", True, (255, 0, 0))
        SCREEN.blit(game_over, (WIDTH // 2 - 100, HEIGHT // 2))
        pygame.display.flip()
        pygame.time.delay(3000)
        running = False

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
