import numpy

def insertionSort(array):
    counter=0
    swap=0
    for i in range(1, len(array)):
        counter=counter+1
        key = array[i]
        j = i - 1
        
     
        while j >= 0 and key < array[j]:
            counter=counter+1
            array[j + 1] = array[j]
            j = j - 1
            array[j + 1] = key
            swap=swap+1
          



    print("///////")
    print(counter)
    print(swap)
    print("///////")
print("------Сортування бульбашкою------")
print("Масив 10 el")
a=[6, 1, 3, 7, 2]
#a = [i for i in range(10)]
print(a)

print("Упорядкована послідовнясть відсортований масив 10 el")
insertionSort(a)
print(a)

b = numpy.random.randint(100000, size=10)
print("Випадкова послідовнясть відсортований масив 10 el")
insertionSort(b)
print(b)

c = (a[::-1])
print("Зворотня послідовнясть відсортований масив 10 el")
insertionSort(c)
print(c)
