import csv

# Especifica o caminho do arquivo CSV
csv_file_path = 'Restaurant_Inspection_Scores.csv'

# Especifica o nome da coluna que deseja extrair
column_name = 'Score'

# Lista para armazenar os valores da coluna
column_values = []

# Abre o arquivo CSV
with open(csv_file_path, 'r', newline='') as csvfile:
    # Cria um leitor CSV
    csv_reader = csv.DictReader(csvfile)

    # Verifica se a coluna especificada existe no cabeçalho CSV
    if column_name not in csv_reader.fieldnames:
        print(f"Coluna '{column_name}' não encontrada no CSV.")
    else:
        # Extrai os valores da coluna especificada
        column_values = [row[column_name] for row in csv_reader]

# Abre o arquivo "data.txt" para escrever os valores da coluna
with open("data.txt", "w") as data_file:
    # Grava os valores da coluna em uma única coluna com várias linhas
    for value in column_values:
        data_file.write(str(value) + '\n')

print(f"{column_name} valores gravados em data.txt.")
