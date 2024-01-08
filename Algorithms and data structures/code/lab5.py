import heapq

def find_medians(arr):
    n = len(arr)

    Hlow = []   
    Hhigh = []  
    medians = []  

    for i in range(n):
        x = arr[i]

        if not Hlow or x <= -Hlow[0]:
            heapq.heappush(Hlow, -x)
        else:
            heapq.heappush(Hhigh, x)

 
        if len(Hlow) - len(Hhigh) > 1:
            heapq.heappush(Hhigh, -heapq.heappop(Hlow))
        elif len(Hhigh) - len(Hlow) > 1:
            heapq.heappush(Hlow, -heapq.heappop(Hhigh))

     
        if i % 2 == 0:
            if len(Hlow) > len(Hhigh):
                medians.append(-Hlow[0])
            else:
                medians.append(Hhigh[0])
        else:
            medians.append((-Hlow[0], Hhigh[0]))

    return medians


with open('input_11_1000.txt', 'r') as file:
    lines = file.readlines()
    n = int(lines[0])
    arr = [int(lines[i]) for i in range(1, n+1)]


medians = find_medians(arr)


with open('output.txt', 'w') as file:
    for median in medians:
        if isinstance(median, int):
            file.write(str(median) + '\n')
        else:
            file.write(' '.join(str(num) for num in median) + '\n')
