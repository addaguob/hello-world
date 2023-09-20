import mysql.connector

# Connect to the MySQL database
connection = mysql.connector.connect(
    host="localhost",
    user="root",
    password="29june2023",
    database="friends"
)

# Create a cursor object
cursor = connection.cursor()

# Execute the SQL query
query = "INSERT INTO `friends`.`customer_bill` (`Customer_Id`, `Bill_Date`, `Bill_Amount`) VALUES ('1', '2/2/2023', '75'); \
INSERT INTO `friends`.`customer_bill` (`Customer_Id`, `Bill_Date`, `Bill_Amount`) VALUES ('1', '3/2/2023', '70'); \
INSERT INTO `friends`.`customer_bill` (`Customer_Id`, `Bill_Date`, `Bill_Amount`) VALUES ('2', '2/2/2023', '55'); \
INSERT INTO `friends`.`customer_bill` (`Customer_Id`, `Bill_Date`, `Bill_Amount`) VALUES ('2', '3/2/2023', '60'); \
INSERT INTO `friends`.`customer_bill` (`Customer_Id`, `Bill_Date`, `Bill_Amount`) VALUES ('3', '2/2/2023', '120'); \
INSERT INTO `friends`.`customer_bill` (`Customer_Id`, `Bill_Date`, `Bill_Amount`) VALUES ('3', '3/2/2023', '125');"
cursor.execute(query)

# Fetch the results
results = cursor.fetchall()

# Print the results
for row in results:
    print(row)

# Close the connection
connection.close()