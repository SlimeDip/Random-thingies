import pygame
import random
import os

pygame.init()

WIDTH, HEIGHT = 500, 600
SCREEN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Piano Circles")

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREY = (107, 107, 107)
LIGHT_GREY = (190, 190, 190)
GREEN = (35, 101, 51)
RED = (217, 33, 33)

TILE_WIDTH = WIDTH // 4
TILE_HEIGHT = 100
RADIUS = 50
SPEED = 5

MARKER = pygame.Surface((WIDTH, HEIGHT - 50))
MARKER.fill(LIGHT_GREY)

FONT = pygame.font.SysFont(None, 60)
BUTTON_FONT = pygame.font.SysFont(None, 40)

KEYS = {pygame.K_d: 0, pygame.K_f: 1, pygame.K_j: 2, pygame.K_k: 3}

BASE_DIR = os.path.dirname(__file__)
HIGH_SCORE_FILE = os.path.join(BASE_DIR, "highscore.txt")

if os.path.exists(HIGH_SCORE_FILE):
    with open(HIGH_SCORE_FILE, "r") as file:
        try:
            high_score = int(file.read())
        except ValueError:
            high_score = 0
else:
    high_score = 0

score = 0

def draw_text(text, x, y, color, center=False):
    label = FONT.render(text, True, color)
    if center:
        x = WIDTH // 2 - label.get_width() // 2
    SCREEN.blit(label, (x, y))

class Tile:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.hit = False

    def move(self):
        self.y += SPEED

    def draw(self):
        color = GREY if self.hit else BLACK
        pygame.draw.circle(SCREEN, color, (self.x + TILE_WIDTH // 2, self.y + TILE_HEIGHT // 2), RADIUS)

    def is_off_screen(self):
        return self.y > HEIGHT

    def collide(self, lane):
        return self.x == lane * TILE_WIDTH and not self.hit and self.y + TILE_HEIGHT >= HEIGHT - 120

def retry_button():
    button_rect = pygame.Rect(WIDTH // 2 - 100, HEIGHT // 2 - 30, 200, 60)
    pygame.draw.rect(SCREEN, GREEN, button_rect)
    text = BUTTON_FONT.render("  Retry", True, WHITE)
    SCREEN.blit(text, (button_rect.x + 50, button_rect.y + 10))
    return button_rect


def main():
    global high_score
    global score
    clock = pygame.time.Clock()
    red_flash = -500
    running = True
    life = 3
    tiles = [Tile(random.choice([0, 1]) * TILE_WIDTH, -TILE_HEIGHT)]

    while running:
        global SPEED

        SCREEN.fill(WHITE)
        draw_text(f"{score}", 200, 300, BLACK, True)
        draw_text(f"{" O " * life}", 200, 50, RED, True)
        SCREEN.blit(MARKER, (0 , HEIGHT - 120))
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                if score > high_score:
                    high_score = score
                    with open(HIGH_SCORE_FILE, "w") as file:
                        file.write(str(high_score))
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key in KEYS:
                    lane = KEYS[event.key]
                    hit_tile = False
                    for tile in tiles:
                        if tile.collide(lane):
                            tile.hit = True
                            if SPEED <= 8.5:
                                SPEED += 0.1
                            score += 1
                            hit_tile = True
                            break
                    if not hit_tile:
                        score -= 1

        for tile in tiles[:]:
            tile.move()
            tile.draw()
            if tile.is_off_screen():
                tiles.remove(tile)
                if not tile.hit:
                    life -= 1
                    SPEED -= 1
                    red_flash = pygame.time.get_ticks()
                    if life == 0:
                        SCREEN.fill(WHITE)
                        if score > high_score:
                            high_score = score
                            with open(HIGH_SCORE_FILE, "w") as file:
                                file.write(str(high_score))
                        draw_text(f"Your score: {score}", 200, 50, BLACK, True)
                        draw_text(f"High score: {high_score}", 200, 100, BLACK, True)
                        score = 0
                        retry_rect = retry_button()
                        pygame.display.flip()
                        waiting = True
                        while waiting:
                            for event in pygame.event.get():
                                if event.type == pygame.QUIT:
                                    pygame.quit()
                                    exit()
                                if event.type == pygame.MOUSEBUTTONDOWN:
                                    if retry_rect.collidepoint(event.pos):
                                        SPEED = 5
                                        main()
                                        waiting = False
                        return

        if pygame.time.get_ticks() - red_flash < 500:
            red_overlay = pygame.Surface((WIDTH, HEIGHT), pygame.SRCALPHA)
            red_overlay.fill((217, 33, 33, 40))
            SCREEN.blit(red_overlay, (0, 0))

        if len(tiles) == 0 or tiles[-1].y > TILE_HEIGHT:
            new_lane = random.choice([0, 1, 2, 3])
            second_lane = random.choice([0, 1, 2, 3])
            tiles.append(Tile(new_lane * TILE_WIDTH, -TILE_HEIGHT))
            if SPEED >= 6.5:
                if random.random() < 0.5 and new_lane != second_lane:
                    tiles.append(Tile(second_lane * TILE_WIDTH, -TILE_HEIGHT))
            else:
                if random.random() < 0.3 and new_lane != second_lane:
                    tiles.append(Tile(second_lane * TILE_WIDTH, -TILE_HEIGHT))

        pygame.display.flip()
        clock.tick(120)

    print(f"Final Score: {score}")
    pygame.quit()

if __name__ == "__main__":
    main()
