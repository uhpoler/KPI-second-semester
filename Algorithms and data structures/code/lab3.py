
#алгоритм швидкого сортування 1-------------------------------------------
def quicksort_last(array, left, right):
    if left < right and len(array) > 0:
        pivot = partition_last(array, left, right)
        quicksort_last(array, left, pivot - 1)
        quicksort_last(array, pivot + 1, right)

def partition_last(array, left, right):
    global comparisons1 # лічильник порівнянь
    pivot = array[right]
    i = left - 1
    for j in range(left, right):
        if array[j] < pivot:
            i += 1
            array[i], array[j] = array[j], array[i]
        comparisons1 += 1 # підрахунок порівнянь
    array[i+1], array[right] = array[right], array[i+1]
    return i+1


#алгоритм швидкого сортування 2-------------------------------------------
def median_of_three(a, mid, c):
    return sorted([a, mid, c])[1]

def quick_sort_median(arr, p, r):
    comparisons = 0
    if p < r:
        if r - p + 1 > 3:
            i, comparisons = part_of_median(arr, p, r)
            comparisons += quick_sort_median(arr, p, i - 1)
            comparisons += quick_sort_median(arr, i + 1, r)
        else:
            comparisons = insertion_sort(arr, p, r)
    return comparisons

def part_of_median(arr, p, r):
    comparisons = 0
    mid = (p+r)//2
    median = median_of_three(arr[p], arr[mid], arr[r])

    if median == arr[p]:
        pivot_index = p
    elif median == arr[mid]:
        pivot_index = mid
    else:
        pivot_index = r

    arr[pivot_index], arr[r] = arr[r], arr[pivot_index]
    i = p - 1
    for j in range(p, r):
        comparisons += 1
        if arr[j] <= median:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[r] = arr[r], arr[i + 1]

    return i + 1, comparisons


def insertion_sort(arr, p, r):
    comparisons = 0
    for i in range(p+1, r+1):
        key = arr[i]
        j = i - 1
        while j >= p and (comparisons := comparisons+1) and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return comparisons



def read_input_file(filename):
    with open(filename, 'r') as f:
        n = int(f.readline().strip())
        arr = [int(f.readline().strip()) for _ in range(n)]
    return arr

def write_output_file(filename, result):
    with open(filename, 'w') as f:
        f.write(str(result))

# Зчитування вхідних даних з файлу та сортування
with open("input_11_1000.txt", "r") as infile:
    n = int(infile.readline())
    array1 = []
    for i in range(n):
        x = int(infile.readline())
        array1.append(x)
    array2 = array1.copy()
    comparisons1 = 0
    print(array1)
    quicksort_last(array1, 0, n-1)
    print(array1)
    comparisons2=quick_sort_median(array2,0,len(array1) - 1)

    

# Запис результату у вихідний файл
with open("output.txt", "w") as outfile:
    #outfile.write(str(comparisons2))
    outfile.write(f"{comparisons1} {comparisons2}")
