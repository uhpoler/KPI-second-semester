import sys

#тимчасовий масив для злиття відсортованих частин
def mergeSort(arr):
    n = len(arr)
    temp_arr = [0]*n
    return _mergeSort(arr, temp_arr, 
                      0, n - 1)

#виконує рекурсивний розділ і злиття  масиву
def _mergeSort(arr, temp_arr, left, right):
  
    inv_count = 0
  
    if left < right:
  
        mid = (left + right)//2
        inv_count += _mergeSort(arr, temp_arr, 
                                left, mid)
        inv_count += _mergeSort(arr, temp_arr, 
                                mid + 1, right)
        inv_count += merge(arr, temp_arr, 
                           left, mid, right)
    return inv_count

  
def merge(arr, temp_arr, left, mid, right):
    i = left     
    j = mid + 1 
  
    k = left     
    inv_count = 0
  
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp_arr[k] = arr[i]
            k += 1
            i += 1
        else:
            temp_arr[k] = arr[j]
            inv_count += (mid-i + 1)
            k += 1
            j += 1
  
    while i <= mid:
        temp_arr[k] = arr[i]
        k += 1
        i += 1
  
    while j <= right:
        temp_arr[k] = arr[j]
        k += 1
        j += 1

#копіює елементи тимчасового масиву в звичайний
    for loop_var in range(left, right + 1):
        arr[loop_var] = temp_arr[loop_var]
          
    return inv_count
  

def newarr(firstarr, secondarr):
    newarr = [0 for i in range(len(firstarr))]

    for i in range(len(firstarr)):
        newarr[firstarr[i] - 1] = secondarr[i]
    return mergeSort(newarr)



# Зчитуємо вхідні дані з файлу
file_path = "./input_5_5.txt"
with open(file_path, "r") as input_file:
    u, m = map(int, input_file.readline().split())
    matrix = [[] for i in range(u)]
    for i in range(u):
        row = list(map(int, input_file.readline().split()))
        matrix[row[0]-1] = row[1:]
# Зчитуємо номер користувача x, з яким порівнюємо
x = 3

# Підраховуємо кількість інверсій для кожного користувача
similarities = []
for i in range(u):
    if i+1 != x:
        inversions = newarr(matrix[i],matrix[x-1])
        similarities.append((i+1, inversions))

# Сортуємо користувачів за зростанням ступеня подібності
similarities.sort(key=lambda x: x[1])

# Записуємо результат у вихідний файл
with open("./output.txt", "w") as output_file:
     output_file.write(str(x) + "\n")
     for similarity in similarities:
          output_file.write(str(similarity[0]) + " " + str(similarity[1]) + "\n")
