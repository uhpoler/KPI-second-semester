import random
import matplotlib.pyplot as plt

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size
        self.comparison_count = 0

    def hash_function(self, key):
        h = 0
        for char in key:
            h = (h << 4) + ord(char)
            g = h & 0xF0000000  # залишає лише найстарші 4 біти h, а інші біти встановлює в 0.
            if g != 0:
                h ^= g >> 24
            h &= ~g
        return h % self.size

    def double_hash(self, key, i):
        hash_1 = self.hash_function(key)
        hash_2 = 1 + (self.hash_function(key) % (self.size - 1))
        return (hash_1 + i * hash_2) % self.size

    def insert(self, key, value):
        i = 0
        while i < self.size:
            index = self.double_hash(key, i)
            if self.table[index] is None:
                self.table[index] = (key, value)
                return True

            i += 1
        return False

    def get(self, key):
        i = 0
        while i < self.size:
            index = self.double_hash(key, i)
            self.comparison_count += 1  
            if self.table[index] is not None and self.table[index][0] == key:
                return self.table[index][1]
            
            i += 1
        return None

def generate_random_string(length):
    chars = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890'
    return ''.join(random.choice(chars) for _ in range(length))

def print_hash_table(hash_table):
    for i, item in enumerate(hash_table.table):
        if item is not None:
            print(f'Index {i}: Key: {item[0]}, Value: {item[1]}')
        else:
            print(f'Index {i}: Empty')
            
average_comparisons = []
size = []
table_size = int(input("Enter the size of the hash table: "))
# Створення хеш-таблиці
hash_table = HashTable(table_size * 2)
key = []

# Заповнення хеш-таблиці згенерованими випадковими значеннями
for i in range(table_size):
    key.append(generate_random_string(20))
    value = generate_random_string(200)
    hash_table.insert(key[i], value)
# Виведення хеш-таблиці на екран
print_hash_table(hash_table)

# Пошук значення за ключем, введеним користувачем
key_to_find = input('Enter a key to search: ')
value = hash_table.get(key_to_find)
if value:
    print(f'Value for key {key_to_find}: {value}')
else:
    print(f'Key {key_to_find} not found.')

print(f'Number of comparisons: {hash_table.comparison_count}')






table_size = [100, 500, 1000, 2000, 5000, 10000, 15000, 20000]
# Отримання розміру хеш-таблиці від користувача
for cnt in range(8):

    # Створення хеш-таблиці
    hash_table = HashTable(table_size[cnt] * 2)
    key = []
    # Заповнення хеш-таблиці згенерованими випадковими значеннями
    for i in range(table_size[cnt]):
        key.append(generate_random_string(20))
        value = generate_random_string(200)
        hash_table.insert(key[i], value)
    for i in range(table_size[cnt]):
        key_to_find = key[i]
        value = hash_table.get(key_to_find)
    total_comparisons = hash_table.comparison_count

    average = total_comparisons / table_size[cnt]
    print(f'{table_size[cnt]}:{average }')
    
    size.append(table_size[cnt])
    average_comparisons.append(average)

plt.plot(size, average_comparisons)
plt.xlabel('Size of Hash Table')
plt.ylabel('Number of Comparisons')
plt.title('HashTable')
plt.show()






