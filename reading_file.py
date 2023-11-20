import csv

data_file = open("data.txt", "wt")

# Specify the CSV file path
csv_file_path = 'Restaurant_Inspection_Scores.csv'

# Specify the column name you want to extract
column_name = 'Score'

# Open the CSV file
with open(csv_file_path, 'r', newline='') as csvfile:
    # Create a CSV reader
    csv_reader = csv.DictReader(csvfile)

    # Check if the specified column exists in the CSV header
    if column_name not in csv_reader.fieldnames:
        print(f"Column '{column_name}' not found in the CSV.")
    else:
        # Extract the specified column values
        column_values = [row[column_name] for row in csv_reader]

        # Print the extracted column values
        print(f"{column_name} column values: {column_values}")
        

close("Restaurant_Inspection_Scores.csv")
close("data.txt")