# 30 days = 100 rel
perfect_days = 23

reliabilty = 100.0
days_present = int(input("Enter days you are present: "))

result = days_present / perfect_days * reliabilty

print(f"Reliabilty result: {result:.2f}%")