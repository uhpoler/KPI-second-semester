import numpy

def bubbleSort(array):
    counter=0
    swap=0
    for i in range(len(array)):
        stop=0
        for j in range(0, len(array) - i - 1):
            counter=counter+1
            if array[j] > array[j+1]:
                swap=swap+1
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp
                stop=-1
        if stop==0:
            break
	   

    print("///////")
    print(counter)
    print(swap)
    print("///////")
print("------Сортування бульбашкою------")
print("Масив 10 el")
a = [i for i in range(10)]
print(a)

print("Упорядкована послідовнясть відсортований масив 10 el")
bubbleSort(a)
print(a)

b = numpy.random.randint(100000, size=10)
print("Випадкова послідовнясть відсортований масив 10 el")
bubbleSort(b)
print(b)

c = (a[::-1])
print("Зворотня послідовнясть відсортований масив 10 el")
bubbleSort(c)
print(c)
