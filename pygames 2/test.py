import pygame

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

        if self.x + self.radius >= screen_width or self.x - self.radius <= 0:
            self.speed_x *= -1

        if self.y + self.radius >= screen_height or self.y - self.radius <= 0:
            self.speed_y *= -1

    def draw(self, screen):
        pygame.draw.circle(screen, self.color, (self.x, self.y), self.radius)

pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
running = True

balls = [
    Ball(25, 25, 25, (0, 0, 0), 10, 10),
    Ball(50, 50, 25, (50, 0, 0), 12, 12),
    Ball(25, 25, 25, (63, 46, 0), 14, 14),
    Ball(50, 50, 25, (69, 0, 220), 16, 16)
]

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill("white")

    for ball in balls:
        ball.update(1280, 720)
        ball.draw(screen)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
