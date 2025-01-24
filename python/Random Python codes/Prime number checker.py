Target = input("Enter a number: ")
Target = int(Target)
prime_check = 0

for i in range(2, Target):  # Check up to half of the Target
    for j in range(2, Target):  # Check up to half of the Target
        if i * j == Target:
            print(f"{i} x {j} = {Target}")
            prime_check += 1
    if prime_check > 0:
        break  # No need to continue outer loop if a factor is found

if prime_check > 0:
    print(f"{Target} is not a prime number")
else:
    print(f"{Target} is a prime number")
