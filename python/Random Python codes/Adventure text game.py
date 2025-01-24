print("this is a text based adventure game. My first kinda big project during summer vacation. Future me, pls fix this")
print("---")
print("Your goal is to defeat the dragon. choose your class")

#Hero Stats
Hp = 0
Mana = 0
Attk = 0
Magic = 0

#Class system
Hero_class = input("archer/warrior/mage: ")
if Hero_class == "archer":
    Hp += 30
    Mana += 10
    Attk += 25
    Magic += 0
    print("You choose Archer")
if Hero_class == "warrior":
    Hp += 50
    Mana += 0
    Attk += 15
    Magic += 0
    print("You choose Warrior")
if Hero_class == "mage":
    Hp += 25
    Mana += 40
    Attk += 0
    Magic += 30
    print("You choose Mage")

print(f"Hp: {Hp}")
print(f"Mana: {Mana}")
print(f"Attk: {Attk}")
print(f"Magic: {Magic}")
