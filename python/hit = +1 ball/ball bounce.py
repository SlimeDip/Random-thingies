import pygame
import random
import math

class Ball:
    def __init__(self, x, y, radius, color, speed_x, speed_y):
        self.x = x
        self.y = y
        self.radius = radius
        self.color = color
        self.speed_x = speed_x
        self.speed_y = speed_y

    def update(self, screen_width, screen_height):
        self.x += self.speed_x
        self.y += self.speed_y
        speed = random.randrange(1, 5)

        if self.x + self.radius >= screen_width or self.x - self.radius <= 0:
            self.speed_x *= -1

        if self.y + self.radius >= screen_height or self.y - self.radius <= 0:
            self.speed_y *= -1

        for ball in balls:
            if ball != self:
                distance = math.sqrt((self.x - ball.x)**2 + (self.y - ball.y)**2)
                if distance < self.radius + ball.radius:
                    
                    self.speed_x, ball.speed_x = ball.speed_x, self.speed_x
                    self.speed_y, ball.speed_y = ball.speed_y, self.speed_y
                    
                    overlap = (self.radius + ball.radius) - distance
                    dx = (self.x - ball.x) / distance
                    dy = (self.y - ball.y) / distance
                    self.x += dx * overlap / 2
                    self.y += dy * overlap / 2
                    ball.x -= dx * overlap / 2
                    ball.y -= dy * overlap / 2

                    balls.append(Ball(random.randrange(1250), random.randrange(700), 10, (0, 0, 0), speed, speed))


    def draw(self, screen):
        pygame.draw.circle(screen, self.color, (self.x, self.y), self.radius)

pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
running = True

balls = [
    Ball(random.randrange(1250), random.randrange(700), 10, (0, 0, 0), 5, 5),
    Ball(random.randrange(1250), random.randrange(700), 10, (0, 0, 0), 5, 5)
]

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill("white")

    for ball in balls:
        ball.update(1280, 720)
        ball.draw(screen)

    if len(balls) > 200:
        running = False

    print(f"number: {len(balls)}")

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
