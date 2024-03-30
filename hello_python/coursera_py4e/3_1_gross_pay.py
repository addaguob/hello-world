hrs = input("Enter Hours:");
h = float(hrs);
rate = input("Enter Rate: ");
r = float(rate);

pay = h * r;
    
if h > 40:
    pay = pay * 1.5;

print(pay);