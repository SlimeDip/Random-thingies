#Ice Cream Price Calculator - www.101computing.net/ice-cream-price-calculator

print("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")
print("+                               +")
print("+      The Ice Cream Shop       +")
print("+            Welcome            +")
print("+                               +")
print("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")
print("")

Total_value = 0

container = input("What type of ice cream container would you like: cup or cone?")
while container!="cup" and container!="cone":
  print("Invalid answer please try again!")
  container = input("What type of ice cream container would you like: cup or cone?")

if container == "cup":
  Total_value += 0.50
elif container == "cone":
  Total_value += 0.80
  
scoops = input("How many scoops would you like: 1-4?")
while scoops!="1" and scoops!="2" and scoops!="3" and scoops!="4":
  print("Invalid answer please try again!")
  scoops = input("How many scoops would you like: 1-4?")
  
if scoops == "1":
  Total_value += 1.00
elif scoops == "2":
  Total_value += 2.00
elif scoops == "3":
  Total_value += 3.00
elif scoops == "4":
  Total_value += 4.00
  
flakes = input("would you like some flakes: yes or no?")
while flakes!="yes" and flakes!="no":
  print("Invalid answer please try again!")
  flakes = input("would you like some flakes: yes or no?")
  
if flakes == "yes":
  Total_value += 0.40
elif flakes == "no":
  pass
  
choc_sprinkels = input("would you like some chocolate sprinkels: yes or no?")
while choc_sprinkels!="yes" and choc_sprinkels!="no":
  print("Invalid answer please try again!")
  choc_sprinkels = input("would you like some chocolate sprinkels: yes or no?")
  
if choc_sprinkels == "yes":
  Total_value += 0.30
elif choc_sprinkels == "no":
  pass

strawb = input("would you like some strawberry coulis: yes or no?")
while strawb!="yes" and strawb!="no":
  print("Invalid answer please try again!")
  strawb = input("would you like some strawberry coulis: yes or no?")
  
if strawb == "yes":
  Total_value += 0.60
elif strawb == "no":
  pass
  
print("Total price: " + "£" + str(Total_value))

