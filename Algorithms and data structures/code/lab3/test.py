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



# зчитуємо вхідний файл
def read_input_file(filename):
    with open(filename, 'r') as f:
        n = int(f.readline().strip())
        arr = [int(f.readline().strip()) for _ in range(n)]
    return arr

def write_output_file(filename, result):
    with open(filename, 'w') as f:
        f.write(str(result))

if __name__ == '__main__':
    arr = read_input_file('input_01_10.txt')
    result = quick_sort_median(arr, 0, len(arr) - 1)
    write_output_file('output.txt', result)
